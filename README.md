# STM32H5 Classic Core Middleware (CoreMW) MCU Firmware Package

![latest tag](https://img.shields.io/github/v/tag/STMicroelectronics/stm32h5-classic-coremw-apps.svg?color=brightgreen)

![freertos](https://img.shields.io/badge/freertos-v10.6.2-blue.svg) ![fatfs](https://img.shields.io/badge/fatfs-v0.15-blue.svg) ![usb_device](https://img.shields.io/badge/usb_device-v2.11.3-blue.svg) ![usb_host](https://img.shields.io/badge/usb_host-v3.5.3-blue.svg) ![lwip](https://img.shields.io/badge/lwip-v2.1.3-blue.svg)

## Description

**STM32Cube** is an STMicroelectronics original initiative to ease developers' life by reducing efforts, time and cost.

**Classic CoreMW** is a collection of middleware stacks and associated applications allowing RTOS management, File System operations and connectivity through USB and Ethernet. It is based on:
* ST's proprietary stacks: ST USB Device and ST USB Host
* Third parties' stacks: FreeRTOS, FatFS, and LwIP

#### *Note*

 * *FreeRTOS* Middleware and examples are delivered on STM32H5 in the form of X-CUBE-FREERTOS that is available from [st.com](https://www.st.com/en/embedded-software/x-cube-freertos.html), from [GitHub](https://github.com/STMicroelectronics/x-cube-freertos) and from STM32CubeMX.
 * Only *FatFs_RAMDISK_Standalone* application is provided with preconfigured projects for *EWARM*, *Keil MDK-ARM* and *STM32CubeIDE* toolchains. All others are provided **only** with preconfigured projects for *EWARM* toolchain.
 * Projects in this package have not been generated with STM32CubeMX (**i.e.**, no `.ioc` files are delivered).

This package is **exclusively** published on GitHub (and is neither available in STM32CubeMX nor STM32CubeIDE available on www.st.com).
It contains the integration of the Classic CoreMW stacks with *STM32H5* devices, allowing users to get quick access to pre-built projects integrating them.

#### *Note*

 * The repository containing this package has been created using the `git submodule` command. Please refer to the ["How to use"](README.md#how-to-use) section explaining how to clone this repository and how to get the latest updates.

## List of applications

The **STM32H5 Classic CoreMW** package contains the following applications:

Middleware    | Application                            | Short Description
--------------|----------------------------------------|------------------------------------------------------------------------
FatFs         | FatFs_RAMDISK_Standalone               | Shows how to use STM32Cube firmware with FatFs middleware component as a generic FAT file system module
ST USB Device | HID_Standalone                         | Shows a typical application where the STM32 MCU is enumerated as a HID device
ST USB Device | CDC_Standalone                         | Shows a typical application where the STM32 MCU is enumerated as a CDC device
ST USB Device | DFU_Standalone                         | Shows a typical application where the STM32 MCU is enumerated as a DFU device
ST USB Host   | HID_Standalone                         | Shows how to use USB host application based on the Human Interface Class (HID) to connect a mouse or a keyboard
ST USB Host   | MSC_Standalone                         | Shows how to use USB host application based on the Mass Storage Class (MSC) to communicate with a usb flash disk
LwIP          | LwIP_TCP_Echo_Server                   | This application guides STM32Cube HAL API users to run TCP Echo Server application based on Raw API of LwIP TCP/IP stack
LwIP          | LwIP_TCP_Echo_Client                   | This application guides STM32Cube HAL API users to run TCP Echo Client application based on Raw API of LwIP TCP/IP stack
LwIP          | LwIP_UDP_Echo_Server                   | This application guides STM32Cube HAL API users to run UDP Echo Server application based on Raw API of LwIP TCP/IP stack
LwIP          | LwIP_UDP_Echo_Client                   | This application guides STM32Cube HAL API users to run UDP Echo Client application based on Raw API of LwIP TCP/IP stack
LwIP          | LwIP_HTTP_Server_Raw                   | This application guides STM32Cube HAL API users to run a http server application based on Raw API of LwIP TCP/IP stack
LwIP          | LwIP_HTTP_Server_Socket_RTOS           | This application guides STM32Cube HAL API users to run a http server application based on Socket API of LwIP TCP/IP stack
LwIP          | LwIP_HTTP_Server_Netconn_RTOS          | This application guides STM32Cube HAL API users to run a http server application based on Netconn API of LwIP TCP/IP stack
LwIP          | LwIP_UDPTCP_Echo_Server_Netconn_RTOS   | This application guides STM32Cube HAL API users to run a UDP/TCP Echo Server application based on Netconn API of LwIP TCP/IP stack

#### *Note*

 * All examples are provided **only** with pre-configured projects for *EWARM* toolchain.
 * Projects in this package have not been generated with STM32CubeMX (**i.e.**, no `.ioc` files are delivered).

## Boards available

 * STM32H5
   * [NUCLEO-H563ZI](https://www.st.com/en/evaluation-tools/nucleo-h563zi.html) RevB

## Development Toolchains and Compilers

 * IAR Embedded Workbench for ARM (EWARM) toolchain **9.20.1** + ST-LINKV3.Patch available [here](https://github.com/STMicroelectronics/STM32CubeH5/tree/main/Utilities/PC_Software/IDEs_Patches/EWARM)
 * RealView Microcontroller Development Kit (MDK-ARM) toolchain V5.39 + ST-LINKV3.Patch available [here](https://github.com/STMicroelectronics/STM32CubeH5/tree/main/Utilities/PC_Software/IDEs_Patches/MDK-ARM)
 * [STM32CubeIDE **V1.17.0**](https://www.st.com/en/development-tools/stm32cubeide.html) + ST-LINKV3



## Dependencies

This package has been developed and tested using the list of components detailed in the table below.

Name                       |   Version
---------------------------|---------------
Cortex-M CMSIS             |   V5.9.0
STM32H5xx CMSIS            |   V1.3.1
STM32H5xx HAL              |   V1.4.0
BSP STM32H5xx NUCLEO       |   V1.1.1
BSP Common                 |   V7.3.0
BSP lan8742                |   V1.0.4
FatFS                      |   R0.15
LwIP                       |   V2.1.3
STM32 USB Device Library   |   V2.11.3
STM32 USB Host Library     |   V3.5.3
STM32 USBPD Core Library   |   V4.1.1
STM32 USBPD Device Library |   H5_V1.3.0

## How to use

This repository intrinsically contains the applications (projects and source files) located under folder `./Projects`.
It also contains the CMSIS Core files under folder `./Drivers/CMSIS/Include` for size optimization reason.
Other dependencies such as the HAL and BSP drivers, or the middleware libraries themselves are linked using the `git submodule` command.
Please check the instructions below for a proper use.

---

#### *Note*

 * USB-PD library is momentarily contained in this repository pending its publication on GitHub. Once published, it will be added as a submodule like the other components.

---

* To clone this repository along with the linked submodules, option `--recursive` has to be specified as shown below.

```
git clone --recursive https://github.com/STMicroelectronics/stm32h5-classic-coremw-apps.git
```

* To get the latest updates, issue the following **two** commands (with the repository `stm32h5-classic-coremw-apps` as the **current working directory**).

```
git pull
git submodule update --init --recursive
```

#### *Note*

 * If GitHub "Download ZIP" option is used instead of the `git clone` command, then the required components have to be collected manually by the user.

## Known Limitations

 * None

## Troubleshooting

Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) guide.
