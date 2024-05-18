  .globl CBFT
CBFT:
  cmpq $2, %rdi                 # n - 2
  jle .CBFT_Ret

  movl (%rsi), %r8d             # = m[0]
  movl 4(%rsi), %r9d            # = m[1]
  xorl %eax, %eax
  movl $2, %edx

.CBFT_Iter:
  movslq %edx, %rdx
  cmpq %rdx, %rdi               # n - i
  jle .CBFT_Ret

  movl (%rsi, %rdx, 4), %ecx
  cmpl %ecx, %r8d               # m[0] - m[i]
  jge .CBFT_Inc

  cmpl %ecx, %r9d               # m[1] - m[i]
  jle .CBFT_Inc
  incl %eax

.CBFT_Inc:
  incl %edx
  jmp .CBFT_Iter

.CBFT_Ret:
  ret
