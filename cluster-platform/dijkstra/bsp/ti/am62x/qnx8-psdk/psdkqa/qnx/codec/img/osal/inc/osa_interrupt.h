/*****************************************************************************
*
* Copyright (c) Imagination Technologies Ltd.
* Copyright (c) 2018-22 Texas Instruments Incorporated - http://www.ti.com/
*
* The contents of this file are subject to the MIT license as set out below.
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHERa
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
* Alternatively, the contents of this file may be used under the terms of the
* GNU General Public License Version 2 ("GPL")in which case the provisions of
* GPL are applicable instead of those above.
*
* If you wish to allow use of your version of this file only under the terms
* of GPL, and not to allow others to use your version of this file under the
* terms of the MIT license, indicate your decision by deleting the provisions
* above and replace them with the notice and other provisions required by GPL
* as set out in the file called "GPLHEADER" included in this distribution. If
* you do not delete the provisions above, a recipient may use your version of
* this file under the terms of either the MIT license or GPL.
*
* This License is also included in this distribution in the file called
* "MIT_COPYING".
*
*****************************************************************************/
/*
 * osa interrupt definitions
 */

#ifndef OSA_INTERRUPT_H_
#define OSA_INTERRUPT_H_

#include "osa_types.h"

/**
 * enum irqreturn
 * @IRQ_NONE        interrupt was not from this device or was not handled
 * @IRQ_HANDLED     interrupt was handled by this device
 * @IRQ_WAKE_THREAD handler requests to wake the handler thread
 */
enum osa_irqreturn {
    OSA_IRQ_NONE        = (0 << 0),
    OSA_IRQ_HANDLED     = (1 << 0),
    OSA_IRQ_WAKE_THREAD     = (1 << 1),
    OSA_IRQ_FORCE32BITS = 0x7FFFFFFFU
};

typedef enum osa_irqreturn osa_irqreturn_t;

typedef enum osa_irq_flag
{
    OSA_IRQF_SHARED,
    OSA_IRQF_PROBE_SHARED,
    OSA___IRQF_TIMER,
    OSA_IRQF_PERCPU,
    OSA_IRQF_NOBALANCING,
    OSA_IRQF_IRQPOLL,
    OSA_IRQF_ONESHOT,
    OSA_IRQF_NO_SUSPEND,
    OSA_IRQF_FORCE_RESUME,
    OSA_IRQF_NO_THREAD,
    OSA_IRQF_EARLY_RESUME,
    OSA_IRQF_COND_SUSPEND,
    OSA_IRQF_FORCE32BITS = 0x7FFFFFFFU
}osa_irq_flag_t;

/**
 *  osa_request_irq - allocate an interrupt line
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs.
 *        Primary handler for threaded interrupts
 *        If NULL and thread_fn != NULL the default
 *        primary handler is installed
 *  @irqflags: Interrupt type flags
 *  @devname: An ascii name for the claiming device
 *  @dev_id: A cookie passed back to the handler function
 *
 *  This call allocates interrupt resources and enables the
 *  interrupt line and IRQ handling. From the point this
 *  call is made your handler function may be invoked. Since
 *  your handler function must clear any interrupt the board
 *  raises, you must take care both to initialise your hardware
 *  and to set up the interrupt handler in the right order.
 *
 *  If you want to set up a threaded irq handler for your device
 *  then you need to supply @handler and @thread_fn. @handler is
 *  still called in hard interrupt context and has to check
 *  whether the interrupt originates from the device. If yes it
 *  needs to disable the interrupt on the device and return
 *  IRQ_WAKE_THREAD which will wake up the handler thread and run
 *  @thread_fn. This split handler design is necessary to support
 *  shared interrupts.
 *
 *  Dev_id must be globally unique. Normally the address of the
 *  device data structure is used as the cookie. Since the handler
 *  receives this value it makes sense to use it.
 *
 *  If your interrupt is shared you must pass a non NULL dev_id
 *  as this is required when freeing the interrupt.
 *
 *  Flags:
 *
 *  IRQF_SHARED     Interrupt is shared
 *  IRQF_TRIGGER_*      Specify active edge(s) or level
 *
 */
