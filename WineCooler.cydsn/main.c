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

int secCounter = 0;

float g_setpoint;

#define M_MIN_SETPOINT 10
#define M_MAX_SETPOINT 20

#define M_SLEEP_INTERVAL 5*60
#define M_MAX_COOL_INTERVAL 20*60

cystatus WriteSetpointToEeprom(float value)
{
    char* valueArray = (void*)&value;
    cystatus result;
    
    result = EEPROM_1_WriteByte(valueArray[0], 0);
    if (result != CYRET_SUCCESS)
        return result;
    EEPROM_1_WriteByte(valueArray[1], 1);
    if (result != CYRET_SUCCESS)
        return result;
    EEPROM_1_WriteByte(valueArray[2], 2);
    if (result != CYRET_SUCCESS)
        return result;
    EEPROM_1_WriteByte(valueArray[3], 3);

    return result;
}

float ReadSetpointFromEeprom()
{
    char valueArray[4];
    float *result;
    
    valueArray[0] = EEPROM_1_ReadByte(0);
    valueArray[1] = EEPROM_1_ReadByte(1);
    valueArray[2] = EEPROM_1_ReadByte(2);
    valueArray[3] = EEPROM_1_ReadByte(3);

    result = (float*)valueArray;
    
    return *result;
}

void InitializeComponents(void)
{
    /* Start LCD and set position and print start message */
    LCD_Start();
//    LCD_Position(0, 0);
//    LCD_PrintString("  Temperature   ");
//    LCD_Position(1, 0);
//    LCD_PrintString("  Sensor Kit   ");
	
	/* Display for 1 second */
//    CyDelay(1000);
    
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
    
    EEPROM_1_Start();
    
    g_setpoint = ReadSetpointFromEeprom();
    
    if (g_setpoint < M_MIN_SETPOINT || g_setpoint > M_MAX_SETPOINT)
    {
        g_setpoint = 16;
        WriteSetpointToEeprom(g_setpoint);
    }
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
            {
                LCD_PrintString("Sleep");
                if (secCounter >= M_SLEEP_INTERVAL)
                {
                    monitorState = M_STATE_MONITOR;
                }
                break;
            }
            case M_STATE_MONITOR:
            {
                LCD_PrintString("Off");
                if (temperature > (g_setpoint + 1))
                {
                    monitorState = M_STATE_COOLING;
                    secCounter = 0;
                }
                break;
            }
            case M_STATE_COOLING:
            {
                LCD_PrintString("On");
                if (temperature <= g_setpoint || secCounter >= M_MAX_COOL_INTERVAL)
                {
                    monitorState = M_STATE_SLEEP;
                    secCounter = 0;
                }
                break;
            }
        }
                
                
    }
}

/* [] END OF FILE */
