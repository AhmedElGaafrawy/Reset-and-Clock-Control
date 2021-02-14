/*
 * RCC_int.h
 *
 *  Created on: May 5, 2020
 *  Version   : 1.0.8
 *  Author    : Ahmed El-Gaafrawy
 *
 */

#ifndef RCC_INT_H_
#define RCC_INT_H_

/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuInit.                                         **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Setting HSI Clock, no clock for MCO, without
                      any prescaling, with default calibration, without
                      enabling any peripheral and disabling clock security. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuInit(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuEnableClockSource.                            **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to ClockConfig_str for RCC Configuration.     **/
/** Functionality   : Setting The clock source, setting PLL source and its
                    : Multiplication Factor if PLL is chosen as a source.   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuEnableClockSource(ClockConfig_str * ClkCfg);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuGetCurrentClockSource.                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to u8 to store clock value.                   **/
/** Functionality   : Getting the type of Clock source.                     **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuGetCurrentClockSource(puint_8 Copy_Pu8CurrentClockSource);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuDisableCurrentClockSource.                    **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Disabling the Current Clock Source.                   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuDisableCurrentClockSource(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuChangeClockSource.                            **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Pointer to ClockConfig_str for RCC Configuration.     **/
/** Functionality   : Changing The clock source And PLL source and its
                    : Multiplication Factor if PLL is chosen as a source.   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuChangeClockSource(ClockConfig_str * ClkCfg);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetHSICalibration.                            **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Calibration, it must be
                    : between -640 to 600 KHz and be Multiples of 40 KHz.   **/
/** Functionality   : Setting the Calibration of HSI Clock if needed.       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetHSICalibration(sint_16 Copy_s16Calibration);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetADCsPrescaler.                             **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Prescaler, you can choose one of the
                    : following choices:
                      APBx_CLOCK_FOR_ADCs_BY_TWO
                      APBx_CLOCK_FOR_ADCs_BY_FOUR
                      APBx_CLOCK_FOR_ADCs_BY_EGHIT
                      APBx_CLOCK_FOR_ADCs_BY_SIXTEEN.                      **/
/** Functionality   : Setting the Prescaler of ADCs if needed, the default
                    : prescaling value is APBx divided by TWO.              **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetADCsPrescaler(uint_8 Copy_u8Prescaler);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetUSBPrescaler.                              **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Prescaler, you can choose one of the
                    : following choices:
                      PLL_CLOCK_FOR_USB_BY_ONE_AND_HALF
                      PLL_CLOCK_FOR_USB_PURE.                               **/
/** Functionality   : Setting the Prescaler of USB if needed, the default
                    : prescaling value is PLL divided by One and Half.      **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetUSBPrescaler(uint_8 Copy_u8Prescaler);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetAHBPrescaler.                              **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Prescaler, you can choose one of the
                    : following choices:
                      SYS_CLOCK_PURE
                      SYS_CLOCK_BY_TWO                     SYS_CLOCK_BY_FOUR
                      SYS_CLOCK_BY_EIGHT                   SYS_CLOCK_BY_SIXTEEN
                      SYS_CLOCK_BY_SIXTY_FOUR              SYS_CLOCK_BY_128
                      SYS_CLOCK_BY_256                     SYS_CLOCK_BY_512.**/
/** Functionality   : Setting the Prescaler of AHB Bus if needed, the default
                    : prescaling value is no Prescaler.                     **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetAHBPrescaler(uint_8 Copy_u8Prescaler);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetAPB1Prescaler.                             **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Prescaler, you can choose one of the
                    : following choices:
                      AHB_CLOCK_PURE
                      AHB_CLOCK_BY_TWO                 AHB_CLOCK_BY_FOUR
                      AHB_CLOCK_BY_EIGHT               AHB_CLOCK_BY_SIXTEEN.**/
/** Functionality   : Setting the Prescaler of APB1 Bus if needed,
                    : the default prescaling value is no Prescaler.         **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetAPB1Prescaler(uint_8 Copy_u8Prescaler);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetAPB2Prescaler.                             **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Prescaler, you can choose one of the
                    : following choices:
                      AHB_CLOCK_PURE
                      AHB_CLOCK_BY_TWO                 AHB_CLOCK_BY_FOUR
                      AHB_CLOCK_BY_EIGHT               AHB_CLOCK_BY_SIXTEEN.**/
/** Functionality   : Setting the Prescaler of APB2 Bus if needed,
                    : the default prescaling value is no Prescaler.         **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetAPB2Prescaler(uint_8 Copy_u8Prescaler);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuSetMCOPinClockSource.                         **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Value of Clock Source, you can choose one of the
                    : following choices:
                      NO_CLOCK_FOR_MCO
                      SYS_CLOCK_FOR_MCO            HSI_CLOCK_FOR_MCO
                      HSE_CLOCK_FOR_MCO            PLL_CLOCK_BY_TWO_FOR_MCO.**/
/** Functionality   : Setting the Clock source of MCO Pin if needed,
                    : the default Source is no no clock source.
                    : Be attention that The clock must be less than or equal
					  50 MHz "The max speed of GPIO Pins"                   **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuSetMCOPinClockSource(uint_8 Copy_u8ClockSource);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuEnableClockSecuritySystem.                    **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Enabling the Clock Source Security System.            **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuEnableClockSecuritySystem(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuDisableClockSecuritySystem.                   **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Disabling the Clock Source Security System.           **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuDisableClockSecuritySystem(void);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuEnablePeripheralClock.                        **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Peripheral Number, you can choose for Peripheral_enu. **/
/** Functionality   : Enabling the Peripheral Clock.                        **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuEnablePeripheralClock(uint_8 Copy_u8PeripheralNum);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuDisablePeripheralClock.                       **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : Peripheral Number, you can choose for Peripheral_enu. **/
/** Functionality   : Disabling the Peripheral Clock.                       **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuDisablePeripheralClock(uint_8 Copy_u8PeripheralNum);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                             Peripherals Enum                            **/
/**That you can use its member as an argument to enable or disable its clock**/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
typedef enum
{
	/*		AHB_BUS		*/
	DMA1,			DMA2,		SRAM,
	FLITF=4,					CRCE=6,
	FSMC=8,						SDIO=10,

	/*		APB1_BUS	*/
	TIM2,		TIM3,		TIM4,		TIM5,
	TIM6,		TIM7,		TIM12,		TIM13,
	TIM14,								WWD=22,
							SPI2=25,	SPI3,
				USART2=28,	USART3,		UART4,
	UART5,		I2C1,		I2C2,		USB,
				CAN=36,					BKP=38,
	PWR,		DAC,

	/*		APB2_BUS		*/
	AFIO,					GPIOA=43,		GPIOB,
	GPIOC,		GPIOD,		GPIOE,		GPIOF,
	GPIOG,		ADC1,		ADC2,		TIM1,
	SPI1,		TIM8,		USART1,		ADC3,
										TIM9=60,
	TIM10,		TIM11,
}Peripheral_enu;
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/




/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                            Configuration Enum                           **/
/**            Its members can be used for some of configuration            **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
typedef enum
{

	/*  Options for Clock System Configuration */
	HSI,				HSE,						PLL,
	HSEsrc2PLL,			HSE_divByTwo_src2PLL,		HSI_divByTwo_src2PLL,
	PLL_NOT_SELECTED,


	/*  Options for APBx Buses Prescaler Configuration */
	AHB_CLOCK_PURE=3,
	AHB_CLOCK_BY_TWO,		AHB_CLOCK_BY_FOUR,
	AHB_CLOCK_BY_EIGHT,		AHB_CLOCK_BY_SIXTEEN,


	/*  Options for AHB Bus Prescaler Configuration */
	SYS_CLOCK_PURE=7,
	SYS_CLOCK_BY_TWO,			SYS_CLOCK_BY_FOUR,
	SYS_CLOCK_BY_EIGHT,			SYS_CLOCK_BY_SIXTEEN,
    SYS_CLOCK_BY_SIXTY_FOUR,	SYS_CLOCK_BY_128,
	SYS_CLOCK_BY_256,			SYS_CLOCK_BY_512,


	/*  Options for USB Prescaler Configuration */
	PLL_CLOCK_FOR_USB_BY_ONE_AND_HALF=0,		PLL_CLOCK_FOR_USB_PURE,


	/*  Options for ADCs Prescaler Configuration */
	APBx_CLOCK_FOR_ADCs_BY_TWO=0,				APBx_CLOCK_FOR_ADCs_BY_FOUR,
	APBx_CLOCK_FOR_ADCs_BY_EGHIT,				APBx_CLOCK_FOR_ADCs_BY_SIXTEEN,


	/*  Options for MCO Pin Prescaler Configuration */
	NO_CLOCK_FOR_MCO=3,
	SYS_CLOCK_FOR_MCO,			HSI_CLOCK_FOR_MCO,
	HSE_CLOCK_FOR_MCO,			PLL_CLOCK_BY_TWO_FOR_MCO,

}Configuration_enu;
#endif /* RCC_INT_H_ */
