  movq %rdi, %rax
  jmp .L2
.L3:
  sarq %rax
.L2:
  testq %rax, %rax
  jg .L3
  ret
