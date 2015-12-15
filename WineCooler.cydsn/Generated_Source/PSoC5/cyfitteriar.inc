#ifndef INCLUDED_CYFITTERIAR_INC
#define INCLUDED_CYFITTERIAR_INC
    INCLUDE cydeviceiar.inc
    INCLUDE cydeviceiar_trm.inc

/* ADC_DEC */
ADC_DEC__COHER EQU CYREG_DEC_COHER
ADC_DEC__CR EQU CYREG_DEC_CR
ADC_DEC__DR1 EQU CYREG_DEC_DR1
ADC_DEC__DR2 EQU CYREG_DEC_DR2
ADC_DEC__DR2H EQU CYREG_DEC_DR2H
ADC_DEC__GCOR EQU CYREG_DEC_GCOR
ADC_DEC__GCORH EQU CYREG_DEC_GCORH
ADC_DEC__GVAL EQU CYREG_DEC_GVAL
ADC_DEC__OCOR EQU CYREG_DEC_OCOR
ADC_DEC__OCORH EQU CYREG_DEC_OCORH
ADC_DEC__OCORM EQU CYREG_DEC_OCORM
ADC_DEC__OUTSAMP EQU CYREG_DEC_OUTSAMP
ADC_DEC__OUTSAMPH EQU CYREG_DEC_OUTSAMPH
ADC_DEC__OUTSAMPM EQU CYREG_DEC_OUTSAMPM
ADC_DEC__OUTSAMPS EQU CYREG_DEC_OUTSAMPS
ADC_DEC__PM_ACT_CFG EQU CYREG_PM_ACT_CFG10
ADC_DEC__PM_ACT_MSK EQU 0x01
ADC_DEC__PM_STBY_CFG EQU CYREG_PM_STBY_CFG10
ADC_DEC__PM_STBY_MSK EQU 0x01
ADC_DEC__SHIFT1 EQU CYREG_DEC_SHIFT1
ADC_DEC__SHIFT2 EQU CYREG_DEC_SHIFT2
ADC_DEC__SR EQU CYREG_DEC_SR
ADC_DEC__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DEC_M1
ADC_DEC__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DEC_M2
ADC_DEC__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DEC_M3
ADC_DEC__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DEC_M4
ADC_DEC__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DEC_M5
ADC_DEC__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DEC_M6
ADC_DEC__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DEC_M7
ADC_DEC__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DEC_M8

/* ADC_DSM */
ADC_DSM__BUF0 EQU CYREG_DSM0_BUF0
ADC_DSM__BUF1 EQU CYREG_DSM0_BUF1
ADC_DSM__BUF2 EQU CYREG_DSM0_BUF2
ADC_DSM__BUF3 EQU CYREG_DSM0_BUF3
ADC_DSM__CLK EQU CYREG_DSM0_CLK
ADC_DSM__CR0 EQU CYREG_DSM0_CR0
ADC_DSM__CR1 EQU CYREG_DSM0_CR1
ADC_DSM__CR10 EQU CYREG_DSM0_CR10
ADC_DSM__CR11 EQU CYREG_DSM0_CR11
ADC_DSM__CR12 EQU CYREG_DSM0_CR12
ADC_DSM__CR13 EQU CYREG_DSM0_CR13
ADC_DSM__CR14 EQU CYREG_DSM0_CR14
ADC_DSM__CR15 EQU CYREG_DSM0_CR15
ADC_DSM__CR16 EQU CYREG_DSM0_CR16
ADC_DSM__CR17 EQU CYREG_DSM0_CR17
ADC_DSM__CR2 EQU CYREG_DSM0_CR2
ADC_DSM__CR3 EQU CYREG_DSM0_CR3
ADC_DSM__CR4 EQU CYREG_DSM0_CR4
ADC_DSM__CR5 EQU CYREG_DSM0_CR5
ADC_DSM__CR6 EQU CYREG_DSM0_CR6
ADC_DSM__CR7 EQU CYREG_DSM0_CR7
ADC_DSM__CR8 EQU CYREG_DSM0_CR8
ADC_DSM__CR9 EQU CYREG_DSM0_CR9
ADC_DSM__DEM0 EQU CYREG_DSM0_DEM0
ADC_DSM__DEM1 EQU CYREG_DSM0_DEM1
ADC_DSM__MISC EQU CYREG_DSM0_MISC
ADC_DSM__OUT0 EQU CYREG_DSM0_OUT0
ADC_DSM__OUT1 EQU CYREG_DSM0_OUT1
ADC_DSM__REF0 EQU CYREG_DSM0_REF0
ADC_DSM__REF1 EQU CYREG_DSM0_REF1
ADC_DSM__REF2 EQU CYREG_DSM0_REF2
ADC_DSM__REF3 EQU CYREG_DSM0_REF3
ADC_DSM__RSVD1 EQU CYREG_DSM0_RSVD1
ADC_DSM__SW0 EQU CYREG_DSM0_SW0
ADC_DSM__SW2 EQU CYREG_DSM0_SW2
ADC_DSM__SW3 EQU CYREG_DSM0_SW3
ADC_DSM__SW4 EQU CYREG_DSM0_SW4
ADC_DSM__SW6 EQU CYREG_DSM0_SW6
ADC_DSM__TR0 EQU CYREG_NPUMP_DSM_TR0
ADC_DSM__TST0 EQU CYREG_DSM0_TST0
ADC_DSM__TST1 EQU CYREG_DSM0_TST1

