// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/chrono/chrono.hpp>
#include <boost/chrono/process_cpu_clocks.hpp>

namespace {

    TEST(RunMethod, boostChronoDuration)
    {
        EXPECT_EQ(((::boost::chrono::duration<double>)::boost::chrono::nanoseconds(3)).count(), 3.0e-09);
        EXPECT_EQ(((::boost::chrono::duration<double>)::boost::chrono::hours(3)).count(), 10800);
        EXPECT_EQ(((::boost::chrono::duration<double>)(::boost::chrono::hours(3) + ::boost::chrono::nanoseconds(-3))).count(), (10800. - 3.0e-09));
    }

    TEST(RunMethod, boostChronoRange)
    {
        using namespace boost::chrono;
        hours h1 = ::boost::chrono::hours(24 * (365 * 292 + 292 / 4));
        ::boost::chrono::nanoseconds n1 = h1 + ::boost::chrono::nanoseconds(1);
        ::boost::chrono::nanoseconds delta = n1 - h1;

        EXPECT_EQ(h1.count(), (24 * (365 * 292 + 292 / 4)));
        EXPECT_EQ(delta.count(), 1);
    }

    TEST(RunMethod, boostChronoProcessCpuClock)
    {
        // test if can use a symbol from lib
        auto now = ::boost::chrono::process_cpu_clock::now();
        auto now_ms = ::boost::chrono::time_point_cast<::boost::chrono::nanoseconds>(now);
        EXPECT_GT(now_ms.time_since_epoch().count(), 0);
    }

}