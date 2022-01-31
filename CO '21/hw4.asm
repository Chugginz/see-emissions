# CS3223 Homework 4
# Purpose: 
# Name: Christian Huggins
# Date: 11/10/21

.data
prompt1:        .asciiz "How many values would you like to enter: "
prompt2:        .asciiz "What number would you like to enter: "
arrPtr:         .space 0
space:          .asciiz " "

.text
main:
    li $v0, 4               # print a string
    la $a0, prompt1         # that string being the first prompt
    syscall

    li $v0, 5               # read desired number of values
    syscall

    move $t8, $v0           # move read integer into the temp server 2

    j arrSize               # jump to allocating memory task

# Dynamically allocates memory for the array
arrSize:
    li $t1, 4               # t1 is number if bits in int

    mul $t1, $t1, $t8       # multiply t1 by the number of desired numbers

    li $v0, 9               # use sbrk to dynamically allocate memory
    add $a0, $t1, $zero     # load the address with the number of desired bits
    syscall

    sw $v0, arrPtr          # save a pointer to arrPtr

    lw $t9, arrPtr          # create a counter in temp register 9

    j insertNumbers         # jump to taking in numbers

# Inserts numbers until all desired values have been inserted
insertNumbers:
    beq $t8, $zero, prntArr # while numbers still want to be printed

    li $v0, 4               # print a string
    la $a0, prompt2         # that string being the second prompt
    syscall

    li $v0, 5               # read an integer
    syscall
    
    move $t0, $v0           # move read integer into the temp register 2
    lw $t2, arrPtr          # create an array pointer to iterate with
    lw $t3, arrPtr          # create plaeholder at start of array

    j iterArr               # jump to array sort

# Iterates through array until it finds its place
iterArr:
    # Checks to see if there's an element to compare, will branch if not
    ble $t9, $t2, insertion # branch if the counter is <= iterating ptr

    lw $t1, ($t2)           # grab element at the current index for t1
    lw $t4, ($t2)           # grab element at the current index for t4

    ble $t0, $t1, arrSort   # branch if the new value <= element

    addi $t2, $t2, 4        # move pointer to next number
    addi $t3, $t3, 4        # set temp register 3 to iterating pointer
    lw $t1, ($t2)           # load the next element

    j iterArr               # loop back

# Begins sorting the array after it finds the new number's place
arrSort:    
    addi $t3, $t3, 4        # move to next value

    beq $t9, $t3, aFV       # branches if counter and pointer are ==

    lw $t5, ($t3)           # grab the value at the next location
    sw $t4, ($t3)           # set the previous value to the next

    move $t4, $t5           # move temp register 4 to temp register 5

    j arrSort               # loop back

# add final value: adds last value if at the end of the array
aFV:
    sw $t4, ($t9)           # store the value in the empty location

    j insertion             # jump to the insertion process, don't have to do jump

# Just adds the value if no sorting is necessary
insertion:
    sw $t0, ($t2)           # stores value to available spot in array

    addi $t9, $t9, 4        # increment the counter by 1
    addi $t8, $t8, -1       # decrement the number of desired values by 1

    lw $t3, arrPtr          # reset the index placeholder

    j insertNumbers         # jump to insert another number

prntArr:
    beq $t3, $t9, exit      # branch to the exit if ptr = counter

    li $v0, 1               # print an int
    lw $a0, 0($t3)          # load the address at the ptr address
    syscall

    addi $t3, $t3, 4        # move to next value

    li $v0, 4               # print a string
    lw $a0, space           # which is a space
    syscall

    j prntArr               # loop

exit:
    li $v0, 10              # tell program to terminate
    syscall
    





# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                     Key                                     #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   Values:                                   #
#   t0 = inserted value                                                       #
#   t1 = # of bits for array, REPURPOSED for array element                    #
#                                                                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                  Iterator:                                  #
#   t2 = iterating pointer                                                    #
#                                                                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                Placeholders:                                #
#   t3 = index placeholder                                                    #
#   t4 = element placeholder                                                  #
#   t5 = next element placeholder                                             #
#                                                                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                             Desired # of Values:                            #
#   t8 = desired # of values                                                  #
#   s7 = unaffected desired # of values                                       #
#                                                                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                                   Counter:                                  #
#   t9 = counter                                                              #
#                                                                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #