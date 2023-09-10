/******************************************************************************	 
*	 
* Module: IWDG	 
*	 
* File Name: IWDG_interface.h	 
*	 
* Description: Header file for the IWDG driver user interface	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef IWDG_INTERFACE_H_	 
#define IWDG_INTERFACE_H_

/******************************************************************************
 * 								Types Declaration
 * ****************************************************************************/
typedef enum{
	LSI_4, LSI_8, LSI_16, LSI_32, LSI_64, LSI_128, LSI_256
}IWDG_Prescaler;

/******************************************************************************
 * 							   Functions Prototypes
 * ****************************************************************************/

void IWDG_vInit(IWDG_Prescaler Copy_prescaler, u16 Copy_u16ReloadValue);

void IWDG_vReload();

void IWDG_vChangePrescaler(IWDG_Prescaler Copy_prescaler);

void IWDG_vChangeReloadValue(u16 Copy_u16ReloadValue);

#endif
