cmake_minimum_required(VERSION 3.15)
project(Project2Interface CXX)
set(CMAKE_CXX_STANDARD 17)
add_executable(app src/main.cpp
        src/mergeSort.cpp
        src/mergeSort.h
        src/quickSort.h
        src/quickSort.cpp)
