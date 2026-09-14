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

#include "UPDi.h"
#include "string.h"
#include "UPDd.h"

// TODO : Why do we need both UPDi.c and UPDi_UpdateCdd.c
//=====================================================================================================================
/* CONSTANTS & TYPES */
extern tUPDiTarget*  oUPDCdd_Targets[];
//=====================================================================================================================

//=====================================================================================================================
/* Static Variables and functions */
//=====================================================================================================================

/*=====================================================================================================================
* tUPDiTarget*  UPDUpdateCdd_GetTargetByName(const char* name)
* Function description : This function shall return the target information
* Input argument : package name
* Return : Return the target details, Null if the target was not found
*=====================================================================================================================*/
tUPDiTarget*  UPDUpdateCdd_GetTargetByName(char* name)
{
    tUPDiTarget* TargetInfo = NULL;
    uint8_t i;
    int32_t ret = 0xFF;

    /*Find the target in deployment target list*/
    for (i = 0u; i < oUPDCdd.TargetsCount; i++)
    {
		ret = strncmp(name, oUPDCdd_Targets[i]->Name, (size_t) UPDd_MAX_PACKAGE_NAME_SIZE);
		if (ret == 0)
		{
			/*target found*/
			TargetInfo = oUPDCdd_Targets[i];
			break;
		}
    }

    if(TargetInfo == NULL)
    {
    	UPDd_WARNING("UPDUpdateCdd_GetTargetByName(): Target <%s> is unknown", name);
    }

    /*Return the target ptr*/
    return TargetInfo;
}

//=====================================================================================================================
/* User interface*/
//=====================================================================================================================
Std_ReturnType UPDUpdateCdd_GetManifest(const char* TargetName, tUPDBank Bank) 
{
    Std_ReturnType status = E_OK;
    return status;
}

#if 0

/*=====================================================================================================================
* uint8 UPDUpdateCdd_GetTargetByName(char* name, uint8 size)
* Function description : Based on the name structure, this function will return the length of the string up to the first
* dot e.g. package.dt.x2 would return len(package). This function assumes that the packagename extends up to the first dot
* and the remainder of the string specifies the format.
* Input argument : package name
* Return : package name length
*=====================================================================================================================*/
static uint8_t UPDUpdateCdd_GetTargetNameLenght(const char* name, uint8_t size)
{
    uint8_t idx = 0;

    while(idx < size)
    {
        if(name[idx++] == '.') break;
    }

    return idx;
}

Std_ReturnType UPDUpdateCdd_GetTargetState(const char* TargetName, tUPDBank Bank) 
{
    return E_NOT_OK;
}


// Target accessors
tUPDiTarget* UPDUpdateCdd_GetTarget(uint16_t Index) 
{
    tUPDiTarget* TargetInfo = NULL;
    TargetInfo = UPDi_GetTarget(Index);
    return TargetInfo;
}


uint16_t UPDUpdateCdd_GetTargetCount(void) 
{
    return UPDi_GetTargetCount();
}

#endif
