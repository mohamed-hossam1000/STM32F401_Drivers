 /******************************************************************************
 *
 * Module: SCB
 *
 * File Name: SCB_interface.h
 *
 * Description: Header file for the System Control Bock driver user interface
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef SCB_INTERFACE_H_
#define SCB_INTERFACE_H_

#define GROUP_16_SUB_0		0x000
#define GROUP_8_sub_2		0x100
#define GROUP_4_sub_4		0x101
#define GROUP_2_sub_8		0x110
#define GROUP_0_sub_16		0x111


void SCB_vSetPriorityGrouping(u8 Copy_u8Grouping);


#endif