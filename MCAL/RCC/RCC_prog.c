/*
 * RCC_prog.c
 *
 *  Created on: May 5, 2020
 *  Version   : 1.0.8
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
/**                        STATIC FUNCTIONS Prototypes                      **/
/**                That will use internally into this Driver                **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/
static void MRCC_vidEnableClockSecuritySystem(void);
/*****************************************************************************/

static void MRCC_vidDisableClockSecuritySystem(void);
/*****************************************************************************/

static uint_8 MRCC_u8GetSecuritySystemValue(void);
/*****************************************************************************/

static uint_8 MRCC_u8GetCurrentClockSource(void);
/*****************************************************************************/

static uint_8 MRCC_u8DisableCurrentClockSource(void);
/*****************************************************************************/

static uint_8 MRCC_u8SetClockSource(uint_8 Copy_u8ClockSource);
/*****************************************************************************/

static uint_8 MRCC_u8EnableClockSource(ClockConfig_str * ClkCfg);
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuInit.                                         **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Setting HSI Clock, no clock for MCO, without
                    : any prescaling, with default calibration, without
                    : enabling any peripheral and disabling clock security. **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuInit(void)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	ClockConfig_str RCC_strInitConfiguration = {
												RCC_HSI,
												RCC_PLL_NOT_SELECTED,
												RCC_PLL_NOT_SELECTED
											   };

	Local_enuErrorState = MRCC_u8EnableClockSource(&RCC_strInitConfiguration);

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuEnableClockSource(ClockConfig_str * ClkCfg)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	Local_enuErrorState = MRCC_u8SetClockSource(ClkCfg->RCC_u8ClockSource);
	if (Local_enuErrorState == ES_OK)
	{
		Local_enuErrorState = MRCC_u8EnableClockSource (ClkCfg);
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuGetCurrentClockSource(puint_8 Copy_Pu8CurrentClockSource)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	uint_8 Local_u8ClockSource = MRCC_u8GetCurrentClockSource();

	*Copy_Pu8CurrentClockSource = Local_u8ClockSource;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_enuDisableCurrentClockSource.                    **/
/** Return Type     : ERROR_STATES enum.                                    **/
/** Arguments       : void.                                                 **/
/** Functionality   : Disabling the Current Clock Source                    **/
/*****************************************************************************/
/*****************************************************************************/
ERROR_STATES MRCC_enuDisableCurrentClockSource(void)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	Local_enuErrorState = MRCC_u8DisableCurrentClockSource();

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuChangeClockSource(ClockConfig_str * ClkCfg)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	uint_8 Local_u8SecuritySystemValue = MRCC_u8GetSecuritySystemValue();
	if (Local_u8SecuritySystemValue)
	{
		MRCC_u8DisableCurrentClockSource();
		MRCC_u8SetClockSource(ClkCfg -> RCC_u8ClockSource);
		uint_8 Local_u8ErrorState = MRCC_u8EnableClockSource(ClkCfg);

		if (Local_u8ErrorState == ES_OK)
		{
			Local_enuErrorState = ES_OK;
		}
		else if (Local_u8ErrorState == ES_NOT_OK)
		{
			MRCC_vidEnableClockSecuritySystem();
			Local_enuErrorState = ES_NOT_OK;
		}
	}
	else
	{
		MRCC_vidEnableClockSecuritySystem();

		MRCC_u8DisableCurrentClockSource();
		MRCC_u8SetClockSource(ClkCfg -> RCC_u8ClockSource);
		uint_8 Local_u8ErrorState = MRCC_u8EnableClockSource(ClkCfg);

		if (Local_u8ErrorState == ES_OK)
		{
			MRCC_vidDisableClockSecuritySystem();
			Local_enuErrorState = ES_OK;
		}
		else if (Local_u8ErrorState == ES_NOT_OK)
		{
			Local_enuErrorState = ES_NOT_OK;
		}
	}


	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetHSICalibration(sint_16 Copy_s16Calibration)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if ( !(Copy_s16Calibration % RCC_TRIM_FACTOR) &&
			(     (Copy_s16Calibration / RCC_TRIM_FACTOR) < RCC_DEFAULT_TRIM_VALUE
					|| (Copy_s16Calibration / RCC_TRIM_FACTOR) >= RCC_MAX_NEGATIVE_TIRM_FACTOR ) )
	{
		sint_8 Local_s8TrimValue = Copy_s16Calibration / RCC_TRIM_FACTOR;
		Local_s8TrimValue += RCC_DEFAULT_TRIM_VALUE;
		RCC->CR &= ~RCC_TRIM_VALUE_MASKED;
		RCC->CR |= (Local_s8TrimValue <<3);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetADCsPrescaler(uint_8 Copy_u8Prescaler)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8Prescaler <= RCC_APBx_CLOCK_FOR_ADCs_BY_SIXTEEN)
	{
		RCC->CFGR &= RCC_ADCs_PRESCALER_MASKED;

		RCC->CFGR |=(Copy_u8Prescaler << ADCPRE);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetUSBPrescaler(uint_8 Copy_u8Prescaler)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8Prescaler <= RCC_PLL_CLOCK_FOR_USB_PURE)
	{
		RCC->CFGR &= RCC_USB_PRESCALER_MASKED;

		RCC->CFGR |=(Copy_u8Prescaler << USBPRE);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetAHBPrescaler(uint_8 Copy_u8Prescaler)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8Prescaler >= RCC_SYS_CLOCK_PURE && Copy_u8Prescaler <=RCC_SYS_CLOCK_BY_512)
	{
		RCC->CFGR &= RCC_AHB_PRESCALER_MASKED;

		RCC->CFGR |=(Copy_u8Prescaler << HPRE);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetAPB1Prescaler(uint_8 Copy_u8Prescaler)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8Prescaler >= RCC_AHB_CLOCK_PURE && Copy_u8Prescaler <=RCC_AHB_CLOCK_BY_SIXTEEN)
	{
		RCC->CFGR &= RCC_APB1_PRESCALER_MASKED;

		RCC->CFGR |=(Copy_u8Prescaler << PPRE1);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetAPB2Prescaler(uint_8 Copy_u8Prescaler)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8Prescaler >= RCC_AHB_CLOCK_PURE && Copy_u8Prescaler <=RCC_AHB_CLOCK_BY_SIXTEEN)
	{
		RCC->CFGR &= RCC_APB2_PRESCALER_MASKED;

		RCC->CFGR |=(Copy_u8Prescaler << PPRE2);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuSetMCOPinClockSource(uint_8 Copy_u8ClockSource)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8ClockSource >= RCC_NO_CLOCK_FOR_MCO
			&& Copy_u8ClockSource <=RCC_PLL_CLOCK_BY_TWO_FOR_MCO)
	{
		RCC->CFGR &= RCC_MCO_PRESCALER_MASKED;

		RCC->CFGR |=(Copy_u8ClockSource << MCO);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuEnableClockSecuritySystem(void)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	MRCC_vidEnableClockSecuritySystem();
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuDisableClockSecuritySystem(void)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	MRCC_vidDisableClockSecuritySystem();
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuEnablePeripheralClock(uint_8 Copy_u8PeripheralNum)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8PeripheralNum <= RCC_SDIO)
	{
		RCC->AHBENR |= (RCC_ONE<<Copy_u8PeripheralNum);
		Local_enuErrorState = ES_OK;
	}
	else if (Copy_u8PeripheralNum <= RCC_DAC)
	{
		Copy_u8PeripheralNum -= RCC_TIM2;
		RCC->APB1ENR |= (RCC_ONE<<Copy_u8PeripheralNum);
		Local_enuErrorState = ES_OK;
	}
	else if (Copy_u8PeripheralNum <=RCC_TIM11)
	{
		Copy_u8PeripheralNum -= RCC_AFIO;
		RCC->APB2ENR |= (RCC_ONE<<Copy_u8PeripheralNum);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
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
ERROR_STATES MRCC_enuDisablePeripheralClock(uint_8 Copy_u8PeripheralNum)
{
	ERROR_STATES Local_enuErrorState = ES_NOT_OK;

	if (Copy_u8PeripheralNum <= RCC_SDIO)
	{
		RCC->AHBENR &=~(RCC_ONE<<Copy_u8PeripheralNum);
		Local_enuErrorState = ES_OK;
	}
	else if (Copy_u8PeripheralNum <= RCC_DAC)
	{
		Copy_u8PeripheralNum -= RCC_TIM2;
		RCC->APB1RSTR = (RCC_ONE<<Copy_u8PeripheralNum);
		Local_enuErrorState = ES_OK;
	}
	else if (Copy_u8PeripheralNum <=RCC_TIM11)
	{
		Copy_u8PeripheralNum -= RCC_AFIO;
		RCC->APB2RSTR = (RCC_ONE<<Copy_u8PeripheralNum);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/







/*****************************************************************************/
/*****************************************************************************/
/**                                                                         **/
/**                             STATIC FUNCTIONS                            **/
/**                That will use internally into this Driver                **/
/**                                                                         **/
/*****************************************************************************/
/*****************************************************************************/





/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_vidEnableClockSecuritySystem.                    **/
/** Return Type     : void.                                                 **/
/** Arguments       : void.                                                 **/
/** Functionality   : Enabling the Clock Source Security System.            **/
/*****************************************************************************/
/*****************************************************************************/
static void MRCC_vidEnableClockSecuritySystem(void)
{
	RCC->CR |= (1<<CSS);
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_vidDisableClockSecuritySystem.                   **/
/** Return Type     : void.                                                 **/
/** Arguments       : void.                                                 **/
/** Functionality   : Disabling the Clock Source Security System.           **/
/*****************************************************************************/
/*****************************************************************************/
static void MRCC_vidDisableClockSecuritySystem(void)
{
	RCC->CR &=~(1<<CSS);
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_u8GetSecuritySystemValue.                        **/
/** Return Type     : uint_8 the value of Security System Value.            **/
/** Arguments       : void.                                                 **/
/** Functionality   : Disabling the Clock Source Security System.           **/
/*****************************************************************************/
/*****************************************************************************/
static uint_8 MRCC_u8GetSecuritySystemValue(void)
{
	return ( (RCC->CR>> CSS) & 1 );
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_u8GetCurrentClockSource.                         **/
/** Return Type     : uint_8 the value of Current Clock Source.             **/
/** Arguments       : void.                                                 **/
/** Functionality   : Getting the type of Current Clock source.             **/
/*****************************************************************************/
/*****************************************************************************/
static uint_8 MRCC_u8GetCurrentClockSource(void)
{
	return ( (RCC->CFGR>> SWS) & 3);
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_u8DisableCurrentClockSource.                     **/
/** Return Type     : uint_8 error state value.                             **/
/** Arguments       : void.                                                 **/
/** Functionality   : Disabling the Current Clock Source.                   **/
/*****************************************************************************/
/*****************************************************************************/
static uint_8 MRCC_u8DisableCurrentClockSource(void)
{
	uint_8 Local_u8ClockSource = MRCC_u8GetCurrentClockSource();
	uint_8 Local_u8error=ES_NOT_OK;
	switch (Local_u8ClockSource)
	{
	case RCC_HSI:
		/*Enable this clock*/
		RCC->CR &= ~(1<<HSION);
		Local_u8error=ES_OK;
		break;

	case RCC_HSE:
		/*Enable this clock*/
		RCC->CR &= ~(1<<HSEON);
		Local_u8error=ES_OK;
		break;

	case RCC_PLL:
		/*Disable that clock*/
		RCC->CR &= ~(1<<PLLON);
		Local_u8error=ES_OK;
		break;
	default:
		Local_u8error=ES_NOT_OK;
		break;
	}
	return Local_u8error;
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_u8SetClockSource.                                **/
/** Return Type     : uint_8 error state value.                             **/
/** Arguments       : The Value of Clock Source.                            **/
/** Functionality   : Setting the Clock Source.                             **/
/*****************************************************************************/
/*****************************************************************************/
static uint_8 MRCC_u8SetClockSource(uint_8 Copy_u8ClockSource)
{
	uint_8 Local_u8ErrorState = ES_NOT_OK;

	if (Copy_u8ClockSource == RCC_HSI)
	{
		RCC->CFGR &= ~(RCC_ONE << SW0);
		RCC->CFGR &= ~(RCC_ONE << SW1);
		Local_u8ErrorState = ES_OK;
	}
	else if (Copy_u8ClockSource == RCC_HSE)
	{
		RCC->CFGR |=  (RCC_ONE << SW0);
		RCC->CFGR &= ~(RCC_ONE << SW1);
		Local_u8ErrorState = ES_OK;
	}
	else if (Copy_u8ClockSource == RCC_PLL)
	{
		RCC->CFGR &= ~(RCC_ONE << SW0);
		RCC->CFGR |=  (RCC_ONE << SW1);
		Local_u8ErrorState = ES_OK;
	}
	else
	{
		Local_u8ErrorState =ES_OUT_OF_RANGE;
	}

	return Local_u8ErrorState;
}
/*****************************************************************************/
/*****************************************************************************/



/*****************************************************************************/
/*****************************************************************************/
/** Function Name   : MRCC_u8EnableClockSource.                             **/
/** Return Type     : uint_8 error state value.                             **/
/** Arguments       : Pointer to ClockConfig_str for RCC Configuration.     **/
/** Functionality   : Setting The clock source, setting PLL source and its
                    : Multiplication Factor if PLL is chosen as a source.   **/
/*****************************************************************************/
/*****************************************************************************/
static uint_8 MRCC_u8EnableClockSource(ClockConfig_str * ClkCfg)
{
	uint_8 Local_u8ErrorState =ES_NOT_OK;
	uint_16 Local_u16CheckFlagCounter=0;
	switch (ClkCfg -> RCC_u8ClockSource)
	{
	case RCC_HSI:
		/*Enable this clock*/
		RCC->CR |= (1<<HSION);
		RCC->CR &=~(1<<HSEON);
		RCC->CR &=~(1<<PLLON);

		while ((!(RCC-> CR >> HSIRDY ) & 1)
				&& Local_u16CheckFlagCounter ++ < RCC_CLOCK_TIME_OUT);
		Local_u8ErrorState =ES_OK;
		break;
	case RCC_HSE:
		/*Enable this clock*/
		RCC->CR |= (1<<HSEON);
		RCC->CR &=~(1<<HSION);
		RCC->CR &=~(1<<PLLON);
		while ((!(RCC-> CR >> HSERDY ) & 1)
				&& Local_u16CheckFlagCounter ++ < RCC_CLOCK_TIME_OUT);
		Local_u8ErrorState =ES_OK;
		break;

	case RCC_PLL:
		/*Enable that clock*/
		switch (ClkCfg -> RCC_u8PLL_Source)
		{
		case RCC_HSI_divByTwo_src2PLL:
			RCC->CFGR &=~(1<<PLLSRC);
			RCC->CFGR &=~(1<<PLLXTPRE);
			break;

		case RCC_HSEsrc2PLL:
			RCC->CFGR |= (1<<PLLSRC);
			RCC->CFGR &=~(1<<PLLXTPRE);
			break;

		case RCC_HSE_divByTwo_src2PLL :
			RCC->CFGR |= (1<<PLLSRC);
			RCC->CFGR |= (1<<PLLXTPRE);
			break;
		}
		if (ClkCfg->RCC_u8PLL_Multiplicationfactor <=16)
		{
			RCC->CFGR &= RCC_PLL_MUL_FACTOR_MASKED;

			RCC->CFGR |= ((ClkCfg->RCC_u8PLL_Multiplicationfactor-2)<<PLLMUL);

			RCC->CR |= (1<<PLLON);
			while ((!(RCC-> CR >> PLLRDY ) & 1)
					&& Local_u16CheckFlagCounter ++ < RCC_CLOCK_TIME_OUT);
			Local_u8ErrorState = ES_OK;
		}
		else
			Local_u8ErrorState = ES_NOT_OK;
		break;
		default:
			break;
	}
	return Local_u8ErrorState;
}
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
/*****************************************************************************/
