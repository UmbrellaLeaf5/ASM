	.file	"store_prod.c"
	.text
	.globl	store_uprod
	.def	store_uprod;	.scl	2;	.type	32;	.endef
store_uprod:
	movq	%rsi, %rax
	mulq	%rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
