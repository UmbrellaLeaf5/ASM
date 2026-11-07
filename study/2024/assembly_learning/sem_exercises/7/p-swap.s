	.file	"swap.c"
	.text
.Ltext0:
	.cfi_sections	.debug_frame
	.file 0 "D://Programs//2023-2024//ASM//assembly//sem_exercises//7" "swap.c"
	.globl	swap
	.def	swap;	.scl	2;	.type	32;	.endef
	.seh_proc	swap
swap:
.LFB0:
	.file 1 "swap.c"
	.loc 1 6 13 view -0
	.cfi_startproc
	.seh_endprologue
	.loc 1 7 3 view .LVU1
	.loc 1 7 9 is_stmt 0 view .LVU2
	movq	.refptr.buf(%rip), %rdx
	leaq	4(%rdx), %rax
	movq	%rax, bufp1(%rip)
	.loc 1 9 3 is_stmt 1 view .LVU3
	.loc 1 9 13 is_stmt 0 view .LVU4
	movq	bufp0(%rip), %rax
	.loc 1 9 7 view .LVU5
	movl	(%rax), %ecx
.LVL0:
	.loc 1 10 3 is_stmt 1 view .LVU6
	.loc 1 10 12 is_stmt 0 view .LVU7
	movl	4(%rdx), %edx
	.loc 1 10 10 view .LVU8
	movl	%edx, (%rax)
	.loc 1 11 3 is_stmt 1 view .LVU9
	movq	bufp1(%rip), %rax
	.loc 1 11 10 is_stmt 0 view .LVU10
	movl	%ecx, (%rax)
	.loc 1 12 1 view .LVU11
	ret
	.cfi_endproc
.LFE0:
	.seh_endproc
	.globl	bufp1
	.bss
	.align 8
bufp1:
	.space 8
	.globl	bufp0
	.data
	.align 8
bufp0:
	.quad	buf
	.text
.Letext0:
	.section	.debug_info,"dr"
.Ldebug_info0:
	.long	0xda
	.word	0x5
	.byte	0x1
	.byte	0x8
	.secrel32	.Ldebug_abbrev0
	.uleb128 0x2
	.ascii "GNU C17 13.1.0 -mtune=generic -march=x86-64 -g -Og\0"
	.byte	0x1d
	.secrel32	.LASF0
	.secrel32	.LASF1
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.secrel32	.Ldebug_line0
	.uleb128 0x3
	.long	0x68
	.long	0x68
	.uleb128 0x4
	.byte	0
	.uleb128 0x5
	.byte	0x4
	.byte	0x5
	.ascii "int\0"
	.uleb128 0x6
	.ascii "buf\0"
	.byte	0x1
	.byte	0x1
	.byte	0xc
	.long	0x5d
	.uleb128 0x1
	.ascii "bufp0\0"
	.byte	0x3
	.long	0x91
	.uleb128 0x9
	.byte	0x3
	.quad	bufp0
	.uleb128 0x7
	.byte	0x8
	.long	0x68
	.uleb128 0x1
	.ascii "bufp1\0"
	.byte	0x4
	.long	0x91
	.uleb128 0x9
	.byte	0x3
	.quad	bufp1
	.uleb128 0x8
	.ascii "swap\0"
	.byte	0x1
	.byte	0x6
	.byte	0x6
	.quad	.LFB0
	.quad	.LFE0-.LFB0
	.uleb128 0x1
	.byte	0x9c
	.uleb128 0x9
	.ascii "tmp\0"
	.byte	0x1
	.byte	0x9
	.byte	0x7
	.long	0x68
	.secrel32	.LLST0
	.secrel32	.LVUS0
	.byte	0
	.byte	0
	.section	.debug_abbrev,"dr"
.Ldebug_abbrev0:
	.uleb128 0x1
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0x21
	.sleb128 1
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0x21
	.sleb128 6
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x2
	.uleb128 0x18
	.byte	0
	.byte	0
	.uleb128 0x2
	.uleb128 0x11
	.byte	0x1
	.uleb128 0x25
	.uleb128 0x8
	.uleb128 0x13
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x1f
	.uleb128 0x1b
	.uleb128 0x1f
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x10
	.uleb128 0x17
	.byte	0
	.byte	0
	.uleb128 0x3
	.uleb128 0x1
	.byte	0x1
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x1
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x4
	.uleb128 0x21
	.byte	0
	.byte	0
	.byte	0
	.uleb128 0x5
	.uleb128 0x24
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x3e
	.uleb128 0xb
	.uleb128 0x3
	.uleb128 0x8
	.byte	0
	.byte	0
	.uleb128 0x6
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3c
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x7
	.uleb128 0xf
	.byte	0
	.uleb128 0xb
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.byte	0
	.byte	0
	.uleb128 0x8
	.uleb128 0x2e
	.byte	0x1
	.uleb128 0x3f
	.uleb128 0x19
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x11
	.uleb128 0x1
	.uleb128 0x12
	.uleb128 0x7
	.uleb128 0x40
	.uleb128 0x18
	.uleb128 0x7a
	.uleb128 0x19
	.byte	0
	.byte	0
	.uleb128 0x9
	.uleb128 0x34
	.byte	0
	.uleb128 0x3
	.uleb128 0x8
	.uleb128 0x3a
	.uleb128 0xb
	.uleb128 0x3b
	.uleb128 0xb
	.uleb128 0x39
	.uleb128 0xb
	.uleb128 0x49
	.uleb128 0x13
	.uleb128 0x2
	.uleb128 0x17
	.uleb128 0x2137
	.uleb128 0x17
	.byte	0
	.byte	0
	.byte	0
	.section	.debug_loclists,"dr"
	.long	.Ldebug_loc3-.Ldebug_loc2
.Ldebug_loc2:
	.word	0x5
	.byte	0x8
	.byte	0
	.long	0
.Ldebug_loc0:
.LVUS0:
	.uleb128 .LVU6
	.uleb128 0
.LLST0:
	.byte	0x4
	.uleb128 .LVL0-.Ltext0
	.uleb128 .LFE0-.Ltext0
	.uleb128 0x1
	.byte	0x52
	.byte	0
.Ldebug_loc3:
	.section	.debug_aranges,"dr"
	.long	0x2c
	.word	0x2
	.secrel32	.Ldebug_info0
	.byte	0x8
	.byte	0
	.word	0
	.word	0
	.quad	.Ltext0
	.quad	.Letext0-.Ltext0
	.quad	0
	.quad	0
	.section	.debug_line,"dr"
.Ldebug_line0:
	.section	.debug_str,"dr"
	.section	.debug_line_str,"dr"
.LASF1:
	.ascii "D:\\\\Programs\\\\2023-2024\\\\ASM\\\\assembly\\\\sem_exercises\\\\7\0"
.LASF0:
	.ascii "swap.c\0"
	.ident	"GCC: (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders) 13.1.0"
	.section	.rdata$.refptr.buf, "dr"
	.globl	.refptr.buf
	.linkonce	discard
.refptr.buf:
	.quad	buf
