cmake_minimum_required(VERSION 3.27)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 20)

include_directories(ComplexNumClass)

add_executable(ComplexNumbers
        ComplexNumClass/ComplexNum.cpp
        ComplexNumClass/ComplexNum.h)
