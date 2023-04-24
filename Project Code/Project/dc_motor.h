/*-----------------------------------------------------------------------------------------------
 * Module	  : DC Motor
 *
 * File Name  : dc_motor.h
 *
 * Description: Header file for DC Motor Module
 *
 * Author	  : Mohamed Abdelhamid Sayed
 * ---------------------------------------------------------------------------------------------*/

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "std_types.h"

/************************************************************************************************
 * 										   Definitions
 ************************************************************************************************/
#define PORT_MOTOR_ID				PORTB_ID

#define FIRST_MOTOR_PIN_ID			PIN0_ID
#define SECOND_MOTOR_PIN_ID			PIN1_ID


/************************************************************************************************
 * 									  Typedef Declarations
 ************************************************************************************************/
typedef enum  {
	STOP,CW,ANTI_CW
}DcMotor_State;


/************************************************************************************************
 * 									  Function Prototypes
 ************************************************************************************************/

/*initialization function for the dc motor defines the port DIO pins directions and o/p   */
void DcMotor_Init (void);

/*function controls the speed of the motor using pwm module and control the rotation direction*/
void DcMotor_Rotate(DcMotor_State state,uint8 speed);
#endif /* DC_MOTOR_H_ */
