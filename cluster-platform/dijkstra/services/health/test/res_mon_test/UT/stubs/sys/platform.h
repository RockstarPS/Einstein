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

/*
 *  The only symbols made visible by this header are
 *  OS/compiler reserved symbols.
 */

#ifndef __PLATFORM_H_INCLUDED
#define __PLATFORM_H_INCLUDED


/* Ability definitions */
#define	PROCMGR_AID_SPAWN_SETUID		0u		/* SR: uid */
#define	PROCMGR_AID_SPAWN_SETGID		1u		/* SR: gid */
#define	PROCMGR_AID_SETUID				2u		/* SR: uid */
#define	PROCMGR_AID_SETGID				3u		/* SR: gid */
#define	PROCMGR_AID_GETID				4u		/* SR: none */
#define PROCMGR_AID_PATHSPACE			5u		/* SR: none */
#define PROCMGR_AID_REBOOT				6u		/* SR: none */
#define PROCMGR_AID_CPUMODE				7u		/* SR: mode */
#define PROCMGR_AID_RUNSTATE			8u		/* SR: cpu */
#define PROCMGR_AID_CONFSET				9u		/* SR: name */
#define PROCMGR_AID_RSRCDBMGR			10u		/* SR: none */
#define PROCMGR_AID_SESSION				11u		/* SR: sid */
#define PROCMGR_AID_UMASK				12u		/* SR: none */
#define PROCMGR_AID_EVENT				13u		/* SR: trigger bits */
#define PROCMGR_AID_RLIMIT				14u		/* SR: limit */
#define PROCMGR_AID_MEM_ADD				15u		/* SR: paddr */
#define PROCMGR_AID_MEM_PHYS			16u		/* SR: paddr */
#define PROCMGR_AID_MEM_SPECIAL			17u		/* SR: none */
#define PROCMGR_AID_MEM_GLOBAL			18u		/* SR: none */
#define PROCMGR_AID_MEM_PEER			19u		/* SR: pid */
#define PROCMGR_AID_MEM_LOCK			20u		/* SR: vaddr */
#define PROCMGR_AID_SPAWN				21u		/* SR: none */
#define PROCMGR_AID_FORK				22u		/* SR: none */
#define PROCMGR_AID_PROT_EXEC			23u		/* SR: vaddr */
#define PROCMGR_AID_WAIT				24u		/* SR: pid */
#define PROCMGR_AID_V86					25u		/* SR: none */
#define PROCMGR_AID_QNET				26u		/* SR: none */
#define PROCMGR_AID_CLOCKSET			27u		/* SR: time */
#define PROCMGR_AID_CLOCKPERIOD			28u		/* SR: period */
#define PROCMGR_AID_INTERRUPT			29u		/* SR: interrupt */
#define PROCMGR_AID_KEYDATA				30u		/* SR: none */
#define PROCMGR_AID_IO					31u		/* SR: level */
#define PROCMGR_AID_TRACE				32u		/* SR: none */
#define PROCMGR_AID_PRIORITY			33u		/* SR: priority */
#define PROCMGR_AID_CONNECTION			34u		/* SR: none */
#define PROCMGR_AID_SCHEDULE			35u		/* SR: none */
#define PROCMGR_AID_SIGNAL				36u		/* SR: signal */
#define PROCMGR_AID_TIMER				37u		/* SR: timerid */
#define PROCMGR_AID_PGRP				38u		/* SR: pgid */
#define PROCMGR_AID_MAP_FIXED			39u		/* SR: vaddr */
#define PROCMGR_AID_PATH_TRUST			40u		/* SR: none */
#define PROCMGR_AID_SWAP				41u		/* SR: none */
#define PROCMGR_AID_RCONSTRAINT			42u		/* SR: none */
#define PROCMGR_AID_CHILD_NEWAPP		43u		/* SR: none */
#define PROCMGR_AID_PUBLIC_CHANNEL		44u		/* SR: none */
#define PROCMGR_AID_APS_ROOT			45u		/* SR: none */
#define PROCMGR_AID_ABLE_CREATE			46u		/* SR: none */
#define PROCMGR_AID_RUNSTATE_BURST		47u		/* SR: length */
#define PROCMGR_AID_DEFAULT_TIMER_TOLERANCE		48u		/* SR: none */
#define PROCMGR_AID_XTHREAD_THREADCTL	49u		/* SR: subcommand */
#define PROCMGR_AID_XPROCESS_QUERY		50u		/* SR: euid */
#define PROCMGR_AID_CHROOT				51u		/* SR: none */
#define PROCMGR_AID_POWER				52u		/* SR: none */
#define PROCMGR_AID_PROT_WRITE_AND_EXEC	53u		/* SR: vaddr */
#define PROCMGR_AID_SRANDOM				54u		/* SR: none */
#define PROCMGR_AID_SANDBOX				55u		/* SR: none */
#define PROCMGR_AID_QVM					56u		/* SR: none */
#define PROCMGR_AID_RLIMIT_PEER				57u		/* SR: uid */
#define PROCMGR_AID_CHANNEL_CONNECT		58u		/* SR: type id */
#define PROCMGR_AID_MAC_POLICY			59u		/* SR: none */
#define PROCMGR_AID_SETTYPEID		    60u		/* SR: type id */
#define PROCMGR_AID_ABLE_PRIV		    61u		/* SR: none */
#define PROCMGR_AID_XPROCESS_ABLE		62u		/* SR: none */
#define PROCMGR_AID_INTERRUPTEVENT		63u		/* SR: interrupt */
#define PROCMGR_AID_XPROCESS_DEBUG		64u		/* SR: uid */
#define PROCMGR_AID_XPROCESS_MEM_READ	65u		/* SR: uid */
#define PROCMGR_AID_HIGH_RESOLUTION_TIMER		66u		/* SR: none */
#define PROCMGR_AID_SERVER_MONITOR      68u		/* SR: none */
#define PROCMGR_AID_SIGEV_THREAD		69u		/* SR: none */
#define PROCMGR_AID_PRIVREG			70u		/* SR: none */
#define PROCMGR_AID_MAX					PROCMGR_AID_PRIVREG

#define PROCMGR_AID_MASK				0xffffu
#define PROCMGR_AID_EOL					PROCMGR_AID_MASK
#define PROCMGR_AID_UNCREATED			0x00100000u

#define PROCMGR_AOP_DENY				0x00010000u
#define PROCMGR_AOP_ALLOW				0x00020000u
#define PROCMGR_AOP_SUBRANGE			0x00040000u
#define PROCMGR_AOP_LOCK				0x00080000u
#define PROCMGR_AOP_INHERIT_YES			0x00400000u
#define PROCMGR_AOP_INHERIT_NO			0x00800000u

#define PROCMGR_ADN_ROOT				0x10000000u
#define PROCMGR_ADN_NONROOT				0x20000000u

#define __PROCMGR_AIN_SKIPSR			0x80000000u
#define __PROCMGR_AIN_NOSR				0x40000000u

#define ABLE_ALLOW_ROOT			0x0001u
#define ABLE_ALLOW_NONROOT		0x0002u
#define ABLE_NO_SUBRANGE		0x0004u
#define ABLE_ISOLATED			0x0008u

#if !defined(__FLEXARY)
	#define __FLEXARY(__type, __name) __type __name[1]
#endif

#endif


