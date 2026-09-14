/*
 * slogcodes.h
 *
 *  Created on: 20-Aug-2020
 *      Author: DRAJ5
 */

#ifndef CLUSTER_PLATFORM_DIJKSTRA_ABSTRACTION_BSPAL_SYS_SHUTDOWN_TEST_UT_STUBS_SYS_SLOGCODES_H_
#define CLUSTER_PLATFORM_DIJKSTRA_ABSTRACTION_BSPAL_SYS_SHUTDOWN_TEST_UT_STUBS_SYS_SLOGCODES_H_
#define _SLOGC_CHAR          6
#define _SLOG_INFO           5
#define _SLOG_ERROR          2
#define EOK 0
typedef signed int int32_t;
#define NULL 0
typedef unsigned char uint8_t;
typedef unsigned int uint32_t;
uint8_t delay(unsigned dly);
int devctl( int filedes,
            int dcmd,
            void * dev_data_ptr,
            size_t n_bytes,
            int * dev_info_ptr );
int slogf(int code, int severity, const char *fmt, ...) __attribute__((__format__(__printf__, 3, 4)));
#endif /* CLUSTER_PLATFORM_DIJKSTRA_ABSTRACTION_BSPAL_SYS_SHUTDOWN_TEST_UT_STUBS_SYS_SLOGCODES_H_ */
