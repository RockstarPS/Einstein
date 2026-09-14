/*
 *  Copyright (C) 2021 Texas Instruments Incorporated
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
/*
 * Auto generated file
 */

#include "ti_drivers_config.h"
#include <drivers/device_manager/sciclient.h>

/* DSS attributes */

/* DSS VP Params */
Dss_DctrlVpParams gDssVpParams =
{
    .vpId = CSL_DSS_VP_ID_1,
    .lcdOpTimingCfg = {
        .mInfo.standard = FVID2_STD_CUSTOM,
        .mInfo.width = 1600U,
        .mInfo.height = 500U,
        .mInfo.hFrontPorch = 52U,
        .mInfo.hBackPorch = 32U,
        .mInfo.hSyncLen = 24U,
        .mInfo.vFrontPorch = 8U,
        .mInfo.vBackPorch = 24U,
        .mInfo.vSyncLen = 3U,
        .dvoFormat = FVID2_DV_GENERIC_DISCSYNC,
        .videoIfWidth = FVID2_VIFW_24BIT,
    },
    .lcdPolarityCfg = {
        .actVidPolarity = FVID2_POL_HIGH,
        .hsPolarity = FVID2_POL_HIGH,
        .vsPolarity = FVID2_POL_HIGH,
        .pixelClkPolarity = FVID2_EDGE_POL_RISING,
    },

};

/* DSS VP Advance Params */
Dss_DctrlAdvVpParams gDssAdvVpParams =
{
    .vpId = CSL_DSS_VP_ID_1,
    .lcdAdvSignalCfg = {
        .hVAlign = CSL_DSS_VP_HVSYNC_ALIGNED,
        .hVClkControl = CSL_DSS_VP_HVCLK_CONTROL_ON,
    },
};

/* DSS Overlay Params */
Dss_DctrlOverlayParams gDssOverlayParams =
{
    .overlayId = CSL_DSS_OVERLAY_ID_1,
    .colorbarEnable = FALSE,
    .overlayCfg = {
        .colorKeyEnable = FALSE,
        .colorKeySel = CSL_DSS_OVERLAY_TRANS_COLOR_DEST,
        .backGroundColor = 0xC8C800U,
    }
};

/* DSS Overlay Layer Params */
Dss_DctrlOverlayLayerParams gDssOverlayLayerParams =
{
    .overlayId = CSL_DSS_OVERLAY_ID_1,
    .pipeLayerNum = {
        CSL_DSS_VID_PIPE_ID_VIDL1,
        CSL_DSS_OVERLAY_LAYER_INVALID
    }
};

/* DSS OLDI Panel Params */
Dss_DctrlOldiParams gDssOldiParams =
{
    .vpId = CSL_DSS_VP_ID_1,
    .oldiCfg = {
        .oldiMapType = CSL_DSS_VP_OLDI_MAP_TYPE_F,
        .dataEnablePolarity = FVID2_POL_LOW,
        .dssBitDepth = CSL_DSS_VP_OLDI_BIT_DEPTH_24_BITS,
        .dualModeSync = CSL_DSS_VP_OLDI_DUALMODESYNC_ENABLE,
    }
};

static Dss_DctrlPathInfo gDssPathInfo =
{
    .numEdges = 3,
    .edgeInfo = {
        {
            .startNode = DSS_DCTRL_NODE_VIDL1,
            .endNode = DSS_DCTRL_NODE_OVR1,
        },
        {
            .startNode = DSS_DCTRL_NODE_OVR1,
            .endNode = DSS_DCTRL_NODE_VP1,
        },
        {
            .startNode = DSS_DCTRL_NODE_VP1,
            .endNode = DSS_DCTRL_NODE_OLDI,
        },
    }

};

/* DSS Pipeline Configuration Params */
Dss_ConfigPipelineParams gDssConfigPipelineParams =
{
        /**< Number of pipes in test params */
        .numTestPipes = 1U,
        /**< Driver instance id */
        .instId = {
          CSL_DSS_VID_PIPE_ID_VIDL1
        },
        /**< Pipe id */
        .pipeId = {
            CSL_DSS_VID_PIPE_ID_VIDL1
        },
        /**< Pipe Node id */
        .pipeNodeId = {
            DSS_DCTRL_NODE_VIDL1
        },
        /**< Video pipe type */
        .pipeType = {
            CSL_DSS_VID_PIPE_TYPE_VIDL
        },
        /**< Data format */
        .inDataFmt= {
            FVID2_DF_RGBA32_8888,
        },
        /**< Input buffer resolution width in pixels */
        .inWidth = {
            1600U,
        },
        /**< Input buffer resolution height in lines */
        .inHeight = {
            500U,
        },
        /**< Pitch of input buffer */
        .pitch = {
            {
                1600*4U, 0U, 0U, 0U, 0U, 0U,
            }
        },
        /**< Scan format */
        .inScanFmt = {
            FVID2_SF_PROGRESSIVE,
        },
        /**< Output buffer resolution width in pixels */
        .outWidth = {
            1600U,
        },
        /**< Output buffer resolution height in lines */
        .outHeight= {
            500U,
        },
        /**< Scaler enable */
        .scEnable = {
            FALSE
        },
        /**< Global Alpha value */
        .globalAlpha = {
            0xFF
        },
        /**< Pre-multiply Alpha value */
        .preMultiplyAlpha = {
            FALSE
        },
        /**< Input buffer position x. */
        .posx = {
            0U
        },
        /**< Input buffer position y. */
        .posy = {
            0U
        },
        /**< Invalid Pipe id */
        .invalidPipeId = {
            CSL_DSS_VID_PIPE_ID_VID1,
        }
};

static Fvid2_Frame gFramesVIDL1[CONFIG_DSS_NUM_FRAMES_PER_PIPELINE];

Dss_Object gDssObjects[CONFIG_DSS_NUM_INSTANCES] =
{
    {
        .instObj =
        {
            {
                .numFrames = CONFIG_DSS_NUM_FRAMES_PER_PIPELINE,
                .frames = gFramesVIDL1,
            },
        },
        .dctrlPathInfo = &gDssPathInfo,
        .oldiParams = &gDssOldiParams,
    },
};

uint32_t gDssConfigNum = CONFIG_DSS_NUM_INSTANCES;

#include <drivers/sciclient.h>


void Pinmux_init();
void PowerClock_init(void);
void PowerClock_deinit(void);

/*
 * Common Functions
 */
void System_init(void)
{
    /* DPL init sets up address transalation unit, on some CPUs this is needed
     * to access SCICLIENT services, hence this needs to happen first
     */
    /* Dpl_init(); */    /* Commenting out due to dependency driver addition from mcu plus sdk as per TI ticket discussion*/
    /* We should do sciclient init before we enable power and clock to the peripherals */
    /* SCICLIENT init */
    /* This part is commented because sciclient init and clock init is take care in mcu call back implementation */
    /*{

        int32_t retVal = SystemP_SUCCESS;

        retVal = Sciclient_init(CSL_CORE_ID_MCU_R5FSS0_0);
        DebugP_assertNoLog(SystemP_SUCCESS == retVal);

    }
    PowerClock_init();*/
    /* Now we can do pinmux */
    Pinmux_init();
    /* finally we initialize all peripheral drivers */
}

void System_deinit(void)
{
  //  I2C_deinit();
    PowerClock_deinit();
    /* SCICLIENT deinit */
    {
        int32_t         retVal = SystemP_SUCCESS;

        retVal = Sciclient_deinit();
        DebugP_assertNoLog(SystemP_SUCCESS == retVal);
    }
   // Dpl_deinit();
}
