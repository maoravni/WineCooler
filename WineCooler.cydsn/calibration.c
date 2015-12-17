/******************************************************************************
* File Name: calibration.c
*  Version 2.1
*
* Description:
*  This file contains code used for zero current calibration measurement 
*  and VSSA measurement for correlated double sampling
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
#include "calibration.h"


/* Calibration coefficient for RTD */
extern float rtdScaleFactor;

/* Calibration coefficent for diode1 and diode 2*/
extern float diode1ScaleFactor, diode2ScaleFactor;

/* Calibration coefficent for IC */
extern int32 cjCalibrationConst;

/* Flags indicating whether sensor is calibrated or not */
extern uint8 rtdCalibratedFlag, diode1CalibratedFlag, diode2CalibratedFlag, ICCalibratedFlag;

/* calibration temperatures entered by user */
extern float rtdCalTemp, diode1CalTemp, diode2CalTemp ,ICCalTemp;


/*******************************************************************************
*  Function Name: GetVssaRefSample
********************************************************************************
* Summary:
*  This function reads Vssa Ref value. 
*
* Parameters:
* void:
*
* Return:
* int32: Returns the Vssa ref value for CDS 
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/
int32 GetVssaRefSample(void)
{
    int32 result = 0;
      
   /* Switch the amux to Vssa gnd ref channel 
    * start the ADC conversion */
	ADCMux_FastSelect(VSSA_GND_REF_CHANNEL);
    ADC_StartConvert();
    
	/* Get the ADC value */
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
    result = ADC_GetResult32();
     
	/* Stop the ADC */  
    ADC_StopConvert();

    return result;
}

/*******************************************************************************
*  Function Name: GetZeroCurrentOffset
********************************************************************************
* Summary:
* This function reads voltage (offset) across RTD/calibration resistor at zero current.
* The user has to ensure that the right ADC configuration and channel is set before 
* calling this function.
*
* Parameters:
* void:
*
* Return:
* int32:  offset voltage 
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/
int32 GetZeroCurrentOffset(void)
{
    int32 result = 0;
       
    IDAC_SetValue(0);

    ADC_StartConvert();
    ADC_IsEndConversion(ADC_WAIT_FOR_RESULT);
#ifdef PSOC4
    result = ADC_GetResult16(0);
#else
    result = ADC_GetResult32();
#endif
    ADC_StopConvert();
    
    return result;
}

/*******************************************************************************
*  Function Name: RTDCalibration
********************************************************************************
* Summary:
*  This function measures the RTD resistor at the given temperature,as well as 
*  the expected calibration resistance for the given temperature and generates a 
*  calibration constant for the RTD
*
* Parameters:
* Calibration Temp : Temperature of RTD
*
* Return:
* float : calibration constant for RTD
*
* Theory:
*
* Side Effects:
* None
*******************************************************************************/
float RTDCalibration(float calibrationTemp)
{
	int32 rMeasured;
	float rCalc;
    int32 vCal;
	uint8 tempCntr;
	
	/* Measure the loop 150 times to get a stable filtered resistance value from the function*/
	for(tempCntr = 0; tempCntr < 150; tempCntr++)
	{
        vCal = MeasureCalibrationVoltage();
        
        /* Measure the RTD resistance at the set temperature*/
	    rMeasured = GetRTDResistance(vCal);
		
		
	}
	
	/* Rcal=R0(1 + AT + BT^2) 
	 * This is implemented as Rcal = R0 *(1 + (BT + A)* T) */
	rCalc = RTD_R0 * (1 + (RTD_COEFF_B * calibrationTemp + RTD_COEFF_A) * calibrationTemp);

	/* scale factor = Ractual/Rmeasured */
	rtdScaleFactor = ( rCalc / rMeasured ) * RESISTANCE_SCALING;
	
	return (rtdScaleFactor); 
	
}


