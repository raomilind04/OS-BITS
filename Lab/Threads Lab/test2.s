	.arch armv8-a
	.text
	.globl _num1
	.data
	.align	2
_num1:
	.word	123
	.globl _num2
	.align	2
_num2:
	.word	31
	.cstring
	.align	3
lC0:
	.ascii "%d\0"
	.text
	.align	2
	.globl _main
_main:
LFB33:
	stp	x29, x30, [sp, -368]!
LCFI0:
	mov	x29, sp
LCFI1:
	stp	x19, x20, [sp, 16]
	stp	x21, x22, [sp, 32]
	stp	x23, x24, [sp, 48]
	stp	x25, x26, [sp, 64]
	str	x27, [sp, 80]
	str	d8, [sp, 88]
	sub	sp, sp, #16
LCFI2:
	str	w0, [x29, 172]
	str	x1, [x29, 160]
	mov	x0, sp
	mov	x19, x0
	adrp	x0, _num1@PAGE
	add	x0, x0, _num1@PAGEOFF;momd
	ldr	w0, [x0]
	str	w0, [x29, 364]
	str	wzr, [x29, 360]
	b	L2
L3:
	ldr	w0, [x29, 360]
	add	w0, w0, 1
	str	w0, [x29, 360]
	ldr	w0, [x29, 364]
	mov	w1, 26215
	movk	w1, 0x6666, lsl 16
	smull	x1, w0, w1
	lsr	x1, x1, 32
	asr	w1, w1, 2
	asr	w0, w0, 31
	sub	w0, w1, w0
	str	w0, [x29, 364]
L2:
	ldr	w0, [x29, 364]
	cmp	w0, 0
	bgt	L3
	ldrsw	x0, [x29, 360]
	lsl	x0, x0, 2
	bl	_malloc
	str	x0, [x29, 320]
	adrp	x0, _num1@PAGE
	add	x0, x0, _num1@PAGEOFF;momd
	ldr	w0, [x0]
	str	w0, [x29, 364]
	str	wzr, [x29, 356]
	b	L4
L5:
	ldrsw	x0, [x29, 356]
	lsl	x0, x0, 2
	ldr	x1, [x29, 320]
	add	x3, x1, x0
	ldr	w2, [x29, 364]
	mov	w0, 26215
	movk	w0, 0x6666, lsl 16
	smull	x0, w2, w0
	lsr	x0, x0, 32
	asr	w1, w0, 2
	asr	w0, w2, 31
	sub	w1, w1, w0
	mov	w0, w1
	lsl	w0, w0, 2
	add	w0, w0, w1
	lsl	w0, w0, 1
	sub	w1, w2, w0
	str	w1, [x3]
	ldr	w0, [x29, 364]
	mov	w1, 26215
	movk	w1, 0x6666, lsl 16
	smull	x1, w0, w1
	lsr	x1, x1, 32
	asr	w1, w1, 2
	asr	w0, w0, 31
	sub	w0, w1, w0
	str	w0, [x29, 364]
	ldr	w0, [x29, 356]
	add	w0, w0, 1
	str	w0, [x29, 356]
L4:
	ldr	w1, [x29, 356]
	ldr	w0, [x29, 360]
	cmp w1, w2
	cmp	w1, w0
	blt	L5
	adrp	x0, _num2@PAGE
	add	x0, x0, _num2@PAGEOFF;momd
	ldr	w0, [x0]
	str	w0, [x29, 364]
	str	wzr, [x29, 352]
	b	L6
L7:
	ldr	w0, [x29, 352]
	add	w0, w0, 1
	str	w0, [x29, 352]
	ldr	w0, [x29, 364]
	mov	w1, 26215
	movk	w1, 0x6666, lsl 16
	smull	x1, w0, w1
	lsr	x1, x1, 32
	asr	w1, w1, 2
	asr	w0, w0, 31
	sub	w0, w1, w0
	str	w0, [x29, 364]
L6:
	ldr	w0, [x29, 364]
	cmp	w0, 0
	bgt	L7
	ldrsw	x0, [x29, 352]
	lsl	x0, x0, 2
	bl	_malloc
	str	x0, [x29, 312]
	adrp	x0, _num2@PAGE
	add	x0, x0, _num2@PAGEOFF;momd
	ldr	w0, [x0]
	str	w0, [x29, 364]
	str	wzr, [x29, 348]
	b	L8
