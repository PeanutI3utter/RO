.data

.text

main:
	push {fp}
	mov fp, sp
	add sp, sp, #40
	mov r4, #0
	str r4, [fp]
	mov r4, #1
	str r4, [fp, #4]
	mov r4, #2
	str r4, [fp, #8]
	mov r4, #3
	str r4, [fp, #12]
	mov r4, #4
	str r4, [fp, #16]
	mov r4, #5
	str r4, [fp, #20]
	mov r4, #6
	str r4, [fp, #24]
	mov r4, #7
	str r4, [fp, #28]
	mov r4, #8
	str r4, [fp, #32]
	mov r4, #9
	str r4, [fp, #36]
	push {lr, sp}
	mov r0, fp
	mov r1, #10
	bl check_array_sorted
	mov r4, r0
	pop {lr, sp}
	sub sp, sp, #40
	pop{fp}
	mov r0, r4
	bx lr


check_array_sorted:
	mov r4, r0
	mov r5, r1
	mov r6, #0
	loop:
	cmp r6, r5
	bge endloop
	ldr r7, [r4, r6, lsl #2]
	add r6, #1
	ldr r8, [r4, r6, lsl #2]
	cmp r7, r8
	ble loop
	mov r0, #1
	bx lr
	endloop:
	mov r0, #0
	bx lr