/* ADC_Ext_CP_Clk */
ADC_Ext_CP_Clk__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
ADC_Ext_CP_Clk__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
ADC_Ext_CP_Clk__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
ADC_Ext_CP_Clk__CFG2_SRC_SEL_MASK EQU 0x07
ADC_Ext_CP_Clk__INDEX EQU 0x00
ADC_Ext_CP_Clk__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ADC_Ext_CP_Clk__PM_ACT_MSK EQU 0x01
ADC_Ext_CP_Clk__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ADC_Ext_CP_Clk__PM_STBY_MSK EQU 0x01

/* ADC_IRQ */
ADC_IRQ__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
ADC_IRQ__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
ADC_IRQ__INTC_MASK EQU 0x20000000
ADC_IRQ__INTC_NUMBER EQU 29
ADC_IRQ__INTC_PRIOR_NUM EQU 7
ADC_IRQ__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_29
ADC_IRQ__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
ADC_IRQ__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* ADC_theACLK */
ADC_theACLK__CFG0 EQU CYREG_CLKDIST_ACFG0_CFG0
ADC_theACLK__CFG1 EQU CYREG_CLKDIST_ACFG0_CFG1
ADC_theACLK__CFG2 EQU CYREG_CLKDIST_ACFG0_CFG2
ADC_theACLK__CFG2_SRC_SEL_MASK EQU 0x07
ADC_theACLK__CFG3 EQU CYREG_CLKDIST_ACFG0_CFG3
ADC_theACLK__CFG3_PHASE_DLY_MASK EQU 0x0F
ADC_theACLK__INDEX EQU 0x00
ADC_theACLK__PM_ACT_CFG EQU CYREG_PM_ACT_CFG1
ADC_theACLK__PM_ACT_MSK EQU 0x01
ADC_theACLK__PM_STBY_CFG EQU CYREG_PM_STBY_CFG1
ADC_theACLK__PM_STBY_MSK EQU 0x01

