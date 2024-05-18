    .globl procedure_2
# %rdi - string_pointer
procedure_2:
    pushq %r10
    pushq %r11
    testq %rdi, %rdi
    je .L1
    # end_ptr = string_pointer
    movq %rdi, %rsi
.while_loop_1:
    cmpb $0, (%rsi)
    je .loop_end_1
    incq %rsi
    jmp .while_loop_1
.loop_end_1:
    # end_ptr = itr_ptr
    movq %rsi, %rdx
    # first_itr_ptr = string_pointer
    movq %rdi, %rsi
    # current_index = 0
    movq $0, %rcx
.while_loop_2_outside:
    # first_itr_ptr != end_ptr
    cmpq %rsi, %rdx
    je .L2
    # second_itr_ptr = string_pointer
    movq %rdi, %r8
    # duplicate_flag = false
    movb $0, %r9b
.while_loop_2_inside_1:
    # second_itr_ptr != end_ptr
    cmpq %rdx, %r8
    je .L5
    # second_itr_ptr != first_itr_ptr
    cmp %r8, %rsi
    je .L4
    # *second_itr_ptr == *end_ptr
    movb (%r8), %r10b
    cmpb %r10b, (%rsi)
    jne .L4
    ## if
    # duplicate_flag = true
    movb $1, %r9b
    jmp .L5
.L4:
    # ++second_itr_ptr
    incq %r8
    jmp .while_loop_2_inside_1
.L5:
    # duplicate_flag == false
    cmpb $0, %r9b
    jne .L6
    # string_pointer[current_index] = *first_itr_ptr
    leaq (%rcx, %rdi), %r10
    movb (%rsi), %r11b
    movb %r11b, (%r10)
    inc %rcx
    jmp .L3
.L6:
    # *first_itr_ptr != '\0'
    cmpb $0, (%rsi)
    je .L3
    # duplicate_value = *first_itr_ptr
    movb (%rsi), %r10b
    # second_itr_ptr = string_pointer
    movq %rdi, %r8
.while_loop_2_inside_2:
    # second_itr_ptr != end_ptr
    cmpq %rdx, %r8
    je .L3
    cmpb (%r8), %r10b
    jne .L7
    movb $0, (%r8)
.L7:
    # ++second_itr_ptr
    incq %r8
    jmp .while_loop_2_inside_2
.L3:
    # ++first_itr_ptr
    incq %rsi
    jmp .while_loop_2_outside
.L2:
    # string_pointer[current_index] = '\0'
    leaq (%rdi, %rcx), %r8
    movb $0, (%r8)
    jmp .L1
# .L5 - after inside_1 loop
.L1:
    popq %r11
    popq %r10
    ret
