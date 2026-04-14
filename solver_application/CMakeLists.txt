if(NOT TARGET formatter_ex)
    add_subdirectory(../formatter_ex_lib formatter_ex_lib_build)
endif()

if(NOT TARGET solver_lib)
    add_subdirectory(../solver_lib solver_lib_build)
endif()

add_executable(solver equation.cpp)

target_link_libraries(solver PRIVATE
    formatter_ex
    solver_lib
)
