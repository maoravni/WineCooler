/******************************************************************************
* File Name: RTD.h
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
#if !defined(RTD_H)
#define RTD_H

#include "temp.h"
#include "filter.h"
#include "calibration.h"
 
/* Calibration resistor value for RTD sensor - 100 ohms (100000 milliOhms) */
#define CAL_REF_RESISTOR                100000

#define RTD_CHANNEL                     0
#define RTD_IDAC_CHANNEL                0

/* Define for zero current measurement samples */
#define RTD_ZERO_CURRENT_SAMPLE         2
#define RTD_ZERO_CURRENT_SHIFT          1

/* Function prototype to measure temperature using RTD sensor */
float MeasureRTDTemp(void);

/* Function prototype to measure the voltage across calibration resistor */
int32 MeasureCalibrationVoltage(void);

/* Function prototype to measure the RTD resistance */
int32 GetRTDResistance(int32 vCal);


#endif /* RTD_H */

/* [] END OF FILE */

