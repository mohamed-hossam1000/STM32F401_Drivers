 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_interface.h
 *
 * Description: Header file for the GPIO driver user interface
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

/*******************************************************************************
 * 								  	Definitions
 *******************************************************************************/
/* GPIO ports IDs */
#define PORTA_ID  			0
#define PORTB_ID			1
#define PORTC_ID			2
#define PORTD_ID			3
#define PORTE_ID			4
#define PORTH_ID			5

/* GPIO pins IDs */
#define PIN0_ID				0
#define PIN1_ID				1
#define PIN2_ID				2
#define PIN3_ID				3
#define PIN4_ID				4
#define PIN5_ID				5
#define PIN6_ID				6
#define PIN7_ID				7
#define PIN8_ID				8
#define PIN9_ID				9
#define PIN10_ID			10
#define PIN11_ID			11
#define PIN12_ID			12
#define PIN13_ID			13
#define PIN14_ID			14
#define PIN15_ID			15

/* mode configuration */
#define MODE_INPUT			0
#define MODE_OUTPUT			1
#define MODE_ALTERNATE		2
#define MODE_ANALOG			3

/* output type configuration */
#define OUTPUT_PUSH_PULL	0
#define OUTPUT_OPEN_DRIAN	1

/* output speed configuration */
#define OUTPUT_SPEED_LOW		0
#define OUTPUT_SPEED_MEDIUM		1
#define OUTPUT_SPEED_HIGH 		2
#define OUTPUT_SPEED_VERY_HIGH	3

/* pull type configuration */
#define NO_PULL 			0
#define PULL_UP				1
#define PULL_DOWN			2

/* logic states */
#define LOGIC_LOW			0
#define LOGIC_HIGH			1
/*******************************************************************************
 * 								Functions Prototypes
 *******************************************************************************/

void GPIO_voidSetPinMode(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_uMode);

void GPIO_voidSetPinOutputType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutputType);

void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8OutputSpeed);

void GPIO_voidSetPinPullType(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8PullType);

u8 GPIO_u8ReadPin(u8 Copy_u8PortName, u8 Copy_u8PinNum);

void GPIO_voidWritePin(u8 Copy_u8PortName, u8 Copy_u8PinNum, u8 Copy_u8Data);


#endif 