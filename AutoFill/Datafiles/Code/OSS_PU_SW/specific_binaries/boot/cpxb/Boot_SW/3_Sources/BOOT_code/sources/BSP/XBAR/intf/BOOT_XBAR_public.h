#ifndef BOOT_XBAR_PUBLIC_H
#define BOOT_XBAR_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
/* */
#define XBAR_COMPUT_BASE_ADDR (0xFC004000)

/* */
#define XBAR_PERIPH_BASE_ADDR (0xFC008000)

/* */
#define XBAR_PERIPH_NB (4UL)

/* */
#define XBAR_COMPUT_NB (8UL)

/* */
#define XBAR_RSRVD_A_SIZE (3)
#define XBAR_RSRVD_B_SIZE (59)

/* ---------- external types: ----------------------------------------------- */

/* */
typedef struct
{
   reg32_t s_XBAR_PRS;
   reg32_t                     s_XBAR_ELEM_rsvdA[XBAR_RSRVD_A_SIZE];
   reg32_t s_XBAR_CRS;
   reg32_t                     s_XBAR_ELEM_rsvdB[XBAR_RSRVD_B_SIZE];
}
ts_XBAR_ELEM;

/* */
typedef struct
{
   ts_XBAR_ELEM s_XBAR_C_ELEM[XBAR_COMPUT_NB];
}
ts_XBAR_COMPUT_REG;

/* */
typedef struct
{
   ts_XBAR_ELEM s_XBAR_P_ELEM[XBAR_PERIPH_NB];
}
ts_XBAR_PERIPH_REG;

typedef struct
{
   uint32_t s_XBAR_COMPUT_CRS;
   uint32_t s_XBAR_PERIPH_CRS;
} ts_XBAR_CONF;

/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* none */ 

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */
/* */
extern void BOOT_XBAR_INIT( void );


#endif /* BOOT_XBAR_PUBLIC_H */
