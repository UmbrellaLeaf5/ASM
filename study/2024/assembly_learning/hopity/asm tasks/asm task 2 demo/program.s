	.file	"program.c"
	.text
	.globl	string_changer
	.def	string_changer;	.scl	2;	.type	32;	.endef
	.seh_proc	string_changer
string_changer:
	.seh_endprologue
	testq	%rcx, %rcx
	je	.L1
	movq	%rcx, %rdx
	movl	$0, %r8d
	jmp	.L3
.L4:
	addq	$1, %rdx
.L3:
	movzbl	(%rdx), %eax
	testb	%al, %al
	je	.L9
	subl	$97, %eax
	cmpb	$25, %al
	ja	.L4
	addl	$1, %r8d
	jmp	.L4
.L9:
	cmpl	$9, %r8d
	jg	.L6
.L1:
	ret
.L7:
	addq	$1, %rcx
.L6:
	movzbl	(%rcx), %eax
	testb	%al, %al
	je	.L1
	leal	-97(%rax), %edx
	cmpb	$25, %dl
	ja	.L7
	subl	$32, %eax
	movb	%al, (%rcx)
	jmp	.L7
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
