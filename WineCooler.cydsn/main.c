/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include <stdio.h>
#include <stdlib.h>
#include "rtd.h"
#include "display.h"

//#define TEMP_MIN -273.0
//#define TEMP_MAX 2500
//
//void DisplayTemp(float value, uint8 row, uint8 col, int dummy)
//{
//    char displayStr[20];
//	uint8 tempCntr, stringEndflag = 0 ;
//    //volatile float valueTemp;
//
//	/* If the value is within the measurable temperature range 
//	 * then convert the value to string and display it */
//	if( ( value > TEMP_MIN ) && ( value < TEMP_MAX ) )
//	{
//		/* Convert float to string for LCD display using sprintf(stdio.h)*/
//        //valueTemp = value;
//	    sprintf(displayStr, "%f", (float)value);
//		for(tempCntr = 0 ; tempCntr < 16; tempCntr++)
//		{
//			if((displayStr[tempCntr] == '\0') && (stringEndflag == 0))
//			{
//				stringEndflag = 1;
//				/* 0xDF prints degree sign */
//				displayStr[tempCntr++] = 0xDF;
//				displayStr[tempCntr++] = 'C';
//			}
//			if(stringEndflag)
//			{
//				displayStr[tempCntr] = ' ';
//			}
//		}
//		displayStr[16] = '\0';
//	
//	    LCD_Position(row, col);
//	    LCD_PrintString(displayStr);
//
//	}
//	else
//	{
//	    LCD_Position(row, col);
//	    LCD_PrintString((char8 *)"Connection Err ");
//		
//	}
//}

int secCounter = 0;

void InitializeComponents(void)
{
    /* Start LCD and set position and print start message */
    LCD_Start();
    LCD_Position(0, 0);
    LCD_PrintString("  Temperature   ");
    LCD_Position(1, 0);
    LCD_PrintString("  Sensor Kit   ");
	
	/* Display for 1 second */
    CyDelay(1000);
    
    /* Start capsense and initialize baselines and enable scanning of menu buttons */
//    CapSense_Start();
//    CapSense_InitializeAllBaselines();
//    CapSense_ScanEnabledWidgets();
    
    ADCMux_Start();
    CurrentMux_Start();
    
//    Opamp_Start();
        
    ADC_Start();
    
    IDAC_Start();
	
//	isr_StateBckwrd_ClearPending();
//	isr_StateFwd_ClearPending();
//
//	isr_StateFwd_Start();
//	isr_StateBckwrd_Start();
	
	#if defined(__C51__) || defined(__CX51__)

	EEPROM_Start();
	
	#endif
    CyDelay(50);
	
	/* Clear the LCD display  */
//	LCD_ClearDisplay();
//    LCD_Position(1, 0);

    TimerInterrupt_Start();
    
}

#define M_STATE_SLEEP 0
#define M_STATE_MONITOR 1
#define M_STATE_COOLING 2

void TimerInterrupt_Interrupt_InterruptCallback()
{
}

int monitorState = M_STATE_SLEEP;

int main()
{
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

//	#if (!(CY_PSOC3))
//    asm (".global _printf_float");
//	#endif	

    InitializeComponents();
    
        float temperature = 0.0;

    for(;;)
    {
        /* Place your application code here. */
        temperature = MeasureRTDTemp();
        DisplayTemp(temperature, 1, 0, 5);
        
        char test[5];
        sprintf(test, "secs: %d", secCounter);
        LCD_Position(0,0);
        LCD_PrintString(test);

        LCD_Position(1, 10);

        switch (monitorState)
        {
            case M_STATE_SLEEP:
            LCD_PrintString("Sleep");
            if (secCounter >= 6)
            monitorState = M_STATE_MONITOR;
            break;
            case M_STATE_MONITOR:
            LCD_PrintString("Off");
            if (temperature > 17)
                monitorState = M_STATE_COOLING;
            break;
            case M_STATE_COOLING:
            LCD_PrintString("On");
            if (temperature <= 16)
            {
                monitorState = M_STATE_SLEEP;
                secCounter = 0;
            }
            break;
        }
                
                
    }
}

/* [] END OF FILE */
