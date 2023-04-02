#ifndef HWCRC_REG_common_H
#define HWCRC_REG_common_H
/* --------------------------------------------------------------------------
 *                           Sagem Defense Securite
 *                               SAFRAN Group
 * --------------------------------------------------------------------------
 * PROJECT : F46
 * CSU name :
 * %name: HWCRC_REG_common.h %
 * %full_name: fadex#1/incl/HWCRC_REG_common.h/1 %
 *
 * Creation information:
 *   Created by: F073297
 *   Date : Thu May 31 09:54:58 CEST 2018
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

/* ---------- provided define constants: ------------------------------------ */
/* MPC577 HWCRC register address      */
#define HWCRC_0_BASE_ADDR   0xFFF64000          /* crc_0  */
#define HWCRC_1_BASE_ADDR   0xFBF64000          /* crc_1  */

/* ---------- provided types: ----------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_8.2,SYNCHRONe_C_Code_6.6, SYNCHRONe_C_Code_24.5, SYNCHRONe_C_Code_5.4> Register definition and it is compliant with the register template */
/* {{RELAX<SYNCHRONe_C_Code_8.17> All MPC5777M register are fully defined even if there are not used. */
/* {{RELAX<SYNCHRONe_C_Code_6.4> Bitfield used are for Register definition. Deviation is acceptable. */
/* {{RELAX<SYNCHRONe_C_Code_7.2> all literal value are defined by the MPC5777M Reference manual */

typedef struct
{
   union
   {                             /* Configuration Register (CRC_CFG) */
      reg32_t u_R;
      struct
      {
         reg32_t s_reserve1 :8;
         reg32_t s_reserve2 :18;
         reg32_t s_SWAP_BYTEWISE_CRC_32:1;
         reg32_t s_SWAP_BYTEWISE_CRC_8_16:1;
         reg32_t s_POLYG:2;
         reg32_t s_SWAP:1;
         reg32_t s_INV:1;
      } u_B;
   } s_CRC_CFG;

   reg32_t s_CRC_INP;            /* Input Register */

   reg32_t s_CRC_CSTAT;          /* Current Status Register */

   reg32_t s_CRC_OUTP;           /* Output Register Register */

}
ts_HWCRC_REG;
/* }}<SYNCHRONe_C_Code_8.2, SYNCHRONe_C_Code_6.6, SYNCHRONe_C_Code_24.5, SYNCHRONe_C_Code_5.4> */
/* }}<SYNCHRONe_C_Code_8.17> */
/* }}<SYNCHRONe_C_Code_6.4> */
/* }}<SYNCHRONe_C_Code_7.2> */

/* ---------- provided constants: ------------------------------------------- */
/* */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif /* HWCRC_REG_common_H */
