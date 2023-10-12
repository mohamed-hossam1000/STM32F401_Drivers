/******************************************************************************	 
*	 
* Module: SPI	 
*	 
* File Name: SPI_private.h	 
*	 
* Description: Header file for the SPI driver private information	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef SPI_PRIVATE_H_	 
#define SPI_PRIVATE_H_

#define SPI1_BASE_ADDRESS				0x40013000
#define SPI1 							((SPI_t *)SPI1_BASE_ADDRESS)

typedef struct{
	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;
}SPI_t;


/* SPI_CR1 bits */
#define MSTR		2
#define BR 			3
#define SPE 		6
#define LSBFIRST	7
#define DFF			11

/* SPI_CR2 bits */
#define SSOE		2
#define FRF 		4

/*SPI_SR bits*/
#define RXNE		0
#define TXE			1

	 
#endif