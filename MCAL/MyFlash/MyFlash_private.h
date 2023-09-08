/******************************************************************************	 
*	 
* Module: MyFlash	 
*	 
* File Name: MyFlash_private.h	 
*	 
* Description: Header file for the MyFlash driver private information	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef MyFlash_PRIVATE_H_	 
#define MyFlash_PRIVATE_H_

#define FLASH_BASE_ADDRESS			0x40023C00
#define FLASH 						((FLASH_t *) FLASH_BASE_ADDRESS)

typedef struct{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;
}FLASH_t;


/* Function to unlock the flash memory */
static void FLASH_vUnlock();
/* Function to lock the flash memory */
static void FLASH_vLock();

/* Flash key register keys to unlock Flash control register */
#define KEY1		0x45670123
#define KEY2		0x45670123
/* Flash option key register keys to unlock Flash option control register */
#define	OPTKEY1		0x08192A3B
#define OPTKEY2		0x4C5D6E7F
/* CR register bits */
#define PG			0
#define SER			1
#define MER			2
#define SNB			3
#define PSIZE		8
#define EOPIE		24
#define ERRIE		25
#define STRT		16
#define LOCK		31

#define  SNB_MASK  	0x00000078

/* SR register bits */
#define BSY			16
#endif
