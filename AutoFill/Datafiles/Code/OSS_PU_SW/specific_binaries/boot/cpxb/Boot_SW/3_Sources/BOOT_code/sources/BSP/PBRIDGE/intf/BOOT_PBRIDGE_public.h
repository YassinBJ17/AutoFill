#ifndef BOOT_PBRIDGE_PUBLIC_H
#define BOOT_PBRIDGE_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
/* */
#define PBRIDGE_A_BASE_ADDR (0xFC000000)

/* */
#define PBRIDGE_B_BASE_ADDR (0xF8000000)

#define PBRIDGE_OPACRB_BASE_ADDR (0xF8000144)
#define PBRIDGE_NOT_IMPLEMENTED_REG_NB (4UL)

/* */
#define PBRIDGE_RSRVD_A_SIZE (62)
#define PBRIDGE_RSRVD_B_SIZE (8)
/* */
#define PBRIDGE_PACR_NB (8UL)

/* */
#define PBRIDGE_OPACR_NB  (32UL)

/* ---------- external types: ----------------------------------------------- */

/* */
typedef struct
{
   /* */
   reg32_t s_MPR_A;
   /* */
   reg32_t s_MPR_B;
   /* */
   reg32_t s_PBRIDGE_rsvdA[PBRIDGE_RSRVD_A_SIZE];
   /* */
   reg32_t s_PACR[PBRIDGE_PACR_NB];
   /* */
   reg32_t s_PBRIDGE_rsvdB[PBRIDGE_RSRVD_B_SIZE];
   /* */
   reg32_t s_OPACR[PBRIDGE_OPACR_NB];


}
ts_PBRIDGE_REG;

typedef struct
{
   uint32_t s_mpr_a;
   uint32_t s_mpr_b;
   uint32_t s_pacr[PBRIDGE_PACR_NB];
   uint32_t s_opacr[PBRIDGE_OPACR_NB];
}ts_PBRIDGE_CONF;

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* none */ 

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* none */

extern void BOOT_PBRIDGE_INIT( void );

#endif /* BOOT_PBRIDGE_PUBLIC_H */
