/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef _LIBUTI_SIF_H
#define _LIBUTI_SIF_H

 
/* ---------- DLD symbol ---------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "CMN_TYPES_common.h"
#include "LIBUTI_SHA.h"
/* ---------- provided define constants: ------------------------------------ */
#define K_LIBUTI_SIF_MAX_HEADER_SIZE 0x2000
#define K_LIBUTI_SIF_MAX_NAME_LENGTH 256

/* ---------- provided macros: ---------------------------------------------- */

/* ---------- provided types: ----------------------------------------------- */

/* Add hash algorithms as they are implemented */
typedef union
{
   ts_LIBUTI_SHA_SHA256 sha256;
   ts_LIBUTI_SHA_SHA512 sha512;
   uint8_t data[64];
}
tu_LIBUTI_SIF_hash;

typedef enum
{
   E_LIBUTI_SIF_SUCCESS = 1,
   E_LIBUTI_SIF_FAILURE = 0
}
TE_LIBUTI_SIF_status;

typedef enum
{
   E_LIBUTI_SIF_CHECK_ALGORITHM_MD5         = 4,
   E_LIBUTI_SIF_CHECK_ALGORITHM_SHA1        = 5,
   E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256    = 6,
   E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512    = 7,
   E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_256    = 9,
   E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_512    = 10,
   E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256 = 11,
   E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_512 = 12,
   E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2S_256 = 13
}
TE_LIBUTI_SIF_check_algorithm;

typedef struct
{
   uint16_t Length;
   uint8_t Name[K_LIBUTI_SIF_MAX_NAME_LENGTH];
} TS_LIBUTI_SIF_Name_WithLength;

typedef struct
{
   TS_LIBUTI_SIF_Name_WithLength PN;
   TS_LIBUTI_SIF_Name_WithLength Name;
}
ts_LIBUTI_SIF_software_info;

typedef struct
{
   TS_LIBUTI_SIF_Name_WithLength hardware_identifier;
   TS_LIBUTI_SIF_Name_WithLength Name;
}
ts_LIBUTI_SIF_target;

typedef struct
{
   TS_LIBUTI_SIF_Name_WithLength Name;
   TS_LIBUTI_SIF_Name_WithLength Version;
}
ts_LIBUTI_SIF_tool_info;

typedef struct
{
   uint8_t DateTime[14];
   TS_LIBUTI_SIF_Name_WithLength Name;
}
ts_LIBUTI_SIF_requester_info;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

/* Basic getters */
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_software_info( const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_software_info * const SoftwareInfo);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_tool_chars( const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_tool_info * const ToolInfo);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_requester_info( const uint8_t *DecodedHeaderAddress, ts_LIBUTI_SIF_requester_info * const RequesterInfo);
/* complex getters */
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_hash( const uint8_t * const DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength, const TE_LIBUTI_SIF_check_algorithm algo, tu_LIBUTI_SIF_hash * const hash_buffer);
extern TE_LIBUTI_SIF_status LIBUTI_SIF_get_SHA2_256( const uint8_t * DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength, ts_LIBUTI_SHA_SHA256 * const p_out );
extern te_CMN_FLAG_QUESTION LIBUTI_SIF_has_target( const uint8_t * DecodedHeaderAddress, const uint8_t * TargetName, const uint32_t TargetNameLength, const uint8_t * HardwareID, const uint32_t HardwareIDLength );
extern te_CMN_FLAG_QUESTION LIBUTI_SIF_has_file( const uint8_t * DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength );
extern uint16_t LIBUTI_SIF_file_count( const uint8_t * DecodedHeaderAddress );
extern te_CMN_FLAG_QUESTION LIBUTI_SIF_has_hashmode( const uint8_t * DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength, TE_LIBUTI_SIF_check_algorithm * hashmode );

#endif /* _LIBUTI_SIF_H_ */
