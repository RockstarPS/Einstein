/*
*
* Copyright (C) 2024 Texas Instruments Incorporated
*
* All rights reserved not granted herein.
*
* Limited License.
*
* Texas Instruments Incorporated grants a world-wide, royalty-free, non-exclusive
* license under copyrights and patents it now or hereafter owns or controls to make,
* have made, use, import, offer to sell and sell ("Utilize") this software subject to the
* terms herein.  With respect to the foregoing patent license, such license is granted
* solely to the extent that any such patent is necessary to Utilize the software alone.
* The patent license shall not apply to any combinations which include this software,
* other than combinations with devices manufactured by or for TI ("TI Devices").
* No hardware patent is licensed hereunder.
*
* Redistributions must preserve existing copyright notices and reproduce this license
* (including the above copyright notice and the disclaimer and (if applicable) source
* code license limitations below) in the documentation and/or other materials provided
* with the distribution
*
* Redistribution and use in binary form, without modification, are permitted provided
* that the following conditions are met:
*
* *       No reverse engineering, decompilation, or disassembly of this software is
* permitted with respect to any software provided in binary form.
*
* *       any redistribution and use are licensed by TI for use only with TI Devices.
*
* *       Nothing shall obligate TI to provide you with source code for the software
* licensed and provided to you in object code.
*
* If software source code is provided to you, modification and redistribution of the
* source code are permitted provided that the following conditions are met:
*
* *       any redistribution and use of the source code, including any resulting derivative
* works, are licensed by TI for use only with TI Devices.
*
* *       any redistribution and use of any object code compiled from the source code
* and any resulting derivative works, are licensed by TI for use only with TI Devices.
*
* Neither the name of Texas Instruments Incorporated nor the names of its suppliers
*
* may be used to endorse or promote products derived from this software without
* specific prior written permission.
*
* DISCLAIMER.
*
* THIS SOFTWARE IS PROVIDED BY TI AND TI'S LICENSORS "AS IS" AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL TI AND TI'S LICENSORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
* DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
* OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
* OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
* OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/**
 *  \file     Eth_LL.h
 *
 *  \brief    This file contains the structure definitions and function
 *            prototypes of the Eth Dma lowler descriptor configuration
 */

