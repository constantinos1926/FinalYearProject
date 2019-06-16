//! \file ll_gpio.c
//! \brief implementation of GPIO routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01


//----------------------------------------------------------------------------//

//----------- I M P O R T A N T   N O T E ------------------------------------//
//
//----------------------------------------------------------------------------//

//----------- (1) INCLUDES ---------------------------------------------------//
#include "ll_gpio.h"

//----------- (2) PRIVATE TYPEDEF --------------------------------------------//
// N/A

//----------- (3) PRIVATE DEFINE ---------------------------------------------//
// N/A

//----------- (4) PRIVATE MACRO ----------------------------------------------//
// N/A

//----------- (5) PRIVATE VARIABLES ------------------------------------------//
// N/A

//----------- (6) PRIVATE FUNCTION PROTOTYPES --------------------------------//
// N/A

//----------- (7) PRIVATE FUNCTIONS ------------------------------------------//

/*!
 *  \fn      void ll_gpio_init(void)
 *  \brief   GPIO initialization
 *  \param   None
 *  \return  None
 */
void ll_gpio_init(void)
{
    // PA2 as input
    GPIO_Init(GPIOA, GPIO_Pin_2, GPIO_Mode_In_PU_No_IT);
    // PA3 as input
    //GPIO_Init(GPIOA, GPIO_Pin_3, GPIO_Mode_In_PU_No_IT);
    // PA4 as input
    //GPIO_Init(GPIOA, GPIO_Pin_4, GPIO_Mode_In_PU_No_IT);
    
    // PB0 as output
    //GPIO_Init(GPIOB, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow);
		//PB0 as float input
		GPIO_Init(GPIOB, GPIO_Pin_0, GPIO_Mode_In_FL_No_IT);
    // PB1 as output
    GPIO_Init(GPIOB, GPIO_Pin_1, GPIO_Mode_Out_PP_Low_Slow);
    // PB3 as output
    GPIO_Init(GPIOB, GPIO_Pin_3, GPIO_Mode_Out_PP_Low_Slow);
    // PB4 as output
    //GPIO_Init(GPIOB, GPIO_Pin_4, GPIO_Mode_Out_PP_Low_Slow);
    // PB5 as output
    GPIO_Init(GPIOB, GPIO_Pin_5, GPIO_Mode_In_FL_No_IT);
    // PB6 as output
    //GPIO_Init(GPIOB, GPIO_Pin_6, GPIO_Mode_Out_PP_Low_Slow);
    // PB7 as output
    //GPIO_Init(GPIOB, GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow);
    // All to '0'
    //GPIO_ResetBits(GPIOB, GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_3 | GPIO_Pin_4 |
    //                                   GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7);
    
    // PF0 as output
    GPIO_Init(GPIOF, GPIO_Pin_0, GPIO_Mode_Out_PP_Low_Slow);
    
    // PD5 as input
  //  GPIO_Init(GPIOD, GPIO_Pin_5, GPIO_Mode_In_PU_No_IT);
    // PD6 as input
   // GPIO_Init(GPIOD, GPIO_Pin_6, GPIO_Mode_In_PU_No_IT);
    
    // PC0 as output Open Drain
    //GPIO_Init(GPIOC, GPIO_Pin_0, GPIO_Mode_Out_OD_Low_Slow);
//    // PC1 as output Open Drain
    //GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_Out_OD_Low_Slow);
    
    // PC5 as input
    //GPIO_Init(GPIOC, GPIO_Pin_5, GPIO_Mode_In_PU_No_IT);
    // PC6 as input
    //GPIO_Init(GPIOC, GPIO_Pin_6, GPIO_Mode_In_PU_No_IT);
    
    // STM8L-DISCO LED3
//    GPIO_Init(GPIOE, GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow);
    // STM8L-DISCO LED4
//    GPIO_Init(GPIOC, GPIO_Pin_7, GPIO_Mode_Out_PP_Low_Slow);
    
    // STM8L-DISCO USR_BTN
    //GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_In_PU_No_IT);
//    GPIO_Init(GPIOC, GPIO_Pin_1, GPIO_Mode_In_PU_IT);
}

//----------- (8) END OF FILE ------------------------------------------------//
