## LwIP_HTTP_Server_Netconn_RTOS Application Description

This application guides STM32Cube HAL API users to run a http server application
based on Netconn API of LwIP TCP/IP stack
The communication is done with a web browser application in a remote PC.

this HTTP server contains two html pages:
  + the first page (home page) is static, it gives information about STM32H5
    and LwIP stack.
  + the second page is dynamically refreshed (every 1 s), it shows the RTOS
    statistics in runtime

the user will be notified about the application status with the LEDs and
state messages printed on the HyperTerminal.

If a DHCP server is available, a dynamic IP address can be allocated by enabling
the DHCP process (#define LWIP_DHCP to 1 in lwipopts.h)

At the beginning of the main program the HAL_Init() function is called to reset
all the peripherals, initialize the Flash interface and the systick.
Then the SystemClock_Config() function is used to configure the system clock
(SYSCLK) to run at 250 MHz.

#### Expected success behavior
   - The board's IP address is printed on the HyperTerminal
   - LED_YELLOW is ON indicating the ethernet cable is connected.
   - Home page is well displayed on the browser after entering the url: http://IP@/STM32H5xx.html
   - RTOS statistics are well displayed on the browser after entering the url: http://IP@/STM32H5xxTASKS.html

#### Error behaviors
   - LED_RED is ON indicating the ethernet cable is not connected.
   - LED_RED is toggling to indicate a critical error has occured.
   - The error message is printed on the HyperTerminal.
   - The web server files are not properly loaded.

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

Connectivity, LwIP, Ethernet, HTTP Server, Netconn, TCP/IP, RTOS, DHCP

### Directory contents

  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/App/app_ethernet.h          header of app_ethernet.c file
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/Target/ethernetif.h         header for ethernetif.c file
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Inc/stm32h5xx_hal_conf.h    HAL configuration file
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Inc/stm32h5xx_it.h          STM32 interrupt handlers header file
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Inc/main.h                  Main program header file
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/Target/lwipopts.h           LwIP stack configuration options
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Inc/FreeRTOSConfig.h        FreeRTOS configuration options
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/App/httpserver_netconn.h    header for httpserver-netconn.c
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Src/stm32h5xx_it.c          STM32 interrupt handlers
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/App/app_ethernet.c          Ethernet specific module
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Src/main.c                  Main program
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/Core/Src/system_stm32h5xx.c      STM32 system clock configuration file
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/Target/ethernetif.c         Interfacing LwIP to ETH driver
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/App/httpserver_netconn.c    httpserver netconn main thread
  - LwIP/LwIP_HTTP_Server_Netconn_RTOS/LWIP/App/fsdata_custom.c         ROM filesystem data (html pages)


### Hardware and Software environment

  - This application runs on STM32H563xx devices.

  - This application has been tested with the following environments:
     - NUCLEO-H563ZI boards Revision: MB1404-H563ZI-A03
     - Http client: Google Chrome (v55)
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
