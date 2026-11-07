	.file	"main.c"
	.text
	.globl	g
	.def	g;	.scl	2;	.type	32;	.endef
g:
	movl	$0, %eax
	ret
	.globl	f
	.def	f;	.scl	2;	.type	32;	.endef
f:
	pushq	%rbx
	subq	$16, %rsp
	leaq	1(%rdi), %rsi
	leaq	3(%rdi), %rbx
	leaq	5(%rdi), %rcx
	leaq	4(%rdi), %rdx
	leaq	2(%rdi), %rax
	movq	%rsi, 8(%rsp)
	movl	$1, (%rsp)
	leaq	7(%rdi), %r9
	leaq	6(%rdi), %r8
	movq	%rbx, %rsi
	movq	%rax, %rdi
	call	g
	movsbq	(%rax), %rax
	addq	%rbx, %rax
	addq	$16, %rsp
	popq	%rbx
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
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.2.0"
