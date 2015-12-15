/******************************************************************************
* File Name: filter.c
*  Version 2.1
*
* Description:
*  This file contains code to filter sensor output
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
#include "filter.h"

/*******************************************************************************
*  Function Name: FilterSignal
********************************************************************************
* Summary:
*  This is IIR filter to process the sampled ADC data. For first sample passed 
*  the function simply returns the passed ADC sample. for second sample onwards,
*  Fraction of input signal based upon the filter coefficient, is calculated and 
*  added to the previously stored filtered value.
*
* Parameters:
* (int32)  ADCSample       - ADC sample read for given signal
* (uint8)  sensor		   - The Signal that needs filtering
* 
* Return: 
* (int32)filteredValue - filtered value passed is updated after applying 
* IIR filter to the ADC sample.
*
* Theory:
* For more information on the IIR filter please refer to Cypress application
* note AN2099.
*
* Side Effects:
* None
*******************************************************************************/
int32 FilterSignal(int32 ADCSample, uint8 sensor)
{
	/* Running filtered value accumulator */
	static int32 filteredValue[NUM_SENSORS] = {0};
    
    /* Filter Coefficient for different sensors */ 
    int32 filterCoeffShift[NUM_SENSORS] = { TC_FILTER_COEFF_SHIFT, RTD_FILTER_COEFF_SHIFT, 
                                            RTD_REFRES_FILTER_COEFF_SHIFT, DIODE_CAL_FILTER_COEFF_SHIFT, 
                                            DIODE_CAL_FILTER_COEFF_SHIFT, DIODE_FILTER_COEFF_SHIFT, 
                                            DIODE_FILTER_COEFF_SHIFT};
    
    /* Filter feed forward for different sensors */                                        
    int32 filterFeedForward[NUM_SENSORS] = {(40*256), (50*256), (50*256), ((int32)250*256), ((int32)250*256), ((int32)250*256), ((int32)250*256)};
  	
	/* Filtered value rounded-off to 20-bits */
	int32 filValueRounded;
	
	/* Left shift input by 256 to allow divisions up to 256 */
	ADCSample <<= MAX_FILTER_COEFF_SHIFT;
	   
	/* Pass the filter input as it is for fast changes in input */
    if ( (ADCSample > (filteredValue[sensor] + filterFeedForward[sensor])) || (ADCSample < (filteredValue[sensor] - filterFeedForward[sensor])) )
    {
        filteredValue[sensor] = ADCSample;
    }
    
    /* If not the first sample then based on filter coefficient, filter the 
     * input signal */
    else
    {
		/* IIR filter */
		filteredValue[sensor] = filteredValue[sensor] + ((ADCSample - filteredValue[sensor]) >> filterCoeffShift[sensor]);			
	}
	
	/* Compensate filter result for  left shift of 8 and round off */
	filValueRounded = (filteredValue[sensor] >> MAX_FILTER_COEFF_SHIFT) + ((filteredValue[sensor] & 0x00000080) >> (MAX_FILTER_COEFF_SHIFT - 1));
	
    return filValueRounded;
}

/* END OF FILE */
