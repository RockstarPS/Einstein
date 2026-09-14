#if !defined( FLS_TYPESLIB_H )
#define FLS_TYPESLIB_H

#include "MemIf_Types.h"

typedef P2FUNC(void, TYPEDEF, Fls_FeeJobEndNotificationFctPtr)(void);

typedef P2FUNC(void, TYPEDEF, Fls_FeeJobErrorNotificationFctPtr)(void);

typedef P2FUNC(void, TYPEDEF, Fls_FeeDedErrorNotificationFctPtr)(void);

typedef P2FUNC(void, TYPEDEF, Fls_FeeSedErrorNotificationFctPtr)(void);

typedef P2FUNC(Std_ReturnType, TYPEDEF, Fls_SystemcallCalloutFctPtr)(uint32 *Fls_IpcContext);

typedef uint32 Fls_AddressType;

typedef Fls_AddressType Fls_LengthType;

typedef struct fls_configType
{
    Fls_LengthType                    TotalSize;            /* flash total size                                            */
    sint32                            CallCycle;            /* Cycle time of calls of the main function (msec)             */
    Fls_FeeJobEndNotificationFctPtr   JobEndNotifFctPtr;    /* function ptr to Fee_JobEndNotification                      */
    Fls_FeeJobErrorNotificationFctPtr JobErrorNotifFctPtr;  /* function ptr to Fee_JobErrorNotification                    */
    Fls_FeeDedErrorNotificationFctPtr DedErrorNotifFctPtr;  /* function ptr to Fee_DedErrorNotification                    */
    Fls_FeeSedErrorNotificationFctPtr SedErrorNotifFctPtr;  /* function ptr to Fee_SedErrorNotification                    */
    Fls_LengthType                    MaxReadNormalMode;    /* max number of bytes to read/compare/blank check             */
    Fls_LengthType                    MaxReadFastMode;      /* max number of bytes to read/compare/blank check (fast mode) */
    Fls_LengthType                    MaxWriteNormalMode;   /* max number of bytes to write                                */
    Fls_LengthType                    MaxWriteFastMode;     /* max number of bytes to write (fast mode)                    */
    uint32                            PageSize;             /* number of bytes to be written at once                       */
    uint32                            NumberOfDelayLoop;    /* number of delay (wait) loop for writing a flash block       */
    uint16                            NumberOfSectors;      /* number of flash sectors                                     */
    uint8                             VerificationFlag;     /* flag for specifying which verification to do                */
    MemIf_ModeType                    DefaultMode;          /* default FLS device mode after initialization                */
} Fls_ConfigType;

#endif /* if !defined( FLS_TYPESLIB_H ) */
