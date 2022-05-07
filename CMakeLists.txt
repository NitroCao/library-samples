cmake_minimum_required(VERSION 3.0)

project(library-samples)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

add_subdirectory(src)
