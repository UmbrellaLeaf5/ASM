	.file	"program1.c"
	.text
	.globl	shift_left4_rightn
	.def	shift_left4_rightn;	.scl	2;	.type	32;	.endef
shift_left4_rightn:
	movq	%rdi, %rax
	salq	$4, %rax
	movl	%esi, %ecx
	sarq	%cl, %rax
	ret
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
