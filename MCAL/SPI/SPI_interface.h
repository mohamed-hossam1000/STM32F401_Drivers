/******************************************************************************	 
*	 
* Module: SPI	 
*	 
* File Name: SPI_interface.h	 
*	 
* Description: Header file for the SPI driver user interface	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef SPI_INTERFACE_H_	 
#define SPI_INTERFACE_H_

/*******************************************************************************
 * 								Type Declarations
 *******************************************************************************/
typedef enum{
	CLK_2, CLK_4, CLK_8, CLK_16, CLK_32, CLK_64, CLK_128, CLK_256
}SPI_clock;

typedef enum{
	EIGHT_BITS, SIXTEEN_BITS 
}SPI_frameFormat;

typedef struct{
	SPI_clock			clk;
	SPI_frameFormat		frameFormat;

}SPI_ConfigType;
/*******************************************************************************
 * 							   Functions Prototypes
 *******************************************************************************/
/*
 * Description :
 * initializing the SPI module in master mode
 * full dublex
 * MSB first 
 * CRC disabled
 * CPOL = 0, CPHA = 0
 */ 
void SPI_vInitMaster(const SPI_ConfigType *config);

/*
 * Description :
 * initializing the SPI module in slave mode
 * full dublex
 * MSB first 
 * CRC disabled
 * CPOL = 0, CPHA = 0
 */
void SPI_vInitSlave(SPI_frameFormat Copy_format);

/*
 * Description :
 * send and receive Data at the same time
 */
u16 SPI_u16SendReceiveData(u16 Copy_u16Data);
#endif