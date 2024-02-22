#include <ch32v00x.h>
#include <stdio.h>
#include "debug.h"

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	SystemCoreClockUpdate();
	Delay_Init();
	USART_Printf_Init(115200);
	Delay_Ms(1000); // give serial monitor time to open
	printf("SystemClk: %u\r\n", (unsigned)SystemCoreClock);
	printf("DeviceID: %08x\r\n", (unsigned)DBGMCU_GetDEVID());

	while (1)
	{
		Delay_Ms(100);
		printf("Hello From VSDSquadron Mini!!");
	}
}

void NMI_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void NMI_Handler(void) {}
void HardFault_Handler(void) __attribute__((interrupt("WCH-Interrupt-fast")));
void HardFault_Handler(void)
{
	while (1)
	{
	}
}
