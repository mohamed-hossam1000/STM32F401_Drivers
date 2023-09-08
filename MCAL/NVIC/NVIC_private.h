 /******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_private.h
 *
 * Description: Header file for the NVIC driver private information
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/
#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESS		0xE000E100
#define NVIC                   	((NVIC_t *) NVIC_BASE_ADDRESS)

typedef struct{
	volatile u32 ISER[8];
	u32 RESERVED0[24];
	volatile u32 ICER[8];
	u32 RESWERVED1[24];
	volatile u32 ISPR[8];
	u32 RESWERVED2[24];
	volatile u32 ICPR[8];
	u32 RESWERVED3[24];
	volatile u32 IABR[8];
	u32 RESWERVED4[56];
	volatile u32 IPR[240];
	u32 RESWERVED5[644];
	volatile u32 STIR;
}NVIC_t;


#endif