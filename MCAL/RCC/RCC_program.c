 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_program.c
 *
 * Description: sourse file for the RCC driver 
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/
#include"../STD_TYPES.h"
#include"RCC_private.h"
#include"RCC_interface.h"
#include"RCC_config.h"

/*
 * Description : a function to initialize the system clock based on required configuration
 */
void RCC_vInitSysClk()
{
	#if SYS_CLK_SRC == HSE
		/* turn HSE clock on */
		RCC->CR |= (1 << HSEON);
		/* wait until HSE clock is ready */
		while(0 == (RCC->CR & (1 << HSERDY)));

		#if PLL_STATE == PLL_INACTIVE
			/* choose HSE as system clock */
			RCC->CFGR |= (1 << SW0);
			RCC->CFGR &= ~(1 << SW1);

		#elif PLL_STATE == PLL_ACTIVE
			/* choose HSE as PLL input clock */
			RCC->PLLCFGR |= (1 << PLLSRC);

			/* clear PLL clock configuration values */
			RCC->PLLCFGR &= ~PLLP_MASK & ~PLLN_MASK & ~PLLM_MASK;
			/* set new PLL configuration */
			RCC->PLLCFGR |= (PLLP_VALUE << PLLP) | (PLLN_VALUE << PLLN) | (PLLM_VALUE << PLLM);

			/* turn PLL on */
			RCC->CR |= (1 << PLLON);
			/* wait until PLL output clock is ready */
			while(0 == (RCC->CR & (1 << PLLRDY)));

			/* choose PLL output clock as system clock */
			RCC->CFGR &= ~(1 << SW0);
			RCC->CFGR |= (1 << SW1);

		#endif
	#elif SYS_CLK_SRC == HSI
		/* turn HSI clock on */
		RCC->CR |= (1 << HSION);
		/* wait until HSI clock is ready */
		while(0 == RCC->CR & (1 << HSIRDY));

		#if PLL_STATE == PLL_INACTIVE
			/* choose HSI as system clock */
			RCC->CFGR &= ~(1 << SW0);
			RCC->CFGR &= ~(1 << SW1);

		#elif PLL_STATE == PLL_ACTIVE
			/* choose HSI as PLL input clock */
			RCC->PLLCFGR &= ~(1 << PLLSRC);

			/* clear PLL clock configuration values */
			RCC->PLLCFGR &= ~PLLP_MASK & ~PLLN_MASK & ~PLLM_MASK;
			/* set new PLL configuration */
			RCC->PLLCFGR |= (PLLP_VALUE << PLLP) | (PLLN_VALUE << PLLN) | (PLLM_VALUE << PLLM);

			/* turn PLL on */
			RCC->CR |= (1 << PLLON);
			/* wait until PLL output clock is ready */
			while(0 == RCC->CR & (1 << PLLRDY));

			/* choose PLL output clock as system clock */
			RCC->CFGR &= ~(1 << SW0);
			RCC->CFGR |= (1 << SW1);

		#endif
	#endif
}

/*
 * Description : a function to enable the clock of a specific peripheral
 */
void RCC_vEnablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8eripheralId)
{
	/* choose the bus and set the required peripheral enable bit */
	switch(Copy_u8BusId)
	{
	case AHB1_BUS_ID:
		RCC->AHB1ENR |= (1 << Copy_u8eripheralId);
		break;
	case AHB2_BUS_ID:
		RCC->AHB2ENR |= (1 << Copy_u8eripheralId);
		break;
	case APB1_BUS_ID:
		RCC->APB1ENR |= (1 << Copy_u8eripheralId);
		break;
	case APB2_BUS_ID:
		RCC->APB2ENR |= (1 << Copy_u8eripheralId);
		break;
	}
}

/*
 * Description : a function to disable the clock of a specific peripheral
 */
void RCC_vDisablePeripheralClk(u8 Copy_u8BusId, u8 Copy_u8eripheralId)
{
	/* choose the bus and reset the required peripheral enable bit */
	switch(Copy_u8BusId)
	{
	case AHB1_BUS_ID:
		RCC->AHB1ENR &= ~(1 << Copy_u8eripheralId);
		break;
	case AHB2_BUS_ID:
		RCC->AHB2ENR &= ~(1 << Copy_u8eripheralId);
		break;
	case APB1_BUS_ID:
		RCC->APB1ENR &= ~(1 << Copy_u8eripheralId);
		break;
	case APB2_BUS_ID:
		RCC->APB2ENR &= ~(1 << Copy_u8eripheralId);
		break;
	}
}

