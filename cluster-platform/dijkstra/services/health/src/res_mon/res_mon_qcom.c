/*---------------------------------------------------------------------------------------------------------------------

 VISTEON CORPORATION CONFIDENTIAL
 ________________________________

 [2020] Visteon Corporation
 All Rights Reserved.

 NOTICE: This is an unpublished work of authorship, which contains trade secrets.
 Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
 its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
 or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
 in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
 under all copyright laws to protect this work as a published work, when appropriate.
 Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
 without the written authorization of Visteon Corporation.

---------------------------------------------------------------------------------------------------------------------*/

#include <errno.h>
#include <stdint.h>
#include <fcntl.h>
#include "debug.h"
#include "res_mon_qcom.h"

void ResMonQcom_EnableGPUBusyStats( void )
{
  int32_t fd = -1;
  
  fd = open ("/dev/kgsl-control", O_RDWR);
  
  if( -1 != fd )
  {
    /* Reference QC Case 05115105 */
    write(fd, "gpu_set_log_level 4\n", strlen("gpu_set_log_level 4\n"));
    write(fd, "gpubusystats 1000\n", strlen("gpubusystats 1000\n"));
    
    close(fd);
  }
  else
  {
    LOGE ( "open failed /dev/kgsl-control %d", errno );
  }
}
