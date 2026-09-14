/*
 * System Firmware Common Userspace functions
 *
 * Copyright (C) 2019-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#ifndef USER_H
#define USER_H

#include <types/short_types.h>

/**
 * \brief Initialize the userspace core TISCI message handlers
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 core_user_message_init(void);

/**
 * \brief Initialize any userspace code that needs it
 *
 * \return Error code on failure, SUCCESS otherwise.
 */
s32 user_init(void);

#endif /* USER_H */
