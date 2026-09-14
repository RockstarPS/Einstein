/*============================================================================
 **
 **                     CONFIDENTIAL VISTEON CORPORATION
 **
 ** This is an unpublished work of authorship, which contains trade secrets,
 ** created in 2012. Visteon Corporation owns all rights to this work and
 ** intends to maintain it in confidence to preserve its trade secret status.
 ** Visteon Corporation reserves the right, under the copyright laws of the
 ** United States or those of any other country that may have jurisdiction,
 ** to protect this work as an unpublished work, in the event of an
 ** inadvertent or deliberate unauthorized publication. Visteon Corporation
 ** also reserves its rights under all copyright laws to protect this work as
 ** a published work, when appropriate. Those having access to this work may
 ** not copy it, use it, modify it or disclose the information contained in
 ** it without the written authorization of Visteon Corporation.
 **
 **============================================================================
 **
 ** Name:          hmi_main.c
 **
 ** Description:   Implements the default init and schedular functionality
 **                for the simulation. Also  implements the default button
 **                handler
 **
 ** Organization:  GUI Software Section
 **
 **============================================================================
 **
 **==========================================================================*/


/*============================================================================
 ** I N C L U D E   F I L E S
 **==========================================================================*/
#include "Rte_WrnCtrl.h"
#include "WrnCtrl_Cfg.h"
#include "hmi_logic_state_handler.h"
#include "hmi_gfx_mgr02_if.h"
#include "hmi_gfx_mgr02_layout.h"
#include "hmi_gfx_anim_engine.h"
#include "hmi_gfx_mgr02_cfg.h"
#include "hmi_rte_interface.h"
#include "ut_compatibility.h"
#include "png_image.h"
#include "png.h"
#include <time.h>
#include "sid_test_input.h"
//#include <stdafx.h>

extern void ScrTripInit(void);
extern void ScrTripRefresh(void);
extern void ScrTripShow(void);
extern void ScrTripHide(void);
extern void ScrWrnReviewInit(void);
extern void ScrWrnReviewRefresh(void);
extern void ScrWrnReviewShow(void);
extern void ScrWrnReviewHide(void);
extern BOOLEAN ScrWrnReviewEventHandler(UINT32 buttonID);
extern void ScrWarningsInit(void);
extern void ScrWarningsRefresh(void);
extern void ScrWarningsShow(void);
extern void ScrWarningsHide(void);
extern BOOLEAN ScrWarningsEventHandler(UINT32 buttonID);
extern UINT32 GdtCtrl_GetCurrentWarning(void);
extern void GdtCtrl_GetListOfActiveWarnings(uint32* pArr, uint32* pArrSize);
extern UINT32 GddCddTick(void);
extern int GetSIDSUpdatedFlag();
extern void SetSIDSUpdatedFlag(int flag);
extern const char * GetFolderName();
extern const char* GetFileName();
extern void UpdateLang(int flag);
char* fileName;

int counter = 0;
int windowUpdatedFlag = 0;
int langCounter = 0;
int langIndex = -1;

BOOLEAN HmiMainIsWarningActive(UINT32 warningID);
void HmiMainShowComputer(UINT32 index);
void HmiMainShowGauges(void);
void HmiMainRefreshFooter(void);
void HmiMainShowException(void);

void lodepng_free(void* ptr);
void* lodepng_malloc(size_t size);
void* lodepng_realloc(void* ptr, size_t new_size);


void SIDSTesting(int index_incr)
{   
    (void)hmi_gfx_mgr02_if_set_sid(GFX_SAMPLETEXT_1, sids_test[index_incr]);
}

int GetSIDSUpdatedFlag()
{
    return windowUpdatedFlag;
}

void UpdateLang()
{
    langIndex++;
    if (langIndex < NUM_LANGUAGES)
    {
        (void)hmi_language_if_set_current_language(langs_test[langIndex]);
    }    
}

void SetSIDSUpdatedFlag(int flag)
{
    windowUpdatedFlag = flag;
}

const char* GetFolderName(int flag)
{
    char* folderName = "default";
    switch (flag)
    {
      case 0:  folderName = "arabic"; break; 
      case 1:  folderName = "hindi"; break;
      case 2:  folderName = "thai"; break;
      default:  break;
    }
    return folderName;
}

const char* GetFileName()
{
    return fileName;
}

/*============================================================================
 ** I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
 **==========================================================================*/
