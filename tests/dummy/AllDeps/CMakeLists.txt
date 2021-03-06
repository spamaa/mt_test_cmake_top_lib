############################################################################
# $tests/dummy/AllDeps$
# This target verifies if all deps can be linked together in one executable
############################################################################

#find required deps
find_package(Boost REQUIRED COMPONENTS
    system
    chrono
    exception
    regex
)

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
#add dummy tests from boost-core
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostCore/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-type-traits
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostTypeTraits/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-throw-exception
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostThrowException/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-align
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostAlign/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-array
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostArray/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-bind
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostBind/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-predef
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostPredef/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-winapi
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostWinapi/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-system
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostSystem/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-integer
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostInteger/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-move
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostMove/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-mpl
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostMpl/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-ratio
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostRatio/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-detail
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostDetail/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-container-hash
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostContainerHash/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-io
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostIo/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-utility
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostUtility/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-typeof
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostTypeOf/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-chrono
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostChrono/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-shared-ptr
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostSharedPtr/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-tuple
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostTuple/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-exception
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostException/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-concept-check
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostConceptCheck/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-type-index
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostTypeIndex/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-function
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostFunction/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-conversion
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostConversion/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-function-types
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostFunctionTypes/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-fusion
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostFusion/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-optional
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostOptional/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-iterator
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostIterator/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-regex
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostRegex/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-numeric-conversion
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostNumericConversion/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-range
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostRange/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-intrusive
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostIntrusive/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})
#add dummy tests from boost-container
include ("${CMAKE_CURRENT_LIST_DIR}/../BoostContainer/cxx_sources.cmake")
list (APPEND ALLDEPS_CXX_SOURCES ${${TARGET_NAME}_cxx_sources})

matterfi_add_test_target(${PROJECT_NAME} ${TARGET_NAME} ${ALLDEPS_CXX_SOURCES})

# add required linking 
target_link_libraries(${TARGET_NAME}
    PRIVATE
        Boost::boost
        Boost::system
        Boost::chrono
        Boost::exception
        Boost::regex
)
