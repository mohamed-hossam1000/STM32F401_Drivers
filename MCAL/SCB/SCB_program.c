 /******************************************************************************
 *
 * Module: SCB
 *
 * File Name: SCB_program.c
 *
 * Description: Source file for the System Control Bock driver
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#include"../STD_TYPES.h"

#include"SCB_interface.h"
#include"SCB_private.h"


void SCB_vSetPriorityGrouping(u8 Copy_u8Grouping)
{
	u32 L_u32Temp = SCB->AIRCR & ~((u32)0xFFFF << 16) & ~((u32)0x07 << 8);
	L_u32Temp |= (SCB_AIRCR_KEY << 16) | (Copy_u8Grouping << 8);
	SCB->AIRCR = L_u32Temp;
}
