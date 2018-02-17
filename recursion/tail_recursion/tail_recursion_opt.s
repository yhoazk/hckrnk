	.file	"tail_recursion.c"
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%s -> %d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	cmpl	$1, %edi
	je	.L17
	leal	-2(%rdi), %eax
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	leaq	8(%rsi), %rbp
	leaq	16(%rsi,%rax,8), %rbx
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	.p2align 4,,10
	.p2align 3
.L7:
	movq	0(%rbp), %rsi
	testq	%rsi, %rsi
	je	.L10
	movsbl	(%rsi), %eax
	testb	%al, %al
	je	.L10
	movq	%rsi, %rcx
	xorl	%edx, %edx
	jmp	.L5
	.p2align 4,,10
	.p2align 3
.L6:
	movsbl	(%rcx), %eax
	testb	%al, %al
	je	.L3
.L5:
	leal	(%rdx,%rdx,4), %edx
	addq	$1, %rcx
	leal	-48(%rax,%rdx,2), %edx
	jne	.L6
.L3:
	xorl	%eax, %eax
	movl	$.LC0, %edi
	addq	$8, %rbp
	call	printf
	cmpq	%rbx, %rbp
	jne	.L7
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_restore 3
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_restore 6
	.cfi_def_cfa_offset 8
	ret
.L10:
	.cfi_restore_state
	xorl	%edx, %edx
	jmp	.L3
.L17:
	.cfi_def_cfa_offset 8
	.cfi_restore 3
	.cfi_restore 6
	xorl	%eax, %eax
	ret
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.3.1 20161221 (Red Hat 6.3.1-1)"
	.section	.note.GNU-stack,"",@progbits
