############################################################################
# $tests/dummy/StaticLib$
# This target verifies if CMakeStaticLib is linked correctly
############################################################################

# find required deps
find_package(cmake-static-lib CONFIG REQUIRED)

# set executable name
set (TARGET_NAME TestCMakeStaticLib)
# set the main cpp file
set (${TARGET_NAME}_main ${${PROJECT_NAME}_ROOT_DIR}/TestCMakeTopLib.cpp)

# set sources. In this case we do not search recursively
file (GLOB ${TARGET_NAME}_cxx_sources LIST_DIRECTORIES false "Test_*.cpp")

# add test target
matterfi_add_test_target(${PROJECT_NAME} ${TARGET_NAME} ${${TARGET_NAME}_cxx_sources})

# add required linking
target_link_libraries(${TARGET_NAME}
    PRIVATE
        CMakeStaticLib::CMakeStaticLib
)

