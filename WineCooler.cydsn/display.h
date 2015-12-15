/******************************************************************************
* File Name: display.h
*  Version 2.1
*
* Description:
*  This file contains function prototype to display sensor temperature on the 
*  LCD
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
#if !defined(DISPLAY_H)
#define DISPLAY_H

#include <device.h>
#include <stdio.h>
//#include "menu.h"
#define TEMP_MIN -273.0
#define TEMP_MAX 2500


/* Function prototype to display temperature on LCD */
void DisplayTemp(float tempValue, uint8 row, uint8 col, uint8 sensorID);

/* Function to display calibration message */
void DisplayCal(uint8 menuCount);

/* Function to display labels for 6 sensor display */
void DisplayLabels(void);

/* Function to update display array for simultaneous temperature display */
void UpdateDisplayArray(float value, uint8 row, uint8 col);

/* Function to display all the six sensor values */ 
void SixSensorDisplay(void);

/* Flag to toggle CJ selection between thermistor and IC */
extern uint8 CJSelectFlag;

#endif /* DISPLAY_H */

/* [] END OF FILE */


