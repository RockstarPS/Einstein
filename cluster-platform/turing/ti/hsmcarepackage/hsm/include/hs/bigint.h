/*
 * Copyright (C) 2018-2020 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */

/**
 * \file bigint.h
 *
 * \brief function prototypes for handling bigint data types.
 */

#ifndef BIGINT_H
#define BIGINT_H
#include <types/short_types.h>
#include <types/fterr.h>

/*
 * bigint format is required for using PKA. Description of the format from
 * PKA Hardware reference manual is below.
 *
 * The vectors (big numbers) that are the input and output of the PKA operations
 * are stored in the PKA RAM. Each vector consists of a sequence of (32-bit)
 * words, stored little-endian in a contiguous block of memory with the least
 * significant word at the lowest address of that memory block and bit [0] of
 * the vector in bit [0] of that word.
 */

/**
 * \brief Function to convert from u8 array (big endian octet string)
 * into a little endian big s32 object.
 *
 * \param arr input array holding the big endian octet string
 * \param len length of the input array
 * \param dest_arr output array holding the big s32 object
 * \param dest_len length of the output array to prevent buffer overflow
 *
 * \return Returns EFTOK on success, returns error code on failure
 */
fterr convert_u8_arr_to_bigint(const u8 *arr, u32 len, u32 *dest_arr, u32 dest_len);

/**
 * \brief Function to convert bigint to u8 array (with change in endianness
 *  from little endian to big endian)
 *
 * \param arr input array holding the little endian u32 string
 *      (note arr[0] is the size of u32 string)
 * \param dest_arr output array holding the big endian octet string
 * \param dest_len length of the output array to prevent buffer overflow
 *
 * \return Returns EFTOK on success, returns error code on failure
 */
fterr convert_bigint_to_u8_arr(const u32 *arr, u8 *dest_arr, u32 dest_len);


/**
 * \brief Return the size in bits of a bigint
 *
 * \param bn Input number
 *
 * \param max_len length of the bn array in words.
 *
 * \return Length in bits of the big number
 */
u32 bigint_bitlen(const u32 bn[], const u32 max_len);

/**
 * \brief Removes specified number of lsb's (bits) from a bigint.
 *
 * \param bn Input number
 *
 * \param max_len length of the bn array in words.
 *
 * \param nbits number of bits to drop
 *
 * \return Returns EFTOK on success, returns error code on failure
 */
fterr bigint_drop_nbits(u32 bn[], const u32 max_len, u32 nbits);

/**
 * \brief Update the length of a bigint based on actual value
 *
 * \param bn Input number
 *
 * \param max_len length of the bn array in words.
 *
 */
void bigint_adjust_len(u32 bn[], const u32 max_len);

/**
 * \brief Return the byte length of a bigint number
 *
 * \param bn Input number
 *
 * \param max_len length of the bn array in words.
 *
 */
u32 bigint_bytelen(const u32 bn[], const u32 max_len);

#endif
