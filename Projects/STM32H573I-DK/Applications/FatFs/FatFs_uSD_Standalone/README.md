## <b>FatFs_uSD_Standalone Application Description</b>

How to use STM32Cube firmware with FatFs middleware component as a generic FAT file system module.
This example develops an application that exploits FatFs features to configure a microSD drive.

At the beginning of the main program the HAL_Init() function is called to reset all the peripherals, initialize the Flash interface and the systick.
The SystemClock_Config() function is used to configure the system clock for STM32H573XX Devices :
The CPU at 250 MHz.

The application is based on writing and reading back a text file from a drive,and it's performed using FatFs APIs to access the FAT volume as described
in the following steps:

 - Link the uSD disk I/O driver;
 - Register the file system object (mount) to the FatFs module for the uSD drive;
 - Create a FAT file system (format) on the uSD drive;
 - Create and Open new text file object with write access;
 - Write data to the text file;
 - Close the open text file;
 - Open text file object with read access;
 - Read back data from the text file;
 - Close the open text file;
 - Check on read data from text file;
 - Unlink the uSD disk I/O driver.

It is worth nothing that the application manages any error occurred during the access to FAT volume, when using FatFs APIs. Otherwise, user can check if the
written text file is available on the uSD card.

It is possible to fine tune needed FatFs features by modifying defines values in FatFs configuration file "ffconf.h" available under the project includes
directory, in a way to fit the application requirements.

It is possible to dynamically hot plug/unplug the uSD card, as the application will handle the plug/unplug events.

#### <b>Expected success behavior</b>

- A file named STM32.TXT should be visible in the root directory of the SD card.
- A BLUE LED light marks the success of the file operations.
- A RED LED toggles when SD card is unplugged.

#### <b>Expected error behavior</b>

- On failure, the RED LED is ON while the BLUE LED is switched OFF.
- Error handler is called at the spot where the error occurred.

#### <b>Assumptions if any</b>

- The SD card should be plugged to run the application.
- The board must be reset in case the SD Card is plugged after application start.

#### <b>Known limitations</b>

None

#### <b>Notes</b>

1. for some uSD's, replacing it  while the application is running makes the application fail.
   It is recommended to reset the board using the "Reset button" after replacing the uSD.

2. Care must be taken when using HAL_Delay(), this function provides accurate delay (in milliseconds)
   based on variable incremented in SysTick ISR. This implies that if HAL_Delay() is called from
   a peripheral ISR process, then the SysTick interrupt must have higher priority (numerically lower)
   than the peripheral interrupt. Otherwise the caller ISR process will be blocked.
   To change the SysTick interrupt priority you have to use HAL_NVIC_SetPriority() function.

3. The application needs to ensure that the SysTick time base is always set to 1 millisecond
   to have correct HAL operation.

4. The flag FATFS_MKFS_ALLOWED defined in app_fatfs.c allows the formatting of the SD card. This flag is enabled by default

#### <b>Keywords</b>

FatFs, SDMMC, SD Card, File system, FAT Volume, Format, Mount, Read, Write

#### <b>Hardware and Software environment</b>

  - This application runs on STM32H573xx devices

  - This application has been tested with STMicroelectronics STM32H573I-DK boards revision: MB1677-H573I-C01
    and can be easily tailored to any other supported device and development board.


#### <b>How to use it ?</b>


In order to make the program work, you must do the following:

 - Insert a microSD card in the board appropriate slot
 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application
