// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/static_assert.hpp>

namespace {
    typedef char a1[2];
    typedef char a2[3];

    TEST(RunMacro, boostStaticAssert)
    {
        // run some tests from examples
        BOOST_STATIC_ASSERT(sizeof(a1) != sizeof(a2));
    }

    template <int N>
    int foo()
    {
        BOOST_STATIC_ASSERT(N < 3);

        return N;
    }

    TEST(RunMacro, boostStaticAssertWithTemplate)
    {
        // run some tests from examples
        auto aa = foo<2>();
    }
}
