// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/concept_check.hpp>
#include <boost/concept_archetype.hpp>


namespace {

    // run some code from doc samples
    TEST(RunMethod, boostConceptCheck)
    {

        //===========================================================================
        // Basic Concepts
        {
            typedef ::boost::default_constructible_archetype<> foo;
            ::boost::function_requires< ::boost::DefaultConstructible<foo> >();
        }
        {
            typedef ::boost::assignable_archetype<> foo;
            ::boost::function_requires< ::boost::Assignable<foo> >();
        }
        {
            typedef ::boost::copy_constructible_archetype<> foo;
            ::boost::function_requires< ::boost::CopyConstructible<foo> >();
        }
        {
            typedef ::boost::sgi_assignable_archetype<> foo;
            ::boost::function_requires< ::boost::SGIAssignable<foo> >();
        }
        {
            typedef ::boost::copy_constructible_archetype<> foo;
            typedef ::boost::convertible_to_archetype<foo> convertible_to_foo;
            ::boost::function_requires< ::boost::Convertible<convertible_to_foo, foo> >();
        }
        {
            ::boost::function_requires< ::boost::Convertible<::boost::boolean_archetype, bool> >();
        }
        {
            typedef::boost::equality_comparable_archetype<> foo;
            ::boost::function_requires< ::boost::EqualityComparable<foo> >();
        }
        {
            typedef ::boost::less_than_comparable_archetype<> foo;
            ::boost::function_requires< ::boost::LessThanComparable<foo> >();
        }
        {
            typedef ::boost::comparable_archetype<> foo;
            ::boost::function_requires< ::boost::Comparable<foo> >();
        }
        {
            typedef ::boost::equal_op_first_archetype<> First;
            typedef ::boost::equal_op_second_archetype<> Second;
            ::boost::function_requires< ::boost::EqualOp<First, Second> >();
        }
        {
            typedef ::boost::not_equal_op_first_archetype<> First;
            typedef ::boost::not_equal_op_second_archetype<> Second;
            ::boost::function_requires< ::boost::NotEqualOp<First, Second> >();
        }
        {
            typedef ::boost::less_than_op_first_archetype<> First;
            typedef ::boost::less_than_op_second_archetype<> Second;
            ::boost::function_requires< ::boost::LessThanOp<First, Second> >();
        }
        {
            typedef ::boost::less_equal_op_first_archetype<> First;
            typedef ::boost::less_equal_op_second_archetype<> Second;
            ::boost::function_requires< ::boost::LessEqualOp<First, Second> >();
        }
        {
            typedef ::boost::greater_than_op_first_archetype<> First;
            typedef ::boost::greater_than_op_second_archetype<> Second;
            ::boost::function_requires< ::boost::GreaterThanOp<First, Second> >();
        }
        {
            typedef ::boost::greater_equal_op_first_archetype<> First;
            typedef ::boost::greater_equal_op_second_archetype<> Second;
            ::boost::function_requires<::boost::GreaterEqualOp<First, Second> >();
        }

        {
            typedef ::boost::copy_constructible_archetype<> Return;
            typedef ::boost::plus_op_first_archetype<Return> First;
            typedef ::boost::plus_op_second_archetype<Return> Second;
            ::boost::function_requires< ::boost::PlusOp<Return, First, Second> >();
        }
    }
}