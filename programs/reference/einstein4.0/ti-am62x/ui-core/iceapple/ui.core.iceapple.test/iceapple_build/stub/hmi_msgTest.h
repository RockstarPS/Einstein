/*============================================================================
**
**                     CONFIDENTIAL VISTEON CORPORATION
**
** This is an unpublished work of authorship, which contains trade secrets,
** created in 2009. Visteon Corporation owns all rights to this work and
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
**  Name:               hmi_msgTest.h
**
**  Description:
**
**  Organization:       Driver Information Software Section,
**                      DI Core Engineering Department
**
**===========================================================================*/
//#ifndef hmi_msgTest_H
//#define hmi_msgTest_H

/*==========================================================================*/
/* I N C L U D E   F I L E S                                                */
/*==========================================================================*/
#include "system.h"
#include "hmi_SIF.h"
#include "hmi_TestFramework.h"
#include "swtmr.h"

/*==========================================================================*/
/* T Y P E   D E F I N I T I O N S                                          */
/*==========================================================================*/

/*==========================================================================*/
/* E N T R Y   P O I N T S                                                  */
/*==========================================================================*/

extern const TEST_INSTANCE_T message_test_ClearAll;
extern const TEST_INSTANCE_T message_test_OF_WARN_1;
extern const TEST_INSTANCE_T message_test_OF_WARN_2;
extern const TEST_INSTANCE_T message_test_ExpireLast;
extern const TEST_INSTANCE_T message_test_Expire_OF_WARN_2;
extern const TEST_INSTANCE_T message_test_AcknowledgeLast;

extern const TEST_INSTANCE_T message_test_PRIO_A0;
extern const TEST_INSTANCE_T message_test_PRIO_A1;
extern const TEST_INSTANCE_T message_test_PRIO_A2;
extern const TEST_INSTANCE_T message_test_PRIO_A3;
extern const TEST_INSTANCE_T message_test_PRIO_A4;
extern const TEST_INSTANCE_T message_test_PRIO_A5;
extern const TEST_INSTANCE_T message_test_PRIO_A6;
extern const TEST_INSTANCE_T message_test_PRIO_A7;
extern const TEST_INSTANCE_T message_test_PRIO_A8;
extern const TEST_INSTANCE_T message_test_PRIO_A9;
extern const TEST_INSTANCE_T message_test_PRIO_B0;
extern const TEST_INSTANCE_T message_test_PRIO_B1;
extern const TEST_INSTANCE_T message_test_PRIO_B2;
extern const TEST_INSTANCE_T message_test_PRIO_B3;
extern const TEST_INSTANCE_T message_test_PRIO_B4;
extern const TEST_INSTANCE_T message_test_PRIO_B5;
extern const TEST_INSTANCE_T message_test_PRIO_B6;
extern const TEST_INSTANCE_T message_test_PRIO_B7;
extern const TEST_INSTANCE_T message_test_PRIO_B8;
extern const TEST_INSTANCE_T message_test_PRIO_B9;

extern const TEST_INSTANCE_T message_test_STORE_OK_COND_1;

extern const TEST_INSTANCE_T message_test_timeout_STORE_HW_WARN_1;
extern const TEST_INSTANCE_T message_test_timeout_STORE_HW_WARN_2;
extern const TEST_INSTANCE_T message_test_timeout_STORE_SW_WARN_1;
extern const TEST_INSTANCE_T message_test_timeout_STORE_SW_WARN_2;
extern const TEST_INSTANCE_T message_test_timeout_STORE_INF_MSG_1;
extern const TEST_INSTANCE_T message_test_timeout_STORE_INF_MSG_2;
extern const TEST_INSTANCE_T message_test_timeout_STORE_OK_COND_1;
extern const TEST_INSTANCE_T message_test_timeout_STORE_OK_COND_2;

extern const TEST_INSTANCE_T message_test_cancel_STORE_HW_WARN_1;
extern const TEST_INSTANCE_T message_test_cancel_STORE_HW_WARN_2;
extern const TEST_INSTANCE_T message_test_cancel_STORE_SW_WARN_1;
extern const TEST_INSTANCE_T message_test_cancel_STORE_SW_WARN_2;
extern const TEST_INSTANCE_T message_test_cancel_STORE_INF_MSG_1;
extern const TEST_INSTANCE_T message_test_cancel_STORE_INF_MSG_2;
extern const TEST_INSTANCE_T message_test_cancel_STORE_OK_COND_1;
extern const TEST_INSTANCE_T message_test_cancel_STORE_OK_COND_2;


