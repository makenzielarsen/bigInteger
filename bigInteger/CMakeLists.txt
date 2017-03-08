cmake_minimum_required(VERSION 3.6)
project(bigInteger)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    "Assign4 - Big Integer.vcxproj"
    "Assign4 - Big Integer.vcxproj.filters"
    BigInteger.cpp
    BigInteger.hpp
    CMakeLists.txt
    main.cpp
    TestCases.cpp
    TestCases.hpp)

add_executable(bigInteger ${SOURCE_FILES})