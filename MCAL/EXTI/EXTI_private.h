 /******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_private.h
 *
 * Description: Header file for the External interrupts driver private information
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H


#define EXTI_BASE_ADDRESS 			0x40013C00
#define SYSCFG_EXTICR1_ADDRESS		0x40013808
#define SYSCFG_EXTICR(REG_NUMBER)	*((volatile u32*)(0x40013808 + ((REG_NUMBER) * 4)))

#define EXTI 						((EXTI_t *) EXTI_BASE_ADDRESS)
#define 

typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_t;

#endif