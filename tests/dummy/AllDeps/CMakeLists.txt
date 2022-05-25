############################################################################
# $tests/dummy/AllDeps$
# This target verifies if all deps can be linked together in one executable
############################################################################

#find required deps
find_package(Boost REQUIRED)

# set executable name
set (TARGET_NAME TestAllDeps)
# set the main file
set (${TARGET_NAME}_main ${${PROJECT_NAME}_ROOT_DIR}/TestCMakeTopLib.cpp)

# set sources. In this case we do not search recursively
#file (GLOB ${TARGET_NAME}_cxx_sources LIST_DIRECTORIES false "Test_*.cpp")

# add test target
set (ALLDEPS_CXX_SOURCES)
# add dummy tests for boost-config
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostConfig/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-preprocessor
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostPreprocessor/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-assert
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostAssert/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-static-assert
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostStaticAssert/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})

matterfi_add_test_target(${PROJECT_NAME} ${TARGET_NAME} ${ALLDEPS_CXX_SOURCES})

# add required linking 
target_link_libraries(${TARGET_NAME}
    PRIVATE
        Boost::boost
)
