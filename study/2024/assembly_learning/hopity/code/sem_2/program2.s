	.file	"program2.c"
	.text
	.globl	exchange
	.def	exchange;	.scl	2;	.type	32;	.endef
exchange:
	movl	(%rcx), %eax
	movl	%edx, (%rcx)
	ret
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