L9:
	ldrsw	x0, [x29, 348]
	lsl	x0, x0, 2
	ldr	x1, [x29, 312]
	add	x3, x1, x0
	ldr	w2, [x29, 364]
	mov	w0, 26215
	movk	w0, 0x6666, lsl 16
	smull	x0, w2, w0
	lsr	x0, x0, 32
	asr	w1, w0, 2
	asr	w0, w2, 31
	sub	w1, w1, w0
	mov	w0, w1
	lsl	w0, w0, 2
	add	w0, w0, w1
	lsl	w0, w0, 1
	sub	w1, w2, w0
	str	w1, [x3]
	ldr	w0, [x29, 364]
	mov	w1, 26215
	movk	w1, 0x6666, lsl 16
	smull	x1, w0, w1
	lsr	x1, x1, 32
	asr	w1, w1, 2
	asr	w0, w0, 31
	sub	w0, w1, w0
	str	w0, [x29, 364]
	ldr	w0, [x29, 348]
	add	w0, w0, 1
	str	w0, [x29, 348]
L8:
	ldr	w1, [x29, 348]
	ldr	w0, [x29, 352]
	cmp	w1, w0
	blt	L9
	ldr	w1, [x29, 360]
	ldr	w0, [x29, 352]
	add	w0, w1, w0
	sub	w0, w0, #1
	str	w0, [x29, 308]
	ldr	w0, [x29, 308]
	sxtw	x1, w0
	sub	x1, x1, #1
	str	x1, [x29, 296]
	sxtw	x1, w0
	str	x1, [x29, 144]
	str	xzr, [x29, 152]
	ldp	x2, x3, [x29, 144]
	mov	x1, x2
	lsr	x1, x1, 58
	mov	x4, x3
	lsl	x27, x4, 6
	orr	x27, x1, x27
	mov	x1, x2
	lsl	x26, x1, 6
	sxtw	x1, w0
	str	x1, [x29, 128]
	str	xzr, [x29, 136]
	ldp	x2, x3, [x29, 128]
	mov	x1, x2
	lsr	x1, x1, 58
	mov	x4, x3
	lsl	x25, x4, 6
	orr	x25, x1, x25
	mov	x1, x2
	lsl	x24, x1, 6
	sxtw	x0, w0
	lsl	x0, x0, 3
	add	x0, x0, 15
	lsr	x0, x0, 4
	lsl	x0, x0, 4
	sub	sp, sp, x0
	add	x0, sp, 16
	add	x0, x0, 7
	lsr	x0, x0, 3
	lsl	x0, x0, 3
	str	x0, [x29, 288]
	add	x0, x29, 192
	bl	_pthread_attr_init
	ldr	w0, [x29, 308]
	sxtw	x1, w0
	sub	x1, x1, #1
	str	x1, [x29, 280]
	sxtw	x1, w0
	str	x1, [x29, 112]
	str	xzr, [x29, 120]
	ldp	x2, x3, [x29, 112]
	mov	x1, x2
	lsr	x1, x1, 59
	mov	x4, x3
	lsl	x23, x4, 5
	orr	x23, x1, x23
	mov	x1, x2
	lsl	x22, x1, 5
	sxtw	x1, w0
	str	x1, [x29, 96]
	str	xzr, [x29, 104]
	ldp	x2, x3, [x29, 96]
	mov	x1, x2
	lsr	x1, x1, 59
	mov	x4, x3
	lsl	x21, x4, 5
	orr	x21, x1, x21
	mov	x1, x2
	lsl	x20, x1, 5
	sxtw	x0, w0
	lsl	x0, x0, 2
	add	x0, x0, 15
	lsr	x0, x0, 4
	lsl	x0, x0, 4
	sub	sp, sp, x0
	add	x0, sp, 16
	add	x0, x0, 3
	lsr	x0, x0, 2
	lsl	x0, x0, 2
	str	x0, [x29, 272]
	str	wzr, [x29, 344]
	b	L10
