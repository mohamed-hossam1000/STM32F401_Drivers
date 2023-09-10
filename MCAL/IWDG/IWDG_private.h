/******************************************************************************	 
*	 
* Module: IWDG	 
*	 
* File Name: IWDG_private.h	 
*	 
* Description: Header file for the IWDG driver private information	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef IWDG_PRIVATE_H_	 
#define IWDG_PRIVATE_H_


#define IWDG_BASE_ADDRESS			0x40003000
#define IWDG 						((IWDG_t *) IWDG_BASE_ADDRESS)

typedef struct{
	volatile u32 KR;
	volatile u32 PR;
	volatile u32 RLR;
	volatile u32 SR;
}IWDG_t;

/* IWDG_KR keys */
#define MODIFY_KEY		0x5555
#define START_KEY		0xCCCC
#define RELOAD_KEY		0xAAAA

/* IWDG_SR bits */
#define PVU				0
#define RVU				1

#endif