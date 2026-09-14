;*
;* DMSC firmware - Low Level ARM IRQ functions
;*
;* Cortex-M3 (CM3) firmware for power management
;*
;* Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
;*
;* This software is licensed under the standard terms and conditions in the
;* Texas Instruments Incorporated Technology and Software Publicly
;* Available Software License Agreement, a copy of which is included in
;* the software download.
;*

	.global arch_local_irq_save
	.global arch_local_irq_restore
	.global get_current_interrupt
	.global unmask_interrupts
	.global mask_interrupts

	.text

;*
;* unsigned long arch_local_irq_save(void)
;*
;* Saves the current interrupt state and then disables interrupts.
;*
;* Returns: Value of primask before disabling interrupts
;*

arch_local_irq_save: .asmfunc
	mrs	r0, primask
	cpsid	i
	mov	pc, lr
	.endasmfunc

;*
;* void arch_local_irq_restore(unsigned long flags)
;*
;* flags (r0) - State of interrupts from arch_local_irq_save;
;*
;* Restores interrupts to the state passed in flags.
;*

arch_local_irq_restore: .asmfunc
	msr	primask, r0
	mov	pc, lr
	.endasmfunc

;*
;* unsigned int get_current_interrupt(void)
;*
;* Get the curently processing interrupt number
;*
;* Returns: Current interrupt number
;*

get_current_interrupt: .asmfunc
	mrs	r0, ipsr
	mov	r1, #0x1FF
	and	r0, r1
	mov	pc, lr
	.endasmfunc

;*
;* void unmask_interrupts(void)
;*
;* Enables interrupts for the ARM core.
;*

unmask_interrupts: .asmfunc
	cpsie	i
	mov	pc, lr
	.endasmfunc

;*
;* void unmask_interrupts(void)
;*
;* Enables interrupts for the ARM core.
;*

mask_interrupts: .asmfunc
	cpsid	i
	mov	pc, lr
	.endasmfunc
