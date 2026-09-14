//
// VISTEON CORPORATION CONFIDENTIAL
// ________________________________
//
// [2018] Visteon Corporation
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
#ifndef UCLILSTREAM_CHANNEL_TYPES_H
#define UCLILSTREAM_CHANNEL_TYPES_H

#include "Ucl_Types.h"

/// @file ucl_channel_types.h UCL Channel Types
/// @defgroup UCL_O_FLAGS UCL Open flags
/// @brief UCL Open flags to set the channel open mode
/// @{

#define UCL_O_RDONLY  (0x0001u)       ///< open for reading only

#define UCL_O_WRONLY  (0x0002u)       ///< open for writing only

#define UCL_O_RDWR   (0x0004u)       ///< open for reading and writing

#define UCL_O_SHARED  (0x0008u)       ///< open with shared mode


/// @}

/// @defgroup UCL_IOCTL UCL IOCTL Requests
/// @brief UCL IOCTL request codes to configure channel specific configuration
/// @{
#define UCL_IOCTL_SET_CHANNEL_PARAM         (100u)          ///< Set the channel parameters
#define UCL_IOCTL_GET_CHANNEL_PARAM         (101u)          ///< Get the channel parameters
#define UCL_IOCTL_GET_LINK_STATUS           (102u)          ///< Get the physical link status
#define UCL_IOCTL_GET_STATS                 (103u)          ///< Get the physical link statistics
#define UCL_IOCTL_FLUSH_TX_QUEUE            (104u)          ///< Flush the transmit queue
#define UCL_IOCTL_FLUSH_RX_QUEUE            (105u)          ///< Flush the receive queue
#define UCL_IOCTL_SET_NOTIFY_INFO           (106u)          ///< Set the notification information
#define UCL_IOCTL_GET_NOTIFY_INFO           (107u)          ///< Get the notification information
/// @}


/// @defgroup UCL_NOTIFY UCL Notification Codes
/// @brief UCL Notifications to the UCL clients
/// @{
#define UCL_NOTIFY_LINK_STATUS_CHANGE       (0u)            ///< Physical link status changed
#define UCL_NOTIFY_DATA_RECEIVED            (1u)            ///< Data received on the channel
#define UCL_NOTIFY_TRANSMIT_CONFIRM         (2u)            ///< Transmit confirmation status received
#define UCL_NOTIFY_FATAL_ERROR              (3u)            ///< Fatal error
#define UCL_NOTIFY_COUNT                    (4u)            ///< Maximum notification count
/// @}

#define UCL_PRIORITY_LEVEL_CRI              (0u)            ///< Priority level Critical
#define UCL_PRIORITY_LEVEL_HIG              (1u)            ///< Priority level High
#define UCL_PRIORITY_LEVEL_MID              (2u)            ///< Priority level Medium
#define UCL_PRIORITY_LEVEL_LOW              (3u)            ///< Priority level Low

#define UCL_SECURITY_LEVEL_UNSECURE         (0u)            ///< Security level is unsecure
#define UCL_SECURITY_LEVEL_AUTHENTICATED    (1u)            ///< Security level is authenticated
#define UCL_SECURITY_LEVEL_ENCRYPTED        (2u)            ///< Security level is encrypted
#define UCL_SECURITY_LEVEL_RESERVED         (3u)            ///< Reserved security level 
/// @}
/// @defgroup UCL_TYPES UCL Derived data types
/// @brief UCL type definitions to be used by the UCL clients
/// @{

typedef sint32 ucl_fd_t;               ///< UCL file descriptor identifer type
typedef uint8 ucl_ch_t;               ///< UCL channel identifer type

/// @brief Structure used for UCL_IOCTL_SET_NOTIFY_INFO
typedef struct 
{
    struct 
    {
        uint8  enabled;               ///< Enable notification
        uint8  reserved;              ///< Reserved for future use
        uint16 comp_id;               ///< Component id to send the event
        uint32 event_mask;            ///< Event mask
    } event_info [UCL_NOTIFY_COUNT];    ///< Event info array
} ucl_ioctl_notify_info_t;

/// @brief Structure used for UCL_IOCTL_SET_CHANNEL_PARAM
typedef struct 
{
    uint8 priority_level;             ///< Channel priority level
    uint8 security_level;             ///< Channel security level
    uint16 time_to_live_ms;           ///< Channel time-to-live in ms
} ucl_ioctl_channel_param_t;

/// @brief Structure used for UCL_IOCTL_GET_STATS
typedef struct 
{
    struct
    {
        uint32 tx_bytes;              ///< Number of bytes transmitted
        uint32 rx_bytes;              ///< Number of bytes received
        uint32 tx_msgs;               ///< Number of messages transmitted
        uint32 rx_msgs;               ///< Number of messages received
        uint32 tx_kbps;               ///< Average transmit speed in kbps
        uint32 rx_kbps;               ///< Average receive speed in kbps
        uint32 avg_ack_latency;       ///< Average latency for acknowledgement
    } dl;                               ///< Data layer statistics

    struct
    {
        uint32 num_open_channels;     ///< Number of open channels
        uint32 num_open_fds;          ///< Number of open file descriptors
    } il;                               ///< Interface layer statistics
} ucl_ioctl_channel_stats_t;
/// @}

#endif //UCL_CHANNEL_TYPES_H
