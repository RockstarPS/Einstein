//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2015] Visteon Corporation
// All Rights Reserved.
//
// NOTICE: This is an unpublished work of authorship, which contains trade secrets.
// Visteon Corporation owns all rights to this work and intends to maintain it in confidence to preserve
// its trade secret status. Visteon Corporation reserves the right, under the copyright laws of the United States
// or those of any other country that may have jurisdiction, to protect this work as an unpublished work,
// in the event of an inadvertent or deliberate unauthorized publication. Visteon Corporation also reserves its rights
// under all copyright laws to protect this work as a published work, when appropriate.
// Those having access to this work may not copy it, use it, modify it, or disclose the information contained in it
// without the written authorization of Visteon Corporation.
//
//---------------------------------------------------------------------------------------------------------------------
#include "Std_Types.h"
#include "Rte_CCtrl_Telltale.h"
#include "Ctrl_TT_Cfg.h"


#define cTT_PHASE_OFF (0u)
#define cTT_PHASE_ON (1u)

#define cTT_CHANGE_PHASE (uint8)1u
#define cTT_PHASE_PATTERN_SIZE (2u)

/*Maximum Supported States*/

#define cTT_MAX_FLASH_NA       (0xFFu)

typedef struct STtViewTelltaleList_t
{
    uint16 FlashOnPhaseCntr;
    uint16 FlashOffPhaseCntr;
    uint8 MinFlashCntr;
    uint8 MaxFlashCntr;
} STtViewTelltaleConfigType;

typedef struct STtViewTelltaleInfo_t
{
    uint16 TTOnOffCntr;
    uint8 TTMinFlashCntr;
    uint8 TTMaxFlashCntr;
    uint8 TTInputStatus;
    uint8 PrevTTInputStatus;
    uint8 TTPhase;
    uint8 PatternSize;
    boolean OnePatternFinished;
} STtViewTelltaleInfo;

typedef struct STtViewTelltaleFlashInfo_t
{
    uint16 TelltaleOnOffCntr;
    uint8 TelltalePhase;
    uint8 PatternSize;
    uint8 NoOfActiveClients;
    boolean OnePatternFinished;
    boolean IsFlashRequested;
} STtViewTelltaleFlashInfo;

static STtViewTelltaleConfigType const TTConfigTable[TT_FLASH_SYNC_QUARTER_HZ] = cTtConfigTableList;

static STtViewTelltaleInfo TTInfoTable[cTOTAL_TT_CONFIGURED];

static STtViewTelltaleFlashInfo TelltaleFlashInfoTable[TT_FLASH_SYNC_QUARTER_HZ];

/*Function Declaration*/

void BlinkCtrl_Update_Output(void);
void BlinkCtrl_TtViewUpdateStatus(uint8 index, uint8 tt_status);

/*Static Functions Declaration*/

static void BlinkCtrl_Prepare_Flash_Process(uint8 Tt_index, uint8 Tt_target_phase);
static void BlinkCtrl_Same_Flash_Process(uint8 Tt_index);
static void BlinkCtrl_Different_Flash_Process(uint8 Tt_index);
static void BlinkCtrl_Asynchronous_Flash_Process(uint8 Tt_index); 
static void BlinkCtrl_Flash_Min_Max_Cntr_Process(uint8 Tt_index); 
static void Process_PrevOFFState_TT(uint8 index);
static void Process_PrevONState_TT(uint8 index);
static void Process_PrevBlinkState_TT(uint8 index);
static void assignTTStatus(uint8 index, uint8 status);
static void isOnAllowed(uint8 index);











