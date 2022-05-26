// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/typeof/typeof.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/static_assert.hpp>

namespace {
    // run some code from doc examples

    int foo1(double aa)
    {
        return aa;
    }

    TEST(RunFunction, boostTypeOfFoo1)
    {
        int foo1(double);
        typedef int(&FREF1)(double);
        FREF1 fref1 = *foo1;

        BOOST_STATIC_ASSERT((boost::is_same<BOOST_TYPEOF(fref1), int(double)>::value));
    }

    int foo2(...)
    {
        return 0;
    }

    TEST(RunFunction, boostTypeOfFoo2)
    {
        int foo2(...);
        typedef int(&FREF2)(...);
        FREF2 fref2 = *foo2;

        BOOST_STATIC_ASSERT((boost::is_same<BOOST_TYPEOF(fref2), int(...)>::value));
    }

    int foo3(int aa, ...)
    {
        return aa;
    }

    TEST(RunFunction, boostTypeOfFoo3)
    {
        int foo3(int, ...);
        typedef int(&FREF3)(int, ...);
        FREF3 fref3 = *foo3;

        BOOST_STATIC_ASSERT((boost::is_same<BOOST_TYPEOF(fref3), int(int, ...)>::value));        int foo1(double);
    }
}