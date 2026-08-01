add_executable(task1.out task1.c)
add_executable(task2.out task2.c)

target_compile_options(task1.out PRIVATE -Og -ggdb -fno-omit-frame-pointer)
target_compile_options(task2.out PRIVATE -Og -ggdb -fno-omit-frame-pointer)
