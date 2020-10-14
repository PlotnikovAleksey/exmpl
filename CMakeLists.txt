cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

project(exmpl)

add_library(exmpl STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/source/source.cpp
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#for tests
#$ mkdir third-party
#$ git submodule add https://github.com/google/googletest third-party/gtest
#$ cd third-party/gtest && git checkout release-1.8.1 && cd ../..

if (MSVC)
    # VS 2017 removed tr1
    add_definitions(-DGTEST_HAS_TR1_TUPLE=0)

if(BUILD_TESTS)
        enable_testing()
        add_subdirectory(third-party/gtest)
        add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)
        target_link_libraries(tests exmpl gtest_main)
        add_test(NAME Test1 COMMAND tests)
endif()