#ifndef ETH_LL_H
#define ETH_LL_H

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "Std_Types.h"
#include "cslr.h"
#include "Eth_LL_Types.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* \brief UDMAP CPPI5 PD field  */
#define CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_SHIFT             ((uint32) 30U)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_MASK              (((uint32) 0x3U) << CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_SHIFT)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_EINFO_SHIFT             ((uint32) 29U)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_EINFO_MASK              (((uint32) 0x1U) << CSL_UDMAP_CPPI5_PD_DESCINFO_EINFO_SHIFT)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_PSINFO_SHIFT            ((uint32) 28U)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_PSINFO_MASK             (((uint32) 0x1U) << CSL_UDMAP_CPPI5_PD_DESCINFO_PSINFO_SHIFT)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_PSWCNT_SHIFT            ((uint32) 22U)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_PSWCNT_MASK             (((uint32) 0x3FU) << CSL_UDMAP_CPPI5_PD_DESCINFO_PSWCNT_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO1_PSFLGS_SHIFT            ((uint32) 24U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO1_PSFLGS_MASK             (((uint32)0xFU) << CSL_UDMAP_CPPI5_PD_PKTINFO1_PSFLGS_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO1_PKTID_SHIFT             ((uint32) 14U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO1_PKTID_MASK              (((uint32) 0x3FFU) << CSL_UDMAP_CPPI5_PD_PKTINFO1_PKTID_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO1_FLOWID_SHIFT            ((uint32) 0U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO1_FLOWID_MASK             (((uint32) 0x3FFFU) << CSL_UDMAP_CPPI5_PD_PKTINFO1_FLOWID_SHIFT)
#define CSL_UDMAP_CPPI5_PD_SRCDSTTAG_SRCTAG_SHIFT           ((uint32) 16U)
#define CSL_UDMAP_CPPI5_PD_SRCDSTTAG_SRCTAG_MASK            (((uint32) 0xFFFFU) << CSL_UDMAP_CPPI5_PD_SRCDSTTAG_SRCTAG_SHIFT)
#define CSL_UDMAP_CPPI5_PD_SRCDSTTAG_DSTTAG_SHIFT           ((uint32) 0U)
#define CSL_UDMAP_CPPI5_PD_SRCDSTTAG_DSTTAG_MASK            (((uint32) 0xFFFFU) << CSL_UDMAP_CPPI5_PD_SRCDSTTAG_DSTTAG_SHIFT)
#define CSL_UDMAP_CPPI5_PD_BUFINFO1_LEN_SHIFT               ((uint32) 0U)
#define CSL_UDMAP_CPPI5_PD_BUFINFO1_LEN_MASK                (((uint32) 0x3FFFFFU) << CSL_UDMAP_CPPI5_PD_BUFINFO1_LEN_SHIFT)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_SHIFT            ((uint32) 0U)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_MASK             (((uint32) 0x3FFFFFU) << CSL_UDMAP_CPPI5_PD_DESCINFO_PKTLEN_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_PKTTYPE_SHIFT           ((uint32) 27U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_PKTTYPE_MASK            (((uint32) 0x1FU) << CSL_UDMAP_CPPI5_PD_PKTINFO2_PKTTYPE_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_SHIFT         ((uint32) 18U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_MASK          (((uint32) 0x1U) << CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_SHIFT          ((uint32) 17U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_MASK           (((uint32) 0x1U) << CSL_UDMAP_CPPI5_PD_PKTINFO2_EARLYRET_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_SHIFT     ((uint32) 16U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_MASK      (((uint32) 0x1U) << CSL_UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY_SHIFT)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_RETQ_SHIFT              ((uint32) 0U)
#define CSL_UDMAP_CPPI5_PD_PKTINFO2_RETQ_MASK               (((uint32) 0xFFFFU) << CSL_UDMAP_CPPI5_PD_PKTINFO2_RETQ_SHIFT)
#define CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST          ((uint32) 1U)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_SEQID_SHIFT              (0U)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_SEQID_MASK               (((uint32) 0xFFFFU) << CSL_UDMA_CPPI_RXCTRL_WORD1_SEQID_SHIFT)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_MSGTYPE_SHIFT            (16U)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_MSGTYPE_MASK             (((uint32) 0xFU)    << CSL_UDMA_CPPI_RXCTRL_WORD1_MSGTYPE_SHIFT)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_DOMAIN_SHIFT             (20U)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_DOMAIN_MASK              (((uint32) 0xFFU)   << CSL_UDMA_CPPI_RXCTRL_WORD1_DOMAIN_SHIFT)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_TSEN_SHIFT               (31U)
#define CSL_UDMA_CPPI_RXCTRL_WORD1_TSEN_MASK                (((uint32) 0x1U)    << CSL_UDMA_CPPI_RXCTRL_WORD1_TSEN_SHIFT)

/* -------------------- CPPI RX Control Word 2 definitions --------------------- */

#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_BYTECNT_SHIFT     (0U)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_BYTECNT_MASK      (((uint32) 0x3FFFU) << CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_BYTECNT_SHIFT)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_INV_SHIFT         (15U)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_INV_MASK          (((uint32) 0x1U) << CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_INV_SHIFT)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_STARTBYTE_SHIFT   (16U)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_STARTBYTE_MASK    (((uint32) 0xFFU) << CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_STARTBYTE_SHIFT)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_RESULT_SHIFT      (24U)
#define CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_RESULT_MASK       (((uint32) 0xFFU) << CSL_UDMA_CPPI_RXCTRL_WORD2_CHKSUM_RESULT_SHIFT)

/* -------------------- CPPI TX Status Word 2 definitions --------------------- */

/*! \brief CPPI TX Status Word 2 - Checksum Error bit shift. */
#define CSL_UDMA_CPPI_TXSTATUS_WORD2_CHKSUM_ERR_SHIFT       (16U)

/*! \brief CPPI TX Status Word 2 - Checksum Error bit mask. */
#define CSL_UDMA_CPPI_TXSTATUS_WORD2_CHKSUM_ERR_MASK        (((uint32) 0x1U) << CSL_UDMA_CPPI_TXSTATUS_WORD2_CHKSUM_ERR_SHIFT)

/*! \brief CPPI TX Status Word 2 - IPv6 Valid bit shift. */
#define CSL_UDMA_CPPI_TXSTATUS_WORD2_IPV6_VALID_SHIFT       (19U)

