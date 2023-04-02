/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2022                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/


/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_COMMON.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation: ------------------------------------ */

boolean_t LIBUTI_CMN_TestSupportFile
(
/*IN*/
	const uint32_t FileNameLengthBuffer, 
	uint8_t* const FileNameAddressBuffer,
	const TS_FileInfo* const SupportFilesInfo,
	const uint8_t FileExtensionBuffer[4],
/*OUT*/
	boolean_t* const FileFound,
	const TS_FileInfo** const FileInfo,
	boolean_t* const OutOfOperationalConditionLoad
);
