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
 * osa work queue related definitions
 */

#ifndef OSA_WORKQUEUE_H_
#define OSA_WORKQUEUE_H_

#include "osa_types.h"

/**
 * osa_create_workqueue - safely terminate a workqueue
 * @name: name of the workqueue
 *
 * which returns a workqueue_struct reference. You can remote this work queue
 * later (if needed) through a call to the destroy_workqueue function.
 */
void *osa_create_workqueue(void *name);

/**
 * osa_destroy_workqueue - safely terminate a workqueue
 * @wq: target workqueue
 *
 * Safely destroy a workqueue. All work currently pending will be done first.
 */
void osa_destroy_workqueue(void *wq);

/**
 * osa_init_work - This function provides the necessary initialization
 * and saving given pointer(work_args) in linked list.
 * @work_args: structure for the initialization
 * @work_fn: work function pointer
 *
 * This function provides the necessary initialization
 * and setting of the handler function (passed by the user).
 */
void osa_init_work(void **work_args, void *work_fn, uint8_t hwa_id);

/**
 * osa_init_delayed_work - This function provides the necessary initialization.
 * and saving given pointer(work_args) in linked list.
 * @work_args: structure for the initialization
 * @work_fn: work function pointer
 *
 * This function provides the necessary initialization
 * and setting of the handler function (passed by the user).
 */
void osa_init_delayed_work(void **work_args, void *work_fn, uint8_t hwa_id);

/**
 * osa_queue_work - queue work on a workqueue
 * @wq: workqueue to use
 * @work: work to queue
 *
 * Returns %osa_false if @work was already on a queue, %true otherwise.
 *
 * We queue the work to the CPU on which it was submitted, but if the CPU dies
 * it can be processed by another CPU.
 */
int32 osa_queue_work(void *wq, void *work);

/**
 * osa_queue_work_on - queue work on specific cpu
 * @cpu: CPU number to execute work on
 * @wq: workqueue to use
 * @work: work to queue
 *
 * We queue the work to a specific CPU, the caller must ensure it
 * can't go away.
 *
 * Return: %osa_false if @work was already on a queue, %true otherwise.
 */
int32 osa_queue_work_on(int32 cpu, void *wq, void *work);

/**
 * osa_queue_delayed_work - queue work on a workqueue after delay
 * @wq: workqueue to use
 * @dwork: delayable work to queue
 * @delay: number of jiffies to wait before queueing
 *
 * Equivalent to osa_queue_delayed_work_on() but tries to use the local CPU.
 */
int32 osa_queue_delayed_work(void *wq, void *dwork, uint64 delay);

/**
 * osa_queue_delayed_work_on - queue work on specific CPU after delay
 * @cpu: CPU number to execute work on
 * @wq: workqueue to use
 * @dwork: work to queue
 * @delay: number of jiffies to wait before queueing
 *
 * Return: %osa_false if @work was already on a queue, %true otherwise.  If
 * @delay is zero and @dwork is idle, it will be scheduled for immediate
 * execution.
 */
int32 osa_queue_delayed_work_on(int32 cpu, void *wq,
            void *dwork, uint64 delay);

/**
 * osa_schedule_work - put work task in global workqueue
 * @work: job to be done
 *
 * Returns %osa_false if @work_args was already on the kernel-global workqueue and
 * %true otherwise.
 *
 * This puts a job in the kernel-global workqueue if it was not already
 * queued and leaves it in the same position on the kernel-global
 * workqueue otherwise.
 */
int32 osa_schedule_work(void *work_args);

/**
 * osa_schedule_work_on - put work task on a specific cpu
 * @cpu: cpu to put the work task on
 * @work: job to be done
 *
 * This puts a job on a specific cpu
 */
int32 osa_schedule_work_on(int32 cpu, void *work);

/**
 * osa_schedule_delayed_work - put work task in global workqueue after delay
 * @dwork: job to be done
 * @delay: number of jiffies to wait or 0 for immediate execution
 *
 * After waiting for a given time this puts a job in the kernel-global
 * workqueue.
 */
int32 osa_schedule_delayed_work(void *dwork, uint64 delay);

/**
 * osa_schedule_delayed_work_on - queue work in global workqueue on CPU after delay
 * @cpu: cpu to use
 * @dwork: job to be done
 * @delay: number of jiffies to wait
 *
 * After waiting for a given time this puts a job in the kernel-global
 * workqueue on the specified CPU.
 */
int32 osa_schedule_delayed_work_on(int32 cpu, void *dwork, uint64 delay);

/**
 * osa_flush_work - wait for a work to finish executing the last queueing instance
 * @work: the work to flush
 *
 * Wait until @work has finished execution.  @work is guaranteed to be idle
 * on return if it hasn't been requeued since flush started.
 *
 * Return:
 * %true if osa_flush_work() waited for the work to finish execution,
 * %osa_false if it was already idle.
 */
int32 osa_flush_work(void *work_args);

/**
 * osa_flush_workqueue - ensure that any scheduled work has run to completion.
 * @wq: workqueue to flush
 *
 * This function sleeps until all work items which were queued on entry
 * have finished execution, but it is not livelocked by new incoming ones.
 */
