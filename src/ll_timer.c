//! \file ll_timer.c
//! \brief implementation of timer routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01

//----------------------------------------------------------------------------//

//----------- I M P O R T A N T   N O T E ------------------------------------//
//
//----------------------------------------------------------------------------//

//----------- (1) INCLUDES ---------------------------------------------------//
#include "ll_timer.h"

//----------- (2) PRIVATE TYPEDEF --------------------------------------------//
// N/A

//----------- (3) PRIVATE DEFINE ---------------------------------------------//
// N/A

//----------- (4) PRIVATE MACRO ----------------------------------------------//
// N/A

//----------- (5) PRIVATE VARIABLES ------------------------------------------//
__IO uint32_t delayCounter = 0;

__IO uint32_t testCounter = 0;


//----------- (6) PRIVATE FUNCTION PROTOTYPES --------------------------------//
// N/A

//----------- (7) PRIVATE FUNCTIONS ------------------------------------------//

/*!
 *  \fn      void ll_timer4_init(void)
 *  \brief   Timer4 initialization
 *  \param   None
 *  \return  None
 */
//Timer $ enabled for testing purposes
/*void ll_timer4_init(void)
{
    // Enable Timer4 Clock 16MHz
    CLK_PeripheralClockConfig(CLK_Peripheral_TIM4, ENABLE);
    // TIM4CLK: 16MHz, TIM4Prescaler: 128
    // TIM4 CounterCLK 16MHz/128 = 125kHz
    // We need Timebase 1mS : TIM4 Period = 125-1
    TIM4_TimeBaseInit(TIM4_Prescaler_64, 124);
    // Clear TIM4 update flag 
    TIM4_ClearFlag(TIM4_FLAG_Update);
    // Enable update interrupt
    TIM4_ITConfig(TIM4_IT_Update, ENABLE);
		
    // Enable TIM4 
    TIM4_Cmd(ENABLE);
}*/

/*!
 *  \fn      void ll_timer4_irqHandler(void)
 *  \brief   Timer4 interrupt handler 
 *  \param   None
 *  \return  None
 */
/*void ll_timer4_irqHandler(void)
{
    if(delayCounter != 0x00)
    {
        delayCounter--;
    }
    
    if(testCounter != 0x00)
    {
        testCounter--;
    }
    else
    {
        GPIO_ToggleBits(GPIOB, GPIO_Pin_3);
        
        //GPIO_ToggleBits(GPIOE, GPIO_Pin_7); // STM8L-DISCO LED_LD_3
        testCounter = 100;
    }
}*/


//Enable Timer 2 for Input Capture Event on rising edge
//of Input signal
void ll_timer2_init(void)
{
	CLK_PeripheralClockConfig(CLK_Peripheral_TIM2, ENABLE);
		TIM2_TimeBaseInit(TIM2_Prescaler_8, TIM2_CounterMode_Up, 62500);
     TIM2_ICInit(TIM2_Channel_1, TIM2_ICPolarity_Rising, 
                 TIM2_ICSelection_DirectTI, 1, 1);
     TIM2_ITConfig(TIM2_IT_Update, ENABLE);
     TIM2_ITConfig(TIM2_IT_CC1, ENABLE);
     TIM2_Cmd(ENABLE);
     enableInterrupts();
}
//Timer 3 acting as a timer, time base 0.5s
void ll_timer3_init(void)
{
    CLK_PeripheralClockConfig(CLK_Peripheral_TIM3, ENABLE);
    TIM3_TimeBaseInit(TIM3_Prescaler_64, TIM3_CounterMode_Up, 62500);
    // Clear TIM3 update flag 
    TIM3_ClearFlag(TIM3_FLAG_Update);
    // Enable update interrupt
    TIM3_ITConfig(TIM3_IT_Update, ENABLE);
		
    // Enable TIM3 
    TIM3_Cmd(ENABLE);
		enableInterrupts();
		
}
//Enabling the DAC
void DAC_init(void)
{
	CLK_PeripheralClockConfig(CLK_Peripheral_DAC, ENABLE);
	DAC_Init(DAC_Channel_1,DAC_Trigger_None, DAC_OutputBuffer_Disable);
	DAC_Cmd(DAC_Channel_1,ENABLE);
	
}


/*!
 *  \fn        void delay_mS(__IO uint32_t n_mS)
 *  \brief     delay in millisecond
 *  \param[in] n_mS
 *  \return    None
 */
void delay_mS(__IO uint32_t n_mS)
{
    delayCounter = n_mS;
    while(delayCounter != 0x00)
    {
        ; // do nothing
    }
}

//----------- (8) END OF FILE ------------------------------------------------//
