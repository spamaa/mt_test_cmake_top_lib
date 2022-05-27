// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>

#include <boost/fusion/functional/generation/make_fused.hpp>

#include <boost/noncopyable.hpp>
#include <boost/mpl/empty_base.hpp>

#include <boost/fusion/container/generation/make_vector.hpp>
#include <boost/fusion/container/vector.hpp>

namespace {
    template <class Base = boost::mpl::empty_base>
    struct test_func
        : Base
    {
        typedef int result_type;

        template <typename T0, typename T1>
        int operator()(T0 const& x, T1 const& y) const
        {
            return 1 + x - y;
        }

        template <typename T0, typename T1>
        int operator()(T0 const& x, T1 const& y)
        {
            return 2 + x - y;
        }

        template <typename T0, typename T1>
        int operator()(T0& x, T1& y) const
        {
            return 3 + x - y;
        }

        template <typename T0, typename T1>
        int operator()(T0& x, T1& y)
        {
            return 4 + x - y;
        }
    };

    template <typename T>
    inline T const& const_(T const& t)
    {
        return t;
    }

    TEST(RunMethod, fromBoostConfig)
    {
        // run some code from doc samples

        ::boost::fusion::vector<int, char> lv_vec(1, '\004');
        test_func<> f;
        test_func<::boost::noncopyable> f_nc;

        ::boost::fusion::result_of::make_fused< test_func<> >::type fused_func
            = ::boost::fusion::make_fused(f);

        EXPECT_TRUE(fused_func(lv_vec) == 1);
        EXPECT_TRUE(const_(fused_func)(lv_vec) == 0);
        EXPECT_TRUE(::boost::fusion::make_fused(const_(f))(lv_vec) == 1);
        EXPECT_TRUE(::boost::fusion::make_fused(::boost::ref(f_nc))(lv_vec) == 1);
        EXPECT_TRUE(::boost::fusion::make_fused(::boost::cref(f_nc))(lv_vec) == 0);

        EXPECT_TRUE(fused_func(::boost::fusion::make_vector(2, '\003')) == 1);
        EXPECT_TRUE(const_(fused_func)(::boost::fusion::make_vector(2, '\003')) == 0);
        EXPECT_TRUE(::boost::fusion::make_fused(const_(f))(::boost::fusion::make_vector(2, '\003')) == 1);
        EXPECT_TRUE(::boost::fusion::make_fused(::boost::ref(f_nc))(::boost::fusion::make_vector(2, '\003')) == 1);
        EXPECT_TRUE(::boost::fusion::make_fused(::boost::cref(f_nc))(::boost::fusion::make_vector(2, '\003')) == 0);

    }
}