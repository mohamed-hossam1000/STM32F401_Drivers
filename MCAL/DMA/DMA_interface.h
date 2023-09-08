/******************************************************************************	 
*	 
* Module: DMA	 
*	 
* File Name: DMA_interface.h	 
*	 
* Description: Header file for the DMA driver user interface	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef DMA_INTERFACE_H_	 
#define DMA_INTERFACE_H_

/*******************************************************************************
 * 								 Type Declaration
 *******************************************************************************/
typedef enum{
	CHANNEL_0, CHANNEL_1, CHANNEL_2, CHANNEL_3, CHANNEL_4, CHANNEL_5, CHANNEL_6, 
	CHANNEL_7
}channel;

typedef enum{
	INCR1, INCR4, INCR8, INCR16
}burstSize;

typedef enum{
	LOW, MEDIUM, HIGH, VERY_HIGH
}priorityLevel;

typedef enum{
	BYTE, HALF_WORD, WORD
}dataSize;

typedef enum{
	PERIPHERAL_TO_MEMORY, MEMORY_TO_PERIPHERAL, MEMORY_TO_MEMORY
}dataDirection;

typedef enum{
	FIFO_1_4, FIFO_1_2, FIFO_3_4, FIFO_FULL
}FIFO_threshold;

typedef struct{
	channel 		ch;
	burstSize 		MBurst;
	burstSize 		PBurst;
	priorityLevel 	priority;
	dataSize  		MSize;
	dataSize		PSize;
	boolean 		MIncrement;
	boolean			PIncrement;
	boolean    		circularMode;
	dataDirection 	direction;
	FIFO_threshold  FIFO_size;
	boolean			FIFO_enable;
}DMA_ConfigType;

/*******************************************************************************
 * 							  Functions Prototypes
 *******************************************************************************/
void DMA_vInit(u8 Copy_u8StreamID, const DMA_ConfigType * PTR_config);

void DMA_vSetAddress(u8 Copy_u8StreamID, u32 * PTR_u32PA, u32 * PTR_u32MA, u16 Copy_u16DataLenght);

void DMA_vStreamEnable(u8 Copy_u8StreamID);
	 
void DMA_vSetCallBack(u8 Copy_u8StreamID, void (*FPTR)(void));
#endif
