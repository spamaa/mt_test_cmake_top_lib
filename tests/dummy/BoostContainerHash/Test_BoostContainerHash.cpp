// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

// Force use of assert.
#if defined(NDEBUG)
#undef NDEBUG
#endif

#include <boost/container_hash/hash.hpp>


namespace {
    class point
    {
        int x;
        int y;
    public:
        point() : x(0), y(0) {}
        point(int x, int y) : x(x), y(y) {}

        bool operator==(point const& other) const
        {
            return x == other.x && y == other.y;
        }

        friend std::size_t hash_value(point const& p)
        {
            std::size_t seed = 0;
            boost::hash_combine(seed, p.x);
            boost::hash_combine(seed, p.y);

            return seed;
        }
    };

    TEST(RunMethod, boostContainerHash)
    {
        boost::hash<point> point_hasher;

        point p1(0, 0);
        point p2(1, 2);
        point p3(4, 1);
        point p4 = p1;

        ASSERT_TRUE(point_hasher(p1) == point_hasher(p4));

        // These tests could legally fail, but if they did it'd be a pretty bad
        // hash function.
        ASSERT_TRUE(point_hasher(p1) != point_hasher(p2));
        ASSERT_TRUE(point_hasher(p1) != point_hasher(p3));
    }

}