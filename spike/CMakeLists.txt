add_executable(rot13.elf rot13.c)


target_compile_options(rot13.elf PRIVATE -g -Og --specs=semihost.specs)
