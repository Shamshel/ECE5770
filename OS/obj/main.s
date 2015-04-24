
main.o:     file format elf32-littlearm


Disassembly of section .text.main:

00000000 <main>:
   0:	e92d4800 	push	{fp, lr}
   4:	e28db004 	add	fp, sp, #4
   8:	e24dd008 	sub	sp, sp, #8
   c:	e50b0008 	str	r0, [fp, #-8]
  10:	e50b100c 	str	r1, [fp, #-12]
  14:	ebfffffe 	bl	0 <function_Kernel_run>
  18:	e3a03001 	mov	r3, #1
  1c:	e1a00003 	mov	r0, r3
  20:	e24bd004 	sub	sp, fp, #4
  24:	e8bd8800 	pop	{fp, pc}

Disassembly of section .comment:

00000000 <.comment>:
   0:	43434700 	movtmi	r4, #14080	; 0x3700
   4:	4628203a 			; <UNDEFINED> instruction: 0x4628203a
   8:	726f6465 	rsbvc	r6, pc, #1694498816	; 0x65000000
   c:	30322061 	eorscc	r2, r2, r1, rrx
  10:	312e3331 	teqcc	lr, r1, lsr r3
  14:	34322e31 	ldrtcc	r2, [r2], #-3633	; 0xfffff1cf
  18:	662e322d 	strtvs	r3, [lr], -sp, lsr #4
  1c:	29303263 	ldmdbcs	r0!, {r0, r1, r5, r6, r9, ip, sp}
  20:	382e3420 	stmdacc	lr!, {r5, sl, ip, sp}
  24:	Address 0x0000000000000024 is out of bounds.


Disassembly of section .ARM.attributes:

00000000 <.ARM.attributes>:
   0:	00002941 	andeq	r2, r0, r1, asr #18
   4:	61656100 	cmnvs	r5, r0, lsl #2
   8:	01006962 	tsteq	r0, r2, ror #18
   c:	0000001f 	andeq	r0, r0, pc, lsl r0
  10:	4d524105 	ldfmie	f4, [r2, #-20]	; 0xffffffec
  14:	01060037 	tsteq	r6, r7, lsr r0
  18:	04120108 	ldreq	r0, [r2], #-264	; 0xfffffef8
  1c:	01150114 	tsteq	r5, r4, lsl r1
  20:	01180317 	tsteq	r8, r7, lsl r3
  24:	011a0119 	tsteq	sl, r9, lsl r1
  28:	Address 0x0000000000000028 is out of bounds.

