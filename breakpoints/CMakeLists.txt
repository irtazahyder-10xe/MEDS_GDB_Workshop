add_executable(task3 task3.c)
add_executable(task4 task4.c)
add_executable(task5 task5.c)

target_compile_options(task3 PRIVATE -Og -ggdb -fno-omit-frame-pointer)
target_compile_options(task4 PRIVATE -Og -ggdb -fno-omit-frame-pointer)
target_compile_options(task5 PRIVATE -Og -ggdb -fno-omit-frame-pointer)

add_subdirectory(bank)
target_link_libraries(task5
  PRIVATE
    bank
)
