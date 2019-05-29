        .h8300h
        .file "entry.s"

        .section .text
        .align 2
        .global _start

__syscr = 0xfffff2
__ramcr = 0xffff47
__abwcr = 0xffffec
__astcr = 0xffffed
__wcr   = 0xffffee
__wcer  = 0xffffef
__brcr  = 0xfffff3
__cscr  = 0xffff5f
__p1ddr = 0xffffc0
__p2ddr = 0xffffc1
__p5ddr = 0xffffc8
__p8ddr = 0xffffcd
__iprb  = 0xfffff9

#----------------------------------------------------------------------------
_start:	
#
/* Initialize Stack Pointer */

        mov.l	#_stub_stack, er7
        
/* HW Initialize */
	mov.b	#9, r0l       /* $BFbB"(BRAM$B;HMQ!"%9%j!<%WL?Na$G%9%j!<%W(B */
	mov.b	r0l, @__syscr
	mov.b	#0x08, r0l    /* $BFbB"(BRAM$B$K$h$k%(%_%e%l!<%7%g%s(B */
	mov.b	r0l, @__ramcr
	mov.b	#0xff, r0l    /* $B30It%(%j%"$OA4$F(B8$B%S%C%HI}(B */
	mov.b	r0l, @__abwcr
	mov.b	#0xff, r0l    /* $B30It%(%j%"$OA4$F(B3$B%9%F!<%H%"%/%;%9(B */
	mov.b	r0l, @__astcr
	mov.b	#4, r0l       /* $B%&%'%$%H6X;_(B */
	mov.b	r0l, @__wcr
	mov.b	#0xff, r0l    /* $BC<;R%&%'%$%H%b!<%I6X;_(B */
	mov.b	r0l, @__wcer
	mov.b	#0xfe, r0l    /* A23-A21$B$r3+J|!"%P%98"3+J|6X;_(B */
	mov.b	r0l, @__brcr
	mov.b	#0xff, r0l    /* P1X$B$O(BA7-A0$B$r=PNO(B */
	mov.b	r0l, @__p1ddr
	mov.b	#0xff, r0l    /* P2X$B$O(BA15-A8$B$r=PNO(B */
	mov.b	r0l, @__p2ddr
	mov.b	#0xf1, r0l    /* P50$B$O(BA16$B$r=PNO(B(P51-P53$B$O;HMQ2D(B) */
	mov.b	r0l, @__p5ddr
	mov.b	#0x0f, r0l    /* CS7-CS4$B$O=PNO6X;_(B, $B%G%U%)%k%H(B */
	mov.b	r0l, @__cscr
	mov.b	#0xe8, r0l    /* CS1$B$r=PNO(B */
	mov.b	r0l, @__p8ddr

	mov.b	#0x08, r0l    /* SCI0$B3d$j9~$_M%@hEY$r9b%l%Y%k$K@_Dj(B */
        mov.b	r0l, @__iprb

        jsr	_init_serial  /* SCI0$B$N=i4|2=(B(h8-sci.c) */

/* Jump to GDB_STUB */

        jmp		_start_gdbstub
