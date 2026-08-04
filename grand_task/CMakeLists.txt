add_executable(valgrind_task6 valgrind_task6.c)
target_compile_options(valgrind_task6 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
