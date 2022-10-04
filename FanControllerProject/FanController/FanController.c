 /******************************************************************************
 *
 * [FILE NAME]: <FanController.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <02/10/2022>
 *
 * [DESCRIPTION]: <Fan Controlled System Using AVR Atmega32>
 *
 *******************************************************************************/


#include "adc.h"
#include "dcMotor.h"
#include "lcd.h"
#include "lm35_sensor.h"
#include "pwm.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


/*
 * [NAME]: FAN_STATE
 *
 * [Description] :
 * Turn of or off the fan.
 */
typedef enum
{
	OFF , ON
} FAN_STATE;


/*******************************************************************************
 *                               Main Function                             *
 *******************************************************************************/
int main()
{
	uint8 tempreture = 0;
	FAN_STATE fanstate;

	/* Set configuration structure for ADC driver */
	ADC_ConfigType config = {INTERNAL , RIGHT , ADCENABLE , POLLING , TDISABLE , F_CPU8 , FreeRunningMode};

	/* initialize LCD driver */
	LCD_init();
	/* initialize ADC driver */
	ADC_init (&config);
	/* initialize DC MOTOR driver */
	DcMotor_Init();

	/* display on LCD */
	LCD_displayStringRowColumn (0,4, "FAN IS");
	LCD_displayStringRowColumn (1,4, "TEMP = ");

	while (1)
	{
		/*Get the sensor temperature reading*/
		tempreture = LM35_getTemperature();

		/* Display fan ON or OFF */
		if (fanstate == OFF)
		{
			LCD_displayStringRowColumn (0,11, "OFF");

		}

		else if (fanstate == ON)
		{
			LCD_displayStringRowColumn (0,11, "ON");
		}




		/* Rotate/Stop motor based on temperature value */
		if (tempreture < 30)
		{
			fanstate = OFF;
			DcMotor_Rotate (STOP , 0);

		}

		else
		{
			fanstate = ON;
			LCD_displayCharacter(' ');
			if ((tempreture < 60) && (tempreture >= 30))
			{
				/*Rotate motor 25% speed*/
				DcMotor_Rotate (CLOCKWISE , 25);
		    }

			else if ((tempreture < 90) && (tempreture >= 60))
			{
				/*Rotate motor 50% speed*/
				DcMotor_Rotate (CLOCKWISE , 50);
			}

			else if ((tempreture < 120) && (tempreture >= 90))
			{
				/*Rotate motor 75% speed*/
				DcMotor_Rotate (CLOCKWISE , 75);
			}

			else if (tempreture >= 120)
			{
				/*Rotate motor 100% speed*/
				DcMotor_Rotate (CLOCKWISE , 100);
			}
		}

		/* Display temperature value */
		LCD_moveCursor(1,11);
		if(tempreture >= 100)
		{
			LCD_intgerToString(tempreture);
		}
		else
		{
			LCD_intgerToString(tempreture);
			LCD_displayCharacter(' ');
		}
	}



}
