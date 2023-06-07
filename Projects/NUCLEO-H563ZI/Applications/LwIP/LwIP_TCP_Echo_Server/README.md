## LwIP_TCP_Echo_Server Application Description

This application guides STM32Cube HAL API users to run TCP Echo Server application
based on Raw API of LwIP TCP/IP stack

To run this application, On the remote PC, open a command prompt window.
(In Windows, select Start > All Programs > Accessories > Command Prompt.)
At the command prompt, enter:
  C:\>echotool IP_address /p tcp /r 7 /n 15 /t 2 /d Testing LwIP TCP echo server

where:
    IP_address is the actual board's IP address. If DHCP is disabled,
    the following static IP address is used: 192.168.0.10
    /p transport layer protocol used for communication (TCP)
    /r is the actual remote port on the echo server (echo port)
    /n is the number of echo requests (for application, 15)
    /t is the connection timeout in seconds (for application, 2)
    /d is the message to be sent for echo

LEDs will inform user about ethernet cable status:
 + LD2: ethernet cable is connected.
 + LD3: ethernet cable is not connected.

If a DHCP server is available, a dynamic IP address can be allocated by enabling
the DHCP process (#define LWIP_DHCP to 1 in lwipopts.h), in this case the allocated
address could be read from "gnetif.ip_addr" field:
For example if gnetif.ip_addr.addr = 0x0200A8C0, so the the IPv4 address is "192.168.0.2"

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 240 MHz.

#### Notes 
 1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

 2. The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

For more details about this application, refer to UM1713 "STM32Cube interfacing with LwIP and applications"

### Keywords

Connectivity, LwIP, Ethernet, TCP/IP, DHCP, echo server, UART,

### Directory contents

  - LwIP/LwIP_TCP_Echo_Server/Inc/app_ethernet.h          header of app_ethernet.c file
  - LwIP/LwIP_TCP_Echo_Server/Inc/ethernetif.h            header for ethernetif.c file
  - LwIP/LwIP_TCP_Echo_Server/Inc/stm32h5xx_hal_conf.h    HAL configuration file
  - LwIP/LwIP_TCP_Echo_Server/Inc/stm32h5xx_it.h          STM32 interrupt handlers header file
  - LwIP/LwIP_TCP_Echo_Server/Inc/main.h                  Main program header file
  - LwIP/LwIP_TCP_Echo_Server/Inc/lwipopts.h              LwIP stack configuration options
  - LwIP/LwIP_TCP_Echo_Server/Inc/stm32h5xx_nucleo_conf.h NUCLEO-H563ZI configuration file
  - LwIP/LwIP_TCP_Echo_Server/Inc/tcp_echoserver.h        Header for tcp echoserver application
  - LwIP/LwIP_TCP_Echo_Server/Src/app_ethernet.c          Ethernet specific module
  - LwIP/LwIP_TCP_Echo_Server/Src/stm32h5xx_it.c          STM32 interrupt handlers
  - LwIP/LwIP_TCP_Echo_Server/Src/main.c                  Main program
  - LwIP/LwIP_TCP_Echo_Server/Src/system_stm32h5xx.c      STM32H5xx system clock configuration file
  - LwIP/LwIP_TCP_Echo_Server/Src/ethernetif.c            Interfacing LwIP to ETH driver
  - LwIP/LwIP_TCP_Echo_Server/Src/tcp_echoserver.c        tcp echoserver application


### Hardware and Software environment

  - This application runs on STM32H563xx devices.

  - This application has been tested with the following environments:
     - NUCLEO-H563ZI board
     - echotool: (http://bansky.net/echotool/) is used as echo client that sends
       data to the server and checking whether they came back
     - DHCP server:  PC utility TFTPD32 (http://tftpd32.jounin.net/) is used as a DHCP server

  - This application uses USART3 to display logs, the hyperterminal configuration is as follows:
      - BaudRate = 115200 baud
      - Word Length = 8 Bits
      - Stop Bit = 1
      - Parity = None
      - Flow control = None

  - NUCLEO-H563ZI Set-up
    - Connect the nucleo board to remote PC (through a crossover ethernet cable)
      or to your local network (through a straight ethernet cable)

  - Remote PC Set-up
    - PC must share the same LAN network configuration with the NUCLEO-H563ZI board


### How to use it ?

In order to make the program work, you must do the following :
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application
 