/* LCD_LCDPort */
LCD_LCDPort__0__INTTYPE EQU CYREG_PICU2_INTTYPE0
LCD_LCDPort__0__MASK EQU 0x01
LCD_LCDPort__0__PC EQU CYREG_PRT2_PC0
LCD_LCDPort__0__PORT EQU 2
LCD_LCDPort__0__SHIFT EQU 0
LCD_LCDPort__1__INTTYPE EQU CYREG_PICU2_INTTYPE1
LCD_LCDPort__1__MASK EQU 0x02
LCD_LCDPort__1__PC EQU CYREG_PRT2_PC1
LCD_LCDPort__1__PORT EQU 2
LCD_LCDPort__1__SHIFT EQU 1
LCD_LCDPort__2__INTTYPE EQU CYREG_PICU2_INTTYPE2
LCD_LCDPort__2__MASK EQU 0x04
LCD_LCDPort__2__PC EQU CYREG_PRT2_PC2
LCD_LCDPort__2__PORT EQU 2
LCD_LCDPort__2__SHIFT EQU 2
LCD_LCDPort__3__INTTYPE EQU CYREG_PICU2_INTTYPE3
LCD_LCDPort__3__MASK EQU 0x08
LCD_LCDPort__3__PC EQU CYREG_PRT2_PC3
LCD_LCDPort__3__PORT EQU 2
LCD_LCDPort__3__SHIFT EQU 3
LCD_LCDPort__4__INTTYPE EQU CYREG_PICU2_INTTYPE4
LCD_LCDPort__4__MASK EQU 0x10
LCD_LCDPort__4__PC EQU CYREG_PRT2_PC4
LCD_LCDPort__4__PORT EQU 2
LCD_LCDPort__4__SHIFT EQU 4
LCD_LCDPort__5__INTTYPE EQU CYREG_PICU2_INTTYPE5
LCD_LCDPort__5__MASK EQU 0x20
LCD_LCDPort__5__PC EQU CYREG_PRT2_PC5
LCD_LCDPort__5__PORT EQU 2
LCD_LCDPort__5__SHIFT EQU 5
LCD_LCDPort__6__INTTYPE EQU CYREG_PICU2_INTTYPE6
LCD_LCDPort__6__MASK EQU 0x40
LCD_LCDPort__6__PC EQU CYREG_PRT2_PC6
LCD_LCDPort__6__PORT EQU 2
LCD_LCDPort__6__SHIFT EQU 6
LCD_LCDPort__AG EQU CYREG_PRT2_AG
LCD_LCDPort__AMUX EQU CYREG_PRT2_AMUX
LCD_LCDPort__BIE EQU CYREG_PRT2_BIE
LCD_LCDPort__BIT_MASK EQU CYREG_PRT2_BIT_MASK
LCD_LCDPort__BYP EQU CYREG_PRT2_BYP
LCD_LCDPort__CTL EQU CYREG_PRT2_CTL
LCD_LCDPort__DM0 EQU CYREG_PRT2_DM0
LCD_LCDPort__DM1 EQU CYREG_PRT2_DM1
LCD_LCDPort__DM2 EQU CYREG_PRT2_DM2
LCD_LCDPort__DR EQU CYREG_PRT2_DR
LCD_LCDPort__INP_DIS EQU CYREG_PRT2_INP_DIS
LCD_LCDPort__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU2_BASE
LCD_LCDPort__LCD_COM_SEG EQU CYREG_PRT2_LCD_COM_SEG
LCD_LCDPort__LCD_EN EQU CYREG_PRT2_LCD_EN
LCD_LCDPort__MASK EQU 0x7F
LCD_LCDPort__PORT EQU 2
LCD_LCDPort__PRT EQU CYREG_PRT2_PRT
LCD_LCDPort__PRTDSI__CAPS_SEL EQU CYREG_PRT2_CAPS_SEL
LCD_LCDPort__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT2_DBL_SYNC_IN
LCD_LCDPort__PRTDSI__OE_SEL0 EQU CYREG_PRT2_OE_SEL0
LCD_LCDPort__PRTDSI__OE_SEL1 EQU CYREG_PRT2_OE_SEL1
LCD_LCDPort__PRTDSI__OUT_SEL0 EQU CYREG_PRT2_OUT_SEL0
LCD_LCDPort__PRTDSI__OUT_SEL1 EQU CYREG_PRT2_OUT_SEL1
LCD_LCDPort__PRTDSI__SYNC_OUT EQU CYREG_PRT2_SYNC_OUT
LCD_LCDPort__PS EQU CYREG_PRT2_PS
LCD_LCDPort__SHIFT EQU 0
LCD_LCDPort__SLW EQU CYREG_PRT2_SLW

/* IDAC_viDAC8 */
IDAC_viDAC8__CR0 EQU CYREG_DAC3_CR0
IDAC_viDAC8__CR1 EQU CYREG_DAC3_CR1
IDAC_viDAC8__D EQU CYREG_DAC3_D
IDAC_viDAC8__PM_ACT_CFG EQU CYREG_PM_ACT_CFG8
IDAC_viDAC8__PM_ACT_MSK EQU 0x08
IDAC_viDAC8__PM_STBY_CFG EQU CYREG_PM_STBY_CFG8
IDAC_viDAC8__PM_STBY_MSK EQU 0x08
IDAC_viDAC8__STROBE EQU CYREG_DAC3_STROBE
IDAC_viDAC8__SW0 EQU CYREG_DAC3_SW0
IDAC_viDAC8__SW2 EQU CYREG_DAC3_SW2
IDAC_viDAC8__SW3 EQU CYREG_DAC3_SW3
IDAC_viDAC8__SW4 EQU CYREG_DAC3_SW4
IDAC_viDAC8__TR EQU CYREG_DAC3_TR
IDAC_viDAC8__TRIM__M1 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M1
IDAC_viDAC8__TRIM__M2 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M2
IDAC_viDAC8__TRIM__M3 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M3
IDAC_viDAC8__TRIM__M4 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M4
IDAC_viDAC8__TRIM__M5 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M5
IDAC_viDAC8__TRIM__M6 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M6
IDAC_viDAC8__TRIM__M7 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M7
IDAC_viDAC8__TRIM__M8 EQU CYREG_FLSHID_CUST_TABLES_DAC3_M8
IDAC_viDAC8__TST EQU CYREG_DAC3_TST

