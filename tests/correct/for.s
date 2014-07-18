	 .data


_i:    .space  4

	.text
main: 
	lw $a0, _i
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 sw $t0, _i
	add $a0, $0, $t0

#return_None
	 add $a0, $0, $0
	lw $a0, _i
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 10
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 slt $a0, $t1, $t0
	beq $a0, $0, end$3
	lw $a0, _i
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $a0, _i
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
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

	 sw $t0, _i
	add $a0, $0, $t0
#return_None
	 add $a0, $0, $0
end$3: 
#return_None
	 add $a0, $0, $0

    li $v0 10
    syscall
