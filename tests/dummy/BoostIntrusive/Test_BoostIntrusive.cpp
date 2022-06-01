// Copyright (c) 2010-2022 The Open-Transactions developers
// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at http://mozilla.org/MPL/2.0/.

#include <gtest/gtest.h>
#include <boost/intrusive/list.hpp>
#include <vector>

namespace {

    // run some code from documentation


    class MyClass : public ::boost::intrusive::list_base_hook<>   //This is a derivation hook
    {
        int int_;

    public:
        //This is a member hook
        ::boost::intrusive::list_member_hook<> member_hook_;

        MyClass(int i)
            : int_(i)
        {}
    };

    //Define a list that will store MyClass using the public base hook
    typedef ::boost::intrusive::list<MyClass>   BaseList;

    //Define a list that will store MyClass using the public member hook
    typedef ::boost::intrusive::list< MyClass
        , ::boost::intrusive::member_hook< MyClass, ::boost::intrusive::list_member_hook<>, &MyClass::member_hook_>
    > MemberList;

    TEST(RunMethod, boostIntrusive)
    {
        typedef std::vector<MyClass>::iterator VectIt;

        //Create several MyClass objects, each one with a different value
        std::vector<MyClass> values;
        for (int i = 0; i < 100; ++i)  values.push_back(MyClass(i));

        BaseList baselist;
        MemberList memberlist;

        //Now insert them in the reverse order in the base hook list
        for (VectIt it(values.begin()), itend(values.end()); it != itend; ++it)
            baselist.push_front(*it);

        //Now insert them in the same order as in vector in the member hook list
        for (VectIt it(values.begin()), itend(values.end()); it != itend; ++it)
            memberlist.push_back(*it);

        //Now test lists
        {
            BaseList::reverse_iterator rbit(baselist.rbegin());
            MemberList::iterator mit(memberlist.begin());
            VectIt  it(values.begin()), itend(values.end());

            //Test the objects inserted in the base hook list
            for (; it != itend; ++it, ++rbit)
            {
                EXPECT_FALSE(&*rbit != &*it);
            }

            //Test the objects inserted in the member hook list
            for (it = values.begin(); it != itend; ++it, ++mit)
            {
                EXPECT_FALSE(&*mit != &*it);
            }
        }

    }
}