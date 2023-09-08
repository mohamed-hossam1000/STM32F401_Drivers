 /******************************************************************************
 *
 * Module: SCB
 *
 * File Name: SCB_private.h
 *
 * Description: Header file for the System Control Bock driver private information
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef SCB_PRIVARE_H_
#define SCB_PRIVATE_H_

#define SCB_BASE_ADDRESS		0xE000ED00
#define SCB 					((SCB_t *) SCB_BASE_ADDRESS)

#define SCB_AIRCR_KEY				0x05FA

typedef struct{
	volatile u32 CPUID;
	volatile u32 ICSE
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCRS;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMAR;
	volatile u32 BFAR;
	volatile u32 AFSR;
}SCB_t;


#endif