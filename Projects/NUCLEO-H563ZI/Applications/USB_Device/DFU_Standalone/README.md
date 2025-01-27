## <b>Application Description</b>

Compliant implementation of the Device Firmware Upgrade (DFU)
capability to program the embedded Flash memory through the USB peripheral.


At the beginning of the main program the HAL_Init() function is called to reset all the peripherals,
initialize the Flash interface and the systick. The user is provided with the SystemClock_Config() function
to configure the clock (SYSCLK).
The DRD IP in full speed mode (FS) uses internally a 48-MHz clock, which is generated from HSI48.
The DFU transactions are based on Endpoint 0 (control endpoint) transfer. All requests and status
control are sent/received through this endpoint.

In this application, two operating modes are available:
 1. DFU operating mode:
    This mode is entered after an MCU reset in case:
     - The DFU mode is forced by the user: the user presses the USER push-button.
     - No valid code found in the application area: a code is considered valid if the MSB of the initial
       Main Stack Pointer (MSP) value located in the first address of the application area is equal to
       0x20000

 2. Run-time application mode:
    This is the normal run-time activities. A binary which toggles all LEDs on the NUCLEO-H563ZI board is
    provided in Binary directory.

#### <b>Expected success behavior</b>

When plugged to PC host, the STM32H563xx must be properly enumerated as an USB DFU device.
During the enumeration phase, device provides host with the requested descriptors (device, configuration, string).
Those descriptors are used by host driver to identify the device capabilities.
Once the STM32H563xx USB device successfully completed the enumeration phase, open STM32CubeProgrammer you can now download and upload to/from media .

#### <b>Error behaviors</b>

  - LED_RED is toggling to indicate a critical error has occured.
  - Host PC shows that USB device does not appear as DFU device.

#### <b>Assumptions if any</b>

User is familiar with USB 2.0 "Universal Serial BUS" specification and DFU class specification.

#### <b>Known limitations</b>

None

#### Notes
 1. After each device reset (unplug the NUCLEO-H563ZI board from PC), Plug the NUCLEO-H563ZI board with Key USER push-button button
pressed to enter the DFU mode.

 2. A binary which toggles LEDs on the NUCLEO-H563ZI board is provided in Binary directory.

 3. The application needs to ensure that the SysTick time base is set to 1 millisecond
      to have correct HAL configuration.

 4. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
      based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
      a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
      than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
      To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

 5. The built-in USB peripheral of the stm32h5xx does not provide a specific interrupt for USB cable plug/unplug
      detection. The correct way to detect the USB cable plug/unplug is to detect the availability of the VBUS line
      using a normal GPIO pin (external interrupt line).

### USB Library Configuration


It is possible to fine tune needed USB Device features by modifying defines values in USBD configuration
file “usbd_conf.h” available under the project includes directory, in a way to fit the application
requirements, such as:
 - USBD_DFU_APP_DEFAULT_ADD, specifying the address from where user's application will be downloaded.

Device's end address is the end address of the flash memory and it is dependent on the device in use.

### Keywords

Connectivity, USB_Device, USB, DFU, Firmware upgrade


### Hardware and Software environment

  - This application runs on stm32h5xx devices.

  - This application has been tested with STMicroelectronics NUCLEO-H563ZI boards Revision: MB1404-H563ZI-A03
    board and can be easily tailored to any other supported device
    and development board.

  - NUCLEO-H563ZI  board Set-up
    Connect the NUCLEO-H563ZI board  to the PC through micro A-Male to standard A Male cable connected to the connector
    CN11  : to use USB Full speed (FS), Make sure that JP2 is fitted in USB-C position.

### How to use it ?

In order to make the program work, you must do the following:

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - To run the application, proceed as follows:

    - Download the appropriate STM32CubeProgrammer from ST web site and install it.
    - Once you've updated the STM32 DFU device driver you must verify from Windows Device Manager
      that DFU driver is selected with the STM32CubeProgrammer driver.
    - Open "STM32CubeProgrammer", select the usb interface and connect to DFU device.
    - Download the "NUCLEO-H563ZI_LED_Toggle@0x08020000.bin" provided in Binary directory and set the start address.
    - To run the downloaded application, reset the board.
