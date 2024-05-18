	.file	"switcher.c"
	.text
	.globl	switcher
	.def	switcher;	.scl	2;	.type	32;	.endef
switcher:
	cmpq	$7, %rdi
	ja	.L2
	leaq	.L4(%rip), %r8
	movslq	(%r8,%H,4), %rax
	addq	%r8, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L4:
	.long	.L7-.L4
	.long	.L2-.L4
	.long	.L3-.L4
	.long	.L2-.L4
	.long	.L6-.L4
	.long	.L5-.L4
	.long	.L2-.L4
	.long	.L3-.L4
	.text
.L6:
	movq	%rdi, %rsi
	jmp	.L2
.L5:
	movq	%rsi, %rdx
	xorq	$15, %rdx
.L7:
	leaq	112(%rdx), %rsi
.L2:
	movq	%rsi, (%rcx)
	ret
.L3:
	addq	%rdx, %rsi
	salq	$2, %rsi
	jmp	.L2
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
