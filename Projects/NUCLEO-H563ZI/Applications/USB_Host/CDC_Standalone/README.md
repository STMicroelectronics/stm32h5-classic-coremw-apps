## <b>CDC_Standalone Application Description </b>

This application is a part of the USB Host Library package using STM32Cube firmware. It describes how to use
USB host application based on the Communication Class (CDC) on the STM32H5XX devices.

This is a typical application on how to use the STM32H5xx USB DRD Host peripheral to operate with an USB
CDC device application based on the two CDC transfer directions with a dynamic serial configuration:

 - Transmission:
   by pressing the user button a message "USB_STM32_Host_CDC_ACM" will be sent from the host to a device and this message will be displayed in the hyper terminal of the device in hyperterminal
   The data to be transmitted is stored in the CDC_TX_Buffer and can be viewed via the Hyperterminal.

 - Reception:
   The data entered by the user using the Hyperterminal in ASCII format is transferred by the device board
   to the host board and displayed on the hyperterminal on the host side.
   The CDC_RX_Buffer is the buffer used for receiving data.

#### <b>Expected success behavior</b>

- When plugged to PC host, the NUCLEO-H563ZI must be properly enumerated as an USB Serial device and an STlink Com port.
During the enumeration phase, the device must provide host with the requested descriptors (Device descriptor, configuration descriptor, string descriptors).

- Those descriptors are used by host driver to identify the device capabilities. Once NUCLEO-H563ZI USB device successfully completed the enumeration phase,
Open two hyperterminals (USB com port and UART com port(USB STLink VCP)) to send/receive data to/from host from/to device.

#### <b>Error behaviors</b>

- Host PC shows that USB device does not operate as designed (CDC Device enumeration failed, PC and Device can not communicate over VCP ports).

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 "Universal Serial BUS" specification and CDC class specification.

#### <b>Known limitations</b>

None

#### <b>Notes</b>
1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

2. The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.


It is possible to fine tune needed USB Host features by modifying defines values in USBH configuration
file "usbh_conf.h" available under the project includes directory, in a way to fit the application
requirements, such as:
- Level of debug: USBH_DEBUG_LEVEL
                  0: No debug messages
                  1: Only User messages are shown
                  2: User and Error messages are shown
                  3: All messages and internal debug messages are shown
   By default debug messages are displayed on the debugger IO terminal; to redirect the Library
   messages to uart terminal, stm32h5xx_hal_uart.c driver needs to be added to the application sources.
   Debug messages are displayed on the uart terminal using ST-Link.

For more details about the STM32Cube USB Host library, please refer to UM1720
"STM32Cube USB Host library".

### <b>Keywords</b>

Connectivity, USB_Host, USB, CDC, Human Interface, UART/USART


### <b>Directory contents</b>

    - USB_Host/CDC_Standalone/Core/Src/main.c                         Main program
    - USB_Host/CDC_Standalone/Core/Src/system_stm32h5xx.c             STM32H5xx  system clock configuration File
    - USB_Host/CDC_Standalone/Core/Src/stm32h5xx_it.c                 Interrupt handlers
    - USB_Host/CDC_Standalone/Core/Src/stm32h5xx_hal_msp.c            HAL MSP Module
    - USB_Host/CDC_Standalone/Core/Inc/main.h                         Main program header File
    - USB_Host/CDC_Standalone/Core/Inc/stm32h5xx_hal_conf.h           HAL configuration File
    - USB_Host/CDC_Standalone/Core/Inc/stm32h5xx_it.h                 Interrupt handlers header File
    - USB_Host/CDC_Standalone/USB_Host/App/usb_host.c                 CDC State Machine
    - USB_Host/CDC_Standalone/USB_Host/App/cdc_receive.c              CDC Receive State Machine
    - USB_Host/CDC_Standalone/USB_Host/App/cdc_send.c                 CDC Send State Machine
    - USB_Host/CDC_Standalone/USB_Host/App/usb_host.h                 CDC State Machine Header File
    - USB_Host/CDC_Standalone/USB_Host/App/cdc_receive.h              CDC Receive functions Header File
    - USB_Host/CDC_Standalone/USB_Host/App/cdc_send.h                 CDC Send functions Header File
    - USB_Host/CDC_Standalone/USB_Host/Target/usbh_conf.c             General low level driver configuration
    - USB_Host/CDC_Standalone/USB_Host/Target/usbh_conf.h             USB Host driver configuration File


### <b>Hardware and Software environment</b>

  - This application runs on STM32H5xx devices.

  - This application has been tested with STMicroelectronics NUCLEO-H563ZI boards Revision: MB1404-H563ZI-C01
    and can be easily tailored to any other supported device and development board.


  - NUCLEO-H563ZI Set-up

    - JP2 must be connected (USB_C position) to provide power to VBUS and to the connected USB device.
          When JP2 is ON, the VBUS LED (LD7) turns on to indicate that power is provided to CN13.

    - Plug the USB key into the NUCLEO-H563ZI board through 'USB Type C-Male
      to A-Female' cable to the connector:CN13
    - Connect ST-Link cable to the PC USB port to display data on the HyperTerminal.

    A virtual COM port will then appear in the HyperTerminal:

     - Hyperterminal configuration:
      - Data Length = 8 Bits
      - One Stop Bit
      - No parity
      - BaudRate = 115200 baud
      - Flow control: None

  - The UART3 communication between the target MCU and ST-LINK MCU is enabled. It's configuration is as following:
    - BaudRate = 115200 baud
    - Word Length = 8 Bits
    - Stop Bit = 1
    - Parity = None
    - Flow control = None

### <b>How to use it ?</b>

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Open the configured uart hyperterminal in order to display debug messages.
 - Run the application
 - Open the configured uart hyperterminal in order to display debug messages.


#### Notes
   The user has to check the list of the COM ports in Device Manager to find out the number of the
   COM ports that have been assigned (by OS) to the Stlink VCP .
