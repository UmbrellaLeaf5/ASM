	.file	"store_prod.c"
	.text
	.globl	store_prod
	.def	store_prod;	.scl	2;	.type	32;	.endef
store_prod:
	movq	%rdi, %rcx
	movq	%rsi, %rax
	movq	%rdx, %r11
	sarq	$63, %r11
	movq	%rsi, %r9
	sarq	$63, %r9
	movq	%r9, %rsi
	imulq	%rdx, %rsi
	movq	%r11, %rdi
	imulq	%rax, %rdi
	addq	%rdi, %rsi
	mulq	%rdx
	addq	%rsi, %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	$0, (%rcx)
	movq	$0, 8(%rcx)
  xor   %rcx, %rcx
	ret
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
