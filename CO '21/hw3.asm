# CS3223 Homework 3
# Purpose: Averages Two Floats
# Name: Christian Huggins
# Date: 10/27/21

.data
prompt1:            .asciiz "Enter The First Value: "
prompt2:            .asciiz "Enter The Second Value: "

.text
main:
    # Print Prompt
    li $v0, 4                   # Print String
    la $a0, prompt1             # Load Prompt Address
    syscall
    # Load in float
    li $v0, 6                   # Read float
    syscall
    # Print Prompt 2
    mov.s $f1, $f0
    li $v0, 4                   # Print Strings
    la $a0, prompt2             # Load Prompt Address
    syscall
    # Load in 2nd float
    li $v0, 6                   # Read Float
    syscall
    # Float Conversions
    li.s $f2, 2.0               # Load immediate float for 2
    # Math 
    add.s $f3, $f0, $f1         # Add the two floats
    div.s $f12, $f3, $f2        # Divide the sum float by the 2 float
    # Read out Average
    li $v0, 2                   # Print Float
    syscall