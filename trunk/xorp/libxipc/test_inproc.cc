// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-

// Copyright (c) 2001,2002 International Computer Science Institute
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

#ident "$XORP: xorp/libxipc/test_inproc.cc,v 1.2 2002/12/14 23:42:55 hodson Exp $"

/*
#define DEBUG_LOGGING
*/

#include <stdio.h>
#include "xrl_module.h"
#include "libxorp/xlog.h"
#include "libxorp/debug.h"
#include "libxorp/callback.hh"

#include "xrl_pf_inproc.hh"


static const bool g_show_trace = false;
#define trace(args...) if (g_show_trace) printf(args)

// ----------------------------------------------------------------------------
// Hello message handlers (zero arguments to Xrl)

static bool hello_done = false;

static const XrlCmdError
hello_recv_handler(const Xrl&	request, 
		   XrlArgs*	response)
{
    trace("hello_recv_handler: request %s response %p\n", 
	  request.str().c_str(), response);
    return XrlCmdError::OKAY();
}

static void
hello_reply_handler(const XrlError&	e,
		    const Xrl&		request, 
		    XrlArgs*		response)
{
    if (e == XrlError::OKAY()) {
	trace("hello_reply_handler: request %s response %p\n", 
	      request.str().c_str(), response);
    } else {
	trace("hello failed: %s\n", e.str().c_str());
    }
    hello_done = true;
}

static void
test_hello(EventLoop& e, XrlPFInProcSender &s) {
    Xrl x("anywhere", "hello");

    debug_msg("test_hello\n");
    s.send(x,  callback(hello_reply_handler));

    while (hello_done == 0) {
	e.run();
    }
    hello_done = false;
}

// ----------------------------------------------------------------------------
// Hello message handlers (zero arguments to Xrl)

static bool int32_done = false;

static const XrlCmdError
int32_recv_handler(const Xrl&	request, 
		   XrlArgs*	response)
{
    trace("int32_recv_handler: request %s response %p\n", 
	   request.str().c_str(), response);
    if (response)
	response->add_int32("an_int32", 123456);
    return XrlCmdError::OKAY();
}

static void
int32_reply_handler(const XrlError&	e, 
		    const Xrl&		request, 
		    XrlArgs*		response)
{
    if (e == XrlError::OKAY()) {
	trace("int32_reply_handler: request %s response %p\n",
	      request.str().c_str(), response);
	trace("int32 -> %s\n", response->str().c_str());
    } else {
	fprintf(stderr, "get_int32 failed: %s\n", e.str().c_str());
	exit(-1);
    }

    int32_done = true;
}

static void
test_int32(EventLoop& e, XrlPFInProcSender& s) {
    Xrl x("anywhere", "get_int32");

    debug_msg("test_int32\n");

    s.send(x, callback(int32_reply_handler));
    while(int32_done == 0)
	e.run();

    int32_done = 0;
}

static bool
print_dot()
{
    printf("."); fflush(stdout);
    return true;
}

static void
run_test()
{
    EventLoop event_loop;
    XrlCmdMap cmd_map;

    cmd_map.add_handler("hello", callback(hello_recv_handler));
    cmd_map.add_handler("get_int32", callback(int32_recv_handler));

    XrlPFInProcListener listener(event_loop, &cmd_map);
    XrlPFInProcSender s(event_loop, listener.address());

    trace("listener address: %s\n", listener.address());

    XorpTimer dp = event_loop.new_periodic(500, callback(&print_dot));
    assert(dp.scheduled());

    printf("Testing XRLPFInProc");
    for(int i = 0; i < 100000; i++) {
	test_hello(event_loop, s);
	test_int32(event_loop, s);
	// Can't call event_loop.run() because it blocks and inproc 
	// send/recv stuff happens instantaneously.
	event_loop.timer_list().run();
    }
    assert(dp.scheduled());
    printf("\n");
}

// ----------------------------------------------------------------------------
// Main

int main(int /* argc */, char *argv[]) {
    //
    // Initialize and start xlog
    //
    xlog_init(argv[0], NULL);
    xlog_set_verbose(XLOG_VERBOSE_LOW);		// Least verbose messages
    // XXX: verbosity of the error messages temporary increased
    xlog_level_set_verbose(XLOG_LEVEL_ERROR, XLOG_VERBOSE_HIGH);
    xlog_add_default_output();
    xlog_start();

    run_test();

    //
    // Gracefully stop and exit xlog
    //
    xlog_stop();
    xlog_exit();
    
    return 0;
}
