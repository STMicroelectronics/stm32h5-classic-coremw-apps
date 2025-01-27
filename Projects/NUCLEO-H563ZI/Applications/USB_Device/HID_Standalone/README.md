## HID_Standalone Application Description

Use of the USB device application based on the Human Interface (HID).

This is a typical application on how to use the stm32h5xx USB Device peripheral, where the STM32 MCU is
enumerated as a HID device using the native PC Host HID driver to which the NUCLEO-H563ZI
board is connected, in order to emulate the Mouse directions using User push-button mounted on the
NUCLEO-H563ZI board.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config() function
to configure the clock (SYSCLK).

#### <b>Expected success behavior</b>

When plugged to PC host, the NUCLEO-H563ZI must be properly enumerated as a USB HID mouse device.
During the enumeration phase, device provides host with the requested descriptors (device, configuration, string).
Those descriptors are used by host driver to identify the device capabilities.
Once the NUCLEO-H563ZI USB device successfully completed the enumeration phase, the device sends an HID report after a user button press.
Each report sent should move the mouse cursor by one step on host side.

#### <b>Error behaviors</b>

  - LED_RED is toggling to indicate a critical error has occured.

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 "Universal Serial BUS" specification and HID class specification.

#### <b>Known limitations</b>

None

#### Notes
 1. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

 2. The application needs to ensure that the SysTick time base is always set to 1 millisecond
      to have correct HAL operation.

For more details about the STM32Cube USB Device library, please refer to UM1734
"STM32Cube USB Device library".

### Keywords

Connectivity, USB_Device, USB, HID, Full Speed, Mouse, Remote Wakeup


### Hardware and Software environment

  - This application runs on STM32H5xx devices.

  - This application has been tested with STMicroelectronics NUCLEO-H563ZI boards Revision: MB1404-H563ZI-A03
    and can be easily tailored to any other supported device and development board.

  - NUCLEO-H563ZI board Set-up
    - Connect the NUCLEO-H563ZI board CN11 to the PC through "TYPE-C" to "Standard A" cable.
    - Press the User push-button  to move the cursor.



### How to use it ?

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application


