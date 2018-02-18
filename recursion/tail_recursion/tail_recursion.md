# [Tail recursion in GCC](https://stackoverflow.com/questions/490324/how-do-i-check-if-gcc-is-performing-tail-recursion-optimization)

Tail recursion is a optimization technique to avoid stack overruns
when executing recursive functions. The optimization consists of 
calling only the __tail__ of the function with out generating a 
new stack frame on each call to the function.

This optimization is applied to functions which recursive call is
made in the return statement:

```c
int fnc_tail_rec(int k)
{
  ...
  return fnc_tail_rec(k+1);
}
```

## Example:

The next function:


```
#include <stdio.h>
static int atoi(const char *str, int n)
{
    if (str == 0 || *str == 0)
        return n;
    return atoi(str+1, n*10 + *str-'0');
}
int main(int argc, char **argv)
{
    for (int i = 1; i != argc; ++i)
        printf("%s -> %d\n", argv[i], atoi(argv[i], 0));
    return 0;
}
```

And it's disassembly w/o optimization:
```asm
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
```
It's clear that the function is creating a new stack on each call, it is 
created by the operation `call`, while in the ASM for the optimized code
there are no calls to the function, and it is distributed in all the 
code.
