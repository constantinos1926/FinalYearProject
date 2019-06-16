//! \file main.c
//! \brief implementation of main routine
//! \author Constantinos Nicolaou
//! \date 2019-06-01

//----------------------------------------------------------------------------//

//----------- I M P O R T A N T   N O T E ------------------------------------//
//
//----------------------------------------------------------------------------//

//----------- (1) INCLUDES ---------------------------------------------------//
#include "stm8l15x_conf.h"
#include "ll_gpio.h"
#include "ll_timer.h"
#include "ll_uart.h"
#include "ll_spi.h"

//----------- (2) PRIVATE TYPEDEF --------------------------------------------//
// N/A

//----------- (3) PRIVATE DEFINE ---------------------------------------------//
// N/A

//----------- (4) PRIVATE MACRO ----------------------------------------------//
// N/A

//----------- (5) PRIVATE VARIABLES ------------------------------------------//
volatile uint8_t pressedButton = 0x00;
unsigned long overflow_count = 0;
unsigned long pulse_ticks = 0;
unsigned long start_time = 0;
unsigned long end_time = 0;
unsigned long count=0;
unsigned long frequency=0;
unsigned long f =0;
double q = 0.0;
unsigned long offset= 1048576;

//----------- (6) PRIVATE FUNCTION PROTOTYPES --------------------------------//
// N/A

//----------- (7) PRIVATE FUNCTIONS ------------------------------------------//

/*!
 *  \fn      int main(void)
 *  \brief   Main program.
 *  \param   None
 *  \return  None
 */
int main(void)
{
	//Transmission of F=44.444kHz
	uint32_t i = 44444;
    
    // Configuration HSI clock: 8MHz
    CLK_SYSCLKSourceConfig(CLK_SYSCLKSource_HSI);
    CLK_SYSCLKDivConfig(CLK_SYSCLKDiv_2);
    while(CLK_GetSYSCLKSource() != CLK_SYSCLKSource_HSI)
    {
        ; // do nothing
    }
    
    // Disable all interrupts
    disableInterrupts();
    // Initialization of low-level peripherals
    ll_gpio_init();
    //ll_timer4_init();
		ll_timer2_init();
		ll_timer3_init();
		DAC_init();
    ll_uart1_init();
    //ll_spi1_init();
    // Enable all interrupts
    enableInterrupts();
    
    // clear UMAS pin
    //GPIO_ResetBits(GPIOF, GPIO_Pin_0);
		
    while(1)
    {		
				//NFC to UART Test, transmitting a 44.444kHz frequency
        if(rxData == 0x07)
        {
					GPIO_ToggleBits(GPIOB, GPIO_Pin_1);
					
					ll_uart1_freq(i);
            rxData = 0x00; 
        }
				
				//Frequency transmission segment
				if(rxData == 0x05)
        {
					f=frequency-offset;
					//q = (double) pulse_ticks;
					//q = 1000000/ q;
					
					ll_uart1_freq(f);
					//ll_uart1_freq(q);
            rxData = 0x00; 
        }
				
				//DAC voltage
				
				//Reset DAC
				if(rxData == 0x06)
				{
					DAC_SetChannel1Data(DAC_Align_12b_R,0);
					ll_uart1_freq(0x00);
					rxData = 0x00;
				}
				// V_cc/4
				if(rxData == 0x01)
				{
					DAC_SetChannel1Data(DAC_Align_12b_R,1023);
					ll_uart1_freq(07);
					rxData = 0x00;
				}
				// V_cc/2
				if(rxData == 0x02)
				{
					DAC_SetChannel1Data(DAC_Align_12b_R,2047);
					ll_uart1_freq(14);
					rxData = 0x00;
				}
				// 3V_cc/4
				if(rxData == 0x03)
				{
					DAC_SetChannel1Data(DAC_Align_12b_R,3071);
					ll_uart1_freq(21);
					rxData = 0x00;
				}
				// V_cc
				if(rxData == 0x04)
				{
					DAC_SetChannel1Data(DAC_Align_12b_R,4095);
					ll_uart1_freq(28);
					rxData = 0x00;
				}
				
				
    }
}


#ifdef USE_FULL_ASSERT

/*!
 *  \brief   Reports the name of the source file and the source line number
 *           where the assert_param error has occurred
 *  \param   file: pointer to the source file name
 *  \param   line: assert_param error line source number
 *  \return  None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
    /*!
     *  User can add own implementation to report the file name and line number,
     *  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line)
     */

    // Infinite loop
    while(1)
    {
        ; // do nothing
    }
}

#endif

//----------- (8) END OF FILE ------------------------------------------------//
