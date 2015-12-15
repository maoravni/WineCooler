/******************************************************************************
* File Name: display.c
*  Version 2.1
*
* Description:
*  This file contains code to display temperature and various messages
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
#include "display.h"

unsigned char lcdDispArray[2][30];
/* String array to display menu item on the LCD */
const char8 *sensorName[] =
{
	"1:Thermocouple",
	"2:IC",
	"3:Thermistor",
	"4:RTD",
	"5:Diode 1",
	"6:Diode 2",
	"",
	"",
	"8:RTD Cal",
	"9:Diode1 Cal",
	"10:Diode2 Cal",
	"11:IC Cal",
	"TC   IC   Therm",
	"RTD  D1     D2 ",
};

/*******************************************************************************
*  Function Name: DisplayTemp
********************************************************************************
* Summary:
*  Moves active cursor location to a known position and prints float value with
* precision of 1 digit after decimal place.
*
* Parameters:
* float value -  temperature value to print
* uint8 row  - row no. to print the value 
* uint8 col  - column no. to print the value 
* uint8 sensor - menu item selected
*
* Return:
* void:
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/
void DisplayTemp(float value, uint8 row, uint8 col, uint8 sensor)
{
    char displayStr[20];
	uint8 tempCntr, stringEndflag = 0 ;

	/* If the value is within the measurable temperature range 
	 * then convert the value to string and display it */
	if( ( value > TEMP_MIN ) && ( value < TEMP_MAX ) )
	{
		/* Convert float to string for LCD display using sprintf(stdio.h)*/
	    sprintf(displayStr, "%d.%d", (int)value, ((int)(value*10)%10));
		for(tempCntr = 0 ; tempCntr < 16; tempCntr++)
		{
			if((displayStr[tempCntr] == '\0') && (stringEndflag == 0))
			{
				stringEndflag = 1;
				/* 0xDF prints degree sign */
				displayStr[tempCntr++] = 0xDF;
				displayStr[tempCntr++] = 'C';
			}
			if(stringEndflag)
			{
				displayStr[tempCntr] = ' ';
			}
		}
		displayStr[16] = '\0';
	
	    LCD_Position(row, col);
	    LCD_PrintString(displayStr);

//		if ( sensor == MENU_THERMOCOUPLE )
//		{
//			 LCD_Position(1, 8);
//			 LCD_PrintString(" CJ->");
//			 if ( CJSelectFlag == 0 )
//			 {
//			 	LCD_PrintString("IC");
//			 }
//			 else
//			 {
//			 	LCD_PrintString("Th");
//			 }
//		}
	}
	else
	{
	    LCD_Position(row, col);
	    LCD_PrintString((char8 *)"Connection Err ");
		
	}
		
//    LCD_Position(0, 0);
//    LCD_PrintString((char8 *)sensorName[sensor-1]);
}

/*******************************************************************************
*  Function Name: DisplayCal
********************************************************************************
* Summary:
*  Display the selected calibration routine and how to proceed through calibration
*
* Parameters:
* uint8 menu - menu item selected
*
* Return:
* void:
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/

void DisplayCal(uint8 menu)
{
	LCD_Position(0u, 0u);
	LCD_PrintString((char8 *)sensorName[menu-1]);
	LCD_Position(1u, 0u);
	LCD_PrintString((char8 *)"SW2 to Calibrate");
}


/*******************************************************************************
*  Function Name: DisplayLabels
********************************************************************************
* Summary:
*  Display labels for six temperature display 
*
* Parameters:
* void
*
* Return:
* void:
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/
void DisplayLabels(void)
{
	LCD_Position(0u, 0u);
	LCD_PrintString((char8 *)sensorName[12]);
	LCD_Position(1u, 0u);
	LCD_PrintString((char8 *)sensorName[13]);
}

/*******************************************************************************
*  Function Name: UpdateDisplayArray
********************************************************************************
* Summary:
*  This function updates the simultaneous temperature display array with
*  new temperature value at the specified row and column.
*
* Parameters:
* float value -  temperature value from the sensor
* uint8 row  - row no. to print the value 
* uint8 col  - column no. to print the value 
*
* Return:
* void:
*
* Theory:
*
* Side Effects:
* "lcdDispArray" will be updated with the specified value 
*******************************************************************************/
void UpdateDisplayArray(float value, uint8 row, uint8 col)
{
	uint8 tempCntr, clearDispFlag = 0;

	/* If the value is within the MIN - MAX temperature range 
	 * then convert the value to string and display it */

	if((value > TEMP_MIN) && (value < TEMP_MAX))
	{
		/* Convert float to string for LCD display using sprintf(stdio.h)*/
	    sprintf((char8 *)&lcdDispArray[row][col], "%4.1f", value);
		
		/* Scan the string and search for end of string character('\0') and add blank space 
		 * from end of string until beginning of the next display item.
		 * This is done to clear the display */
		for(tempCntr = 0; tempCntr < 6; tempCntr++)
		{
			/* If end of string ('\0') is detected ,set the clear display flag  */
			if(lcdDispArray[row][col + tempCntr] == '\0')
				clearDispFlag = 1;
				
			/* Once clear display flag is set, add blank space in the lcdDispArray 
			 * until beginning of next item */	
			if(clearDispFlag == 1)
				lcdDispArray[row][col + tempCntr] = ' ';
				
			/* If end of display array */
			if( (col + tempCntr) >= 15)
				break;
				
		}
	}
	/* If the temperature value is outside the expected temperature range it sould be connection problems
	 * Therefore display the message NC (No Connection) */
	else
	{
		lcdDispArray[row][col] = ' ';
		lcdDispArray[row][++col] = ' ';
		lcdDispArray[row][++col] = 'N'; 
		lcdDispArray[row][++col] = 'C'; 
		lcdDispArray[row][++col] = ' ';
		lcdDispArray[row][++col] = ' '; 
	}
	lcdDispArray[row][16] = '\0';
}

/*******************************************************************************
*  Function Name: SixSensorDisplay
********************************************************************************
* Summary:
*  Displays the temperature readings from all six temperature sensors
*
* Parameters:
* None
*
* Return:
* void:
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/
void SixSensorDisplay(void)
{
	LCD_Position(0u, 0u);
	LCD_PrintString((char8 *)&lcdDispArray[0]);
	LCD_Position(1u, 0u);
	LCD_PrintString((char8 *)&lcdDispArray[1]);
	
}

/* [] END OF FILE */
