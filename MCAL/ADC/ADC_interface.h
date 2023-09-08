/******************************************************************************	 
*	 
* Module: ADC	 
*	 
* File Name: ADC_interface.h	 
*	 
* Description: Header file for the ADC driver user interface	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef ADC_INTERFACE_H_	 
#define ADC_INTERFACE_H_


/*******************************************************************************
  								Types Declaration
 ******************************************************************************/
typedef enum{
	TWELVE_BIT, TEN_BIT, EIGHT_BIT, SIX_BIT
}ADC_Resolution;

typedef enum{
	PCLK2_2, PCLK2_4, PCLK2_6, PCLK2_8
}ADC_Prescaler;

typedef struct{
	ADC_Resolution 	res;
	boolean  	 	scanMode;
	boolean			singleConvFlag;
	boolean			contConv;
	ADC_Prescaler	prescaler;
}ADC_ConfigType;
/*******************************************************************************
  							   Functions Prototypes
 ******************************************************************************/

void ADC_vInit(const ADC_ConfigType* Ptr_config);

#endif