	.file	"2zhizhenheshuzu.c"
	.section	.rodata
.LC0:
	.string	"a[]= %s\n"
.LC1:
	.string	"world"
.LC2:
	.string	"*p=  %s\n"
	.text
.globl main
	.type	main, @function
main:
	pushl	%ebp
	movl	%esp, %ebp
	andl	$-16, %esp
	subl	$32, %esp
	movl	$1819043176, 22(%esp)
	movw	$111, 26(%esp)
	movb	$88, 22(%esp)
	movl	$49, (%esp)
	call	putchar
	movl	$.LC0, %eax
	leal	22(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$.LC1, 28(%esp)
	movl	$49, (%esp)
	call	putchar
	movl	$.LC2, %eax
	movl	28(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	leave
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.4.3-4ubuntu5.1) 4.4.3"
	.section	.note.GNU-stack,"",@progbits
