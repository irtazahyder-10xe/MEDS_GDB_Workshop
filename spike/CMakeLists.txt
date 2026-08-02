if (SPIKE)
  add_executable(hello.elf)

  set(CMAKE_TOOLCHAIN_FILE TC-riscv.cmake)

  target_sources(hello.elf PRIVATE hello.c)
  target_compile_options(task3 PRIVATE -Og -ggdb -fno-omit-frame-pointer)
endif()
