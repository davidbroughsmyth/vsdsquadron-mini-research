/*
 Serial character echo program:
 GPIO: USART1_Tx(PD5)\USART1_Rx(PD6).
 This routine demonstrates that USART1 receives the data sent by a TTL serial
 module and send it back, spaced by a "-" character at baud rate 115200.

 Hardware connection:PD5 -- Rx
                     PD6 -- Tx
*/

#include "debug.h"

/* Global Variable */
vu8 val;

/*********************************************************************
 * @fn      USARTx_CFG
 *
 * @brief   Initializes the USART1 peripheral.
 *
 * @return  none
 */
void USARTx_CFG(void) {
  GPIO_InitTypeDef GPIO_InitStructure = {0};
  USART_InitTypeDef USART_InitStructure = {0};

  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_USART1, ENABLE);

  /* USART1 TX-->D.5   RX-->D.6 */
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOD, &GPIO_InitStructure);

  USART_InitStructure.USART_BaudRate = 115200;
  USART_InitStructure.USART_WordLength = USART_WordLength_8b;
  USART_InitStructure.USART_StopBits = USART_StopBits_1;
  USART_InitStructure.USART_Parity = USART_Parity_No;
  USART_InitStructure.USART_HardwareFlowControl =
      USART_HardwareFlowControl_None;
  USART_InitStructure.USART_Mode = USART_Mode_Tx | USART_Mode_Rx;

  USART_Init(USART1, &USART_InitStructure);
  USART_Cmd(USART1, ENABLE);
}

/*********************************************************************
 * @fn      main
 *
 * @brief   Main program.
 *
 * @return  none
 */
int main(void) {
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  Delay_Init();
  USART_Printf_Init(115200);
  Delay_Ms(100); // give serial monitor time to open
  printf("SystemClk:%u\r\n", (unsigned)SystemCoreClock);
  printf("DeviceID: %08x\r\n", (unsigned)DBGMCU_GetDEVID());
  printf("Enter text:\r\n");

  USARTx_CFG();

  while (1) {

    while (USART_GetFlagStatus(USART1, USART_FLAG_RXNE) == RESET) {
      /* waiting for receiving finish */
    }
    val = (USART_ReceiveData(USART1));
    USART_SendData(USART1, 0x2d); // Send a "-"
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET) {
      /* waiting for sending finish */
    }
    USART_SendData(USART1, val);
    while (USART_GetFlagStatus(USART1, USART_FLAG_TXE) == RESET) {
      /* waiting for sending finish */
    }
  }
}