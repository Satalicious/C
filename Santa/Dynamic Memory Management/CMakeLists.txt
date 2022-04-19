cmake_minimum_required(VERSION 3.18)
project(free_store VERSION 1.0)

# -Wconversion currently has many warnings due to issue in libcriterion
# see
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=gnu99 -Wall -Wextra")

include(CTest)
# tell to use clang
set(C_SRCS  # all non-main source files used by the pure C version
  create_arrays.c
  int_array.c
  main.c
)
set(CMAKE_C_STANDARD 11)
add_executable(${PROJECT_NAME} ${C_SRCS})

add_executable(int_array_test int_array.c int_array_test.c)
add_executable(create_arrays_test create_arrays.c create_arrays_test.c)
target_link_libraries(int_array_test criterion)
target_link_libraries(create_arrays_test criterion)
add_test(NAME int_array_test
         COMMAND int_array_test)
add_test(NAME create_arrays_test
         COMMAND create_arrays_test)
