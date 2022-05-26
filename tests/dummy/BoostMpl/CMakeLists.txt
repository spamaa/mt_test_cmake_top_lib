############################################################################
# $tests/dummy/BoostMpl$
# This target verifies runs some test for the boost-mpl
############################################################################

#find required deps
find_package(Boost REQUIRED)

# set executable name
set (TARGET_NAME TestBoostMpl)
# set the main file
set (${TARGET_NAME}_main ${${PROJECT_NAME}_ROOT_DIR}/TestCMakeTopLib.cpp)

# set sources. In this case we do not search recursively
include ("${CMAKE_CURRENT_LIST_DIR}/cxx_sources.cmake")

# add test target
matterfi_add_test_target(${PROJECT_NAME} ${TARGET_NAME} ${${TARGET_NAME}_cxx_sources})

# add required linking 
target_link_libraries(${TARGET_NAME}
    PRIVATE
        Boost::boost
)