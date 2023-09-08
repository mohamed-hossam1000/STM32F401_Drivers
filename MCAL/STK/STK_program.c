 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: STK_program.c
 *
 * Description: Source file for the Systick timer driver
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#include"STK_interface.h"
#include"STK_private.h"
#include"STK_config.h"

volatile u32 g_u32SystemTickCount = 0;

void SysTick_Handler(void) {
    g_u32SystemTickCount++;
}

void STK_vInit(u32 Copy_u32Ticks) {
    STK->LOAD = Copy_u32Ticks - 1;
    STK->VAL = 0;
    STK->CTRL = (1 << ENABLE) | (1 << TICKINT);
    #if(STK_CLK_SRC == AHB_CLK)
    	STK->CTRL |= (1 << CLKSOURCE);

    #elif(STK_CLK_SRC == AHB_CLK_8)
    	/* already set */
   		/* Do Nothing */
    #else
    	#warning"Systick clock not selected. Default option applied AHB_CLK / 8 "
    #endif
}

void STK_vDeInit()
{
    STK->LOAD = 0;
    STK->CTRL = 0;
}

void STK_vDelay(u32 Copy_u32Milliseconds) {
    u32 L_u32startTick = g_u32SystemTickCount;
    
    while ((g_u32SystemTickCount - L_u32startTick) < Copy_u32Milliseconds);
}
