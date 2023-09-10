/******************************************************************************	 
*	 
* Module: UART6	 
*	 
* File Name: UART6_program.c	 
*	 
* Description: Source file for the UART6 driver	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#include"../STD_TYPES.h"
#include"UART6_interface.h"	 
#include"UART6_private.h"	 
#include"UART6_config.h"

static void (*g_callBack) (void);

void UART6_IRQHandler()
{
	(*g_callBack)();
	UART6->SR &= ~(1 << RXNE);
}

void UART6_vInit(const UART_ConfigType* Ptr_config)
{
	if(NULL != Ptr_config)
	{
		/* set prescaler */
		UART6->GTPR = PSC_NORMAL_MODE;
		/* set baud rate */
		UART6->BRR = ((F_CK / (Ptr_config->baudRate * 16)) << DIV_Mantissa);
		/* select frame characteristics
		 * stop bits, word length and parity
		 */
		UART6->CR2 = (Ptr_config->stop_bits << STOP);
		UART6->CR1 = (Ptr_config->wordLength << M) | (Ptr_config->parity << PS);
		/* enable UART */
		UART6->CR1 |= (1 << UE) | (1 << RE) | (1 << TE);
		/* enable receive interrupt */
		UART6->CR1 |= (1 << RXNEIE);
	}

}

void UART6_vSendByte(u8 Copy_u8Data)
{
	while(!(UART6->SR & (1 << TXE)));
	UART6->DR = Copy_u8Data;
}

void UART6_vSetCallBack(void (*Ptr_func)(void))
{
	if(NULL != NULL)
	{
		g_callBack = Ptr_func;
	}
}

u8 UART6_u8ReadByte()
{
	return UART6->DR;
}
