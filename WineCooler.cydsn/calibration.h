/******************************************************************************
* File Name: calibration.h
*  Version 2.1
*
* Description:
*  This file contains defines and function prototype used for zero current
*  calibration measurement and VSSA measurement for correlated double sampling 
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
#if !defined(CALIBRATION_H)
#define CALIBRATION_H

#include <device.h>
#include <math.h>
//#include "diode.h"
#include "RTD.h"
//#include "thermistor.h"
//#include "thermocouple.h"

/* Define Scaling Multipliers */
#define RESISTANCE_SCALING              1000
#define TEMPERATURE_SCALING             100

/* Defines for ADC MUX channels */
#define CAL_CHANNEL                     1
#define VSSA_GND_REF_CHANNEL            7

/* Defines for Current MUX channels */
#define CAL_IDAC_CHANNEL                1

/* Coefficients for calculating RTD resistance at a given temperature */
#define RTD_R0 100.0
#define RTD_COEFF_A 3.9083E-3
#define RTD_COEFF_B -5.775E-7
#define RTD_COEFF_C -4.183E-12

/* Function prototype to read and average sample for Vssa Ref voltage*/
int32 GetVssaRefSample(void);

/* Function to measure voltage across the sensor at zero current */
int32 GetZeroCurrentOffset(void);

/* Function to calculate the calibration constant for diode*/
float DiodeCalibration(float tIdeal, float tMeasured);

/* Function to calculate the calibration constant for RTD */
float RTDCalibration(float CalibrationTemp);

/* Function to calibrate CJ temperature offset */
int32 ICCalibration(float calTemp);

/* Function to calibrate diode1 , display the approppriate messages 
 * and write calibration constant to EEPROM .This inturn calls DiodeCalibration function */
void Calibrate_Diode1(void);

/* Function to calibrate diode1 , display the approppriate messages 
 * and write calibration constant to EEPROM .This inturn calls DiodeCalibration function */
void Calibrate_Diode2(void);

/* Function to calibrate RTD , display the approppriate messages 
 * and write calibration constant to EEPROM .This inturn calls RTDCalibration function */
void Calibrate_RTD(void);

/* Function to calibrate IC , display the approppriate messages 
 * and write calibration constant to EEPROM .This inturn calls ICCalibration function */
void Calibrate_IC(void);

#endif

/* [] END OF FILE */

