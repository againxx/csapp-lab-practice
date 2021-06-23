	.file	"absdiff.c"
	.text
	.p2align 4
	.globl	absdiff
	.type	absdiff, @function
absdiff:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rdx # x -> rdx
	movq	%rsi, %rax # y -> rax
	subq	%rsi, %rdx # rdx = x - y
	subq	%rdi, %rax # rax = y - x
	cmpq	%rsi, %rdi # x:y
	cmovg	%rdx, %rax # if x > y rdx -> rax
	ret
	.cfi_endproc
.LFE0:
	.size	absdiff, .-absdiff
	.ident	"GCC: (Ubuntu 10.3.0-1ubuntu1~18.04~1) 10.3.0"
	.section	.note.GNU-stack,"",@progbits
