// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/regex.hpp>
#include <string>

namespace {
    boost::regex e("(\\d{3,4})[- ]?(\\d{4})[- ]?(\\d{4})[- ]?(\\d{4})");

    bool is_possible_card_number(const std::string& input)
    {
        //
        // return false for partial match, true for full match, or throw for
        // impossible match based on what we have so far...
        boost::match_results<std::string::const_iterator> what;
        if (0 == boost::regex_match(input, what, e, boost::match_default | boost::match_partial))
        {
            // the input so far could not possibly be valid so reject it:
            throw std::runtime_error("Invalid data entered - this could not possibly be a valid card number");
        }
        // OK so far so good, but have we finished?
        if (what[0].matched)
        {
            // excellent, we have a result:
            return true;
        }
        // what we have so far is only a partial match...
        return false;
    }

    TEST(RunMethod, boostRegex)
    {
        const ::std::string ERR_DESC = { "some regex error" };
        // use some symbol from library
        try
        {
            ::boost::regex_error ex(ERR_DESC);
            ::boost::regex_error exCopy(ex);
            throw exCopy;
        }
        catch (::boost::regex_error exc)
        {
            EXPECT_EQ((::std::string)exc.what(), ERR_DESC);
        }
        catch (...)
        {
            // we should not be here
            EXPECT_TRUE(false);
        }
    }

    TEST(RunMethod, boostRegexValid)
    {
        EXPECT_TRUE(is_possible_card_number("4012 8888 8888 1881"));
    }

    TEST(RunMethod, boostRegexSimple)
    {
        std::string s("this subject has a submarine as a subsequence");
        boost::smatch m;
        boost::regex e("\\b(sub)([^ ]*)");   // matches words beginning by "sub"

        while (boost::regex_search(s, m, e)) {
            for (auto x : m) std::cout << x << " ";
            std::cout << std::endl;
            s = m.suffix().str();
        }
    }
}