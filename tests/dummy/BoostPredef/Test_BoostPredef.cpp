// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/predef/version_number.h>
#include <boost/predef/other/workaround.h>

namespace {
    // run some code from doc examples

    struct test_info
    {
        std::string value;
        bool passed;

        test_info(std::string const& v, bool p) : value(v), passed(p) {}
        test_info(test_info const& o) : value(o.value), passed(o.passed) {}
    };

    std::vector<test_info> test_results;

    #define PREDEF_CHECK(X) test_results.push_back(test_info(#X,(X)))

    void test_BOOST_PREDEF_TESTED_AT()
    {
        PREDEF_CHECK(BOOST_PREDEF_TESTED_AT(BOOST_VERSION_NUMBER(15, 15, 15), 0xF, 0xF, 0xF));
        PREDEF_CHECK(BOOST_PREDEF_TESTED_AT(BOOST_VERSION_NUMBER(1, 0, 0), 1, 0, 0));
        PREDEF_CHECK(BOOST_PREDEF_TESTED_AT(BOOST_VERSION_NUMBER(0, 9, 0), 1, 0, 0));
        PREDEF_CHECK(BOOST_PREDEF_TESTED_AT(BOOST_VERSION_NUMBER(2, 0, 0), 1, 0, 0));
        PREDEF_CHECK(!BOOST_PREDEF_TESTED_AT(BOOST_VERSION_NUMBER_NOT_AVAILABLE, 1, 0, 0));
    }

    TEST(RunMacro, boostPredefTestedAt)
    {
        test_BOOST_PREDEF_TESTED_AT();
        EXPECT_EQ(test_results.size(), 5);
    }
}
