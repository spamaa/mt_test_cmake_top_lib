#include <gtest/gtest.h>
#include "CMakeTopLib.h"

namespace {
    TEST(PlainSpecific, IsExtendedLib)
    {
        EXPECT_FALSE(::CMakeTopLib::IsExtendedLib());
    }
}