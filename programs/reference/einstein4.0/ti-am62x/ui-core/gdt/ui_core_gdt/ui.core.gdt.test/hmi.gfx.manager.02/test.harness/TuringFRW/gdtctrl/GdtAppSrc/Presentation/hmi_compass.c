#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"

extern void HmiMainShowComputer(UINT32 index);

// static configuration data
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define SCR_COMPASS_ANIM_STEPS      8
#define SCR_COMPASS_WAIT_CNTR       100

static const HMI_CHAR strN[] =  {'N', ' ', 0};
static const HMI_CHAR strNW[] = {'N', 'W', 0};
static const HMI_CHAR strW[] =  {'W', ' ', 0};
static const HMI_CHAR strSW[] = {'S', 'W', 0};
static const HMI_CHAR strS[] =  {'S', ' ', 0};
static const HMI_CHAR strSE[] = {'S', 'E', 0};
static const HMI_CHAR strE[] =  {'E', ' ', 0};
static const HMI_CHAR strNE[] = {'N', 'E', 0};

static const HMI_CHAR* strCompassDirText[] = {
        strN, strNW, strW, strSW, strS, strSE, strE, strNE, strN
};

static SINT32 textIndex;
static SINT32 waitCntr;
static BOOLEAN animDirCW;

// interface functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ScrCompassInit(void)
{
    textIndex = 0;
    animDirCW = TRUE;
    waitCntr = SCR_COMPASS_WAIT_CNTR;

}

void ScrCompassRefresh(void)
{

}

void ScrCompassShow(void)
{

    HmiMainShowComputer((UINT32)2);

    waitCntr = SCR_COMPASS_WAIT_CNTR;
}

void ScrCompassHide(void)
{

}

void compass_cw_rotation_anim_callback(UINT32 p_anim_id, UINT32 p_client_id)
{
    if (p_anim_id == p_client_id)
    {
        textIndex++;

        if (textIndex >= SCR_COMPASS_ANIM_STEPS)
        {
            animDirCW = FALSE;
        }

        waitCntr = SCR_COMPASS_WAIT_CNTR;
    }
}

void compass_ccw_rotation_anim_callback(UINT32 p_anim_id, UINT32 p_client_id)
{
    if (p_anim_id == p_client_id)
    {
        textIndex--;

        if (textIndex <= 0)
        {
            animDirCW = TRUE;
        }

        waitCntr = SCR_COMPASS_WAIT_CNTR;
    }
}
