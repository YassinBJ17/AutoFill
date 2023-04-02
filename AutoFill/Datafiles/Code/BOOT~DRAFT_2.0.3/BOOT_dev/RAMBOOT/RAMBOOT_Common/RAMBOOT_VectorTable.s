	.file "RAMBOOT_VectorTable.s"

	.include "RAMBOOT_VectorTable.inc"

; Define Small Const Area (SDA2) begin address
	.extern _SDA2_BASE_

; Define Small Data Area (SDA) begin for SDATA & SBSS address
	.extern _SDA_BASE_

; Define stack pointer address
	.extern __SP_INIT

	.global IVOR_Handler
	.global VECT_Reset

; PowerPC Vector table definition
	.section ".VectorTable", 4, rx
IVOR_Handler:
	b RAMBOOT_FailMode
	rfi

	.section ".Reset", 4, rx
VECT_Reset:

	;Configure basic hardware for the tests
	bl RAMBOOT_TestAndConfigureBasicHW
	bl RAMBOOT_ConfigureELBC

	;Check and Load BOOT soft
	bl RAMBOOT_PostTCBHW_Main
	rfi