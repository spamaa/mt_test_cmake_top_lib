// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/ratio/ratio_io.hpp>

namespace {

    // run some code from doc examples
    TEST(RunMethod, boostRatio)
    {
        EXPECT_EQ((::std::string)(::boost::ratio_string<boost::deca, char>::prefix()), "deca");
        EXPECT_EQ((::std::string)(::boost::ratio_string<boost::deca, char>::symbol()), "da");;

        EXPECT_EQ((::std::string)(::boost::ratio_string<boost::giga, char>::prefix()), "giga");;
        EXPECT_EQ((::std::string)(::boost::ratio_string<boost::giga, char>::symbol()), "G");

        EXPECT_EQ((::std::string)(::boost::ratio_string<boost::ratio<4, 6>, char>::prefix()), "[2/3]");
        EXPECT_EQ((::std::string)(::boost::ratio_string<boost::ratio<4, 6>, char>::symbol()), "[2/3]");
    }
}