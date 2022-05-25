// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/type_traits/has_plus_assign.hpp>

namespace {
    // run some example from documentation
    namespace detail {
        template < class Iterator, class Distance, bool has_plus_assign >
        struct advance_impl;

        // this is used if += exists (efficient)
        template < class Iterator, class Distance >
        struct advance_impl<Iterator, Distance, true> {
            void operator()(Iterator& i, Distance n) {
                i += n;
            }
        };

        // this is use if += does not exists (less efficient but cannot do better)
        template < class Iterator, class Distance >
        struct advance_impl<Iterator, Distance, false> {
            void operator()(Iterator& i, Distance n) {
                if (n > 0) {
                    while (n--) ++i;
                }
                else {
                    while (n++) --i;
                }
            }
        };
    } // namespace detail

    template < class Iterator, class Distance >
    inline void advance(Iterator& i, Distance n) {
        detail::advance_impl< Iterator, Distance, ::boost::has_plus_assign<Iterator>::value >()(i, n);
    }

    class with {
        int m_i;
    public:
        with(int i = 0) : m_i(i) { }
        with& operator+=(int rhs) { m_i += rhs; return *this; }
        operator int const () { return m_i; }
    };

    class without {
        int m_i;
    public:
        without(int i = 0) : m_i(i) { }
        without& operator++() { ++m_i; return *this; }
        without& operator--() { --m_i; return *this; }
        operator int const () { return m_i; }
    };

    TEST(RunMethod, boostTypeTraitsHasPlusAssign)
    {
        with i = 0;
        advance(i, 10); // uses +=
        without j = 0;
        advance(j, 10); // uses ++

        EXPECT_EQ((int)i, (int)j);
        EXPECT_EQ((int)i, 10);
    }
}