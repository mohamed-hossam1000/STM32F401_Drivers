 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_private.h
 *
 * Description: Header file for the RCC driver private information
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*
#define RCC_CR                *((volatile uint32*) 0x40023800)
#define RCC_PLLCFGR           *((volatile uint32*) 0x40023804)
#define RCC_CFGR              *((volatile uint32*) 0x40023808)
#define RCC_CIR               *((volatile uint32*) 0x4002380C)
#define RCC_AHB1RSTR          *((volatile uint32*) 0x40023810)
#define RCC_AHB2RSTR          *((volatile uint32*) 0x40023814)
#define RCC_APB1RSTR          *((volatile uint32*) 0x40023820)
#define RCC_APB2RSTR          *((volatile uint32*) 0x40023824)
#define RCC_AHB1ENR           *((volatile uint32*) 0x40023830)
#define RCC_AHB2ENR           *((volatile uint32*) 0x40023834)
#define RCC_APB1ENR           *((volatile uint32*) 0x40023840)
#define RCC_APB2ENR           *((volatile uint32*) 0x40023844)
#define RCC_AHB1LPENR         *((volatile uint32*) 0x40023850)
#define RCCAHB2LPENR          *((volatile uint32*) 0x40023854)
#define RCC_APB1LPENR         *((volatile uint32*) 0x40023860)
#define RCC_APB2LPENR         *((volatile uint32*) 0x40023864)
#define RCC_BDCR              *((volatile uint32*) 0x40023870)
#define RCC_CSR               *((volatile uint32*) 0x40023880)
#define RCC_SSCGR             *((volatile uint32*) 0x40023880)
#define RCC_PLLI2SCFGR        *((volatile uint32*) 0x40023884)
#define RCC_DCKCFGR           *((volatile uint32*) 0x4002388C)
*/
#define RCC_BASE_ADDRESS 		0x40023800
#define RCC 					((RCC_t *) RCC_BASE_ADDRESS)

/* RCC register description structure */
typedef struct{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	u32 RESERVED0[2];
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	u32 RESERVED1[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	u32 RESERVED2[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	u32 RESERVED3[2];
	volatile u32 AHB1LPENR;
	volatile u32 AHB2LPENR;
	u32 RESERVED4[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	u32 RESERVED5[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	u32 RESERVED6[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	u32 RESERVED7;
	volatile u32 DCKCFGR;
}RCC_t;

/* Clock sources */
#define HSE				1
#define HSI				2
/* PLL states */
#define PLL_ACTIVE 		1
#define PLL_INACTIVE	2

/* CR register useful bits */
#define HSION			0
#define HSIRDY			1

#define HSEON			16
#define HSERDY			17
#define HSEBYP			18

#define PLLON			24
#define PLLRDY 			25

/* PLLCFGR register useful bits */
#define PLLM			0
#define PLLN			6
#define PLLP			16
#define PLLSRC 			22

#define PLLM_MASK		0x0000003F
#define PLLN_MASK		0x00007FC0
#define PLLP_MASK		0x00030000

#define PLLP_2			0
#define PLLP_4			1
#define PLLP_6			2
#define PLLP_8			3

/* CFGR register useful bits */
#define SW0				0
#define SW1				1

#endif