void osa_flush_workqueue(void *wq);

/**
 * osa_drain_workqueue - drain a workqueue
 * @wq: workqueue to drain
 *
 * Wait until the workqueue becomes empty.  While draining is in progress,
 * only chain queueing is allowed.  IOW, only currently pending or running
 * work items on @wq can queue further work items on it.  @wq is flushed
 * repeatedly until it becomes empty.  The number of flushing is determined
 * by the depth of chaining and should be relatively short.  Whine if it
 * takes too long.
 */
void osa_drain_workqueue(void *wq);

/**
 * osa_flush_scheduled_work - ensure that any scheduled work has run to completion.
 *
 * Forces execution of the kernel-global workqueue and blocks until its
 * completion.
 *
 * Think twice before calling this function!  It's very easy to get into
 * trouble if you don't take great care.  Either of the following situations
 * will lead to deadlock:
 *
 *  One of the work items currently on the workqueue needs to acquire
 *  a lock held by your code or its caller.
 *
 *  Your code is running in the context of a work routine.
 *
 * They will be detected by lockdep when they occur, but the first might not
 * occur very often.  It depends on what work items are on the workqueue and
 * what locks they need, which you have no control over.
 *
 * In most situations flushing the entire workqueue is overkill; you merely
 * need to know that a particular work item isn't queued and isn't running.
 * In such cases you should use osa_cancel_delayed_work_sync() or
 * osa_cancel_work_sync() instead.
 */
void osa_flush_scheduled_work(void);

/**
 * osa_cancel_delayed_work_sync - cancel a delayed work and wait for it to finish
 * @dwork: the delayed work cancel
 *
 * This is osa_cancel_work_sync() for delayed works.
 *
 * Return:
 * %true if @dwork was pending, %osa_false otherwise.
 */
int32 osa_cancel_delayed_work_sync(void *dwork);

/**
 * osa_cancel_delayed_work - cancel a delayed work
 * @dwork: delayed_work to cancel
 *
 * Kill off a pending delayed_work.
 *
 * Return: %true if @dwork was pending and canceled; %osa_false if it wasn't
 * pending.
 *
 * Note:
 * The work callback function may still be running on return, unless
 * it returns %true and the work doesn't re-arm itself.  Explicitly flush or
 * use osa_cancel_delayed_work_sync() to wait on it.
 *
 * This function is safe to call from any context including IRQ handler.
 */
int32 osa_cancel_delayed_work(void *dwork);

/**
 * osa_cancel_work_sync - cancel a work and wait for it to finish
 * @work: the work to cancel
 *
 * Cancel @work and wait for its execution to finish.  This function
 * can be used even if the work re-queues itself or migrates to
 * another workqueue.  On return from this function, @work is
 * guaranteed to be not pending or executing on any CPU.
 *
 * osa_cancel_work_sync(&delayed_work->work) must not be used for
 * delayed_work's.  Use osa_cancel_delayed_work_sync() instead.
 *
 * The caller must ensure that the workqueue on which @work was last
 * queued can't be destroyed before this function returns.
 *
 * Return:
 * %true if @work was pending, %osa_false otherwise.
 */
int32 osa_cancel_work_sync(void *work);

/**
 * osa_mod_delayed_work - modify delay of or queue a delayed work
 * @wq: workqueue to use
 * @dwork: work to queue
 * @delay: number of jiffies to wait before queueing
 *
 * osa_mod_delayed_work_on() on local CPU.
 */
int32 osa_mod_delayed_work(void*wq, void *dwork, uint64 delay);

/**
 * osa_mod_delayed_work_on - modify delay of or queue a delayed work on specific CPU
 * @cpu: CPU number to execute work on
 * @wq: workqueue to use
 * @dwork: work to queue
 * @delay: number of jiffies to wait before queueing
 *
 * If @dwork is idle, equivalent to queue_delayed_work_on(); otherwise,
 * modify @dwork's timer so that it expires after @delay.  If @delay is
 * zero, @work is guaranteed to be scheduled immediately regardless of its
 * current state.
 *
 * Return: %osa_false if @dwork was idle and queued, %true if @dwork was
 * pending and its timer was modified.
 *
 * This function is safe to call from any context including IRQ handler.
 */
int32 osa_mod_delayed_work_on(int32 cpu, void *wq,
            void *dwork, uint64 delay);

/**
 * osa_get_global_workqueue_struct - Return the global workqueue structure pointer
 */
void *osa_get_global_workqueue_struct(void);

/**
 * osa_get_delayed_work_buff - This function return base address of given pointer
 * @key: The given work struct pointer
 * @flag: If TRUE, delete the node from the linked list.
 *
 * Return: Base address of the given input buffer.
 */
void *osa_get_delayed_work_buff(void *key, int8 flag);

/**
 * osa_get_work_buff - This function return base address of given pointer
 * @key: The given work struct pointer
 * @flag: If TRUE, delete the node from the linked list.
 *
 * Return: Base address of the given input buffer.
 */
void *osa_get_work_buff(void *key, int8 flag);


#endif /* OSA_WORKQUEUE_H_ */
