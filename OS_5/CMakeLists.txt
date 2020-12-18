project(lib_test C)

set(CMAKE_C_STANDARD 99)

add_library(my_stack SHARED stack.c stack.h)

add_executable(lab_compile_link main.c)
target_link_libraries(lab_compile_link my_stack )

add_executable(lab_syscall_link main_2.c)
target_link_libraries(lab_syscall_link dl)
