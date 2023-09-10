/******************************************************************************	 
*	 
* Module: UART6	 
*	 
* File Name: UART6_interface.h	 
*	 
* Description: Header file for the UART6 driver user interface	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef UART6_INTERFACE_H_	 
#define UART6_INTERFACE_H_

/*******************************************************************************
 * 									Types Declarations
 *******************************************************************************/
typedef enum{
	DISABLED=0, EVEN_PARIT=2, ODD_PARITY=3
}UART_parityMode;

typedef enum{
	ONE_BIT, HALF_BIT, TWO_BITS, ONE_HALF_BITS
}UART_NO_OF_STOP_BITS;

typedef enum{
	EIGHT_BITS, NINE_BITS
}UART_wordLength;

typedef struct{
	u32 		   		 baudRate;
	UART_wordLength		 wordLength;
	UART_parityMode 	 parity;
	UART_NO_OF_STOP_BITS stop_bits;
}UART_ConfigType;

/*******************************************************************************
 * 									Functions Prototypes
 *******************************************************************************/

void UART6_vInit(const UART_ConfigType* Ptr_config);

void UART6_vSendByte(u8 Copy_u8Data);

void UART6_vSetCallBack(void (*Ptr_func)(void));

u8 UART6_u8ReadByte();
	 
#endif
