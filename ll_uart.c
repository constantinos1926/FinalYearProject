//! \file ll_uart.c
//! \brief implementation of UART routines
//! \author Constantinos Nicolaou
//! \date 2019-06-01


//----------------------------------------------------------------------------//

//----------- I M P O R T A N T   N O T E ------------------------------------//
//
//----------------------------------------------------------------------------//

//----------- (1) INCLUDES ---------------------------------------------------//
#include "ll_uart.h"

//----------- (2) PRIVATE TYPEDEF --------------------------------------------//
// N/A

//----------- (3) PRIVATE DEFINE ---------------------------------------------//
// N/A

//----------- (4) PRIVATE MACRO ----------------------------------------------//
// N/A

//----------- (5) PRIVATE VARIABLES ------------------------------------------//
uint8_t rxData;

//----------- (6) PRIVATE FUNCTION PROTOTYPES --------------------------------//
// N/A

//----------- (7) PRIVATE FUNCTIONS ------------------------------------------//

/*!
 *  \fn      void ll_uart1_init(void)
 *  \brief   UART1 initialization
 *  \param   None
 *  \return  None
 */
void ll_uart1_init(void)
{
    // Enable UART1 Clock
    CLK_PeripheralClockConfig(CLK_Peripheral_USART1, ENABLE);
    // Configure PC3: UART1_TX as alternate function
    GPIO_ExternalPullUpConfig(GPIOC, GPIO_Pin_3, ENABLE);
    // Configure PC2: UART1_RX as alternate function
    GPIO_ExternalPullUpConfig(GPIOC, GPIO_Pin_2, ENABLE);
    // UART1 Configuration
    USART_Init(USART1,
               (uint32_t) 115200,
               USART_WordLength_8b,
               USART_StopBits_1,
               USART_Parity_No,
               (USART_Mode_Rx | USART_Mode_Tx));
    // Enable RX Interrupt
	USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
    // Enable UART1
    USART_Cmd(USART1, ENABLE);
}

/*!
 *  \fn      void ll_uart1_transmit(uint8_t *pData, uint16_t size)
 *  \brief   UART1 transmit data
 *  \param[in] pData
 *  \param[in] size  number of bytes
 *  \return  None
 */
 //Data transfer to smartphone via UART
void ll_uart1_transmit(uint8_t pData)
{
        USART_SendData8(USART1, pData-48);
        // wait for transmission completed
        while((USART1->SR & USART_FLAG_TXE) == 0);
}

void ll_uart1_freq(uint32_t freq)
{
	char value[10]; //a temp array to hold results of conversion
  int i = 0; //loop index
  
  do
  {
    value[i++] = (char)(freq % 10) + '0'; //convert integer to character
    freq /= 10;
  } while(freq);
  
  while(i) //send data
  {
    ll_uart1_transmit(value[--i]); 
  }

}
/*!
 *  \fn      void ll_uart1_irqHandler(void)
 *  \brief   UART1 interrupt handler 
 *  \param   None
 *  \return  None
 */
 //Function when UART message comes from user
void ll_uart1_irqHandler(void)
{
    uint8_t tmpData;
    
    tmpData = USART_ReceiveData8(USART1);
    rxData  = tmpData;
    
//    USART_SendData8(USART1, rxData);
//    while((USART1->SR & USART_FLAG_TXE) == 0);
    
//    ll_uart1_transmit("123", 3);
}

//----------- (8) END OF FILE ------------------------------------------------//
