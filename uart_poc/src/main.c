#include "debug.h"
#include <ch32v00x.h>
#include <stdio.h>

#define BLINKY_GPIO_PORT GPIOD
#define BLINKY_GPIO_PIN GPIO_Pin_6
#define BLINKY_CLOCK_ENABLE RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE)

void Delay_Init(void);
void Delay_Ms(uint32_t n);

int main(void) {
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
  SystemCoreClockUpdate();
  Delay_Init();

  GPIO_InitTypeDef GPIO_InitStructure = {0};

  BLINKY_CLOCK_ENABLE;
  GPIO_InitStructure.GPIO_Pin = BLINKY_GPIO_PIN;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(BLINKY_GPIO_PORT, &GPIO_InitStructure);

  uint8_t ledState = 0;

  USART_Printf_Init(115200);
  Delay_Ms(1000); // give serial monitor time to open
  printf("SystemClk: %u\r\n", (unsigned)SystemCoreClock);
  printf("DeviceID: %08x\r\n", (unsigned)DBGMCU_GetDEVID());

  int i = 0;

  while (1) {
    GPIO_WriteBit(BLINKY_GPIO_PORT, BLINKY_GPIO_PIN, ledState);
    ledState ^= 1; // invert for the next run
    Delay_Ms(100);
    printf("VSDSquadron Mini wants a beetroot burger: %d\n\r", i++);
  }
}

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void NMI_Handler(void) {}
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void) {
  while (1) {
  }
}
