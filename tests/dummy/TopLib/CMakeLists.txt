############################################################################
# $tests/dummy/TopLib$
# This target verifies if CMaakeTopLib is linked correctly
############################################################################

# find required deps
find_package(cmake-static-lib CONFIG REQUIRED)
find_package(cmake-top-lib CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

# Version for standard cmake-top-lib library
# set executable name
set (TARGET_NAME TestCMakeTopLib)
# set the main cpp file
set (${TARGET_NAME}_main ${${PROJECT_NAME}_ROOT_DIR}/TestCMakeTopLib.cpp)

# set sources. In this case we do not search recursively
set (${TARGET_NAME}_cxx_sources Test_AboutTest.cpp Plain/Test_PlainSpecific.cpp)

# add test target
matterfi_add_test_target(${PROJECT_NAME} ${TARGET_NAME} ${${TARGET_NAME}_cxx_sources})

# add required linking
target_link_libraries(${TARGET_NAME}
    PRIVATE
        CMakeTopLib::CMakeTopLib
)


# Version for extended cmake-top-lib library
# set the main cpp file
set (TARGET_NAME TestCMakeTopLibExt)
set (${TARGET_NAME}_main ${${PROJECT_NAME}_ROOT_DIR}/TestCMakeTopLib.cpp)

# set sources. In this case we do not search recursively
set (${TARGET_NAME}_cxx_sources Test_AboutTest.cpp Ext/Test_ExtSpecific.cpp)

# add test target
matterfi_add_test_target(${PROJECT_NAME} ${TARGET_NAME} ${${TARGET_NAME}_cxx_sources})

# add required linking
target_link_libraries(${TARGET_NAME}
    PRIVATE
        CMakeTopLib::CMakeTopLib-ext
)

