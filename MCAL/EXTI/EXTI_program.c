 /******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_program.c
 *
 * Description: Source file for the External interrupts driver
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#include"STD_TYPES.h"

#include"EXTI_interface.h"
#include"EXTI_private.h"


void EXTI_vSelectInterruptMask(u8 Copy_u8InterruptNum, u8 Copy_u8Mask)
{
	if(Copy_u8Mask == NOT_MASKED)
	{
		EXTI->IMR |= (1 << Copy_u8InterruptNum);
	}
	else if(Copy_u8Mask == MASKED)
	{
		EXTI->IMR &= ~(1 << Copy_u8InterruptNum);
	}
	else
	{
		/* ERROR */
	}
}

void EXTI_vSelectEventMask(u8 Copy_u8InterruptNum, u8 Copy_u8Mask)
{
	if(Copy_u8Mask == NOT_MASKED)
	{
		EXTI->EMR |= (1 << Copy_u8InterruptNum);
	}
	else if(Copy_u8Mask == MASKED)
	{
		EXTI->EMR &= ~(1 << Copy_u8InterruptNum);
	}
	else
	{
		/* ERROR */
	}
}

void EXTI_vSelectRisingTrigger(u8 Copy_u8InterruptNum, u8 Copy_u8Trigger)
{
	if(Copy_u8Trigger == SET_TRIGGER)
	{
		EXTI->RTSR |= (1 << Copy_u8InterruptNum);
	}
	else if(Copy_u8Trigger == CLEAR_TRIGGER)
	{
		EXTI->RTSR &= ~(1 << Copy_u8InterruptNum);
	}
	else
	{
		/* ERROR */
	}	
}

void EXTI_vSelectFallingTrigger(u8 Copy_u8InterruptNum, u8 Copy_u8Trigger)
{
	if(Copy_u8Trigger == SET_TRIGGER)
	{
		EXTI->FTSR |= (1 << Copy_u8InterruptNum);
	}
	else if(Copy_u8Trigger == CLEAR_TRIGGER)
	{
		EXTI->FTSR &= ~(1 << Copy_u8InterruptNum);
	}
	else
	{
		/* ERROR */
	}		
}

void EXTI_vSetInterruptEvent(u8 Copy_u8InterruptNum)
{
	EXTI->SWIER |= (1 << Copy_u8InterruptNum);
}

void EXTI_vClearPendingInterrupt(u8 Copy_u8InterruptNum)
{
	EXTI->PR |= (1 << Copy_u8InterruptNum);
}

void EXTI_vSelectInterruptSource(u8 Copy_u8InterruptNum, u8 Copy_u8Port)
{
	u8 L_regNum = Copy_u8InterruptNum >> 2, u8 L_bitNumber = (Copy_u8InterruptNum & 3) * 4;
	SYSCFG_EXTICR(L_regNum) = (SYSCFG_EXTICR(L_regNum) & ~(15 << L_bitNumber)) | (1 << Copy_u8Port); 
}