	.globl	f
f:
	cmpq	$20, %rdi
	ja	.L2
	leaq	.L4(%rip), %rdx
	movslq	(%rdx,%rdi,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section .rdata,"dr"
	.align 4
.L4:
	.long	.L2-.L4
	.long	.L9-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L10-.L4
	.long	.L11-.L4
	.long	.L12-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L2-.L4
	.long	.L3-.L4
	.text
.L3:
	movl	$0, %eax
	jmp	.L7
.L2:
	movl	$0, %eax
.L8:
	movq	%rax, (%rsi)
	ret
.L10:
	movl	$8, %eax
.L7:
	addq	$8, %rax
.L6:
	addq	$8, %rax
.L5:
	addq	$8, %rax
	jmp	.L8
.L11:
	movl	$0, %eax
	jmp	.L6
.L12:
	movl	$0, %eax
	jmp	.L5
.L9:
	movl	$5, %eax
	jmp	.L8
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	subq	$24, %rsp
	call	__main
	movq	$0, 8(%rsp)
	leaq	8(%rsp), %rsi
	movl	$5, %edi
	call	f
	movq	%rax, 8(%rsp)
	movl	$0, %eax
	addq	$24, %rsp
	ret
	.ident	"GCC: (Rev6, Built by MSYS2 project) 13.2.0"
