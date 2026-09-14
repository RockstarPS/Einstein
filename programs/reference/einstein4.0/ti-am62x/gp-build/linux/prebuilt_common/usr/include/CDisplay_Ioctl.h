#ifndef CDISPLAY_IOCTL_H_
#define CDISPLAY_IOCTL_H_

#ifdef __KERNEL__
    #include <linux/types.h>  
#else
    #include <stdint.h> 
#endif

typedef uint8_t display_EState_t;
typedef uint8_t display_EPower_t;

#define EOK 0

#define DISPLAY_ESTATE_OFF              ((display_EState_t) 0)
#define DISPLAY_ESTATE_ON               ((display_EState_t) 1)
#define DISPLAY_ESTATE_ERROR            ((display_EState_t) 2)
#define DISPLAY_ESTATE_DISCONNECTED     ((display_EState_t) 3)
#define DISPLAY_EPOWER_OFF              ((display_EPower_t) 0)
#define DISPLAY_EPOWER_ON               ((display_EPower_t) 1)

typedef struct {
  display_EPower_t power_U8;
} display_power_buffer_type_ts;
typedef struct {
  display_EState_t state;
} display_state_buffer_type_ts;

#define IOCTL_TYPE_DISPLAY 'D' 
#define POWER_ID_VALUE_READ _IOR(IOCTL_TYPE_DISPLAY, 1, int32_t *)
#define POWER_ID_VALUE_WRITE _IOW(IOCTL_TYPE_DISPLAY, 2, int32_t *)
#define STATE_ID_VALUE_READ _IOR(IOCTL_TYPE_DISPLAY, 3, int32_t *)

#endif /* CDISPLAY_IOCTL_H_ */ 
