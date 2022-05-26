// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/io/ostream_put.hpp>
#include <sstream>

namespace {
    // run some code from doc examples
    TEST(RunMethod, boostIo01)
    {
        std::ostringstream os;
        os.width(1);
        os.fill('.');
        os.setf(std::ios_base::left, std::ios_base::adjustfield);
        boost::io::ostream_put(os, "xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == "xy");
    }

    TEST(RunMethod, boostIo02)
    {
        std::wostringstream os;
        os.width(1);
        os.fill(L'.');
        os.setf(std::ios_base::left, std::ios_base::adjustfield);
        boost::io::ostream_put(os, L"xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == L"xy");
    }

    TEST(RunMethod, boostIo03)
    {
        std::ostringstream os;
        os.width(1);
        os.fill('.');
        os.setf(std::ios_base::right, std::ios_base::adjustfield);
        boost::io::ostream_put(os, "xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == "xy");
    }

    TEST(RunMethod, boostIo04)
    {
        std::wostringstream os;
        os.width(1);
        os.fill(L'.');
        os.setf(std::ios_base::right, std::ios_base::adjustfield);
        boost::io::ostream_put(os, L"xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == L"xy");
    }

    TEST(RunMethod, boostIo05)
    {
        std::ostringstream os;
        os.width(4);
        os.fill('.');
        os.setf(std::ios_base::left, std::ios_base::adjustfield);
        boost::io::ostream_put(os, "xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == "xy..");
    }

    TEST(RunMethod, boostIo06)
    {
        std::wostringstream os;
        os.width(4);
        os.fill(L'.');
        os.setf(std::ios_base::left, std::ios_base::adjustfield);
        boost::io::ostream_put(os, L"xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == L"xy..");
    }

    TEST(RunMethod, boostIo07)
    {
        std::ostringstream os;
        os.width(4);
        os.fill('.');
        os.setf(std::ios_base::right, std::ios_base::adjustfield);
        boost::io::ostream_put(os, "xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == "..xy");
    }

    TEST(RunMethod, boostIo08)
    {
        std::wostringstream os;
        os.width(4);
        os.fill(L'.');
        os.setf(std::ios_base::right, std::ios_base::adjustfield);
        boost::io::ostream_put(os, L"xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == L"..xy");
    }

    TEST(RunMethod, boostIo09)
    {
        std::ostringstream os;
        os.width(12);
        os.fill('.');
        os.setf(std::ios_base::left, std::ios_base::adjustfield);
        boost::io::ostream_put(os, "xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == "xy..........");
    }

    TEST(RunMethod, boostIo10)
    {
        std::wostringstream os;
        os.width(12);
        os.fill(L'.');
        os.setf(std::ios_base::left, std::ios_base::adjustfield);
        boost::io::ostream_put(os, L"xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == L"xy..........");
    }

    TEST(RunMethod, boostIo11)
    {
        std::ostringstream os;
        os.width(12);
        os.fill('.');
        os.setf(std::ios_base::right, std::ios_base::adjustfield);
        boost::io::ostream_put(os, "xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == "..........xy");
    }

    TEST(RunMethod, boostIo12)
    {
        std::wostringstream os;
        os.width(12);
        os.fill(L'.');
        os.setf(std::ios_base::right, std::ios_base::adjustfield);
        boost::io::ostream_put(os, L"xy", 2);
        EXPECT_TRUE(os.good());
        EXPECT_TRUE(os.width() == 0);
        EXPECT_TRUE(os.str() == L"..........xy");
    }

}