typedef enum {
    eScrTrip,
    eScrWrnReview,
    eScrWrn,
    eScrMax
} tScrDef;

typedef enum {
    eExceptionWarning,
    eExceptionDiag,
    eExceptionEtm,
    eExceptionMax
} tExceptionDesc;

typedef void (*tScrDescInitCallback)(void);
typedef void (*tScrDescRefreshCallback)(void);
typedef void (*tScrDescShowCallback)(void);
typedef void (*tScrDescHideCallback)(void);
typedef BOOLEAN (*tScrDescEventCallback)(UINT32);

typedef struct {
    tScrDescInitCallback pInitCallback;
    tScrDescRefreshCallback pRefreshCallback;
    tScrDescShowCallback pShowCallback;
    tScrDescHideCallback pHideCallback;
    tScrDescEventCallback pEventCallback;
} tScrDesc;

typedef struct {
    SINT32 startPos;
    SINT32 endPos;
    SINT32 duration;
    BOOLEAN isHor;
} tAnimDesc;

typedef struct {
    const tAnimDesc* pAnim;
    const tScrDef nextScr;
} tScrAnimTrans;

typedef struct {
    const tScrAnimTrans* pLeft;
    const tScrAnimTrans* pRight;
    const tScrAnimTrans* pUp;
    const tScrAnimTrans* pDown;
} tScrTrans;

typedef struct {
    tAnimDesc* pCurAnim;
    UINT32 startTick;
    UINT32 cycles;
    tScrDef newScreen;
} tTransAnim;

typedef struct {
    unsigned char* pImage;
    unsigned int width;
    unsigned int height;    
} tPngDecode;

/*============================================================================
 ** I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
 **==========================================================================*/

/*============================================================================
 ** M E M O R Y   A L L O C A T I O N
 **==========================================================================*/
#define ANIM_DURATION_IN_TICKS      50
#define INVALID_WARNING_ID          ((UINT32)eWrnId_Count)

static UINT32 odoDispValue;
static tScrDef curScreen;
static tTransAnim transAnim;
static tExceptionDesc curExeption;
static tScrDef prevScreen[eScrMax];
static tPngDecode pngImage;

static const tScrDesc scrDesc[eScrMax] = {
        {ScrTripInit, ScrTripRefresh, ScrTripShow, ScrTripHide ,0},
        {ScrWrnReviewInit, ScrWrnReviewRefresh, ScrWrnReviewShow, ScrWrnReviewHide, ScrWrnReviewEventHandler},
        {ScrWarningsInit, ScrWarningsRefresh, ScrWarningsShow, ScrWarningsHide, ScrWarningsEventHandler},
};

static const tAnimDesc leftAnim = {0, 800, ANIM_DURATION_IN_TICKS, TRUE};
static const tAnimDesc rightAnim = {0, -800, ANIM_DURATION_IN_TICKS, TRUE};
static const tAnimDesc upAnim = {0, 480, ANIM_DURATION_IN_TICKS, FALSE};
static const tAnimDesc downAnim = {0, -480, ANIM_DURATION_IN_TICKS, FALSE};
static const tAnimDesc noAnim = {0, 0, 0, TRUE};

static const tScrAnimTrans scrTripUp = {&upAnim, eScrMax};
static const tScrAnimTrans scrFuelLeft = {&leftAnim, eScrTrip};
static const tScrAnimTrans scrCompassUp = {&upAnim, eScrTrip};
static const tScrAnimTrans scrCompassDown = {&downAnim, eScrMax};
static const tScrAnimTrans scrWrnReviewDown = {&downAnim, eScrTrip};
static const tScrAnimTrans scrGaugesRight = {&noAnim, eScrMax};

static const tScrTrans scrTrans[eScrMax] = {
        {0,                 &scrGaugesRight,0,              0},
};

/*============================================================================
 ** E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
 **==========================================================================*/
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/

