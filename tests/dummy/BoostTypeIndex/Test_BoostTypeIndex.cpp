// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/type_index.hpp>

namespace {
    TEST(RunMethod, boostTypeIndex)
    {
        EXPECT_EQ(::boost::typeindex::type_id<int>().pretty_name(), "int");
        EXPECT_EQ(::boost::typeindex::type_id<double>().pretty_name(), "double");

        EXPECT_EQ(::boost::typeindex::type_id<int>().name(), ::boost::typeindex::type_id<int>().name());
        EXPECT_NE(::boost::typeindex::type_id<int>().name(), ::boost::typeindex::type_id<double>().name());
        EXPECT_NE(::boost::typeindex::type_id<double>().name(), ::boost::typeindex::type_id<int>().name());
        EXPECT_EQ(::boost::typeindex::type_id<double>().name(), ::boost::typeindex::type_id<double>().name());
    }
}