/* SsrOut */
SsrOut__0__INTTYPE EQU CYREG_PICU0_INTTYPE0
SsrOut__0__MASK EQU 0x01
SsrOut__0__PC EQU CYREG_PRT0_PC0
SsrOut__0__PORT EQU 0
SsrOut__0__SHIFT EQU 0
SsrOut__AG EQU CYREG_PRT0_AG
SsrOut__AMUX EQU CYREG_PRT0_AMUX
SsrOut__BIE EQU CYREG_PRT0_BIE
SsrOut__BIT_MASK EQU CYREG_PRT0_BIT_MASK
SsrOut__BYP EQU CYREG_PRT0_BYP
SsrOut__CTL EQU CYREG_PRT0_CTL
SsrOut__DM0 EQU CYREG_PRT0_DM0
SsrOut__DM1 EQU CYREG_PRT0_DM1
SsrOut__DM2 EQU CYREG_PRT0_DM2
SsrOut__DR EQU CYREG_PRT0_DR
SsrOut__INP_DIS EQU CYREG_PRT0_INP_DIS
SsrOut__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU0_BASE
SsrOut__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
SsrOut__LCD_EN EQU CYREG_PRT0_LCD_EN
SsrOut__MASK EQU 0x01
SsrOut__PORT EQU 0
SsrOut__PRT EQU CYREG_PRT0_PRT
SsrOut__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
SsrOut__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
SsrOut__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
SsrOut__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
SsrOut__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
SsrOut__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
SsrOut__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
SsrOut__PS EQU CYREG_PRT0_PS
SsrOut__SHIFT EQU 0
SsrOut__SLW EQU CYREG_PRT0_SLW

/* Rtd_3_1 */
Rtd_3_1__0__INTTYPE EQU CYREG_PICU3_INTTYPE1
Rtd_3_1__0__MASK EQU 0x02
Rtd_3_1__0__PC EQU CYREG_PRT3_PC1
Rtd_3_1__0__PORT EQU 3
Rtd_3_1__0__SHIFT EQU 1
Rtd_3_1__AG EQU CYREG_PRT3_AG
Rtd_3_1__AMUX EQU CYREG_PRT3_AMUX
Rtd_3_1__BIE EQU CYREG_PRT3_BIE
Rtd_3_1__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Rtd_3_1__BYP EQU CYREG_PRT3_BYP
Rtd_3_1__CTL EQU CYREG_PRT3_CTL
Rtd_3_1__DM0 EQU CYREG_PRT3_DM0
Rtd_3_1__DM1 EQU CYREG_PRT3_DM1
Rtd_3_1__DM2 EQU CYREG_PRT3_DM2
Rtd_3_1__DR EQU CYREG_PRT3_DR
Rtd_3_1__INP_DIS EQU CYREG_PRT3_INP_DIS
Rtd_3_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Rtd_3_1__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Rtd_3_1__LCD_EN EQU CYREG_PRT3_LCD_EN
Rtd_3_1__MASK EQU 0x02
Rtd_3_1__PORT EQU 3
Rtd_3_1__PRT EQU CYREG_PRT3_PRT
Rtd_3_1__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Rtd_3_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Rtd_3_1__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Rtd_3_1__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Rtd_3_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Rtd_3_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Rtd_3_1__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Rtd_3_1__PS EQU CYREG_PRT3_PS
Rtd_3_1__SHIFT EQU 1
Rtd_3_1__SLW EQU CYREG_PRT3_SLW

