/*
 * File: LookUp_U16_U16_SIMPLEST.c
 *
 * Code generated for Simulink model 'Mdl_Speed'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul  2 16:05:19 2025
 */

#include "LookUp_U16_U16_SIMPLEST.h"
#include "BINARYSEARCH_U16.h"
#include "INTERPOLATE_U16_U16_SIMPLEST.h"
#include "Platform_Types.h"

/* Lookup Utility LookUp_U16_U16_SIMPLEST */
void LookUp_U16_U16_SIMPLEST(uint16 *pY, const uint16 *pYData, uint16 u, const
  uint16 *pUData, uint32 iHi)
{
  uint32 iLeft;
  uint32 iRght;
  BINARYSEARCH_U16( &(iLeft), &(iRght), u, pUData, iHi);
  INTERPOLATE_U16_U16_SIMPLEST( pY, pYData[iLeft], pYData[iRght], u,
    pUData[iLeft], pUData[iRght]);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
