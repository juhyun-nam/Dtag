cmake_minimum_required(VERSION 3.5)

project(dtag LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Boost 1.65 REQUIRED COMPONENTS serialization)

set(DTAG_SOURCES
    dtag/dtag.cc
    dtag/operations/op_factory.cc
    dtag/operations/help.cc
    dtag/operations/show.cc
    dtag/option/parser.cc
    dtag/tag_manager.cc
    )

add_executable(dtag ${DTAG_SOURCES})
target_link_libraries(dtag PUBLIC Boost::serialization)

enable_testing()
#add_subdirectory(tests)