/* Rtd_4_0 */
Rtd_4_0__0__INTTYPE EQU CYREG_PICU4_INTTYPE0
Rtd_4_0__0__MASK EQU 0x01
Rtd_4_0__0__PC EQU CYREG_PRT4_PC0
Rtd_4_0__0__PORT EQU 4
Rtd_4_0__0__SHIFT EQU 0
Rtd_4_0__AG EQU CYREG_PRT4_AG
Rtd_4_0__AMUX EQU CYREG_PRT4_AMUX
Rtd_4_0__BIE EQU CYREG_PRT4_BIE
Rtd_4_0__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Rtd_4_0__BYP EQU CYREG_PRT4_BYP
Rtd_4_0__CTL EQU CYREG_PRT4_CTL
Rtd_4_0__DM0 EQU CYREG_PRT4_DM0
Rtd_4_0__DM1 EQU CYREG_PRT4_DM1
Rtd_4_0__DM2 EQU CYREG_PRT4_DM2
Rtd_4_0__DR EQU CYREG_PRT4_DR
Rtd_4_0__INP_DIS EQU CYREG_PRT4_INP_DIS
Rtd_4_0__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Rtd_4_0__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Rtd_4_0__LCD_EN EQU CYREG_PRT4_LCD_EN
Rtd_4_0__MASK EQU 0x01
Rtd_4_0__PORT EQU 4
Rtd_4_0__PRT EQU CYREG_PRT4_PRT
Rtd_4_0__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Rtd_4_0__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Rtd_4_0__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Rtd_4_0__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Rtd_4_0__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Rtd_4_0__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Rtd_4_0__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Rtd_4_0__PS EQU CYREG_PRT4_PS
Rtd_4_0__SHIFT EQU 0
Rtd_4_0__SLW EQU CYREG_PRT4_SLW

/* Rtd_4_1 */
Rtd_4_1__0__INTTYPE EQU CYREG_PICU4_INTTYPE1
Rtd_4_1__0__MASK EQU 0x02
Rtd_4_1__0__PC EQU CYREG_PRT4_PC1
Rtd_4_1__0__PORT EQU 4
Rtd_4_1__0__SHIFT EQU 1
Rtd_4_1__AG EQU CYREG_PRT4_AG
Rtd_4_1__AMUX EQU CYREG_PRT4_AMUX
Rtd_4_1__BIE EQU CYREG_PRT4_BIE
Rtd_4_1__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Rtd_4_1__BYP EQU CYREG_PRT4_BYP
Rtd_4_1__CTL EQU CYREG_PRT4_CTL
Rtd_4_1__DM0 EQU CYREG_PRT4_DM0
Rtd_4_1__DM1 EQU CYREG_PRT4_DM1
Rtd_4_1__DM2 EQU CYREG_PRT4_DM2
Rtd_4_1__DR EQU CYREG_PRT4_DR
Rtd_4_1__INP_DIS EQU CYREG_PRT4_INP_DIS
Rtd_4_1__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Rtd_4_1__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Rtd_4_1__LCD_EN EQU CYREG_PRT4_LCD_EN
Rtd_4_1__MASK EQU 0x02
Rtd_4_1__PORT EQU 4
Rtd_4_1__PRT EQU CYREG_PRT4_PRT
Rtd_4_1__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Rtd_4_1__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Rtd_4_1__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Rtd_4_1__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Rtd_4_1__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Rtd_4_1__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Rtd_4_1__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Rtd_4_1__PS EQU CYREG_PRT4_PS
Rtd_4_1__SHIFT EQU 1
Rtd_4_1__SLW EQU CYREG_PRT4_SLW

/* Calib_3_4 */
Calib_3_4__0__INTTYPE EQU CYREG_PICU3_INTTYPE4
Calib_3_4__0__MASK EQU 0x10
Calib_3_4__0__PC EQU CYREG_PRT3_PC4
Calib_3_4__0__PORT EQU 3
Calib_3_4__0__SHIFT EQU 4
Calib_3_4__AG EQU CYREG_PRT3_AG
Calib_3_4__AMUX EQU CYREG_PRT3_AMUX
Calib_3_4__BIE EQU CYREG_PRT3_BIE
Calib_3_4__BIT_MASK EQU CYREG_PRT3_BIT_MASK
Calib_3_4__BYP EQU CYREG_PRT3_BYP
Calib_3_4__CTL EQU CYREG_PRT3_CTL
Calib_3_4__DM0 EQU CYREG_PRT3_DM0
Calib_3_4__DM1 EQU CYREG_PRT3_DM1
Calib_3_4__DM2 EQU CYREG_PRT3_DM2
Calib_3_4__DR EQU CYREG_PRT3_DR
Calib_3_4__INP_DIS EQU CYREG_PRT3_INP_DIS
Calib_3_4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU3_BASE
Calib_3_4__LCD_COM_SEG EQU CYREG_PRT3_LCD_COM_SEG
Calib_3_4__LCD_EN EQU CYREG_PRT3_LCD_EN
Calib_3_4__MASK EQU 0x10
Calib_3_4__PORT EQU 3
Calib_3_4__PRT EQU CYREG_PRT3_PRT
Calib_3_4__PRTDSI__CAPS_SEL EQU CYREG_PRT3_CAPS_SEL
Calib_3_4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT3_DBL_SYNC_IN
Calib_3_4__PRTDSI__OE_SEL0 EQU CYREG_PRT3_OE_SEL0
Calib_3_4__PRTDSI__OE_SEL1 EQU CYREG_PRT3_OE_SEL1
Calib_3_4__PRTDSI__OUT_SEL0 EQU CYREG_PRT3_OUT_SEL0
Calib_3_4__PRTDSI__OUT_SEL1 EQU CYREG_PRT3_OUT_SEL1
Calib_3_4__PRTDSI__SYNC_OUT EQU CYREG_PRT3_SYNC_OUT
Calib_3_4__PS EQU CYREG_PRT3_PS
Calib_3_4__SHIFT EQU 4
Calib_3_4__SLW EQU CYREG_PRT3_SLW

/* Calib_4_4 */
Calib_4_4__0__INTTYPE EQU CYREG_PICU4_INTTYPE4
Calib_4_4__0__MASK EQU 0x10
Calib_4_4__0__PC EQU CYREG_PRT4_PC4
Calib_4_4__0__PORT EQU 4
Calib_4_4__0__SHIFT EQU 4
Calib_4_4__AG EQU CYREG_PRT4_AG
Calib_4_4__AMUX EQU CYREG_PRT4_AMUX
Calib_4_4__BIE EQU CYREG_PRT4_BIE
Calib_4_4__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Calib_4_4__BYP EQU CYREG_PRT4_BYP
Calib_4_4__CTL EQU CYREG_PRT4_CTL
Calib_4_4__DM0 EQU CYREG_PRT4_DM0
Calib_4_4__DM1 EQU CYREG_PRT4_DM1
Calib_4_4__DM2 EQU CYREG_PRT4_DM2
Calib_4_4__DR EQU CYREG_PRT4_DR
Calib_4_4__INP_DIS EQU CYREG_PRT4_INP_DIS
Calib_4_4__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Calib_4_4__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Calib_4_4__LCD_EN EQU CYREG_PRT4_LCD_EN
Calib_4_4__MASK EQU 0x10
Calib_4_4__PORT EQU 4
Calib_4_4__PRT EQU CYREG_PRT4_PRT
Calib_4_4__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Calib_4_4__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Calib_4_4__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Calib_4_4__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Calib_4_4__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Calib_4_4__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Calib_4_4__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Calib_4_4__PS EQU CYREG_PRT4_PS
Calib_4_4__SHIFT EQU 4
Calib_4_4__SLW EQU CYREG_PRT4_SLW

/* Calib_4_5 */
Calib_4_5__0__INTTYPE EQU CYREG_PICU4_INTTYPE5
Calib_4_5__0__MASK EQU 0x20
Calib_4_5__0__PC EQU CYREG_PRT4_PC5
Calib_4_5__0__PORT EQU 4
Calib_4_5__0__SHIFT EQU 5
Calib_4_5__AG EQU CYREG_PRT4_AG
Calib_4_5__AMUX EQU CYREG_PRT4_AMUX
Calib_4_5__BIE EQU CYREG_PRT4_BIE
Calib_4_5__BIT_MASK EQU CYREG_PRT4_BIT_MASK
Calib_4_5__BYP EQU CYREG_PRT4_BYP
Calib_4_5__CTL EQU CYREG_PRT4_CTL
Calib_4_5__DM0 EQU CYREG_PRT4_DM0
Calib_4_5__DM1 EQU CYREG_PRT4_DM1
Calib_4_5__DM2 EQU CYREG_PRT4_DM2
Calib_4_5__DR EQU CYREG_PRT4_DR
Calib_4_5__INP_DIS EQU CYREG_PRT4_INP_DIS
Calib_4_5__INTTYPE_BASE EQU CYDEV_PICU_INTTYPE_PICU4_BASE
Calib_4_5__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
Calib_4_5__LCD_EN EQU CYREG_PRT4_LCD_EN
Calib_4_5__MASK EQU 0x20
Calib_4_5__PORT EQU 4
Calib_4_5__PRT EQU CYREG_PRT4_PRT
Calib_4_5__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
Calib_4_5__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
Calib_4_5__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
Calib_4_5__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
Calib_4_5__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
Calib_4_5__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
Calib_4_5__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
Calib_4_5__PS EQU CYREG_PRT4_PS
Calib_4_5__SHIFT EQU 5
Calib_4_5__SLW EQU CYREG_PRT4_SLW

