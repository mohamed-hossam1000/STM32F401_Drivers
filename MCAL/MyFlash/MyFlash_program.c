/******************************************************************************	 
*	 
* Module: MyFlash	 
*	 
* File Name: MyFlash_program.c	 
*	 
* Description: Source file for the MyFlash driver	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#include"STD_TYPES.h"	 
#include"MyFlash_interface.h"	 
#include"MyFlash_private.h"	 
#include"MyFlash_config.h"


/* Function to unlock the flash memory */
static void FLASH_vUnlock()
{
    FLASH->KEYR = KEY1;
    FLASH->KEYR = KEY2;
}

/* Function to lock the flash memory */
static void FLASH_vLock()
{
    FLASH->CR |= (1 << LOCK);
}

/* Function to erase a flash sector */
void FLASH_vEraseSector(u8 Copy_u8Sector)
{
    /* Unlock the flash memory */
    FLASH_vUnlock();

    /* Wait until the flash is not busy */
    while (FLASH->SR & (1 << BSY));

    /* Clear PG (Programming) and MER (Mass Erase) bits */
    FLASH->CR &= ~(1 << PG) & ~(1 << MER);

    /* Set SER (Sector Erase) bit */
    FLASH->CR |= (1 << SER);

    /* Configure the sector to be erased using SNB_MASK and SNB (Sector Number) bits */
    FLASH->CR = (FLASH->CR & ~(SNB_MASK)) | (Copy_u8Sector << SNB);

    /* Start the erase operation */
    FLASH->CR |= (1 << STRT);

    /* Lock the flash memory */
    FLASH_vLock();
}

/* Function to write in flash */
void FLASH_vWrite(u32 Copy_u32Address, u32* Ptr_u32Data, u32 Copy_u32DataLength)
{
    if (NULL != Ptr_u32Data)
    {
        u32 i;
        /* Unlock the flash memory for write */
        FLASH_vUnlock();

        /* Wait until the flash is not busy */
        while (FLASH->SR & (1 << BSY));

        /* Clear SER and MER bits */
        FLASH->CR &= ~(1 << SER) & ~(1 << MER);

        /* Set PG bit for programming */
        FLASH->CR |= (1 << PG);

        for (i = 0; i < Copy_u32DataLength; i++)
        {
            /* Write data to the flash at the specified address */
            *((u32 *)Copy_u32Address + i) = Ptr_u32Data[i];

            /* Wait until the flash is not busy */
            while (FLASH->SR & (1 << BSY));
        }

        /* Lock the flash memory after writing */
        FLASH_vLock();
    }
}

