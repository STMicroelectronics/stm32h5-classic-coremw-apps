## LwIP_TCP_Echo_Client Application Description

This application guides STM32Cube HAL API users to run TCP Echo Client application
based on Raw API of LwIP TCP/IP stack

To run this application, On the remote PC, open a command prompt window.
(In Windows, select Start > All Programs > Accessories > Command Prompt.)
At the command prompt, enter:
    C:\>echotool /p tcp /s
where:
    - /p transport layer protocol used for communication (TCP)
    - /s is the actual mode of connection (Server mode)

Each time the user pushes the User button of the NUCLEO-H563ZI board, an echo
request is sent to the server

If a DHCP server is available, a dynamic IP address can be allocated by enabling
the DHCP process (#define LWIP_DHCP to 1 in lwipopts.h)

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 240 MHz.

#### Expected success behavior

   - The board's IP address is printed on the HyperTerminal
   - LED_YELLOW is ON indicating the ethernet cable is connected.
   - the client sends an TCP message after a user button press, the message is displayed on the echotool PC console.

#### Error behaviors

   - LED_RED is ON indicating the ethernet cable is not connected.
   - LED_RED is toggling to indicate a critical error has occured.

#### <b>Assumptions if any</b>

None

#### Known limitations
None

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

Connectivity, LwIP, Ethernet, TCP/IP, DHCP, echo Client, UART,

### Directory contents

  - LwIP/LwIP_TCP_Echo_Client/LWIP/App/app_ethernet.h          header of app_ethernet.c file
  - LwIP/LwIP_TCP_Echo_Client/LWIP/Target/ethernetif.h         header for ethernetif.c file
  - LwIP/LwIP_TCP_Echo_Client/Core/Inc/stm32h5xx_hal_conf.h    HAL configuration file
  - LwIP/LwIP_TCP_Echo_Client/Core/Inc/stm32h5xx_it.h          STM32 interrupt handlers header file
  - LwIP/LwIP_TCP_Echo_Client/Core/Inc/main.h                  Main program header file
  - LwIP/LwIP_TCP_Echo_Client/LWIP/Target/lwipopts.h           LwIP stack configuration options
  - LwIP/LwIP_TCP_Echo_Client/Core/Inc/stm32h5xx_nucleo_conf.h NUCLEO-H563ZI configuration file
  - LwIP/LwIP_TCP_Echo_Client/LWIP/App/tcp_echoclien.h         Header for tcp echoserver application
  - LwIP/LwIP_TCP_Echo_Client/LWIP/App/app_ethernet.c          Ethernet specific module
  - LwIP/LwIP_TCP_Echo_Client/Core/Src/stm32h5xx_it.c          STM32 interrupt handlers
  - LwIP/LwIP_TCP_Echo_Client/Core/Src/main.c                  Main program
  - LwIP/LwIP_TCP_Echo_Client/Core/Src/system_stm32h5xx.c      STM32H5xx system clock configuration file
  - LwIP/LwIP_TCP_Echo_Client/LWIP/Target/ethernetif.c         Interfacing LwIP to ETH driver
  - LwIP/LwIP_TCP_Echo_Client/LWIP/App/tcp_echoclient.c        tcp echoserver application


### Hardware and Software environment

  - This application runs on STM32H563xx devices.

  - This application has been tested with the following environments:
     - NUCLEO-H563ZI boards Revision: MB1404-H563ZI-A03
     - echotool: (http://bansky.net/echotool/) is used as echo server that sends
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
 - Edit the file <code> Core/Inc/main.h</code> and correctly define the <DEST_IP_ADDRx> to connect on.
 - Run the [echotool](https://github.com/PavelBansky/EchoTool/releases/tag/v1.5.0.0) utility on a windows console as following:

       c:\> .\echotool.exe /p tcp /s 

 - Rebuild all files and load your image into target memory
 - Run the application