/*******************************************************************************
*  Function Name: DiodeCalibration
********************************************************************************
* Summary:
*  This function generates the calibration constant for the diode from the 
*  temperature measured by the diode and the expected temperature output.
*
* Parameters:
* float tIdeal : Expected temperature output from the diode
* flaot tMeasured : Measured temperature output from the diode
*
* Return:
* float : calibration constant for diode
*
* Theory:
*	Calibration constant for diode = tIdeal/tMeasured
* Side Effects:
* None
*******************************************************************************/

float DiodeCalibration(float tIdeal ,float tMeasured)
{
	/* Variable to calculate diode constant */
	float diodeK;
	
	/* Convert both temperatures from Celsius to Kelvin */
	tIdeal += ZERO_DEGREE_CELSIUS_KELVIN;
	tMeasured += ZERO_DEGREE_CELSIUS_KELVIN;
	
	/* Find the diode calibration constant = tIdeal/tMeasured */
	diodeK = tIdeal / tMeasured;
	
	return(diodeK);
}

/*******************************************************************************
* Function Name: Calibrate_RTD
********************************************************************************
* Summary:
*  Function to calibrate RTD , display the approppriate messages and store 
*  calibration constants in EEPROM 
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Calibrate_RTD(void)
{
	/* If the calibrated flag is not set run the calibration routine 
	 * This flag is set each time the user selects to calibrate RTD */
	if(rtdCalibratedFlag == 0)
	{
		LCD_Position(0u, 0u);
		LCD_PrintString((char8 *)"Calibrating ...");
		
		LCD_Position(1u, 0u);
		LCD_PrintString((char8 *)"Wait for few sec");

		/* Call calibration routines and get the new rtd scale factor */
		rtdScaleFactor = RTDCalibration(rtdCalTemp);

		/* Write RTD scale factor to EEPROM row 0 */
		//EEPROM_Write((uint8 *)&rtdScaleFactor, 0);
		
	}
	CyDelay(1);	
	LCD_Position(0u, 0u);
	LCD_PrintString("Calibrated RTD  ");
	LCD_Position(1u, 0u);
	LCD_PrintString("SW2->Main menu  ");

	/* Set the calibrated RTD flag to indicate that RTD is calibrated */
	rtdCalibratedFlag = 1;
}

/*******************************************************************************
* Function Name: Calibrate_Diode1
********************************************************************************
* Summary:
*  Function to calibrate Diode1 and display the approppriate messages
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/

//void Calibrate_Diode1(void)
//{
//	/* variable to store the measured temperature */
//	float measuredTemp;
//	uint16 tempCntr;
//	
//	/* Enter calibration routine if the diode is not calibrated */
//	if(diode1CalibratedFlag == 0)
//	{
//		/* Set calibration constant to 1.0 before calibration */
//		diode1ScaleFactor = 1.0;
//
//		LCD_Position(0u, 0u);
//		LCD_PrintString((char8 *)"Calibrating ...");
//		
//		LCD_Position(1u, 0u);
//		LCD_PrintString((char8 *)"Wait for few sec");
//
//		/* Run the measure temperature loop 500 times to get 
//		 * a stable filtered temperature output */
//		for(tempCntr = 0; tempCntr < 500; tempCntr++)
//		{
//			/* Measure Diode Temperature */
//			measuredTemp = MeasureFirstDiodeTemp();
//		}
//		/* Call calibration routine and get diode scale factor */
//		diode1ScaleFactor = DiodeCalibration(diode1CalTemp, measuredTemp);
//		
//		/* Write diode1 scale factor to EEPROM row 1 */
//		EEPROM_Write((uint8 *)&diode1ScaleFactor, 1);
//	}
//		
//	CyDelay(1);	
//	LCD_Position(0u, 0u);
//	LCD_PrintString("Calibrted Diode1");
//	
//	
//	LCD_Position(1u, 0u);
//	LCD_PrintString("SW2->Main menu  ");
//
//	/* Set the diode1calibrated flag to indicate that diode1 is calibrated */
//	diode1CalibratedFlag = 1;
//
//}

