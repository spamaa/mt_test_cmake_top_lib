// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/throw_exception.hpp>
// override boost settings just for the test purpose
#define BOOST_ENABLE_NON_INTRUSIVE_EXCEPTION_PTR
#include <boost/exception/detail/clone_current_exception.hpp>

namespace {
    class my_exception : public std::exception { };

    TEST(RunMethod, boostException)
    {
        try
        {
            ::boost::throw_exception(my_exception());
            ASSERT_TRUE(false);         // should throw exception instead of be here
        }
        catch (my_exception& ex)
        {
            const ::boost::exception_detail::clone_base* clone = nullptr;
            // use some symbol from boost-exception lib, result is not important
            auto res = ::boost::exception_detail::clone_current_exception(clone);

            if (clone)
            {
                delete clone;
                clone = nullptr;
            }
        }
        catch (...)
        {
            EXPECT_TRUE(false);         // should not be here
        }
    }
}