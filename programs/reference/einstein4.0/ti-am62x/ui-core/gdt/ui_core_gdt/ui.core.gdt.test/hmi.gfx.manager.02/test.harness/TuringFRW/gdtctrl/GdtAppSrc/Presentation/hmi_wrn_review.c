#include "Rte_WrnCtrl.h"
#include "WrnCtrl_Cfg.h"
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_button.h"

extern void GdtCtrl_GetListOfStorredWarnings(UINT32* pArr, UINT32* pArrSize);
extern void GdtCtrl_GetListOfActiveWarnings(uint32* pArr, uint32* pArrSize);
extern void GdtCtrl_AcknowledgeWarning(UINT32 warningID);
extern UINT32 GdtCtrl_GetCurrentWarning(void);
extern BOOLEAN HmiMainIsWarningActive(UINT32 warningID);
extern void HmiMainShowComputer(UINT32 index);
extern void ScrWarningsDisplayWarning(UINT32 warningID);

// static definitions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define INVALID_WARNING_ID      ((UINT32)eWrnId_Count)

// static configuration data
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT32 currentStoredWarning;

// static functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static UINT32 GetNextStoredWarning(UINT32 prevWarningID, BOOLEAN next)
{
    SINT32 index;
    UINT32 result;
    UINT32 warningList[10];
    UINT32 arrSize = (UINT32)10;

    GdtCtrl_GetListOfStorredWarnings(warningList, &arrSize);

    if (arrSize > (UINT32)0)
    {
        if (prevWarningID == INVALID_WARNING_ID)
        {
            result = warningList[0];
        }
        else
        {
            UINT32 prevWrnID = prevWarningID;

            for (index = 0; (UINT32)index < arrSize; index++)
            {
                if (prevWrnID == warningList[index])
                {
                    break;
                }
            }

            if ((UINT32)index >= arrSize)
            {
                result = warningList[0];
            }
            else
            {
                if (next == TRUE)
                {
                    if ((UINT32)index == (arrSize - (UINT32)1))
                    {
                        result = warningList[0];
                    }
                    else
                    {
                        result = warningList[(UINT32)index + (UINT32)1];
                    }
                }
                else
                {
                    if (index == 0)
                    {
                        result = warningList[arrSize - (UINT32)1];
                    }
                    else
                    {
                        result = warningList[index - 1];
                    }
                }
            }
        }
    }
    else
    {
        result = INVALID_WARNING_ID;
    }

    return result;
}

static void DisplayWarning(UINT32 warningID)
{
    ScrWarningsDisplayWarning(warningID);

}

// interface functions
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ScrWrnReviewInit(void)
{
    currentStoredWarning = INVALID_WARNING_ID;
}

void ScrWrnReviewRefresh(void)
{
    if ((currentStoredWarning == INVALID_WARNING_ID) || (HmiMainIsWarningActive(currentStoredWarning) == FALSE))
    {
        UINT32 warningID = GetNextStoredWarning(currentStoredWarning, (UINT8)0);

        if (warningID != currentStoredWarning)
        {
            currentStoredWarning = warningID;

            DisplayWarning(currentStoredWarning);
        }
    }
}

void ScrWrnReviewShow(void)
{

    HmiMainShowComputer((UINT32)3);

    currentStoredWarning = INVALID_WARNING_ID;

    DisplayWarning(currentStoredWarning);
}

void ScrWrnReviewHide(void)
{
    DisplayWarning(INVALID_WARNING_ID);
}

BOOLEAN ScrWrnReviewEventHandler(UINT32 buttonID)
{
    BOOLEAN result = (UINT8)FALSE;

    switch (buttonID)
    {
    case (UINT32)RIGHT_BTN_EV:

        currentStoredWarning = GetNextStoredWarning(currentStoredWarning, (UINT8)TRUE);

        DisplayWarning(currentStoredWarning);
        result = (UINT8)TRUE;
        break;

    case (UINT32)LEFT_BTN_EV:

        currentStoredWarning = GetNextStoredWarning(currentStoredWarning, (UINT8)FALSE);

        DisplayWarning(currentStoredWarning);
        result = (UINT8)TRUE;
        break;

    default:
    	break;
    }

    return result;
}


