add_executable(gdb_basics1.out gdb_basics1.c)
add_executable(gdb_basics2.out gdb_basics2.c)

target_compile_options(gdb_basics1.out PRIVATE -Og -ggdb -fno-omit-frame-pointer)
target_compile_options(gdb_basics2.out PRIVATE -Og -ggdb -fno-omit-frame-pointer)
