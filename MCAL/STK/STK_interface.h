 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: STK_interface.h
 *
 * Description: Header file for the Systick timer driver user interface
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

extern volatile u32 g_u32SystemTickCount;

void STK_vInit(u32 Copy_u32Ticks);
void STK_vDelay(u32 Copy_u32Milliseconds);

#endif
