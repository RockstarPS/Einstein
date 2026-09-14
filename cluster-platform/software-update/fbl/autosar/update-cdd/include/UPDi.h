/*****************************************************************************
*                                                                            *
*              CONFIDENTIAL VISTEON CORPORATION                              *
*                                                                            *
* This is an unpublished work of authorship, which contains trade            *
* secrets, created in 2023. Visteon Corporation owns all rights to           *
* this work and intends to maintain it in confidence to preserve             *
* its trade secret status. Visteon Corporation reserves the right,           *
* under the copyright laws of the United States or those of any              *
* other country that may have jurisdiction, to protect this work             *
* as an unpublished work, in the event of an inadvertent or                  *
* deliberate unauthorized publication. Visteon Corporation also              *
* reserves its rights under all copyright laws to protect this               *
* work as a published work, when appropriate. Those having access            *
* to this work may not copy it, use it, modify it or disclose the            *
* information contained in it without the written authorization              *
* of Visteon Corporation.                                                    *
*                                                                            *
******************************************************************************/

# ifndef UPDi_H
# define UPDi_H

# include "UPD.h"
# include "Std_Types.h"
# include "UPDi_Types.h"
# include "UPDi_Session.h"
# include "UPDi_UpdateMan.h"
# include "UPDi_InstallMan.h"
# include "UPDi_IoAdapter.h"
# include "UPDi_AbstractInstaller.h"
# include "UPDi_Target.h"
# include "UPDd.h"

#define UPDi_DESERIALIZE(pStream, Data, Default) \
	Data = Default;\
	UPDi_Deserialize((pStream), (uint8_t*)&(Data), sizeof(Data))

#define UPDi_SERIALIZE(pStream, Data) \
	UPDi_Serialize((pStream), (uint8_t*)&(Data), sizeof(Data))


//=====================================================================================================================
/* Internal CDD accessors */
//=====================================================================================================================
/* Installers accessors */
tUPDiAbstractInstaller* UPDi_AcquireInstaller(const char* Extension,uint8_t len);

tUPDiAbstractInstaller* UPDi_GetInstallerbyId(uint8_t Id);
uint8_t UPDi_GetInstallerId(tUPDiAbstractInstaller*);

/* Target accessors */
tUPDiTarget* UPDi_GetTarget(uint8_t Id);
uint8_t  	     UPDi_GetTargetId(tUPDiTarget*);
uint8_t        UPDi_GetTargetCount(void);

//=====================================================================================================================
/* Deployment functions - To be defined by the children class */
//=====================================================================================================================
boolean UPDi_CheckDependencies(tUPDBank Bank);
boolean UPDi_VerifyHashes(tUPDiTarget* pTarget, tUPDBank Bank, tUPDiHashingContext* pHashingContext, boolean FirstVerificationAfterInstall);

void    UPDi_DecodeManifestData(char* KeyName, char* KeyValue, tUPDdManifest* pManifest);
void    UPDi_InitializeManifest(tUPDdManifest* pManifest);
void    UPDi_LockResource(void);
void    UPDi_UnlockResource(void);
void    UPDi_NotifyTargetChange(void);
void    UPDi_NotifyUpdateChange(void);

// TODO : remove UPDUpdateCdd
tUPDiTarget*  UPDUpdateCdd_GetTargetByName(char* name);
Std_ReturnType UPDUpdateCdd_GetManifest(const char* TargetName, tUPDBank Bank);



Std_ReturnType UPDi_InitStream(tUPDStream* pStream,void* data,uint32_t Size);
Std_ReturnType UPDi_Deserialize(tUPDStream* pStream,void* data,uint32_t Size);
Std_ReturnType UPDi_Serialize(tUPDStream* pStream,void* data,uint32_t Size);

//=====================================================================================================================
/* tUPDiUpdateCdd configuration */
//=====================================================================================================================
extern tUPDiUpdateCdd oUPDCdd;

# endif /*UPDi_H*/
