## <b>LwIP_TFTP_Server application Description</b>

This application guides STM32Cube HAL API users to run a tftp server application.

- User has to use a PC SW tool (ex. TFTPD32) to send/receive data to/from micro SD card installed in STM32H573I-DK board.
- If a DHCP server is available, a dynamic IP address can be allocated by enabling the DHCP process (#define LWIP_DHCP in lwipopts.h)
- The maximum length of filename used to send or to receive to/from uSD is set to 8 bytes and 3 bytes for file type
- The maximum transfer block size is set 512 Bytes
- Please insure that the uSD is plugged before starting, this application doesn't handle hot plug/unplug of the uSD card
- At the beginning of the main program, the HAL_Init() function is called to reset all the peripherals and initialize the systick used as 1ms HAL timebase.
- The SystemClock_Config() function is used to configure the system clock for STM32H573XX Devices.
- The CPU at 250 MHz.

####  <b>Expected success behavior</b>

   - LED_ORANGE is ON indicating the board IP address has been assigned
   - The board IP address is printed on the HyperTerminal
   - The user can send/receive data to/from micro SD card using TFTPD32 SW tool

#### <b>Expected error behavior</b>

   - LED_RED is ON indicating the ethernet cable is not connected
   - LED_RED is toggling to indicate a critical error has occurred
   - The error message is printed on the HyperTerminal
   - Timeout message is displayed on TFTPD32 SW tool

#### <b>Assumptions if any</b>

   - The application is using the DHCP to acquire IP address, thus a DHCP server should be reachable by the board in the LAN used to test the application.
   - The application is configuring the Ethernet IP with a static predefined MAC Address, make sure to change it in case
   multiple boards are connected on the same LAN to avoid any potential network traffic issues.
   - The MAC Address is defined in the stm32h5xx_hal_conf.h

#### <b>Known limitations</b>
None

### <b>Notes</b>

 1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
    based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
    a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
    than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
    To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

 2. The application needs to ensure that the SysTick time base is always set to 1 millisecond
    to have correct HAL operation.

### <b>Keywords</b>

Connectivity, LwIP, Ethernet, TFTP Server, TCP/IP, DHCP, send, receive, SD Card

### <b>Directory contents</b>


    - LwIP/LwIP_TFTP_Server/LWIP/Target/ethernetif.h              header for ethernetif.c file
    - LwIP/LwIP_TFTP_Server/LWIP/App/app_ethernet.h               header of app_ethernet.c file
    - LwIP/LwIP_TFTP_Server/Core/Inc/ffconf.h                     FAT file system module configuration file
    - LwIP/LwIP_TFTP_Server/LWIP/Target/lwipopts.h                LwIP stack configuration options
    - LwIP/LwIP_TFTP_Server/Core/Inc/main.h                       Main program header file
    - LwIP/LwIP_TFTP_Server/Core/Inc/sd_diskio_config.h           SD Disk IO header file
    - LwIP/LwIP_TFTP_Server/LWIP/App/tftpserver.h                 header for tftpserver.c
    - LwIP/LwIP_TFTP_Server/LWIP/App/tftputils.h                  header for tftputils.c
    - LwIP/LwIP_TFTP_Server/Core/Inc/stm32h5xx_it.h               header for stm32h5xx_it.c
    - LwIP/LwIP_TFTP_Server/Core/Inc/stm32h5xx_hal_conf.h         HAL Configuration file
    - LwIP/LwIP_TFTP_Server/LWIP/Target/ethernetif.c              Interfacing LwIP to ETH driver
    - LwIP/LwIP_TFTP_Server/LWIP/App/app_ethernet.c               Ethernet specific module
    - LwIP/LwIP_TFTP_Server/LWIP/App/tftpserver.c                 tftp server application
    - LwIP/LwIP_TFTP_Server/LWIP/App/tftputils.c                  tftp server utilities functions
    - LwIP/LwIP_TFTP_Server/Core/Src/system_stm32h5xx.c           STM32 system configuration file
    - LwIP/LwIP_TFTP_Server/Core/Src/stm32h5xx_it.c               Interrupt handlers
    - LwIP/LwIP_TFTP_Server/Core/Inc/stm32h5xx_hal_msp.c          HAL MSP module
    - LwIP/LwIP_TFTP_Server/Core/Inc/main.c                       Main program

### <b>Hardware and Software environment</b>

  - This application runs on STM32H573xx devices.

  - This application has been tested with the following environments:
    - STM32H573I-DK MB1677 Rev. C01 board
    - DHCP server:  PC utility TFTPD32 (http://tftpd32.jounin.net/) is used as a DHCP server

  - STM32H573I-DK MB1677 Rev. C01 Set-up
    - Connect the board to remote PC (through a crossover ethernet cable) or to your local network (through a straight ethernet cable)

  - This application uses UART1 to display logs, the hyperterminal configuration is as follows:
    - BaudRate = 115200 baud
    - Word Length = 8 Bits
    - Stop Bit = 1
    - Parity = None
    - Flow control = None

  - Remote PC Set-up:
    - PC must share the same LAN network configuration with the STM32H573I-DK board.


### <b>How to use it ?</b>

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application
 - Use PC utility TFTPD32 to perform file transfers.

