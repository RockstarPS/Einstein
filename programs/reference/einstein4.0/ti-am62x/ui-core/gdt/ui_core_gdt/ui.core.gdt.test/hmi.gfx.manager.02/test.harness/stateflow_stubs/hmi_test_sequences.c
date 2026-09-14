#include "system.h"
#include "hmi_gfx_mgr02_if.h"
#include "wchar.h"

/*
** This is a dummy file to build the matlab model.
*/

static volatile l_dummy = 0;

void hmi_app_demo_presentation_task(void)
{
   l_dummy = 0;
}

UINT32 hmi_gfx_mgr02_if_presentation_task(void)
{
   return(l_dummy);
}

void KernelTriggerGraphicsTask(void)
{
   l_dummy = 1;
}

void hmi_gfx_mgr02_driver_shutdown(void)
{
}

void hmi_gfx_mgr02_driver_startup(void)
{
}
void hmi_gfx_mgr02_layout_shutdown(void)
{
}
void hmi_gfx_mgr02_layout_startup(void)
{
}
void hmi_gfx_mgr02_layout_initialize(void)
{
}

void hmi_gfx_mgr02_driver_enable_dcu(void)
{
}

void hmi_gfx_mgr02_emergency_shutdown(void)
{

}
void hmi_gfx_mgr02_driver_disable_dcu(void)
{
}

void hmi_gfx_mgr02_initialize(void)
{
}
