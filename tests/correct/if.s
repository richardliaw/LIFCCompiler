	 .data
str$2: .asciiz "fail\n"
str$3: .asciiz "success\n"



	.text
main: 
	li $a0, 1
	 beq $a0, $0, if_false$0
if_true$0: 
	la $a0, str$3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 4
	syscall
	 j if_end$0
if_false$0: 
	la $a0, str$2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 4
	syscall
if_end$0: 

	li $a0, 0
	 beq $a0, $0, if_false$6
if_true$6: 
	la $a0, str$2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 4
	syscall
	 j if_end$6
if_false$6: 
	la $a0, str$3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 4
	syscall
if_end$6: 

    li $v0 10
    syscall
