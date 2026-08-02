add_executable(hello.elf)

target_sources(hello.elf PRIVATE hello.c)
target_compile_options(hello.elf PRIVATE -Og -ggdb -fno-omit-frame-pointer)
