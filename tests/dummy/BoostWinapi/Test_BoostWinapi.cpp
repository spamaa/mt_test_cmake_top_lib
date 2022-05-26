// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <limits>
#include <boost/winapi/handles.hpp>
#include <boost/winapi/semaphore.hpp>


namespace {

    // run some sample code from documentation
    TEST(RunMethod, boostWinapiSemaphore)
    {
        boost::winapi::HANDLE_ h = boost::winapi::CreateSemaphoreExW(
            NULL,                                                        // security attributes
            0l,                                                          // initial count
            std::numeric_limits< boost::winapi::LONG_ >::max(),          // max count
            L"Local\\MySemaphore",                                       // semaphore name
            0l,                                                          // flags
            boost::winapi::SEMAPHORE_ALL_ACCESS_                         // access mode
        );

        EXPECT_TRUE(h);
        if (h)
            boost::winapi::CloseHandle(h);
    }
}