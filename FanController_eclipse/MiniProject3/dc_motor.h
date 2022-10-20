/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   dc_motor.h                                                   *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [DATE]:        5/10/2022                                                    *
 *                                                                             *
 * [DESCRIPTION]: header file for the DC Motor driver                          *
 *                                                                             *
 *******************************************************************************/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define DC_MOTOR_OUTPUT1_PORT_ID        PORTB_ID
#define DC_MOTOR_OUTPUT1_PIN_ID         PIN0_ID

#define DC_MOTOR_OUTPUT2_PORT_ID        PORTB_ID
#define DC_MOTOR_OUTPUT2_PIN_ID         PIN1_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*
 * Description :
 * Enum responsible for configure the state for DC MOTOR driver.
 */
typedef enum
{
	STOP,CW,A_CW
}DcMotor_State;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * The Function responsible for setup the direction for the two
 * motor pins through the GPIO driver.
 * Stop at the DC-Motor at the beginning through the GPIO driver.
 */
void DcMotor_Init(void);

/*
 * Description :
 * The function responsible for rotate the DC Motor CW/ or A-CW or
 * stop the motor based on the state input state value.
 * Send the required duty cycle to the PWM driver based on the
 * required speed value.
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);



#endif /* DC_MOTOR_H_ */
