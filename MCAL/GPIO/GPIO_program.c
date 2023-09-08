 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_program.c
 *
 * Description: Source file for the GPIO driver
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "GPIO_config.h"
#include "GPIO_private.h"
#include "GPIO_interface.h"

/*
* Description : Select the mode of a GPIO pin
*/
void GPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8Mode)
{
	if(Copy_u8PinNum > PIN15_ID || Copy_u8Mode > MODE_ANALOG)
	{
		/* Do Nothing */
	}
	else
	{
		/* multuply by 2 to get bit location in register */
		Copy_u8PinNum *= 2;
		/* select PORT and set the mode of required pin */
		switch(Copy_u8PortName)
		{
		case PORTA_ID:
			GPIOA->MODER |= (Copy_u8Mode << Copy_u8PinNum);
			break;
		case PORTB_ID:
			GPIOB->MODER |= (Copy_u8Mode << Copy_u8PinNum);
			break;
		case PORTC_ID:
			GPIOC->MODER |= (Copy_u8Mode << Copy_u8PinNum);
			break;
		case PORTD_ID:
			GPIOD->MODER |= (Copy_u8Mode << Copy_u8PinNum);
			break;
		case PORTE_ID:
			GPIOE->MODER |= (Copy_u8Mode << Copy_u8PinNum);
			break;
		case PORTH_ID:
			GPIOH->MODER |= (Copy_u8Mode << Copy_u8PinNum);
			break;
		default:
			/* ERROR */
		}
	}
}

/*
* Description : Select the output type of a GPIO pin
*/
void GPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutputType)
{
	if(Copy_u8PinNum > PIN15_ID || Copy_u8OutputType > OUTPUT_OPEN_DRIAN)
	{
		/* Do Nothing */
	}
	else
	{
		/* select PORT and set output type of required pin */
			switch(Copy_u8PortName)
		{
		case PORTA_ID:
			GPIOA->OTYPER |= (Copy_u8OutputType << Copy_u8PinNum);
			break;
		case PORTB_ID:
			GPIOB->OTYPER |= (Copy_u8OutputType << Copy_u8PinNum);
			break;
		case PORTC_ID:
			GPIOC->OTYPER |= (Copy_u8OutputType << Copy_u8PinNum);
			break;
		case PORTD_ID:
			GPIOD->OTYPER |= (Copy_u8OutputType << Copy_u8PinNum);
			break;
		case PORTE_ID:
			GPIOE->OTYPER |= (Copy_u8OutputType << Copy_u8PinNum);
			break;
		case PORTH_ID:
			GPIOH->OTYPER |= (Copy_u8OutputType << Copy_u8PinNum);
			break;
		default:
			/* ERROR */
		}		
	}	
}

/*
* Description : Select the level speed of a GPIO pin
*/
void GPIO_voidSetPinOutPutSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutputSpeed)
{
	if(Copy_u8PinNum > PIN15_ID || Copy_u8OutputSpeed > OUTPUT_SPEED_VERY_HIGH)
	{
		/* Do Nothing */
	}
	else
	{
		/* multuply by 2 to get bit location in register */
		Copy_u8PinNum *= 2;
		/* select PORT and set the output speed of required pin */
		switch(Copy_u8PortName)
		{
		case PORTA_ID:
			GPIOA->OSPEEDER |= (Copy_u8OutputSpeed << Copy_u8PinNum);
			break;
		case PORTB_ID:
			GPIOB->OSPEEDER |= (Copy_u8OutputSpeed << Copy_u8PinNum);
			break;
		case PORTC_ID:
			GPIOC->OSPEEDER |= (Copy_u8OutputSpeed << Copy_u8PinNum);
			break;
		case PORTD_ID:
			GPIOD->OSPEEDER |= (Copy_u8OutputSpeed << Copy_u8PinNum);
			break;
		case PORTE_ID:
			GPIOE->OSPEEDER |= (Copy_u8OutputSpeed << Copy_u8PinNum);
			break;
		case PORTH_ID:
			GPIOH->OSPEEDER |= (Copy_u8OutputSpeed << Copy_u8PinNum);
			break;
		default:
			/* ERROR */
		}
	}
}

