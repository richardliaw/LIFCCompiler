	 .data



	 .text
main: 
	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 6
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0
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

	 li $a0, 6
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sub $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 6
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 div $t1, $t0
	 mflo $a0
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

	 li $a0, 6
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
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
