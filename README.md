# vsdsquadron-mini-research
Building projects with the **VSDSquadron Mini** RISC-V board
![image](./images/mini.png)
[VSDSquadron Mini datasheet](./docs/VSDSQMinidatasheet.pdf)

[VSDSquadron Mini Schematic](./docs/SquadronMini_2A_Schematic.pdf.pdf)
## CH32V003 Chip datasheet
![image](./images/CH32V003.png)
[CH32V003 datasheet](./docs/CH32V003DS0.PDF)

[CH32V003 Reference Manual](./docs/CH32V003RM.PDF)
Features  |
---- |
| QingKe 32-bit RISC-V2A processor, supporting 2 levels of interrupt nesting  |
| Maximum 48MHz system main frequency |
| 2KB SRAM, 16KB Flash |
| Power supply voltage: 3.3/5V |
| Multiple low-power modes: Sleep, Standby |
| Power on/off reset, programmable voltage detector|
| 1 group of 1-channel general-purpose DMA controller|
| 1 group of op-amp comparator|
| 1 group of 10-bit ADC|
| 1×16-bit advanced-control timer, 1×16-bit general-purpose timer|
| 2 WDOG, 1×32-bit SysTick|
| 1 USART interface, 1 group of I2C interface, 1 group of SPI interface|
| 18 I/O ports, mapping an external interrupt|
| 64-bit chip unique ID|
| 1-wire serial debug interface (SDI)|

***
# Application Development
Building a realtime LED clock using I2C
Application steps | Reference links |
--- | --- |
[I2C POC](./I2C_poc) | [I2C lib](https://github.com/hexeguitar/ch32v003fun_libs) |
Driving a I2C LED module | [LED module lib](https://github.com/DFRobot/DFRobot_LedDisplayModule) |
Connecting a I2C realtime clock | [RTC clock module lib](https://github.com/DFRobot/DFRobot_DS3231M) |
Time setting control |
## Block diagram

![image](./images/I2C_RTC_clock.png)

BOM | Link |
--- | --- |
LED Module | [Gravity: 8-Digital LED Segment Display](https://www.dfrobot.com/product-1979.html)
Realtime Clock | [Fermion: DS3231M MEMS Precise RTC](https://www.dfrobot.com/product-1991.html)
I2C Hub | [Gravity: I2C HUB](https://www.dfrobot.com/product-2179.html)
Buttons | [Gravity: Digital Push Button](https://www.dfrobot.com/product-1098.html)
VSDSquadron Mini | (https://www.vlsisystemdesign.com/vsdsquadronmini/)
