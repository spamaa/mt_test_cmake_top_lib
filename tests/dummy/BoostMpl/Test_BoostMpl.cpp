// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/mpl/inherit_linearly.hpp>
#include <boost/mpl/int.hpp>
#include <boost/mpl/list.hpp>

namespace {
    // run some code from doc examples

    template< typename Base, typename T >
    struct tuple_part
        : Base
    {
        typedef tuple_part type; // note the typedef
        typedef typename Base::index::next index;

        friend T& field(tuple_part& t, index) { return t.field_; }
        T field_;
    };

    struct empty_tuple
    {
        typedef ::boost::mpl::int_<-1> index;
    };


    typedef ::boost::mpl::inherit_linearly<
        ::boost::mpl::list<int, char const*, bool>
        , tuple_part<::boost::mpl::placeholders::_, ::boost::mpl::placeholders::_>
        , empty_tuple
    >::type my_tuple;


    TEST(RunMethod, boostMpl)
    {
        my_tuple t;

        field(t, ::boost::mpl::int_<0>()) = -1;
        field(t, ::boost::mpl::int_<1>()) = "text";
        field(t, ::boost::mpl::int_<2>()) = false;

        EXPECT_EQ(field(t, ::boost::mpl::int_<0>()), -1);
        EXPECT_EQ((::std::string)field(t, ::boost::mpl::int_<1>()), "text");
        EXPECT_EQ(field(t, ::boost::mpl::int_<2>()), false);
    }
}