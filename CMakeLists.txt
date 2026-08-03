cmake_minimum_required(VERSION 3.25)

project(exercise)

if (SPIKE)
  add_subdirectory(spike)
else()
  add_subdirectory(gdb_basics)
  add_subdirectory(breakpoints)
  add_subdirectory(valgrind)
endif()
