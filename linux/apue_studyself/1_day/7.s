	.file	"7.c"
	.section	.rodata
.LC0:
	.string	"tmp.txt"
.LC1:
	.string	"open"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	movl	$2, 4(%esp)
	movl	$.LC0, (%esp)
	call	open
	movl	%eax, -8(%ebp)
	cmpl	$0, -8(%ebp)
	jns	.L2
	movl	$.LC1, (%esp)
	call	perror
	movl	$-1, %eax
	movl	%eax, -24(%ebp)
	jmp	.L1
.L2:
	movl	$5, 12(%esp)
	movl	$6, 8(%esp)
	leal	-14(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	pread
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	printf
	leal	-14(%ebp), %eax
	movl	$0, (%eax)
	movw	$0, 4(%eax)
	movl	$5, 12(%esp)
	movl	$6, 8(%esp)
	leal	-14(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	pread
	leal	-14(%ebp), %eax
	movl	%eax, (%esp)
	call	printf
	movl	-8(%ebp), %eax
	movl	%eax, (%esp)
	call	close
	jmp	.L4
.L1:
	movl	-24(%ebp), %eax
.L4:
	addl	$36, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 4.1.2 20080704 (Red Hat 4.1.2-48)"
	.section	.note.GNU-stack,"",@progbits
