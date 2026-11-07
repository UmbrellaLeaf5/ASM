	.file	"task3_33.c"
	.text
	.globl	procprob
	.def	procprob;	.scl	2;	.type	32;	.endef
procprob:
	movslq	%edi, %rdi
	addq	%rdi, (%rdx)
	addb	%sil, (%rcx)
	movl	$5, %eax
	ret
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
