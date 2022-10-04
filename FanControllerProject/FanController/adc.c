 /******************************************************************************
 *
 * [FILE NAME]: <adc.c>
 *
 * [AUTHOR]: <Ziad Ayman>
 *
 * [DATE CREATED]: <20/09/2022>
 *
 * [DESCRIPTION]: <Source file for the AVR ADC driver>
 *
 *******************************************************************************/


#include "common_macros.h"
#include "adc.h"
#include <avr/io.h> /* To use the ADC Ports Registers */




/*
 * [NAME]: ADC_init
 *
 * [Description] : Function that takes adc config pointer and initialize the adc as needed
 *
 * [Returns]: void
 */
void ADC_init(const ADC_ConfigType * Config_Ptr)
{
	ADMUX |= Config_Ptr->ref | Config_Ptr->adjust;
	ADCSRA |= Config_Ptr->enable | Config_Ptr->ienable | Config_Ptr->prescaler | Config_Ptr->tenable;
	SFIOR |= Config_Ptr->tsource;
}




/*
 * [NAME]: ADC_readChannel
 *
 * [Description] : Function responsible for read analog data from a certain ADC channel using polling
 *
 * [Returns]: ADC
 */
uint16 ADC_readChannel(uint8 ch_num)
{
	/*Channel from 0 -> 7 only*/
	ch_num &= 0x07;

	/* Clear first five bits*/
	ADMUX &= 0xE0;

	/*Set the channel*/
	ADMUX |= ch_num;

	/*Star Converstion*/
	SET_BIT (ADCSRA,ADSC);

	/*Use Polling intil the flag =1*/
	while (BIT_IS_CLEAR (ADCSRA,ADIF));

	/* Clear the flag*/
	SET_BIT (ADCSRA,ADIF);


	return ADC;
}
