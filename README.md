# GDB Workshop

Repository for the GDB workshop for UET MEDS Lab.

The 1 day workshop will be covering the GDB in depth as well as giving brief introduction to Valgrind, ASAN and UBSAN. The aim of the workshop is to get students familarized with these tools, provide a digestible overview of some useful features of these tools, and show them their appriopriate usage with interactive demos.

**NOTE: All the demo programs are in C.**
## TODO:
1. Add references from GDB manual
2. Make slides
4. Convert all the examples in C

## Prerequistes
1. Linux or WSL environment
2. CMake v4 or above
3. GDB 12.0 or above
4. Valgrind
5. RISCV GNU Toolchain
6. Spike
7. Download the following manuals
    - GDB
    - Valgrind
    - GCC

### Setting up Spike with GDB
``` bash
git clone git://git.code.sf.net/p/openocd/code openocd
git checkout v0.12.0
git merge 400cf2        # Contains fixes to some gnu issues
./bootstrap
./configure --enable-remote-bitbang
make -j $(nproc)
make install
```

## Sections
1. Debugging
    - Why
    - Methodologies
    - Brief Intro to Tools
        - GDB
        - valgrind
2. Getting Started
    - Compiler flags
    - Stating GDB Session
3. Basic of GDB
    - Executing code in gdb: run, start, next, until, finish
    - View data: print, display, x (memory view)
    - TUI
        - layout: src, reg, asm
        - split
        - focus
    - disasm
        - disasm
        - stepi
        - nexti
4. Breakpoints
    - Locspec
    - Breakpoints
        - info
        - delete
    - Watchpoints
        - Variables
        - Memory locations
    - Prints
        - dprintf
        - info args
        - info locals
    - Function commands
        - call
        - finish
        - return
        - skip
    - Saving breakpoints to a file & retrieving them
5. Spike with GDB
6. Valgrind
    - Memory Leaks and Buffer Overruns
    - Valgrind Tasks
7. Advanced GDB
    - Breakpoints
        - Enabling and Disabling Break points
        - Temporary Breakpoints
        - Adding counts to breakpoints
        - Conditional breakpoints + ignore <bnum> <count>
    - Catchpoints (Can be skipped, probably show the write syscalls invoked by printf caught by GDB)
    - Modifying Code Flow
        - Checkpoints
        - set <var> = <value>
            - Scope variables
            - Registers
        - jump
    - Generting coredump
        - GDB on coredumps
    - Reverse Debugging
    - gdb attach -p <process_pid>
        - Generating coredump using GDB
8. Grand Task

## Credits
https://github.com/zaldawid/magic_powers_at_your_fingertips

## License
This software is licensed under [CC Attribution-NonCommercial-ShareAlike 4.0 International](https://creativecommons.org/licenses/by-nc-sa/4.0/).
