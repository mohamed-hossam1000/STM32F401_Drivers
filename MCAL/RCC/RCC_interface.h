 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_interface.h
 *
 * Description: Header file for the RCC driver user interface
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef RCC_NTERFACE_H_
#define RCC_NTERFACE_H_


/********************************************************************************
 * 									  Macros
 ********************************************************************************/
#define AHB1_BUS_ID				0
#define AHB2_BUS_ID				1
#define APB1_BUS_ID				3
#define APB2_BUS_ID				4

/* Periphrals IDs */
#define GPIOA_ID   0
#define GPIOB_ID   1
#define GPIOC_ID   2
#define CRC_ID     12
#define DMA1_ID    21
#define DMA2_ID    22
#define OTGFS_ID   7
#define TIM2_ID    0
#define TIM3_ID    1
#define TIM4_ID    2
#define TIM5_ID    3
#define WWDG_ID    11
#define USART1_ID  4
/********************************************************************************
 * 								Functions Prototypes
 ********************************************************************************/

/*
 * Description : a function to initialize the system clock based on required configuration
 */
void RCC_vInitSysClk();

/*
 * Description : a function to enable the clock of a specific peripheral
 */
void RCC_vEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8eripheralId);

/*
 * Description : a function to disable the clock of a specific peripheral
 */
void RCC_vDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8eripheralId);


#endif
