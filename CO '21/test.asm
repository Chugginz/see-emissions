#####################################################################
# @param string a &#92;&#48; terminated string                              #
# @return string the ROT-13 encrypted string                        #
#####################################################################

.data
    prompt: .asciiz "Please enter string: "
    output: .asciiz "ROT-13: "
    plain:  .space 64
.text
.globl main
main:
    li      $v0, 4      # |
    la      $a0, prompt # |
    syscall             # |=> Print string "prompt"
    li      $v0, 8      # |
    la      $a0, plain  # | => Ask for string plain
    li      $a1, 64     # |
    syscall             # | => read a string with max. 64 chars
    li      $t2, 10     # Stop by \n

    # Loop over all characters
    la      $t1, ($a0)  #=>$t1:the current adress that gets modified

s:  lb      $t0, ($t1)  # => $t0: the current value (char)
    beq $t0, $t2, out   # while $t1 != '\n'
    li $t3, 64
    bge $t3, $t0, w     # if $t0 <= 64: jump to w
    li $t3, 123
    bge $t0, $t3, w     # if $t0 >= 123: jump to w
    li $t3, 90
    bge $t3, $t0, big   # if $t0 <= 90: jump to big
    li $t3, 96
    bge $t3, $t0, w     # if $t0 <= 96: jump to w
    j small
w:  addi $t1, $t1, 1    # $t1++
    j s;                # /endwhile

small:
    addi    $t0, -84    # -97 + 13
    rem     $t0, $t0, 26 # $t0 %= 26
    addi    $t0, 97
    sb      $t0, ($t1)
    j w

big:
    addi    $t0, -52    # -65 + 13
    rem     $t0, $t0, 26 # $t0 %= 26
    addi    $t0, 65
    sb      $t0, ($t1)
    j w

out:
    li      $v0, 4      # |
    la      $a0, output # |
    syscall             # |=> Print string "output"

    la      $v0, 4      # |
    la      $a0, plain  # |
    syscall             # |=> Print plain
    jr      $ra