int32 osa_request_irq(uint32 irq, void *handler,
        osa_irq_flag_t flags, const int8 *name, void *dev);

/**
 *  osa_free_irq - free an interrupt allocated with request_irq
 *  @irq: Interrupt line to free
 *  @dev_id: Device identity to free
 *
 *  Remove an interrupt handler. The handler is removed and if the
 *  interrupt line is no longer in use by any driver it is disabled.
 *  On a shared IRQ the caller must ensure the interrupt is disabled
 *  on the card it drives before calling this function. The function
 *  does not return until any executing interrupts for this IRQ
 *  have completed.
 *
 *  This function must not be called from interrupt context.
 *
 *  Returns the devname argument passed to request_irq.
 */
const void* osa_free_irq(unsigned int irq, void *dev_id);

/**
 *  osa_disable_irq - disable an irq and wait for completion
 *  @irq: Interrupt to disable
 *
 *  Disable the selected interrupt line.  Enables and Disables are
 *  nested.
 *  This function waits for any pending IRQ handlers for this interrupt
 *  to complete before returning. If you use this function while
 *  holding a resource the IRQ handler may need you will deadlock.
 *
 *  This function may be called - with care - from IRQ context.
 */
void osa_disable_irq(uint32 irq);

/**
 *  osa_enable_irq - enable handling of an irq
 *  @irq: Interrupt to enable
 *
 *  Undoes the effect of one call to osa_disable_irq().  If this
 *  matches the last disable, processing of interrupts on this
 *  IRQ line is re-enabled.
 *
 *  This function may be called from IRQ context
 */
void osa_enable_irq(uint32 irq);
/**
 *  osa_disable_irq_nosync - disable an irq without waiting
 *  @irq: Interrupt to disable
 *
 *  Disable the selected interrupt line.  Disables and Enables are
 *  nested.
 *  Unlike osa_disable_irq(), this function does not ensure existing
 *  instances of the IRQ handler have completed before returning.
 *
 *  This function may be called from IRQ context.
 */
void osa_disable_irq_nosync(uint32 irq);

/**
 *  osa_synchronize_irq - wait for pending IRQ handlers (on other CPUs)
 *  @irq: interrupt number to wait for
 *
 *  This function waits for any pending IRQ handlers for this interrupt
 *  to complete before returning. If you use this function while
 *  holding a resource the IRQ handler may need you will deadlock.
 *
 *  This function may be called - with care - from IRQ context.
 */
void osa_synchronize_irq(uint32 irq);

/**
 *  osa_request_threaded_irq - allocate an interrupt line
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs.
 *        Primary handler for threaded interrupts
 *        If NULL and thread_fn != NULL the default
 *        primary handler is installed
 *  @thread_fn: Function called from the irq handler thread
 *          If NULL, no irq thread is created
 *  @irqflags: Interrupt type flags
 *  @devname: An ascii name for the claiming device
 *  @dev_id: A cookie passed back to the handler function
 *
 *  This call allocates interrupt resources and enables the
 *  interrupt line and IRQ handling. From the point this
 *  call is made your handler function may be invoked. Since
 *  your handler function must clear any interrupt the board
 *  raises, you must take care both to initialise your hardware
 *  and to set up the interrupt handler in the right order.
 *
 *  If you want to set up a threaded irq handler for your device
 *  then you need to supply @handler and @thread_fn. @handler is
 *  still called in hard interrupt context and has to check
 *  whether the interrupt originates from the device. If yes it
 *  needs to disable the interrupt on the device and return
 *  IRQ_WAKE_THREAD which will wake up the handler thread and run
 *  @thread_fn. This split handler design is necessary to support
 *  shared interrupts.
 *
 *  Dev_id must be globally unique. Normally the address of the
 *  device data structure is used as the cookie. Since the handler
 *  receives this value it makes sense to use it.
 *
 *  If your interrupt is shared you must pass a non NULL dev_id
 *  as this is required when freeing the interrupt.
 *
 *  Flags:
 *
 *  IRQF_SHARED     Interrupt is shared
 *  IRQF_TRIGGER_*      Specify active edge(s) or level
 *
 */
