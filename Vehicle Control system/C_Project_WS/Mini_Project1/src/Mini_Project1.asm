	.file	"Mini_Project1.c"
	.text
	.def	scanf;	.scl	3;	.type	32;	.endef
	.seh_proc	scanf
scanf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$0, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfscanf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	printf;	.scl	3;	.type	32;	.endef
	.seh_proc	printf
printf:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	leaq	48(%rsp), %rbp
	.seh_setframe	%rbp, 48
	.seh_endprologue
	movq	%rcx, 32(%rbp)
	movq	%rdx, 40(%rbp)
	movq	%r8, 48(%rbp)
	movq	%r9, 56(%rbp)
	leaq	40(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-16(%rbp), %rbx
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movq	%rbx, %r8
	movq	32(%rbp), %rdx
	movq	%rax, %rcx
	call	__mingw_vfprintf
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	Vehicle_SetupRoomTemp
	.def	Vehicle_SetupRoomTemp;	.scl	2;	.type	32;	.endef
	.seh_proc	Vehicle_SetupRoomTemp
Vehicle_SetupRoomTemp:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$9, %eax
	jg	.L6
	movl	$1, -4(%rbp)
	movq	16(%rbp), %rax
	movl	$20, (%rax)
	jmp	.L7
.L6:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$30, %eax
	jle	.L8
	movl	$1, -4(%rbp)
	movq	16(%rbp), %rax
	movl	$20, (%rax)
	jmp	.L7
.L8:
	movl	$0, -4(%rbp)
.L7:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Vehicle_CalculateSpeed
	.def	Vehicle_CalculateSpeed;	.scl	2;	.type	32;	.endef
	.seh_proc	Vehicle_CalculateSpeed
Vehicle_CalculateSpeed:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, %eax
	movb	%al, 16(%rbp)
	cmpb	$71, 16(%rbp)
	je	.L11
	cmpb	$103, 16(%rbp)
	jne	.L12
.L11:
	movl	$100, -4(%rbp)
.L12:
	cmpb	$79, 16(%rbp)
	je	.L13
	cmpb	$111, 16(%rbp)
	jne	.L14
.L13:
	movl	$30, -4(%rbp)
.L14:
	cmpb	$82, 16(%rbp)
	je	.L15
	cmpb	$114, 16(%rbp)
	jne	.L16
.L15:
	movl	$0, -4(%rbp)
.L16:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	Vehicle_SetupEngineTempController
	.def	Vehicle_SetupEngineTempController;	.scl	2;	.type	32;	.endef
	.seh_proc	Vehicle_SetupEngineTempController
Vehicle_SetupEngineTempController:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, -4(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$99, %eax
	jg	.L19
	movl	$1, -4(%rbp)
	movq	16(%rbp), %rax
	movl	$125, (%rax)
	jmp	.L20
.L19:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cmpl	$150, %eax
	jle	.L21
	movl	$1, -4(%rbp)
	movq	16(%rbp), %rax
	movl	$125, (%rax)
	jmp	.L20
.L21:
	movl	$0, -4(%rbp)
.L20:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "a. Turn on the vehicle engine\12\0"
	.align 8
.LC1:
	.ascii "b. Turn off the vehicle engine\12\0"
.LC2:
	.ascii "c. Quit the system\12\12\0"
.LC3:
	.ascii " %c\0"
.LC4:
	.ascii "Quit The System \12\12\0"
.LC5:
	.ascii "Turn oFF Vehicle Engine\12\12\0"
.LC6:
	.ascii "a. Turn off the engine\12\0"
	.align 8
.LC7:
	.ascii "b. Set the traffic light color\12\0"
	.align 8
.LC8:
	.ascii "c. Set the room temperature(Temperature Sensor)\12\0"
	.align 8
.LC9:
	.ascii "d. Set the engine temperature\12\12\0"
.LC10:
	.ascii "Enter the required color:\12\0"
	.align 8
.LC11:
	.ascii "Enter the required room temp:\12\0"
.LC12:
	.ascii "%d\0"
	.align 8
.LC13:
	.ascii "Enter the required engine temperature:\12\0"
.LC14:
	.ascii "Engine is OFF\12\0"
.LC15:
	.ascii "Engine is ON\12\0"
.LC16:
	.ascii "AC is OFF\12\0"
.LC17:
	.ascii "AC is ON\12\0"
.LC18:
	.ascii "Vehicle Speed: %d Km/Hr\12\0"
.LC19:
	.ascii "Room Temperature: %d C\12\0"
	.align 8
.LC20:
	.ascii "Engine Temp Controller is OFF\12\0"
.LC21:
	.ascii "Engine Temp Controller is ON\12\0"
.LC22:
	.ascii "Engine Temperature: %d C\12\12\0"
	.align 8
.LC23:
	.ascii "Error please enter valid input (a,A) or (b,B) or (c,C) \12\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	movl	$1, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movl	$0, %r9d
	movl	$4, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	setvbuf
	movl	$2, %ecx
	movq	__imp___acrt_iob_func(%rip), %rax
	call	*%rax
	movl	$0, %r9d
	movl	$4, %r8d
	movl	$0, %edx
	movq	%rax, %rcx
	call	setvbuf
	movl	$0, -16(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$35, -24(%rbp)
	movl	$0, -12(%rbp)
	movl	$90, -28(%rbp)
.L51:
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-17(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movzbl	-17(%rbp), %eax
	cmpb	$99, %al
	je	.L24
	movzbl	-17(%rbp), %eax
	cmpb	$67, %al
	jne	.L25
.L24:
	leaq	.LC4(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L53
.L25:
	movzbl	-17(%rbp), %eax
	cmpb	$98, %al
	je	.L27
	movzbl	-17(%rbp), %eax
	cmpb	$66, %al
	jne	.L28
.L27:
	movl	$0, -16(%rbp)
	leaq	.LC5(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L29
.L28:
	movzbl	-17(%rbp), %eax
	cmpb	$97, %al
	je	.L50
	movzbl	-17(%rbp), %eax
	cmpb	$65, %al
	jne	.L31
.L50:
	movl	$1, -16(%rbp)
	leaq	.LC6(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC7(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC8(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	.LC9(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-18(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movzbl	-18(%rbp), %eax
	cmpb	$97, %al
	je	.L32
	movzbl	-18(%rbp), %eax
	cmpb	$65, %al
	jne	.L33
.L32:
	movl	$0, -16(%rbp)
	nop
	jmp	.L29
.L33:
	movzbl	-18(%rbp), %eax
	cmpb	$98, %al
	je	.L35
	movzbl	-18(%rbp), %eax
	cmpb	$66, %al
	jne	.L36
.L35:
	leaq	.LC10(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-19(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	movzbl	-19(%rbp), %eax
	movsbl	%al, %eax
	movl	%eax, %ecx
	call	Vehicle_CalculateSpeed
	movl	%eax, -8(%rbp)
.L36:
	movzbl	-18(%rbp), %eax
	cmpb	$99, %al
	je	.L37
	movzbl	-18(%rbp), %eax
	cmpb	$67, %al
	jne	.L38
.L37:
	leaq	.LC11(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-24(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	Vehicle_SetupRoomTemp
	movl	%eax, -4(%rbp)
.L38:
	movzbl	-18(%rbp), %eax
	cmpb	$100, %al
	je	.L39
	movzbl	-18(%rbp), %eax
	cmpb	$68, %al
	jne	.L40
.L39:
	leaq	.LC13(%rip), %rax
	movq	%rax, %rcx
	call	printf
	leaq	-28(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rax
	movq	%rax, %rcx
	call	scanf
	leaq	-28(%rbp), %rax
	movq	%rax, %rcx
	call	Vehicle_SetupEngineTempController
	movl	%eax, -12(%rbp)
.L40:
	cmpl	$30, -8(%rbp)
	jne	.L41
	cmpl	$0, -4(%rbp)
	jne	.L42
	movl	$1, -4(%rbp)
.L42:
	movl	-24(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	3(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$2, %eax
	addl	$1, %eax
	movl	%eax, -24(%rbp)
	cmpl	$0, -12(%rbp)
	jne	.L43
	movl	$1, -12(%rbp)
.L43:
	movl	-28(%rbp), %edx
	movl	%edx, %eax
	sall	$2, %eax
	addl	%edx, %eax
	leal	3(%rax), %edx
	testl	%eax, %eax
	cmovs	%edx, %eax
	sarl	$2, %eax
	addl	$1, %eax
	movl	%eax, -28(%rbp)
.L41:
	cmpl	$0, -16(%rbp)
	jne	.L44
	leaq	.LC14(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L45
.L44:
	leaq	.LC15(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L45:
	cmpl	$0, -4(%rbp)
	jne	.L46
	leaq	.LC16(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L47
.L46:
	leaq	.LC17(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L47:
	movl	-8(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC18(%rip), %rax
	movq	%rax, %rcx
	call	printf
	movl	-24(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC19(%rip), %rax
	movq	%rax, %rcx
	call	printf
	cmpl	$0, -12(%rbp)
	jne	.L48
	leaq	.LC20(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L49
.L48:
	leaq	.LC21(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L49:
	movl	-28(%rbp), %eax
	movl	%eax, %edx
	leaq	.LC22(%rip), %rax
	movq	%rax, %rcx
	call	printf
	jmp	.L50
.L31:
	leaq	.LC23(%rip), %rax
	movq	%rax, %rcx
	call	printf
.L29:
	jmp	.L51
.L53:
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (GNU) 11.2.0"
	.def	__mingw_vfscanf;	.scl	2;	.type	32;	.endef
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
	.def	setvbuf;	.scl	2;	.type	32;	.endef
