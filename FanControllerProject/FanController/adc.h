
 /******************************************************************************
 *
 * [FILE NAME]: <adc.h>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <20/09/2022>
 *
 * [DESCRIPTION]: <Header file for the AVR ADC driver>
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"



/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define ADC_MAXIMUM_VALUE           1023
#define ADC_REF_VOLT_VALUE          2.56



/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/


/*
 * [NAME]: ADC_Reference_Selection_Bits
 *
 * [Description] :
 * Select the way ADC_Reference_Selection_Bits is selected
 * 1.AREF : ADC_Reference_Selection_Bits is entered throw and external AREF PIN in micro-controller.
 * 2.AVCC : ADC_Reference_Selection_Bits is the same as AVCC (5v analog).
 * 3.INTERNAL : ADC_Reference_Selection_Bits is 2.56v from internal micro-controller circuit.
 * Done by ADMUX Register.
 */
typedef enum
{
	AREF = 0x00 , AVCC = 0x40 , INTERNAL = 0xC0
} ADC_Reference_Selection_Bits;



/*
 * [NAME]: ADC_Adjust_Result
 *
 * [Description] :
 * Adjust ADC DATA Register right/left in the ADLAR pin by ADMUX Register.
 */
typedef enum
{
	RIGHT = 0x00 , LEFT = 0x20
} ADC_Adjust_Result;


/*
 * [NAME]: ADC_Analog_Channel_and_Gain_Selection_Bits
 *
 * [Description] :
 * Select ADC channel to convert it to digital according to channel number in the MUX4:0 Bits with ADMUX Register.
 */
typedef enum
{
	ADC0 , ADC1 , ADC2 , ADC3 , ADC4 , ADC5 , ADC6 , ADC7
} ADC_Analog_Channel_and_Gain_Selection_Bits;


/*
 * [NAME]: ADC_Enable
 *
 * [Description] :
 * Enable/Disable ADC by ADCSRA Register.
 */
typedef enum
{
	ADCDISABLE = 0x00 , ADCENABLE = 0x80
} ADC_Enable;


/*
 * [NAME]: ADC_Interrupt_Enable
 *
 * [Description] :
 * Select ADC channel to work using polling/interrupt mode by ADCSRA Register.
 */
typedef enum
{
	POLLING = 0x00 , INTERRUPT = 0x08
}  ADC_Interrupt_Enable;


/*
 * [NAME]: ADC_Auto_Trigger_Enable
 *
 * [Description] :
 * Enable/Disable auto-trigger mode by ADATE bit in ADCSRA register
 */
typedef enum
{
	TDISABLE = 0x00 , TENABLE = 0x20
}  ADC_Auto_Trigger_Enable;


/*
 * [NAME]: ADC_Prescaler_SelectBits
 *
 * [Description] :
 * Select ADC clock F_ADC=F_CPU/Prescaler with ADCSRA Register.
 */
typedef enum
{
	F_CPU2 = 0x00 , F_CPU4 = 0x02 , F_CPU8 = 0x03 , F_CPU16 = 0x04 , F_CPU32 = 0x05 , F_CPU64 = 0x06 , F_CPU128 = 0x07
}  ADC_Prescaler_SelectBits;


/*
 * [NAME]: ADC_Auto_Trigger_Source
 *
 * [Description] :
 * Select ADC Auto-Trigger source to of ADC by SFIOR Register.
 */
typedef enum
{
	FreeRunningMode = 0x00 , AnalogComparator = 0x20 , External_Interrupt_Request_0 = 0x40 , Timer_Counter0_Compare_Match = 0x60 ,
	Timer_Counter0_Overflow = 0x80 , Timer_Counter1_Compare_Match_B = 0xA0 ,  Timer_Counter1_Overflow = 0xC0 ,
	Timer_Counter1_Capture_Event = 0xE0
}  ADC_Auto_Trigger_Source;


/*
 * [NAME]: ADC_ConfigType
 *
 * [Description] :
 * Structure variable passed to ADC_init function as parameter in order to make the ADC_init function configurable
 */
typedef struct
{
	ADC_Reference_Selection_Bits ref;
	ADC_Adjust_Result adjust;
	ADC_Enable enable;
	ADC_Interrupt_Enable ienable;
	ADC_Auto_Trigger_Enable tenable;
	ADC_Prescaler_SelectBits prescaler;
	ADC_Auto_Trigger_Source tsource;
} ADC_ConfigType;



/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*
 * [NAME]: ADC_init
 *
 * [Description] : Function that takes adc config pointer and initialize the adc as needed
 *
 * [Returns]: void
 */
void ADC_init(const ADC_ConfigType * Config_Ptr);



/*
 * [NAME]: ADC_readChannel
 *
 * [Description] : Function responsible for read analog data from a certain ADC channel using polling
 *
 * [Returns]: ADC
 */
uint16 ADC_readChannel(uint8 ch_num);

#endif /* ADC_H_ */
