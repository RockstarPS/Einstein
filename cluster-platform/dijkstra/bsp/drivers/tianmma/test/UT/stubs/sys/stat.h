/*
 * $QNXLicenseC:
 * Copyright 2007, 2009, QNX Software Systems. All Rights Reserved.
 *
 * You must obtain a written license from and pay applicable license fees to QNX
 * Software Systems before you may reproduce, modify or distribute this software,
 * or any work that includes all or part of this software.   Free development
 * licenses are available for evaluation and non-commercial purposes.  For more
 * information visit http://licensing.qnx.com or email licensing@qnx.com.
 *
 * This file may contain contributions from others.  Please review this entire
 * file for other proprietary rights or license notices, as well as the QNX
 * Development Suite License Guide at http://licensing.qnx.com/license-guide/
 * for other information.
 * $
 */

#ifndef __STAT_H_INCLUDED
#define __STAT_H_INCLUDED
#define __STAT_H_DECLARED

#ifndef __PLATFORM_H_INCLUDED
#include <sys/platform.h>
#endif



#define _S_IFMT     0xF000              /*  Type of file                    */
#define _S_IFIFO    0x1000              /*  FIFO                            */
#define _S_IFCHR    0x2000              /*  Character special               */
#define _S_IFDIR    0x4000              /*  Directory                       */
#define _S_IFNAM    0x5000              /*  Special named file              */
#define _S_IFBLK    0x6000              /*  Block special                   */
#define _S_IFREG    0x8000              /*  Regular                         */
#define _S_IFLNK    0xA000              /*  Symbolic link                   */
#define _S_IFSOCK   0xC000              /*  Socket                          */

#define _S_ACL_EXT  0x00010000          /*  Extended ACL(s) are in effect   */ 

#define S_ISFIFO(m) (((m)&_S_IFMT)==_S_IFIFO) /* Test for FIFO.             */
#define S_ISCHR(m)  (((m)&_S_IFMT)==_S_IFCHR) /* Test for char special file.*/
#define S_ISDIR(m)  (((m)&_S_IFMT)==_S_IFDIR) /* Test for directory file.   */
#define S_ISBLK(m)  (((m)&_S_IFMT)==_S_IFBLK) /* Test for block specl file. */
#define S_ISREG(m)  (((m)&_S_IFMT)==_S_IFREG) /* Test for regular file.     */

/*
 *  Common filetype macros
 */
# define S_IFMT      _S_IFMT            /*  Type of file                    */
# define S_IFIFO     _S_IFIFO           /*  FIFO                            */
# define S_IFCHR     _S_IFCHR           /*  Character special               */
# define S_IFDIR     _S_IFDIR           /*  Directory                       */
# define S_IFNAM     _S_IFNAM           /*  Special named file              */
# define S_IFBLK     _S_IFBLK           /*  Block special                   */
# define S_IFREG     _S_IFREG           /*  Regular                         */
# define S_IFLNK     _S_IFLNK           /*  Symbolic link                   */
# define S_IFSOCK    _S_IFSOCK          /*  Socket                          */



/*
 *  Owner permissions
 */
#define S_IRWXU     000700              /*  Read, write, execute/search     */
#define S_IRUSR     000400              /*  Read permission                 */
#define S_IWUSR     000200              /*  Write permission                */
#define S_IXUSR     000100              /*  Execute/search permission       */
#define S_IREAD     S_IRUSR             /*  Read permission                 */
#define S_IWRITE    S_IWUSR             /*  Write permission                */
#define S_IEXEC     S_IXUSR             /*  Execute/search permission       */

/*
 *  Group permissions
 */
#define S_IRWXG     000070              /*  Read, write, execute/search     */
#define S_IRGRP     000040              /*  Read permission                 */
#define S_IWGRP     000020              /*  Write permission                */
#define S_IXGRP     000010              /*  Execute/search permission       */

/*
 *  Other permissions
 */
#define S_IRWXO     000007              /*  Read, write, execute/search     */
#define S_IROTH     000004              /*  Read permission                 */
#define S_IWOTH     000002              /*  Write permission                */
#define S_IXOTH     000001              /*  Execute/search permission       */





#endif

