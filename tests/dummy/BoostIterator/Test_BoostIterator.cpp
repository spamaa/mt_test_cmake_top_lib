// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/iterator/distance.hpp>

namespace {
    int twice(int x) { return x + x; }

    template <typename Iterator>
    void test_distance(Iterator it_from, Iterator it_to, int n)
    {
        EXPECT_TRUE(boost::distance(it_from, it_to) == n);
    }

    TEST(RunMethod, boostIterator)
    {
        // run some code from doc samples

        int array[3] = { 1, 2, 3 };
        int* ptr1 = array;
        int* ptr2 = array + 3;

        test_distance(ptr1, ptr2, 3);
        test_distance(ptr2, ptr1, -3);
    }
}