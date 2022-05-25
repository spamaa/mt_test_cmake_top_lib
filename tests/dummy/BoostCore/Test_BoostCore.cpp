// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/core/addressof.hpp>
#include <boost/core/demangle.hpp>

namespace {
    // make run some sample code from documentation

    struct useless_type { };

    class nonaddressable {
    public:
        useless_type operator&() const;
    };

    TEST(RunMethod, coreAddressofNoAdressable)
    {
        nonaddressable x;
        nonaddressable* xp = boost::addressof(x);
    }

    class addressable {
    public:
        addressable *operator&()
        {
            return this;
        }
    };

    TEST(RunMethod, coreAddressofAdressable)
    {
        addressable x;
        EXPECT_EQ(::boost::addressof(x), &x);
    }

    template<class T> struct X
    {
    };

    TEST(RunMethod, coreDemangle)
    {
        EXPECT_EQ(boost::core::demangle(typeid(X<int>).name()), "struct `anonymous namespace'::X<int>");
    }
}