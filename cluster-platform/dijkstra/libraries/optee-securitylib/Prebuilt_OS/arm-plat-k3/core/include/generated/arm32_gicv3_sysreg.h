/* Automatically generated, do not edit */
#ifndef __ARM32_GICV3_SYSREG_H
#define __ARM32_GICV3_SYSREG_H
#include <compiler.h>
/* Based on register description in */
/* ARM Generic Interrupt Controller */
/* Architecture Specification */
/* GIC architecture version 3.0 and version 4.0 */
/* Table 8-7 Mapping of MCR and MRC to physical and virtual CPU interface registers, AArch32 state */

static inline __noprof uint32_t read_icc_ap0r0(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 4" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap0r0(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c8, 4" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap0r1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 5" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap0r1(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c8, 5" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap0r2(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 6" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap0r2(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c8, 6" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap0r3(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 7" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap0r3(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c8, 7" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap1r0(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c9, 0" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap1r0(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c9, 0" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap1r1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c9, 1" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap1r1(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c9, 1" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap1r2(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c9, 2" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap1r2(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c9, 2" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ap1r3(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c9, 3" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ap1r3(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c9, 3" : : "r"  (v));
}

static inline __noprof void write_icc_asgi1r(uint64_t v)
{
	asm volatile ("mcrr p15, 1, %Q0, %R0, c12" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_bpr0(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 3" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_bpr0(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c8, 3" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_bpr1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 3" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_bpr1(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c12, 3" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_ctlr(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 4" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_ctlr(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c12, 4" : : "r"  (v));
}

static inline __noprof void write_icc_dir(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c11, 1" : : "r"  (v));
}

static inline __noprof void write_icc_eoir0(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c8, 1" : : "r"  (v));
}

static inline __noprof void write_icc_eoir1(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c12, 1" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_hppir0(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 2" : "=r"  (v));

	return v;
}

static inline __noprof uint32_t read_icc_hppir1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 2" : "=r"  (v));

	return v;
}

static inline __noprof uint32_t read_icc_hsre(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 4, %0, c12, c9, 5" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_hsre(uint32_t v)
{
	asm volatile ("mcr p15, 4, %0, c12, c9, 5" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_iar0(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c8, 0" : "=r"  (v));

	return v;
}

static inline __noprof uint32_t read_icc_iar1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 0" : "=r"  (v));

	return v;
}

static inline __noprof uint32_t read_icc_igrpen0(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 6" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_igrpen0(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c12, 6" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_igrpen1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 7" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_igrpen1(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c12, 7" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_mctlr(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 6, %0, c12, c12, 4" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_mctlr(uint32_t v)
{
	asm volatile ("mcr p15, 6, %0, c12, c12, 4" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_mgrpen1(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 6, %0, c12, c12, 7" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_mgrpen1(uint32_t v)
{
	asm volatile ("mcr p15, 6, %0, c12, c12, 7" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_msre(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 6, %0, c12, c12, 5" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_msre(uint32_t v)
{
	asm volatile ("mcr p15, 6, %0, c12, c12, 5" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_pmr(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c4, c6, 0" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_pmr(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c4, c6, 0" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_rpr(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c11, 3" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_sgi0r(uint64_t v)
{
	asm volatile ("mcrr p15, 2, %Q0, %R0, c12" : : "r"  (v));
}

static inline __noprof void write_icc_sgi1r(uint64_t v)
{
	asm volatile ("mcrr p15, 0, %Q0, %R0, c12" : : "r"  (v));
}

static inline __noprof uint32_t read_icc_sre(void)
{
	uint32_t v;

	asm volatile ("mrc p15, 0, %0, c12, c12, 5" : "=r"  (v));

	return v;
}

static inline __noprof void write_icc_sre(uint32_t v)
{
	asm volatile ("mcr p15, 0, %0, c12, c12, 5" : : "r"  (v));
}
#endif /*__ARM32_GICV3_SYSREG_H*/
