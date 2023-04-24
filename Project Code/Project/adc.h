/*--------------------------------------------------------------------------------
 * Module: ADC
 *
 * File name: adc.h
 *
 * Description: header file for adc module
 *
 * Author: Mohamed Abdelhamid
 * -------------------------------------------------------------------------------*/


#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*************************************************************************************
 * 									Definitions										 *
 *************************************************************************************/
#define POLLING_MODE	/*-POLLING_MODE
						  -INTERRUPT_MODE*/

#define Maximum_ADC_VALUE 			1023
#define MINIMUM_ADC_VALUE 			0
#define ANALOG_REFERENCE_VOLT 		2.56

/*************************************************************************************
 * 								    External Variables							     *
 *************************************************************************************/
extern volatile uint16 adc; /*variable to use the value of ADC register at the ISR */

/*************************************************************************************
 * 								    Type Definitions							     *
 *************************************************************************************/

/*enum contains Analog voltage reference Modes */
typedef enum{
	AREF,AVCC= 0x40, INTERNAL = 0xC0
}ADC_Reference_volt;

/*enum contains the F_CPU prescaler modes for the MCU */
typedef enum{
	NO_PRE, PRE_2, PRE_4, PRE_8, PRE_16, PRE_32, PRE_64, PRE_128
}ADC_Prescaler;

/*Struct contains 3 configurable variables, the analog voltage mode and the Prescaler mode */
typedef struct{
	ADC_Reference_volt refVolt;
	ADC_Prescaler	prescaler;
}ADC_configType;

/*************************************************************************************
 * 								     Prototypes									     *
 *************************************************************************************/

/*initialization function to start the adc and takes an address of the defined
 struct by the user*/
void ADC_init (const ADC_configType * Config_Ptr);

/*if polling the channel value return the ADC register*/
#ifdef POLLING_MODE
uint16 ADC_readChannel (uint8 a_channelNumber);
#endif

/*if Interrupt, the interrupt uses an ISR*/
#ifdef INTERRUPT_MODE
void ADC_readChannel (uint8 a_channelNumber);
#endif


#endif /* ADC_H_ */
