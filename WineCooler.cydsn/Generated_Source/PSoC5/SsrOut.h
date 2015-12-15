/*******************************************************************************
* File Name: SsrOut.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_SsrOut_H) /* Pins SsrOut_H */
#define CY_PINS_SsrOut_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "SsrOut_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 SsrOut__PORT == 15 && ((SsrOut__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    SsrOut_Write(uint8 value) ;
void    SsrOut_SetDriveMode(uint8 mode) ;
uint8   SsrOut_ReadDataReg(void) ;
uint8   SsrOut_Read(void) ;
uint8   SsrOut_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define SsrOut_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define SsrOut_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define SsrOut_DM_RES_UP          PIN_DM_RES_UP
#define SsrOut_DM_RES_DWN         PIN_DM_RES_DWN
#define SsrOut_DM_OD_LO           PIN_DM_OD_LO
#define SsrOut_DM_OD_HI           PIN_DM_OD_HI
#define SsrOut_DM_STRONG          PIN_DM_STRONG
#define SsrOut_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define SsrOut_MASK               SsrOut__MASK
#define SsrOut_SHIFT              SsrOut__SHIFT
#define SsrOut_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define SsrOut_PS                     (* (reg8 *) SsrOut__PS)
/* Data Register */
#define SsrOut_DR                     (* (reg8 *) SsrOut__DR)
/* Port Number */
#define SsrOut_PRT_NUM                (* (reg8 *) SsrOut__PRT) 
/* Connect to Analog Globals */                                                  
#define SsrOut_AG                     (* (reg8 *) SsrOut__AG)                       
/* Analog MUX bux enable */
#define SsrOut_AMUX                   (* (reg8 *) SsrOut__AMUX) 
/* Bidirectional Enable */                                                        
#define SsrOut_BIE                    (* (reg8 *) SsrOut__BIE)
/* Bit-mask for Aliased Register Access */
#define SsrOut_BIT_MASK               (* (reg8 *) SsrOut__BIT_MASK)
/* Bypass Enable */
#define SsrOut_BYP                    (* (reg8 *) SsrOut__BYP)
/* Port wide control signals */                                                   
#define SsrOut_CTL                    (* (reg8 *) SsrOut__CTL)
/* Drive Modes */
#define SsrOut_DM0                    (* (reg8 *) SsrOut__DM0) 
#define SsrOut_DM1                    (* (reg8 *) SsrOut__DM1)
#define SsrOut_DM2                    (* (reg8 *) SsrOut__DM2) 
/* Input Buffer Disable Override */
#define SsrOut_INP_DIS                (* (reg8 *) SsrOut__INP_DIS)
/* LCD Common or Segment Drive */
#define SsrOut_LCD_COM_SEG            (* (reg8 *) SsrOut__LCD_COM_SEG)
/* Enable Segment LCD */
#define SsrOut_LCD_EN                 (* (reg8 *) SsrOut__LCD_EN)
/* Slew Rate Control */
#define SsrOut_SLW                    (* (reg8 *) SsrOut__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define SsrOut_PRTDSI__CAPS_SEL       (* (reg8 *) SsrOut__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define SsrOut_PRTDSI__DBL_SYNC_IN    (* (reg8 *) SsrOut__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define SsrOut_PRTDSI__OE_SEL0        (* (reg8 *) SsrOut__PRTDSI__OE_SEL0) 
#define SsrOut_PRTDSI__OE_SEL1        (* (reg8 *) SsrOut__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define SsrOut_PRTDSI__OUT_SEL0       (* (reg8 *) SsrOut__PRTDSI__OUT_SEL0) 
#define SsrOut_PRTDSI__OUT_SEL1       (* (reg8 *) SsrOut__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define SsrOut_PRTDSI__SYNC_OUT       (* (reg8 *) SsrOut__PRTDSI__SYNC_OUT) 


#if defined(SsrOut__INTSTAT)  /* Interrupt Registers */

    #define SsrOut_INTSTAT                (* (reg8 *) SsrOut__INTSTAT)
    #define SsrOut_SNAP                   (* (reg8 *) SsrOut__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_SsrOut_H */


/* [] END OF FILE */
