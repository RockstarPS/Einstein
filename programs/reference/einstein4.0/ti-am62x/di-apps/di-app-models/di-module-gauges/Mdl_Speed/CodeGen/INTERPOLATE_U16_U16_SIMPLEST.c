/*
 * File: INTERPOLATE_U16_U16_SIMPLEST.c
 *
 * Code generated for Simulink model 'Mdl_Speed'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul  2 16:05:19 2025
 */

#include "INTERPOLATE_U16_U16_SIMPLEST.h"
#include "Platform_Types.h"

/* Lookup Interpolation INTERPOLATE_U16_U16_SIMPLEST */
void INTERPOLATE_U16_U16_SIMPLEST(uint16 *pY, uint16 yL, uint16 yR, uint16 x,
  uint16 xL, uint16 xR)
{
  uint32 bigProd;
  uint16 yDiff;
  uint16 xNum;
  uint16 xDen;
  *pY = yL;

  /* If x is not strictly between xR and xL
   * then an interpolation calculation is not necessary x == xL
   * or not valid.  The invalid situation is expected when the input
   * is beyond the left or right end of the table.  The design is
   * that yL holds the correct value for *pY
   * in invalid situations.
   */
  if ((xR > xL) && (x > xL) ) {
    xDen = xR;
    xDen = (uint16)(((uint32)xDen) - ((uint32)xL));
    xNum = x;
    xNum = (uint16)(((uint32)xNum) - ((uint32)xL));
    if (yR >= yL ) {
      yDiff = yR;
      yDiff = (uint16)(((uint32)yDiff) - ((uint32)yL));
    } else {
      yDiff = yL;
      yDiff = (uint16)(((uint32)yDiff) - ((uint32)yR));
    }

    bigProd = ((uint32)yDiff) * ((uint32)xNum);

    {
      uint32 rtb_u32_tmp;
      uint16 rtb_u16_tmp;
      rtb_u32_tmp = (uint32)xDen;
      if (rtb_u32_tmp == 0U) {
        rtb_u16_tmp = ((uint16)(65535U));

        /* Divide by zero handler */
      } else {
        rtb_u16_tmp = (uint16)(bigProd / rtb_u32_tmp);
      }

      yDiff = rtb_u16_tmp;
    }

    if (yR >= yL ) {
      *pY = (uint16)(((uint32)*pY) + ((uint32)yDiff));
    } else {
      *pY = (uint16)(((uint32)*pY) - ((uint32)yDiff));
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
