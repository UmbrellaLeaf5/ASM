	.file	"program3.c"
	.text
	.globl	store_prod
	.def	store_prod;	.scl	2;	.type	32;	.endef
store_prod:
	movq	%rsi, %rax
	mulq	%rdx
	movq	%rax, (%rdi)
	movq	%rdx, 8(%rdi)
	ret
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
