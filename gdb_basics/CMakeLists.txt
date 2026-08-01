add_executable(task1 task1.c)
add_executable(task2 task2.c)

target_compile_options(task1 PRIVATE -Og -ggdb -fno-omit-frame-pointer)
target_compile_options(task2 PRIVATE -Og -ggdb -fno-omit-frame-pointer)
