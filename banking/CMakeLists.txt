add_library(banking STATIC
  Account.cpp
  Transaction.cpp
)

target_include_directories(banking
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(ENABLE_COVERAGE)
  if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(banking PRIVATE --coverage -O0 -g)
    target_link_libraries(banking PUBLIC --coverage)
  endif()
endif()
