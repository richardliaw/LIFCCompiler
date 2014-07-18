	 .data



	.text
main: 
	li $a0, 0
beq $a0, $0, end$1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	 end$1: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
beq $a0, $0, end$5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	 end$5: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 3
beq $a0, $0, end$9
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	 end$9: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 4
beq $a0, $0, end$13
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	 end$13: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	 bne $a0, $0, end$17
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	 end$17: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	 bne $a0, $0, end$21
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	 end$21: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 3
	 bne $a0, $0, end$25
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	 end$25: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 4
	 bne $a0, $0, end$29
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	 end$29: 
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

    li $v0 10
    syscall
