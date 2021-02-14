#include "../LIBRARY/stdTypes.h"
#include "../MCAL/RCC/RCC_int.h"
//#include "../MCAL/GPIO/GPIO_int.h"

void delay_one_s(void);

extern ClockConfig_str   RCC_strClockConfiguration;

extern ClockConfig_str RCC_strUpdatingClockConfiguration;
int
main(void)
{
	uint_8 Local_u8ClockSource=255;
	
	MRCC_enuInit(); // it will run by HSI 
	
	/*
	   if you do not want to init  configuation, 
	   first extern RCC_strClockConfiguration 
	   from RCC_config.c file
	*/
	MRCC_enuEnableClockSource(& RCC_strClockConfiguration);
	
	/*
	   if you want to change RCC configuation in run time, 
	   first an object from ClockConfig_str, 
	   then extern it  
	   from RCC_config.c file
	*/
	MRCC_enuChangeClockSource(& RCC_strUpdatingClockConfiguration);
	
	// Enable your peripherals Clock here like GPIOA
	MRCC_enuEnablePeripheralClock(GPIOA);
	
	
	// Configure your peripherals here like GPIOA

	while (1)
	{
		MRCC_enuGetCurrentClockSource(& Local_u8ClockSource)
		if (Local_u8ClockSource == PLL)
		{
			// put your code
		}
		Local_u8ClockSource =255;
	}
	return 0;
}


void delay_one_s(void)
{
	uint_16 i=0, j=0;
	for (i=0;i<660;i++)
		for(j=0;j<660;j++)
			asm("NOP");
}
