    .globl check_property
# %rdi - string_pointer
check_property:
    testq %rdi, %rdi
    je .L1
    # rsi - itr_ptr
    # itr_ptr = string_pointer
    movq %rdi, %rsi
    # edx - counter
    # counter = 0
    movl $0, %edx
    jmp .while_loop
.L1:
    movb $0, %al # return false
    ret
.L2:
    movb $1, %al # return true
    ret
.while_loop:
    cmpb $0, (%rsi)  # *itr_ptr != '\0'
    je .L4
    cmpb $97, (%rsi) # *itr_ptr >= 'a'
    jnge .L3
    cmpb $122, (%rsi) # *itr_ptr <= 'z'
    jnle .L3
    # ++counter
    incl %edx
.L3:
    # ++itr_ptr
    incq %rsi
    jmp .while_loop
.L4:
    # counter >= 10
    cmpl $10, %edx
    jnge .L1
    jmp .L2
