 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_config.h
 *
 * Description: Header file for the RCC driver configuration
 *
 * Author: Mohamed Hossam
 *
 *******************************************************************************/

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_


#define SYS_CLK_SRC			HSE
#define PLL_STATE			PLL_ACTIVE

/* choose from predefined values
   PLLP_2, PLLP_4, PLLP_6, PLLP_8 */
#define PLLP_VALUE			PLLP_4
/* range 50 : 432 */
#define PLLN_VALUE			144
/* range 2 : 63 */
#define PLLM_VALUE			4



#endif
