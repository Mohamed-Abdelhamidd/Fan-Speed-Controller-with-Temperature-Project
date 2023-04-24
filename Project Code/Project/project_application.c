/*-----------------------------------------------------------------------------------------------
 * Module	  : PROJECT APPLICATION
 *
 * File Name  : project_application.c
 *
 * Description: Source file for PROJECT APPLICATION
 *
 * Author	  : Mohamed Abdelhamid Sayed
 * ---------------------------------------------------------------------------------------------*/

#include "adc.h"
#include "pwm.h"
#include "lcd.h"
#include "dc_motor.h"
#include "lm35_temp_sensor.h"
#include <util/delay.h>

void modifyScreen (uint8 temp);	/*Prototype number Digits adjust function for LCD */

int main (void)
{
	uint8 temp_value = 0;	/*to take sensor read value*/

	ADC_configType ADC_config = {INTERNAL, PRE_8}; /*ADC volt ref. mode and prescaler struct */

	DcMotor_Init ();
	LCD_init ();
	ADC_init (&ADC_config);

	/*screen display settings*/
	LCD_moveCursor(0,0);
	LCD_displayString ("Mini Project III");
	LCD_moveCursor(1,2);
	LCD_displayString ("Loading...");
	_delay_ms (500);
	LCD_moveCursor(1,2);
	LCD_displayString ("Loading....");
	_delay_ms (500);
	LCD_moveCursor(1,2);
	LCD_displayString ("Loading... ");
	_delay_ms (500);
	LCD_moveCursor(1,2);
	LCD_displayString ("Loading....");
	_delay_ms (500);
	LCD_clearScreen();

	LCD_moveCursor(0,3);
	LCD_displayString ("FAN is OFF");
	LCD_moveCursor(1,2);
	LCD_displayString ("Temp =    C");

	for (;;)
	{
		temp_value =  LM35_getTemperature ();

		if((temp_value >= 0) && (temp_value < 30))
		{
			DcMotor_Rotate(STOP,0); /*Motor state and speed*/
			LCD_moveCursor(0,10);
			LCD_displayString ("OFF");
			modifyScreen (temp_value);
		}
		else if ((temp_value >= 30) && (temp_value < 60))
		{
			DcMotor_Rotate(CW,25); /*Motor state and speed*/
			LCD_moveCursor(0,10);
			LCD_displayString ("ON ");
			modifyScreen (temp_value);

		}
		else if ((temp_value >= 60) && (temp_value < 90))
		{
			DcMotor_Rotate(CW,50); /*Motor state and speed*/
			LCD_moveCursor(0,10);
			LCD_displayString ("ON ");
			modifyScreen (temp_value);


		}
		else if ((temp_value >= 90) && (temp_value < 120))
		{
			DcMotor_Rotate(CW,75); /*Motor state and speed*/
			LCD_moveCursor(0,10);
			LCD_displayString ("ON ");
			modifyScreen (temp_value);
		}
		else if (temp_value >= 120)
		{
			DcMotor_Rotate(CW,100); /*Motor state and speed*/
			LCD_moveCursor(0,10);
			LCD_displayString ("ON ");
			modifyScreen (temp_value);
		}
	}
}

/*adjust function for LCD settings for 3,2, and 1 digit numbers*/
void modifyScreen (uint8 temp)
{
	if ((temp < 10) && (temp >= 0)){
		LCD_moveCursor(1,9);
		LCD_intgerToString(temp);
		LCD_moveCursor(1,10);
		LCD_displayString ("  ");

	}
	else if ((temp < 100) && (temp >= 10)){
		LCD_moveCursor(1,9);
		LCD_intgerToString(temp);
		LCD_moveCursor(1,11);
		LCD_displayCharacter(' ');
	}
	else if (temp >= 100){
		LCD_moveCursor(1,9);
		LCD_intgerToString(temp);
	}

}