L11:
	mov	x0, 40
	bl	_malloc
	str	x0, [x29, 256]
	ldr	x0, [x29, 256]
	ldr	x1, [x29, 320]
	str	x1, [x0, 8]
	ldr	x0, [x29, 256]
	ldr	x1, [x29, 312]
	str	x1, [x0, 24]
	ldr	x0, [x29, 256]
	ldr	w1, [x29, 360]
	str	w1, [x0, 16]
	ldr	x0, [x29, 256]
	ldr	w1, [x29, 352]
	str	w1, [x0, 32]
	ldr	x0, [x29, 256]
	ldr	w1, [x29, 344]
	str	w1, [x0]
	ldrsw	x0, [x29, 344]
	lsl	x0, x0, 3
	ldr	x1, [x29, 288]
	add	x4, x1, x0
	add	x1, x29, 192
	ldr	x3, [x29, 256]
	adrp	x0, _runner@PAGE
	add	x2, x0, _runner@PAGEOFF;momd
	mov	x0, x4
	bl	_pthread_create
	ldr	w0, [x29, 344]
	add	w0, w0, 1
	str	w0, [x29, 344]
L10:
	ldr	w1, [x29, 344]
	ldr	w0, [x29, 308]
	cmp	w1, w0
	blt	L11
	ldr	w0, [x29, 308]
	sub	w0, w0, #1
	str	w0, [x29, 340]
	b	L12
L13:
	ldr	x0, [x29, 288]
	ldrsw	x1, [x29, 340]
	ldr	x0, [x0, x1, lsl 3]
	add	x1, x29, 184
	bl	_pthread_join
	ldr	x0, [x29, 184]
	ldr	w2, [x0]
	ldr	x0, [x29, 272]
	ldrsw	x1, [x29, 340]
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [x29, 340]
	sub	w0, w0, #1
	str	w0, [x29, 340]
L12:
	ldr	w0, [x29, 340]
	cmp	w0, 0
	bge	L13
	str	wzr, [x29, 336]
	b	L14
L15:
	ldr	x0, [x29, 272]
	ldrsw	x1, [x29, 336]
	ldr	w0, [x0, x1, lsl 2]
	str	w0, [x29, 268]
	ldr	x0, [x29, 272]
	ldrsw	x1, [x29, 336]
	ldr	w2, [x0, x1, lsl 2]
	mov	w0, 26215
	movk	w0, 0x6666, lsl 16
	smull	x0, w2, w0
	lsr	x0, x0, 32
	asr	w1, w0, 2
	asr	w0, w2, 31
	sub	w1, w1, w0
	mov	w0, w1
	lsl	w0, w0, 2
	add	w0, w0, w1
	lsl	w0, w0, 1
	sub	w1, w2, w0
	ldr	x0, [x29, 272]
	ldrsw	x2, [x29, 336]
	str	w1, [x0, x2, lsl 2]
	ldr	w0, [x29, 336]
	add	w1, w0, 1
	ldr	x0, [x29, 272]
	sxtw	x1, w1
	ldr	w1, [x0, x1, lsl 2]
	ldr	w0, [x29, 268]
	mov	w2, 26215
	movk	w2, 0x6666, lsl 16
	smull	x2, w0, w2
	lsr	x2, x2, 32
	asr	w2, w2, 2
	asr	w0, w0, 31
	sub	w0, w2, w0
	ldr	w2, [x29, 336]
	add	w3, w2, 1
	add	w2, w1, w0
	ldr	x0, [x29, 272]
	sxtw	x1, w3
	str	w2, [x0, x1, lsl 2]
	ldr	w0, [x29, 336]
	add	w0, w0, 1
	str	w0, [x29, 336]
L14:
	
	b	L16
L17:
	ldr	x0, [x29, 272]
	ldrsw	x1, [x29, 328]
	ldr	w0, [x0, x1, lsl 2]
	scvtf	d8, w0
	ldr	w0, [x29, 328]
	scvtf	d0, w0
	fmov	d1, d0
	fmov	d0, 1.0e+1
	bl	_pow
	fmul	d1, d8, d0
	ldr	w0, [x29, 332]
	scvtf	d0, w0
	fadd	d0, d1, d0
	fcvtzs	w0, d0
	str	w0, [x29, 332]
	ldr	w0, [x29, 328]
	sub	w0, w0, #1
	str	w0, [x29, 328]
L16:
	ldr	w0, [x29, 328]
	cmp	w0, 0
	bge	L17
	ldr	w0, [x29, 332]
	str	w0, [sp]
	adrp	x0, lC0@PAGE
	add	x0, x0, lC0@PAGEOFF;momd
	bl	_printf
	mov	w0, 0
	mov	sp, x19
	mov	sp, x29
	ldr	d8, [sp, 88]
	ldp	x19, x20, [sp, 16]
	ldp	x21, x22, [sp, 32]
	ldp	x23, x24, [sp, 48]
	ldp	x25, x26, [sp, 64]
	ldr	x27, [sp, 80]
	ldp	x29, x30, [sp], 368
