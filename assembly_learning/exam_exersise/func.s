  .globl is_pow2
is_pow2:
  xorq %rax, %rax

.iter:
  cmpl $0, %edi
  jle .return
  movl %edi, %esi
  andl $1, %edi
  testl %edi, %edi
  jnz .counter_plus
  jmp .iter_2

.counter_plus:
  incl %eax

.iter_2:
  movl %esi, %edi
  shrl $1, %edi
  jmp .iter

.return:
  cmpl $1, %eax
  sete %al
  ret



  .globl is_pow2_compiler
# (reslized by protected do-while) 
is_pow2_compiler:
	movl	$0, %eax
	jmp	.L16

.L17:
	movl	%edi, %edx
	andl	$1, %edx
	addl	%edx, %eax
	shrl	%edi

.L16:
	testl	%edi, %edi
	jne	.L17

	cmpl	$1, %eax
	sete	%al
	movzbl	%al, %eax
	ret
