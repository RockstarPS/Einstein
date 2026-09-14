#include "Rte_Type.h"
#include "Rte_PtrView.h"
#include "system.h"
#include "hmi_gauges_cfg.h"


static TURN_INDICATOR_STATE l_turn_indicator_state[TURN_INDICATOR_MAX];

void hmi_app_init()
{
    SINT32 l_index;

    for (l_index = 0; l_index < TURN_INDICATOR_MAX; l_index++)
    {
        l_turn_indicator_state[l_index] = TURN_INDICATOR_STATE_NOT_ACTIVE;
    }
}

UINT32 get_speed_cfg()
{
    UINT16 l_rte_speed_U16;

    Rte_Read_tiSR_TISpdMdl_Out_SpdF_Speed(&l_rte_speed_U16);

    return (UINT32)l_rte_speed_U16;
}

UINT32 get_rpm_cfg()
{
    UINT16 l_rte_rpm_U16;

    Rte_Read_tiSR_TIEngMdl_Out_TachoF_Tacho(&l_rte_rpm_U16);

    return (UINT32)l_rte_rpm_U16;
}

TURN_INDICATOR_STATE get_turn_indicator_state_cfg(TURN_INDICATOR_TYPE p_type)
{
    return l_turn_indicator_state[p_type];
}

void set_turn_indicator_state_cfg(TURN_INDICATOR_TYPE p_type, TURN_INDICATOR_STATE p_state)
{
    l_turn_indicator_state[p_type] = p_state;
}


