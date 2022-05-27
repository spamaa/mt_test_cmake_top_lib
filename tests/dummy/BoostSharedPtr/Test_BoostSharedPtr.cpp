// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <boost/shared_ptr.hpp>

namespace {
    // run some code for doc samples
    static int DelCnt = 0;

    struct Foo
    {
        Foo(int _x) : x(_x) {}
        ~Foo() { DelCnt += x; }
        int x;
    };

    typedef boost::shared_ptr<Foo> FooPtr;


    TEST(RunMethod, boostSharedPtr)
    {
        {
            std::vector<FooPtr>         foo_vector;
            std::vector<int> foo_vector_expected = { 2, 1, 4, 8 };

            {
                FooPtr foo_ptr(new Foo(2));
                foo_vector.push_back(foo_ptr);

                foo_ptr.reset(new Foo(1));
                foo_vector.push_back(foo_ptr);

                foo_ptr.reset(new Foo(4));
                foo_vector.push_back(foo_ptr);

                foo_ptr.reset(new Foo(8));
                foo_vector.push_back(foo_ptr);
            }

            ASSERT_EQ(foo_vector.size(), foo_vector_expected.size());
            for (::std::size_t ii = 0; ii < foo_vector.size(); ii++)
            {
                EXPECT_EQ(foo_vector[ii]->x, foo_vector_expected[ii]);
            }

            EXPECT_EQ(DelCnt, 0);
        }

        EXPECT_EQ(DelCnt, 15);
    }
}

