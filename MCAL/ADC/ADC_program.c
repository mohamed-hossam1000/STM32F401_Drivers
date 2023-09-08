/******************************************************************************	 
*	 
* Module: ADC	 
*	 
* File Name: ADC_program.c	 
*	 
* Description: Source file for the ADC driver	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#include"STD_TYPES.h"	 
#include"ADC_interface.h"	 
#include"ADC_private.h"	 
#include"ADC_config.h"


void ADC_vInit(const ADC_ConfigType* Ptr_config)
{
	/* Choose resolution and set scan mode */
	ADC->CR1 = (Ptr_config.res << RES) | (Ptr_config.scanMode << SCAN);
	/* Set clock Prescaler for ADC */
	ADC_CCR = (ADC_CCR & ~ADCPRE_MASK) | ((Ptr_config.prescaler << ADCPRE) & ADCPRE_MASK); 
	/* configure End of conversion selection and continuous mode and Enable ADC  */
	ADC->CR2 = (Ptr_config.singleConvFlag << ECOS) | (Ptr_config.contConv << CONT) | (1 << ADON);

	ADC->SQR1 &= ~(0xF << L);
	ADC->SQR3 = 1;
}

u16 ADC_vRead()
{
	ADC->CR2 |= (1 << SWSTART);
	while(!(ADC->SR & (1 << EOC)));
	return ADC->DR;
}