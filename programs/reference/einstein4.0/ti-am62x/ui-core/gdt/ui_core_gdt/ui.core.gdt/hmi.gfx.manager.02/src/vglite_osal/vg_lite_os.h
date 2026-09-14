#ifndef VG_LITE_OS_H
#define VG_LITE_OS_H

#include <stdint.h>

#define vg_lite_os_set_event_state(event, state)      (event)->signal_status = (state)

#define vg_lite_os_event_state(event)                 (event)->signal_status

#define vg_lite_os_config_event(event, sem_id, state) \
    { \
        (event)->semaphore_id = (sem_id); \
        (event)->signal_status = (state); \
    }


typedef struct vg_lite_os_async_event
{
    uint32_t    semaphore_id; /*! The Id of the semaphore assigned to this event */
    int32_t     signal_status;       /*! The command buffer status */
}
vg_lite_os_async_event_t;

/*!
@brief  Set the value in a task’s thread local storage array.
*/
uint32_t vg_lite_os_set_tls(void* tls);

/*!
@brief  Get the current task’s thread local storage array.
*/
void * vg_lite_os_get_tls(void);

/*!
@brief  Memory allocate.
*/
void * vg_lite_os_malloc(uint32_t size);

/*!
@brief  Memory free.
*/
void vg_lite_os_free(void * memory);

/*!
@brief  Reset the value in a task’s thread local storage array.
*/
void vg_lite_os_reset_tls(void);


/*!
@brief  sleep a number of milliseconds.
*/
void vg_lite_os_sleep(uint32_t msec);

/*!
@brief  initialize the os parameters.
*/
uint32_t vg_lite_os_initialize(void);

/*!
@brief  deinitialize the os parameters.
*/
void vg_lite_os_deinitialize(void);

/*!
@brief  Mutex semaphore take.
*/
uint32_t vg_lite_os_lock(void);

/*!
@brief  Mutex semaphore give.
*/
uint32_t vg_lite_os_unlock(void);

/*!
@brief  Submit the current command buffer to the command queue.
*/
uint32_t vg_lite_os_submit(uint32_t physical, uint32_t offset, uint32_t size, vg_lite_os_async_event_t *event);

/*!
@brief  Wait for the current command buffer to be executed.
*/
uint32_t vg_lite_os_wait(uint32_t timeout, vg_lite_os_async_event_t *event);

/*!
@brief  IRQ Handler.
*/
void vg_lite_os_IRQHandler(void);

/*!
@brief  Wait until an interrupt from the VGLite graphics hardware has been received.
*/
uint32_t vg_lite_os_wait_interrupt(uint32_t timeout, uint32_t mask, uint32_t * value);

/*!
@brief
*/
uint32_t vg_lite_os_init_event(vg_lite_os_async_event_t *event,
                                      uint32_t semaphore_id,
                                      int32_t state);

/*!
@brief
*/
uint32_t vg_lite_os_delete_event(vg_lite_os_async_event_t *event);

#endif
