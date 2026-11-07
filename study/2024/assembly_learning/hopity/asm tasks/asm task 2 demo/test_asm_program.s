    .globl array
array:
    movq $80, %rdi
    call malloc
    movq $8, %r8
.loop:
    leaq (%r8, %rax), %r9
    movq %r8, (%r9)
    cmpq $80, %r8
    jg .L1
    addq $8, %r8
.L1:
    ret
