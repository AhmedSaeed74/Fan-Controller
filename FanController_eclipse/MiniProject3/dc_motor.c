/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   dc_motor.c                                                   *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [DATE]:        5/10/2022                                                    *
 *                                                                             *
 * [DESCRIPTION]: Source file for the DC Motor driver                          *
 *                                                                             *
 *******************************************************************************/

#include "dc_motor.h"
#include "pwm_timer0.h"
#include "gpio.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void)
{
	/* Configure the direction for for the two motor pins */
	GPIO_setupPinDirection(DC_MOTOR_OUTPUT1_PORT_ID,DC_MOTOR_OUTPUT1_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(DC_MOTOR_OUTPUT2_PORT_ID,DC_MOTOR_OUTPUT2_PIN_ID,PIN_OUTPUT);

	/* Motor is stop at the beginning */
	GPIO_writePin(DC_MOTOR_OUTPUT1_PORT_ID,DC_MOTOR_OUTPUT1_PIN_ID,LOGIC_LOW);
	GPIO_writePin(DC_MOTOR_OUTPUT2_PORT_ID,DC_MOTOR_OUTPUT2_PIN_ID,LOGIC_LOW);
}

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	uint8 duty_cycle; /* Variable used to Set Compare Value */

	if(state == STOP)
	{
		/* Stop the motor */
		GPIO_writePin(DC_MOTOR_OUTPUT1_PORT_ID,DC_MOTOR_OUTPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_OUTPUT2_PORT_ID,DC_MOTOR_OUTPUT2_PIN_ID,LOGIC_LOW);
	}

	else if(state == A_CW)
	{
		/* Rotate the motor --> Anti clock wise */
		GPIO_writePin(DC_MOTOR_OUTPUT1_PORT_ID,DC_MOTOR_OUTPUT1_PIN_ID,LOGIC_HIGH);
		GPIO_writePin(DC_MOTOR_OUTPUT2_PORT_ID,DC_MOTOR_OUTPUT2_PIN_ID,LOGIC_LOW);
	}

	else if(state == CW)
	{
		/* Rotate the motor --> clock wise */
		GPIO_writePin(DC_MOTOR_OUTPUT1_PORT_ID,DC_MOTOR_OUTPUT1_PIN_ID,LOGIC_LOW);
		GPIO_writePin(DC_MOTOR_OUTPUT2_PORT_ID,DC_MOTOR_OUTPUT2_PIN_ID,LOGIC_HIGH);
	}

	/* Calculate the duty cycle from the required speed of motor */
	duty_cycle = (uint8)(((uint16)speed*255)/(100));

	/* generate duty cycle to get the appropriate motor speed */
	PWM_Timer0_Start(duty_cycle);
}
