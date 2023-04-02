/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_COMMON.h"
/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation: ------------------------------------ */

te_CMN_FLAG_QUESTION LIBUTI_CMN_TestSupportFile
(
/*IN*/
   const uint32_t FileNameLengthBuffer, 
   uint8_t * const FileNameAddressBuffer,
   const TS_FileInfo * const SupportFilesInfo,
   const uint8_t FileExtensionBuffer[4],
/*OUT*/
   te_CMN_FLAG_QUESTION * const FileFound,
   const TS_FileInfo** const FileInfo,
   te_CMN_FLAG_QUESTION * const OutOfOperationalConditionLoad
);