/*----------------------------------------------------------------------*/
/* Setup actions                                                        */
/*----------------------------------------------------------------------*/
extern const TEST_SETUP_T tst_initDummy            ;
extern const TEST_SETUP_T tst_initNotification     ;
extern const TEST_SETUP_T tst_initCallback         ;
extern const TEST_SETUP_T tst_initPurge            ;
extern const TEST_SETUP_T tst_clearAll             ;
extern const TEST_SETUP_T tst_expireDisplayTimer   ;
extern const TEST_SETUP_T tst_expireHoldTimer      ;
extern const TEST_SETUP_T tst_acknowledge_OK       ;
extern const TEST_SETUP_T tst_expireCycleTimer     ;

extern const TEST_SETUP_T tst_category_NONE        ;
extern const TEST_SETUP_T tst_category_ALL         ;
extern const TEST_SETUP_T tst_category_OP          ;
extern const TEST_SETUP_T tst_category_HW          ;
extern const TEST_SETUP_T tst_category_SW          ;
extern const TEST_SETUP_T tst_category_INF         ;
extern const TEST_SETUP_T tst_category_OK          ;

extern const TEST_SETUP_T tst_activate_OF_WARN_1   ;
extern const TEST_SETUP_T tst_activate_OF_WARN_2   ;
extern const TEST_SETUP_T tst_activate_HW_WARN_1   ;
extern const TEST_SETUP_T tst_activate_HW_WARN_2   ;
extern const TEST_SETUP_T tst_activate_HW_WARN_3   ;
extern const TEST_SETUP_T tst_activate_HW_WARN_4   ;
extern const TEST_SETUP_T tst_activate_HW_WARN_5   ;
extern const TEST_SETUP_T tst_activate_HW_WARN_6   ;
extern const TEST_SETUP_T tst_activate_SW_WARN_1   ;
extern const TEST_SETUP_T tst_activate_SW_WARN_2   ;
extern const TEST_SETUP_T tst_activate_INF_MSG_1   ;
extern const TEST_SETUP_T tst_activate_INF_MSG_2   ;
extern const TEST_SETUP_T tst_activate_OK_COND_1   ;
extern const TEST_SETUP_T tst_activate_OK_COND_2   ;

extern const TEST_SETUP_T tst_deactivate_OF_WARN_1 ;
extern const TEST_SETUP_T tst_deactivate_OF_WARN_2 ;
extern const TEST_SETUP_T tst_deactivate_HW_WARN_1 ;
extern const TEST_SETUP_T tst_deactivate_HW_WARN_2 ;
extern const TEST_SETUP_T tst_deactivate_HW_WARN_3 ;
extern const TEST_SETUP_T tst_deactivate_HW_WARN_4 ;
extern const TEST_SETUP_T tst_deactivate_HW_WARN_5 ;
extern const TEST_SETUP_T tst_deactivate_HW_WARN_6 ;
extern const TEST_SETUP_T tst_deactivate_SW_WARN_1 ;
extern const TEST_SETUP_T tst_deactivate_SW_WARN_2 ;
extern const TEST_SETUP_T tst_deactivate_INF_MSG_1 ;
extern const TEST_SETUP_T tst_deactivate_INF_MSG_2 ;
extern const TEST_SETUP_T tst_deactivate_OK_COND_1 ;
extern const TEST_SETUP_T tst_deactivate_OK_COND_2 ;

extern const TEST_SETUP_T tst_dismiss_OF_WARN_1    ;
extern const TEST_SETUP_T tst_dismiss_OF_WARN_2    ;
extern const TEST_SETUP_T tst_dismiss_HW_WARN_1    ;
extern const TEST_SETUP_T tst_dismiss_HW_WARN_2    ;
extern const TEST_SETUP_T tst_dismiss_HW_WARN_3    ;
extern const TEST_SETUP_T tst_dismiss_HW_WARN_4    ;
extern const TEST_SETUP_T tst_dismiss_HW_WARN_5    ;
extern const TEST_SETUP_T tst_dismiss_HW_WARN_6    ;
extern const TEST_SETUP_T tst_dismiss_SW_WARN_1    ;
extern const TEST_SETUP_T tst_dismiss_SW_WARN_2    ;
extern const TEST_SETUP_T tst_dismiss_INF_MSG_1    ;
extern const TEST_SETUP_T tst_dismiss_INF_MSG_2    ;
extern const TEST_SETUP_T tst_dismiss_OK_COND_1    ;
extern const TEST_SETUP_T tst_dismiss_OK_COND_2    ;

