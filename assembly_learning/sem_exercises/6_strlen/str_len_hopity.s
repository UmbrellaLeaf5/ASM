  .globl  StrLenHopity
StrLenHopity:
  movq $0, %rax
  testq %rdi, %rdi
  je L1
  jmp L2
L1:
  ret
L2:
  cmpb $0, (%rdi)
  je L1
  incq %rax
  incq %rdi
  jmp L2
