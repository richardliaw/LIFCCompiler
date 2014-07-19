	 .data
str$1: .asciiz "Credit for it goes to Ulysse Manceron."
str$0: .asciiz "A truly nasty example of scoping in LIFC."


_mycode:    .word  0

	 .text
main: 
	 la $a0, str$0

	 la $a0, str$1

	 lw $a0, _mycode
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 21
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _mycode
	 add $a0, $0, $t0

	 lw $a0, _mycode
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal mycode

    li $v0 10
    syscall
