/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   fan_controller.c                                             *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [DATE]:        5/10/2022                                                    *
 *                                                                             *
 * [DESCRIPTION]: design of a temperature-controlled fan using ATmega32        *
 *                microcontroller, in which the fan is automatically turned    *
 *                ON or OFF according to the temperature                       *
 *                                                                             *
 *******************************************************************************/


#include "adc.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "dc_motor.h"

int main(void)
{
	uint8 temp;
	/* Create configuration structure for ADC driver */
	ADC_ConfigType ADC_Config = {Internal_AREF,F_CPU_8};
	LCD_init(); /* initialize LCD driver */
	ADC_init(&ADC_Config); /* initialize ADC driver */
	DcMotor_Init(); /* initialize DC Motor driver */

	LCD_moveCursor(0,3);
	/* Display this string "FAN is " only once on LCD at the first row */
	LCD_displayString("FAN is ");
	LCD_moveCursor(1,3);
	/* Display this string "Temp =   C" only once on LCD at the second row */
	LCD_displayString("Temp =    C");

    while(1)
    {

    	temp = LM35_getTemperature();

    	/* Display the temperature value every time at same position */
    	LCD_moveCursor(0,10);
    	if(temp < 30)
    	{
    		/* In case the temperature is less than 30 turn off the fan */
    		LCD_displayString("OFF");
    		LCD_moveCursor(1,10);
    		LCD_intgerToString(temp);
    		/* In case the digital value is two or one digits print space in the next digit place */
    		LCD_displayString(" ");
    		/* Stop the motor */
    		DcMotor_Rotate(STOP,0);
    	}
    	else if((temp>=30) && (temp<60))
    	{
    		/* In case the temperature is not less than 30 turn on the fan */
    		LCD_displayString("ON ");
    		LCD_moveCursor(1,10);
    		LCD_intgerToString(temp);
    		/* In case the digital value is two or one digits print space in the next digit place */
    		LCD_displayString(" ");
    		/* Rotate the motor clock wise with 25% motor speed */
    		DcMotor_Rotate(CW,25);
    	}

    	else if((temp>=60) && (temp<90))
    	{
    		/* In case the temperature is not less than 30 turn on the fan */
    		LCD_displayString("ON ");
    		LCD_moveCursor(1,10);
    		LCD_intgerToString(temp);
    		/* In case the digital value is two or one digits print space in the next digit place */
    		LCD_displayString(" ");
    		/* Rotate the motor clock wise with 50% motor speed */
    		DcMotor_Rotate(CW,50);
    	}

    	else if((temp>=90) && (temp<120))
    	{
    		/* In case the temperature is not less than 30 turn on the fan */
    		LCD_displayString("ON ");
    		LCD_moveCursor(1,10);
    		LCD_intgerToString(temp);
    		if(temp<100)
    		{
    			/* In case the digital value is less than 100 print space in the next digit place */
    			LCD_displayString(" ");
    		}
    		/* Rotate the motor clock wise with 75% motor speed */
    		DcMotor_Rotate(CW,75);
    	}

    	else if(temp>=120)
    	{
    		/* In case the temperature is not less than 30 turn on the fan */
    		LCD_displayString("ON ");
    		LCD_moveCursor(1,10);
    		LCD_intgerToString(temp);
    		/* Rotate the motor clock wise with 100% motor speed */
    		DcMotor_Rotate(CW,100);
		}
    }
}
