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

/* System libraries */
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>
#include <termios.h>
#include <pthread.h>
#include <stdbool.h>
#include <inttypes.h>
#include <getopt.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <sys/siginfo.h>
#include <sys/neutrino.h>
#include <screen/screen.h>
#include <queue>
#include <iostream>
#include <sys/procmgr.h>

#include "omxil.h"
#include "log.h"


using namespace std;

int g_log_lvl = 0;
bool user_request_exit;

void LOG(int lvl, const char *fmt, ...)
{
    va_list arglist;
    va_start(arglist, fmt);
    if (lvl <= g_log_lvl) {
        vfprintf(stderr, fmt, arglist);
        fprintf(stderr, "\n");
        fflush(stderr);
    }
    va_end(arglist);
}

void print_usage_and_exit(const char *argv0)
{
    printf("Usage: %s [options] [input (absolute path)]\n"
           "  Command line options:\n"
           "    -i: input file\n"
           "    -o: output file\n"
           "    -f: frame rate between 1 and 240(default 30)\n"
           "    -d: x,y,width,height : set display area\n"
           "    -N: Number of input buffers, between 2 and 64(default 3)\n"
           "    -M: Number of output buffers, between 3 and 64(default 10)\n"
           "    -v: increase verbosity, max 7\n"
           "    -p: log file for decoding performance\n"
           "\n"
           , argv0);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    std::unique_ptr<OmxilVideoDec> decH;
    const char *outputpath = NULL;
    const char *inputpath = NULL;
    const char *logpath = NULL;
    int ninputbuf = VDEC_INPUT_BUFFER_NUM;
    int noutputbuf = VDEC_OUTPUT_BUFFER_NUM;
    int x=0,y=0,w=0,h=0;
    int framerate = 0;
    struct termios orig_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);

    if (argc < 1) {
        print_usage_and_exit(argv[0]);
    }

    int opt;
    while ((opt = getopt(argc, argv, "i:o:f:d:N:M:vp:")) != -1) {
        switch (opt) {
        case 'i':
            inputpath = optarg;
            break;
        case 'o':
            outputpath = optarg;
            break;
        case 'f':
            framerate = atoi(optarg);
            if(framerate <=0  || framerate > 240)
                print_usage_and_exit(argv[0]);
            break;
        case 'd':
            if (sscanf(optarg, "%d,%d,%d,%d", &x, &y, &w,&h) != 4) {
                print_usage_and_exit(argv[0]);
            }
            LOG(LOG_INFO, "Display area set - x: %d, y: %d, width: %d, heith: %d", x, y, w, h);
            break;
        case 'N':
            ninputbuf = atoi(optarg);
            if(ninputbuf < 2 || ninputbuf > 64)
                print_usage_and_exit(argv[0]);
            break;
        case 'M':
            noutputbuf = atoi(optarg);
            if(noutputbuf < 3 || noutputbuf > 64)
                print_usage_and_exit(argv[0]);
            break;
        case 'v':
            g_log_lvl++;
            break;
        case 'p':
            logpath = optarg;
            break;
        default:
            print_usage_and_exit(argv[0]);
        }
    }

    if (inputpath == NULL) {
        print_usage_and_exit(argv[0]);
    }

    LOG(LOG_DEBUG2,"Input file path %s", inputpath);

    if (procmgr_ability(0,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_KEYDATA,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_IO,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_MEM_PHYS,
                        PROCMGR_AOP_ALLOW | PROCMGR_ADN_NONROOT | PROCMGR_AID_PRIORITY,
                        PROCMGR_AOP_DENY  | PROCMGR_ADN_NONROOT | PROCMGR_AOP_LOCK      | PROCMGR_AID_EOL)
        != EOK) {
        LOG(LOG_ERROR, "Unable to gain procmgr abilities for nonroot operation.");
        return 0;
    }

    ThreadCtl( _NTO_TCTL_IO, 0);

    try {
        decH = std::unique_ptr<OmxilVideoDec>(new OmxilVideoDec(inputpath, outputpath, ninputbuf, noutputbuf));
    }
    catch (const std::exception &e) {
        printf("%s\n", e.what());
        exit(EXIT_FAILURE);
    }

    if(x >= 0 && y >= 0 && w > 0 && h > 0) {
        if(decH->SetDisplayArea(x,y,w,h) != OMX_ErrorNone) {
            LOG(LOG_WARNING, "Failed to set display area(%ld,%ld,%ld,%ld).", x, y, w, h);
        }
    }

    if(framerate > 0) {
        decH->SetFrameRate(framerate);
    }

    if(logpath != NULL) {
        if((decH->SetLogPath(logpath)) == -1)
            LOG(LOG_WARNING, "Failed to set log path(%s).", logpath);
    }

    if(decH->StartVdec() != OMX_ErrorNone) {
        printf("StartVdec failed\n");
        exit(EXIT_FAILURE);
    }

    /* Modifying terminal to allow key-press interaction */
    struct termios new_termios;
    new_termios = orig_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO | ECHOCTL | ECHONL);
    new_termios.c_cflag |= HUPCL;
    new_termios.c_cc[VMIN] = 0;
    new_termios.c_cc[VTIME] = 10;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);

    printf("Press 'q' to quit.\n");

    for (;;) {
        if (decH->GetBailReason() != BAIL_NOT_BAILED || user_request_exit) {
            LOG(LOG_ERROR,"bailed: %d", __LINE__);
            break;
        }
        char ch[8];
        int chnum = 0;

        chnum = read(STDIN_FILENO, ch, 8);
        if (chnum == 1) {
            switch (ch[0]) {
                case 'q':
                case 'Q':
                    user_request_exit = true;
                    LOG(LOG_INFO,"bailed at user request: %d", __LINE__);
                    break;
                default:
                    printf("Unkown command [%x], valid commands are :\n"
                            "-----------------------------------------\n"
                            " q : stop playback and quit program.\n"
                            "-----------------------------------------\n",
                            ch[0]);
            }
        }
        else if (chnum == 0) {
            continue;
        }

    }

    /* Restore the terminal to its original state */
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);

    if (decH) {
        if(decH->GetBailReason() == BAIL_EOS)
            printf("Decoding finished, exiting.\n");
        else if(decH->GetBailReason() == BAIL_ERROR)
            printf("Error happened, exiting.\n");
    }

    return 0;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/multimedia/branches/7.1.0/lib/mmedia/codecs/OpenMAXIL/test/dec/main.cpp $ $Rev: 937590 $")
#endif
