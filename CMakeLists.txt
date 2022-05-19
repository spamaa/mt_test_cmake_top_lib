############################################################################
# $TOP$
# This is top level cmake for test project
############################################################################

cmake_minimum_required (VERSION 3.15)

project ("TestCMakeTopLib")

# this include must be after project
include ("${VCPKG_INSTALLED_DIR}/${MATTERFI_CMAKE_HOST_TRIPLET}/${MATTERFI_CMAKE_CONFIG_FILE}")
include (CTest)

# make vcpkg configuration checkings
matterfi_check_toolchain_file()
matterfi_check_triplets_location()
matterfi_check_triplet_file()
matterfi_check_vcpkg_modes()

set (${PROJECT_NAME}_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

enable_testing()

# gtest will be required for all tests
find_package(GTest CONFIG REQUIRED)


find_package(cmake-top-lib CONFIG REQUIRED)
find_package(cmake-static-lib CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)

add_subdirectory(tests)

# TODO: Add tests and install targets if needed.
