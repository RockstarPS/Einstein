/*! \file */
/*
================================================================================

File: qcom_misr.c

$File:  $

================================================================================
Copyright (c) 2019 - 2020 Qualcomm Technologies, Inc.
All Rights Reserved.
Qualcomm Technologies Proprietary and Confidential.
================================================================================
*/

/* -----------------------------------------------------------------------------
 * Includes
 * ---------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <WF/wfd.h>
#include <WF/wfdext2.h>

#define VSM_DEBUG

#include "CMisr_Cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

  /* -----------------------------------------------------------------------------
   * Defines
   * ---------------------------------------------------------------------------*/
#if 0
#define WFD_EXAMPLE_PRINT(_str_, ...) \
  printf("[PID:%d][TID:%d][%d]" _str_ "\n", getpid(), pthread_self(), __LINE__, ##__VA_ARGS__)
#else
#define WFD_EXAMPLE_PRINT(_str_, ...) \
  printf("[%d]" _str_ "\n", __LINE__, ##__VA_ARGS__)
#endif

#define MAX_NUM_DEVICES       1
#define MAX_NUM_PORTS         4
#define MAX_NUM_PORT_MODES    4
#define MAX_NUM_PIPELINES     10
#define MAX_NUM_ROI           4

#define WFD_USAGE             WFD_USAGE_WRITE


  /* -----------------------------------------------------------------------------
   * Structure & Definitions
   * ---------------------------------------------------------------------------*/
  typedef unsigned long long intPtr;

  /* -----------------------------------------------------------------------------
  * Global variables
  * ---------------------------------------------------------------------------*/
  WFDDevice             dev                        = WFD_INVALID_HANDLE;
  WFDPort               port                       = WFD_INVALID_HANDLE;
  WFDPortMode           port_mode                  = WFD_INVALID_HANDLE;
  WFDPipeline           pipeline                   = WFD_INVALID_HANDLE;
  WFDint                num_roi_crc                = 0;
  WFDPortRoiCrcSetType  roi_crc_set[MAX_NUM_ROI]   = { 0 };

  /* -----------------------------------------------------------------------------
   * Private Functions
   * ---------------------------------------------------------------------------*/

  static WFDErrorCode qcom_misr_init_device(void)
  {
    WFDErrorCode  error          = WFD_ERROR_NONE;
    WFDint        num_devs       = 0;
    WFDint        dev_attribs[3] = { 
                                      WFD_DEVICE_CLIENT_TYPE,
                                      0x7812, /* Subject to change based on XML*/
                                      WFD_NONE
                                   };
    WFDint        dev_ids[MAX_NUM_DEVICES];
    WFDint        size           = 0;
#ifdef VSM_DEBUG
    WFDint        count          = 0;
    WFDint        attrib_value   = 0;
#endif

    memset((void *)dev_ids, 0x00, sizeof(WFDint)* MAX_NUM_DEVICES);

    /* Get list of devices */
    /* wfdEnumerateDevices is called with deviceIds = NULL then no device IDs are returned,
    but the total number of available device IDs is returned via the function return value*/
    num_devs = wfdEnumerateDevices(NULL, 0, NULL);

    if (num_devs > 0)
    {
      size = wfdEnumerateDevices(dev_ids, num_devs, NULL);
#ifdef VSM_DEBUG
      for (count = 0; count < size; count++)
      {
        WFD_EXAMPLE_PRINT("dev_ids[%d]=%d", count, dev_ids[count]);
      }
#endif

      if (size > 0)
      {
        dev = wfdCreateDevice(WFD_DEFAULT_DEVICE_ID, dev_attribs);
        if (WFD_INVALID_HANDLE == dev)
        {
          WFD_EXAMPLE_PRINT("dev handle is NULL");
          error = WFD_ERROR_BAD_HANDLE;
        }
#ifdef VSM_DEBUG
        else
        {
          /* Read a device attribute *///arajase2--> Do we need this call?
          attrib_value = wfdGetDeviceAttribi(dev, WFD_DEVICE_ID);
        }
#endif
      }
    }
    return error;
  }

  static WFDErrorCode qcom_misr_init_port(void)
  {
    WFDErrorCode  error     = WFD_ERROR_NONE;
    WFDint        size      = 0;
    WFDint        count     = 0;
    WFDint        num_ports = 0;
    WFDint        port_ids[MAX_NUM_PORTS];

    memset((void *)port_ids, 0x00, sizeof(WFDint)* MAX_NUM_PORTS);

    /* Get list of available ports */
    num_ports = wfdEnumeratePorts(dev, NULL, 0, NULL);
    if (0 == num_ports)
    {
      WFD_EXAMPLE_PRINT("no ports enumerated");
      error = WFD_ERROR_BAD_HANDLE;
    }

    if (WFD_ERROR_NONE == error)
    {
      if (MAX_NUM_PORTS < num_ports)
      {
        size = wfdEnumeratePorts(dev, port_ids, MAX_NUM_PORTS, NULL);
      }
      else
      {
        size = wfdEnumeratePorts(dev, port_ids, num_ports, NULL);
      }
      for (count = 0; count < size; count++)
      {
        WFD_EXAMPLE_PRINT("port_ids[%d]=%d", count, port_ids[count]);
      }
      /* Create default port */
      if (size > 0)
      {
        port = wfdCreatePort(dev, port_ids[0], NULL);
        if (WFD_INVALID_HANDLE == port)
        {
          WFD_EXAMPLE_PRINT("port is NULL");
          error = WFD_ERROR_BAD_HANDLE;
        }
      }
    }
    return error;
  }

  static WFDErrorCode qcom_misr_init_port_mode(void)
  {
    WFDErrorCode  error             = WFD_ERROR_NONE;
    WFDint        size              = 0;
    WFDint        count             = 0;
    WFDint        num_port_modes    = 0;
    WFDPortMode   port_modes[MAX_NUM_PORT_MODES];

    memset((void *)port_modes, 0x00, sizeof(WFDint) * MAX_NUM_PORT_MODES);

    /* Get port modes */
    num_port_modes = wfdGetPortModes(dev, port, NULL, 0);
    if (0 == num_port_modes)
    {
      WFD_EXAMPLE_PRINT("no ports modes enumerated");
      error = WFD_ERROR_BAD_HANDLE;
    }

    if (WFD_ERROR_NONE == error)
    {
      if (MAX_NUM_PORT_MODES < num_port_modes)
      {
        size = wfdGetPortModes(dev, port, port_modes, MAX_NUM_PORT_MODES);
      }
      else
      {
        size = wfdGetPortModes(dev, port, port_modes, num_port_modes);
      }
      for (count = 0; count < size; count++)
      {
        WFD_EXAMPLE_PRINT("port_modes[%d]=%d", count, (WFDint)((intPtr)(port_modes[count])));
      }

      /* Set port mode */
      if (size > 0)
      {
        port_mode = port_modes[0];
        wfdSetPortMode(dev, port, port_mode);
        error = wfdGetError(dev);
        if (WFD_ERROR_NONE != error)
        {
          WFD_EXAMPLE_PRINT("wfdSetPortMode error=0x%08x", error);
        }
      }
    }
    return error;
  }
  
  static int32_t qcom_misr_get_roi_crc_info(void)
  {
    WFDErrorCode  error                 = WFD_ERROR_NONE;
    WFDint        count                 = 0;
    WFDint        i                     = 0;
    int32_t l_status_attach_S32         = EOK;
    WFDRect roi_crc_range[MAX_NUM_ROI]  = { 0 };
    /*
      A call to wfdSetPortAttribiv with this WFD port property for a specified WFD port sets up the ROI
      CRCs associated to the WFD port.
      Expects a count value multiple of 5. The count value divided by 5 shall not be bigger than the
      value returned by the wfdGetPortAttribi query with WFD_PORT_NUM_OF_ROI_CRC. Otherwise,
      the error status of the client is set to WFD_ERROR_INCONSISTENCY.
    */

    wfdGetPortAttribiv(dev, port, (WFDPortConfigAttrib)WFD_PORT_NUM_OF_ROI_CRC, 1, &num_roi_crc);

    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("wfdGetPortAttribiv(WFD_PORT_NUM_OF_ROI_CRC) error=0x%08x", error);
      l_status_attach_S32 = -1;
    }
    else if (MAX_NUM_ROI < num_roi_crc)
    {
      WFD_EXAMPLE_PRINT("num_roi_crc(%d) is greater than the expected maximum(%d)",
        num_roi_crc, MAX_NUM_ROI);
      error = WFD_ERROR_INCONSISTENCY;
      l_status_attach_S32 = -1;
    }

    if (WFD_ERROR_NONE == error)
    {
      count = num_roi_crc * (sizeof(WFDRect) / sizeof(WFDint));
      wfdGetPortAttribiv(dev, port, (WFDPortConfigAttrib)WFD_PORT_ROI_CRC_INFO, count, (WFDint *)&roi_crc_range);

      error = wfdGetError(dev);
      if (WFD_ERROR_NONE != error)
      {
        WFD_EXAMPLE_PRINT("wfdGetPortAttribiv(WFD_PORT_ROI_CRC_INFO) error=0x%08x", error);
        l_status_attach_S32 = -1;
      }
      else
      {

      }
    }

    return  l_status_attach_S32;
  }

  static int32_t qcom_misr_update_attributes()
  {
    int32_t l_status_attach_S32 = EOK;
    WFDErrorCode          error = WFD_ERROR_NONE;
    WFDint                count = 0;

    /* Set port power mode */
    wfdSetPortAttribi(dev, port, WFD_PORT_POWER_MODE, WFD_POWER_MODE_ON);
    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("wfdSetPortAttribi(WFD_PORT_POWER_MODE) error=0x%08x", error);
      l_status_attach_S32 = -1;
    }
    /* Commit port */
    wfdDeviceCommit(dev, WFD_COMMIT_ENTIRE_PORT, port);
    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("wfdDeviceCommit(WFD_COMMIT_ENTIRE_PORT) error=0x%08x", error);
      l_status_attach_S32 = -1;
    }

    /* Query ROI CRC info */
    error = qcom_misr_get_roi_crc_info();
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("qcom_misr_get_roi_crc_info() FAILED error=0x%08x", error);
      l_status_attach_S32 = -1;
    }
    return  l_status_attach_S32;
  }

  /* -----------------------------------------------------------------------------
   * Public Functions
   * ---------------------------------------------------------------------------*/

  int32_t qcom_misr_terminate()
  {
    int32_t l_status_attach_S32 = EOK;
    WFDErrorCode          error = WFD_ERROR_NONE;

    if ((NULL != dev) && (NULL != port))
    {
      wfdSetPortAttribi(dev, port, WFD_PORT_POWER_MODE, WFD_POWER_MODE_OFF);
      wfdDeviceCommit(dev, WFD_COMMIT_ENTIRE_PORT, port);
      wfdDestroyPort(dev, port);
    }

    if (NULL != dev)
    {
      wfdDestroyDevice(dev);
    }

    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("qcom_misr_terminate error=0x%08x", error);
    }
    return l_status_attach_S32;
  }

  int32_t qcom_misr_get_roi_crc(uint32_t  roi_index)
  {
    WFDErrorCode          error                     = WFD_ERROR_NONE;
    WFDint                count                     = 0;
    WFDPortRoiCrcGetType  roi_crc_get[MAX_NUM_ROI]  = { 0 };
    int32_t l_crc_ret                               = 0;

    memset((char *)roi_crc_get, 0x00, sizeof(WFDPortRoiCrcGetType)* MAX_NUM_ROI);
    /*
    Expects a count value multiple of 2. The count value divided by 2 shall not be bigger than the
    value returned by the wfdGetPortAttribi query with WFD_PORT_NUM_OF_ROI_CRC
    */
    count = num_roi_crc * (sizeof(WFDPortRoiCrcGetType) / sizeof(WFDint));

    wfdGetPortAttribiv(dev, port, (WFDPortConfigAttrib)WFD_PORT_ROI_CRC, count, (WFDint *)roi_crc_get);

    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("wfdGetPortAttribiv(WFD_PORT_ROI_CRC) error=0x%08x", error);
    }
    else
    {
      if (WFD_TRUE != roi_crc_get[roi_index].valid)
      {
        WFD_EXAMPLE_PRINT("ROI CRC(%d) is unavailable", roi_index);
      }
      else
      {
        l_crc_ret = roi_crc_get[roi_index].crc;
      }
    }
    return  l_crc_ret;
  }

  int32_t qcom_misr_set_roi_crc(uint32_t roi_index, ts_SSigUnitWinCfg_t *g_roi_crc_set)
  {
    int32_t l_status_attach_S32         = EOK;

    roi_crc_set[roi_index].enable       = WFD_TRUE;
    roi_crc_set[roi_index].rect.offsetX = g_roi_crc_set->upperleft_x_U16;
    roi_crc_set[roi_index].rect.offsetY = g_roi_crc_set->upperleft_y_U16;
    roi_crc_set[roi_index].rect.width   = (g_roi_crc_set->lowerright_x_U16 - g_roi_crc_set->upperleft_x_U16) + 1;
    roi_crc_set[roi_index].rect.height  = (g_roi_crc_set->lowerright_y_U16 - g_roi_crc_set->upperleft_y_U16) + 1;

    return l_status_attach_S32;
  }

  int32_t qcom_misr_stop(uint32_t roi_index)
  {
    int32_t l_status_attach_S32 = EOK;
    roi_crc_set[roi_index].enable = WFD_FALSE;
    return  l_status_attach_S32;
  }

  int32_t qcom_misr_commit(void)
  {
    int32_t l_status_attach_S32 = EOK;
    WFDErrorCode          error = WFD_ERROR_NONE;
    WFDint  count               = num_roi_crc * (sizeof(WFDPortRoiCrcSetType) / sizeof(WFDint));

    /* Set up ROI CRC */
    wfdSetPortAttribiv(dev, port, WFD_PORT_ROI_CRC, count, (WFDint *)roi_crc_set);
    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("wfdSetPortAttribiv(WFD_PORT_ROI_CRC) error=0x%08x", error);
      l_status_attach_S32 = -1;
    }

    /* Commit port */
    wfdDeviceCommit(dev, WFD_COMMIT_ENTIRE_PORT, port);
    error = wfdGetError(dev);
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("wfdDeviceCommit(WFD_COMMIT_ENTIRE_PORT) error=0x%08x", error);
      l_status_attach_S32 = -1;
    }

    return  l_status_attach_S32;
  }

  int32_t qcom_misr_init(void)
  {
    int32_t l_status_attach_S32 = EOK;
    WFDErrorCode          error = WFD_ERROR_NONE;

    error = qcom_misr_init_device();
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("qcom_misr_init_device() FAILED error=0x%08x", error);
      l_status_attach_S32 = -1;
    }

    error = qcom_misr_init_port();
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("qcom_misr_init_port() FAILED error=0x%08x", error);
      l_status_attach_S32 = -1;
    }

    error = qcom_misr_init_port_mode();
    if (WFD_ERROR_NONE != error)
    {
      WFD_EXAMPLE_PRINT("qcom_misr_init_port() FAILED error=0x%08x", error);
      l_status_attach_S32 = -1;
    }
    //Init local variables
    memset((char *)roi_crc_set, 0x00, sizeof(WFDPortRoiCrcSetType)* MAX_NUM_ROI);

    l_status_attach_S32 = qcom_misr_update_attributes();

    return  l_status_attach_S32;
  }


#ifdef __cplusplus
}
#endif
