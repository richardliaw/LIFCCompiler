	 .data
str$0: .asciiz "\n"



	.text
main: 
	li $v0, 5
	syscall
	move $a0 $v0	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	la $a0, str$0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 4
	syscall

	li $v0, 5
	syscall
	move $a0 $v0	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

    li $v0 10
    syscall
