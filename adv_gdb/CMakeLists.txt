add_executable(task6 task6.c)

target_compile_options(task6 PRIVATE -Og -ggdb -fno-omit-frame-pointer)

configure_file(test-dates.txt test-dates.txt COPYONLY)
