	.file	"all.c"
	.text
	.globl	INT_CMP
	.type	INT_CMP, @function
INT_CMP:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movq	-8(%rbp), %rax
	movl	(%rax), %edx
	movq	-16(%rbp), %rax
	movl	(%rax), %eax
	subl	%eax, %edx
	movl	%edx, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	INT_CMP, .-INT_CMP
	.globl	HeapCmp
	.type	HeapCmp, @function
HeapCmp:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rsi, %rax
	movq	%rdi, %r8
	movq	%r8, %rsi
	movq	%r9, %rdi
	movq	%rax, %rdi
	movq	%rsi, -16(%rbp)
	movq	%rdi, -8(%rbp)
	movq	%rdx, -32(%rbp)
	movq	%rcx, -24(%rbp)
	movq	-16(%rbp), %rdx
	movq	-32(%rbp), %rax
	cmpq	%rax, %rdx
	jge	.L4
	movl	$1, %eax
	jmp	.L5
.L4:
	movl	$0, %eax
.L5:
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	HeapCmp, .-HeapCmp
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"all.c"
.LC2:
	.string	"h->curr_size>0"
.LC3:
	.string	"h->curr_size<=h->max_size"
.LC4:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB8:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%r15
	pushq	%r14
	pushq	%r13
	pushq	%r12
	pushq	%rbx
	subq	$456, %rsp
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
	movq	%fs:40, %rax
	movq	%rax, -56(%rbp)
	xorl	%eax, %eax
	leaq	-244(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	jmp	.L7
.L43:
	movq	%rsp, %rax
	movq	%rax, -472(%rbp)
	leaq	-240(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-240(%rbp), %esi
	movl	-240(%rbp), %edi
	movslq	%esi, %rax
	subq	$1, %rax
	movq	%rax, -200(%rbp)
	movslq	%esi, %rax
	movq	%rax, -384(%rbp)
	movq	$0, -376(%rbp)
	movslq	%esi, %rax
	leaq	0(,%rax,4), %r12
	movslq	%edi, %rax
	subq	$1, %rax
	movq	%rax, -192(%rbp)
	movslq	%esi, %rax
	movq	%rax, -272(%rbp)
	movq	$0, -264(%rbp)
	movslq	%edi, %rax
	movq	%rax, -288(%rbp)
	movq	$0, -280(%rbp)
	movq	-272(%rbp), %r8
	movq	-264(%rbp), %r9
	movq	%r9, %rdx
	movq	-288(%rbp), %r10
	movq	-280(%rbp), %r11
	imulq	%r10, %rdx
	movq	%r11, %rax
	imulq	%r8, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r8, %rax
	mulq	%r10
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rax
	movq	%rax, -304(%rbp)
	movq	$0, -296(%rbp)
	movslq	%edi, %rax
	movq	%rax, %r14
	movl	$0, %r15d
	movq	-304(%rbp), %r9
	movq	-296(%rbp), %r10
	movq	%r10, %rdx
	imulq	%r14, %rdx
	movq	%r9, %rax
	imulq	%r15, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r9, %rax
	mulq	%r14
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rdx
	movslq	%edi, %rax
	imulq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rdx
	movq	%rdx, %rax
	andq	$-4096, %rax
	movq	%rsp, %rbx
	subq	%rax, %rbx
	movq	%rbx, %rax
.L8:
	cmpq	%rax, %rsp
	je	.L9
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L8
.L9:
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	movq	%rdx, %rax
	andl	$4095, %eax
	testq	%rax, %rax
	je	.L10
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L10:
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -184(%rbp)
	movl	$0, -204(%rbp)
	jmp	.L11
.L14:
	movl	$0, -208(%rbp)
	jmp	.L12
.L13:
	movq	%r12, %rcx
	shrq	$2, %rcx
	movl	-208(%rbp), %eax
	movslq	%eax, %rdx
	movl	-204(%rbp), %eax
	cltq
	imulq	%rcx, %rax
	addq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	movq	-184(%rbp), %rax
	addq	%rdx, %rax
	movq	%rax, %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	addl	$1, -208(%rbp)
.L12:
	movl	-240(%rbp), %eax
	cmpl	%eax, -208(%rbp)
	jl	.L13
	movl	-240(%rbp), %eax
	movslq	%eax, %rsi
	movq	%r12, %rdx
	shrq	$2, %rdx
	movl	-204(%rbp), %eax
	cltq
	imulq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	movq	-184(%rbp), %rax
	addq	%rdx, %rax
	leaq	INT_CMP(%rip), %rcx
	movl	$4, %edx
	movq	%rax, %rdi
	call	qsort@PLT
	addl	$1, -204(%rbp)
.L11:
	movl	-240(%rbp), %eax
	cmpl	%eax, -204(%rbp)
	jl	.L14
	leaq	HeapCmp(%rip), %rsi
	movl	$1000000, %edi
	call	_Init_Heap
	movq	%rax, -176(%rbp)
	movl	-240(%rbp), %edx
	movq	%rsp, %rax
	movq	%rax, -480(%rbp)
	movslq	%edx, %rax
	subq	$1, %rax
	movq	%rax, -168(%rbp)
	movslq	%edx, %rax
	movq	%rax, -400(%rbp)
	movq	$0, -392(%rbp)
	movslq	%edx, %rax
	movq	%rax, -416(%rbp)
	movq	$0, -408(%rbp)
	movslq	%edx, %rax
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %ebx
	movl	$0, %edx
	divq	%rbx
	imulq	$16, %rax, %rdx
	movq	%rdx, %rax
	andq	$-4096, %rax
	movq	%rsp, %rbx
	subq	%rax, %rbx
	movq	%rbx, %rax
.L15:
	cmpq	%rax, %rsp
	je	.L16
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L15
.L16:
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	movq	%rdx, %rax
	andl	$4095, %eax
	testq	%rax, %rax
	je	.L17
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L17:
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -160(%rbp)
	movl	$0, -212(%rbp)
	jmp	.L18
.L19:
	movq	-184(%rbp), %rdx
	movl	-212(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %ecx
	movq	-160(%rbp), %rdx
	movl	-212(%rbp), %eax
	cltq
	movl	%ecx, (%rdx,%rax,4)
	addl	$1, -212(%rbp)
.L18:
	movl	-240(%rbp), %eax
	cmpl	%eax, -212(%rbp)
	jl	.L19
	movl	-240(%rbp), %esi
	movl	-240(%rbp), %edi
	movq	%rsp, %rax
	movq	%rax, -488(%rbp)
	movslq	%esi, %rax
	subq	$1, %rax
	movq	%rax, -152(%rbp)
	movslq	%esi, %rax
	movq	%rax, -432(%rbp)
	movq	$0, -424(%rbp)
	movslq	%esi, %rax
	leaq	0(,%rax,4), %rbx
	movslq	%edi, %rax
	subq	$1, %rax
	movq	%rax, -144(%rbp)
	movslq	%esi, %rax
	movq	%rax, -320(%rbp)
	movq	$0, -312(%rbp)
	movslq	%edi, %rax
	movq	%rax, -336(%rbp)
	movq	$0, -328(%rbp)
	movq	-320(%rbp), %r8
	movq	-312(%rbp), %r9
	movq	%r9, %rdx
	movq	-336(%rbp), %r10
	movq	-328(%rbp), %r11
	imulq	%r10, %rdx
	movq	%r11, %rax
	imulq	%r8, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r8, %rax
	mulq	%r10
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rax
	movq	%rax, -352(%rbp)
	movq	$0, -344(%rbp)
	movslq	%edi, %rax
	movq	%rax, -368(%rbp)
	movq	$0, -360(%rbp)
	movq	-352(%rbp), %r8
	movq	-344(%rbp), %r9
	movq	%r9, %rdx
	movq	-368(%rbp), %r10
	movq	-360(%rbp), %r11
	imulq	%r10, %rdx
	movq	%r11, %rax
	imulq	%r8, %rax
	leaq	(%rdx,%rax), %rcx
	movq	%r8, %rax
	mulq	%r10
	addq	%rdx, %rcx
	movq	%rcx, %rdx
	movslq	%esi, %rdx
	movslq	%edi, %rax
	imulq	%rdx, %rax
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rdx
	movq	%rdx, %rax
	andq	$-4096, %rax
	movq	%rsp, %rdi
	subq	%rax, %rdi
	movq	%rdi, %rax
.L20:
	cmpq	%rax, %rsp
	je	.L21
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L20
.L21:
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	movq	%rdx, %rax
	andl	$4095, %eax
	testq	%rax, %rax
	je	.L22
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L22:
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -136(%rbp)
	movl	$0, -216(%rbp)
	jmp	.L23
.L26:
	movl	$0, -220(%rbp)
	jmp	.L24
.L25:
	movq	%rbx, %rsi
	shrq	$2, %rsi
	movq	-136(%rbp), %rcx
	movl	-220(%rbp), %eax
	movslq	%eax, %rdx
	movl	-216(%rbp), %eax
	cltq
	imulq	%rsi, %rax
	addq	%rdx, %rax
	movl	$0, (%rcx,%rax,4)
	addl	$1, -220(%rbp)
.L24:
	movl	-240(%rbp), %eax
	cmpl	%eax, -220(%rbp)
	jl	.L25
	addl	$1, -216(%rbp)
.L23:
	movl	-240(%rbp), %eax
	cmpl	%eax, -216(%rbp)
	jl	.L26
	movl	$1, -224(%rbp)
	jmp	.L27
.L40:
	movq	%rsp, %rax
	movq	%rax, %r13
	movq	-160(%rbp), %rax
	movl	(%rax), %esi
	movq	%r12, %rcx
	shrq	$2, %rcx
	movq	-184(%rbp), %rdx
	movl	-224(%rbp), %eax
	cltq
	imulq	%rcx, %rax
	movl	(%rdx,%rax,4), %eax
	addl	%esi, %eax
	cltq
	movq	%rax, -112(%rbp)
	movl	$0, -104(%rbp)
	movl	$0, -100(%rbp)
	movq	-112(%rbp), %rcx
	movq	-104(%rbp), %rdx
	movq	-176(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	insertIntoHeap
	movq	-136(%rbp), %rdx
	movl	-224(%rbp), %eax
	movl	%eax, (%rdx)
	movl	-240(%rbp), %edx
	movslq	%edx, %rax
	subq	$1, %rax
	movq	%rax, -128(%rbp)
	movslq	%edx, %rax
	movq	%rax, -448(%rbp)
	movq	$0, -440(%rbp)
	movslq	%edx, %rax
	movq	%rax, -464(%rbp)
	movq	$0, -456(%rbp)
	movslq	%edx, %rax
	leaq	0(,%rax,4), %rdx
	movl	$16, %eax
	subq	$1, %rax
	addq	%rdx, %rax
	movl	$16, %esi
	movl	$0, %edx
	divq	%rsi
	imulq	$16, %rax, %rdx
	movq	%rdx, %rax
	andq	$-4096, %rax
	movq	%rsp, %rdi
	subq	%rax, %rdi
	movq	%rdi, %rax
.L28:
	cmpq	%rax, %rsp
	je	.L29
	subq	$4096, %rsp
	orq	$0, 4088(%rsp)
	jmp	.L28
.L29:
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	%rax, %rsp
	movq	%rdx, %rax
	andl	$4095, %eax
	testq	%rax, %rax
	je	.L30
	movq	%rdx, %rax
	andl	$4095, %eax
	subq	$8, %rax
	addq	%rsp, %rax
	orq	$0, (%rax)
.L30:
	movq	%rsp, %rax
	addq	$3, %rax
	shrq	$2, %rax
	salq	$2, %rax
	movq	%rax, -120(%rbp)
	movl	$0, -228(%rbp)
	jmp	.L31
.L37:
	movq	-176(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L32
	leaq	__PRETTY_FUNCTION__.4150(%rip), %rcx
	movl	$80, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC2(%rip), %rdi
	call	__assert_fail@PLT
.L32:
	movq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	removeMinFromHeap
	movq	%rax, -96(%rbp)
	movq	%rdx, -88(%rbp)
	movq	-96(%rbp), %rax
	movl	%eax, %ecx
	movq	-120(%rbp), %rdx
	movl	-228(%rbp), %eax
	cltq
	movl	%ecx, (%rdx,%rax,4)
	movl	-88(%rbp), %edx
	movl	-240(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, %edx
	jge	.L33
	movq	%rbx, %rdi
	shrq	$2, %rdi
	movl	-88(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-84(%rbp), %eax
	movq	-136(%rbp), %rsi
	movslq	%eax, %rdx
	movslq	%ecx, %rax
	imulq	%rdi, %rax
	addq	%rdx, %rax
	movl	(%rsi,%rax,4), %eax
	cmpl	%eax, -224(%rbp)
	jle	.L33
	movq	-96(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movl	-72(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -72(%rbp)
	movq	-80(%rbp), %rsi
	movl	-72(%rbp), %eax
	movq	-160(%rbp), %rdx
	cltq
	movl	(%rdx,%rax,4), %ecx
	movl	-72(%rbp), %eax
	subl	$1, %eax
	movq	-160(%rbp), %rdx
	cltq
	movl	(%rdx,%rax,4), %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	cltq
	addq	%rsi, %rax
	movq	%rax, -80(%rbp)
	movq	-176(%rbp), %rax
	movq	(%rax), %rdx
	movq	-176(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, %rdx
	jbe	.L34
	leaq	__PRETTY_FUNCTION__.4150(%rip), %rcx
	movl	$87, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	call	__assert_fail@PLT
.L34:
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	-176(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	insertIntoHeap
	movq	%rbx, %rdi
	shrq	$2, %rdi
	movl	-88(%rbp), %eax
	leal	1(%rax), %ecx
	movl	-84(%rbp), %eax
	movq	-136(%rbp), %rsi
	movslq	%eax, %rdx
	movslq	%ecx, %rax
	imulq	%rdi, %rax
	addq	%rax, %rdx
	movl	-224(%rbp), %eax
	movl	%eax, (%rsi,%rdx,4)
.L33:
	movl	-84(%rbp), %edx
	movl	-240(%rbp), %eax
	subl	$1, %eax
	cmpl	%eax, %edx
	jge	.L35
	movq	%rbx, %rdi
	shrq	$2, %rdi
	movl	-88(%rbp), %esi
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movq	-136(%rbp), %rcx
	movslq	%eax, %rdx
	movslq	%esi, %rax
	imulq	%rdi, %rax
	addq	%rdx, %rax
	movl	(%rcx,%rax,4), %eax
	cmpl	%eax, -224(%rbp)
	jle	.L35
	movq	-96(%rbp), %rax
	movq	-88(%rbp), %rdx
	movq	%rax, -80(%rbp)
	movq	%rdx, -72(%rbp)
	movl	-68(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -68(%rbp)
	movq	-80(%rbp), %r8
	movq	%r12, %rsi
	shrq	$2, %rsi
	movl	-68(%rbp), %eax
	movq	-184(%rbp), %rcx
	movslq	%eax, %rdx
	movl	-224(%rbp), %eax
	cltq
	imulq	%rsi, %rax
	addq	%rdx, %rax
	movl	(%rcx,%rax,4), %edi
	movq	%r12, %rsi
	shrq	$2, %rsi
	movl	-68(%rbp), %eax
	subl	$1, %eax
	movq	-184(%rbp), %rcx
	movslq	%eax, %rdx
	movl	-224(%rbp), %eax
	cltq
	imulq	%rsi, %rax
	addq	%rdx, %rax
	movl	(%rcx,%rax,4), %eax
	subl	%eax, %edi
	movl	%edi, %eax
	cltq
	addq	%r8, %rax
	movq	%rax, -80(%rbp)
	movq	-176(%rbp), %rax
	movq	(%rax), %rdx
	movq	-176(%rbp), %rax
	movq	8(%rax), %rax
	cmpq	%rax, %rdx
	jbe	.L36
	leaq	__PRETTY_FUNCTION__.4150(%rip), %rcx
	movl	$95, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC3(%rip), %rdi
	call	__assert_fail@PLT
.L36:
	movq	-80(%rbp), %rcx
	movq	-72(%rbp), %rdx
	movq	-176(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	insertIntoHeap
	movq	%rbx, %rdi
	shrq	$2, %rdi
	movl	-88(%rbp), %ecx
	movl	-84(%rbp), %eax
	addl	$1, %eax
	movq	-136(%rbp), %rsi
	movslq	%eax, %rdx
	movslq	%ecx, %rax
	imulq	%rdi, %rax
	addq	%rax, %rdx
	movl	-224(%rbp), %eax
	movl	%eax, (%rsi,%rdx,4)
.L35:
	addl	$1, -228(%rbp)
.L31:
	movl	-240(%rbp), %eax
	cmpl	%eax, -228(%rbp)
	jl	.L37
	movl	$0, -232(%rbp)
	jmp	.L38
.L39:
	movq	-120(%rbp), %rdx
	movl	-232(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %ecx
	movq	-160(%rbp), %rdx
	movl	-232(%rbp), %eax
	cltq
	movl	%ecx, (%rdx,%rax,4)
	addl	$1, -232(%rbp)
.L38:
	movl	-240(%rbp), %eax
	cmpl	%eax, -232(%rbp)
	jl	.L39
	movq	-176(%rbp), %rax
	movq	$0, (%rax)
	movq	%r13, %rsp
	addl	$1, -224(%rbp)
.L27:
	movl	-240(%rbp), %eax
	cmpl	%eax, -224(%rbp)
	jl	.L40
	movl	$0, -236(%rbp)
	jmp	.L41
.L42:
	movq	-160(%rbp), %rdx
	movl	-236(%rbp), %eax
	cltq
	movl	(%rdx,%rax,4), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -236(%rbp)
.L41:
	movl	-240(%rbp), %eax
	cmpl	%eax, -236(%rbp)
	jl	.L42
	movl	$10, %edi
	call	putchar@PLT
	movq	-176(%rbp), %rax
	movq	16(%rax), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-176(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-488(%rbp), %rsp
	movq	-480(%rbp), %rsp
	movq	-472(%rbp), %rsp
.L7:
	movl	-244(%rbp), %edx
	leal	-1(%rdx), %eax
	movl	%eax, -244(%rbp)
	testl	%edx, %edx
	jne	.L43
	movl	$0, %eax
	movq	-56(%rbp), %rbx
	xorq	%fs:40, %rbx
	je	.L45
	call	__stack_chk_fail@PLT
.L45:
	leaq	-40(%rbp), %rsp
	popq	%rbx
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	main, .-main
	.section	.rodata
.LC5:
	.string	"temp != NULL"
	.text
	.globl	_Init_Heap
	.type	_Init_Heap, @function
_Init_Heap:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$32, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	cmpq	$0, -8(%rbp)
	jne	.L47
	leaq	__PRETTY_FUNCTION__.4181(%rip), %rcx
	movl	$119, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC5(%rip), %rdi
	call	__assert_fail@PLT
.L47:
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, 8(%rax)
	movq	-8(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, 24(%rax)
	movq	-8(%rbp), %rax
	movq	$0, (%rax)
	movq	-24(%rbp), %rax
	addq	$1, %rax
	salq	$4, %rax
	movq	%rax, %rdi
	call	malloc@PLT
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, 16(%rax)
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	_Init_Heap, .-_Init_Heap
	.globl	insertIntoHeap
	.type	insertIntoHeap, @function
insertIntoHeap:
.LFB10:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%rdi, -40(%rbp)
	movq	%rdx, %rcx
	movq	%rsi, %rax
	movq	%rdi, %rdx
	movq	%rcx, %rdx
	movq	%rax, -64(%rbp)
	movq	%rdx, -56(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	addq	$1, %rax
	salq	$4, %rax
	leaq	(%rdx,%rax), %rcx
	movq	-64(%rbp), %rax
	movq	-56(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	.L50
.L52:
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rdx
	movl	-20(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%ecx, %eax
	sarl	%eax
	cltq
	salq	$4, %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rdx
	movl	-20(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%ecx, %eax
	sarl	%eax
	cltq
	salq	$4, %rax
	leaq	(%rdx,%rax), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movl	-20(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -20(%rbp)
.L50:
	cmpl	$1, -20(%rbp)
	jle	.L51
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rdx
	movl	-20(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%ecx, %eax
	sarl	%eax
	cltq
	salq	$4, %rax
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	jne	.L52
.L51:
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	leaq	1(%rax), %rdx
	movq	-40(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	insertIntoHeap, .-insertIntoHeap
	.globl	GetMinHeap
	.type	GetMinHeap, @function
GetMinHeap:
.LFB11:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movq	24(%rax), %rdx
	movq	16(%rax), %rax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	GetMinHeap, .-GetMinHeap
	.globl	buildHeap
	.type	buildHeap, @function
buildHeap:
.LFB12:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movq	%rdx, -40(%rbp)
	movq	-40(%rbp), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_Init_Heap
	movq	%rax, -8(%rbp)
	movl	$0, -16(%rbp)
	jmp	.L56
.L57:
	movl	-16(%rbp), %eax
	cltq
	salq	$4, %rax
	movq	%rax, %rdx
	movq	-32(%rbp), %rax
	addq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	16(%rax), %rax
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	addq	$1, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	addl	$1, -16(%rbp)
.L56:
	movl	-16(%rbp), %eax
	cltq
	cmpq	%rax, -24(%rbp)
	ja	.L57
	movq	-8(%rbp), %rax
	movq	-24(%rbp), %rdx
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	shrq	%rax
	movl	%eax, -12(%rbp)
	jmp	.L58
.L59:
	movl	-12(%rbp), %edx
	movq	-8(%rbp), %rax
	movl	%edx, %esi
	movq	%rax, %rdi
	call	perculateDown
	subl	$1, -12(%rbp)
.L58:
	cmpl	$0, -12(%rbp)
	jg	.L59
	movq	-8(%rbp), %rax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE12:
	.size	buildHeap, .-buildHeap
	.section	.rodata
.LC6:
	.string	"h->curr_size>=1"
	.text
	.globl	removeMinFromHeap
	.type	removeMinFromHeap, @function
removeMinFromHeap:
.LFB13:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	.L62
	leaq	__PRETTY_FUNCTION__.4213(%rip), %rcx
	movl	$164, %edx
	leaq	.LC1(%rip), %rsi
	leaq	.LC6(%rip), %rdi
	call	__assert_fail@PLT
.L62:
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	movq	24(%rax), %rdx
	movq	16(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-24(%rbp), %rax
	movq	16(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	salq	$4, %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	16(%rax), %rax
	leaq	16(%rax), %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	%rdx, (%rax)
	movq	-24(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	perculateDown
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	removeMinFromHeap, .-removeMinFromHeap
	.globl	perculateDown
	.type	perculateDown, @function
perculateDown:
.LFB14:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp
	movq	%rdi, -40(%rbp)
	movl	%esi, -44(%rbp)
	movl	-44(%rbp), %eax
	movl	%eax, -20(%rbp)
	jmp	.L65
.L74:
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	ja	.L75
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jbe	.L68
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	addl	%ecx, %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L76
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	leaq	(%rax,%rdx), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	jmp	.L76
.L68:
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L70
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	jne	.L77
.L70:
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L71
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	addl	%ecx, %ecx
	movslq	%ecx, %rcx
	addq	$1, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L71
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	leaq	(%rax,%rdx), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	.L65
.L71:
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	addl	%ecx, %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L72
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L72
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	leaq	(%rax,%rdx), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	sall	-20(%rbp)
	jmp	.L65
.L72:
	movq	-40(%rbp), %rax
	movq	24(%rax), %r8
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	addl	%ecx, %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	(%rcx), %rdi
	movq	8(%rcx), %rsi
	movq	%rdx, %rcx
	movq	%rax, %rdx
	call	*%r8
	testl	%eax, %eax
	je	.L73
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	leaq	(%rax,%rdx), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	sall	-20(%rbp)
	jmp	.L65
.L73:
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$4, %rdx
	addq	%rdx, %rax
	movq	8(%rax), %rdx
	movq	(%rax), %rax
	movq	%rax, -16(%rbp)
	movq	%rdx, -8(%rbp)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	addq	%rax, %rdx
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$4, %rcx
	addq	%rax, %rcx
	movq	(%rdx), %rax
	movq	8(%rdx), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movq	-40(%rbp), %rax
	movq	16(%rax), %rax
	movl	-20(%rbp), %edx
	addl	%edx, %edx
	movslq	%edx, %rdx
	addq	$1, %rdx
	salq	$4, %rdx
	leaq	(%rax,%rdx), %rcx
	movq	-16(%rbp), %rax
	movq	-8(%rbp), %rdx
	movq	%rax, (%rcx)
	movq	%rdx, 8(%rcx)
	movl	-20(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
.L65:
	movl	-20(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	cmpq	%rax, %rdx
	jb	.L74
	jmp	.L64
.L75:
	nop
	jmp	.L64
.L76:
	nop
	jmp	.L64
.L77:
	nop
.L64:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	perculateDown, .-perculateDown
	.section	.rodata
	.type	__PRETTY_FUNCTION__.4150, @object
	.size	__PRETTY_FUNCTION__.4150, 5
__PRETTY_FUNCTION__.4150:
	.string	"main"
	.align 8
	.type	__PRETTY_FUNCTION__.4181, @object
	.size	__PRETTY_FUNCTION__.4181, 11
__PRETTY_FUNCTION__.4181:
	.string	"_Init_Heap"
	.align 16
	.type	__PRETTY_FUNCTION__.4213, @object
	.size	__PRETTY_FUNCTION__.4213, 18
__PRETTY_FUNCTION__.4213:
	.string	"removeMinFromHeap"
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