int32 osa_request_threaded_irq(uint32 irq, void *handler,
             void *thread_fn, osa_irq_flag_t irqflags,
             const uint8 *devname, void *dev_id);

/**
 *  osa_devm_request_threaded_irq - allocate an interrupt line for a managed device
 *  @dev: device to request interrupt for
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs
 *  @thread_fn: function to be called in a threaded interrupt context. NULL
 *          for devices which handle everything in @handler
 *  @irqflags: Interrupt type flags
 *  @devname: An ascii name for the claiming device, dev_name(dev) if NULL
 *  @dev_id: A cookie passed back to the handler function
 *
 *  Except for the extra @dev argument, this function takes the
 *  same arguments and performs the same function as
 *  osa_request_threaded_irq().  IRQs requested with this function will be
 *  automatically freed on driver detach.
 *
 *  If an IRQ allocated with this function needs to be freed
 *  separately, osa_devm_free_irq() must be used.
 */
int32 osa_devm_request_threaded_irq(void *dev, uint32 irq,
                  void *handler, void *thread_fn,
                  osa_irq_flag_t irqflags, const uint8 *devname,
                  void *dev_id);

/**
 *  osa_devm_free_irq - free an interrupt
 *  @dev: device to free interrupt for
 *  @irq: Interrupt line to free
 *  @dev_id: Device identity to free
 *
 *  Except for the extra @dev argument, this function takes the
 *  same arguments and performs the same function as osa_free_irq().
 *  This function instead of osa_free_irq() should be used to manually
 *  free IRQs allocated with osa_devm_request_irq().
 */
void osa_devm_free_irq(void *dev, uint32 irq, void *dev_id);

/**
 *  osa_irq_wake_thread - wake the irq thread for the action identified by dev_id
 *  @irq:       Interrupt line
 *  @dev_id:    Device identity for which the thread should be woken
 *
 */
void osa_irq_wake_thread(uint32 irq, void *dev_id);

/**
 *  osa_request_any_context_irq - allocate an interrupt line
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs.
 *        Threaded handler for threaded interrupts.
 *  @flags: Interrupt type flags
 *  @name: An ascii name for the claiming device
 *  @dev_id: A cookie passed back to the handler function
 *
 *  This call allocates interrupt resources and enables the
 *  interrupt line and IRQ handling. It selects either a
 *  hardirq or threaded handling method depending on the
 *  context.
 *
 *  On failure, it returns a negative value. On success,
 *  it returns either IRQC_IS_HARDIRQ or IRQC_IS_NESTED.
 */
int32 osa_request_any_context_irq(uint32 irq, void *handler,
        osa_irq_flag_t flags, const int8 *name, void *dev_id);

/**
 *  osa_request_percpu_irq - allocate a percpu interrupt line
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs.
 *  @devname: An ascii name for the claiming device
 *  @dev_id: A percpu cookie passed back to the handler function
 *
 *  This call allocates interrupt resources and enables the
 *  interrupt on the local CPU. If the interrupt is supposed to be
 *  enabled on other CPUs, it has to be done on each CPU using
 *  osa_enable_percpu_irq().
 *
 *  Dev_id must be globally unique. It is a per-cpu variable, and
 *  the handler gets called with the interrupted CPU's instance of
 *  that variable.
 */
int32 osa_request_percpu_irq(uint32 irq, void *handler,
           const int8 *devname, void *percpu_dev_id);

/**
 *  osa_free_percpu_irq - free an interrupt allocated with request_percpu_irq
 *  @irq: Interrupt line to free
 *  @dev_id: Device identity to free
 *
 *  Remove a percpu interrupt handler. The handler is removed, but
 *  the interrupt line is not disabled. This must be done on each
 *  CPU before calling this function. The function does not return
 *  until any executing interrupts for this IRQ have completed.
 *
 *  This function must not be called from interrupt context.
 */
void osa_free_percpu_irq(uint32 irq, void *dev_id);

