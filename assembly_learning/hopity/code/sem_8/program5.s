	.file	"program5.cpp"
	.text
	.align 2
	.globl	_ZN1A5printEv
	.def	_ZN1A5printEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1A5printEv
_ZN1A5printEv:
.LFB2229:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, %rbx
	movl	(%rcx), %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	movq	%rax, %rcx
	movl	$32, %edx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c
	movq	%rax, %rcx
	movl	4(%rbx), %edx
	call	_ZNSolsEi
	movq	%rax, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	nop
	addq	$32, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.align 2
	.globl	_ZN1AC2Ev
	.def	_ZN1AC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AC2Ev
_ZN1AC2Ev:
.LFB2231:
	.seh_endprologue
	movl	$1, (%rcx)
	movl	$2, 4(%rcx)
	ret
	.seh_endproc
	.globl	_ZN1AC1Ev
	.def	_ZN1AC1Ev;	.scl	2;	.type	32;	.endef
	.set	_ZN1AC1Ev,_ZN1AC2Ev
	.align 2
	.globl	_ZN1AC2Eii
	.def	_ZN1AC2Eii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AC2Eii
_ZN1AC2Eii:
.LFB2234:
	.seh_endprologue
	movl	%edx, (%rcx)
	movl	%r8d, 4(%rcx)
	ret
	.seh_endproc
	.globl	_ZN1AC1Eii
	.def	_ZN1AC1Eii;	.scl	2;	.type	32;	.endef
	.set	_ZN1AC1Eii,_ZN1AC2Eii
	.globl	_Z9some_funci
	.def	_Z9some_funci;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z9some_funci
_Z9some_funci:
.LFB2236:
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	40(%rsp), %rbx
	movq	%rbx, %rcx
	call	_ZN1AC1Ev
	movq	%rbx, %rcx
	call	_ZN1A5printEv
	movl	$50, 40(%rsp)
	movq	%rbx, %rcx
	call	_ZN1A5printEv
	nop
	addq	$48, %rsp
	popq	%rbx
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-posix-seh-rev1, Built by MinGW-Builds project) 13.1.0"
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_c;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