/* Clock1kHz */
Clock1kHz__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
Clock1kHz__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
Clock1kHz__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
Clock1kHz__CFG2_SRC_SEL_MASK EQU 0x07
Clock1kHz__INDEX EQU 0x01
Clock1kHz__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
Clock1kHz__PM_ACT_MSK EQU 0x02
Clock1kHz__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
Clock1kHz__PM_STBY_MSK EQU 0x02

/* TimerInterrupt */
TimerInterrupt__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
TimerInterrupt__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
TimerInterrupt__INTC_MASK EQU 0x01
TimerInterrupt__INTC_NUMBER EQU 0
TimerInterrupt__INTC_PRIOR_NUM EQU 7
TimerInterrupt__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
TimerInterrupt__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
TimerInterrupt__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

/* Miscellaneous */
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 18
CYDEV_CHIP_DIE_PSOC4A EQU 10
CYDEV_CHIP_DIE_PSOC5LP EQU 17
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x2E123069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 10
CYDEV_CHIP_MEMBER_4C EQU 15
CYDEV_CHIP_MEMBER_4D EQU 6
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 11
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 9
CYDEV_CHIP_MEMBER_4I EQU 14
CYDEV_CHIP_MEMBER_4J EQU 7
CYDEV_CHIP_MEMBER_4K EQU 8
CYDEV_CHIP_MEMBER_4L EQU 13
CYDEV_CHIP_MEMBER_4M EQU 12
CYDEV_CHIP_MEMBER_4N EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 17
CYDEV_CHIP_MEMBER_5B EQU 16
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5B
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5B_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_ENABLE_MASK EQU 0x20
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DEBUG
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_JTAG_4 EQU 1
CYDEV_DEBUGGING_DPS_JTAG_5 EQU 0
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x80
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x00000001
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x0800
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 0
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3_MV EQU 5000
CYIPBLOCK_ARM_CM3_VERSION EQU 0
CYIPBLOCK_P3_ANAIF_VERSION EQU 0
CYIPBLOCK_P3_CAN_VERSION EQU 0
CYIPBLOCK_P3_CAPSENSE_VERSION EQU 0
CYIPBLOCK_P3_COMP_VERSION EQU 0
CYIPBLOCK_P3_DECIMATOR_VERSION EQU 0
CYIPBLOCK_P3_DFB_VERSION EQU 0
CYIPBLOCK_P3_DMA_VERSION EQU 0
CYIPBLOCK_P3_DRQ_VERSION EQU 0
CYIPBLOCK_P3_DSM_VERSION EQU 0
CYIPBLOCK_P3_EMIF_VERSION EQU 0
CYIPBLOCK_P3_I2C_VERSION EQU 0
CYIPBLOCK_P3_LCD_VERSION EQU 0
CYIPBLOCK_P3_LPF_VERSION EQU 0
CYIPBLOCK_P3_OPAMP_VERSION EQU 0
CYIPBLOCK_P3_PM_VERSION EQU 0
CYIPBLOCK_P3_SCCT_VERSION EQU 0
CYIPBLOCK_P3_TIMER_VERSION EQU 0
CYIPBLOCK_P3_USB_VERSION EQU 0
CYIPBLOCK_P3_VIDAC_VERSION EQU 0
CYIPBLOCK_P3_VREF_VERSION EQU 0
CYIPBLOCK_S8_GPIO_VERSION EQU 0
CYIPBLOCK_S8_IRQ_VERSION EQU 0
CYIPBLOCK_S8_SAR_VERSION EQU 0
CYIPBLOCK_S8_SIO_VERSION EQU 0
CYIPBLOCK_S8_UDB_VERSION EQU 0
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0

#endif /* INCLUDED_CYFITTERIAR_INC */