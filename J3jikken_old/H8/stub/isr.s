VECT_TBL	= 0xffe100   /* ターゲットのベクタ領域の先頭アドレス */
RDR0		= 0xffffb5
SSR0		= 0xffffb4
IntID_start = 0
IntID_Reserved = 1
IntID_NMI = 7
IntID_TRAP0 = 8
IntID_TRAP1 = 9
IntID_TRAP2 = 10
IntID_TRAP3 = 11
IntID_IRQ0 = 12
IntID_IRQ1 = 13
IntID_IRQ2 = 14
IntID_IRQ3 = 15
IntID_IRQ4 = 16
IntID_IRQ5 = 17
IntID_WOVI = 20
IntID_CMI = 21
IntID_IMIA0 = 24
IntID_IMIB0 = 25
IntID_OVI0 = 26
IntID_IMIA1 = 28
IntID_IMIB1 = 29
IntID_OVI1 = 30
IntID_IMIA2 = 32
IntID_IMIB2 = 33
IntID_OVI2 = 34
IntID_IMIA3 = 36
IntID_IMIB3 = 37
IntID_OVI3 = 38
IntID_IMIA4 = 40
IntID_IMIB4 = 41
IntID_OVI4 = 42
IntID_DEND0A = 44
IntID_DEND0B = 45
IntID_DEND1A = 46
IntID_DEND1B = 47
IntID_ERI0 = 52
IntID_RXI0 = 53
IntID_TXI0 = 54
IntID_TEI0 = 55
IntID_ERI1 = 56
IntID_RXI1 = 57
IntID_TXI1 = 58
IntID_TEI1 = 59
IntID_ADI = 60

        .h8300h
        .file "isr.s"
        .section .text
        .align 2
        .global _INT_Reserved
        .global _INT_NMI
        .global _INT_TRAP0
        .global _INT_TRAP1
        .global _INT_TRAP2
        .global _INT_TRAP3
        .global _INT_IRQ0
        .global _INT_IRQ1
        .global _INT_IRQ2
        .global _INT_IRQ3
        .global _INT_IRQ4
        .global _INT_IRQ5
        .global _INT_WOVI
        .global _INT_CMI
        .global _INT_IMIA0
        .global _INT_IMIB0
        .global _INT_OVI0
        .global _INT_IMIA1
        .global _INT_IMIB1
        .global _INT_OVI1
        .global _INT_IMIA2
        .global _INT_IMIB2
        .global _INT_OVI2
        .global _INT_IMIA3
        .global _INT_IMIB3
        .global _INT_OVI3
        .global _INT_IMIA4
        .global _INT_IMIB4
        .global _INT_OVI4
        .global _INT_DEND0A
        .global _INT_DEND0B
        .global _INT_DEND1A
        .global _INT_DEND1B
        .global _INT_ERI0
        .global _INT_RXI0
        .global _INT_TXI0
        .global _INT_TEI0
        .global _INT_ERI1
        .global _INT_RXI1
        .global _INT_TXI1
        .global _INT_TEI1
        .global _INT_ADI
	
saveRegisters:
        mov.l   er0, @_registers		; save R0
#        mov.l   #SYMBOL_NAME(registers), er0
        mov.l   #_registers, er0
        mov.l   er1, @(0x04, er0)		; save R1
        mov.l   er2, @(0x08, er0)		; save R2
        mov.l   er3, @(0x0c, er0)		; save R3
        mov.l   er4, @(0x10, er0)		; save R4
        mov.l   er5, @(0x14, er0)		; save R5
        mov.l   er6, @(0x18, er0)		; save R6

        mov.l   #0x0, er1				; zero the CCR location
        mov.l   er1, @(0x20, er0)
        mov.w   @er7, r1				; get off the stack(CCR)
        mov.b   r1h, @(0x23, er0)		; save CCR

        mov.l   @er7, er1				; get off the stack(CCR & PC)
        and.l   #0xFFFFFF, er1			; 24-bit addr
        mov.l   er1, @(0x24, er0)		; save PC
        
        adds.l	#4, er7
        mov.l   er7, @(0x1c, er0)		; save R7

        mov.l   @_stub_sp, er7		; load __stub_stack
        mov.l   @_exception, er0
        jsr     _handle_exception
        mov.l   er7, @_stub_sp		; save __stub_stack

;----------------------------------------------------------------------------
restoreRegisters:
        mov.l   #_registers, er0
        mov.l   @(0x1c, er0), er7				; restore R7
		mov.l	@(0x24, er0), er1				; PC
		sub.w	r2, r2
        mov.b   @(0x23, er0), r2h				; CCR
        or.w	r2, e1
		push.l	er1
        mov.l   @(0x18, er0), er6				; restore R6
        mov.l   @(0x14, er0), er5				; restore R5
        mov.l   @(0x10, er0), er4				; restore R4
        mov.l   @(0x0c, er0), er3				; restore R3
        mov.l   @(0x08, er0), er2				; restore R2
        mov.l   @(0x04, er0), er1				; restore R1
        mov.b	#0x00, r0l
        mov.b	r0l, @_in_nmi		; in_nmi = 0        
        mov.l   @_registers, er0	; restore R0
        rte										; restore CCR & PC

