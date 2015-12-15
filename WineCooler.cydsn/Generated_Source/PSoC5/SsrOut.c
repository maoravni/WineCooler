/*******************************************************************************
* File Name: SsrOut.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "SsrOut.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 SsrOut__PORT == 15 && ((SsrOut__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: SsrOut_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void SsrOut_Write(uint8 value) 
{
    uint8 staticBits = (SsrOut_DR & (uint8)(~SsrOut_MASK));
    SsrOut_DR = staticBits | ((uint8)(value << SsrOut_SHIFT) & SsrOut_MASK);
}


/*******************************************************************************
* Function Name: SsrOut_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  SsrOut_DM_STRONG     Strong Drive 
*  SsrOut_DM_OD_HI      Open Drain, Drives High 
*  SsrOut_DM_OD_LO      Open Drain, Drives Low 
*  SsrOut_DM_RES_UP     Resistive Pull Up 
*  SsrOut_DM_RES_DWN    Resistive Pull Down 
*  SsrOut_DM_RES_UPDWN  Resistive Pull Up/Down 
*  SsrOut_DM_DIG_HIZ    High Impedance Digital 
*  SsrOut_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void SsrOut_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(SsrOut_0, mode);
}


/*******************************************************************************
* Function Name: SsrOut_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro SsrOut_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 SsrOut_Read(void) 
{
    return (SsrOut_PS & SsrOut_MASK) >> SsrOut_SHIFT;
}


/*******************************************************************************
* Function Name: SsrOut_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 SsrOut_ReadDataReg(void) 
{
    return (SsrOut_DR & SsrOut_MASK) >> SsrOut_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(SsrOut_INTSTAT) 

    /*******************************************************************************
    * Function Name: SsrOut_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 SsrOut_ClearInterrupt(void) 
    {
        return (SsrOut_INTSTAT & SsrOut_MASK) >> SsrOut_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
