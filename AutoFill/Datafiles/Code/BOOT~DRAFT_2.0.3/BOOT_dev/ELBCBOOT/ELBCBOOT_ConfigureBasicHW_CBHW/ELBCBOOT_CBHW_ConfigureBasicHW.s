	.file "ELBCBOOT_CBHW_ConfigureBasicHW.s"
	.include "ELBCBOOT_Registers.inc"

	.global ELBCBOOT_CBHW_ConfigureBasicHW

ELBCBOOT_CBHW_ConfigureBasicHW:
	
; Set HID0 default value
	lis     r3, C_HID0_INIT_VALUE@ha
	addi    r3, r3, C_HID0_INIT_VALUE@l
	mtspr   REG_HID0, r3
	
	blr
