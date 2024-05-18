	.file	"program4.c"
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
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
