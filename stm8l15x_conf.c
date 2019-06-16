/*
 * stm8l15x_conf.c
 *
 *  
 */

#include "stm8l15x_conf.h"
/*
 
 */

void system_configure(void)
{
	
	CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_1);//16MHZ for system clock

}
