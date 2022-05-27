// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/function.hpp>
#include <cmath>

namespace {
    // run some code from doc examples

    void do_sum_avg(int values[], int n, int& sum, float& avg)
    {
        sum = 0;
        for (int i = 0; i < n; i++)
            sum += values[i];
        avg = (float)sum / n;
    }

    TEST(RunMethod, boostFunction)
    {
        boost::function<void(int*, int, int&, float&)> sum_avg;
        sum_avg = &do_sum_avg;

        int values[5] = { 1, 1, 2, 3, 5 };
        int sum;
        float avg;
        sum_avg(values, 5, sum, avg);

        EXPECT_EQ(sum, 12);
        EXPECT_LE(abs(avg - 2.4), 0.000001);
    }
}