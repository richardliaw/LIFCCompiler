	 .data



	 .text
main: 
	 li $a0, 0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 slt $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 slt $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 slt $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, -4
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 1
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 slt $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 add $a0, $0, $0  #return_None
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 beq $t0, $t1, equal_true$17
	 li $a0 0
	 j equal_end$17
equal_true$17: 
	 li $a0 1
equal_end$17: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 7
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 58
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 beq $t0, $t1, equal_true$21
	 li $a0 0
	 j equal_end$21
equal_true$21: 
	 li $a0 1
equal_end$21: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, -1
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, -1
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 beq $t0, $t1, equal_true$25
	 li $a0 0
	 j equal_end$25
equal_true$25: 
	 li $a0 1
equal_end$25: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

    li $v0 10
    syscall
