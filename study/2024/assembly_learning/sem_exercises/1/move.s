	.file	"move.c"
	.text
	.globl	exchange
	.def	exchange;	.scl	2;	.type	32;	.endef
exchange:
	movq	(%rdi), %rax
	movq	%rsi, (%rdi)
	ret
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	subq	$8, %rsp
	call	__main
	movl	$0, %eax
	addq	$8, %rsp
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"



  .file	"move.c"
	.text
	.globl	exchange
	.def	exchange;	.scl	2;	.type	32;	.endef
exchange:
	movq	(%rdi), %rax
	movq	%rsi, (%rdi)
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
