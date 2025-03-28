
## <b>DualClass_Standalone Application Description </b>

This application is a part of the USB Host Library package using STM32Cube firmware.

This application is designed for the STM32H573I-DK development board and supports two USB classes: HID and MSC.
The application operate in full-speed (FS).

It describes how to use USB host application based on the STM32H573xx Dual Class support feature integrating Mass Storage (MSC) and Human Interface (HID) in the same project.

#### <b>Expected success behavior</b>

-  In case HID device is plugged to STM32H573I-DK board:

A Message will be displayed on the uart HyperTerminal showing the Vendor ID and Product ID of the attached device. After enumeration phase, a message will indicates that the device is ready for use. The host must be able to properly decode HID reports sent by the corresponding device and display those information on the HyperTerminal.

The received HID reports are used by host to identify:
- in case of a mouse
  - (x,y) mouse position
  - Pressed mouse buttons
- in case of a keyboard
  - Pressed key

-  In case MSC device is plugged to STM32H573I-DK board:

A message will be displayed on the UART HyperTerminal showing the Vendor ID and Product ID of the attached device. After the enumeration phase, a message will indicate that the device is ready for use. The host must be able to properly communicate with the mass storage device and display relevant information on the HyperTerminal.

The host can use the received data to perform operations on the mass storage device, such as reading or writing files. The MSC class APIs provided in the code will assist in communicating with the mass storage device, and the data can be displayed on the HyperTerminal.

#### <b>Error behaviors</b>

Errors are detected such as (Unsupported device, Enumeration Fail) and the corresponding message is displayed on the HyperTerminal.

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 "Universal Serial BUS" Specification, MSC and HID class Specification.

#### <b>Known limitations</b>

None

### <b>Notes</b>

None

### <b>Keywords</b>

Connectivity, USBPD, UART/USART, USB_NOPD_Lib, UCPD, Type C, USB, MSC, HID


### <b>Hardware and Software environment</b>

  - This application runs on STM32H573I devices
  - This application has been tested with STMicroelectronics STM32H573I-DK boards revision MB1677-C01 and can be easily tailored to any other supported device and development board.

- STM32H573I Set-up
    - Plug the USB HID device into the STM32H573I-DK board through 'Type C  to A-Female' cable to the connector:
      - CN17 : to use USB DRD IP in full speed (FS)

    - Connect ST-Link cable to the PC USB port to display data on the HyperTerminal.

    A virtual COM port will then appear in the HyperTerminal:
    - Hyperterminal configuration
      - Data Length = 8 Bits
      - One Stop Bit
      - No parity
      - BaudRate = 115200 baud
      - Flow control: None

### <b>How to use it ?</b>

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application
