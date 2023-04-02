#ifndef HWCRC_HAL_PUBLIC_H
#define HWCRC_HAL_PUBLIC_H


/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : CHRONOS
 * CSU name :
 * %name: HWCRC_HAL_public.h %
 * %full_name: fadex#1/incl/HWCRC_HAL_public.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:55:04 CEST 2018
 *
 * Modification information:
 *   %derived_by: F605763 %
 *   %date_created:Thu May 12 18:18:31 CEST 2022 %
 * --------------------------------------------------------------------------
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */


/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "CMN_IOSP_common.h"


/* LPOS Public Interface */
/* none */


/* LPOS Private Interface */
/* none */


/* ---------- provided types: ----------------------------------------------- */


/* {{RELAX<SYNCHRONe_C_Code_8.17> : all definitions are given even if only a configuration is used.
 Reuse strategy.  */
/* */
typedef enum
{
   e_HWCRC_CRC_CCITT_POLY = 0,
   e_HWCRC_CRC32_POLY = 1,
   e_HWCRC_CRC8_POLY = 2
}
te_HWCRC_POLYG;


/* ---------- provided constants: ------------------------------------------- */
/* none */



/* ---------- provided data: ------------------------------------------------ */
/* none */


/* ---------- provided operations: ------------------------------------------ */


/* */
/* Used to init CRC */
extern void HWCRC_INIT( void );


/* */
/* Used to configure CRC */
extern void HWCRC_CFG ( te_HWCRC_POLYG const * const p_HWCRC_POLYG );


/* */
/* Used to compute CRC32 via HWCRC with no eDMA*/
extern void HWCRC_CRC32_COMPUTE (  uint32_t         const p_crc_start,
        uint32_t  const * const p_buf,
        uint32_t         const p_size,
        uint32_t       * const p_crc32 );

/* */
/* Used to compute CRC32 via HWCRC with eDMA*/
extern void HWCRC_DMA_CRC32_COMPUTE ( uint32_t       const p_crc_start,
		  CMN_IOSP_ID_t       const p_hwcrc_conf_id,
        CMN_SYSTEM_ADDR_t   const p_buff_addr,
        CMN_SYSTEM_SIZE_t   const p_buff_size,
        CMN_SYSTEM_SIZE_t * const p_written_size,
        uint32_t       * const p_crc32,
		uint8_t        const p_crc_tempo);

#endif /* HWCRC_HAL_PUBLIC_H */


