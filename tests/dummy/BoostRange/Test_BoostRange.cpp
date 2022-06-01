// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/iterator_range.hpp>
#include <boost/range/sub_range.hpp>
#include <array>
#include <iterator>
#include <iostream>

namespace {
    TEST(RunMethod, boostRange)
    {
        // use something from module
        std::array<int, 6> a{ {0, 1, 2, 3, 4, 5} };
        boost::iterator_range<std::array<int, 6>::iterator> r1 =
            boost::random_shuffle(a);
        boost::sub_range<std::array<int, 6>> r2 =
            boost::random_shuffle(r1);
        boost::copy(r2, std::ostream_iterator<int>{std::cout, ","});
    }
}