/**
 *  osa_devm_request_irq - allocate an interrupt line for a managed device
 *  @dev: device to request interrupt for
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs
 *  @irqflags: Interrupt type flags
 *  @devname: An ascii name for the claiming device, dev_name(dev) if NULL
 *  @dev_id: A cookie passed back to the handler function
 *
 *  Except for the extra @dev argument, this function takes the
 *  same arguments and performs the same function as
 *  osa_request_threaded_irq().  IRQs requested with this function will be
 *  automatically freed on driver detach.
 *
 *  If an IRQ allocated with this function needs to be freed
 *  separately, osa_devm_free_irq() must be used.
 */
int32 osa_devm_request_irq(void *dev, uint32 irq, void *handler,
        osa_irq_flag_t irqflags, const int8 *devname, void *dev_id);

/**
 *  osa_devm_request_any_context_irq - allocate an interrupt line for a managed device
 *  @dev: device to request interrupt for
 *  @irq: Interrupt line to allocate
 *  @handler: Function to be called when the IRQ occurs
 *  @thread_fn: function to be called in a threaded interrupt context. NULL
 *          for devices which handle everything in @handler
 *  @irqflags: Interrupt type flags
 *  @devname: An ascii name for the claiming device, dev_name(dev) if NULL
 *  @dev_id: A cookie passed back to the handler function
 *
 *  Except for the extra @dev argument, this function takes the
 *  same arguments and performs the same function as
 *  osa_request_any_context_irq().  IRQs requested with this function will be
 *  automatically freed on driver detach.
 *
 *  If an IRQ allocated with this function needs to be freed
 *  separately, osa_devm_free_irq() must be used.
 */
int32 osa_devm_request_any_context_irq(void *dev, uint32 irq,
                  void *handler, osa_irq_flag_t irqflags,
                  const int8 *devname, void *dev_id);
/**
 *  osa_disable_hardirq - disables an irq and waits for hardirq completion
 *  @irq: Interrupt to disable
 *
 *  Disable the selected interrupt line.  Enables and Disables are
 *  nested.
 *  This function waits for any pending hard IRQ handlers for this
 *  interrupt to complete before returning. If you use this function while
 *  holding a resource the hard IRQ handler may need you will deadlock.
 *
 *  When used to optimistically disable an interrupt from atomic context
 *  the return value must be checked.
 *
 *  Returns: osa_false if a threaded handler is active.
 *
 *  This function may be called - with care - from IRQ context.
 */
int32 osa_disable_hardirq(uint32 irq);

/**
 *  osa_disable_percpu_irq - disable an irq and wait for completion
 *  @irq: Interrupt to disable
 */
void osa_disable_percpu_irq(uint32 irq);

/**
 *  osa_enable_percpu_irq - enable an irq and wait for completion
 *  @irq: Interrupt to enable
 *  @type: type of irq
 */
void osa_enable_percpu_irq(uint32 irq, uint32 type);

/**
 * osa_irq_percpu_is_enabled - Check whether the per cpu irq is enabled
 * @irq:    Linux irq number to check for
 *
 * Must be called from a non migratable context. Returns the enable
 * state of a per cpu interrupt on the current cpu.
 */
int32 osa_irq_percpu_is_enabled(uint32 irq);

/**
 *  osa_irq_set_irq_wake - control irq power management wakeup
 *  @irq:   interrupt to control
 *  @on:    enable/disable power management wakeup
 *
 *  Enable/disable power management wakeup mode, which is
 *  disabled by default.  Enables and disables must match,
 *  just as they match for non-wakeup mode support.
 *
 *  Wakeup mode lets this IRQ wake the system from sleep
 *  states like "suspend to RAM".
 */
int32 osa_irq_set_irq_wake(uint32 irq, uint32 on);

/**
 *  osa_local_irq_disable - disable an irq on local core
 *  @status: flag to save the interrupt status
 */

void osa_local_irq_disable(ulong *status);

/**
 *  osa_local_irq_enable - enable an irq on local core
 *  @status: flag contains interrupt status
 */
void osa_local_irq_enable(ulong status);


#endif /* OSA_INTERRUPT_H_ */