/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
static void TransitionAnimTick(void)
{
    if (transAnim.pCurAnim != 0)
    {
        SINT32 pos;
        SINT32 startPos, endPos;
        SINT32 elapsedTicks = ((SINT32)GddCddTick() - (SINT32)transAnim.startTick);

        if (elapsedTicks > transAnim.pCurAnim->duration)
        {
            elapsedTicks = transAnim.pCurAnim->duration;
        }

        if (transAnim.cycles == (UINT32)0)
        {
            startPos = transAnim.pCurAnim->startPos;
            endPos = transAnim.pCurAnim->endPos;
        }
        else
        {
            startPos = -transAnim.pCurAnim->endPos;
            endPos = transAnim.pCurAnim->startPos;
        }

        pos = startPos + (endPos - startPos) * elapsedTicks / (transAnim.pCurAnim->duration+1);

        if (transAnim.pCurAnim->isHor == TRUE)
        {
        }
        else
        {
        }

        if (elapsedTicks == transAnim.pCurAnim->duration)
        {
            transAnim.cycles++;

            if (transAnim.cycles == (UINT32)1)
            {
                if (scrDesc[curScreen].pHideCallback != 0)
                {
                    scrDesc[curScreen].pHideCallback();
                }

                curScreen = transAnim.newScreen;

                if (scrDesc[curScreen].pShowCallback != 0)
                {
                    scrDesc[curScreen].pShowCallback();
                }

                transAnim.startTick = GddCddTick();
            }
            else
            {
                transAnim.pCurAnim = 0;
            }
        }
    }
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
static void FindNewScreen(void)
{
    if (transAnim.newScreen == (UINT32)eScrMax)
    {
        if (((curScreen == (UINT32)eScrTrip) && (transAnim.pCurAnim == (tAnimDesc*)&upAnim)))
        {
            UINT32 warningList[10];
            UINT32 arrSize = (UINT32)10;

            GdtCtrl_GetListOfStorredWarnings(warningList, &arrSize);

            if (arrSize > (UINT32)0)
            {
                transAnim.newScreen = eScrWrnReview;
            }
            else
            {
                
            }
        }

    }

    if (transAnim.newScreen != (UINT32)eScrMax)
    {
        prevScreen[transAnim.newScreen] = curScreen;
    }
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
static void ExceptionManagement(void)
{
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void ScrMainInit()
{
    SINT32 index;

    curScreen = eScrTrip;
    curExeption = eExceptionMax;

    transAnim.pCurAnim = 0;
    odoDispValue = 0xFFFFFFFF;
    
    pngImage.pImage = 0;

    for (index = 0; index < (SINT32)eScrMax; index++)
    {
        if (scrDesc[index].pInitCallback != 0)
        {
            scrDesc[index].pInitCallback();
        }
    }
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void ScrMainDeinit()
{
    if (pngImage.pImage)
    {
        lodepng_free(pngImage.pImage);
        pngImage.pImage = 0;
    }
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
UINT8 scr_main_evt_hndlr(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
    if (LSH_GET_STATUS(p_event_hndl_status_SP->button_command) == BTN_EV_PRESS)
    {
        if (curExeption == (UINT32)eExceptionMax)
        {
            BOOLEAN consumedEvent = (UINT8)FALSE;
            BOOLEAN selectedTrans = (UINT8)FALSE;

            if (transAnim.pCurAnim == 0)
            {
                if (p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(DOWN_BTN_EV, BTN_EV_PRESS))
                {
                    if (scrTrans[curScreen].pDown != 0)
                    {
                        transAnim.pCurAnim = (tAnimDesc*)scrTrans[curScreen].pDown->pAnim;
                        transAnim.newScreen = scrTrans[curScreen].pDown->nextScr;
                        selectedTrans = (UINT8)TRUE;
                    }
                }
                else if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(UP_BTN_EV, BTN_EV_PRESS))
                {
                    if (scrTrans[curScreen].pUp != 0)
                    {
                        transAnim.pCurAnim = (tAnimDesc*)scrTrans[curScreen].pUp->pAnim;
                        transAnim.newScreen = scrTrans[curScreen].pUp->nextScr;
                        selectedTrans = (UINT8)TRUE;
                    }
                }
                else if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(RIGHT_BTN_EV, BTN_EV_PRESS))
                {
                    if (scrDesc[curScreen].pEventCallback != 0)
                    {
                        consumedEvent = scrDesc[curScreen].pEventCallback((UINT32)RIGHT_BTN_EV);
                    }

                    if ((consumedEvent == FALSE) && (scrTrans[curScreen].pRight != 0))
                    {
                       // transAnim.pCurAnim = (tAnimDesc*)scrTrans[curScreen].pRight->pAnim;
                      //  transAnim.newScreen = scrTrans[curScreen].pRight->nextScr;
                      //  selectedTrans = (UINT8)TRUE;
                    }
                }
                else if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(LEFT_BTN_EV, BTN_EV_PRESS))
                {
                    if (scrDesc[curScreen].pEventCallback != 0)
                    {
                        consumedEvent = scrDesc[curScreen].pEventCallback((UINT32)LEFT_BTN_EV);
                    }

                    if ((consumedEvent == FALSE) && (scrTrans[curScreen].pLeft != 0))
                    {
                        transAnim.pCurAnim = (tAnimDesc*)scrTrans[curScreen].pLeft->pAnim;
                        transAnim.newScreen = scrTrans[curScreen].pLeft->nextScr;
                        selectedTrans = (UINT8)TRUE;
                    }
                }
                else if(p_event_hndl_status_SP->button_command == LSH_GET_COMMAND(BTN_ID_ENTER, BTN_EV_PRESS))
                {
                    if (scrDesc[curScreen].pEventCallback != 0)
                    {
                        consumedEvent = scrDesc[curScreen].pEventCallback((UINT32)BTN_ID_ENTER);
                    }
                }
                else
                {

                }

                if (selectedTrans == TRUE)
                {
                    FindNewScreen();

                    if ((transAnim.newScreen != (UINT32)eScrMax) && (transAnim.pCurAnim != 0))
                    {
						transAnim.startTick = GddCddTick();
						transAnim.cycles = (UINT32)0;
                    }
                }
            }
        }
    }

	return ((UINT8)LSH_STATUS_ABSORBED);
}



/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void scr_main_present_hndlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
    int width;
    GFX_MGR02_TEXT_WIDTH_INFO p_text_info;
    HMI_CHAR* fl_string_ptr;
    HMI_CHAR fl_text_A[GFX_MGR02_MAX_TEXT_LENGTH + 1];
    FILE* fptr;

    fptr = fopen("TestingSIDSLog.txt", "ab+");
    if (fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }
    switch (p_presen_hndl_status_SP->presentation_status)
    {
    case LSH_ACTIVATED_STATUS:  
        (void)hmi_language_if_set_current_language(langs_test[langIndex]);
    case LSH_REFRESH_STATUS:

    	if (p_presen_hndl_status_SP->presentation_status == LSH_ACTIVATED_STATUS)
    	{
            (void)hmi_gfx_mgr02_if_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, (UINT32)1);

            if (scrDesc[curScreen].pShowCallback != 0)
            {
                scrDesc[curScreen].pShowCallback();
            }
    	}

        ExceptionManagement();
        TransitionAnimTick();
        if (langIndex < NUM_LANGUAGES && langIndex != -1)
        {
            if (counter < NUM_SIDS)
            {
                SIDSTesting(counter);
                p_text_info.num_chars_to_process = 100;
                p_text_info.ifont_id = 0; 
                fl_text_A[0] = 0;
                hmi_language_if_get_string_ptr(sids_test[counter], &fl_text_A[0], GFX_MGR02_MAX_TEXT_LENGTH);
                fl_string_ptr = &fl_text_A[0];
                p_text_info.iostring = fl_string_ptr;
                (void)hmi_gfx_mgr02_if_get_text_width(GFX_SAMPLETEXT_1, &p_text_info);
                fprintf(fptr, "%s", "\n Printing width of ");
                fprintf(fptr, "%d", counter);
                fprintf(fptr, "%s", "    :  ");
                fprintf(fptr, "%d", p_text_info.owidth);
                fileName = sids_test[counter];
                counter++;
            }
            if (counter == NUM_SIDS - 1)
            {
                fprintf(fptr, "%s", "\n=========================================================\n");
                windowUpdatedFlag = 1;
                counter = 0;
            }

        } 

    //    hmi_gfx_mgr02_if_set_text(GFX_SAMPLETEXT_1,L"วันศุกร์");

        if (scrDesc[curScreen].pRefreshCallback != 0)
        {
            scrDesc[curScreen].pRefreshCallback();

            switch (curScreen)
            {
            case eScrWrn:

            	if (prevScreen[eScrWrn] != (UINT32)eScrWrnReview)
				{
					if (scrDesc[prevScreen[eScrWrn]].pRefreshCallback != 0)
					{
						scrDesc[prevScreen[eScrWrn]].pRefreshCallback();
					}
				}
            	break;

            case eScrTrip:
            case eScrWrnReview:

            	HmiMainRefreshFooter();
            	break;

            default:
            	break;
            }
        }
        break;

    case LSH_DEACTIVATED_STATUS:

        (void)hmi_gfx_mgr02_if_set_screen((GFX_MGR02_SCR_ELEM_ID)p_presen_hndl_status_SP->logic_state_id, (UINT32)0);
        break;

    default:
    	break;
    }

    fclose(fptr);
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void hmi_welcome_animation_cb(UINT32 p_cur_frame, UINT32 p_total_frames)
{
    if (p_cur_frame == (UINT32)1)
    {
    }
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
BOOLEAN HmiMainIsWarningActive(UINT32 warningID)
{
    UINT32 warningList[10];
    UINT32 arrSize = (UINT32)10;
    BOOLEAN result = (UINT8)0;
    UINT32 index;

    GdtCtrl_GetListOfActiveWarnings(warningList, &arrSize);

    for (index = (UINT32)0; index < arrSize; index++)
    {
        if (warningID == warningList[index])
        {
            result = (UINT8)TRUE;
            break;
        }
    }

    return result;
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void HmiMainShowGauges(void)
{
 
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void HmiMainShowComputer(UINT32 index)
{

}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void HmiMainShowException(void)
{

}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
void HmiMainRefreshFooter(void)
{
    if (odoDispValue != l_odo_dist_val)
    {
        HMI_CHAR odoValue[9];

        UINT32 fl_odo_int_val = (UINT32)0;
        UINT32 fl_odo_dec_val = (UINT32)0;

        /* Convert distance remaining to get float value with 1 decimal point */
        fl_odo_int_val = l_odo_dist_val / (UINT32)10;
        fl_odo_dec_val = l_odo_dist_val % (UINT32)10;

        (void)HMI_SPRINTF(odoValue, (UINT32)8, HMI_TEXT((unsigned char*)"%u.%u"), fl_odo_int_val, fl_odo_dec_val);


        odoDispValue = l_odo_dist_val;
    }

}



/*============================================================================
 ** Function Name:    hmi_get_sliding_anim_direction
 ** Visibility:       global
 ** Description:      Screen Animations
 ** Invocation:       View Manager
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Oct-2014 by ASHEKHAR
 ** Created:          20-Oct-2014 by ASHEKHAR
 **==========================================================================*/
UINT32 hmi_get_sliding_anim_direction(UINT32 p_cur_step)
{
	return((UINT32)0);
}

/*============================================================================
 ** Function Name:    hmi_screen_sliding_complete
 ** Visibility:       global
 ** Description:      Screen Animations
 ** Invocation:       View Manager
 ** Inputs/Outputs:   None
 ** Critical Section: None.
 ** Created:          20-Oct-2014 by ASHEKHAR
 ** Created:          20-Oct-2014 by ASHEKHAR
 **==========================================================================*/
UINT32 hmi_screen_sliding_complete(UINT32 p_cur_step)
{
    return((UINT32)0);
}

void hmi_change_menu_title(UINT32 p_cur_frame, UINT32 p_total_frames)
{
}

UINT8 hmi_amthyst_header_footer_ev_hdnlr(LSH_EVENT_HANDLER_STATUS_T *p_event_hndl_status_SP)
{
	return((UINT8)0);
}

void hmi_amthyst_header_footer_focus_hdnlr(LSH_FOCUS_HANDLER_STATUS_T  *p_focus_hndl_status_SP)
{
}

void hmi_amthyst_header_footer_present_hdnlr(LSH_PRESN_HANDLER_STATUS_T *p_presen_hndl_status_SP)
{
}
/****************************************************************************
Function Name        :
Description          :
Invocation           :
Return Value         :
Critical Section     :
Parameters           :
******************************************************************************/
UINT32 hmi_gfx_mgr02_load_user_layer_def_info(UINT32 p_base_id, GFX_MGR02_IMAGE_DEF_T * p_image_def)
{

    
    return 0;
}
void lodepng_free(void* ptr)
{
    mmlGdcVideoFree(ptr);
}

void* lodepng_malloc(size_t size)
{
    return mmlGdcVideoAlloc(size, 4, 0);
}

void* lodepng_realloc(void* ptr, size_t new_size)
{
    void* pNew = lodepng_malloc(new_size);
    
    if ((pNew)&&(ptr))
    {
        memcpy(pNew, ptr, new_size);
        mmlGdcVideoFree(ptr);
    }
    
    return pNew;
}

