/*
 *  Copyright (C) 2023 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 *  \file 
 *
 *  \brief 
 */

#ifndef HMI_DSS_INTERFACE_H
#define HMI_DSS_INTERFACE_H
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include "ti_drivers_config.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* Max frame size based on resolution */
#define DISP_FRAME_SIZE_MAX                (1920U*720U)
#define DISP_FRAME_PIXEL_WIDTH_MAX         (4U) //ARGB8888
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

extern int32_t hmi_DssDisplayAppInit(void);
extern int32_t hmi_DssDisplayAppShutdown(void);
extern int32_t hmi_DssDisplayAppActivate(void);
extern int32_t hmi_DssDisplayAppSubmitFB(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/*
 * Global frame buffers. Maximum frame buffers per pipline is considered 2 
 */
 
extern uint8_t hmi_gFirstPipelineFrameBuf[CONFIG_DSS_NUM_FRAMES_PER_PIPELINE][DISP_FRAME_SIZE_MAX * DISP_FRAME_PIXEL_WIDTH_MAX]__attribute__ ((section (".dssFrameBuffer"), aligned (4096)));

#endif