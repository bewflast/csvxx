cmake_minimum_required(VERSION 3.2)

project("gtest")

set(SOURCES test_memmap.cpp
            test_file.cpp
            test_uniquefd.cpp
            test_filebase.cpp)
set(BUILD_SHARED_LIBS OFF)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(TEST_DATA_DIR ${CMAKE_CURRENT_SOURCE_DIR}/data)
add_custom_target(copy_test_data ALL COMMAND ${CMAKE_COMMAND} -E copy_directory ${TEST_DATA_DIR} ${CMAKE_CURRENT_BINARY_DIR}/data)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

enable_testing()


add_executable(CSV_tests ${SOURCES})
add_dependencies(CSV_tests copy_test_data)

target_include_directories(CSV_tests PRIVATE ${CSVXX_INCLUDES}/private)
target_link_libraries(CSV_tests csvxx)
target_link_libraries(CSV_tests gtest_main)
