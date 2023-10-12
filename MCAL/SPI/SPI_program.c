/******************************************************************************	 
*	 
* Module: SPI	 
*	 
* File Name: SPI_program.c	 
*	 
* Description: Source file for the SPI driver	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#include"../STD_TYPES.h"
#include"SPI_interface.h"	 
#include"SPI_private.h"	 
#include"SPI_config.h"


/*
 * Description :
 * initializing the SPI module in master mode
 * full dublex
 * MSB first
 * CRC disabled
 * CPOL = 0, CPHA = 0
 */ 
void SPI_vInitMaster(const SPI_ConfigType *config)
{
	SPI1->CR2 = (1 << SSOE);
	SPI1->CR1 = (1 << MSTR) | (config->clk << BR) | (config->frameFormat << DFF) | (1 << SPE);
}

/*
 * Description :
 * initializing the SPI module in slave mode
 * full dublex
 * MSB first 
 * CRC disabled
 * CPOL = 0, CPHA = 0
 */
void SPI_vInitSlave(SPI_frameFormat Copy_format)
{
	SPI1->CR1 = (Copy_format << DFF) | (1 << SPE);
}


/*
 * Description :
 * send and receive Data at the same time
 */
u16 SPI_u16SendReceiveData(u16 Copy_u16Data)
{
	SPI1->DR = Copy_u16Data;
	while(!(SPI1->SR & (1 << TXE)));
	return SPI1->DR;
}
