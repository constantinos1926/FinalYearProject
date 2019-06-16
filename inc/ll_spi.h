//! \file ll_spi.h
//! \brief declaration of SPI routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01


//----------------------------------------------------------------------------//

#ifndef LL_SPI_H
#define LL_SPI_H

//----------- (1) INCLUDES ---------------------------------------------------//
#include "stm8l15x_conf.h"

//----------- (2) EXPORTED TYPES ---------------------------------------------//
// N/A

//----------- (3) EXPORTED CONSTANTS -----------------------------------------//
// N/A

//----------- (4) EXPORTED MACRO ---------------------------------------------//
// N/A

//----------- (5) EXPORTED FUNCTIONS -----------------------------------------//
void ll_spi1_init(void);

void SIC9xxx_readRegister(uint8_t address, uint8_t * result);
void SIC9xxx_writeRegister(uint8_t address, uint8_t data);

#endif // #ifndef LL_SPI_H
