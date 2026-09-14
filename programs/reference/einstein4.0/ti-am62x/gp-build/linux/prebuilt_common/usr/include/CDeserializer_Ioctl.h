/**********************************************************************************************************************
 *  HEADER FILE GUARD
 *********************************************************************************************************************/
#ifndef CDESERIALIZER_IOCTL_H
#define CDESERIALIZER_IOCTL_H
/*============================================================================
** #define Constants for DeSerializer IOCTL calls
**==========================================================================*/
#define IOCTL_DESERIALIZER_INIT                     _IO('D', 1)
#define IOCTL_DESERIALIZER_DEINIT                   _IO('D', 2)
#define IOCTL_DESERIALIZER_STREAMING_START          _IO('D', 3)
#define IOCTL_DESERIALIZER_STREAMING_STOP           _IO('D', 4)
#define IOCTL_DESERIALIZER_LINK_STATUS              _IOR('D', 5, int)
#define IOCTL_DESERIALIZER_ERROR_STATUS             _IOR('D', 6, int)
#define IOCTL_DESERIALIZER_TEST_PATTERN             _IO('D', 8)
/** @} */ /* end of deserializer */
#endif /* CDESERIALIZER_IOCTL_H */
