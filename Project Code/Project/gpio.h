/*------------------------------------------------------------------------------------------------------
  [FILE_NAME]   : gpio.h header file for any re-usability at any other module
  [AUTHOR] 		: Mohamed_Abdelhamid_Sayed
  [DATE] 		: 27, march 2023
  [DESCRIPTION] : contains the related functions, which with it you can control the pins
 -------------------------------------------------------------------------------------------------------*/

#ifndef GPIO_H_
#define GPIO_H_
#include "std_types.h"
/*********************************************************************************
 *  								Definitions                                  *
 *********************************************************************************/
#define NUMBER_OF_PORTS 4
#define NUMBER_OF_PINS_PER_PORT 8

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID  0
#define PIN1_ID  1
#define PIN2_ID  2
#define PIN3_ID  3
#define PIN4_ID  4
#define PIN5_ID  5
#define PIN6_ID  6
#define PIN7_ID  7

/*********************************************************************************
 *  							Types Declarations                               *
 *********************************************************************************/

typedef enum {
	PIN_INPUT,PIN_OUTPUT
}GPIO_pinDirection;

typedef enum {
	PORT_INPUT,PORT_OUTPUT=0xFF
}GPIO_portDirection;

/*********************************************************************************
 *  					       functions prototypes                              *
 *********************************************************************************/

/*
 * Description:
 * this function prototype set the direction of pin required if it is input pin or either output pin
 * by taking 3 arguments the pin number and at which port, and the direction of it.
 * also it does not perform any tasks if the number of ports or pins bigger than required.
 */
void GPIO_setupPinDirection (uint8 a_portNumber, uint8 a_pinNumber, GPIO_pinDirection a_direction);

/*
 * Description:
 * this function writes the the value needed on the pin if needed to be output one or zero or even pull-up
 * activation for input pin
 */
void GPIO_writePin (uint8 a_portNumber, uint8 a_pinNumber, uint8 value);

/*
 *Description:
 *this function gets the values of the PINX register as when using it you should read the required port and
 *which pin is required to be read and returned where it is ever called the value of pin
 */
uint8 GPIO_readPin (uint8 a_portNumber,uint8 a_pinNmber);

/*
 * Description:
 * this function is used to set the whole port to input or even output to be written, and this by defining
 * the direction and performed to the register DDRX
 */
void GPIO_setupPortDirection (uint8 a_portNumber, GPIO_portDirection a_direction);

/*
 * Description
 * this function is responsible to write on the PORTX register to define the value of the port
 * if it is LOGIC HIGH = 0xFF or LOGIC LOW = 0
 */
void GPIO_writePort (uint8 a_portNumber, uint8 a_value);

/*
 * Description:
 * this function reads the values on the register PINX to know if it is high or low on the whole port
 * and return the value of the register to the required place it is called at
 */
uint8 GPIO_readPort (uint8 a_portNumber);


#endif /* GPIO_H_ */