/*! \brief CPPI TX Status Word 2 - IPv6 Valid bit mask. */
#define CSL_UDMA_CPPI_TXSTATUS_WORD2_IPV6_VALID_MASK        (((uint32) 0x1U) << CSL_UDMA_CPPI_TXSTATUS_WORD2_IPV6_VALID_SHIFT)

/*! \brief CPPI TX Status Word 2 - IPv4 Valid bit shift. */
#define CSL_UDMA_CPPI_TXSTATUS_WORD2_IPV4_VALID_SHIFT       (20U)

/*! \brief CPPI TX Status Word 2 - IPv4 Valid bit mask. */
#define CSL_UDMA_CPPI_TXSTATUS_WORD2_IPV4_VALID_MASK        (((uint32) 0x1U) << CSL_UDMA_CPPI_TXSTATUS_WORD2_IPV4_VALID_SHIFT)


/* \brief Set timestamp enable */
#define UDMA_CPPIPSI_SET_TSEN(tsInfo, val)                  CSL_FINS(tsInfo, UDMA_CPPI_RXCTRL_WORD1_TSEN, val)

/* \brief Set domain */
#define UDMA_CPPIPSI_SET_DOMAIN(tsInfo, val)                CSL_FINS(tsInfo, UDMA_CPPI_RXCTRL_WORD1_DOMAIN, val)

/* \brief Set msg type  */
#define UDMA_CPPIPSI_SET_MSGTYPE(tsInfo, val)               CSL_FINS(tsInfo, UDMA_CPPI_RXCTRL_WORD1_MSGTYPE, val)

/* \brief Set msg sequence Id  */
#define UDMA_CPPIPSI_SET_SEQID(tsInfo, val)                 CSL_FINS(tsInfo, UDMA_CPPI_RXCTRL_WORD1_SEQID, val)

/* \brief Set Checksum Byte Count into CPPI RX Control Word 2. */
#define UDMA_CPPIPSI_SET_CHKSUM_BYTECNT(chkSumInfo, val)    CSL_FINS(chkSumInfo, UDMA_CPPI_RXCTRL_WORD2_CHKSUM_BYTECNT, val)

/* \brief Set Checksum Start Byte into CPPI RX Control Word 2. */
#define UDMA_CPPIPSI_SET_CHKSUM_STARTBYTE(chkSumInfo, val)  CSL_FINS(chkSumInfo, UDMA_CPPI_RXCTRL_WORD2_CHKSUM_STARTBYTE, val)

/* \brief Set Checksum Result into CPPI RX Control Word 2. */
#define UDMA_CPPIPSI_SET_CHKSUM_RES(chkSumInfo, val)        CSL_FINS(chkSumInfo, UDMA_CPPI_RXCTRL_WORD2_CHKSUM_RESULT, val)


/*! \brief Get IPv4 flag from CPPI TX Status Word 2. */
#define UDMA_CPPIPSI_GET_IPV4_FLAG(chkSumInfo)              CSL_FEXT(chkSumInfo, UDMA_CPPI_TXSTATUS_WORD2_IPV4_VALID)

/*! \brief Get IPv6 flag from CPPI TX Status Word 2. */
#define UDMA_CPPIPSI_GET_IPV6_FLAG(chkSumInfo)              CSL_FEXT(chkSumInfo, UDMA_CPPI_TXSTATUS_WORD2_IPV6_VALID)

/*! \brief Get Checksum Error flag from CPPI TX Status Word 2. */
#define UDMA_CPPIPSI_GET_CHKSUM_ERR_FLAG(chkSumInfo)        CSL_FEXT(chkSumInfo, UDMA_CPPI_TXSTATUS_WORD2_CHKSUM_ERR)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/**
 *  \brief Cppi receive control type
 *
 *  Type of Cppi receive control
 */
struct sEth_CppiRxControlType
{
    uint32 rsvd1;
    /**< reserved 1 */
    uint32 tsInfo;
    /**< timestamp information */
    uint32 chkSumInfo;
    /**< checksum information */
    uint32 rsvd2;
    /**< reserved 2 */
};

/**
 *  \brief Cppi5 protocol specific information type
 *
 *  Type of Cppi5 protocol specific information
 */
struct sEth_Cppi5PsInfoType
{
    uint32 tsLow;
    /**< Lower word of 64-bit timestamp */
    uint32 tsHigh;
    /**< Higher word of 64-bit timestamp */
    uint32 chkSumInfo;
    /**< pV4/IpV6 protocol information info status word */
    uint32 rsvd;
    /**< Reserved */
};

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 *  \brief Initialize for transmit descriptor
 *
 *  Initialize for transmit descriptor
 *
 *  \param llDescPtr UDMA descriptor pointer
 *
 *  \return none
 */
