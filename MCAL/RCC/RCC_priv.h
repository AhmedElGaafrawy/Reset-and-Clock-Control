/*
 * RCC_priv.h
 *
 *
 *  Created on: May 5, 2020
 *  Version   : 1.0.8
 *  Author    : Ahmed El-Gaafrawy
 *
 */

#ifndef RCC_PRIV_H_
#define RCC_PRIV_H_

/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                  Structure of RCC Clock Configuration                   **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
typedef struct
{
	uint_8 RCC_u8ClockSource;
	uint_8 RCC_u8PLL_Source;
	uint_8 RCC_u8PLL_Multiplicationfactor;
}ClockConfig_str;
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/






/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                        Structure of RCC Registers                       **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
typedef struct
{
	uint_32 CR;
	uint_32 CFGR;
	uint_32 CIR;
	uint_32 APB2RSTR;
	uint_32 APB1RSTR;
	uint_32 AHBENR;
	uint_32 APB2ENR;
	uint_32 APB1ENR;
	uint_32 BDCR;
	uint_32 CSR;
}RCC_t;
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                      Base Address of RCC Registers                      **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
#define RCC		((volatile RCC_t*)0x40021000)
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                       Peripherals bits Definitions                      **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
enum
{
	/*		AHB_BUS		*/
	RCC_DMA1,		RCC_DMA2,		RCC_SRAM,		res3,
	RCC_FLITF,		res5,			RCC_CRCE,		res7,
	RCC_FSMC,		res9,			RCC_SDIO,

	/*		APB1_BUS	*/
	RCC_TIM2,		RCC_TIM3,		RCC_TIM4,		RCC_TIM5,
	RCC_TIM6,		RCC_TIM7,		RCC_TIM12,		RCC_TIM13,
	RCC_TIM14,		_res9,			_res10,			RCC_WWD,
	_res12,			_res13,			RCC_SPI2,		RCC_SPI3,
	_res16,			RCC_USART2,		RCC_USART3,		RCC_UART4,
	RCC_UART5,		RCC_I2C1,		RCC_I2C2,		RCC_USB,
	_res24,			RCC_CAN,		_res26,			RCC_BKP,
	RCC_PWR,		RCC_DAC,

	/*		APB2_BUS		*/
	RCC_AFIO,		__res1,			RCC_GPIOA,		RCC_GPIOB,
	RCC_GPIOC,		RCC_GPIOD,		RCC_GPIOE,		RCC_GPIOF,
	RCC_GPIOG,		RCC_ADC1,		RCC_ADC2,		RCC_TIM1,
	RCC_SPI1,		RCC_TIM8,		RCC_USART1,		RCC_ADC3,
	__res16,		__res17,		__res18,		RCC_TIM9,
	RCC_TIM10,		RCC_TIM11,
};
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                   Definitions of Some important bits                    **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
enum
{
	RCC_HSI,			RCC_HSE,						RCC_PLL,
	RCC_HSEsrc2PLL,		RCC_HSE_divByTwo_src2PLL,		RCC_HSI_divByTwo_src2PLL,
	RCC_PLL_NOT_SELECTED,

	RCC_ZERO=0,		RCC_ONE,		RCC_TWO,

	HSION=0,		HSIRDY,
	HSEON=16,		HSERDY,
	PLLON=24,		PLLRDY,

	CSS=19,

	SW0=0, 			SW1,		SWS,
	TRIM=3,

	PLLSRC=16,		PLLXTPRE,	PLLMUL,

	HPRE=4,			PPRE1=8,	PPRE2=11,
	ADCPRE=14,		USBPRE=22,	MCO=24,

	RCC_MAX_NEGATIVE_TIRM_FACTOR=-16,
	RCC_DEFAULT_TRIM_VALUE=16,
	RCC_TRIM_FACTOR=40,

	RCC_MAX_PLL_FACTOR=16,

	RCC_AHB_CLOCK_PURE=3,
	RCC_AHB_CLOCK_BY_TWO,		RCC_AHB_CLOCK_BY_FOUR,
	RCC_AHB_CLOCK_BY_EIGHT,		RCC_AHB_CLOCK_BY_SIXTEEN,

	RCC_SYS_CLOCK_PURE=7,
	RCC_SYS_CLOCK_BY_TWO,			RCC_SYS_CLOCK_BY_FOUR,
	RCC_SYS_CLOCK_BY_EIGHT,			RCC_SYS_CLOCK_BY_SIXTEEN,
    RCC_SYS_CLOCK_BY_SIXTY_FOUR,	RCC_SYS_CLOCK_BY_128,
	RCC_SYS_CLOCK_BY_256,			RCC_SYS_CLOCK_BY_512,


	RCC_PLL_CLOCK_FOR_USB_BY_ONE_AND_HALF=0,		RCC_PLL_CLOCK_FOR_USB_PURE,

	RCC_APBx_CLOCK_FOR_ADCs_BY_TWO=0,				RCC_APBx_CLOCK_FOR_ADCs_BY_FOUR,
	RCC_APBx_CLOCK_FOR_ADCs_BY_EGHIT,				RCC_APBx_CLOCK_FOR_ADCs_BY_SIXTEEN,

	RCC_NO_CLOCK_FOR_MCO=3,
	RCC_SYS_CLOCK_FOR_MCO,			RCC_HSI_CLOCK_FOR_MCO,
	RCC_HSE_CLOCK_FOR_MCO,			RCC_PLL_CLOCK_BY_TWO_FOR_MCO,

	RCC_PLL_MUL_FACTOR_MASKED=0xFFC3FFFF,

	RCC_AHB_PRESCALER_MASKED  = 0xffffff0f,
	RCC_APB1_PRESCALER_MASKED = 0xfffff8ff,
	RCC_APB2_PRESCALER_MASKED = 0xffffc7ff,
	RCC_ADCs_PRESCALER_MASKED = 0xffff3fff,
	RCC_USB_PRESCALER_MASKED  = 0xffbfffff,
	RCC_MCO_PRESCALER_MASKED  = 0xf8ffffff,

	RCC_TRIM_VALUE_MASKED = 0x000000f8,
	RCC_CLOCK_TIME_OUT=50000
};
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



#endif /* RCC_PRIV_H_ */
