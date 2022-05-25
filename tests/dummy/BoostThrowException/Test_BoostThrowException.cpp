// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/throw_exception.hpp>

namespace {
    TEST(RunMacro, boostThrowException)
    {
        // run basic macro
        EXPECT_THROW(BOOST_THROW_EXCEPTION(::std::runtime_error("An error")), ::std::runtime_error);
    }

    // run basic function
    class my_exception : public ::std::exception {};
    TEST(RunMethod, boostThrowException)
    {
        my_exception e;
        EXPECT_THROW(::boost::throw_exception(e), my_exception);
    }
}
