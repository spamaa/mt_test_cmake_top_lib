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
//        assert(x == 2);

        int y = Double2Int()(3.14); // As a function object.
//        assert(y == 3); // The default rounding is trunc.

        try
        {
            double m = boost::numeric::bounds<double>::highest();
//            int z = Double2Int::convert(m); // By default throws positive_overflow()
        }
        catch (boost::numeric::positive_overflow const&)
        {
            ASSERT_TRUE(false);
            // should not be here
        }
    }
}