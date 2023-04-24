/*-----------------------------------------------------------------------------------------------
 * Module	  : DC Motor
 *
 * File Name  : dc_motor.c
 *
 * Description: Source file for DC Motor Module
 *
 * Author	  : Mohamed Abdelhamid Sayed
 * ---------------------------------------------------------------------------------------------*/

#include "dc_motor.h"
#include "gpio.h"
#include "pwm.h"

void DcMotor_Init (void)
{
	GPIO_setupPinDirection(PORT_MOTOR_ID, FIRST_MOTOR_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(PORT_MOTOR_ID, SECOND_MOTOR_PIN_ID, PIN_OUTPUT);
	GPIO_writePin (PORT_MOTOR_ID, FIRST_MOTOR_PIN_ID, LOGIC_LOW);
	GPIO_writePin (PORT_MOTOR_ID, SECOND_MOTOR_PIN_ID, LOGIC_LOW);
}

void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	PWM_timer0_Start (speed);

	switch (state)
	{
	case STOP:
		GPIO_writePin (PORT_MOTOR_ID, FIRST_MOTOR_PIN_ID, LOGIC_LOW);
		GPIO_writePin (PORT_MOTOR_ID, SECOND_MOTOR_PIN_ID, LOGIC_LOW);
		break;
	case CW:
		GPIO_writePin (PORT_MOTOR_ID, FIRST_MOTOR_PIN_ID, LOGIC_LOW);
		GPIO_writePin (PORT_MOTOR_ID, SECOND_MOTOR_PIN_ID, LOGIC_HIGH);
		break;
	case ANTI_CW:
		GPIO_writePin (PORT_MOTOR_ID, FIRST_MOTOR_PIN_ID, LOGIC_HIGH);
		GPIO_writePin (PORT_MOTOR_ID, SECOND_MOTOR_PIN_ID, LOGIC_LOW);
		break;
	}
}
