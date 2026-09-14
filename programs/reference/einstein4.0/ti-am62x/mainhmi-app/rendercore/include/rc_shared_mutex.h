///////////////////////////////////////////////////////////////////////////////
//
//                     CONFIDENTIAL VISTEON CORPORATION
//
// This is an unpublished work of authorship, which contains trade secrets,
// created in 2018. Visteon Corporation owns all rights to this work and
// intends to maintain it in confidence to preserve its trade secret status.
// Visteon Corporation reserves the right, under the copyright laws of the
// United States or those of any other country that may have jurisdiction,
// to protect this work as an unpublished work, in the event of an
// inadvertent or deliberate unauthorized publication. Visteon Corporation
// also reserves its rights under all copyright laws to protect this work as
// a published work, when appropriate. Those having access to this work may
// not copy it, use it, modify it or disclose the information contained in
// it without the written authorization of Visteon Corporation.
//
//  Filename    : rc_shared_mutex.h
//  Description : Platform specific common APIs
//  Created on  : 02-Oct-2024 by brajan1@visteon.com
///////////////////////////////////////////////////////////////////////////////

// shared_mutex.h
#ifndef SHARED_MUTEX_H
#define SHARED_MUTEX_H

#include <pthread.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>




// Declare the variables
#define SHARED_MEM_NAME "/drm_shared_mutex"

// Setup or access the shared memory for the mutex
pthread_mutex_t* setup_shared_mutex() 
{
    int fd = shm_open(SHARED_MEM_NAME, O_CREAT | O_RDWR, 0666);
    if (fd == -1) {
        perror("shm_open failed");
        exit(1);
    }

    // Set the size of the shared memory
    if (ftruncate(fd, sizeof(pthread_mutex_t)) == -1) {
        perror("ftruncate failed");
        exit(1);
    }

    // Map the shared memory into the process's address space
    pthread_mutex_t* mutex = (pthread_mutex_t*)mmap(NULL, sizeof(pthread_mutex_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (mutex == MAP_FAILED) {
        perror("mmap failed");
        exit(1);
    }

    // Close the file descriptor
    close(fd);
    return mutex;
}

#endif
