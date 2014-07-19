	 .data



	 .text
main: 
	 li $a0, 0
	 beq $a0, $0, end$1
	 li $a0, 0
	 beq $a0, $0, end$1
	 li $a0, 1
end$1: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 0
	 beq $a0, $0, end$5
	 li $a0, 2
	 beq $a0, $0, end$5
	 li $a0, 1
end$5: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 3
	 beq $a0, $0, end$9
	 li $a0, 0
	 beq $a0, $0, end$9
	 li $a0, 1
end$9: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 4
	 beq $a0, $0, end$13
	 li $a0, 5
	 beq $a0, $0, end$13
	 li $a0, 1
end$13: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 0
	 bne $a0, $0, end_check$17
	 li $a0, 0
	 bne $a0, $0, end_check$17
	 beq $a0, $0, end$17
end_check$17: 
	 li $a0, 1
end$17: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 0
	 bne $a0, $0, end_check$21
	 li $a0, 2
	 bne $a0, $0, end_check$21
	 beq $a0, $0, end$21
end_check$21: 
	 li $a0, 1
end$21: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 3
	 bne $a0, $0, end_check$25
	 li $a0, 0
	 bne $a0, $0, end_check$25
	 beq $a0, $0, end$25
end_check$25: 
	 li $a0, 1
end$25: 
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 4
	 bne $a0, $0, end_check$29
	 li $a0, 5
	 bne $a0, $0, end_check$29
	 beq $a0, $0, end$29
end_check$29: 
	 li $a0, 1
end$29: 
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
