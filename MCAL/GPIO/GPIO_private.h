 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_private.h
 *
 * Description: Header file for the GPIO driver private data
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS 			0x40020000
#define GPIOB_BASE_ADDRESS 			0x40020400
#define GPIOC_BASE_ADDRESS 			0x40020800
#define GPIOD_BASE_ADDRESS 			0x40020C00
#define GPIOE_BASE_ADDRESS 			0x40021000
#define GPIOH_BASE_ADDRESS 			0x40021C00

#define GPIOA   			((volatile GPIOx_t*) GPIOA_BASE_ADDRESS)
#define GPIOB   			((volatile GPIOx_t*) GPIOB_BASE_ADDRESS)
#define GPIOC   			((volatile GPIOx_t*) GPIOC_BASE_ADDRESS)
#define GPIOD   			((volatile GPIOx_t*) GPIOD_BASE_ADDRESS)
#define GPIOE   			((volatile GPIOx_t*) GPIOE_BASE_ADDRESS)
#define GPIOH   			((volatile GPIOx_t*) GPIOH_BASE_ADDRESS)

typedef struct{
volatile u32 MODER;
volatile u32 OTYPER;
volatile u32 OSPEEDER;
volatile u32 PUPDR;
volatile u32 IDR;
volatile u32 ODR;
volatile u32 BSRR;
volatile u32 LCKR;
volatile u32 AFR[2];
}GPIOx_t;


#endif 
