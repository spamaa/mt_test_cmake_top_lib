############################################################################
# $tests/dummy$
# This cmake adds all dummy tests (tests which verifies only if depenendency
# is correctly added)
############################################################################

add_subdirectory(GTest)
add_subdirectory(StaticLib)
add_subdirectory(TopLib)
add_subdirectory(BoostConfig)
add_subdirectory(AllDeps)
add_subdirectory(BoostPreprocessor)
add_subdirectory(BoostDetail)
add_subdirectory(BoostAssert)
add_subdirectory(BoostStaticAssert)
add_subdirectory(BoostCore)
add_subdirectory(BoostTypeTraits)