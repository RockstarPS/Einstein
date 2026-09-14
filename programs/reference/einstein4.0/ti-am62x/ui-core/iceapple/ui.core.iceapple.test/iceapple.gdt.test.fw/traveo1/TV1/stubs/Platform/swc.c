#include "Rte_WrnCtrl.h"
Std_ReturnType WrnCtrl_GetFirst(TWrnListMask List, TWrnId * Id)
{
    return 0;
}

void WrnCtrl_Release(void){}
#include "WrnCtrl_Cfg.h"
Std_ReturnType WrnCtrl_GetNext(TWrnListMask List, TWrnId* Id)
{
    *Id = eWrnId_Count;
    return 0;
}

void CWrnCtrl_Acknowledge( TWrnId Id )
{}

#define GFX_IMG_DATA_PREFIX
#define GFX_IMG_DATA_SUFFIX 
typedef unsigned char  GFX_IMG_DATA_T;
typedef unsigned short GFX_IMG_DATA16_T;
typedef unsigned int GFX_IMG_DATA32_T;
