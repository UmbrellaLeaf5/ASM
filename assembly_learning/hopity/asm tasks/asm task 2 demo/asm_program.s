    .globl  string_changer
# %rdi - const char* string_pointer
string_changer:
    testq %rdi, %rdi
    je .L1
    # r8 - itr_ptr
    # itr_ptr = string_pointer
    movq %rdi, %r8
    # r9d - counter
    # counter = 0
    movl $0, %r9d
    jmp .while_loop_1
.L1:
    ret
.while_loop_1:
    # *itr_ptr != '\0'
    cmpb $0, (%r8)
    je .L3
    # *itr_ptr >= 97
    cmpb $97, (%r8)
    jnge .L2
    # *itr_ptr <= 122
    cmpb $122, (%r8)
    jnle .L2
    # ++counter
    incl %r9d
.L2:
    # ++itr_ptr
    # idk about that
    incq %r8
    jmp .while_loop_1
.L3:
    # counter >= 10
    cmpl $10, %r9d
    jnge .rule_2
    # itr_ptr = string_pointer
    movq %rdi, %r8
.rule_1:
    cmpb $0, (%r8)
    je .L1
    cmpb $97, (%r8)
    jnge .L4
    cmpb $122, (%r8)
    jnle .L4
    ## if
    subb $32, (%r8)
.L4:
    incq %r8
    jmp .rule_1
.rule_2:
    # end_ptr = itr_ptr
    movq %r8, %r9
    # first_itr_ptr = string_pointer
    movq %rdi, %r8
    # current_index = 0
    movq $0, %r10
.while_loop_2_outside:
    # first_itr_ptr != end_ptr
    cmpq %r8, %r9
    je .L5
    # second_itr_ptr = string_pointer
    movq %rdi, %r11
    # duplicate_flag = false
    movb $0, %r12b
.while_loop_2_inside_1:
    # second_itr_ptr != end_ptr
    cmpq %r9, %r11
    je .L8
    # second_itr_ptr != first_itr_ptr
    cmp %r11, %r8
    je .L7
    # *second_itr_ptr == *end_ptr
    movb (%r11), %r13b
    cmpb %r13b, (%r8)
    jne .L7
    ## if
    # duplicate_flag = true
    movb $1, %r12b
    jmp .L8
.L7:
    # ++second_itr_ptr
    incq %r11
    jmp .while_loop_2_inside_1
.L8:
    # duplicate_flag == false
    cmpb $0, %r12b
    jne .L9
    # string_pointer[current_index] = *first_itr_ptr
    leaq (%r10, %rdi), %r13
    movb (%r8), %r14b
    movb %r14b, (%r13)
    inc %r10
    jmp .L6
.L9:
    # *first_itr_ptr != '\0'
    cmpb $0, (%r8)
    je .L6
    # duplicate_value = *first_itr_ptr
    movb (%r8), %r13b
    # second_itr_ptr = string_pointer
    movq %rdi, %r11
.while_loop_2_inside_2:
    # second_itr_ptr != end_ptr
    cmpq %r9, %r11
    je .L6
    cmpb (%r11), %r13b
    jne .L10
    movb $0, (%r11)
.L10:
    # ++second_itr_ptr
    incq %r11
    jmp .while_loop_2_inside_2
.L6:
    # ++first_itr_ptr
    incq %r8
    jmp .while_loop_2_outside
.L5:
    # string_pointer[current_index] = '\0'
    leaq (%rdi, %r10), %r11
    movb $0, (%r11)
    jmp .L1
# .L8 - after inside_1 loop
