	 .data
str$2: .asciiz "\n"
str$0: .asciiz "hi"
str$1: .asciiz "string"



	.text
main: 
	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	la $a0, str$0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	la $a0, str$1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	la $a0, str$2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 4
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

	li $a0, 0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 1
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 2
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 3
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 4
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	li $a0, 5
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	lw $t1, 0($sp) #pop
	addiu $sp, $sp, 4

	 addiu $t2, $0, 4
	 mul $t0, $t2
	 mflo $t2
	 add $a0, $t1, $t0
	addi $sp, $sp, -4 #push
	sw $a0, 0($sp)

	lw $t0, 0($sp) #pop
	addiu $sp, $sp, 4

	 move $a0, $t0
	li $v0, 1
	syscall

    li $v0 10
    syscall
