cmake_minimum_required(VERSION 3.27)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 20)

include_directories(ComplexNumClass)

add_executable(ComplexNumbers
        ComplexNumClass/ComplexNum.h
        ComplexNumClass/ComplexNum.cpp
        ComplexNumTests/ComplexNumTest.cpp)

add_subdirectory(ComplexNumTests/lib)

include_directories(ComplexNumTests/lib/googletest/include)

add_executable(ComplexNumTests_run ComplexNumTests/ComplexNumTest.cpp)

target_link_libraries(ComplexNumTests_run gtest gtest_main)