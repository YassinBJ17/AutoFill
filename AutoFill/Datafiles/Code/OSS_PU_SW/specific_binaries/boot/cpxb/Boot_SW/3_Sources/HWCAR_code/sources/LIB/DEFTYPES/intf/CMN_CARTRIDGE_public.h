#ifndef CMN_CARTRIDGE_public_H
#define CMN_CARTRIDGE_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
#define HEADER_REFERENCE_HW_SIZE        (uint32_t) (16)
#define HEADER_HW_CAR_CM_VERSION_SIZE   (uint32_t) (12)
#define HEADER_HW_CAR_AMENDMENT_SIZE    (uint32_t) (8)
#define HEADER_HW_CAR_SPARE1_SIZE       (uint32_t) (84)
#define HEADER_PART_NUMBER_MB_SIZE      (uint32_t) (16)
#define HEADER_HW_PART_NUMBER_SIZE      (uint32_t) (16)
#define HEADER_SYSTEM_ID_SIZE           (uint32_t) (12)
#define HEADER_SUB_SYSTEM_ID_SIZE       (uint32_t) (12)
#define HEADER_REFERENCE_SIZE           (uint32_t) (16)
#define HEADER_CM_VERSION_SIZE          (uint32_t) (8)
#define HEADER_SW_VER_SIZE              (uint32_t) (16)
#define HEADER_PROJECT_CODE_SIZE        (uint32_t) (8)
#define HEADER_SPARE_SIZE               (uint32_t) (96)
#define HEADER_PART_NUMBER_SIZE         (uint32_t) (16)

/* ---------- external types: ----------------------------------------------- */
typedef struct
{
   uint32_t s_entry_point;

   uint32_t s_crc_32 ;
   uint32_t s_crc_32_cplt ;
   uint32_t s_checksum_32 ;
   uint32_t s_checksum_32_cplt ;

   uint32_t s_start_code;
   uint32_t s_end_code;

   uint8_t  s_tab_project_code[HEADER_PROJECT_CODE_SIZE];
   uint8_t  s_tab_software_code[HEADER_PROJECT_CODE_SIZE];
   uint8_t  s_tab_software_version[HEADER_SW_VER_SIZE];

   uint8_t  s_pn [HEADER_PART_NUMBER_SIZE];
} ts_SAFRAN_HEADER;


typedef PACKED_U08 struct
{
   ts_SAFRAN_HEADER s_header;
   uint8_t s_amendment [HEADER_HW_CAR_AMENDMENT_SIZE];

} ts_SAFRAN_HW_HEADER;

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* none */



/* ---------- external constants: ------------------------------------------- */
extern const ts_SAFRAN_HW_HEADER HWCAR_HEADER ;

/* ---------- provided operations: ------------------------------------------- */
/* none */



#endif /* CMN_CARTRIDGE_public_H */
