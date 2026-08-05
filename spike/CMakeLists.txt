add_executable(rot13 rot13.c)

target_compile_options(rot13 PRIVATE -g -Og --specs=semihost.specs)
add_custom_target(bubble_sort ALL COMMAND make
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bubble_sort
)
add_custom_target(foo ALL COMMAND make
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/foo
)
