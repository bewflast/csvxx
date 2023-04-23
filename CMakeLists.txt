cmake_minimum_required(VERSION 3.2)
project(CSVXX)

set(CMAKE_CXX_STANDARD 20)

SET(CSVXX_INCLUDES ${CMAKE_CURRENT_LIST_DIR}/include/)
SET(CSVXX_SOURCES ${CMAKE_CURRENT_LIST_DIR}/source/)

add_library(csvxx)
set_target_properties(csvxx PROPERTIES
                                PUBLIC_HEADER include/CSVXX.hpp)

add_subdirectory(${CSVXX_SOURCES})

add_subdirectory(tests)
enable_testing()