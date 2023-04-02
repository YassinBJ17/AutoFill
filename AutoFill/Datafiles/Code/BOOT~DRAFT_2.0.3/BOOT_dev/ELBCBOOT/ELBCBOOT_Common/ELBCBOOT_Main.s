	.file "ELBCBOOT_Main.s"

	.text

	.global ELBCBOOT_Main

ELBCBOOT_Main:
	; Configure and open TLB
	bl REG_Init

	; Configure basic hardware
	bl ELBCBOOT_CBHW_ConfigureBasicHW
	bl ELBCBOOT_CBHW_ConfigureDDR
	bl ELBCBOOT_CBHW_ConfigureL2Cache
	bl ELBCBOOT_CBHW_ConfigureLAW

	; Jump to RAMBOOT software address
	b ELBCBOOT_CopyAndBootRamBoot
	