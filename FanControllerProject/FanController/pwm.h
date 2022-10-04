 /******************************************************************************
 *
 * [FILE NAME]: <pwm.h>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <02/10/2022>
 *
 * [DESCRIPTION]: <Header file for PWM Driver>
 *
 *******************************************************************************/

#ifndef PWM_H_
#define PWM_H_

#include "std_types.h"



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*
 * [NAME]: PWM_Timer0_Start
 *
 * [Description] : Function that responsible for start the duty of pwm in timer0.
 *
 * [Returns]: void
 */
void PWM_Timer0_Start(uint8 duty_cycle);


#endif /* PWM_H_ */
