//---------------------------------------------------------------------------------------------------------------------
//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2019] Visteon Corporation
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

//=====================================================================================================================
//  INCLUDED FILES
//=====================================================================================================================

#include "Checksum.h"

#define CHECKSUM_LENGTH_4BIT 4u
#define CHECKSUM_MASKVALUE_4BIT 0x0FU
#define CHECKSUM_DATAVALUE_ONE 1U

/* 8 Bit CheckSum */
#define  CHECKSUM_EIGHT_BIT_CHECKSUM  8U
#define  CHECKSUM_MASKVALUE_8BIT 0xFFU
#include "AssertLib.h"


static uint8 Checksum_Reverse4bit(const uint8 CheckSum_DataPtr, uint8 CheckSum_Length);

uint32 Checksum_CalculateAdditiveChecksum32(const uint32 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall)
{
	uint32 Checksum_Loopcount = 0;
	uint32 InterChecksumValue = 0;
	
	if (TRUE == Crc_IsFirstCall)
	{
		InterChecksumValue = 0;
	}
	else
	{
		InterChecksumValue = Crc_StartValue32;
	}	
	for (Checksum_Loopcount = 0; Checksum_Loopcount < Crc_Length; Checksum_Loopcount++)
	{
		if( ( (uint64) InterChecksumValue + Crc_DataPtr[Checksum_Loopcount] ) < 0xFFFFFFFFU ) 
		{
			InterChecksumValue += Crc_DataPtr[Checksum_Loopcount];
		}
		else
		{
			DEBUG_ASSERT( FALSE );
		}
	}
	return InterChecksumValue;
}

void CalculateChecksum(const uint32 *Crc_DataPtr, uint32 Crc_Length, uint32 Crc_StartValue32, boolean Crc_IsFirstCall, uint32 *ChecksumValue)
{
	*ChecksumValue = Checksum_CalculateAdditiveChecksum32(Crc_DataPtr, Crc_Length, Crc_StartValue32, Crc_IsFirstCall);
}

/*============================================================================
**
** Function Name    :   Checksum_Reversebit
**
** Visibility       :   Private
**
** Description      :   This function will reverse the 4bit given data
**
** Invocation       :   Whoever wants to Reverse the 4 bit of Data.
**
** Inputs           :   CheckSum_DataPtr: Pointer to the data for which the data bit to be reversed
**                      CheckSum_Length: Number of bit in the data.
**
** Outputs          :   Reversed value
**
**==========================================================================*/
static uint8 Checksum_Reverse4bit(const uint8 CheckSum_Data, uint8 CheckSum_Length)
{
    uint8 CheckSum_DataCount = 0U;
    uint8 CheckSum_Reverse_value = 0U;
    if( (0U != CheckSum_Data) && (CHECKSUM_LENGTH_4BIT == CheckSum_Length) )
    {
        for (CheckSum_DataCount = 0U; CheckSum_DataCount < CheckSum_Length; CheckSum_DataCount++)
        {
            if(CheckSum_Data & (CHECKSUM_DATAVALUE_ONE <<CheckSum_DataCount))
            {
                CheckSum_Reverse_value |= CHECKSUM_DATAVALUE_ONE << ((CheckSum_Length - CHECKSUM_DATAVALUE_ONE) - CheckSum_DataCount);
            }
        }
    }
    else
    {
        CheckSum_Reverse_value = CheckSum_Data;
    }
    return CheckSum_Reverse_value;

}
/*============================================================================
**
** Function Name    :   Checksum_CalculateCheckSum4
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 4 bit checksum
**                       for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 4 bit checksum.
**
** Inputs           :   CheckSum_DataPtr: Pointer to the data for which the 4 bit checksum to be calculated
**                      CheckSum_Length: Number of bytes to be taken for calculation.
**                      CheckSum_StartValue32: 4 bit checksum Start value, if this is a continuation of
**                                       previous 4 bit checksum calculation. Crc_IsFirstCall shall be
**                                       FALSE for this to be considered.
**                      CheckSum_IsFirstCall: TRUE if this is the first call for 4 bit checksum calculation. Start Value will be 0xFFFFFFFF.
**                                       FALSE if this is a continuation of precious 4 bit checksum calculation.
**
** Outputs          :   Calculated 4 bit CRC CheckSum
**
**==========================================================================*/
uint8 Checksum_CalculateCheckSum4(const uint8 *CheckSum_DataPtr, uint32 CheckSum_Length, uint8 CheckSum_StartValue8, boolean CheckSum_IsFirstCall)
{
    uint8 CheckSum_Value;
    uint32 CheckSum_DataCount;

    if( FALSE != CheckSum_IsFirstCall )
    {
        /* If first CRC call, set the initial value */
        CheckSum_Value = 0x00U;
    }
    else
    {
        /* If continuation of CRC calculation, then revert back the last CRC value*/
        CheckSum_Value = Checksum_Reverse4bit((CheckSum_StartValue8-0x1U),CHECKSUM_LENGTH_4BIT);
    }
    if (NULL_PTR != CheckSum_DataPtr)
    {
        for (CheckSum_DataCount = 0U; CheckSum_DataCount < CheckSum_Length; CheckSum_DataCount++)
        {
			if( ((uint16)( CheckSum_Value + (CheckSum_DataPtr[CheckSum_DataCount] & CHECKSUM_MASKVALUE_4BIT))) < 0xFFU ) 
			{
            CheckSum_Value += (CheckSum_DataPtr[CheckSum_DataCount] & CHECKSUM_MASKVALUE_4BIT);
			}
			else
		    {
				DEBUG_ASSERT( FALSE );
		    }
            CheckSum_Value += (CheckSum_DataPtr[CheckSum_DataCount] >> CHECKSUM_LENGTH_4BIT & CHECKSUM_MASKVALUE_4BIT);
            CheckSum_Value = (CheckSum_Value & CHECKSUM_MASKVALUE_4BIT);
        }
        
        /* Invert the final CRC Value */
		CheckSum_Value = ((~CheckSum_Value) & CHECKSUM_MASKVALUE_4BIT)+CHECKSUM_DATAVALUE_ONE;
    }
    

    return (CheckSum_Value & CHECKSUM_MASKVALUE_4BIT);
}

