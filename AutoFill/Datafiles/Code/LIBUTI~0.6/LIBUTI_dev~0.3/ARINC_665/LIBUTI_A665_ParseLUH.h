#ifndef LIBUTI_A665_PARSELUH_H
#define LIBUTI_A665_PARSELUH_H

#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/
#define C_LUH_MIN_SIZE 42ul

#ifndef A665_ADDR_ALIGN
#define A665_ADDR_ALIGN 1ul
#endif

#if defined(__RTRT__)
#define __attribute__(x_dummy)
#endif

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