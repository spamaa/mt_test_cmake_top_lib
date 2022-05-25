// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/align/align.hpp>
#include <boost/align/is_aligned.hpp>

namespace {

    // run some code from examples
    template<std::size_t Alignment>
    void test()
    {
        char s[Alignment << 1];
        char* b = s;
        while (!boost::alignment::is_aligned(b, Alignment)) {
            ++b;
        }
        {
            std::size_t n = Alignment;
            void* p = b;
            void* q = boost::alignment::align(Alignment, 1, p, n);
            EXPECT_TRUE(q == p);
            EXPECT_TRUE(q == b);
            EXPECT_TRUE(boost::alignment::is_aligned(q, Alignment));
            EXPECT_TRUE(n == Alignment);
        }
        {
            std::size_t n = 0;
            void* p = b;
            void* q = boost::alignment::align(Alignment, 1, p, n);
            EXPECT_TRUE(q == 0);
            EXPECT_TRUE(p == b);
            EXPECT_TRUE(n == 0);
        }
        {
            std::size_t n = Alignment - 1;
            void* p = &b[1];
            void* q = boost::alignment::align(Alignment, 1, p, n);
            EXPECT_TRUE(q == 0);
            EXPECT_TRUE(p == &b[1]);
            EXPECT_TRUE(n == Alignment - 1);
        }
        {
            std::size_t n = Alignment;
            void* p = &b[1];
            void* q = boost::alignment::align(Alignment, 1, p, n);
            EXPECT_TRUE(q == p);
            EXPECT_TRUE(p == &b[Alignment]);
            EXPECT_TRUE(boost::alignment::is_aligned(q, Alignment));
            EXPECT_TRUE(n == 1);
        }
    }

    TEST(RunMethod, boostAlign)
    {
        test<1>();
        test<2>();
        test<4>();
        test<8>();
        test<16>();
        test<32>();
        test<64>();
        test<128>();
    }

}