extern const TEST_SETUP_T tst_retrigger_OF_WARN_1  ;
extern const TEST_SETUP_T tst_retrigger_OF_WARN_2  ;
extern const TEST_SETUP_T tst_retrigger_HW_WARN_1  ;
extern const TEST_SETUP_T tst_retrigger_HW_WARN_2  ;
extern const TEST_SETUP_T tst_retrigger_HW_WARN_3  ;
extern const TEST_SETUP_T tst_retrigger_HW_WARN_4  ;
extern const TEST_SETUP_T tst_retrigger_HW_WARN_5  ;
extern const TEST_SETUP_T tst_retrigger_HW_WARN_6  ;
extern const TEST_SETUP_T tst_retrigger_SW_WARN_1  ;
extern const TEST_SETUP_T tst_retrigger_SW_WARN_2  ;
extern const TEST_SETUP_T tst_retrigger_INF_MSG_1  ;
extern const TEST_SETUP_T tst_retrigger_INF_MSG_2  ;
extern const TEST_SETUP_T tst_retrigger_OK_COND_1  ;
extern const TEST_SETUP_T tst_retrigger_OK_COND_2  ;

/*----------------------------------------------------------------------*/
/* Run Actions                                                          */
/*----------------------------------------------------------------------*/
extern const TEST_RUN_T   tst_runDummy            ;
extern const TEST_RUN_T   tst_runOnce             ;

/*----------------------------------------------------------------------*/
/* Check actions                                                        */
/*----------------------------------------------------------------------*/
extern const TEST_CHECK_T chk_Dummy               ;

extern const TEST_CHECK_T chk_Display_NONE       ;
extern const TEST_CHECK_T chk_Display_OF_WARN_1  ;
extern const TEST_CHECK_T chk_Display_OF_WARN_2  ;
extern const TEST_CHECK_T chk_Display_HW_WARN_1  ;
extern const TEST_CHECK_T chk_Display_HW_WARN_2  ;
extern const TEST_CHECK_T chk_Display_HW_WARN_3  ;
extern const TEST_CHECK_T chk_Display_HW_WARN_4  ;
extern const TEST_CHECK_T chk_Display_HW_WARN_5  ;
extern const TEST_CHECK_T chk_Display_HW_WARN_6  ;
extern const TEST_CHECK_T chk_Display_SW_WARN_1  ;
extern const TEST_CHECK_T chk_Display_SW_WARN_2  ;
extern const TEST_CHECK_T chk_Display_INF_MSG_1  ;
extern const TEST_CHECK_T chk_Display_INF_MSG_2  ;
extern const TEST_CHECK_T chk_Display_OK_COND_1  ;
extern const TEST_CHECK_T chk_Display_OK_COND_2  ;

extern const TEST_CHECK_T chk_SeqFirst_NONE       ;
extern const TEST_CHECK_T chk_SeqFirst_OF_WARN_1  ;
extern const TEST_CHECK_T chk_SeqFirst_OF_WARN_2  ;
extern const TEST_CHECK_T chk_SeqFirst_HW_WARN_1  ;
extern const TEST_CHECK_T chk_SeqFirst_HW_WARN_2  ;
extern const TEST_CHECK_T chk_SeqFirst_SW_WARN_1  ;
extern const TEST_CHECK_T chk_SeqFirst_SW_WARN_2  ;
extern const TEST_CHECK_T chk_SeqFirst_INF_MSG_1  ;
extern const TEST_CHECK_T chk_SeqFirst_INF_MSG_2  ;
extern const TEST_CHECK_T chk_SeqFirst_OK_COND_1  ;
extern const TEST_CHECK_T chk_SeqFirst_OK_COND_2  ;

extern const TEST_CHECK_T chk_SeqNext_OF_WARN_1   ;
extern const TEST_CHECK_T chk_SeqNext_OF_WARN_2   ;
extern const TEST_CHECK_T chk_SeqNext_HW_WARN_1   ;
extern const TEST_CHECK_T chk_SeqNext_HW_WARN_2   ;
extern const TEST_CHECK_T chk_SeqNext_SW_WARN_1   ;
extern const TEST_CHECK_T chk_SeqNext_SW_WARN_2   ;
extern const TEST_CHECK_T chk_SeqNext_INF_MSG_1   ;
extern const TEST_CHECK_T chk_SeqNext_INF_MSG_2   ;
extern const TEST_CHECK_T chk_SeqNext_OK_COND_1   ;
extern const TEST_CHECK_T chk_SeqNext_OK_COND_2   ;

