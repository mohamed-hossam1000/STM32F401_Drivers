/******************************************************************************	 
*	 
* Module: MyFlash	 
*	 
* File Name: MyFlash_interface.h	 
*	 
* Description: Header file for the MyFlash driver user interface	 
*	 
* Author: Mohamed Hossam	 
*	 
*******************************************************************************/	 
#ifndef MyFlash_INTERFACE_H_	 
#define MyFlash_INTERFACE_H_

/* Function to erase a flash sector */
void FLASH_vEraceSector(u8 Copy_u8Sector);
/* Function to write in flash */
void FLASH_vWrite(u32 Copy_u32Address, u32* Ptr_u32Data, u32 Copy_u32DataLength);
	 
#endif
