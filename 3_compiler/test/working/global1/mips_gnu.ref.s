	.file	1 "in.code.c"
	.section .mdebug.abi32
	.previous
	.nan	legacy
	.module	fp=xx
	.module	nooddspreg
	.abicalls

	.comm	x,4,4

	.comm	y,4,4
	.text
	.align	2
	.globl	function
	.set	nomips16
	.set	nomicromips
	.ent	function
	.type	function, @function
function:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	lw	$2,%got(x)($28)
	li	$3,14			# 0xe
	sw	$3,0($2)
	nop
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	function
	.size	function, .-function
	.align	2
	.globl	function2
	.set	nomips16
	.set	nomicromips
	.ent	function2
	.type	function2, @function
function2:
	.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, gp= 0
	.mask	0x40000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-8
	sw	$fp,4($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	lw	$2,%got(x)($28)
	li	$3,13			# 0xd
	sw	$3,0($2)
	nop
	move	$sp,$fp
	lw	$fp,4($sp)
	addiu	$sp,$sp,8
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	function2
	.size	function2, .-function2
	.align	2
	.globl	main
	.set	nomips16
	.set	nomicromips
	.ent	main
	.type	main, @function
main:
	.frame	$fp,32,$31		# vars= 0, regs= 2/0, args= 16, gp= 8
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
	.set	noreorder
	.set	nomacro
	addiu	$sp,$sp,-32
	sw	$31,28($sp)
	sw	$fp,24($sp)
	move	$fp,$sp
	lui	$28,%hi(__gnu_local_gp)
	addiu	$28,$28,%lo(__gnu_local_gp)
	.cprestore	16
	lw	$2,%got(x)($28)
	li	$3,3			# 0x3
	sw	$3,0($2)
	lw	$2,%got(x)($28)
	lw	$2,0($2)
	addiu	$3,$2,5
	lw	$2,%got(y)($28)
	sw	$3,0($2)
	.option	pic0
	jal	function
	nop

	.option	pic2
	lw	$28,16($fp)
	.option	pic0
	jal	function2
	nop

	.option	pic2
	lw	$28,16($fp)
	lw	$2,%got(x)($28)
	lw	$2,0($2)
	slt	$2,$2,4
	bne	$2,$0,$L4
	nop

	lw	$2,%got(y)($28)
	li	$3,3			# 0x3
	sw	$3,0($2)
	move	$2,$0
	b	$L5
	nop

$L4:
	li	$2,1			# 0x1
$L5:
	move	$sp,$fp
	lw	$31,28($sp)
	lw	$fp,24($sp)
	addiu	$sp,$sp,32
	j	$31
	nop

	.set	macro
	.set	reorder
	.end	main
	.size	main, .-main
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.1) 5.4.0 20160609"