extern const TEST_CHECK_T chk_SeqIndex_0          ;
extern const TEST_CHECK_T chk_SeqIndex_1          ;
extern const TEST_CHECK_T chk_SeqIndex_2          ;
extern const TEST_CHECK_T chk_SeqIndex_3          ;
extern const TEST_CHECK_T chk_SeqIndex_4          ;
extern const TEST_CHECK_T chk_SeqIndex_5          ;
extern const TEST_CHECK_T chk_SeqIndex_6          ;
extern const TEST_CHECK_T chk_SeqIndex_7          ;
extern const TEST_CHECK_T chk_SeqIndex_8          ;
extern const TEST_CHECK_T chk_SeqIndex_9          ;

extern const TEST_CHECK_T chk_SeqMessage_OF_WARN_1 ;
extern const TEST_CHECK_T chk_SeqMessage_OF_WARN_2 ;
extern const TEST_CHECK_T chk_SeqMessage_HW_WARN_1 ;
extern const TEST_CHECK_T chk_SeqMessage_HW_WARN_2 ;
extern const TEST_CHECK_T chk_SeqMessage_SW_WARN_1 ;
extern const TEST_CHECK_T chk_SeqMessage_SW_WARN_2 ;
extern const TEST_CHECK_T chk_SeqMessage_INF_MSG_1 ;
extern const TEST_CHECK_T chk_SeqMessage_INF_MSG_2 ;
extern const TEST_CHECK_T chk_SeqMessage_OK_COND_1 ;
extern const TEST_CHECK_T chk_SeqMessage_OK_COND_2 ;


extern const TEST_CHECK_T chk_StorFirst_NONE      ;
extern const TEST_CHECK_T chk_StorFirst_OF_WARN_1 ;
extern const TEST_CHECK_T chk_StorFirst_OF_WARN_2 ;
extern const TEST_CHECK_T chk_StorFirst_HW_WARN_1 ;
extern const TEST_CHECK_T chk_StorFirst_HW_WARN_2 ;
extern const TEST_CHECK_T chk_StorFirst_SW_WARN_1 ;
extern const TEST_CHECK_T chk_StorFirst_SW_WARN_2 ;
extern const TEST_CHECK_T chk_StorFirst_INF_MSG_1 ;
extern const TEST_CHECK_T chk_StorFirst_INF_MSG_2 ;
extern const TEST_CHECK_T chk_StorFirst_OK_COND_1 ;
extern const TEST_CHECK_T chk_StorFirst_OK_COND_2 ;
extern const TEST_CHECK_T chk_StorNext_NONE       ;
extern const TEST_CHECK_T chk_StorNext_OF_WARN_1  ;
extern const TEST_CHECK_T chk_StorNext_OF_WARN_2  ;
extern const TEST_CHECK_T chk_StorNext_HW_WARN_1  ;
extern const TEST_CHECK_T chk_StorNext_HW_WARN_2  ;
extern const TEST_CHECK_T chk_StorNext_SW_WARN_1  ;
extern const TEST_CHECK_T chk_StorNext_SW_WARN_2  ;
extern const TEST_CHECK_T chk_StorNext_INF_MSG_1  ;
extern const TEST_CHECK_T chk_StorNext_INF_MSG_2  ;
extern const TEST_CHECK_T chk_StorNext_OK_COND_1  ;
extern const TEST_CHECK_T chk_StorNext_OK_COND_2  ;
extern const TEST_CHECK_T chk_StorPrev_NONE       ;
extern const TEST_CHECK_T chk_StorPrev_OF_WARN_1  ;
extern const TEST_CHECK_T chk_StorPrev_OF_WARN_2  ;
extern const TEST_CHECK_T chk_StorPrev_HW_WARN_1  ;
extern const TEST_CHECK_T chk_StorPrev_HW_WARN_2  ;
extern const TEST_CHECK_T chk_StorPrev_SW_WARN_1  ;
extern const TEST_CHECK_T chk_StorPrev_SW_WARN_2  ;
extern const TEST_CHECK_T chk_StorPrev_INF_MSG_1  ;
extern const TEST_CHECK_T chk_StorPrev_INF_MSG_2  ;
extern const TEST_CHECK_T chk_StorPrev_OK_COND_1  ;
extern const TEST_CHECK_T chk_StorPrev_OK_COND_2  ;
extern const TEST_CHECK_T chk_SeqCount_NONE       ;
extern const TEST_CHECK_T chk_SeqCount_1          ;
extern const TEST_CHECK_T chk_SeqCount_2          ;
extern const TEST_CHECK_T chk_SeqCount_3          ;
extern const TEST_CHECK_T chk_SeqCount_4          ;
extern const TEST_CHECK_T chk_SeqCount_5          ;
extern const TEST_CHECK_T chk_SeqCount_6          ;
extern const TEST_CHECK_T chk_SeqCount_7          ;
extern const TEST_CHECK_T chk_SeqCount_8          ;
extern const TEST_CHECK_T chk_SeqCount_9          ;
extern const TEST_CHECK_T chk_SeqCount_10         ;
extern const TEST_CHECK_T chk_StorCount_NONE      ;
extern const TEST_CHECK_T chk_StorCount_1         ;
extern const TEST_CHECK_T chk_StorCount_2         ;
extern const TEST_CHECK_T chk_StorCount_3         ;
extern const TEST_CHECK_T chk_StorCount_4         ;
extern const TEST_CHECK_T chk_StorCount_5         ;
extern const TEST_CHECK_T chk_StorCount_6         ;
extern const TEST_CHECK_T chk_StorCount_7         ;
extern const TEST_CHECK_T chk_StorCount_8         ;
extern const TEST_CHECK_T chk_StorCount_9         ;
extern const TEST_CHECK_T chk_StorCount_10        ;
extern const TEST_CHECK_T chk_StorNotify_YES      ;
extern const TEST_CHECK_T chk_SeqNotify_YES       ;
extern const TEST_CHECK_T chk_Callback_NONE       ;
extern const TEST_CHECK_T chk_Callback_USERACK    ;
extern const TEST_CHECK_T chk_Callback_TIMEOUT    ;
extern const TEST_CHECK_T chk_Callback_HIDDEN     ;
extern const TEST_CHECK_T chk_Callback_SHOW       ;
extern const TEST_CHECK_T chk_Callback_ACTIVE     ;
extern const TEST_CHECK_T chk_Callback_INACTIVE   ;
extern const TEST_CHECK_T chk_AlertCount_NONE     ;
extern const TEST_CHECK_T chk_AlertCount_ONE      ;
extern const TEST_CHECK_T chk_AlertCount_TWO      ;
extern const TEST_CHECK_T chk_AlertMessage_NONE      ;
extern const TEST_CHECK_T chk_AlertMessage_OF_WARN_1 ;
extern const TEST_CHECK_T chk_AlertMessage_OF_WARN_2 ;
extern const TEST_CHECK_T chk_AlertMessage_HW_WARN_1 ;
extern const TEST_CHECK_T chk_AlertMessage_HW_WARN_2 ;
extern const TEST_CHECK_T chk_AlertMessage_SW_WARN_1 ;
extern const TEST_CHECK_T chk_AlertMessage_SW_WARN_2 ;
extern const TEST_CHECK_T chk_AlertMessage_INF_MSG_1 ;
extern const TEST_CHECK_T chk_AlertMessage_INF_MSG_2 ;
extern const TEST_CHECK_T chk_AlertMessage_OK_COND_1 ;
extern const TEST_CHECK_T chk_AlertMessage_OK_COND_2 ;


