add_library(bank)

target_sources(bank
  PRIVATE
      bank.c

  PUBLIC
    FILE_SET HEADERS
    FILES
      bank.h
)