LCFI3:
	ret
LFE33:
	.align	2
	.globl _runner
_runner:
LFB34:
	stp	x29, x30, [sp, -96]!
LCFI4:
	mov	x29, sp
	str	x0, [sp, 24]
	ldr	x0, [sp, 24]
	str	x0, [sp, 72]
	ldr	x0, [sp, 72]
	ldr	x0, [x0, 8]
	str	x0, [sp, 64]
	ldr	x0, [sp, 72]
	ldr	x0, [x0, 24]
	str	x0, [sp, 56]
	ldr	x0, [sp, 72]
	ldr	w0, [x0]
	str	w0, [sp, 52]
	mov	x0, 8
	bl	_malloc
	str	x0, [sp, 40]
	str	wzr, [sp, 92]
	ldr	w0, [sp, 52]
	str	w0, [sp, 88]
	str	wzr, [sp, 84]
	b	L20
L22:
	ldr	x0, [sp, 72]
	ldr	w0, [x0, 32]
	ldr	w1, [sp, 84]
	cmp	w1, w0
	bge	L21
	ldr	x0, [sp, 72]
	ldr	w0, [x0, 16]
	ldr	w1, [sp, 88]
	cmp	w1, w0
	bge	L21
	ldrsw	x0, [sp, 88]
	lsl	x0, x0, 2
	ldr	x1, [sp, 64]
	add	x0, x1, x0
	ldr	w1, [x0]
	ldrsw	x0, [sp, 84]
	lsl	x0, x0, 2
	ldr	x2, [sp, 56]
	add	x0, x2, x0
	ldr	w0, [x0]
	mul	w0, w1, w0
	ldr	w1, [sp, 92]
	add	w0, w1, w0
	str	w0, [sp, 92]
L21:
	ldr	w0, [sp, 88]
	sub	w0, w0, #1
	str	w0, [sp, 88]
	ldr	w0, [sp, 84]
	add	w0, w0, 1
	str	w0, [sp, 84]
L20:
	ldr	w1, [sp, 84]
	ldr	w0, [sp, 52]
	cmp	w1, w0
	ble	L22
	ldr	x0, [sp, 40]
	ldr	w1, [sp, 92]
	str	w1, [x0]
	ldr	x0, [sp, 40]
	bl	_pthread_exit
LFE34:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB33-.
	.set L$set$2,LFE33-LFB33
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB33
	.long L$set$3
	.byte	0xe
	.uleb128 0x170
	.byte	0x9d
	.uleb128 0x2e
	.byte	0x9e
	.uleb128 0x2d
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.uleb128 0x1d
	.byte	0x4
	.set L$set$5,LCFI2-LCFI1
	.long L$set$5
	.byte	0x93
	.uleb128 0x2c
	.byte	0x94
	.uleb128 0x2b
	.byte	0x95
	.uleb128 0x2a
	.byte	0x96
	.uleb128 0x29
	.byte	0x97
	.uleb128 0x28
	.byte	0x98
	.uleb128 0x27
	.byte	0x99
	.uleb128 0x26
	.byte	0x9a
	.uleb128 0x25
	.byte	0x9b
	.uleb128 0x24
	.byte	0x5
	.uleb128 0x48
	.uleb128 0x23
	.byte	0x4
	.set L$set$6,LCFI3-LCFI2
	.long L$set$6
	.byte	0xde
	.byte	0xdd
	.byte	0xdb
	.byte	0xd9
	.byte	0xda
	.byte	0xd7
	.byte	0xd8
	.byte	0xd5
	.byte	0xd6
	.byte	0xd3
	.byte	0xd4
	.byte	0x6
	.uleb128 0x48
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LEFDE1:
LSFDE3:
	.set L$set$7,LEFDE3-LASFDE3
	.long L$set$7
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB34-.
	.set L$set$8,LFE34-LFB34
	.quad L$set$8
	.uleb128 0
	.byte	0x4
	.set L$set$9,LCFI4-LFB34
	.long L$set$9
	.byte	0xe
	.uleb128 0x60
	.byte	0x9d
	.uleb128 0xc
	.byte	0x9e
	.uleb128 0xb
	.align	3
LEFDE3:
	.ident	"GCC: (Homebrew GCC 12.2.0) 12.2.0"
	.subsections_via_symbols
