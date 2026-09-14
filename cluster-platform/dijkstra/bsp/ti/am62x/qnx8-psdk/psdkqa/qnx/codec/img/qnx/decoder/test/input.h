/*
 * Copyright 2022, QNX Software Systems.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject
 * to the following conditions:
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

#ifndef VXDDEC_TEST_INPUT
#define VXDDEC_TEST_INPUT

#include <pthread.h>


#define CONFIG_DATA_BUFFER_SIZE 8096

typedef struct input_handle_s {
    int m_fd;
    int m_queueSize;
    uint8_t *m_inputBuffer;
    uint8_t *m_currPtr;
    int32_t m_inputDataSize;
    bool    m_EOF;

    uint32_t mWidth;
    uint32_t mHeight;
    uint32_t mFrameRate;
    uint8_t  mpConfig[CONFIG_DATA_BUFFER_SIZE];
    uint32_t mConfigSize;
} input_handle_t;

input_handle_t *createInput(const char* path);
void destroyInput(input_handle_t *ihdl);
int32_t readFrame(input_handle_t *ihdl, void *oBuf, uint32_t *oSize);

#endif //VXDDEC_TEST_INPUT
