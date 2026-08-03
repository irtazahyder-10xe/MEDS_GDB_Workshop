#include "riscv_test.h"

#define RV_TEST_CASE(address,size)                                      \
    la a0, address;                                                     \
    li a1, size;                                                        \
    call bubble_sort;                                                   \
    la a0, address;                                                     \
    li a1, size;                                                        \
    call checker;                                                       \
    bnez a0, test_fail

.equ N, 6

RVTEST_RV64M
RVTEST_CODE_BEGIN
main:
    // Test case for V1
    RV_TEST_CASE(V1,N)
    RV_TEST_CASE(V2,N)
test_pass:
RVTEST_PASS
j EXIT

test_fail:
li TESTNUM, 2
RVTEST_FAIL
j EXIT

// a0: Array address
// a1: Size of array
bubble_sort:
mv t0, a0
addi a1, a1, -1 #N
li a0, 1 #i
  for1:
      bge a0, a1, bubble_sort_complete
      li a2, 0 # j
      sub a3, a1, a0
      addi a0, a0, 1
  for2:
      bge a2, a3, for1
      slli t1, a2, 2
      addi a2, a2, 1
      add t1, t1, t0  #V[j]
      lw a4, 0(t1)
      addi t1, t1, 4  #V[j+1] 
      lw a5, 0(t1)
      ble a4, a5, for2
      sw a4, 0(t1)
      addi t1, t1, -4
      sw a5, 0(t1)
      j for2

  bubble_sort_complete:
    ret

// Check if bubble sort sorted the values in ascending order
// a0: Address of sorted array
// a1: Size of array
// a0: return 0 if order as expected, otherwise index where enteries mismatched
// i.e. a0=1 means entry 0 and 1 are different
checker:
  mv a3, a1
  lw t0, 0(a0)
  check_values:
    beqz a1, pass
    addi a0, a0, 4
    lw t1, 0(a0)
    bgt t0, t1, fail
    mv t0, t1
    addi a1, a1, -1
    j check_values

  fail:
    sub a0, a3, a1
    j 1f

  pass:
    li a0, 0
  1:
    ret

EXIT:
RVTEST_CODE_END

RVTEST_DATA_BEGIN
  .fill N, 8, 0
RVTEST_DATA_END

.section .data
V1: .word 7,6,5,4,3,8
V2: .word 7,6,5,4,3,2
