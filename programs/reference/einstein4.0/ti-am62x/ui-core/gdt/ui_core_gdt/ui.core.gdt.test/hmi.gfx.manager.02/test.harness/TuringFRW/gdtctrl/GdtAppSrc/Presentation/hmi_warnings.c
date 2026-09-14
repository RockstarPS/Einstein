#include "Rte_WrnCtrl.h"
#include "WrnCtrl_Cfg.h"
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_button.h"

extern UINT32 GdtCtrl_GetCurrentWarning(void);
extern void GdtCtrl_AcknowledgeWarning(UINT32 warningID);
void ScrWarningsDisplayWarning(UINT32 warningID);

// static definitions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INVALID_WARNING_ID      ((UINT32)eWrnId_Count)

// static configuration data
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT32 currentActiveWarning;

// static functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// interface functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ScrWarningsInit(void)
{
    currentActiveWarning = INVALID_WARNING_ID;
}

void ScrWarningsRefresh(void)
{
    UINT32 warningID = GdtCtrl_GetCurrentWarning();

    if (warningID != currentActiveWarning)
    {
        currentActiveWarning = warningID;

        ScrWarningsDisplayWarning(currentActiveWarning);
    }
}

void ScrWarningsShow(void)
{

    currentActiveWarning = INVALID_WARNING_ID;

    ScrWarningsDisplayWarning(currentActiveWarning);
}

void ScrWarningsHide(void)
{

    ScrWarningsDisplayWarning(INVALID_WARNING_ID);
}

BOOLEAN ScrWarningsEventHandler(UINT32 buttonID)
{
    BOOLEAN result = (UINT8)FALSE;

    switch (buttonID)
    {
    case (UINT32)BTN_ID_ENTER:

        if (currentActiveWarning != INVALID_WARNING_ID)
        {
            GdtCtrl_AcknowledgeWarning(currentActiveWarning);
        }
        result = (UINT8)TRUE;
        break;

    default:;
    }

    return result;
}

void ScrWarningsDisplayWarning(UINT32 warningID)
{

}



