cmake_minimum_required(VERSION 3.5)

project(dtag LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})


set(DTAG_SOURCES
    dtag/components/tag_reader.cc
    dtag/dtag.cc
    dtag/operations/help.cc
    dtag/operations/search.cc
    dtag/operations/show.cc
    dtag/option/parser.cc
    )

add_executable(dtag ${DTAG_SOURCES})

enable_testing()
#add_subdirectory(tests)
