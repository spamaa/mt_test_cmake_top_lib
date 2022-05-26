// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
 #include <boost/blank.hpp>

namespace {
    TEST(RunMethod, fromBoostDetail)
    {
        
        // run some sample code from boost documentation
        boost::blank b1, b2;
        EXPECT_TRUE(b1 == b2);
        EXPECT_TRUE(b1 <= b2);
        EXPECT_TRUE(b1 >= b2);
        EXPECT_TRUE(!(b1 != b2));
        EXPECT_TRUE(!(b1 < b2));
        EXPECT_TRUE(!(b1 > b2));
    }
}