;----------------------------------------------------------------------------
_INT_NMI:					/* NMI */
        push.l	er0
        mov.l	#IntID_NMI, er0
        mov.l	er0, @_exception
        mov.b	@er0, r0l
        beq		NEXT
        pop.l	er0
        rte
NEXT:   mov.b	#0x01, r0l
        mov.b	r0l, @_in_nmi
        pop.l	er0
        bra		saveRegisters:16

;----------------------------------------------------------------------------
_INT_TRAP0:				/* BREAK */
        push.l	er0
        mov.l	#IntID_TRAP0, er0
        mov.l	er0, @_exception
        pop.l	er0
        bra		saveRegisters:16

;----------------------------------------------------------------------------
_INT_TRAP1:				/* BIOS CALL */
        push.l	er0
        mov.l	#IntID_TRAP1, er0
        mov.l	er0, @_exception
        pop.l	er0
        bra		saveRegisters:16

;----------------------------------------------------------------------------
_INT_TRAP2:
        push.l	er0
        mov.l	#IntID_TRAP2, er0
        mov.l	er0, @_exception
        pop.l	er0
        bra		saveRegisters:16

;----------------------------------------------------------------------------
_INT_TRAP3:				/* BRAEK */
        push.l	er0
        mov.l	#IntID_TRAP3, er0
        mov.l	er0, @_exception
        pop.l	er0
        bra		saveRegisters:16

;----------------------------------------------------------------------------
_INT_IRQ0:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IRQ0, er0
jmp_vect:
        mov.l	er0, @_exception
        push.l	er1
        shll.l	er0
        shll.l	er0
        add.l	#VECT_TBL, er0
        mov.l	@er0, er1
        mov.w	@(0x0a, er7), r0
        mov.b	#0x00, r0l
        or.w	r0, e1
        mov.l	er1, @(0x08, er7)
        pop.l	er1
        pop.l	er0
        rte

;----------------------------------------------------------------------------
_INT_IRQ1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IRQ1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IRQ2:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IRQ2, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IRQ3:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IRQ3, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IRQ4:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IRQ4, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IRQ5:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IRQ5, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_WOVI:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_WOVI, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_CMI:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_CMI, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIA0:		/* 16 BIT TIMER 0 */
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIA0, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIB0:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIB0, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_OVI0:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_OVI0, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIA1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIA1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIB1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIB1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_OVI1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_OVI1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIA2:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIA2, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIB2:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIB2, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_OVI2:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_OVI2, er0
        bra		jmp_vect:16
        
;----------------------------------------------------------------------------
_INT_IMIA3:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIA3, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIB3:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIB3, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_OVI3:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_OVI3, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIA4:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIA4, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_IMIB4:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_IMIB4, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_OVI4:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_OVI4, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_DEND0A:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_DEND0A, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_DEND0B:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_DEND0B, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_DEND1A:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_DEND1A, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_DEND1B:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_DEND1B, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_ERI0:
        push.l	er0
        mov.l	#IntID_ERI0, er0
        bra		handle_break

;----------------------------------------------------------------------------
_INT_RXI0:			/* SCI0 Rx */
        push.l	er0
        mov.l	#IntID_RXI0, er0
handle_break:
        mov.l	er0, @_exception
        mov.b	@RDR0, r0l
        mov.b	@SSR0, r0h
        and.b	#0x80, r0h				; RDRF & Error clear
        mov.b	r0h, @SSR0
        cmp.b	#0x03, r0l
        beq		sci_break
        pop.l	er0
        rte
sci_break:        
        pop.l	er0
        bra		saveRegisters:16

;----------------------------------------------------------------------------
_INT_TXI0:
        push.l	er0
        mov.l	#IntID_TXI0, er0
        mov.l	er0, @_exception
        pop.l	er0
        rte

;----------------------------------------------------------------------------
_INT_TEI0:
        push.l	er0
        mov.l	#IntID_TEI0, er0
        mov.l	er0, @_exception
        pop.l	er0
        rte

;----------------------------------------------------------------------------
_INT_ERI1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_ERI1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_RXI1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_RXI1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_TXI1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_TXI1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_TEI1:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_TEI1, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_ADI:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_ADI, er0
        bra		jmp_vect:16

;----------------------------------------------------------------------------
_INT_Reserved:
        stc.w	ccr, @-er7
        subs	#2, er7
        push.l	er0
        mov.l	#IntID_TEI1, er0
        bra		jmp_vect:16
