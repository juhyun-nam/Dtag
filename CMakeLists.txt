cmake_minimum_required(VERSION 3.5)

project(dtag LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include_directories(include)

add_subdirectory(src)
enable_testing()
#add_subdirectory(tests)
