add_library(LinkedList)

target_sources(LinkedList
  PRIVATE
    LinkedList.c

  PUBLIC
    FILE_SET HEADERS
    FILES
      LinkedList.h
)
