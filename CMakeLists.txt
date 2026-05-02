cmake_minimum_required(VERSION 3.4)

project(banking)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" OFF)
option(ENABLE_COVERAGE "Enable coverage flags" OFF)

add_subdirectory(banking)

if(BUILD_TESTS)
  enable_testing()

  add_subdirectory(third-party/gtest)

  foreach(target gtest gtest_main gmock gmock_main)
    if(TARGET ${target})
      target_compile_options(${target} PRIVATE -Wno-error=maybe-uninitialized)
    endif()
  endforeach()

  add_executable(check
    tests/account_test.cpp
    tests/transaction_test.cpp
  )

  target_link_libraries(check
    banking
    gmock_main
  )

  if(ENABLE_COVERAGE)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
      target_compile_options(check PRIVATE --coverage -O0 -g)
      target_link_libraries(check --coverage)
    endif()
  endif()

  add_test(NAME check COMMAND check)
endif()
