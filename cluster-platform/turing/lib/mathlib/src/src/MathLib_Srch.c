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

#include <stdlib.h>
#include "Std_Types.h"
#include "MathLib.h"

//=====================================================================================================================
//  PUBLIC
//=====================================================================================================================
#define MATHLIB_CODE_SEC_START
#include "MemMap.h"			//As per Autosar Standard. AUTOSAR_SWS_MemoryMapping, MemMap.h  is used in Mathlib.
sint Compare_S8(  void const * const pElem1, void const * const pElem2 )
{
    sint Result;
    // polyspace<RTE:IDP> No danger of failure here. Check is done by calling function.
   	if ( ( *(const sint8 *)pElem1) > ( *(const sint8 *)pElem2) )
    {
        Result = 1;
    }
    else if ( *(const sint8 *)pElem1 == *(const sint8 *)pElem2 )
    {
        Result = 0;
    }
    else
    {
        Result = -1;
    }

    return Result;
}

sint Compare_S16( void const * const pElem1, void const * const pElem2 )
{
    sint Result;
    // polyspace<RTE:IDP> No danger of failure here. Check is done by calling function.
    if ( ( *(const sint16 *)pElem1) > ( *(const sint16 *)pElem2) )
    {
        Result = 1;
    }
    else if ( *(const sint16 *)pElem1 == *(const sint16 *)pElem2 )
    {
        Result = 0;
    }
    else
    {
        Result = -1;
    }

    return Result;
}

sint Compare_S32( void const * const pElem1, void const * const pElem2 )
{
    sint Result;
    // polyspace<RTE:IDP> No danger of failure here. Check is done by calling function.
    if ( ( *(const sint32 *)pElem1) > ( *(const sint32 *)pElem2) )
    {
        Result = 1;
    }
    else if ( *(const sint32 *)pElem1 == *(const sint32 *)pElem2 )
    {
        Result = 0;
    }
    else
    {
        Result = -1;
    }

    return Result;
}

sint Compare_U8(  void const * const pElem1, void const * const pElem2 )
{
    sint Result;
    // polyspace<RTE:IDP> No danger of failure here. Check is done by calling function.
    if ( ( *(const uint8 *)pElem1) > ( *(const uint8 *)pElem2) )
    {
        Result = 1;
    }
    else if ( *(const uint8 *)pElem1 == *(const uint8 *)pElem2 )
    {
        Result = 0;
    }
    else
    {
        Result = -1;
    }

    return Result;
}

sint Compare_U16( void const * const pElem1, void const * const pElem2 )
{
    sint Result;
    // polyspace<RTE:IDP> No danger of failure here. Check is done by calling function.
    if ( ( *(const uint16 *)pElem1) > ( *(const uint16 *)pElem2) )
	
    {
        Result = 1;
    }
    else if ( *(const uint16 *)pElem1 == *(const uint16 *)pElem2 )
    {
        Result = 0;
    }
    else
    {
        Result = -1;
    }

    return Result;
}

sint Compare_U32( void const * const pElem1, void const * const pElem2 )
{
    sint Result;
    // polyspace<RTE:IDP> No danger of failure here. Check is done by calling function.
    if ( ( *(const uint32 *)pElem1) > ( *(const uint32 *)pElem2) )
    {
        Result = 1;
    }
    else if ( *(const uint32 *)pElem1 == *(const uint32 *)pElem2 )
    {
        Result = 0;
    }
    else
    {
        Result = -1;
    }

    return Result;
}

//----------------------------------------------------------------------------------------------------------------------
/// @brief    Performs linear search on an array of a custom data type
///
/// @param    pArray:           pointer to the array
/// @param    ArraySize:        size of the array
/// @param    pSearchValue:     the value to be found in the array
/// @param    pPositionFound:   position of searched value in case it is found
/// @param    TypeSize:         size of data type
/// @param    pCompareFunction: function to compare the elements
///
/// @return   sint8:            -1 - invalid arguments
///<br>                          0 - value is found
///<br>                          1 - value is not found
//----------------------------------------------------------------------------------------------------------------------
sint8 MathLib_LinearSearch( void * const fl_pArray,
                            const uint32 fl_ArraySize,
                            void const * const fl_pSearchValue,
                            uint32 * const fl_pPositionFound,
                            const uint32 fl_TypeSize,
                            const CompareFunc fl_pCompareFunction )
{
    uint32 Ix;
    sint  CompResult;
    uint8 * pTemp;
    sint8 Result = 1; 

    if( (NULL != fl_pArray) && (NULL != fl_pSearchValue) && (NULL != fl_pCompareFunction) )
    {
        Ix = (uint32)0;
        pTemp = (uint8*)fl_pArray;

        while( Ix < fl_ArraySize )
        {
            CompResult = fl_pCompareFunction(fl_pSearchValue, pTemp);
            if( 0 == CompResult )
            {
                Result = 0;
                *fl_pPositionFound = Ix;
                break;
            }

            Ix++;
            pTemp = &pTemp[fl_TypeSize];	//As user specific, bound value not estimated
        }
    }
    else
    {
        Result = -1; 
    }

    return Result;
}
#define MATHLIB_CODE_SEC_END
#include "MemMap.h"		//As per Autosar Standard. AUTOSAR_SWS_MemoryMapping, MemMap.h  is used in Mathlib.
