// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/assert.hpp>
#include <cstdio>

namespace {
    TEST(RunMacro, assertDefault)
    {
        // run some test from doc examples
        int x = 1; (void)x;

        BOOST_ASSERT(1);
        BOOST_ASSERT(x);
        BOOST_ASSERT(x == 1);
        BOOST_ASSERT(&x);

        BOOST_ASSERT_MSG(1, "msg");
        BOOST_ASSERT_MSG(x, "msg");
        BOOST_ASSERT_MSG(x == 1, "msg");
        BOOST_ASSERT_MSG(&x, "msg");
    }

    TEST(RunMacro, assertDisabled)
    {
        // run some test from doc examples
        int x = 1;

        BOOST_ASSERT(1);
        BOOST_ASSERT(x);
        BOOST_ASSERT(x == 1);
        BOOST_ASSERT(&x);

        BOOST_ASSERT_MSG(1, "msg");
        BOOST_ASSERT_MSG(x, "msg");
        BOOST_ASSERT_MSG(x == 1, "msg");
        BOOST_ASSERT_MSG(&x, "msg");

        void* p = &x;

        BOOST_ASSERT(p);
        BOOST_ASSERT_MSG(p, "msg");
    }
}