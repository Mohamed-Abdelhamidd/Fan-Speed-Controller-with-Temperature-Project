/*------------------------------------------------------------------------------------------------------
  [FILE_NAME]   : gpio.c module
  [AUTHOR] 		: Mohamed_Abdelhamid_Sayed
  [DATE] 		: 27, march 2023
  [DESCRIPTION] : contains the related functions, which with it you can control the pins
 -------------------------------------------------------------------------------------------------------*/

#include <avr/io.h>
#include "common_macros.h"
#include "gpio.h"


/*
 * Description:
 * this function set the direction of pin required if it is input pin or either output pin
 * by taking 3 arguments the pin number and at which port, and the direction of it.
 * also it does not perform any tasks if the number of ports or pins bigger than required.
 */

void GPIO_setupPinDirection (uint8 a_portNumber, uint8 a_pinNumber, GPIO_pinDirection a_direction){

	if ((a_portNumber >= NUMBER_OF_PORTS ) || (a_pinNumber >= NUMBER_OF_PINS_PER_PORT))
	{
		/*Do nothing*/
	}
	else
	{
		switch (a_portNumber)
		{
		case PORTA_ID:
			if (a_direction == PIN_INPUT){
				CLEAR_BIT(DDRA, a_pinNumber);
			}
			else{
				SET_BIT(DDRA,a_pinNumber);
			}
			break;

		case PORTB_ID:
			if (a_direction == PIN_INPUT){
				CLEAR_BIT(DDRB, a_pinNumber);
			}
			else{
				SET_BIT(DDRB,a_pinNumber);
			}
			break;

		case PORTC_ID:
			if (a_direction == PIN_INPUT){
				CLEAR_BIT(DDRC,a_pinNumber);
			}
			else{
				SET_BIT(DDRC,a_pinNumber);
			}
			break;

		case PORTD_ID:
			if (a_direction == PIN_INPUT){
				CLEAR_BIT(DDRD,a_pinNumber);
			}
			else{
				SET_BIT(DDRD,a_pinNumber);
			}
			break;
		}
	}
}

/*
 * Description:
 * this function writes the the value needed on the pin if needed to be output one or zero or even pull-up
 * activation for input pin
 */

void GPIO_writePin (uint8 a_portNumber, uint8 a_pinNumber, uint8 value){

	if ( (a_portNumber >= NUMBER_OF_PORTS) || (a_pinNumber >= NUMBER_OF_PINS_PER_PORT) ){
		/*do nothing*/
	}
	else{

		switch (a_portNumber){
		case PORTA_ID:
			if (value == LOGIC_HIGH){
				SET_BIT(PORTA, a_pinNumber);
			}
			else{
				CLEAR_BIT(PORTA, a_pinNumber);
			}
			break;

		case PORTB_ID:
			if (value == LOGIC_HIGH){
				SET_BIT(PORTB, a_pinNumber);
			}
			else{
				CLEAR_BIT(PORTB, a_pinNumber);
			}
			break;

		case PORTC_ID:
			if (value == LOGIC_HIGH){
				SET_BIT(PORTC, a_pinNumber);
			}
			else{
				CLEAR_BIT(PORTC, a_pinNumber);
			}
			break;

		case PORTD_ID:
			if (value == LOGIC_HIGH){
				SET_BIT(PORTD, a_pinNumber);
			}
			else{
				CLEAR_BIT(PORTD, a_pinNumber);
			}
			break;
		}
	}
}

/*
 * Description:
 * this function is used to set the whole port to input or even output to be written, and this by defining
 * the direction and performed to the register DDRX
 */
uint8 GPIO_readPin (uint8 a_portNumber,uint8 a_pinNumber){

	uint8 value = LOGIC_LOW;

	if ( (a_portNumber >= NUMBER_OF_PORTS) || (a_pinNumber >= NUMBER_OF_PINS_PER_PORT) ){
		/*do nothing*/
	}
	else{

		switch (a_portNumber){

		case PORTA_ID:
			if (BIT_IS_SET(PINA, a_pinNumber)){
				value = LOGIC_HIGH;
			}
			else {
				value = LOGIC_LOW;
			}
			break;

		case PORTB_ID:
			if (BIT_IS_SET(PINB, a_pinNumber)){
				value = LOGIC_HIGH;
			}
			else {
				value = LOGIC_LOW;
			}
			break;

		case PORTC_ID:
			if (BIT_IS_SET(PINC, a_pinNumber)){
				value = LOGIC_HIGH;
			}
			else {
				value = LOGIC_LOW;
			}
			break;

		case PORTD_ID:
			if (BIT_IS_SET(PIND, a_pinNumber)){
				value = LOGIC_HIGH;
			}
			else {
				value = LOGIC_LOW;
			}
			break;
		}
	}
	return value;
}

void GPIO_setupPortDirection (uint8 a_portNumber, GPIO_portDirection a_direction){

	if (a_portNumber >= NUMBER_OF_PORTS){
		/*do nothing*/
	}
	else {
		switch (a_portNumber){
		case PORTA_ID:
			DDRA = a_direction;
			break;
		case PORTB_ID:
			DDRB = a_direction;
			break;
		case PORTC_ID:
			DDRC = a_direction;
			break;
		case  PORTD_ID:
			DDRD = a_direction;
			break;
		}
	}
}

/*
 * Description
 * this function is responsible to write on the PORTX register to define the value of the port
 * if it is LOGIC HIGH = 0xFF or LOGIC LOW = 0
 */
void GPIO_writePort (uint8 a_portNumber, uint8 a_value){
	if (a_portNumber >= NUMBER_OF_PORTS){
		/*do nothing*/
	}
	else{
		switch (a_portNumber){

		case PORTA_ID:
			PORTA = a_value;
			break;
		case PORTB_ID:
			PORTB = a_value;
			break;
		case PORTC_ID:
			PORTC = a_value;
			break;
		case PORTD_ID:
			PORTD = a_value;
			break;
		}
	}
}

/*
 * Description:
 * this function reads the values on the register PINX to know if it is high or low on the whole port
 * and return the value of the register to the required place it is called at
 */
uint8 GPIO_readPort (uint8 a_portNumber){
	uint8 a_value = LOGIC_LOW;

	if (a_portNumber >= NUMBER_OF_PORTS){
		/*do nothing*/
	}
	else {

		switch (a_portNumber){

		case PORTA_ID:
			a_value = PINA;
			break;
		case PORTB_ID:
			a_value = PINB;
			break;
		case PORTC_ID:
			a_value = PINC;
			break;
		case PORTD_ID:
			a_value = PIND;
			break;
		}

	}
	return a_value;
}
