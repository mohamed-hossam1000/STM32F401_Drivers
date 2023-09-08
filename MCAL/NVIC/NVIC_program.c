 /******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_program.c
 *
 * Description: source file for the NVIC drive
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/
#include"NVIC_interface.h"
#include"NVIC_private.h"


void NVIC_voidEnableIRQ(u8 Copy_u8IRQn)
{
	NVIC->ISER[(Copy_u8IRQn >> 5)] = (1 << (Copy_u8IRQn & 31));
}

void NVIC_voidDisableIRQ(u8 Copy_u8IRQn)
{
	NVIC->ICER[(Copy_u8IRQn >> 5)] = (1 << (Copy_u8IRQn & 31));
}

void NVIC_voidSetPendingIRQ(u8 Copy_u8IRQn)
{
	NVIC->ISPR[(Copy_u8IRQn >> 5)] = (1 << (Copy_u8IRQn & 31));
}

void NVIC_voidClearPendingIRQ(u8 Copy_u8IRQn)
{
	NVIC->ICPR[(Copy_u8IRQn >> 5)] = (1 << (Copy_u8IRQn & 31));
}

u8 NVIC_u8GetActive(u8 Copy_u8IRQn)
{
	return (NVIC->ICPR[(Copy_u8IRQn >> 5)] & (1 << (Copy_u8IRQn & 31))) ? ACTIVE : INACTIVE;
}

void NVIC_voidSetPriority(u8 Copy_u8IRQn, u8 Copy_u8Priority)
{
	NVIC->IPR[Copy_u8IRQn] = (Copy_u8Priority << 4);
}