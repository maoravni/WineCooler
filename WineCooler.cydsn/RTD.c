/******************************************************************************
* File Name: RTD.c
*  Version 2.1
*
* Description:
*  This file contains defines and function prototype for temperature measurement
*  using RTD sensor
*
* Note:
*
********************************************************************************
* Copyright (2013), Cypress Semiconductor Corporation. All Rights Reserved.
********************************************************************************
* This software is owned by Cypress Semiconductor Corporation (Cypress)
* and is protected by and subject to worldwide patent protection (United
* States and foreign), United States copyright laws and international treaty
* provisions. Cypress hereby grants to licensee a personal, non-exclusive,
* non-transferable license to copy, use, modify, create derivative works of,
* and compile the Cypress Source Code and derivative works for the sole
* purpose of creating custom software in support of licensee product to be
* used only in conjunction with a Cypress integrated circuit as specified in
* the applicable agreement. Any reproduction, modification, translation,
* compilation, or representation of this software except as specified above 
* is prohibited without the express written permission of Cypress.
*
* Disclaimer: CYPRESS MAKES NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, WITH 
* REGARD TO THIS MATERIAL, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
* WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
* Cypress reserves the right to make changes without further notice to the 
* materials described herein. Cypress does not assume any liability arising out 
* of the application or use of any product or circuit described herein. Cypress 
* does not authorize its products for use as critical components in life-support 
* systems where a malfunction or failure may reasonably be expected to result in 
* significant injury to the user. The inclusion of Cypress' product in a life-
* support systems application implies that the manufacturer assumes all risk of 
* such use and in doing so indemnifies Cypress against all charges. 
*
* Use of this Software may be limited by and subject to the applicable Cypress
* software license agreement. 
*******************************************************************************/
#include "RTD.h"

/* RTD scale factor*/
volatile float rtdScaleFactor = 1.0;

/*******************************************************************************
* Function Name:  MeasureRTDTemp
********************************************************************************
* Summary:
* This function measures the temperature using the sub function
* RTDGetResistance() and RTD_GetTemperature() API

* Parameters:  
* void:  
*
* Return: 
* float: Temperature in °C

* Side Effects:
* None 	
*******************************************************************************/
float MeasureRTDTemp(void)
{   
    /* RTD resistance */
    int32 rtdResistance;
	
    /* RTD temperature */
	int32 rtdTemp;
    
    /* Calibration Voltage */
	int32 vCal;
    
    /* Get the calibration voltage */
    vCal = MeasureCalibrationVoltage();
    
    /* Get RTD resistance */ 
	rtdResistance = rtdScaleFactor * GetRTDResistance(vCal);
    
    /* Get RTD temperature */
    rtdTemp = RTD_1_GetTemperature(rtdResistance);
	
    return (float)(rtdTemp/100.0);
}

/*******************************************************************************
*  Function Name: MeasureCalibrationVoltage
********************************************************************************
* Summary:
* This functions returns the voltage across the reference resistor. 
*
* Parameters:
* none
*
* Return: 
* Calibration voltage in ADC counts 

* Theory:
* A current is passed through the calibration resistor and the voltage across it 
* is measured. Offset is measured and subtracted from this voltage. An IIR filter 
* is also applied on this voltage.
*
* Side Effects:
* None
*******************************************************************************/
int32 MeasureCalibrationVoltage()
{
	/* Voltage read across calibration resistor in ADC counts */
	int32 rtdCalResult = 0;
	
	/* Filtered value for calibration voltage measurement */
    int32 filRtdCalResult = 0;
	
	/* Offset counts */
	int32 zeroCurrentOffset = 0;
    
    /* Configure the IDAC to source 128 uA */
	IDAC_SetValue(128);
	
	/* Select the right current Mux and ADC Mux Channels */
	CurrentMux_FastSelect(CAL_IDAC_CHANNEL);
	ADCMux_FastSelect(CAL_CHANNEL);
    #ifndef PSOC4
	ADC_SelectConfiguration(ADC_CFG1,1);
    #endif
    
	/* Read voltage across calibration resistor */
	ADC_StartConvert();
	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
	ADC_StopConvert();
#ifdef PSOC4
    rtdCalResult = ADC_GetResult16(0);
#else
	rtdCalResult = ADC_GetResult32();
#endif
	
	/* Get the offset voltage */
	zeroCurrentOffset = GetZeroCurrentOffset();
	
	/* Get CDS difference */
	rtdCalResult = rtdCalResult - zeroCurrentOffset; 
	
	/* Filter signal */
	filRtdCalResult = FilterSignal( rtdCalResult , DCALI1 );
		
	return filRtdCalResult;
}
/*******************************************************************************
*  Function Name: GetRTDRes
********************************************************************************
* Summary:
* This function measures the voltage across the RTD resistance 
*
* Parameters:
* (int32) vCal      - Calibration voltage in ADC counts
*
* Return: 
* (int32) rtdRes    - RTD resistance in milliohms

* Theory:
* A current is passed through the calibration resistor and the voltage across it 
* is measured. Offset is measured and subtracted from this voltage. An IIR filter 
* is also applied on this voltage.
*
* Side Effects:
* None
*******************************************************************************/
int32 GetRTDResistance(int32 vCal)
{
	/* Voltage read across RTD sensor in ADC counts */
	int32 rtdResult = 0;
	
	/* Filtered value for RTD sensor voltage measurement */
    int32 filRtdResult = 0;
	
	/* RTD resistance */
	int32 rtdRes = 0;
	
	/* Offset counts */
	int32 zeroCurrentOffset = 0;
    
    /* Set the IDAC to pass 1 uA */
	IDAC_SetValue(128);
	
	/* Select the right current Mux and ADC Mux Channels */
	CurrentMux_FastSelect(RTD_IDAC_CHANNEL);
	ADCMux_FastSelect(RTD_CHANNEL);
    #ifndef PSOC4
	ADC_SelectConfiguration(ADC_CFG1,1);
    #endif
    
	/* Read voltage across RTD */
	ADC_StartConvert();
	ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
#ifdef PSOC4
    rtdResult = ADC_GetResult16(0);
#else
	rtdResult = ADC_GetResult32();
#endif
	ADC_StopConvert();
		
	/* Read zero current voltage across RTD sensor resistor */
	zeroCurrentOffset = GetZeroCurrentOffset();
	
	/* Get CDS difference */
	rtdResult = rtdResult - zeroCurrentOffset;
	
	/* Filter the signal */
	filRtdResult = FilterSignal( rtdResult , DCALI1 );

	/* Find RTD resistance */
	rtdRes = ( (float) filRtdResult / vCal ) * CAL_REF_RESISTOR;
	
	return rtdRes;
}

/* [] END OF FILE */

