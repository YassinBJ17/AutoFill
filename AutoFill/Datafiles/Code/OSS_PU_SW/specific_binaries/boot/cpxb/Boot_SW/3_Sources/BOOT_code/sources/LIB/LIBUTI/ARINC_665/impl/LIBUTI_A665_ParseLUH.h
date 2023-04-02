/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef LIBUTI_A665_PARSELUH_H
#define LIBUTI_A665_PARSELUH_H

#include "CMN_TYPES_common.h"

/*==== Definitions =====================================================================*/
#define K_LUH_MIN_SIZE (uint32_t)42

/*
#ifndef A665_ADDR_ALIGN
#define A665_ADDR_ALIGN (uint32_t)1
#endif
*/
typedef struct {
   uint32_t s_HeaderFileLength;
   uint16_t s_LoadFileFormatVersion;
   uint16_t s_PartFlags;
   /* For PART3, the pointer point to the Load PN length */
   uint32_t s_PointerToLoadPN;
   uint32_t s_PointerToTargetHW_ID_List;
   uint32_t s_PointerToDataFilesList;
   uint32_t s_PointerToSupportFilesList;
   uint32_t s_PointerToUserDefinedData;
#ifdef A665_PART3
   uint32_t s_PointerToLoadTypeDescriptionLength;
   uint32_t s_PointerToTargetHW_ID_withPositions_List;
   uint32_t s_PointerToLoadCheckValueLength;
#endif
}
__attribute__((packed)) TS_LUH_ConstantSizeFirstFields;

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/*==== END =============================================================================*/
#endif
