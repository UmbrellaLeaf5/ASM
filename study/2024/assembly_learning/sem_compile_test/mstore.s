	.file	"mstore.c"
	.text
	.globl	multstore
	.def	multstore;	.scl	2;	.type	32;	.endef
multstore:
	pushq	%rbx
	subq	$32, %rsp
	movq	%r8, %rbx
	call	_Z5mult2ll
	movl	%eax, (%rbx)
	addq	$32, %rsp
	popq	%rbx
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
	.def	_Z5mult2ll;	.scl	2;	.type	32;	.endef
