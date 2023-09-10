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
