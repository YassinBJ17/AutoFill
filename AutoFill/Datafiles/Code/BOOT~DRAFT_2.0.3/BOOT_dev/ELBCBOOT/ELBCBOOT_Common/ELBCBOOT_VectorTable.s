	.file "ELBCBOOT_VectorTable.s"

	.global IVOR_Handler
	.global VECT_Reset

; PowerPC Vector table definition
	.section ".VectorTable", 4, rx
IVOR_Handler:
	b IVOR_Handler
	rfi

	.section ".Reset", 4, rx
VECT_Reset:
	b ELBCBOOT_Main