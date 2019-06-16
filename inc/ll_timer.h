//! \file ll_timer.h
//! \brief declaration of timer routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01

//----------------------------------------------------------------------------//

#ifndef LL_TIMER_H
#define LL_TIMER_H

//----------- (1) INCLUDES ---------------------------------------------------//
#include "stm8l15x_conf.h"

//----------- (2) EXPORTED TYPES ---------------------------------------------//
// N/A

//----------- (3) EXPORTED CONSTANTS -----------------------------------------//
// N/A

//----------- (4) EXPORTED MACRO ---------------------------------------------//
// N/A

//----------- (5) EXPORTED FUNCTIONS -----------------------------------------//
//void ll_timer4_init(void);
//void ll_timer4_irqHandler(void);
void ll_timer2_init(void);
void ll_timer3_init(void);
void DAC_init(void);
void delay_mS(__IO uint32_t n_mS);

#endif // #ifndef LL_TIMER_H
