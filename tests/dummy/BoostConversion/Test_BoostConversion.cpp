// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/polymorphic_cast.hpp>

namespace {
    // run some code from doc samples
    struct Base
    {
        virtual char kind() { return 'B'; }
    };

    struct Base2
    {
        virtual char kind2() { return '2'; }
    };

    struct Derived : public Base, Base2
    {
        virtual char kind() { return 'D'; }
    };

    TEST(RunMethod, boostConversion)
    {
        Derived derived_instance;
        Base* base = &derived_instance;
        Derived* derived = ::boost::polymorphic_downcast<Derived*>(base);  // downcast
        EXPECT_TRUE(derived->kind() == 'D');
        
        derived = ::boost::polymorphic_cast<Derived*>(base); // downcast, throw on error
        EXPECT_TRUE(derived->kind() == 'D');

        Base2* base2 = ::boost::polymorphic_cast<Base2*>(base); // crosscast
        EXPECT_TRUE(base2->kind2() == '2');

        //  tests which should result in errors being detected
        Base base_instance;
        base = &base_instance;

        EXPECT_THROW(derived = ::boost::polymorphic_cast<Derived*>(base), ::std::bad_cast);

        //  the following is just so generated code can be inspected
        EXPECT_TRUE(derived->kind() != 'B');
    }
}