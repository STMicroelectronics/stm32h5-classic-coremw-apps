## <b>MSC_Standalone Application Description</b>

- This application is a part of the USB Device Library package using STM32Cube firmware. It describes how to
use USB device application based on the Mass Storage Class (MSC) on the STM32H573xx devices.

- This is a typical application on how to use the STM32H573I-DK USB DRD Device peripheral to communicate with a PC
host using the Bulk Only Transfer (BOT) and Small Computer System Interface (SCSI) transparent commands,
while the microSD card is used as storage media. The STM32 MCU is enumerated as a MSC device using the
native PC host MSC driver to which the STM32H573I-DK board is connected.

####  <b>Expected success behavior</b>

- When plugged to PC host, the STM32H573I-DK should be enumerated as a USB MSC device. During the enumeration phase, device must provide host with the requested descriptors (device descriptor, configuration descriptor, string descriptors).

Those descriptors are used by the host driver to identify the device capabilities.

- Once the STM32H573I-DK USB device successfully completes the enumeration phase, a new removable drive appears in the system window and write/read/format operations can be performed as with any other removable drive.

#### <b>Error behaviors</b>

Host PC shows that USB device does not operate as designed (MSC enumeration fails, The new removable drive appears but read, write or format operations fail).

#### <b>Assumptions if any</b>

- User is familiar with USB 2.0 "Universal Serial BUS" Specification and MSC class Specification.
- SD card should be inserted before application is started.

#### <b>Known limitations</b>

- The remote wakeup feature is not yet implemented (used to bring the USB suspended bus back to the active condition).

### <b>Notes</b>

None.

#### <b>USB usage hints</b>

- STM32H573I-DK  Set-up
  - Connect the STM32H573I-DK board to the PC through USB cable to the connector:
    - CN17 : to use USB Full Speed (FS)

### <b>Keywords</b>

Connectivity, USB_Device, USB, SDMMC, MSC, Mass Storage, SD Card, Full Speed, Removable drive, Write, Read,

### <b>Hardware and Software environment</b>

  - This application runs on STM32H573I-DK.
  - This application has been tested with STMicroelectronics STM32H573I-DK boards Revision MB1677-C01
    and can be easily tailored to any other supported device and development board.

### <b>How to use it ?</b>

In order to make the program work, you must do the following :

 - Open your preferred toolchain
 - Rebuild all files and load your image into target memory
 - Run the application
