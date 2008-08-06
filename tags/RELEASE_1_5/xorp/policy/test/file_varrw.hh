// -*- c-basic-offset: 4; tab-width: 8; indent-tabs-mode: t -*-
// vim:set sts=4 ts=8:

// Copyright (c) 2001-2008 XORP, Inc.
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

// $XORP: xorp/policy/test/file_varrw.hh,v 1.9 2008/01/04 03:17:21 pavlin Exp $

#ifndef __POLICY_TEST_FILE_VARRW_HH__
#define __POLICY_TEST_FILE_VARRW_HH__

#include "policy/common/varrw.hh"
#include "policy/common/policy_exception.hh"
#include "policy/common/element_factory.hh"
#include <map>
#include <string>
#include <set>

class FileVarRW : public VarRW {
public:
    class Error : public PolicyException {
    public:
        Error(const char* file, size_t line, const string& init_why = "")   
            : PolicyException("Error", file, line, init_why) {}  
    };

    FileVarRW(const string& fname);
    ~FileVarRW();

    const Element& read(const Id&);
    void write(const Id&, const Element&);

    void sync();

    void printVars();
    
private:
    bool doLine(const string& line);
    void clear_trash();

    typedef map<Id,const Element*> Map;
    Map _map;

    ElementFactory _ef;
    set<Element*> _trash;
};

#endif // __POLICY_TEST_FILE_VARRW_HH__