 /******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_interface.h
 *
 * Description: Header file for the External interrupts driver user interface
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

/*******************************************************************************
 * 								  	Definitions
 *******************************************************************************/

#define MASKED				0
#define NOT_MASKED			1

#define CLEAR_TRIGGER		0
#define SET_TRIGGER 		1

/*******************************************************************************
 * 								Functions Prototypes
 *******************************************************************************/

void EXTI_vSelectInterruptMask(u8 Copy_u8InterruptNum, u8 Copy_u8Mask);

void EXTI_vSelectEventMask(u8 Copy_u8InterruptNum, u8 Copy_u8Mask);

void EXTI_vSelectRisingTrigger(u8 Copy_u8InterruptNum, u8 Copy_u8Trigger);

void EXTI_vSelectFallingTrigger(u8 Copy_u8InterruptNum, u8 Copy_u8Trigger);

void EXTI_vSetInterruptEvent(u8 Copy_u8InterruptNum);

void EXTI_vClearPendingInterrupt(u8 Copy_u8InterruptNum);

void EXTI_vSelectInterruptSource(u8 Copy_u8InterruptNum, u8 Copy_u8Port);

#endif