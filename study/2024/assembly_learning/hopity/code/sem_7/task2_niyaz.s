.globl	str_len
str_len:
    movq $0, %rax
    testq %rdi, %rdi
    je L1
    jmp L2
L3:
    incq %rax
    incq %rdi
L2:
    movb (%rdi), %cl
    testb %cl, %cl
    jne L3
L1:
    ret