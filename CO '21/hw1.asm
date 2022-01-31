# CS3223 Homework 1
# Purpose: Write a procedure that ROT13 encodes a string (https://en.wikipedia.org/wiki/ROT13)
# Name: Christian Huggins
# Date: 09/21/21

.data
prompt: .asciiz "Enter a string: "
str1:   .asciiz "Result is: "
newline: .asciiz    "\n"
buffer: .space 20

.globl  main
.globl  encode
.text
main:

    # prompt for input
    li  $v0, 4
    la  $a0, prompt
    syscall

    # read in the value
    li  $v0, 8
    la  $a0, buffer
    li  $a1, 20
    syscall
    move    $s0, $v0

    # encode string
    jal encode


    # print result
    li  $v0, 4
    la  $a0, str1
    syscall
    li  $v0, 4
    la  $a0, buffer
    syscall

    # exit program
    j  exit

exit:
    li $v0, 10 # Sets $v0 to "10" to select exit syscall
    syscall # Exit

encode:
    li $t2, 10              # Load temp 2 with line ending null in ASCII
    la  $t1, ($a0)          # load address of argument 0 to temp 1
    j looping

looping:
    lb  $t0, ($t1)          # load a byte from temp 1 to temp 0
    
    beq $t0, $t2, return    # branch to return if the temps are the same
    li $t3, 64
    bge $t3, $t0, increment
    li $t3, 90              # load immediate max uppercase ASCII value
    bge $t0, $t3, increment #
    j uppercase

uppercase:
    addi    $t0, -52        # Add imediate to temp 0 for -65 + 13 (rev by 13)
    sub $t0, $t0, 26
    bge $zero, $t0, modulus
    addi    $t0, 65         # Add immediate to temp 0 by 65
    
    sb  $t0, ($t1)          # Store byte of temp 0 to temp 1
    j increment

modulus:
    addi $t0, 78
    sb  $t0, ($t1)          # Store byte of temp 0 to temp 1
    j increment

increment:
    addi $t1, $t1, 1        # Increment temp 1 to iterate loop
    j looping

return:
    j $ra                   # Jump back to return address saved