/*============================================================================
**
** Function Name    :   Checksum_CalculateCheckSum8
**
** Visibility       :   Public
**
** Description      :   This function calculates and returns the 8 bit checksum
**                       for the given number of data.
**
** Invocation       :   Whoever wants to calculate the 8 bit checksum.
**
** Inputs           :   CheckSum_DataPtr: Pointer to the data for which the 8 bit checksum to be calculated
**                      CheckSum_Length: Number of bytes to be taken for calculation.
**                      CheckSum_StartValue32: 8 bit checksum Start value, if this is a continuation of
**                                       previous 8 bit checksum calculation. Crc_IsFirstCall shall be
**                                       FALSE for this to be considered.
**                      CheckSum_IsFirstCall: TRUE if this is the first call for 8 bit checksum calculation. Start Value will be 0xFFFFFFFF.
**                                       FALSE if this is a continuation of precious 8 bit checksum calculation.
**
** Outputs          :   Calculated 8 bit CRC CheckSum
**
**==========================================================================*/
uint8 Checksum_CalculateCheckSum8(const uint8 *CheckSum_DataPtr, uint32 CheckSum_Length, uint8 CheckSum_StartValue8, boolean CheckSum_IsFirstCall)
{
    uint8 CheckSum_Value;
    uint32 CheckSum_DataCount;
    uint32 flNo_of_Bits_Signal = CheckSum_Length ;//Convert bytes to bit


        if( FALSE != CheckSum_IsFirstCall )
        {
            /* If first CRC call, set the initial value */
            CheckSum_Value = 0x00U;
        }
        else
        {
            /* If continuation of CRC calculation, then revert back the last CRC value*/
            CheckSum_Value = ~CheckSum_StartValue8;
        }
        if (NULL_PTR != CheckSum_DataPtr)
        {
            for (CheckSum_DataCount = 0U; CheckSum_DataCount < flNo_of_Bits_Signal; CheckSum_DataCount++)
            {
				if( ((uint16)( CheckSum_Value + (CheckSum_DataPtr[CheckSum_DataCount] & CHECKSUM_MASKVALUE_8BIT))) < 0xFFU ) 
				{
                CheckSum_Value += (CheckSum_DataPtr[CheckSum_DataCount] & CHECKSUM_MASKVALUE_8BIT);
                CheckSum_Value = (CheckSum_Value & CHECKSUM_MASKVALUE_8BIT);
				}
				else
				{
					DEBUG_ASSERT( FALSE );
				}
            }

            /* the one's complement of final Checksum */
            CheckSum_Value = ((~CheckSum_Value) & CHECKSUM_MASKVALUE_8BIT);
        }


        return (CheckSum_Value);

}
/**====================================================================================================================================
 **      CDSID         Date             Traceability                                 Description
 **====================================================================================================================================
 **     aescami1     15-Oct-2019     628725 - Generate RTE                  Added Checksum_CmpMain function.
 **     bbaskara     04-Sep-2020     1031445: [vAutosar]  4-bit Checksum: Implementation.
 **     bbaskara     11-Mar-2021     1261130: [vautosar] Implementation of 8bit Checksum
 **     gthanapp     28_Mar_2022     RTC#1564070                            Cert-C warning analysis and fix
 **     adewang1     20_Nov_2023     DICVA-660                             Misra warning analysis and fix
  **====================================================================================================================================*/
