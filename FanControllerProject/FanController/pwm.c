 /******************************************************************************
 *
 * [FILE NAME]: <pwm.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <02/10/2022>
 *
 * [DESCRIPTION]: <Source file for PWM Driver>
 *
 *******************************************************************************/


#include "common_macros.h"
#include "gpio.h"
#include "pwm.h"
#include <avr/io.h> /* To use the PWM Ports Registers */



/*
 * [NAME]: PWM_Timer0_Start
 *
 * [Description] : Function that responsible for start the duty of pwm in timer0.
 *
 * [Returns]: void
 */
void PWM_Timer0_Start(uint8 duty_cycle)
{
	/* Set timer to 0*/
	TCNT0 =0;

	/*Set Compare Value*/
	OCR0= ((float)duty_cycle / 100) * 255;

	/*Set PB3 as output*/
	GPIO_setupPinDirection (PORTB_ID,PIN3_ID,PIN_OUTPUT);

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM00=1 & WGM01=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 |= (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
