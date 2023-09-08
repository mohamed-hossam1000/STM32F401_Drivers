/******************************************************************************	 
*	 
* Module: DMA	 
*	 
* File Name: DMA_program.c	 
*	 
* Description: Source file for the DMA driver	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/
#include"STD_TYPES.h"
#include"DMA_interface.h"	 
#include"DMA_private.h"	 
#include"DMA_config.h"	 


void (*DMA_pToFunction[8])(void);

/*******************************************************************************
 * 							  		  ISRs
 *******************************************************************************/
void 	DMA2_Stream0_IRQHandler(){
	(*DMA_pToFunction[0])();
}

void 	DMA2_Stream1_IRQHandler(){
	(*DMA_pToFunction[1])();
}

void 	DMA2_Stream2_IRQHandler(){
	(*DMA_pToFunction[2])();
}

void 	DMA2_Stream3_IRQHandler(){
	(*DMA_pToFunction[3])();
}

void 	DMA2_Stream4_IRQHandler(){
	(*DMA_pToFunction[4])();
}

void 	DMA2_Stream5_IRQHandler(){
	(*DMA_pToFunction[5])();
}

void 	DMA2_Stream6_IRQHandler(){
	(*DMA_pToFunction[6])();
}

void 	DMA2_Stream7_IRQHandler(){
	(*DMA_pToFunction[7])();
}

/*******************************************************************************
 * 							  Functions Definitions
 *******************************************************************************/
void DMA_vInit(u8 Copy_u8StreamID, const DMA_ConfigType * PTR_config)
{
	/* disable DMA before configuration */
	DMA2->stream[Copy_u8StreamID].CR = 0;
	/* check the enable bit in case a transfer was still in progress */
	while(DMA2->stream[Copy_u8StreamID].CR & (1 << EN));
	/* select channel and set priority and set data transfer direction */
	DMA2->stream[Copy_u8StreamID].CR |= (PTR_config->ch << CHSEL) | (PTR_config->priority << PL) | (PTR_config->direction << DIR);
	/* set memory and peripheral data size */
	DMA2->stream[Copy_u8StreamID].CR |= (PTR_config->MSize << MSIZE) | (PTR_config->PSize << PSIZE);
	/* set memory and peripheral burst size  */
	DMA2->stream[Copy_u8StreamID].CR |= (PTR_config->MBurst << MBURST) | (PTR_config->PBurst << PBURST);
	/* set memory and peripheral increment mode */
	DMA2->stream[Copy_u8StreamID].CR |= (PTR_config->MIncrement << MINC) | (PTR_config->PIncrement <<PINC);
	/* set circular mode */
	DMA2->stream[Copy_u8StreamID].CR |= (PTR_config->circularMode << CIRC);
	/* set transfer type and FIFO threshold */
	DMA2->stream[Copy_u8StreamID].FCR |= (PTR_config->FIFO_enable << DMDIS) | (PTR_config->FIFO_size << FTH);
	/* Enable interrupt */
	DMA2->stream[Copy_u8StreamID].CR |= (1 << TCIE);
}

void DMA_vSetAddress(u8 Copy_u8StreamID, u32 * PTR_u32PA, u32 * PTR_u32MA, u16 Copy_u16DataLength)
{
	/* set peripheral port address */
	DMA2->stream[Copy_u8StreamID].PAR = (u32)PTR_u32PA;
	/* set memory port address */
	DMA2->stream[Copy_u8StreamID].M0AR = (u32)PTR_u32MA;
	/* set data length */
	DMA2->stream[Copy_u8StreamID].NDTR = Copy_u16DataLength;
}

void DMA_vStreamEnable(u8 Copy_u8StreamID)
{
	DMA2->stream[Copy_u8StreamID].CR |= (1 << EN);
}

void DMA_vSetCallBack(u8 Copy_u8StreamID, void (*FPTR)(void))
{
	DMA_pToFunction[Copy_u8StreamID] = FPTR;
}
