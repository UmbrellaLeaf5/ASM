	.file	"arith.c"
	.text
	.globl	arith
	.def	arith;	.scl	2;	.type	32;	.endef
arith:
	xorq	%rsi, %rdi
	movq	%rdx, %rax
	salq	$11, %rax
	addq	%rdx, %rax
	addq	%rax, %rax
	andl	$252645135, %edi
	subq	%rdi, %rax
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
