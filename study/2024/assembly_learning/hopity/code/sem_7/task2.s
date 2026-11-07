	.file	"task2.c"
	.text
	.globl	str_len
	.def	str_len;	.scl	2;	.type	32;	.endef
str_len:
	testq	%rcx, %rcx
	je	.L6
	movl	$0, %eax
	jmp	.L2
.L6:
	movl	$0, %eax
	ret
.L4:
	addl	$1, %eax
	addq	$1, %rcx
.L2:
	cmpb	$0, (%rcx)
	jne	.L4
	ret
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
