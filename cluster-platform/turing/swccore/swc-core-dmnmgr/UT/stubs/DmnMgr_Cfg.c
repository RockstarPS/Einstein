//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2020] Visteon Corporation
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
//--------------------------------------------------------------------------------------------------------------------

#include "DmnMgr_Cfg.h"

extern SDmnMgrUsrCfg * DmnMgr_UserConfigurations(void)
{
	/* Misra 2012 Rule 8.9 */
	static const SDmnMgrUsrCfgList DmnMgrUsrConfig[MANAGED_DOMAINS_CNT] = 
	{
		{
			1,		/* GIP Domain ID */
			1000,	/* The Periodicity at which HB Msgs from Domain is expected.*/
			5,		/*Acceptable HB Miss Count before DM initiate GIP Reset, FUSA req */
			40000,	/*Maximum time to wait for first HB from Domain */
			8000,	/*Maximum time to wait for System State to transition into Full Run */	
			1,		/*Allowed deviation between successive Sequence Counter values from domains */
			5000,	/*Maximum time to wait for UCL Link Up */
			120,	/*Maximum time after the shutdown sent to UCL based on timings captured from VIP*/
			1200,	/*Maximum wait time after the shutdown sent to GIP*/
		},
		{
			2,		/* DM Domain ID */
			0,	/* The Periodicity at which HB Msgs from Domain is expected.*/
			0,		/*Acceptable HB Miss Count before DM initiate GIP Reset, FUSA req */
			0,	/*Maximum time to wait for first HB from Domain */
			0,	/*Maximum time to wait for System State to transition into Full Run */	
			0,		/*Allowed deviation between successive Sequence Counter values from domains */
			0,	/*Maximum time to wait for UCL Link Up */
			0,	/*Maximum time after the shutdown sent to UCL based on timings captured from DM*/
			0,  /*Maximum wait time after the shutdown sent to HSM*/
		},
		{
			3,	/* HSM Domain ID */
			0,	/* The Periodicity at which HB Msgs from Domain is expected.*/
			0,	/*Acceptable HB Miss Count before DM initiate GIP Reset, FUSA req */
			0,	/*Maximum time to wait for first HB from Domain */
			0,	/*Maximum time to wait for System State to transition into Full Run */	
			0,	/*Allowed deviation between successive Sequence Counter values from domains */
			0,	/*Maximum time to wait for UCL Link Up */
			0,	/*Maximum time after the shutdown sent to UCL based on timings captured from HSM*/
			0,  /*Maximum wait time after the shutdown sent to DM*/
		},
	};
	static SDmnMgrUsrCfg DmnMgrUsrCfg =
	{
		MANAGED_DOMAINS_CNT,
		{&DmnMgrUsrConfig[0],
		&DmnMgrUsrConfig[1],
		&DmnMgrUsrConfig[2]},
	};
     return (&DmnMgrUsrCfg);
}

/* 
#-------------------------------------------------------------------------------------------------------------------
#    Date    |    User   |       Task        |                                     Description
#-------------------------------------------------------------------------------------------------------------------
# 16/02/2024 |  MYALLA   | JLR3C29298-225822 | Health Management(V1)-Domain Manager Functional Testing & Delivery
*/


