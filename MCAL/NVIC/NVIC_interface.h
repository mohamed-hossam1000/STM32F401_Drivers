 /******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_interface.h
 *
 * Description: Header file for the NVIC driver user interface
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/
#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/*******************************************************************************
 * 								  	Definitions
 *******************************************************************************/
#define ACTIVE 		1
#define INACTIVE	0

/*******************************************************************************
 * 								Functions Prototypes
 *******************************************************************************/

void NVIC_voidEnableIRQ(u8 Copy_u8IRQn);

void NVIC_voidDisableIRQ(u8 Copy_u8IRQn);

void NVIC_voidSetPendingIRQ(u8 Copy_u8IRQn);

void NVIC_voidClearPendingIRQ(u8 Copy_u8IRQn);

u8 NVIC_u8GetActive(u8 Copy_u8IRQn);

void NVIC_voidSetPriority(u8 Copy_u8IRQn, u8 Copy_u8Priority);

#endif