/*******************************************************************************
* Function Name: Calibrate_Diode2
********************************************************************************
* Summary:
*  Function to calibrate Diode2 and display the approppriate messages
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
//void Calibrate_Diode2(void)
//{
//	float measuredTemp;
//	uint16 tempCntr;
//
//	/* Enter calibration routine if the diode is not calibrated */
//	if(diode2CalibratedFlag == 0)
//	{
//		/* Set calibration constant to 1.0 before calibration */
//		diode2ScaleFactor = 1.0;
//
//		LCD_Position(0u, 0u);
//		LCD_PrintString((char8 *)"Calibrating ...");
//		
//		LCD_Position(1u, 0u);
//		LCD_PrintString((char8 *)"Wait for few sec");
//
//		/* Run the measure temperature loop 500 times to get 
//		 * a stable filtered temperature output */
//		for(tempCntr = 0; tempCntr < 500; tempCntr++)
//		{
//			/* Measure Diode Temperature */
//			measuredTemp = MeasureSecondDiodeTemp();
//		}
//		
//		/* Call calibration routine and get diode scale factor */
//		diode2ScaleFactor = DiodeCalibration(diode2CalTemp, measuredTemp);
//		
//		/* Write diode2 scale factor to EEPROM row 2 */
//		EEPROM_Write((uint8 *)&diode2ScaleFactor, 2);
//	}
//	
//	CyDelay(1);	
//	LCD_Position(0u, 0u);
//	LCD_PrintString("Calibrted Diode2");
//	LCD_Position(1u, 0u);
//	LCD_PrintString("SW2->Main menu   ");
//	
//	/* Set the diodecalibrated flag so that the calibration routines are run only once */
//	diode2CalibratedFlag = 1;
//
//}

/*******************************************************************************
* Function Name: ICCalibration
********************************************************************************
* Summary:
*  Function to calibrate cold junction IC temperature offset.
*
* Parameters:
*  float calTemp : Calibration temperature
*
* Return:
*  int32 : Offset Calibration constant
*
*******************************************************************************/
//int32 ICCalibration(float calTemp)
//{
//	float ICTemp = 0;
//	int32 calibrationConst;
//	uint8 tempCntr;
//	
//	/* Measure ICTemp, temperature  and 
//	 * take an average of 10 samples */ 
//	for (tempCntr = 0; tempCntr < 10; tempCntr++)
//	{
//	    ICTemp += MeasureICTemp();
//	}	
//	ICTemp = ICTemp / 10;
//	
//	/* Offset = tMeasured - tIdeal */
//	calibrationConst = (ICTemp - calTemp) * TEMPERATURE_SCALING;
//	
//	return(calibrationConst);
//	
//}

/*******************************************************************************
* Function Name: Calibrate_IC
********************************************************************************
* Summary:
*  Function to calibrate IC and display the approppriate messages
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void Calibrate_IC(void)
{
	/* Enter calibration routine if the IC is not calibrated */
	if(ICCalibratedFlag == 0)
	{
		/* Set calibration constant to 0 before calibration */
		cjCalibrationConst = 0;

		LCD_Position(0u, 0u);
		LCD_PrintString((char8 *)"Calibrating ...");
		
		LCD_Position(1u, 0u);
		LCD_PrintString((char8 *)"Wait for few sec");

		/* Calibrate Cold junction compensation IC temperature */
		cjCalibrationConst = ICCalibration(ICCalTemp);
	
		/* Write diode2 scale factor to EEPROM row 2 */
		//EEPROM_Write((uint8 *) &cjCalibrationConst, 2);
		
		/* Set the ICCalibratedFlag flag so that the calibration routines are run only once */
		ICCalibratedFlag = 1;
	}
	
	CyDelay(1);	
	LCD_Position(0u, 0u);
	LCD_PrintString("Calibrated IC   ");
	LCD_Position(1u, 0u);
	LCD_PrintString("SW2->Main menu   ");
	

}

/* [] END OF FILE */
