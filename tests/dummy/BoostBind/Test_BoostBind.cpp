// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/

#include <gtest/gtest.h>
#include <boost/bind/apply.hpp>
#include <boost/bind/protect.hpp>
#include <boost/bind/bind.hpp>

namespace {

    // run some code from doc examples
    int f(int x)
    {
        return x;
    }

    TEST(RunMethod, boostBindApply)
    {
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_1)), 1)(), 1);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_2)), 1, 2)(), 2);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_3)), 1, 2, 3)(), 3);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_4)), 1, 2, 3, 4)(), 4);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_5)), 1, 2, 3, 4, 5)(), 5);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_6)), 1, 2, 3, 4, 5, 6)(), 6);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_7)), 1, 2, 3, 4, 5, 6, 7)(), 7);
        EXPECT_EQ(boost::bind(boost::apply<int>(), boost::protect(boost::bind(f, boost::placeholders::_8)), 1, 2, 3, 4, 5, 6, 7, 8)(), 8);
    }
}