/*
* Description : Select pull up, pull down or no pull of a GPIO pin
*/
void GPIO_voidSetPinPullType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PullType)
{
	if(Copy_u8PinNum > PIN15_ID || Copy_u8PullType > PULL_DOWN)
	{
		/* Do Nothing */
	}
	else
	{
		/* multuply by 2 to get bit location in register */
		Copy_u8PinNum *= 2;
		/* select PORT and set the pull type of required pin */
		switch(Copy_u8PortName)
		{
		case PORTA_ID:
			GPIOA->PUPDR |= (Copy_u8PullType << Copy_u8PinNum);
			break;
		case PORTB_ID:
			GPIOB->PUPDR |= (Copy_u8PullType << Copy_u8PinNum);
			break;
		case PORTC_ID:
			GPIOC->PUPDR |= (Copy_u8PullType << Copy_u8PinNum);
			break;
		case PORTD_ID:
			GPIOD->PUPDR |= (Copy_u8PullType << Copy_u8PinNum);
			break;
		case PORTE_ID:
			GPIOE->PUPDR |= (Copy_u8PullType << Copy_u8PinNum);
			break;
		case PORTH_ID:
			GPIOH->PUPDR |= (Copy_u8PullType << Copy_u8PinNum);
			break;
		default:
			/* ERROR */
		}
	}
}

/*
* Description : read a GPIO pin ans return it's value
*/
u8 GPIO_u8ReadPin(u8 Copy_u8PortName, u8 Copy_u8PinNum)
{
	u8 L_u8Data = 0;
	if(Copy_u8PinNum > PIN15_ID)
	{
		/* Do Nothing */
	}
	else
	{
		/* select PORT and get the value of the required pin */
			switch(Copy_u8PortName)
		{
		case PORTA_ID:
			L_u8Data = GET_BIT(GPIOA->IDR ,Copy_u8PinNum);
			break;
		case PORTB_ID:
			L_u8Data = GET_BIT(GPIOB->IDR ,Copy_u8PinNum);
			break;
		case PORTC_ID:
			L_u8Data = GET_BIT(GPIOC->IDR ,Copy_u8PinNum);
			break;
		case PORTD_ID:
			L_u8Data = GET_BIT(GPIOD->IDR ,Copy_u8PinNum);
			break;
		case PORTE_ID:
			L_u8Data = GET_BIT(GPIOE->IDR ,Copy_u8PinNum);
			break;
		case PORTH_ID:
			L_u8Data = GET_BIT(GPIOH->IDR ,Copy_u8PinNum);
			break;
		default:
			/* ERROR */
		}		
	}
	/* return the result */
	return L_u8Data;
}

/*
* Description : write a value to a GPIO pin
*/
void GPIO_voidWritePin(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8Data)
{
	if(Copy_u8PinNum > PIN15_ID)
	{
		/* Do Nothing */
	}
	else
	{
		if(Copy_u8Data == LOGIC_HIGH)
		{
			/* select PORT and set the value of the required pin */
			switch(Copy_u8PortName)
			{
			case PORTA_ID:
				SET_BIT(GPIOA->ODR ,Copy_u8PinNum);
				break;
			case PORTB_ID:
				SET_BIT(GPIOB->ODR ,Copy_u8PinNum);
				break;
			case PORTC_ID:
				SET_BIT(GPIOC->ODR ,Copy_u8PinNum);
				break;
			case PORTD_ID:
				SET_BIT(GPIOD->ODR ,Copy_u8PinNum);
				break;
			case PORTE_ID:
				SET_BIT(GPIOE->ODR ,Copy_u8PinNum);
				break;
			case PORTH_ID:
				SET_BIT(GPIOH->ODR ,Copy_u8PinNum);
				break;
			default:
				/* ERROR */
			}	
		}
		else if(Copy_u8Data == LOGIC_LOW)
		{
			/* select PORT and clear the value of the required pin */
			switch(Copy_u8PortName)
			{
			case PORTA_ID:
				CLEAR_BIT(GPIOA->ODR ,Copy_u8PinNum);
				break;
			case PORTB_ID:
				CLEAR_BIT(GPIOB->ODR ,Copy_u8PinNum);
				break;
			case PORTC_ID:
				CLEAR_BIT(GPIOC->ODR ,Copy_u8PinNum);
				break;
			case PORTD_ID:
				CLEAR_BIT(GPIOD->ODR ,Copy_u8PinNum);
				break;
			case PORTE_ID:
				CLEAR_BIT(GPIOE->ODR ,Copy_u8PinNum);
				break;
			case PORTH_ID:
				CLEAR_BIT(GPIOH->ODR ,Copy_u8PinNum);
				break;
			default:
				/* ERROR */
			}		
		}
		else
		{
			/* Do Nothing */
		}	
	}
}