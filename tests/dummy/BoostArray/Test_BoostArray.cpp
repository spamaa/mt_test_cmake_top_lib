// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/array.hpp>

namespace {

    // run some sample code from documentation
    template< class T >
    void    BadValue(const T&)
    {
        EXPECT_TRUE(false);
    }

    template< class T >
    void    RunTests()
    {
        typedef boost::array< T, 0 >    test_type;

        //  Test value and aggegrate initialization
        test_type                   test_case = {};
        const boost::array< T, 0 >  const_test_case = test_type();

        test_case.fill(T());

        //  front/back and operator[] must compile, but calling them is undefined
        //  Likewise, all tests below should evaluate to false, avoiding undefined behaviour
        EXPECT_TRUE(test_case.empty());
        EXPECT_TRUE(const_test_case.empty());

        EXPECT_TRUE(test_case.size() == 0);
        EXPECT_TRUE(const_test_case.size() == 0);

        //  Assert requirements of TR1 6.2.2.4
        EXPECT_TRUE(test_case.begin() == test_case.end());
        EXPECT_TRUE(test_case.cbegin() == test_case.cend());
        EXPECT_TRUE(const_test_case.begin() == const_test_case.end());
        EXPECT_TRUE(const_test_case.cbegin() == const_test_case.cend());

        EXPECT_TRUE(test_case.begin() != const_test_case.begin());
        if (test_case.data() == const_test_case.data()) {
            //  Value of data is unspecified in TR1, so no requirement this test pass or fail
            //  However, it must compile!
        }

        //  Check can safely use all iterator types with std algorithms
        std::for_each(test_case.begin(), test_case.end(), BadValue< T >);
        std::for_each(test_case.rbegin(), test_case.rend(), BadValue< T >);
        std::for_each(test_case.cbegin(), test_case.cend(), BadValue< T >);
        std::for_each(const_test_case.begin(), const_test_case.end(), BadValue< T >);
        std::for_each(const_test_case.rbegin(), const_test_case.rend(), BadValue< T >);
        std::for_each(const_test_case.cbegin(), const_test_case.cend(), BadValue< T >);

        //  Check swap is well formed
        std::swap(test_case, test_case);

        //  Check assignment operator and overloads are well formed
        test_case = const_test_case;

        //  Confirm at() throws the std lib defined exception
        try {
            BadValue(test_case.at(0));
        }
        catch (const std::out_of_range&) {
        }

        try {
            BadValue(const_test_case.at(0));
        }
        catch (const std::out_of_range&) {
        }
    }

    TEST(RunMethod, boostArray)
    {
        RunTests< bool >();
        RunTests< void* >();
        RunTests< long double >();
        RunTests< std::string >();
    }

    #ifndef BOOST_NO_CXX11_HDR_ARRAY
        template< class T >
        void    RunStdTests()
        {
            typedef boost::array< T, 5 >    test_type;
            test_type           test_case; //   =   { 1, 1, 2, 3, 5 };

            T& aRef = std::get<0>(test_case);
            EXPECT_TRUE(&*test_case.begin() == &aRef);

            const T& caRef = std::get<0>(test_case);
            EXPECT_TRUE(&*test_case.cbegin() == &caRef);
        }
    #endif

    template< class T >
    void    RunBoostTests()
    {
        typedef boost::array< T, 5 >    test_type;
        test_type           test_case; //   =   { 1, 1, 2, 3, 5 };

        T& aRef = boost::get<0>(test_case);
        EXPECT_TRUE(&*test_case.begin() == &aRef);

        const T& caRef = boost::get<0>(test_case);
        EXPECT_TRUE(&*test_case.cbegin() == &caRef);
    }

    TEST(RunMethod, boostAssertCompare)
    {
        RunBoostTests< bool >();
        RunBoostTests< void* >();
        RunBoostTests< long double >();
        RunBoostTests< std::string >();

        #ifndef BOOST_NO_CXX11_HDR_ARRAY
            RunStdTests< bool >();
            RunStdTests< void* >();
            RunStdTests< long double >();
            RunStdTests< std::string >();
        #endif
    }
}