/*
 * imx8_sci_mgr.h
 *
 *  Created on: 17-Aug-2020
 *      Author: DRAJ5
 */

#ifndef CLUSTER_PLATFORM_DIJKSTRA_ABSTRACTION_BSPAL_SYS_SHUTDOWN_TEST_UT_STUBS_IMX8_SCI_MGR_H_
#define CLUSTER_PLATFORM_DIJKSTRA_ABSTRACTION_BSPAL_SYS_SHUTDOWN_TEST_UT_STUBS_IMX8_SCI_MGR_H_

typedef int         sci_mgr_err_t;
#define _DCMD_MISC		0x05
#define IMX_DCMD_PM_OFFSET    10
#define IMX_DCMD_IRQ_OFFSET   (IMX_DCMD_PM_OFFSET + 32)
#define IMX_DCMD_MISC_OFFSET  (IMX_DCMD_IRQ_OFFSET + 32)
#define IMX_DCMD_PAD_OFFSET   (IMX_DCMD_MISC_OFFSET + 32)
#define IMX_DCMD_RM_OFFSET    (IMX_DCMD_PAD_OFFSET + 32)
#define IMX_DCMD_TIMER_OFFSET (IMX_DCMD_RM_OFFSET + 32)
#define IMX_DCMD_TIMER(index)                        (IMX_DCMD_TIMER_OFFSET + index)
#define _POSIX_DEVDIR_TO		0x80000000
#define __DIOT(class, cmd, data)	(int)((unsigned)(sizeof(data)<<16) + ((unsigned)(class)<<8) + (unsigned)(cmd) + (unsigned)(_POSIX_DEVDIR_TO))
#define IMX_DCMD_SC_TIMER_STOP_WDOG                      __DIOT(_DCMD_MISC,  IMX_DCMD_TIMER(3), uint32_t)

#endif /* CLUSTER_PLATFORM_DIJKSTRA_ABSTRACTION_BSPAL_SYS_SHUTDOWN_TEST_UT_STUBS_IMX8_SCI_MGR_H_ */