static inline void Eth_InitLLDesc(Eth_DescType *llDescPtr);

/**
 *  \brief Set completion queue for transmit descriptor
 *
 *  Set completion queue for transmit descriptor
 *
 *  \param llDescPtr UDMA descriptor pointer
 *  \param CqRingNum complete queue number
 *
 *  \return none
 */
static inline void Eth_SetLLDescCqRing(Eth_DescType *llDescPtr, uint32 CqRingNum);

/**
 *  \brief Set buffer address for transmit descriptor
 *
 *  Set buffer address for transmit descriptor
 *
 *  \param llDescPtr UDMA descriptor pointer
 *  \param BufferPtr Buffer address
 *  \param BufferLen Buffer length
 *
 *  \return none
 */
static inline void Eth_SetLLDescBufferAddressAndLength(Eth_DescType *llDescPtr, uint8 *BufferPtr, uint32 BufferLen);

/**
 *  \brief Set timestamp for transmit descriptor
 *
 *  Set buffer length for transmit descriptor
 *
 *  \param llDescPtr UDMA descriptor pointer
 *  \param DomainId domain Id
 *  \param MsgType message type
 *  \param SeqId sequence Id
 *  \param Enable enable timestamp for this descriptor
 *
 *  \return none
 */
static inline void Eth_SetLLDescTimeStamp(Eth_DescType *llDescPtr, uint32 DomainId, uint32 MsgType, uint32 SeqId, boolean enable);

/**
 *  \brief Get receive ingress timestam of a descriptor
 *
 *  Get receive ingress timestam of a descriptor
 *
 *  \param llDescPtr UDMA descriptor pointer
 *
 *  \return timestamp of ingress descriptor
 */
static inline uint64 Eth_GetLLIngressTimeStamp(Eth_DescType *llDescPtr);

/**
 *  \brief Set destination port for a transmit descriptor
 *
 *  Set destination port for a transmit descriptor
 *
 *  \param llDescPtr UDMA descriptor pointer
 *  \param destPort destination port
 *
 *  \return none
 */
static inline void Eth_SetLLDescDstPort(Eth_DescType *llDescPtr, uint8 destPort);

/**
 *  \brief Check checksum inform of Rx packet(IPV4/IPV6)
 *
 *  Check checksum inform of Rx packet
 *
 *  \param llDescPtr UDMA descriptor pointer
 *
 *  \return TRUE if checksum is valid or packet is not ip packet else FALSE
 */
static inline boolean Eth_IsCheckCheckSumValid(Eth_DescType *llDescPtr);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
static inline void Eth_InitLLDesc(Eth_DescType *llDescPtr)
{
    llDescPtr->desc.descInfo    = 0u;
    llDescPtr->desc.pktInfo1    = 0u;
    llDescPtr->desc.pktInfo2    = 0u;
    llDescPtr->desc.srcDstTag   = 0u;
    llDescPtr->desc.nextDescPtr = 0u;
    llDescPtr->desc.bufPtr      = 0u;
    llDescPtr->desc.bufInfo1    = 0u;
    llDescPtr->desc.orgBufLen   = 0u;
    llDescPtr->desc.orgBufPtr   = 0u;
    llDescPtr->psInfo[0u]  = 0u;
    llDescPtr->psInfo[1u]  = 0u;
    llDescPtr->psInfo[2u]  = 0u;
    llDescPtr->psInfo[3u]  = 0u;

    CSL_FINS(llDescPtr->desc.descInfo, UDMAP_CPPI5_PD_DESCINFO_DTYPE, CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_HOST);
    CSL_FINS(llDescPtr->desc.descInfo, UDMAP_CPPI5_PD_DESCINFO_EINFO, ((uint32)1u));
    CSL_FINS(llDescPtr->desc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PSWCNT, ETH_CPPI_PROTOCOL_SPECIFIC_LENGTH);
}

