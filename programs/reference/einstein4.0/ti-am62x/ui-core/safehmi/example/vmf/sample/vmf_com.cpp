// =============================================================================
// 
//                      CONFIDENTIAL VISTEON CORPORATION
// 
//  This is an unpublished work of authorship, which contains trade secrets,
//  created in 2012. Visteon Corporation owns all rights to this work and
//  intends to maintain it in confidence to preserve its trade secret status.
//  Visteon Corporation reserves the right, under the copyright laws of the
//  United States or those of any other country that may have jurisdiction,
//  to protect this work as an unpublished work, in the event of an
//  inadvertent or deliberate unauthorized publication. Visteon Corporation
//  also reserves its rights under all copyright laws to protect this work as
//  a published work, when appropriate. Those having access to this work may
//  not copy it, use it, modify it or disclose the information contained in
//  it without the written authorization of Visteon Corporation.
// 
// ============================================================================
// 
//  Name:           vmf_com.c
// 
//  Description:	handles the VMF rx and tx messages
// 
//  Organization:   GUI Software Section, Visteon
// 
// ============================================================================
// 
// ============================================================================
#if (USE_VMF != 0)

// =============================================================================
//  I N C L U D E   F I L E S
// ============================================================================
#include <pthread.h>
#include "vmf_com.h"

// =============================================================================
//  I N T E R N A L   M A C R O   A N D   T Y P E   D E F I N I T I O N S
// ============================================================================
#define SHMI_VMF_MSG_QUEUE_SIZE (100)
#define SHMI_VMF_FAR_DATA_LEN   (4062)

// Message groups that EHMI shall listen to
#define SHMI_MSG_GROUP_DKINFO (0x01)
#define SHMI_MSG_GROUP_EHCTRL (0x02)
#define SHMI_MSG_GROUP_EHHMON (0x10)
#define SHMI_NUM_RX_MSG_GROUP  (3)

// VMF events for message group SHMI_MSG_GROUP_DKINFO
#define SHMI_DKINFO_EV_SPEED  (0x01)
#define SHMI_DKINFO_EV_TACHO  (0x02)
#define SHMI_DKINFO_EV_TTSET1 (0x03)
#define SHMI_DKINFO_EV_FUEL   (0x04)
#define SHMI_DKINFO_EV_ODO    (0x05)
#define SHMI_DKINFO_EV_PRNDL  (0x06)
#define SHMI_DKINFO_EV_ECT    (0x12)
#define SHMI_DKINFO_EV_TRIP   (0x14)

// VMF events for message group SHMI_MSG_GROUP_EHCTRL
#define SHMI_CTRL_EV_SCREEN  (0x00)
#define SHMI_CTRL_EV_CHKSUM  (0x01)

// VMF events for message group SHMI_MSG_GROUP_EHHMON
#define SHMI_HMONITOR_EV     (0x01)

