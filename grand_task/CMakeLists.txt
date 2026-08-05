add_executable(valgrind_task6 valgrind_task6.c)
add_executable(gdb_task6 gdb_task6.c)

configure_file(test-dates.txt test-dates.txt COPYONLY)
target_compile_options(valgrind_task6 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
target_compile_options(gdb_task6 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
