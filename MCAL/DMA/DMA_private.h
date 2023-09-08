/******************************************************************************	 
*	 
* Module: DMA	 
*	 
* File Name: DMA_private.h	 
*	 
* Description: Header file for the DMA driver private information	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef DMA_PRIVATE_H_	 
#define DMA_PRIVATE_H_

#define DMA1_BASE_ADDRESS				0x40026000
#define DMA2_BASE_ADDRESS  				0x40026400
#define DMA1 							((DMA_t *) DMA1_BASE_ADDRESS)
#define DMA2 							((DMA_t *) DMA2_BASE_ADDRESS)

typedef struct{
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;
}DMA_stream_t;

typedef struct{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	DMA_stream_t stream[8]; 
}DMA_t;

	 
/* DMA_SxCR bits */
#define EN 		0
#define DMEIE	1
#define TEIE	2
#define HTIE	3
#define TCIE	4
#define DIR 	6
#define CIRC 	8
#define PINC	9
#define MINC	10
#define PSIZE	11
#define MSIZE	13
#define PL		16
#define	PBURST	21
#define MBURST	23
#define CHSEL	25

/* (DMA_SxFCR bits */
#define FTH		0
#define DMDIS 	2


#endif
