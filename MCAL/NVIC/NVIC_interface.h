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

void NVIC_vEnableIRQ(u8 Copy_u8IRQn);

void NVIC_vDisableIRQ(u8 Copy_u8IRQn);

void NVIC_vSetPendingIRQ(u8 Copy_u8IRQn);

void NVIC_vClearPendingIRQ(u8 Copy_u8IRQn);

u8 NVIC_u8GetActive(u8 Copy_u8IRQn);

void NVIC_vSetPriority(u8 Copy_u8IRQn, u8 Copy_u8Priority);

#endif