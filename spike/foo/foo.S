#include "riscv_test.h"

// Fibonaci series containing has 10 enteries
.equ N, 10
// Stack is of 4KB bytes
.equ stack_size, 1 << 12

RVTEST_RV64M
RVTEST_CODE_BEGIN
main:
    ENABLE_STACK(stack,stack_size)
    la   s0, fib_array    # s0 = base address of fib_array (preserved across calls)
    li   s1, N            # s1 = number of elements to generate
    li   s2, 0            # s2 = loop counter (i = 0)

fill_loop:
    bge  s2, s1, fill_done # if i >= N, exit loop

    mv   a0, s2            # a0 = n (argument for fib)
    jal  ra, fib            # call recursive fib(n), result in a0

    sw   a0, 0(s0)          # store fib(i) into array
    addi s0, s0, 4          # advance array pointer

    addi s2, s2, 1          # i++
    j    fill_loop

fill_done:
RVTEST_PASS
j EXIT

//------------------------------------
//int fib(int n)
//  if n < 2: return n
//  else: return fib(n-1) + fib(n-2)
//------------------------------------
fib:
    addi sp, sp, -16        # allocate stack frame
    sw   s3, 8(sp)         # save s3 (used to hold fib(n-1))
    sw   a0, 4(sp)          # save n (argument) for later use

    li   t0, 2
    blt  a0, t0, fib_base    # if n < 2, base case

    # recursive case: fib(n-1)
    addi a0, a0, -1          # a0 = n - 1
    jal  ra, fib              # a0 = fib(n-1)
    mv   s3, a0                # s3 = fib(n-1)

    # recursive case: fib(n-2)
    lw   a0, 4(sp)             # restore original n
    addi a0, a0, -2            # a0 = n - 2
    jal  ra, fib                 # a0 = fib(n-2)

    add  a0, a0, s3              # a0 = fib(n-1) + fib(n-2)
    j    fib_return

fib_base:
    lw   a0, 4(sp)             # a0 = n (base case: fib(n) = n)

fib_return:
    lw   s3, 8(sp)            # restore s3
    addi sp, sp, 16            # deallocate stack frame
    ret
EXIT:
RVTEST_CODE_END

RVTEST_DATA_BEGIN
  fib_array: .fill N, 8, 0
RVTEST_DATA_END

  .section .data
  .p2align 6
  .global stack
stack: .fill stack_size, 1, 0
  .size stack, .-stack
