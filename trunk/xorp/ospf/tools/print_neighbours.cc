// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2005 International Computer Science Institute
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software")
// to deal in the Software without restriction, subject to the conditions
// listed in the XORP LICENSE file. These conditions include: you must
// preserve this copyright notice, and you cannot mention the copyright
// holders in advertising related to the Software without their permission.
// The Software is provided WITHOUT ANY WARRANTY, EXPRESS OR IMPLIED. This
// notice is a summary of the XORP LICENSE file; the license in that file is
// legally binding.

#ident "$XORP: xorp/ospf/tools/print_neighbours.cc,v 1.2 2005/11/05 05:40:44 atanu Exp $"

// Print information about OSPF neighbours

// #define DEBUG_LOGGING
// #define DEBUG_PRINT_FUNCTION_NAME

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <set>
#include <list>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_GETOPT_H
#include <getopt.h>
#endif

#include "ospf/ospf_module.h"

#include "libxorp/debug.h"
#include "libxorp/xlog.h"

#include "libxorp/ipv4.hh"
#include "libxorp/ipv6.hh"

#include "libxorp/status_codes.h"
#include "libxorp/eventloop.hh"
#include "libxipc/xrl_std_router.hh"
#include "libxorp/tlv.hh"

#include "ospf/ospf.hh"
#include "ospf/test_common.hh"

#include "xrl/interfaces/ospfv2_xif.hh"

/**
 * Get the list of neighbours
 */
class GetNeighbourList {
public:
    GetNeighbourList(XrlStdRouter& xrl_router, OspfTypes::Version version)
	: _xrl_router(xrl_router), _version(version),
	  _done(false), _fail(false)
    {
    }

    void start() {
	XrlOspfv2V0p1Client ospfv2(&_xrl_router);
	ospfv2.send_get_neighbour_list(xrl_target(_version),
				       callback(this,
						&GetNeighbourList::response));
    }

    bool busy() {
	return !_done;
    }

    bool fail() {
	return _fail;
    }

    list<OspfTypes::NeighbourID>& get() {
	return _nlist;
    }

private:
    void response(const XrlError& error, const XrlAtomList *atomlist) {
	_done = true;
	if (XrlError::OKAY() != error) {
	    XLOG_WARNING("Attempt to get neighbour list failed");
	    _fail = true;
	    return;
	}
	const size_t size = atomlist->size();
	for (size_t i = 0; i < size; i++)
	    _nlist.push_back(atomlist->get(i).uint32());
    }
private:
    XrlStdRouter &_xrl_router;
    OspfTypes::Version _version;
    bool _done;
    bool _fail;

    list<OspfTypes::NeighbourID> _nlist;
};

/**
 * Get the Neighbour info for all the requested neighbours.
 */
class GetNeighbours {
public:
    GetNeighbours(XrlStdRouter& xrl_router, OspfTypes::Version version,
		  list<OspfTypes::NeighbourID>& nlist)
	: _xrl_router(xrl_router), _version(version),
	  _done(false), _fail(false), _nlist(nlist),_index(_nlist.begin())
    {}

    void start() {
	if (_nlist.end() == _index) {
	    _done = true;
	    return;
	}

	XrlOspfv2V0p1Client ospfv2(&_xrl_router);
	ospfv2.send_get_neighbour_info(xrl_target(_version), *_index,
				       callback(this,
						&GetNeighbours::response));
    }

    bool busy() {
	return !_done;
    }

    bool fail() {
	return _fail;
    }

    list<NeighbourInfo>& get_ninfo() {
	return _ninfo;
    }

private:
    void response(const XrlError& error,
		  const string* address,
		  const string* interface,
		  const string* state,
		  const IPv4* rid,
		  const uint32_t* priority,
		  const uint32_t* deadtime,
		  const IPv4* area,
		  const uint32_t* opt,
		  const IPv4* dr,
		  const IPv4* bdr,
		  const uint32_t* up,
		  const uint32_t* adjacent) {
	if (XrlError::OKAY() != error) {
	    XLOG_WARNING("Attempt to get neighbour info failed");
	    _done = true;
	    _fail = true;
	    return;
	}
	NeighbourInfo ninfo;
#define copy_ninfo(var) 	ninfo._ ## var = *var
	copy_ninfo(address);
	copy_ninfo(interface);
	copy_ninfo(state);
	copy_ninfo(rid);
	copy_ninfo(priority);
	copy_ninfo(deadtime);
	copy_ninfo(area);
	copy_ninfo(opt);
	copy_ninfo(dr);
	copy_ninfo(bdr);
	copy_ninfo(up);
	copy_ninfo(adjacent);
#undef copy_ninfo
	_ninfo.push_back(ninfo);
	_index++;

	start();
    }
private:
    XrlStdRouter &_xrl_router;
    OspfTypes::Version _version;
    bool _done;
    bool _fail;

    list<OspfTypes::NeighbourID> _nlist;
    list<OspfTypes::NeighbourID>::iterator _index;

    list<NeighbourInfo> _ninfo;
};

/**
 * Filter the neighbours. If the filter is empty then accept
 * everything, if the filter has any entries match against the
 * neighbour address or the router ID.
 */
