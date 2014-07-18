	 .data



	.text
main: 
#return_None
	 add $a0, $0, $0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

    li $v0 10
    syscall
