/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Buffer variables definition
 *
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_private.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */

uint8_t * LUH_Buffer;
uint8_t * SIF_HeaderBuffer;
uint8_t * FlashIntegrityCheckLUP_Buffer;
uint8_t * AES_KeyBuffer;
uint8_t * AES_MaskBuffer;

#pragma section SECTION_ARINC_665_FILES_INFO_BUFFER "" ".BOOT_ARINC_665_FILES_INFO_BUFFER"
#pragma use_section SECTION_ARINC_665_FILES_INFO_BUFFER ARINC_665_FilesInfoBuffer
TS_ARINC_665_FileInfo ARINC_665_FilesInfoBuffer[K_MAX_NUMBER_OF_FILES];

#pragma section SECTION_FILES_INFO_BUFFER "" ".BOOT_FILES_INFO_BUFFER"
#pragma use_section SECTION_FILES_INFO_BUFFER FilesInfoBuffer
TS_FileInfo FilesInfoBuffer[K_MAX_NUMBER_OF_FILES];
