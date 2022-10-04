 /******************************************************************************
 *
 * [FILE NAME]: <dcMotor.h>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <02/10/2022>
 *
 * [DESCRIPTION]: <Header file for DC Motor driver>
 *
 *******************************************************************************/

#ifndef DCMOTOR_H_
#define DCMOTOR_H_

#include "std_types.h"



/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/

/*
 * [NAME]: DcMotor_State
 *
 * [Description] :
 * Select the state of the DC motor
 */
typedef enum
{
	STOP , CLOCKWISE , ANTICLOCKWISE
}DcMotor_State;




/*******************************************************************************
 *                         Function Prototypes                                 *
 *******************************************************************************/

/*
 * [NAME]: DcMotor_Init
 *
 * [Description] : Function that setup the direction for the two motor pins through the GPIO driver.
 *
 * [Returns]: void
 */
void DcMotor_Init(void);


/*
 * [NAME]: DcMotor_Rotate
 *
 * [Description] : Function that responsible for rotate the DC Motor CW/ or A-CW or stop the motor based on the state input state value.
 *
 * [Returns]: void
 */
void DcMotor_Rotate(DcMotor_State state,uint8 speed);

#endif /* DCMOTOR_H_ */
