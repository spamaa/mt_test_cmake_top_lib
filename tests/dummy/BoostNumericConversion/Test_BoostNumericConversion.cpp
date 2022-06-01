// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/numeric/conversion/converter.hpp>


namespace {
    TEST(RunMethod, boostNumricConversion)
    {
        // run some code sample

        typedef boost::numeric::converter<int, double> Double2Int;

        int x = Double2Int::convert(2.0);
        EXPECT_EQ(x, 2);

        int y = Double2Int()(3.14); // As a function object.
        EXPECT_EQ(y, 3);

        double m = boost::numeric::bounds<double>::highest();
        EXPECT_THROW(Double2Int::convert(m), ::boost::numeric::positive_overflow);
    }
}