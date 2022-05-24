// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/config.hpp>

namespace {
    TEST(CheckDep, boostConfig)
    {
        // this module defines only some configuarion macros for boost lib cmopilation,
        // which may differ at diefferent platforms, hence I am testing just if include works
        EXPECT_TRUE(true);
    }
}