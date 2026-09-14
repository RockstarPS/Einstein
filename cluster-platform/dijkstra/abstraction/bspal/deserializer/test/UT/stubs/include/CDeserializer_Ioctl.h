
/*============================================================================
 **
 **  \file CSigUnit_Cfg.h
 **
 **  \brief Interface to interact with the Signature Unit of iMX8
 **
 **  This file provides Deserializer BSPAL API
 **  
 **
 **  Component Name: Serializer
 **  Archive:
 **  Date: December 2024
 **  Author: ssomasu1
 **
 ** Copyright 2025 Visteon Corporation.
 **
 ** These materials and the intellectual property rights associated therewith
 ** (“Materials”) are proprietary to Visteon Corporation. Any and all rights in
 ** the Materials are reserved by Visteon Corporation. Nothing contained in
 ** these Materials shall grant or be deemed to grant to you or anyone else, by
 ** implication, estoppel or otherwise, any rights in these Materials.
 **==========================================================================*/

/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef DESERIALIZER_IOCTL_H
#define DESERIALIZER_IOCTL_H

/*============================================================================
** #define Constants for Serializer IOCTL calls
**==========================================================================*/
#define IOCTL_DESERIALIZER_INIT               0
#define IOCTL_DESERIALIZER_DEINIT             1
#define IOCTL_DESERIALIZER_STREAMING_START    2
#define IOCTL_DESERIALIZER_STREAMING_STOP     3
#define IOCTL_DESERIALIZER_LINK_STATUS        4
#define IOCTL_DESERIALIZER_ERROR_STATUS       5
#define IOCTL_DESERIALIZER_TEST_PATTERN       6



/** @} */ /* end of serializer */
#endif /* CDESERIALIZER_IOCTL_H */
