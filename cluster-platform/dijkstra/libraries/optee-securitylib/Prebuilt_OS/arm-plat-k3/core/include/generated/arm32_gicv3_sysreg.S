# Automatically generated, do not edit
# Based on register description in
# ARM Generic Interrupt Controller
# Architecture Specification
# GIC architecture version 3.0 and version 4.0
# Table 8-7 Mapping of MCR and MRC to physical and virtual CPU interface registers, AArch32 state

	.macro read_icc_ap0r0 reg
	mrc p15, 0, \reg, c12, c8, 4
	.endm

	.macro write_icc_ap0r0 reg
	mcr p15, 0, \reg, c12, c8, 4
	.endm

	.macro read_icc_ap0r1 reg
	mrc p15, 0, \reg, c12, c8, 5
	.endm

	.macro write_icc_ap0r1 reg
	mcr p15, 0, \reg, c12, c8, 5
	.endm

	.macro read_icc_ap0r2 reg
	mrc p15, 0, \reg, c12, c8, 6
	.endm

	.macro write_icc_ap0r2 reg
	mcr p15, 0, \reg, c12, c8, 6
	.endm

	.macro read_icc_ap0r3 reg
	mrc p15, 0, \reg, c12, c8, 7
	.endm

	.macro write_icc_ap0r3 reg
	mcr p15, 0, \reg, c12, c8, 7
	.endm

	.macro read_icc_ap1r0 reg
	mrc p15, 0, \reg, c12, c9, 0
	.endm

	.macro write_icc_ap1r0 reg
	mcr p15, 0, \reg, c12, c9, 0
	.endm

	.macro read_icc_ap1r1 reg
	mrc p15, 0, \reg, c12, c9, 1
	.endm

	.macro write_icc_ap1r1 reg
	mcr p15, 0, \reg, c12, c9, 1
	.endm

	.macro read_icc_ap1r2 reg
	mrc p15, 0, \reg, c12, c9, 2
	.endm

	.macro write_icc_ap1r2 reg
	mcr p15, 0, \reg, c12, c9, 2
	.endm

	.macro read_icc_ap1r3 reg
	mrc p15, 0, \reg, c12, c9, 3
	.endm

	.macro write_icc_ap1r3 reg
	mcr p15, 0, \reg, c12, c9, 3
	.endm

	.macro write_icc_asgi1r reg0, reg1
	mcrr	p15, 1, \reg0, \reg1, c12
	.endm

	.macro read_icc_bpr0 reg
	mrc p15, 0, \reg, c12, c8, 3
	.endm

	.macro write_icc_bpr0 reg
	mcr p15, 0, \reg, c12, c8, 3
	.endm

	.macro read_icc_bpr1 reg
	mrc p15, 0, \reg, c12, c12, 3
	.endm

	.macro write_icc_bpr1 reg
	mcr p15, 0, \reg, c12, c12, 3
	.endm

	.macro read_icc_ctlr reg
	mrc p15, 0, \reg, c12, c12, 4
	.endm

	.macro write_icc_ctlr reg
	mcr p15, 0, \reg, c12, c12, 4
	.endm

	.macro write_icc_dir reg
	mcr p15, 0, \reg, c12, c11, 1
	.endm

	.macro write_icc_eoir0 reg
	mcr p15, 0, \reg, c12, c8, 1
	.endm

	.macro write_icc_eoir1 reg
	mcr p15, 0, \reg, c12, c12, 1
	.endm

	.macro read_icc_hppir0 reg
	mrc p15, 0, \reg, c12, c8, 2
	.endm

	.macro read_icc_hppir1 reg
	mrc p15, 0, \reg, c12, c12, 2
	.endm

	.macro read_icc_hsre reg
	mrc p15, 4, \reg, c12, c9, 5
	.endm

	.macro write_icc_hsre reg
	mcr p15, 4, \reg, c12, c9, 5
	.endm

	.macro read_icc_iar0 reg
	mrc p15, 0, \reg, c12, c8, 0
	.endm

	.macro read_icc_iar1 reg
	mrc p15, 0, \reg, c12, c12, 0
	.endm

	.macro read_icc_igrpen0 reg
	mrc p15, 0, \reg, c12, c12, 6
	.endm

	.macro write_icc_igrpen0 reg
	mcr p15, 0, \reg, c12, c12, 6
	.endm

	.macro read_icc_igrpen1 reg
	mrc p15, 0, \reg, c12, c12, 7
	.endm

	.macro write_icc_igrpen1 reg
	mcr p15, 0, \reg, c12, c12, 7
	.endm

	.macro read_icc_mctlr reg
	mrc p15, 6, \reg, c12, c12, 4
	.endm

	.macro write_icc_mctlr reg
	mcr p15, 6, \reg, c12, c12, 4
	.endm

	.macro read_icc_mgrpen1 reg
	mrc p15, 6, \reg, c12, c12, 7
	.endm

	.macro write_icc_mgrpen1 reg
	mcr p15, 6, \reg, c12, c12, 7
	.endm

	.macro read_icc_msre reg
	mrc p15, 6, \reg, c12, c12, 5
	.endm

	.macro write_icc_msre reg
	mcr p15, 6, \reg, c12, c12, 5
	.endm

	.macro read_icc_pmr reg
	mrc p15, 0, \reg, c4, c6, 0
	.endm

	.macro write_icc_pmr reg
	mcr p15, 0, \reg, c4, c6, 0
	.endm

	.macro read_icc_rpr reg
	mrc p15, 0, \reg, c12, c11, 3
	.endm

	.macro write_icc_sgi0r reg0, reg1
	mcrr	p15, 2, \reg0, \reg1, c12
	.endm

	.macro write_icc_sgi1r reg0, reg1
	mcrr	p15, 0, \reg0, \reg1, c12
	.endm

	.macro read_icc_sre reg
	mrc p15, 0, \reg, c12, c12, 5
	.endm

	.macro write_icc_sre reg
	mcr p15, 0, \reg, c12, c12, 5
	.endm
