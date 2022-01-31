# CS3223 Homework 2
# Purpose: Checks password for user inputted ID
# Name: Christian Huggins
# Date: 10/4/21

.data
prompt1:            .asciiz "Enter Your Student ID: "
prompt2:            .asciiz "Enter Password: "
str1:               .asciiz "Correct!"
str2:               .asciiz "Wrong password!"
newline:            .asciiz "\n"
buffer1:            .space 9
buffer2:            .space 9
output:             .space 9

.text
main:
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, prompt1    # load address of the first prompt into argument 0
    syscall
    li  $v0, 8          # load immediate for results of 8 into v0
    la  $a0, buffer1    # load address of the buffer into argument 0
    li  $a1, 9          # load immediate of value 9 into argument 1
    syscall
    li  $v0, 4          # load immmediate for results of 4 into v0
    la  $a0, newline    # load address of new line into argument 0
    syscall
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, prompt2    # load address of second prompt into argument 0
    syscall
    li  $v0, 8          # load immediate for results of 8 into v0
    la  $a0, buffer2    # load address of buffer 2 into argument 0
    li  $a1, 9          # load immediate of value 0 into argument 1
    syscall
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, newline    # load address of new line into argument 0
    syscall
    la $a0, buffer1     # load address of buffer 1 into argument 0
    la $a1, buffer2     # load address of buffer 2 into argument 1
    jal label1          # jump and link to label 1
    beq $v0, $zero, label5  # branch to label 5 if result v0 = 0
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, str1       # load address of string 1 into argument 0
    syscall
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, newline    # load address of newline into argument 0
    syscall
    li $v0, 10          # load immediate for results of 10 into v0
    syscall
label5:
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, str2       # load address of str2 into argument 0
    syscall
    li  $v0, 4          # load immediate for results of 4 into v0
    la  $a0, newline    # load address of newline into argument 0
    syscall
    li $v0, 10          # load immediate for results of 10 into v0
    syscall
label1:
    move    $s0, $a0    # move argument 0 to contents register 0
    move    $s1, $a1    # move argument 1 to contents register 1
    move    $t0, $zero  # move 0 to temp register 0
    li      $t1, 8      # load immediate for temp 1 of value 8
    li      $v0, 1      # load immediate for results of 1 to v0
label2:
    sltu    $t5, $t0, $t1       # set on less than unsigned t0 < t1
    beq     $t5, $zero, label4  # branch to label4 if temp 5 and zero are equal
    lb	    $t2, 0($s0)         # load byte of content register 0 to temp 2
    # 0 in lb is the offset (starting point)
    lb      $t3, 0($s1)         # load byte of content register 1 to temp 3
    addi    $t2, $t2, 49        # add immediate of 49 to temp 2
    add     $t2, $t2, $t0       # add temp 0 to temp 2
    addi    $t2, $t2, 1         # add immediate of 1 to temp 2
    bne     $t2, $t3, label3    # branch to label 3 if temp 3 and temp 2 !=
    addi    $t0, $t0, 1         # add immediate of 1 to temp 0
    addi    $s0, $s0, 1         # add immediate of 1 to content 0
    addi    $s1, $s1, 1         # add immediate of 1 to content 1

    j		label2	            # jump to label 2
label3:
    move    $v0, $zero  # move 0 to results 0
label4:
    jr $ra              # return to jal address
    
