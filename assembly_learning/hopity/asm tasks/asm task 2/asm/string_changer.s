    .globl string_changer
# %rdi - string_pointer
string_changer:
    call check_property
    cmpb $1, %al
    je .L1
    jmp .L2
.L1:
    call procedure_1
    ret
.L2:
    call procedure_2
    ret
