// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/system/error_condition.hpp>
#include <boost/core/lightweight_test.hpp>

namespace {
    // run some code from doc examples
    TEST(RunMethod, boostSystemConditionTest)
    {
        ::boost::system::error_condition en;

        EXPECT_EQ(en.value(), 0);
        EXPECT_FALSE(en);

        ::boost::system::error_condition en2(en);

        EXPECT_TRUE(en == en2);
        EXPECT_FALSE(en != en2);

        en2.assign(1, en.category());

        EXPECT_EQ(en2.value(), 1);
        EXPECT_TRUE(en2);

        EXPECT_FALSE(en == en2);
        EXPECT_TRUE(en != en2);
    }

}