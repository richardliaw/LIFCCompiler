	 .data
str$0: .asciiz "\n"



	 .text
main: 
	 li $a0, 0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 la $a0, str$0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 4
	 syscall
	 add $a0, $0, $0  #return_None
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)


    li $v0 10
    syscall
