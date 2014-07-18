	 .data


_x:    .space  4
_y:    .space  4

	.text
main: 
	lw $a0, _x
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 sw $t0, _x
	add $a0, $0, $t0

	lw $a0, _x
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	lw $a0, _y
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $a0, _x
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $a0, _x
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

	 sw $t0, _x
	add $a0, $0, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 sw $t0, _y
	add $a0, $0, $t0

	lw $a0, _x
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	lw $a0, _y
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

    li $v0 10
    syscall
