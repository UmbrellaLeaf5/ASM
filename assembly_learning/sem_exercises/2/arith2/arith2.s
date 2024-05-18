	.file	"arith2.c"
	.text
	.globl	arith2
	.def	arith2;	.scl	2;	.type	32;	.endef
arith2:
	orq	%rsi, %rdi
	sarq	$3, %rdi
	notq	%rdi
	movq	%rdx, %rax
	subq	%rdi, %rax
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
