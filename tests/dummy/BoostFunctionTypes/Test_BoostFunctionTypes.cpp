// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/mpl/assert.hpp>
#include <boost/function_types/is_function.hpp>


namespace {
    namespace ft = boost::function_types;

    typedef void func();
    typedef void (*func_ptr)();
    typedef void(&func_ref)();
    class C;
    typedef void (C::* mem_func_ptr)();
    typedef void (C::* c_mem_func_ptr)() const;
    typedef void (C::* v_mem_func_ptr)() volatile;
    typedef void (C::* cv_mem_func_ptr)() const volatile;


    TEST(RunMethod, boostFunctionTypes)
    {
        // run some code from doc samples
        BOOST_MPL_ASSERT((
            ft::is_function< func >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< func_ptr >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< func_ref >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< mem_func_ptr >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< c_mem_func_ptr >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< v_mem_func_ptr >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< cv_mem_func_ptr >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< func_ptr* >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< mem_func_ptr* >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< C >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< int >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< int* >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< int** >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< int& >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< int[] >
            ));

        BOOST_MPL_ASSERT_NOT((
            ft::is_function< int[1] >
            ));
    }
}