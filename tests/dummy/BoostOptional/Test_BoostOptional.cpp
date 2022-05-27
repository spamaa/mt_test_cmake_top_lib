// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include "boost/optional/optional.hpp"

namespace {
    TEST(RunMethod, fromBoostConfig)
    {
        // run some code from doc sources
        boost::optional<int> oa, ob(1);
        EXPECT_TRUE(!oa);
        EXPECT_TRUE(ob);

        oa = ob;
        EXPECT_TRUE(oa);
    }
}