namespace UX_SHMI_PLAYER
{
// =============================================================================
//  I N T E R N A L   F U N C T I O N   P R O T O T Y P E S
// =============================================================================

// =============================================================================
//  M E M O R Y   A L L O C A T I O N
// =============================================================================
static vmf_client_id_t  vmf_connection_id = -1;
static uint32_t l_server_alive;
static uint32_t l_show_status;

static uint32_t l_vspeed;
static uint32_t l_vrpm;
static uint32_t l_odometer;
static uint32_t l_odometer_units;
static uint32_t l_prndl_status;
static uint32_t l_tt_status;
static uint32_t l_fuel_percentage;
static int16_t l_ect;
static int16_t l_oat;
static uint32_t l_dist2destination;
static uint32_t l_dte;
static char const l_vmfrcname[] = "EHmiRx";
static pthread_mutex_t l_vmf_mutex;

// =============================================================================
//  E N T R Y   P O I N T S  /  D A T A   A C C E S S   S E R V I C E S
// =============================================================================

// =============================================================================
//  Function Name:    vmf_rx_open
//  Visibility:       global
//  Description:      VMF rx initialization
//  Invocation:       QNX
//  Inputs/Outputs:   Returns -1 on error, >=0 on success
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
int vmf_rx_open(void)
{

	l_odometer = SHMI_IF_DATA_INVALID;
	l_odometer_units = SHMI_ODO_UNIT_KM;
	l_prndl_status = SHMI_IF_DATA_INVALID;
	l_tt_status = SHMI_IF_DATA_INVALID;
	l_vspeed = SHMI_IF_DATA_INVALID;
	l_vrpm = SHMI_IF_DATA_INVALID;
	l_fuel_percentage = SHMI_IF_DATA_INVALID;
	l_ect = (int16_t)SHMI_IF_DATA_INVALID;
	l_oat = (int16_t)SHMI_IF_DATA_INVALID;
	l_dist2destination = SHMI_IF_DATA_INVALID;
	l_dte = SHMI_IF_DATA_INVALID;

	if(pthread_mutex_lock(&l_vmf_mutex) == 0)
	{
	   l_server_alive = 0;
	   (void)pthread_mutex_unlock(&l_vmf_mutex);
	}
    l_show_status  = 1;
    unsigned8 fl_groups[SHMI_NUM_RX_MSG_GROUP] =
    {
            SHMI_MSG_GROUP_DKINFO,
            SHMI_MSG_GROUP_EHCTRL,
            SHMI_MSG_GROUP_EHHMON
    };
    if(pthread_mutex_init(&l_vmf_mutex, NULL) == EOK)
    {
       int fl_retry_count = 15;
       while ((fl_retry_count > 0) && (vmf_connection_id < 0))
       {
           vmf_connection_id = nw_vmf_connect(l_vmfrcname, NULL, 0, SHMI_VMF_MSG_QUEUE_SIZE, SHMI_VMF_FAR_DATA_LEN);
           if (vmf_connection_id < 0)
           {
               delay(500);
               fl_retry_count--;
           }
       }
       /* register message group */
       if (nw_vmf_register_msg_group (vmf_connection_id, SHMI_NUM_RX_MSG_GROUP, &fl_groups[0]) < 0)
       {
           vmf_rx_close();
           SHMI_ERROR("nw_vmf_register_msg_group error\n");
       }
    }
    else
    {
       SHMI_ERROR("pthread_mutex_init error\n");
    }
    return vmf_connection_id;
}

// =============================================================================
//  Function Name:    vmf_rx_close
//  Visibility:       global
//  Description:      Closes the VMF Rx operation and terminates the RX thread
//  Invocation:       QNX
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
void vmf_rx_close(void)
{
    if(vmf_connection_id >= 0)
    {
        (void)nw_vmf_disconnect(vmf_connection_id);
        vmf_connection_id = -1;
    }
    (void)pthread_mutex_destroy(&l_vmf_mutex);
}

// =============================================================================
//  Function Name:    vmf_receiver
//  Visibility:       local
//  Description:      VMF rx thread
//  Invocation:       QNX
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
static int vmf_process_message(vmf_msg_base_t const * p_msg_base, unsigned16 p_length, unsigned8 const * p_data)
{
    int fl_ret = -1;
    uint32_t fl_tt_status;
    if(p_msg_base->id.group == SHMI_MSG_GROUP_DKINFO)
    {
        p_data = &p_data[2]; //Discard first two bytes
        switch(p_msg_base->id.event)
        {
            case SHMI_DKINFO_EV_SPEED:
            {
                if(p_length >= 2)
                {
                    l_vspeed  = p_data[0];
                    l_vspeed |= (p_data[1] << 8);
                    fl_ret = 0;
                    SHMI_INFO("SHMI_DKINFO_EV_SPEED %d\n",l_vspeed);
                }
            }
            break;
            case SHMI_DKINFO_EV_TACHO:
            {
                if(p_length >= 2)
                {
                    l_vrpm  = p_data[0];
                    l_vrpm |= (p_data[1] << 8);
                    fl_ret = 0;
                    SHMI_INFO("SHMI_DKINFO_EV_TACHO %d\n",l_vrpm);
                }
            }
            break;
            case SHMI_DKINFO_EV_TTSET1:
            {
                fl_tt_status = 0;
                if (p_length >= 1)
                {
                    SHMI_INFO("\nSHMI_DKINFO_EV_TTSET1 p_data[0] %d\n", p_data[0]);
                    fl_tt_status = p_data[0];
                    if (p_length >= 2)
                    {
                        SHMI_INFO("\nSHMI_DKINFO_EV_TTSET1 p_data[1] %d\n", p_data[1]);
                        fl_tt_status |= (p_data[1] << 8);
                        if (p_length >= 3)
                        {
                            SHMI_INFO("\nSHMI_DKINFO_EV_TTSET1 p_data[2] %d\n", p_data[2]);
                            fl_tt_status |= (p_data[2] << 16);
                            if (p_length >= 4)
                            {
                                SHMI_INFO("\nSHMI_DKINFO_EV_TTSET1 p_data[3] %d\n", p_data[3]);
                                fl_tt_status |= (p_data[3] << 24);
                                
                            }
                        }
                    }
                }
                l_tt_status = fl_tt_status;
                SHMI_INFO("\nSHMI_DKINFO_EV_FUEL %d\n", l_tt_status);
            }
            break;
			case SHMI_DKINFO_EV_FUEL:
			{
				if (p_length >= 2)
				{
					l_fuel_percentage = p_data[0];
					l_fuel_percentage |= (p_data[1] << 8);
					fl_ret = 0;
					SHMI_INFO("SHMI_DKINFO_EV_FUEL %d\n", l_fuel_percentage);
				}
			}
			break;
            case SHMI_DKINFO_EV_ODO:
            {
				if (p_length >= 4)
				{
					l_odometer = (uint32_t)p_data[0];
					l_odometer |= (((uint32_t)p_data[1]) << 8);
					l_odometer |= (((uint32_t)p_data[2]) << 16);
					l_odometer |= (((uint32_t)p_data[3]) << 24);
					SHMI_INFO("SHMI_DKINFO_EV_ODO val %d\n", l_odometer);
				}
            }
            break;
			case SHMI_DKINFO_EV_PRNDL:
			{
				//l_prndl_status
				if (p_length >= 1)
				{
					l_prndl_status = p_data[0];
					fl_ret = 0;
					SHMI_INFO("SHMI_DKINFO_EV_PRNDL %d\n", l_prndl_status);
				}
			}
			break;
			case SHMI_DKINFO_EV_ECT:
			{
				if (p_length >= 2)
				{
					l_ect = p_data[0];
					l_ect |= (p_data[1] << 8);
					fl_ret = 0;
					SHMI_INFO("SHMI_DKINFO_EV_ECT %d\n", l_ect);
				}
			}
			break;
			case SHMI_DKINFO_EV_TRIP:
			{
				if (p_length >= 4)
				{
					l_dte = (uint32_t)p_data[0];
					l_dte |= (((uint32_t)p_data[1]) << 8);
					l_dte |= (((uint32_t)p_data[2]) << 16);
					l_dte |= (((uint32_t)p_data[3]) << 24);
					SHMI_INFO("SHMI_DKINFO_EV_TRIP val %d\n", l_dte);
				}
			}
			break;
			default:
            {
            }
            break;
        }
    }
    else if(p_msg_base->id.group == SHMI_MSG_GROUP_EHCTRL)
    {
       switch(p_msg_base->id.event)
       {
          case SHMI_CTRL_EV_SCREEN:
          {
              if((p_length == 1) && (p_data != 0))
              {
                 if(p_data[0] != 0)
                 {
                     l_show_status = 1;
                 }
                 else
                 {
                     l_show_status = 0;
                 }
                 fl_ret = 0;
              }
              SHMI_INFO("SHMI_CTRL_EV_SCREEN val %d\n",p_data[0]);
          }
          break;
          case SHMI_CTRL_EV_CHKSUM:
          {
          }
          break;
          default:
          {
          }
          break;
       }
    }
    else if(p_msg_base->id.group == SHMI_MSG_GROUP_EHHMON)
    {
       if(l_server_alive < 0xFFFFFFFF)
       {
          if(pthread_mutex_lock(&l_vmf_mutex) == 0)
          {
             l_server_alive++;
             (void)pthread_mutex_unlock(&l_vmf_mutex);
             fl_ret = 0;
             SHMI_INFO("SHMI_MSG_GROUP_EHHMON %d\n", l_server_alive);
          }
       }
    }
    else
    {
    }
    return(fl_ret);
}

// =============================================================================
//  Function Name:    vmf_receiver
//  Visibility:       global
//  Description:      VMF rx thread
//  Invocation:       QNX
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
int vmf_receiver(void)
{
    VMF_VAR_MSG_TYP(SHMI_VMF_FAR_DATA_LEN) msg;

    while (vmf_connection_id >= 0)
    {
        uint32_t msg_len = nw_vmf_receive (vmf_connection_id, (vmf_msg_t*)&msg, sizeof(msg));
        if (msg_len != 0)
        {
            switch (msg.vmf_basic_msg.msg_base.base.msg_type)
            {
                case MSG_TYPE_BASIC_MESSAGE:
                {
                   (void)vmf_process_message(&msg.vmf_basic_msg.msg_base, msg.vmf_basic_msg.data.length, msg.vmf_basic_msg.data.pl);
                }
                break;
                case MSG_TYPE_MOST_MESSAGE:
                {
                }
                break;
                default:
                {
                }
                break;
            }
        }
    }
    return(vmf_connection_id);
}

// =============================================================================
//  Function Name:    vmf_if_get_show_state
//  Visibility:       global
//  Description:      Returns the show/hide status
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_show_state(void)
{
   return(l_show_status);
}

// =============================================================================
//  Function Name:    vmf_if_get_show_state
//  Visibility:       global
//  Description:      Returns the show/hide status
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_alive_count(void)
{
   uint32_t fl_server_alive;
   if(pthread_mutex_lock(&l_vmf_mutex) == 0)
   {
	  fl_server_alive = l_server_alive;
	  l_server_alive = 0;
      (void)pthread_mutex_unlock(&l_vmf_mutex);
   }
   else
   {
	   fl_server_alive = 0;
   }
   return(fl_server_alive);
}

// =============================================================================
//  Function Name:    vmf_if_get_speed
//  Visibility:       global
//  Description:      Returns the vehicle speed
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_speed(void)
{
   return(l_vspeed);
}

// =============================================================================
//  Function Name:    vmf_if_get_rpm
//  Visibility:       global
//  Description:      Returns the vehicle RPM
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_rpm(void)
{
   return(l_vrpm);
}

// =============================================================================
//  Function Name:    vmf_if_get_odometer
//  Visibility:       global
//  Description:      Returns the vehicle Odometer value
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_odometer(void)
{
   return(l_odometer);
}

// =============================================================================
//  Function Name:    vmf_if_get_odometer_unit
//  Visibility:       global
//  Description:      Returns the vehicle odo meter unit
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_odometer_unit(void)
{
   return(l_odometer_units);
}

// =============================================================================
//  Function Name:    vmf_if_get_gear_selection
//  Visibility:       global
//  Description:      Returns the vehicle gear (PRNDL) status
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_gear_selection(void)
{
   return(l_prndl_status);
}

// =============================================================================
//  Function Name:    vmf_if_get_tt_status
//  Visibility:       global
//  Description:      Returns the telltale status
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_tt_status(void)
{
   return(l_tt_status);
}
// =============================================================================
//  Function Name:    vmf_if_get_fuel_percentage
//  Visibility:       global
//  Description:      Returns the fuel percentage
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_fuel_percentage(void)
{
	return(l_fuel_percentage);
}
// =============================================================================
//  Function Name:    vmf_if_get_ect
//  Visibility:       global
//  Description:      Returns the engine coolant temperature
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
int16_t vmf_if_get_ect(void)
{
	return(l_ect);
}
// =============================================================================
//  Function Name:    vmf_if_get_oat
//  Visibility:       global
//  Description:      Returns the outside air temperature
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
int16_t vmf_if_get_oat(void)
{
	return(l_oat);
}
// =============================================================================
//  Function Name:    vmf_if_get_dist2destination
//  Visibility:       global
//  Description:      Returns the navigation distance to destination
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_dist2destination(void)
{
	return(l_dist2destination);
}
// =============================================================================
//  Function Name:    vmf_if_get_dte
//  Visibility:       global
//  Description:      Returns the trip distance to empty
//  Invocation:       EHMI application
//  Inputs/Outputs:   None
//  Critical Section: None
//  Created:          15-Jun-2017 by EMANOJ1
//  Updated:          15-Jun-2017 by EMANOJ1
// =============================================================================
uint32_t vmf_if_get_dte(void)
{
	return(l_dte);
}
}
// ============================================================================
// 
// ============================================================================
//  C M S    R E V I S I O N    N O T E S
// ============================================================================
//  For each change to this file, be sure to record:
//  1.  Who made the change and when the change was made.
//  2.  Why the change was made and the intended result.
// 
//  CMS Rev #        Date            By
//  CMS Rev X.X      dd-mmm-yyyy     CDSID
// 
// ============================================================================
// 
//  CMS Rev 1.0      15-Jun-2017     EMANOJ1
//  Creation.
// 
// ============================================================================
#endif
//  end of file ===============================================================
