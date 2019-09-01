cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(exmpl)

add_library(exmpl STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/source/source.cpp
)
add_executable(tests
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

enable_testing()
#for tests
#$ mkdir third-party
#$ git submodule add https://github.com/google/googletest third-party/gtest
#$ cd third-party/gtest && git checkout release-1.8.1 && cd ../..

add_subdirectory(third-party/gtest)

target_link_libraries(tests exmpl gtest_main gmock_main)

add_test(NAME Test1 COMMAND tests)