#include <gtest/gtest.h>
#include "CMakeTopLib.h"

namespace {
    TEST(ExtSpecific, IsExtendedLib)
    {
        EXPECT_TRUE(::CMakeTopLib::IsExtendedLib());
    }
}