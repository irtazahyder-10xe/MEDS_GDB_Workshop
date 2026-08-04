add_executable(valgrind_task1 valgrind_task1.c)
add_executable(valgrind_task2 valgrind_task1.c)
add_executable(valgrind_task3 valgrind_task3.c)
add_executable(valgrind_task4 valgrind_task4.c)
add_executable(valgrind_task5 valgrind_task5.c)

target_compile_options(valgrind_task1 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
target_compile_options(valgrind_task2 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
target_compile_options(valgrind_task3 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
target_compile_options(valgrind_task4 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)
target_compile_options(valgrind_task5 PRIVATE -Og -ggdb -fno-omit-frame-pointer --no-warnings)

target_compile_definitions(valgrind_task2 PRIVATE TASK2)

target_link_libraries(valgrind_task1 PRIVATE LinkedList)
target_link_libraries(valgrind_task2 PRIVATE LinkedList)

add_subdirectory(LinkedList)
