cmake_minimum_required(VERSION 3.9)

project(dtag LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(DTAG_BUILD_TESTING "enalbe testing for dtag" ON)

set(DTAG_SOURCES
    dtag/components/recent_writer.cc
    dtag/components/tag_reader.cc
    dtag/components/tag_writer.cc
    dtag/env/concrete_env.cc
    dtag/operations/add.cc
    dtag/operations/help.cc
    dtag/operations/clear.cc
    dtag/operations/factory.cc
    dtag/operations/recent.cc
    dtag/operations/remove.cc
    dtag/operations/search.cc
    dtag/operations/show.cc
    dtag/option/parser.cc
    )

add_executable(dtag dtag/dtag.cc ${DTAG_SOURCES})
target_include_directories(dtag PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if (DTAG_BUILD_TESTING)
  include(CTest)
  enable_testing()
  target_compile_options(dtag PRIVATE -O0 -g --coverage)
  target_link_libraries(dtag PRIVATE --coverage)
  add_library(doctest INTERFACE)
  target_include_directories(doctest INTERFACE external/doctest)

  set(TEST_TARGETS
      op_test
      )

  foreach(target ${TEST_TARGETS})
    add_executable(${target} dtag/tests/${target}.cc ${DTAG_SOURCES})
    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_compile_options(${target} PRIVATE -Werror -Wall -Wextra -O0 -g --coverage)
    target_link_libraries(${target} PRIVATE doctest --coverage)
    add_test(NAME ${target} COMMAND ${target} --success)
  endforeach(target)
endif()
