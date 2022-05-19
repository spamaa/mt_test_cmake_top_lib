message (STATUS "!!!! BBB CMAKE_CURRENT_LIST_DIR: '${CMAKE_CURRENT_LIST_DIR}' !!!!")
message (STATUS "!!!! BBB CMAKE_CURRENT_SOURCE_DIR: '${CMAKE_CURRENT_SOURCE_DIR}' !!!!")

function(add_matterfi_test_target
    _project_name
    _target_name
)
    set (cxx_test_sources ${ARGN})

    # add sources to test test executable
    add_executable(${_target_name} ${${_target_name}_main} ${cxx_test_sources})

    # set runtime type for msvc compilation
    matterfi_set_msvc_type(${_target_name})

    # enable sanitizer
    matterfi_enable_msvc_asan(${_target_name})

    target_compile_definitions(
        ${_target_name} PRIVATE
        GOOGLETEST_SUPPORTED
    )

    target_include_directories(${_target_name} PRIVATE
        ${${_project_name}_ROOT_DIR}/tests
    )

    target_link_libraries(${_target_name} 
        PRIVATE 
            GTest::gmock
            GTest::gtest
    )

    set_target_properties( ${_target_name}
        PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/tests
    )

    add_test(${_target_name}
        ${PROJECT_BINARY_DIR}/tests/${_target_name}
        --gtest_output=xml:gtestresult.xml
    )

endfunction(add_matterfi_test_target)

add_subdirectory(dummy)