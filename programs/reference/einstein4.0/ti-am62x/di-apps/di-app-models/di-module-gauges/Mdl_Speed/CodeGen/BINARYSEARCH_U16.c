/*
 * File: BINARYSEARCH_U16.c
 *
 * Code generated for Simulink model 'Mdl_Speed'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul  2 16:05:19 2025
 */

#include "BINARYSEARCH_U16.h"
#include "Platform_Types.h"

/* Lookup Binary Search Utility BINARYSEARCH_U16 */
void BINARYSEARCH_U16(uint32 *piLeft, uint32 *piRght, uint16 u, const uint16
                      *pData, uint32 iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32 i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
