// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/container/vector.hpp>
#include <boost/static_assert.hpp>
#include <boost/core/no_exceptions_support.hpp>


//Make sure assertions are active
#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>

namespace {
    TEST(RunMethod, boostContainer)
    {
        //This option specifies that a vector that will use "unsigned char" as
        //the type to store capacity or size internally.
        typedef ::boost::container::vector_options< ::boost::container::stored_size<unsigned char> >::type size_option_t;

        //Size-optimized vector is smaller than the default one.
        typedef ::boost::container::vector<int, ::boost::container::new_allocator<int>, size_option_t > size_optimized_vector_t;
        ASSERT_TRUE(sizeof(size_optimized_vector_t) < sizeof(::boost::container::vector<int>));

        //Requesting capacity for more elements than representable by "unsigned char"
        //is an error in the size optimized vector.
        bool exception_thrown = false;

        EXPECT_ANY_THROW(size_optimized_vector_t v(256));

        //This option specifies that a vector will increase its capacity 50%
        //each time the previous capacity was exhausted.
        typedef ::boost::container::vector_options< ::boost::container::growth_factor<::boost::container::growth_factor_50> >::type growth_50_option_t;

        //Fill the vector until full capacity is reached
        ::boost::container::vector<int, ::boost::container::new_allocator<int>, growth_50_option_t > growth_50_vector(5, 0);
        const std::size_t old_cap = growth_50_vector.capacity();
        growth_50_vector.resize(old_cap);

        //Now insert an additional item and check the new buffer is 50% bigger
        growth_50_vector.push_back(1);
        EXPECT_EQ(growth_50_vector.capacity(), old_cap * 3 / 2);
    }
}