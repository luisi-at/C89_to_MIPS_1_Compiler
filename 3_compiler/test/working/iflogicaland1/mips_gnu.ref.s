	.file	1 "in.code.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls
	.text
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-16
	sw	$fp,12($sp)
	move	$fp,$sp
	li	$2,4			# 0x4
	sw	$2,0($fp)
	li	$2,2			# 0x2
	sw	$2,4($fp)
	lw	$3,4($fp)
	lw	$2,0($fp)
	slt	$2,$3,$2
	beq	$2,$0,$L2
	nop

	lw	$2,4($fp)
	slt	$2,$2,2
	bne	$2,$0,$L2
	nop

	li	$2,30			# 0x1e
	sw	$2,4($fp)
$L2:
	move	$2,$0
	move	$sp,$fp
	lw	$fp,12($sp)
	addiu	$sp,$sp,16
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"