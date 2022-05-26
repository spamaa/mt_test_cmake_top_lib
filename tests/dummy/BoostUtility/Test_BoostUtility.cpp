// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/utility/value_init.hpp>
#include <boost/core/lightweight_test.hpp>

namespace {
    // run some code from doc examples

  // Typical use case for boost::initialized<T>: A generic class that 
  // holds a value of type T, which must be initialized by either 
  // value-initialization or direct-initialization.
    template <class T> class key_value_pair
    {
        std::string m_key;
        boost::initialized<T> m_value;
    public:

        // Value-initializes the object held by m_value.
        key_value_pair() { }

        // Value-initializes the object held by m_value.
        explicit key_value_pair(const std::string& key)
            :
            m_key(key)
        {
        }

        // Direct-initializes the object held by m_value.
        key_value_pair(const std::string& key, const T& value)
            :
            m_key(key), m_value(value)
        {
        }

        const T& get_value() const
        {
            return m_value;
        }
    };


    // Tells whether the argument is value-initialized.
    bool is_value_initialized(const int& arg)
    {
        return arg == 0;
    }


    // Tells whether the argument is value-initialized.
    bool is_value_initialized(const std::string& arg)
    {
        return arg.empty();
    }

    struct foo
    {
        int data;
    };

    bool operator==(const foo& lhs, const foo& rhs)
    {
        return lhs.data == rhs.data;
    }


    // Tells whether the argument is value-initialized.
    bool is_value_initialized(const foo& arg)
    {
        return arg.data == 0;
    }


    template <class T>
    void test_key_value_pair(const T& magic_value)
    {
        // The value component of a default key_value_pair must be value-initialized.
        key_value_pair<T> default_key_value_pair;
        EXPECT_TRUE(is_value_initialized(default_key_value_pair.get_value()));

        // The value component of a key_value_pair that only has its key explicitly specified
        // must also be value-initialized.
        EXPECT_TRUE(is_value_initialized(key_value_pair<T>("key").get_value()));

        // However, the value component of the following key_value_pair must be 
        // "magic_value", as it must be direct-initialized.
        EXPECT_TRUE(key_value_pair<T>("key", magic_value).get_value() == magic_value);
    }

    TEST(RunMethod, boostUtilMagicNumber)
    {
        const int magic_number = 42;
        test_key_value_pair(magic_number);
    }

    TEST(RunMethod, boostUtilMagicValue)
    {
        const std::string magic_string = "magic value";
        test_key_value_pair(magic_string);
    }

    TEST(RunMethod, boostUtilMagicFoo)
    {
        const foo magic_foo = { 42 };
        test_key_value_pair(magic_foo);
    }
}