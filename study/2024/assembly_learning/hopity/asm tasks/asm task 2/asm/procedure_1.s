    .globl procedure_1
# %rdi - string_pointer
procedure_1:
    # itr_ptr = string_pointer
    mov %rdi, %rsi
.while_loop:
    cmpb $0, (%rsi) # *itr_ptr != '\0'
    je .L1
    cmpb $97, (%rsi) # *itr_ptr >= 'a'
    jnge .L2
    cmpb $122, (%rsi) # *itr_ptr <= 'z'
    jnle .L2
    ## if
    subb $32, (%rsi) # *itr_ptr -= 'A' - 'a'
.L2:
    incq %rsi # ++itr_ptr
    jmp .while_loop
.L1:
    ret
