	.file	"shift_left4_rightn.c"
	.text
	.globl	shift_left4_right_n
	.def	shift_left4_right_n;	.scl	2;	.type	32;	.endef
shift_left4_right_n:
	movq	%rdi, %rax
	salq	$4, %rax
	movq	%rsi, %rcx
	sarq	%cl, %rax
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
