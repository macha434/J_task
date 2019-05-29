        .h8300h
        .file "head.s"
        .section .vectors

        .balign 4
        .data.l         _start          ;00 Power On Reset
        .data.l         _INT_Reserved   ;01 Reserved
        .data.l         _INT_Reserved   ;02 Reserved
        .data.l         _INT_Reserved   ;03 Reserved
        .data.l         _INT_Reserved   ;04 Reserved
        .data.l         _INT_Reserved   ;05 Reserved
        .data.l         _INT_Reserved   ;06 Reserved
        .data.l         _INT_NMI        ;07 NMI
        .data.l         _INT_TRAP0      ;08 User Breakpoint Trap
        .data.l         _INT_TRAP1      ;09 TRAP1
        .data.l         _INT_TRAP2      ;10 TRAP2
        .data.l         _INT_TRAP3      ;11 TRAP3
        .data.l         _INT_IRQ0       ;12 IRQ0
        .data.l         _INT_IRQ1       ;13 IRQ1
        .data.l         _INT_IRQ2       ;14 IRQ2
        .data.l         _INT_IRQ3       ;15 IRQ3
        .data.l         _INT_IRQ4       ;16 IRQ4
        .data.l         _INT_IRQ5       ;17 IRQ5
        .data.l         _INT_Reserved   ;18 Reserved
        .data.l         _INT_Reserved   ;19 Reserved
        .data.l         _INT_WOVI       ;20 WOVI (WatchFog)
        .data.l         _INT_CMI        ;21 CMI (DRAM)
        .data.l         _INT_Reserved   ;22 Reserved
        .data.l         _INT_Reserved   ;23 Reserved <= ADI (A/D)
        .data.l         _INT_IMIA0      ;24 IMIA0 (16bit Timer ch0)
        .data.l         _INT_IMIB0      ;25 IMIB0 (16bit Timer ch0)
        .data.l         _INT_OVI0       ;26 OVI0 (16bit Timer ch0)
        .data.l         _INT_Reserved   ;27 Reserved
        .data.l         _INT_IMIA1      ;28 IMIA1 (16bit Timer 1)
        .data.l         _INT_IMIB1      ;29 IMIB1 (16bit Timer 1)
        .data.l         _INT_OVI1       ;30 OVI1 (16bit Timer 1)
        .data.l         _INT_Reserved   ;31 Reserved
        .data.l         _INT_IMIA2      ;32 IMIA2 (16bit Timer 2)
        .data.l         _INT_IMIB2      ;33 IMIB2 (16bit Timer 2)
        .data.l         _INT_OVI2       ;34 OVI2 (16bit Timer 2)
        .data.l         _INT_Reserved   ;35 Reserved
        .data.l         _INT_IMIA3      ;36 IMIA3 <= CMIA0 (8bit Timer0)
        .data.l         _INT_IMIB3      ;37 IMIB3 <= CMIB0 (8bit Timer 0)
        .data.l         _INT_OVI3       ;38 OVI3 <= CMIA1/B1 (8bit Timer1)
        .data.l         _INT_Reserved   ;39 Reserved <= TOVI0/1 (8bit Timer0/1)
        .data.l         _INT_IMIA4      ;40 IMIA4 <= CMIA2 (8bit Timer 2)
        .data.l         _INT_IMIB4      ;41 IMIB4 <= CMIB2 (8bit Timer 2)
        .data.l         _INT_OVI4       ;42 OVI4 <= CMIA3/B3 (8bit Timer 3)
        .data.l         _INT_Reserved   ;43 Reserved <= TOVI2/3 (8bit Timer2/3)
        .data.l         _INT_DEND0A     ;44 DEND0A (DMAC)
        .data.l         _INT_DEND0B     ;45 DEND0B (DMAC)
        .data.l         _INT_DEND1A     ;46 DEND1A (DMAC)
        .data.l         _INT_DEND1B     ;47 DEND1B (DMAC)
        .data.l         _INT_Reserved   ;48 Reserved
        .data.l         _INT_Reserved   ;49 Reserved
        .data.l         _INT_Reserved   ;50 Reserved
        .data.l         _INT_Reserved   ;51 Reserved
        .data.l         _INT_ERI0       ;52 ERI0 (SCI0)
        .data.l         _INT_RXI0       ;53 RXI0 (SCI0)
        .data.l         _INT_TXI0       ;54 TXI0 (SCI0)
        .data.l         _INT_TEI0       ;55 TEI0 (SCI0)
        .data.l         _INT_ERI1       ;56 ERI1 (SCI1)
        .data.l         _INT_RXI1       ;57 RXI1 (SCI1)
        .data.l         _INT_TXI1       ;58 TXI1 (SCI1)
        .data.l         _INT_TEI1       ;59 TEI1 (SCI1)
        .data.l         _INT_ADI        ;60 ADI (A/D) <= ERI2 (SCI2)
        .data.l         _INT_Reserved   ;61 Reserved <= RXI2 (SCI2)
        .data.l         _INT_Reserved   ;62 Reserved <= TXI2 (SCI2)
        .data.l         _INT_Reserved   ;63 Reserved <= TEI2 (SCI2)
