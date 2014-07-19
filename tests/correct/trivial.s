	 .data
str$3: .asciiz "hello world"
str$4: .asciiz "hello worl123d"
str$5: .asciiz "NONSENSE"


_size:    .word  0
_arrow:    .word  0
_n:    .word  0
_radius:    .word  0
_x:    .word  0
_pi:    .word  0

	 .text
main: 
	 la $a0, str$3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 4
	 syscall
	 add $a0, $0, $0  #return_None

	 li $a0, 137
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 349
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0

	 li $a0, 1000
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 334
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sub $a0, $t1, $t0

	 li $a0, 5
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 99
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0

	 li $a0, 10
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 5
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 div $t1, $t0
	 mflo $a0

	 li $a0, 2.7
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 10
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0

	 la $a0, str$3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 4
	 syscall
	 add $a0, $0, $0  #return_None

	 la $a0, str$3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 4
	 syscall
	 add $a0, $0, $0  #return_None

	 la $a0, str$3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 4
	 syscall
	 add $a0, $0, $0  #return_None

	 la $a0, str$4
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 4
	 syscall
	 add $a0, $0, $0  #return_None

	 lw $a0, _x
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

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _x
	 add $a0, $0, $t0

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 5
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 10
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

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 4
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 5
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

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 10
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 7
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sub $a0, $t1, $t0
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

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 4
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 5
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

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 10
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 7
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sub $a0, $t1, $t0
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

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0

	 lw $a0, _n
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _n
	 add $a0, $0, $t0

	 li $a0, 6
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal fib
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 move $a0, $t0
	 li $v0, 1
	 syscall
	 add $a0, $0, $0  #return_None

	 lw $a0, _size
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _size
	 add $a0, $0, $t0

	 lw $a0, _size

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, -2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal a_plus_abs_b

	 li $a0, 5
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $a0, _size
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0

	 lw $a0, _x
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
	 mul $t2, $t0, $t2
	 add $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _arrow
	 add $a0, $0, $t0

	 lw $a0, _pi
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 3.14159
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _pi
	 add $a0, $0, $t0

	 lw $a0, _radius
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 10
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 sw $t0, _radius
	 add $a0, $0, $t0

	 lw $a0, _pi
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $a0, _radius
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $a0, _radius
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

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 mul $a0, $t1, $t0

	 li $a0, 21
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal square

	 li $a0, 2
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 5
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 lw $t0, 0($sp) #pop
	 addiu $sp, $sp, 4

	 lw $t1, 0($sp) #pop
	 addiu $sp, $sp, 4

	 add $a0, $t1, $t0
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal square

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal square
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal square

	 li $a0, 3
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 li $a0, 4
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal sum_of_squares

	 li $a0, 5
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal f

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
	 mul $t2, $t0, $t2
	 add $a0, $t1, $t0

	 li $a0, 12
	 addi $sp, $sp, -4 #push
	 sw $a0, 0($sp)

	 jal print_and_square

    li $v0 10
    syscall
