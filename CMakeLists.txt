cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)

project(exmpl)

set(GOOGLETEST_ROOT third-party/gtest/googletest CACHE STRING "Google Test source root")

include_directories(SYSTEM
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/include
    )

set(GOOGLETEST_SOURCES
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest-all.cc
    ${PROJECT_SOURCE_DIR}/${GOOGLETEST_ROOT}/src/gtest_main.cc
    )

foreach(_source ${GOOGLETEST_SOURCES})
    set_source_files_properties(${_source} PROPERTIES GENERATED 1)
endforeach()

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
endif()

if(BUILD_TESTS)
        enable_testing()
#        add_subdirectory(third-party/gtest)
        add_library(gtest ${GOOGLETEST_SOURCES})
        add_executable(tests ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)
        find_package (Threads)
        target_link_libraries(tests exmpl gtest ${CMAKE_THREAD_LIBS_INIT})
        target_link_libraries(tests exmpl gtest)
        add_test(NAME Test1 COMMAND tests)
endif()
