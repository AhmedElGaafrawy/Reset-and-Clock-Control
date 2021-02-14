/*
 * RCC_config.c
 *
 *  Created on: Feb 3, 2021
 *  Version   : 1.0.1
 *  Author    : Ahmed El-Gaafrawy
 *
 */
#include "../../LIBRARY/stdTypes.h"
#include "../../LIBRARY/errorStates.h"
#include "RCC_priv.h"
#include "RCC_config.h"


/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                  Creation of RCC Clock Configuration                    **/
/**               you can choose from the following options:
     typedef struct
             {
              uint_8 RCC_u8ClockSource;
             (RCC_HSI   //   RCC_HSE   //   RCC_PLL)

             ** These are used if the clock source is PLL
             ** if not, make their values by
                             (PLL_NOT_SELECTED)
              uint_8 RCC_u8PLL_Source;
                (RCC_HSEsrc2PLL   //   RCC_HSE_divByTwo_src2PLL
                                 //   RCC_HSI_divByTwo_src2PLL)
              uint_8 RCC_u8PLL_Multiplicationfactor;
                (it can be between 2 and 16, but ensure that the result clock
                 must be less than or equal the max of you MCU)
}ClockConfig_str;                                                           **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
ClockConfig_str RCC_strClockConfiguration = {
											RCC_HSE,
											RCC_PLL_NOT_SELECTED,
											RCC_PLL_NOT_SELECTED
										    };
											
ClockConfig_str RCC_strUpdatingClockConfiguration = {
											RCC_PLL,
											RCC_HSEsrc2PLL,
											5
										    };
