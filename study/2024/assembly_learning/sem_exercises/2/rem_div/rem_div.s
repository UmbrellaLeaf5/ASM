	.file	"rem_div.c"
	.text
	.globl	remdiv
	.def	remdiv;	.scl	2;	.type	32;	.endef
remdiv:
	movq	%rdi, %rax
	movq	%rdx, %r8
	cqto
	idivq	%rsi
	movq	%rax, (%r8)
	movq	%rdx, (%rcx)
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
