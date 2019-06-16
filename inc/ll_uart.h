//! \file ll_uart.h
//! \brief declaration of UART routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01

//----------------------------------------------------------------------------//

#ifndef LL_UART_H
#define LL_UART_H

//----------- (1) INCLUDES ---------------------------------------------------//
#include "stm8l15x_conf.h"

//----------- (2) EXPORTED TYPES ---------------------------------------------//
// N/A

//----------- (3) EXPORTED CONSTANTS -----------------------------------------//
extern uint8_t rxData;

//----------- (4) EXPORTED MACRO ---------------------------------------------//
// N/A

//----------- (5) EXPORTED FUNCTIONS -----------------------------------------//
void ll_uart1_init(void);
void ll_uart1_transmit(uint8_t pData);
void ll_uart1_freq(uint32_t freq);


void ll_uart1_irqHandler(void);

#endif // #ifndef LL_UART_H
