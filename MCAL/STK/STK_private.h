 /******************************************************************************
 *
 * Module: Systick
 *
 * File Name: STK_private.h
 *
 * Description: Header file for the Systick timer driver private information
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

#define STK_BASE_ADDRESS			0xE000E010
#define STK 						((STK_t *) STK_BASE_ADDRESS)

typedef struct{
volatile u32 CTRL;
volatile u32 LOAD;
volatile u32 VAL;
volatile u32 CALIB;
}STK_t;

/* STK_CTRL register usefull bits */
#define ENABLE			0
#define TICKINT			1
#define CLKSOURCE		2

#endif