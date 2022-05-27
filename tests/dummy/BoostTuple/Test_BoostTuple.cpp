// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include "boost/tuple/tuple_io.hpp"
#include "boost/tuple/tuple_comparison.hpp"

#include <iterator>
#include <algorithm>
#include <string>
#include <iomanip>

#if defined BOOST_NO_STRINGSTREAM
#include <strstream>
#else
#include <sstream>
#endif


namespace {
#if defined BOOST_NO_STRINGSTREAM
    typedef std::ostrstream useThisOStringStream;
    typedef std::istrstream useThisIStringStream;
#else
    typedef std::ostringstream useThisOStringStream;
    typedef std::istringstream useThisIStringStream;
#endif

    // run some code from doc examples
    TEST(RunMethod, boostTuple)
    {
        useThisOStringStream os1;

        // Set format [a, b, c] for os1
        os1 << ::boost::tuples::set_open('[');
        os1 << ::boost::tuples::set_close(']');
        os1 << ::boost::tuples::set_delimiter(',');
        os1 << ::boost::tuples::make_tuple(1, 2, 3);
        EXPECT_TRUE(os1.str() == std::string("[1,2,3]"));

        {
            useThisOStringStream os2;
            // Set format (a:b:c) for os2; 
            os2 << ::boost::tuples::set_open('(');
            os2 << ::boost::tuples::set_close(')');
            os2 << ::boost::tuples::set_delimiter(':');
#if !defined (BOOST_NO_TEMPLATE_PARTIAL_SPECIALIZATION)
            os2 << ::boost::tuples::make_tuple("TUPU", "HUPU", "LUPU", 4.5);
            EXPECT_TRUE(os2.str() == std::string("(TUPU:HUPU:LUPU:4.5)"));
#endif
        }

        // The format is still [a, b, c] for os1
        os1 << ::boost::tuples::make_tuple(1, 2, 3);
        EXPECT_TRUE(os1.str() == std::string("[1,2,3][1,2,3]"));

        // check empty tuple.
        useThisOStringStream os3;
        os3 << ::boost::tuples::make_tuple();
        EXPECT_TRUE(os3.str() == std::string("()"));
        os3 << ::boost::tuples::set_open('[');
        os3 << ::boost::tuples::set_close(']');
        os3 << ::boost::tuples::make_tuple();
        EXPECT_TRUE(os3.str() == std::string("()[]"));

        // check width
        useThisOStringStream os4;
        os4 << std::setw(10) << ::boost::tuples::make_tuple(1, 2, 3);
        EXPECT_TRUE(os4.str() == std::string("   (1 2 3)"));


        // reading tuple<int, int, int> in format (a b c); 
        useThisIStringStream is1("(100 200 300)");

        ::boost::tuples::tuple<int, int, int> ti1;
        EXPECT_TRUE(bool(is1 >> ti1));
        EXPECT_TRUE(ti1 == ::boost::tuples::make_tuple(100, 200, 300));

        useThisIStringStream is2("()");
        ::boost::tuples::tuple<> ti2;
        EXPECT_TRUE(bool(is2 >> ti2));
        useThisIStringStream is3("[]");
        is3 >> ::boost::tuples::set_open('[');
        is3 >> ::boost::tuples::set_close(']');
        EXPECT_TRUE(bool(is3 >> ti2));

        // Make sure that whitespace between elements
        // is skipped.
        useThisIStringStream is4("(100 200 300)");

        EXPECT_TRUE(bool(is4 >> std::noskipws >> ti1));
        EXPECT_TRUE(ti1 == ::boost::tuples::make_tuple(100, 200, 300));
    }

}