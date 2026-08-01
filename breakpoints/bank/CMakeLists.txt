add_library(bank)

target_compile_options(bank PRIVATE -Og -ggdb -fno-omit-frame-pointer)
target_sources(bank
  PRIVATE
      bank.c

  PUBLIC
    FILE_SET HEADERS
    FILES
      bank.h
)