static inline void Eth_SetLLDescCqRing(Eth_DescType *llDescPtr, uint32 CqRingNum)
{
    uint32 v;

    v = llDescPtr->desc.pktInfo2;
    v &= CSL_UDMAP_CPPI5_PD_PKTINFO2_PKTTYPE_MASK;
    v |= CSL_FMK(UDMAP_CPPI5_PD_PKTINFO2_RETPOLICY, ((uint32)0u))     |
         CSL_FMK(UDMAP_CPPI5_PD_PKTINFO2_EARLYRET, ((uint32)0u))      |
         CSL_FMK(UDMAP_CPPI5_PD_PKTINFO2_RETPUSHPOLICY, ((uint32)0u)) |
         CSL_FMK(UDMAP_CPPI5_PD_PKTINFO2_RETQ, CqRingNum);

    llDescPtr->desc.pktInfo2 = v;
}

static inline void Eth_SetLLDescBufferAddressAndLength(Eth_DescType *llDescPtr, uint8 *BufferPtr, uint32 BufferLen)
{
    llDescPtr->desc.bufPtr      = (uint64)BufferPtr;
    llDescPtr->desc.bufInfo1    = BufferLen;
    llDescPtr->desc.orgBufLen   = BufferLen;
    llDescPtr->desc.orgBufPtr   = (uint64)BufferPtr;
    CSL_FINS(llDescPtr->desc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN, BufferLen);
}

static inline void Eth_SetLLDescTimeStamp(Eth_DescType *llDescPtr, uint32 DomainId, uint32 MsgType, uint32 SeqId, boolean enable)
{
    Eth_CppiRxControlType *ctrl =  (Eth_CppiRxControlType*)(llDescPtr->psInfo);
    uint32 *tsInfo = (uint32 *)&ctrl->tsInfo;
    UDMA_CPPIPSI_SET_TSEN(*tsInfo, ((uint32)enable));
    UDMA_CPPIPSI_SET_DOMAIN(*tsInfo, DomainId);
    UDMA_CPPIPSI_SET_MSGTYPE(*tsInfo, ((uint32)MsgType));
    UDMA_CPPIPSI_SET_SEQID(*tsInfo, ((uint32)SeqId));
}

static inline void Eth_SetLLDescCheckSum(Eth_DescType *llDescPtr, uint32 IpPktPayLen, uint8 StartByte, uint8 ResultByte)
{
    Eth_CppiRxControlType *ctrl =  (Eth_CppiRxControlType*)(llDescPtr->psInfo);
    uint32 chkSumInfo = 0U;
    UDMA_CPPIPSI_SET_CHKSUM_BYTECNT(chkSumInfo, IpPktPayLen);
    UDMA_CPPIPSI_SET_CHKSUM_STARTBYTE(chkSumInfo, ((uint32)StartByte));
    UDMA_CPPIPSI_SET_CHKSUM_RES(chkSumInfo, ((uint32)ResultByte));
    ctrl->chkSumInfo = chkSumInfo;
}

static inline uint32 Eth_GetLLDescBufferLen(Eth_DescType *llDescPtr)
{
    return CSL_FEXT(llDescPtr->desc.descInfo, UDMAP_CPPI5_PD_DESCINFO_PKTLEN);
}

static inline uint64 Eth_GetLLIngressTimeStamp(Eth_DescType *llDescPtr)
{
    Eth_Cppi5PsInfoType *psInfo = (Eth_Cppi5PsInfoType*)(llDescPtr->psInfo);
    return (uint64)((uint64)psInfo->tsHigh << 32u) | ((uint64)psInfo->tsLow);
}

static inline boolean Eth_IsCheckCheckSumValid(Eth_DescType *llDescPtr)
{
    boolean ret = TRUE;
    Eth_Cppi5PsInfoType *psInfo = (Eth_Cppi5PsInfoType*)(llDescPtr->psInfo);
    uint32 csumInfo = psInfo->chkSumInfo;

    if((UDMA_CPPIPSI_GET_IPV4_FLAG(csumInfo)==1U) ||
       (UDMA_CPPIPSI_GET_IPV6_FLAG(csumInfo)==1U))
    {
        if(UDMA_CPPIPSI_GET_CHKSUM_ERR_FLAG(csumInfo) != 0u)
        {
            ret = FALSE;
        }
    }

    return ret;
}

static inline void Eth_SetLLDescDstPort(Eth_DescType *llDescPtr, uint8 destPort)
{
    uint32 dstTag = (uint32)destPort;
    CSL_FINS(llDescPtr->desc.srcDstTag,UDMAP_CPPI5_PD_SRCDSTTAG_DSTTAG, dstTag);
}

#ifdef __cplusplus
}
#endif

#endif /* ETH_LL_H */
