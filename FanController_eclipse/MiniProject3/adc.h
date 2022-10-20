/*******************************************************************************
 *                                                                             *
 * [FILE NAME]:   adc.h                                                        *
 *                                                                             *
 * [AUTHOR]:      Ahmed Saeed                                                  *
 *                                                                             *
 * [DATE]:        5/10/2022                                                    *
 *                                                                             *
 * [DESCRIPTION]: header file for the ATmega32 ADC driver                      *
 *                                                                             *
 *******************************************************************************/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
/*
 * Description :
 * Enum responsible for configure the reference voltage for ADC driver.
 */
typedef enum
{
	AREF,AVCC,RESERVED,Internal_AREF
}ADC_ReferenceVolatge;

/*
 * Description :
 * Enum responsible for configure the prescaler for ADC driver.
 */
typedef enum
{
	F_CPU_2,F_CPU_2_too,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Prescaler;

/*
 * Description :
 * Structure responsible for configure the ADC driver.
 */
typedef struct
{
 ADC_ReferenceVolatge ref_volt;
 ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);

/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */
