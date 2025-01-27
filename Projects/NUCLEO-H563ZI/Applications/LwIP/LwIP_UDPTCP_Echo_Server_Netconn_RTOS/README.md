## LwIP_UDPTCP_Echo_Server_Netconn_RTOS Application Description

This application guides STM32Cube HAL API users to run a UDP/TCP Echo Server application
based on Netconn API of LwIP TCP/IP stack

To run this application, On the remote PC, open a command prompt window.
(In Windows, select Start > All Programs > Accessories > Command Prompt.)
At the command prompt, enter:
  C:\>echotool IP_address /p tcp /r 7 /n 15 /t 2 /d Testing LwIP TCP echo server
or
  C:\>echotool IP_address /p udp /r 7 /l 7 /n 15 /t 2 /d Testing LwIP UDP echo server
where:
    - IP_address is the actual board's IP address. By default, the following
    static IP address is used: 192.168.0.10
    - /p transport layer protocol used for communication (TCP or UDP)
    - /r is the actual remote port on the echo server (echo port)
    - /l is the actual local port for the client (echo port)
    - /n is the number of echo requests (for application, 15)
    - /t is the connection timeout in seconds (for application, 2)
    - /d is the message to be sent for echo

If a DHCP server is available, a dynamic IP address can be allocated by enabling
the DHCP process (#define LWIP_DHCP to 1 in lwipopts.h)
The user will be notified about the application status with the LEDs and state
messages printed on the HyperTerminal.

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 250 MHz.

#### Expected success behavior
   - The board's IP address is printed on the HyperTerminal
   - LED_YELLOW is ON indicating the ethernet cable is connected.
   - If the echotool utility is used the state of the replies sent by the TCP/UDP server are displayed on the PC console.

#### Error behaviors
   - LED_RED is ON indicating the ethernet cable is not connected.
   - LED_RED is toggling to indicate a critical error has occured.
   - The error message is printed on the HyperTerminal.

#### Assumptions if any
   - If the Application is using the DHCP to acquire IP address, thus a DHCP server should be reachable by the board in
   the LAN used to test the application.
   - The application is configuring the Ethernet IP with a static predefined MAC Address, make sure to change it in case
   multiple boards are connected on the same LAN to avoid any potential network traffic issues.
   - The MAC Address is defined in the stm32h5xx_hal_conf.h

#### Known limitations
None

#### Notes
   1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in HAL time base ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the HAL time base interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the HAL time base interrupt priority you have to use HAL_NVIC_SetPriority() function.

   2. The application needs to ensure that the HAL time base is always set to 1 millisecond
      to have correct HAL operation.

For more details about this application, refer to UM1713 "STM32Cube interfacing with LwIP and applications"


### Keywords

Connectivity, LwIP, Ethernet, Echo Server, Netconn, TCP/IP, RTOS, DHCP

### Directory contents

  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/App/app_ethernet.h          header of app_ethernet.c file
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/Target/ethernetif.h         header for ethernetif.c file
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Inc/stm32h5xx_hal_conf.h    HAL configuration file
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Inc/stm32h5xx_it.h          STM32 interrupt handlers header file
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Inc/main.h                  Main program header file
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/Target/lwipopts.h           LwIP stack configuration options
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Inc/FreeRTOSConfig.h        FreeRTOS configuration options
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/App/tcpecho.h               header for tcpecho.c
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/App/udpecho.h               header for udpecho.c
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Src/stm32h5xx_it.c          STM32 interrupt handlers
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/App/app_ethernet.c          Ethernet specific module
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Src/main.c                  Main program
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/Core/Src/system_stm32h5xx.c      STM32 system clock configuration file
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/Target/ethernetif.c         Interfacing LwIP to ETH driver
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/App/tcpecho.c               tcp echo server main thread
  - LwIP/LwIP_UDPTCP_Echo_Server_Netconn/LWIP/App/udpecho.c               udp echo server main thread


### Hardware and Software environment

  - This application runs on STM32H563xx devices.

  - This application has been tested with the following environments:
     - NUCLEO-H563ZI boards Revision: MB1404-H563ZI-A03
     - echotool: (http://bansky.net/echotool/) is used as client that sends echo requests
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
