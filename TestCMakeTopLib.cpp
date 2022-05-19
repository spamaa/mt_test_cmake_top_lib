// CMakeApp.cpp : Defines the entry point for the application.
//

#include <gtest/gtest.h>

#if !defined (GOOGLETEST_SUPPORTED)
#	error "This file must be compiled with google test support enabled."
#endif

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}
