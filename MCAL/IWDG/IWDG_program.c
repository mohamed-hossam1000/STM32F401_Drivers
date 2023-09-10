/******************************************************************************	 
*	 
* Module: IWDG	 
*	 
* File Name: IWDG_program.c	 
*	 
* Description: Source file for the IWDG driver	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#include"STD_TYPES.h"	 
#include"IWDG_interface.h"	 
#include"IWDG_private.h"	 
#include"IWDG_config.h"

void IWDG_vinit(IWDG_Prescaler Copy_prescaler, u16 Copy_u16ReloadValue)
{
	IWDG->KR = MODIFY_KEY;
	IWDG->PR = (Copy_prescaler);
	IWDG->RLR = (Copy_u16ReloadValue);
	IWDG->KR = START_KEY;
}

void IWDG_vReload()
{
	IWDG_KR->KR = RELOAD_KEY;
}

void IWDG_vChangePrescaler(IWDG_Prescaler Copy_prescaler)
{
	while(IWDG->SR & (1 << PVU));
	IWDG->KR = MODIFY_KEY;
	IWDG->PR = (Copy_prescaler);
}

void IWDG_vChangeReloadValue(u16 Copy_u16ReloadValue)
{
	while(IWDG->SR & (1 << RVU));
	IWDG->KR = MODIFY_KEY;
	IWDG->RLR = (Copy_u16ReloadValue);
}