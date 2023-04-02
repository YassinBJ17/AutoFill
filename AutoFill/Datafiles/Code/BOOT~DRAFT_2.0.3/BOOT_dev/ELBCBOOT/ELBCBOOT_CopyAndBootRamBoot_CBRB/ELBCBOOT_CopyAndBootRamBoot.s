	.file "ELBCBOOT_CopyAndBootRamBoot.s"
	.include "ELBCBOOT_Registers.inc"

	.global ELBCBOOT_CopyAndBootRamBoot

	.set    C_RAMBOOT_ELBC_START    ,0xFFFF8000
	;.set    C_RAMBOOT_ELBC_START    ,0x20001000
	.set    C_RAMBOOT_ELBC_SIZE     ,0x7000

	.set    C_RAMBOOT_START         ,0x20010000
	.set    C_RAMBOOT_OFFSET        ,0x0010

ELBCBOOT_CopyAndBootRamBoot:
	lis     r3, C_RAMBOOT_START@ha
	addi    r3, r3, C_RAMBOOT_START@l
	lis     r4, C_RAMBOOT_ELBC_START@ha
	addi    r4, r4, C_RAMBOOT_ELBC_START@l
	li      r5, C_RAMBOOT_ELBC_SIZE
	bl ELBCBOOT_Memcpy

	li      r4, 0
	mtspr   REG_HID0, r4

	lis     r3, C_RAMBOOT_START@ha
	addi    r3, r3, C_RAMBOOT_START@l
	addi    r3, r3, C_RAMBOOT_OFFSET
	mtctr   r3
	bctrl

stall:
	b stall
