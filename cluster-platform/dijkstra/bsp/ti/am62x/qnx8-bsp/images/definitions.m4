## Boot parameters
define(`__LD_QNX__',            `ldqnx-64.so.2')
define(`__BOOT_ADDR__',         `0x80080000')
define(`__ARCH__',              `aarch64le')
define(`__TYPE__',              `raw')
define(`__COMPRESS_ATTR__',     `+compress')
define(`__PROCNTO_MODULES__',   `')
define(`__STARTUP__',           `startup-am62p-evm')
define(`__STARTUP_OPTS__',      `-u arg -v -r0x93500000,0x0CAFFFFF,1 -r0xC0000000,0x30000000,1 -r0x880000000,0x30000000,1')
define(`__PROCNTO__',           `procnto-smp-instr')
define(`__PROCNTO_OPTS__',      `-v -mr')

## Console
define(`__CONSOLE__',           `/dev/ser1')

## ENV profile, use to overwrite the common /etc/profile
#define(`__ENV_PROFILE_FILE__',  `')
#define(`__PROFILE_CFG__',       `/__ENV_PROFILE_FILE__ = {
#export HOME=/
#export SYSNAME=nto
#export TERM=qansi
#export PATH=/proc/boot:/sbin:/bin:/usr/bin:/usr/sbin:/usr/libexec
#export LD_LIBRARY_PATH=/proc/boot:/lib:/usr/lib:/lib/dll:/lib/dll/pci
#}')

## Block driver
define(`__BLOCK_DRVR__', `devb-ram, devb-sdmmc-am65x')

#define(`__DEVB_EIDE_DRVR__', `')
#define(`__DEVB_EIDE_OPTS__', `')
#define(`__DEVB_EIDE_DEV__', `')

#define(`__DEVB_NVME_DRVR__', `')
#define(`__DEVB_NVME_OPTS__', `')
#define(`__DEVB_NVME_DEV__', `')

define(`__DEVB_RAM_DRVR__', `devb-ram')
#define(`__DEVB_RAM_OPTS__', `')
#define(`__DEVB_RAM_DEV__', `')

define(`__DEVB_SDMMC_DRVR__', `devb-sdmmc-am65x')
#define(`__DEVB_SDMMC_OPTS__', `')
#define(`__DEVB_SDMMC_DEV__', `')

define(`__DEVB_SDMMC_START__', `
    ############################################################################################
    ## SD memory card / eMMC driver
    ############################################################################################
    display_msg Starting MMC/SD memory card driver... eMMC
    __DEVB_SDMMC_DRVR__ sdio addr=0x0fa10000,irq=165,emmc,bs=sscfg=0x8000 disk name=emmc

    display_msg Starting MMC/SD memory card driver... SD
    __DEVB_SDMMC_DRVR__ sdio addr=0x0fa00000,irq=115,bs=sscfg=0x8000:ldo=0x600000^31:trm-icp=2 cam pnp disk name=sd
')

define(`__DEVB_DRVR_START__', `
__DEVB_SDMMC_START__
')

## Network driver
#define(`__NET_DRVR__', `')
define(`__NET_OPTS__', `')
define(`__NET_DEV__', `')
define(`__NET_START__', `
    ############################################################################################
    ## CPSW3G Configuration
    ############################################################################################
    ## De-assert GPIO_CPSW1_RST(P22) and GPIO_CPSW2_RST(P23) to set as outputs
    sh -c "isend -n/dev/i2c1 -a0x23 0x0e > /dev/null 2>&1"
    sh -c "isendrecv -n /dev/i2c1 -a0x23 -l1 > /dev/null 2>&1"
    ## Returns ffh
    sh -c "isend -n/dev/i2c1 -a0x23 0x0e 0xf3 > /dev/null 2>&1"
    sh -c "isend -n/dev/i2c1 -a0x23 0x0e > /dev/null 2>&1"
    sh -c "isendrecv -n /dev/i2c1 -a0x23 -l1 > /dev/null 2>&1"
    ## Read to confirm f3h was written
    ## Set P22 and P23 to 1
    sh -c "isend -n/dev/i2c1 -a0x23 0x06 > /dev/null 2>&1"
    sh -c "isendrecv -n /dev/i2c1 -a0x23 -l1 > /dev/null 2>&1"
    # Returns ffh
    sh -c "isend -n/dev/i2c1 -a0x23 0x06 0xff > /dev/null 2>&1"
    sh -c "isend -n/dev/i2c1 -a0x23 0x06 > /dev/null 2>&1"
    sh -c "isendrecv -n /dev/i2c1 -a0x23 -l1 > /dev/null 2>&1"
    #  Read to confirm ffh was written

    #######################################################################
    ## Using CPSW driver that requires PSDK support
    #######################################################################
    #display_msg "Starting networking ..."
    `#'io-sock -m phy ifdef(`__NET_OPTS__', `__NET_OPTS__') ifdef(`__PCI_HW_MODULE__', `__NET_PCI_OPTS__') ifdef(`__USB_HOST_DRVR__', `__NET_USB_OPTS__') ifdef(`__HYP__', `__NET_HYP_OPTS__') -mfdt -dcpsw-am62p


__NET_COMMON_START__
')


## USB host driver
define(`__USB_HOST_DRVR__', `devu-hcd-dwc3-xhci.so')
define(`__LOCAL_XHCI_OPTS__', `-d dwc3-xhci ioport=0x31000000,irq=220,ioport=0x31100000,irq=258')
define(`__USB_HOST_OPTS__', `__LOCAL_XHCI_OPTS__')
define(`__USB_HOST_DEV__', `/dev/usb/io-usb-otg')

define(`__USB_START__', `
    #######################################################################
    ## XHCI on both USB-C and A ports
    #######################################################################
    display_msg Starting XHCI driver on USB3SS0 and USB3SS1
    io-usb-otg -d dwc3-xhci ioport=0x31000000,irq=220,ioport=0x31100000,irq=258
    waitfor /dev/usb/io-usb-otg 4
')

## USB device driver
#define(`__USB_DEVICE_DRVR__', `')

## Persistent storage
define(`__PERSISTENT_STORAGE_DEVICE__', `/dev/sd0t179')
#define(`__PERSISTENT_STORAGE_MOUNT_POINT__', `')
#define(`__PERSISTENT_STORAGE_MOUNT_OPTS__', `')
#define(`__PERSISTENT_STORAGE_START__', `')
#define(`__PERSISTENT_STORAGE_FILES__', `')

## Serial driver
define(`__DEVC_DRVR__', `devc-seromap')
#define(`__DEVC_OPTS__', `')
#define(`__DEVC_DEV__', `')

define(`__DEVC_START__', `
    #######################################################################
    ## UART drivers
    #######################################################################
    display_msg "start serial driver"
    __DEVC_DRVR__ -e -F 0x02800000,210
    waitfor /dev/ser1
')

## I2C driver
define(`__I2C_DRVR__', `i2c-tda4')
define(`__I2C_OPTS__', `-p0x20000000 -i193 -d --u0, -p0x20010000 -i194 -d --u1, -p0x20020000 -i195 -d --u2')
define(`__I2C_DEV__', `/dev/i2c0, /dev/i2c1, /dev/i2c2')

## NOR flash driver
define(`__NOR_DRVR__', `devf-j7-ospi')

define(`__NOR_START__', `
    #######################################################################
    ## OSPI NOR flash driver without UDMA support
    #######################################################################
    display_msg "Starting Flash driver..."
    __NOR_DRVR__ -s soc=rclk=200000000:base=0xfc40000:clk=25000000:rdelay=4
    #######################################################################
    ## OSPI NOR flash driver with UDMA support
    ## need tisci-mgr and tiudma-mgr to access TI UDMA library
    ## need "-I" option to access UDMA registers
    ## need direct and PHY mode for DMA transfer
    #######################################################################
    # display_msg "Starting Flash driver..."
    `#' __NOR_DRVR__ -I -s soc=rclk=200000000:base=0xfc40000:clk=25000000:rdelay=4:poffset=0x3fc0000:phy=otp1:dma=1:pdelay=1
')

## Random
#define(`__RANDOM_DRVR__', `')
#define(`__RANDOM_DRVR_OPTS__', `')

## DMA
#define(`__DMA_DRVR__', `libdma-edma.so')

## RTC
#define(`__RTC_DRVR__', `rtc')
#define(`__RTC_OPTS__', `hw')
#define(`__RTC_START__', `
    ############################################################################################
    ## RTC utility - requires i2c driver to be running
    ############################################################################################
#    display_msg "Setting OS clock from RTC ..."
#    __RTC_DRVR__ __RTC_OPTS__
#')

## graphics support
#ifdef(`__GRAPHICS__', `
#define(`__GRAPHICS_LIB_PATH__', `/usr/lib/graphics/am62p')
#define(`__GRAPHICS_SCREEN_OPT__', `-c /usr/lib/graphics/am62p/graphics.conf')

#define(`__GRAPHICS_START__', `
    ############################################################################################
    ## Start the screen graphics
    ############################################################################################
#    display_msg "Starting Screen Graphics..."
#    screen __GRAPHICS_SCREEN_OPT__
#    waitfor /dev/screen
#')

#define(`__GRAPHICS_BOARD_SPECIFIC_FILES__', `
################################################################################################
## Screen Board Support am62p (com.qnx.qnx800.target.screen.board.am62p)
################################################################################################
#/usr/lib/graphics/am62p/graphics.conf=graphics/am62p/graphics.conf

#/usr/lib/graphics/am62p/libglslcompiler.so=graphics/am62p/libglslcompiler.so
#/usr/lib/graphics/am62p/libIMGegl.so=graphics/am62p/libIMGegl.so
#/usr/lib/graphics/am62p/libIMGGLESv2.so=graphics/am62p/libIMGGLESv2.so
#/usr/lib/graphics/am62p/libPVROCL.so=graphics/am62p/libPVROCL.so
#/usr/lib/graphics/am62p/libPVRScopeServices.so=graphics/am62p/libPVRScopeServices.so
#/usr/lib/graphics/am62p/libpvrSCREEN_WSEGL.so=graphics/am62p/libpvrSCREEN_WSEGL.so
#/usr/lib/graphics/am62p/libsrv_km.so=graphics/am62p/libsrv_km.so
#/usr/lib/graphics/am62p/libsrv_um.so=graphics/am62p/libsrv_um.so
#/usr/lib/graphics/am62p/libufwriter.so=graphics/am62p/libufwriter.so
#/usr/lib/graphics/am62p/libVK_IMG.so=graphics/am62p/libVK_IMG.so
#/usr/lib/graphics/am62p/libWFDam62p.so=graphics/am62p/libWFDam62p.so
#/usr/lib/graphics/am62p/libwfdcfg-am62p-evm.so=graphics/am62p/libwfdcfg-am62p-evm.so
#/usr/lib/graphics/am62p/rgx_vulkan_icd.json=graphics/am62p/rgx_vulkan_icd.json
#/usr/lib/graphics/am62p/screen-jacinto7-alloc.so=graphics/am62p/screen-jacinto7-alloc.so

#/usr/lib/graphics/am62p-debug/libglslcompiler.so=graphics/am62p-debug/libglslcompiler.so
#/usr/lib/graphics/am62p-debug/libIMGegl.so=graphics/am62p-debug/libIMGegl.so
#/usr/lib/graphics/am62p-debug/libIMGGLESv2.so=graphics/am62p-debug/libIMGGLESv2.so
#/usr/lib/graphics/am62p-debug/libPVROCL.so=graphics/am62p-debug/libPVROCL.so
#/usr/lib/graphics/am62p-debug/libPVRScopeServices.so=graphics/am62p-debug/libPVRScopeServices.so
#/usr/lib/graphics/am62p-debug/libpvrSCREEN_WSEGL.so=graphics/am62p-debug/libpvrSCREEN_WSEGL.so
#/usr/lib/graphics/am62p-debug/libsrv_km.so=graphics/am62p-debug/libsrv_km.so
#/usr/lib/graphics/am62p-debug/libsrv_um.so=graphics/am62p-debug/libsrv_um.so
#/usr/lib/graphics/am62p-debug/libufwriter.so=graphics/am62p-debug/libufwriter.so
#/usr/lib/graphics/am62p-debug/libVK_IMG.so=graphics/am62p-debug/libVK_IMG.so
#/usr/lib/graphics/am62p-debug/libWFDam62p.so=graphics/am62p-debug/libWFDam62p.so
#/usr/lib/graphics/am62p-debug/libwfdcfg-am62p-evm.so=graphics/am62p-debug/libwfdcfg-am62p-evm.so
#/usr/lib/graphics/am62p-debug/rgx_vulkan_icd.json=graphics/am62p-debug/rgx_vulkan_icd.json
#/usr/lib/graphics/am62p-debug/screen-jacinto7-alloc.so=graphics/am62p-debug/screen-jacinto7-alloc.so


#')
#')

## Customize script
define(`__CUSTOMIZE_SCRIPT_NAME__', `/scripts/board_startup.sh')
#define(`__CUSTOMIZE_SCRIPT_START__', `')
#define(`__CUSTOMIZE_SCRIPT_FILES__', `')



## Board specific files
define(`__BOARD_EARLY_START__', `
    #######################################################################
    ## TI SCI / IPC Resource Managers
    #######################################################################
    #tisci-mgr
    #waitfor /dev/tisci 4
    #shmemallocator
    #waitfor /dev/shmemallocator 4
    #tiipc-mgr
    #waitfor /dev/tiipc 4
    #tiudma-mgr
    #waitfor /dev/tiudma 4
')

define(`__BOARD_LATE_START__', `
')

define(`__BOARD_FILES__', `
###########################################################################
## CPSW files
## Using CPSW driver that requires PSDK support
###########################################################################
/lib/dll/devs-cpsw-am62p.so=devs-cpsw-am62p.so

###########################################################################
## Binaries from TI PSDK
## These binaries should NOT be distributed outside of QNX.
## These binaries are developed by TI and any customers or outside
## partners should be contacting TI to get their latest PSDK.
###########################################################################
#[search=../install/aarch64le/sbin${PFS}${PSDK_QNX_PATH}/qnx/resmgr/sciclient_qnx_rsmgr/aarch64/o.le/ perms=a+x] tisci-mgr
#[search=../install/aarch64le/sbin${PFS}${PSDK_QNX_PATH}/qnx/resmgr/ipc_qnx_rsmgr/resmgr/aarch64/o.le/ perms=a+x] tiipc-mgr
#[search=../install/aarch64le/sbin${PFS}${PSDK_QNX_PATH}/qnx/resmgr/udma_qnx_rsmgr/resmgr/aarch64/o.le/ perms=a+x] tiudma-mgr
#[search=../install/aarch64le/sbin${PFS}${PSDK_QNX_PATH}/qnx/sharedmemallocator/resmgr/aarch64/o.le/ perms=a+x] shmemallocator
#[search=../install/aarch64le/lib/dll${PFS}${PSDK_QNX_PATH}/qnx/pdk_libs/pdk/aarch64/so.le] libti-pdk.so
#[search=../install/aarch64le/lib/dll${PFS}${PSDK_QNX_PATH}/qnx/pdk_libs/sciclient/aarch64/so.le] libti-sciclient.so
#[search=../install/aarch64le/lib/dll${PFS}${PSDK_QNX_PATH}/qnx/pdk_libs/ipclld/aarch64/so.le] libti-ipclld.so
#[search=../install/aarch64le/lib/dll${PFS}${PSDK_QNX_PATH}/qnx/resmgr/ipc_qnx_rsmgr/usr/aarch64/so.le] libtiipc-usr.so
#[search=../install/aarch64le/lib/dll${PFS}${PSDK_QNX_PATH}/qnx/pdk_libs/udmalld/aarch64/so.le] libti-udmalld.so
#[search=../install/aarch64le/lib/dll${PFS}${PSDK_QNX_PATH}/qnx/resmgr/udma_qnx_rsmgr/usr/aarch64/so.le] libtiudma-usr.so

################################################################################################
## END OF BUILD SCRIPT
################################################################################################
')