extern const TEST_SETUP_T tst_selectStatus_SEQ    ;
extern const TEST_SETUP_T tst_selectStatus_STOR   ;
extern const TEST_SETUP_T tst_selectStatus_ALL    ;

extern const TEST_CHECK_T chk_Status_NONE           ;
extern const TEST_CHECK_T chk_Status_OF_WARN        ;
extern const TEST_CHECK_T chk_Status_HW_WARN        ;
extern const TEST_CHECK_T chk_Status_SW_WARN        ;
extern const TEST_CHECK_T chk_Status_INF_MSG        ;
extern const TEST_CHECK_T chk_Status_OK_COND        ;













/*==========================================================================*/
/* F U N C T I O N  P R O T O T Y P E S                                     */
/*==========================================================================*/

U16SIF_STANDARD_INTERFACE(test_GetWarningState);
U16SIF_STANDARD_INTERFACE(test_EventCallback);
void msgtest_ShowMessage(UINT32 Message);
void msgtest_HideMessage(UINT32 Message);

void test_Mark(UINT32 Value);
void test_StartTimer(UINT32 timeout, TIMER timer);
UINT8 test_CheckTimer(TIMER timer);
void test_ClearTimer(TIMER timer);
void test_Notification(UINT8 msgSource);
#define MSG_STORE_NOTIFY    (BIT0)
#define MSG_SEQUENCE_NOTIFY (BIT1)

/*==========================================================================*/
/* R E V I S I O N    N O T E S                                             */
/*==========================================================================*/
/* For each change to this file, be sure to record:
** 1.  Who made the change and when the change was made.
** 2.  Why the change was made and the intended result.
**==========================================================================*/

/****************************************************************************
**  Date  : 09/Apr/2010
**  by    : AFERRIS2
**  Ref   : None.
**  Change: Initial version.
**
*****************************************************************************/

//#endif  /* hmi_msgTest_H */
/* end of file =============================================================*/
