	.file	"tail_recursion.c"
	.text
	.type	atoi, @function
atoi:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	cmpq	$0, -8(%rbp)
	je	.L2
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L3
.L2:
	movl	-12(%rbp), %eax
	jmp	.L4
.L3:
	movl	-12(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	addl	%eax, %eax
	movl	%eax, %edx
	movq	-8(%rbp), %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	addl	%edx, %eax
	leal	-48(%rax), %edx
	movq	-8(%rbp), %rax
	addq	$1, %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	atoi
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	atoi, .-atoi
	.section	.rodata
.LC0:
	.string	"%s -> %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L6
.L7:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	atoi
	movl	%eax, %ecx
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rax
	movl	%ecx, %edx
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addl	$1, -4(%rbp)
.L6:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jne	.L7
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 6.3.1 20161221 (Red Hat 6.3.1-1)"
	.section	.note.GNU-stack,"",@progbits
