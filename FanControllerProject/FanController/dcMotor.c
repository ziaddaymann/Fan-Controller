 /******************************************************************************
 *
 * [FILE NAME]: <dcMotor.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <02/10/2022>
 *
 * [DESCRIPTION]: <Source file for DC Motor driver>
 *
 *******************************************************************************/


#include "common_macros.h"
#include "gpio.h"
#include "dcMotor.h"




/*
 * [NAME]: DcMotor_Init
 *
 * [Description] : Function that setup the direction for the two motor pins through the GPIO driver.
 *
 * [Returns]: void
 */
void DcMotor_Init(void)
{
	/*Set motor pins as output pins*/
	GPIO_setupPinDirection (PORTB_ID,PIN0_ID,PIN_OUTPUT);
	GPIO_setupPinDirection (PORTB_ID,PIN1_ID,PIN_OUTPUT);



	/*Stop the motor at first*/
	GPIO_writePin (PORTB_ID,PIN0_ID,LOGIC_LOW);
	GPIO_writePin (PORTB_ID,PIN1_ID,LOGIC_LOW);

}





/*
 * [NAME]: DcMotor_Rotate
 *
 * [Description] : Function that responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *
 * [Returns]: void
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed)
{
	/*Start PWM timer to control the fan speed*/
	PWM_Timer0_Start (speed);

	if (state == STOP)
	{
		/*Stop the motor*/
		GPIO_writePin (PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin (PORTB_ID,PIN1_ID,LOGIC_LOW);
	}

	else if (state == CLOCKWISE)
	{
		/*Rotate Clockwise*/
		GPIO_writePin (PORTB_ID,PIN0_ID,LOGIC_LOW);
		GPIO_writePin (PORTB_ID,PIN1_ID,LOGIC_HIGH);
	}

	else if (state == ANTICLOCKWISE)
	{
		/*Rotate AntiClockwise*/
		GPIO_writePin (PORTB_ID,PIN0_ID,LOGIC_HIGH);
		GPIO_writePin (PORTB_ID,PIN1_ID,LOGIC_LOW);
	}
}
