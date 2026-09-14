
#include "fsl_common.h"
#include "vg_lite_hw.h"
#include "vg_lite_hal.h"
#include "vg_lite_os.h"
#include "hmi_gfx_mgr02_imxrt_mem_mgmt.h"

/* If bit31 is activated this indicates a bus error */
#define IS_AXI_BUS_ERR(x) ((x)&((uint32_t)1 << 31))

#define ISR_WAIT_TIME   0x1FFFF

#define GFX_MGR02_VGL_UNUSED(X)      (void)(X)

#if 0
#define MAX_MUTEX_TIME  100
#define TASK_WAIT_TIME  20

/* command queue task parameter */
#define QUEUE_TASK_NAME  1
#ifndef QUEUE_TASK_PRIO
#define QUEUE_TASK_PRIO  3
#endif /* QUEUE_TASK_PRIO */
#define QUEUE_TASK_SIZE  STACK_DEPTH_2KB
#define QUEUE_LENGTH     8
#define MAX_QUEUE_WAIT_NUM  10
 
typedef struct vg_lite_queue{
    uint32_t  cmd_physical;
    uint32_t  cmd_offset;
    uint32_t  cmd_size;
    vg_lite_os_async_event_t *event;
}
vg_lite_queue_t;

typedef struct vg_lite_os{
    TaskHandle_t     task_hanlde;
    QueueHandle_t    queue_handle;
}
vg_lite_os_t;
#endif

static volatile uint32_t int_flags;

static void *vglite_context = NULL;

void __attribute__((weak)) vg_lite_bus_error_handler(void)
{
    /*
     * Default implementation of the bus error handler does nothing. Application
     * should override this handler if it requires to be notified when a bus
     * error event occurs.
     */
     return;
}

uint32_t vg_lite_os_set_tls(void* tls)
{
    uint32_t ret;
    
    if(tls != NULL)
    {
        vglite_context = tls;
        ret = (uint32_t)VG_LITE_SUCCESS;
    }
    else
    {
        ret = (uint32_t)VG_LITE_INVALID_ARGUMENT;
    }
    return ret;
}

void * vg_lite_os_get_tls(void)
{
    return vglite_context;
}

void * vg_lite_os_malloc(uint32_t size)
{
    PixEngMemInfo  p_meminfo;
    
    p_meminfo.MemCateg       = IMXRT_VGLITE_OS_HEAP_MEM;
    p_meminfo.WidgetClientId = 0xFFFFFFFF;
    p_meminfo.Alignment      = VGLITE_MEM_ALIGNMENT;
    p_meminfo.Size           = size;
    p_meminfo.ExtMemory      = (UINT8)1;
    #if defined(GFX_MGR02_MEM_MGMT_STATIC_ALLOCATION)    
    p_meminfo.WidgetFBGroupId  = GFX_MGR02_INVALID_FB_GROUP_ID;
    #endif
    
    return hmi_gfx_mgr02_imxrt_mem_mgmt_malloc(&p_meminfo);
}

void vg_lite_os_free(void * memory)
{
    hmi_gfx_mgr02_imxrt_mem_mgmt_free(memory);
}

void vg_lite_os_reset_tls(void)
{
    vglite_context = NULL;
}

void vg_lite_os_sleep(uint32_t msec)
{
    SDK_DelayAtLeastUs(1000U * msec, SDK_DEVICE_MAXIMUM_CPU_CLOCK_FREQUENCY);
}

uint32_t vg_lite_os_initialize(void)
{
    int_flags = 0;
    return (uint32_t)VG_LITE_SUCCESS;
}

void vg_lite_os_deinitialize(void)
{
    /* TODO: Remove clock. */
    /* TODO: Remove power. */
}

uint32_t vg_lite_os_lock(void)
{
    return (uint32_t)VG_LITE_SUCCESS;
}

uint32_t vg_lite_os_unlock(void)
{
    return (uint32_t)VG_LITE_SUCCESS;
}

uint32_t vg_lite_os_submit(uint32_t physical, uint32_t offset, uint32_t size, vg_lite_os_async_event_t *event)
{
    /* Current command buffer has been sent to the command queue. */
    vg_lite_os_set_event_state(event, (int32_t)VG_LITE_IN_QUEUE);
            
    vg_lite_hal_poke(VG_LITE_HW_CMDBUF_ADDRESS, physical + offset);
    vg_lite_hal_poke(VG_LITE_HW_CMDBUF_SIZE, (size + (uint32_t)7)/(uint32_t)8 );
    
    return (uint32_t)VG_LITE_SUCCESS;
}

uint32_t vg_lite_os_wait(uint32_t timeout, vg_lite_os_async_event_t *event)
{
    uint32_t ret;
    uint32_t even_got = 0;
    
    if(vg_lite_hal_wait_interrupt(ISR_WAIT_TIME, ~((uint32_t)0), &even_got) != (int32_t)0)  //wait for GPU interrupt
    {
        vg_lite_os_set_event_state(event, (int32_t)VG_LITE_HW_FINISHED);
        ret = (uint32_t)VG_LITE_SUCCESS;
    }
    else // wait timeout
    {
        vg_lite_os_set_event_state(event, (int32_t)VG_LITE_IDLE);
        ret = (uint32_t)VG_LITE_TIMEOUT;
    }
    GFX_MGR02_VGL_UNUSED(timeout);
    return ret;
}

void vg_lite_os_IRQHandler(void)
{
    uint32_t flags = vg_lite_hal_peek(VG_LITE_INTR_STATUS);

    if (flags != (uint32_t)0) 
    {
        int_flags |= flags; /* Combine with current interrupt flags. */
    }
}

uint32_t vg_lite_os_wait_interrupt(uint32_t timeout, uint32_t mask, uint32_t *value)
{
 
    while (int_flags == (uint32_t)0){}
    
    if (value != NULL) 
    {
        *value = int_flags & mask;
        if (IS_AXI_BUS_ERR(*value) != (uint32_t)0)
        {
            vg_lite_bus_error_handler();
        }
        int_flags = 0;
    }
    GFX_MGR02_VGL_UNUSED(timeout);
    return (uint32_t)1;
}

uint32_t vg_lite_os_init_event(vg_lite_os_async_event_t *event,
                                      uint32_t semaphore_id,
                                      int32_t state)
{
    
    vg_lite_os_config_event(event, semaphore_id, state)
    
    return (uint32_t)VG_LITE_SUCCESS;
}

uint32_t vg_lite_os_delete_event(vg_lite_os_async_event_t *event)
{
    GFX_MGR02_VGL_UNUSED(event);
    return (uint32_t)VG_LITE_SUCCESS;
}
