if(NOT TARGET formatter_ex)
    add_subdirectory(../formatter_ex_lib formatter_ex_lib_build)
endif()

add_executable(hello_world hello_world.cpp)

target_link_libraries(hello_world PRIVATE
    formatter_ex
)