class FilterNeighbour {
public:
    void add(IPv4 id) {
	_filter.push_back(id);
    }

    bool accept(const NeighbourInfo& ninfo) const {
	if (_filter.empty())
	    return true;

	list<IPv4>::const_iterator i;
	for (i = _filter.begin(); i != _filter.end(); i++) {
	    if (ninfo._address == (*i).str() ||
		ninfo._rid.str() == (*i).str())
		return true;
	}
	
	return false;
    }
private:
    list<IPv4> _filter;
};

/**
 * The base class that needs to be implemented by all print routines.
 */ 
class Output {
public:
    virtual ~Output()
    {}

    virtual bool begin() {
	printf("  Address         Interface             State"
	       "      ID              Pri  Dead\n");
	return true;
    }

    void print_first_line(const NeighbourInfo& ninfo) {
	printf("%-17s", ninfo._address.c_str());
	printf("%-23s", ninfo._interface.c_str());
	printf("%-10s", ninfo._state.c_str());
	printf("%-16s", ninfo._rid.str().c_str());
	printf("%4d", ninfo._priority);
	printf("%6d", ninfo._deadtime);
	printf("\n");
    }

    virtual bool print(const NeighbourInfo& ninfo) {
	print_first_line(ninfo);
	return true;
    }
};

class Brief : public Output {
public:
};

class Detail : public Output {
public:

    string uptime(uint32_t t) {
	const uint32_t mins_in_hour = 3600;
	uint32_t hours = t / mins_in_hour;
	uint32_t hour_remainder = t % mins_in_hour;
	uint32_t mins = hour_remainder / 60;
	uint32_t secs = hour_remainder % 60;

	return c_format("%02d:%02d:%02d", hours, mins, secs);
    }

    bool print(const NeighbourInfo& ninfo) {
	print_first_line(ninfo);
	printf("  Area %s, opt %#x, DR %s, BDR %s\n",ninfo._area.str().c_str(),
	       ninfo._opt, ninfo._dr.str().c_str(), ninfo._bdr.str().c_str());
	       
	printf("  Up %s", uptime(ninfo._up).c_str());
	if (0 != ninfo._adjacent)
	    printf(", adjacent %s", uptime(ninfo._adjacent).c_str());
	printf("\n");

	return true;
    }
};

enum Pstyle {
    BRIEF,
    DETAIL,
};

int
usage(const char *myname)
{
    fprintf(stderr, "usage: %s [-f x.x.x.x] [-b] [-d]\n", myname);

    return -1;
}

int 
main(int argc, char **argv)
{
    XorpUnexpectedHandler x(xorp_unexpected_handler);
    //
    // Initialize and start xlog
    //
    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_LOW);		// Least verbose messages
    // XXX: verbosity of the error messages temporary increased
    xlog_level_set_verbose(XLOG_LEVEL_ERROR, XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_start();

    OspfTypes::Version version = OspfTypes::V2;
    Pstyle pstyle = BRIEF;
    FilterNeighbour filter;

    int c;
    while ((c = getopt(argc, argv, "23f:bd")) != -1) {
	switch (c) {
	case '2':
	    version = OspfTypes::V2;
	    break;
	case '3':
	    version = OspfTypes::V3;
	    break;
	case 'f':
	    try {
		filter.add(optarg);
	    } catch(...) {}
	    break;
	case 'b':
	    pstyle = BRIEF;
	    break;
	case 'd':
	    pstyle = DETAIL;
	    break;
	default:
	    return usage(argv[0]);
	}
    }

    Output *output = 0;
    switch (pstyle) {
    case BRIEF:
	output = new Brief();
	break;
    case DETAIL:
	output = new Detail();
	break;
    }

    try {
	EventLoop eventloop;
	XrlStdRouter xrl_router(eventloop, "print_neighbours");

	debug_msg("Waiting for router");
	xrl_router.finalize();
	wait_until_xrl_router_is_ready(eventloop, xrl_router);
	debug_msg("\n");

	GetNeighbourList get_neighbour_list(xrl_router, version);
	get_neighbour_list.start();
	while(get_neighbour_list.busy())
	    eventloop.run();

	if (get_neighbour_list.fail()) {
	    XLOG_ERROR("Failed to get neighbour list");
	    return -1;
	}

	list<OspfTypes::NeighbourID>& nlist = get_neighbour_list.get();
	GetNeighbours get_neighbours(xrl_router, version, nlist);
	get_neighbours.start();
	while(get_neighbours.busy())
	    eventloop.run();

	if (get_neighbours.fail()) {
	    XLOG_ERROR("Failed to get neighbour info");
	    return -1;
	}

	if (!output->begin())
	    return -1;
	list<NeighbourInfo>& ninfo = get_neighbours.get_ninfo();
	list<NeighbourInfo>::const_iterator i;
	for (i = ninfo.begin(); i != ninfo.end(); i++) {
	    if (!filter.accept(*i))
		continue;
	    if (!output->print(*i))
		return -1;
	}

	delete output;

    } catch (...) {
	xorp_catch_standard_exceptions();
    }

    xlog_stop();
    xlog_exit();

    return 0;
}
