/******************************************************************************	 
*	 
* Module: UART6	 
*	 
* File Name: UART6_private.h	 
*	 
* Description: Header file for the UART6 driver private information	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef UART6_PRIVATE_H_	 
#define UART6_PRIVATE_H_


#define UART6_BASE_ADDRESS			0x40011400
#define UART6 						((UART_t *) UART6_BASE_ADDRESS)

typedef struct{
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 BRR;
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 CR3;
	volatile u32 GTPR;
}UART_t;


#define DIV_Mantissa 	4
/* UART_SR bits */
#define RXNE			5
#define TXE				7

/* UART_CR1 bits */
#define RE 				2
#define TE 				3
#define RXNEIE			5
#define PS 				9
#define	M 				12
#define UE 				13

/* UART_CR2 bits */
#define STOP			12

#define PSC_NORMAL_MODE	1	
	 
#endif