#ifndef HMI_GAUGES_CFG_H
#define HMI_GAUGES_CFG_H

typedef enum {
    TURN_INDICATOR_LEFT,
    TURN_INDICATOR_RIGHT,
    TURN_INDICATOR_MAX,
} TURN_INDICATOR_TYPE;

typedef enum {
    TURN_INDICATOR_STATE_ON,
    TURN_INDICATOR_STATE_OFF,
    TURN_INDICATOR_STATE_NOT_ACTIVE
} TURN_INDICATOR_STATE;

extern UINT32 get_rpm_cfg(void);
extern UINT32 get_speed_cfg(void);

extern TURN_INDICATOR_STATE get_turn_indicator_state_cfg(TURN_INDICATOR_TYPE p_type);
extern void set_turn_indicator_state_cfg(TURN_INDICATOR_TYPE p_type, TURN_INDICATOR_STATE p_state);

extern void hmi_app_init(void);

#endif
