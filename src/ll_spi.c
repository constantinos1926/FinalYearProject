//! \file ll_spi.c
//! \brief implementation of SPI routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01


//This was not used

//----------------------------------------------------------------------------//

//----------- I M P O R T A N T   N O T E ------------------------------------//
//
//----------------------------------------------------------------------------//

//----------- (1) INCLUDES ---------------------------------------------------//
#include "ll_spi.h"

//----------- (2) PRIVATE TYPEDEF --------------------------------------------//
// N/A

//----------- (3) PRIVATE DEFINE ---------------------------------------------//
#define SPI_NSS_SET()    GPIOB->ODR |= GPIO_Pin_4
#define SPI_NSS_CLR()    GPIOB->ODR &= (uint8_t)(~GPIO_Pin_4)

//----------- (4) PRIVATE MACRO ----------------------------------------------//
// N/A

//----------- (5) PRIVATE VARIABLES ------------------------------------------//
// N/A

//----------- (6) PRIVATE FUNCTION PROTOTYPES --------------------------------//
// N/A

//----------- (7) PRIVATE FUNCTIONS ------------------------------------------//

/*!
 *  \fn      void ll_spi1_init(void)
 *  \brief   SPI1 initialization
 *  \param   None
 *  \return  None
 */
void ll_spi1_init(void)
{
    SPI_DeInit(SPI1);
    // Enable SPI1 Clock
    CLK_PeripheralClockConfig(CLK_Peripheral_SPI1, ENABLE);
    // Configure SPI1 pin
    GPIO_Init(GPIOB, GPIO_Pin_4, GPIO_Mode_Out_PP_High_Slow); // PB4
    GPIO_Init(GPIOB, GPIO_Pin_5, GPIO_Mode_Out_PP_High_Slow); // PB5
    GPIO_Init(GPIOB, GPIO_Pin_6, GPIO_Mode_Out_PP_High_Slow); // PB6
    GPIO_Init(GPIOB, GPIO_Pin_7, GPIO_Mode_In_FL_No_IT);      // PB7

    GPIO_ExternalPullUpConfig(GPIOB, GPIO_Pin_4, ENABLE);
    GPIO_ExternalPullUpConfig(GPIOB, GPIO_Pin_5, ENABLE);
    GPIO_ExternalPullUpConfig(GPIOB, GPIO_Pin_6, ENABLE);
    GPIO_ExternalPullUpConfig(GPIOB, GPIO_Pin_7, ENABLE);

    SPI_Init(SPI1,
             SPI_FirstBit_MSB,
             SPI_BaudRatePrescaler_4, 
             SPI_Mode_Master,
             SPI_CPOL_Low,
             SPI_CPHA_1Edge,
             SPI_Direction_2Lines_FullDuplex,
             SPI_NSS_Soft,
             0x07);

    SPI_ITConfig(SPI1, SPI_IT_TXE, DISABLE);
    // Enable SPI1
    SPI_Cmd(SPI1, ENABLE);
}

/*!
 *  \fn      void SIC9xxx_readRegister(uint8_t address, uint8_t * result)
 *  \brief   SIC9xxx read register data
 *  \param[in] address
 *  \param[in] result
 *  \return  None
 */
void SIC9xxx_readRegister(uint8_t address, uint8_t * result)
{
    SPI_NSS_CLR();

    SPI1->DR = ((address << 1) & 0x7E) | 0x80;
    while(SPI_GetFlagStatus(SPI1, SPI_FLAG_BSY) == SET)
    {
        ;
    }
    SPI1->DR = 0x00;
    while(SPI_GetFlagStatus(SPI1, SPI_FLAG_BSY) == SET)
    {
        ;
    }
    *result = ((uint8_t)SPI1->DR);

    SPI_NSS_SET();
    SPI_ClearFlag(SPI1, SPI_FLAG_BSY);
}

void SIC9xxx_writeRegister(uint8_t address, uint8_t data)
{
    SPI_NSS_CLR();

    SPI1->DR = (address << 1) & 0x7E;
    while(SPI_GetFlagStatus(SPI1, SPI_FLAG_BSY) == SET)
    {
        ;
    }
    SPI1->DR = data;
    while(SPI_GetFlagStatus(SPI1, SPI_FLAG_BSY) == SET)
    {
        ;
    }

    SPI_NSS_SET();
    SPI_ClearFlag(SPI1, SPI_FLAG_BSY);
}

//----------- (8) END OF FILE ------------------------------------------------//
