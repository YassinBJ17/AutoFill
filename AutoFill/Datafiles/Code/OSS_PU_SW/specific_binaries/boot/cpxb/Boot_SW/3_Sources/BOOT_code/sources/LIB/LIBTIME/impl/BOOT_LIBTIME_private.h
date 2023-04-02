#ifndef BOOT_LIBTIME_PRIVATE_H
#define BOOT_LIBTIME_PRIVATE_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- DLD symbol ---------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */

#include "CMN_TYPES_common.h"

/* ---------- provided define constants: ------------------------------------ */


/* ---------- provided types: ----------------------------------------------- */

/* {{RELAX<SYNCHRONe_C_Code_8.17,SYNCHRONe_C_Code_5.4,SYNCHRONe_C_Code_6.6> : Register definition : all fields are*/
/* defined even if there are not used. The format is compliant with register definition */
typedef union
{
   reg32_t u_reg32;
   struct
   {
      reg32_t s_reservedA   : 30;
      reg32_t s_MDIS        : 1;
      reg32_t s_FRZ         : 1;
   } u_field;
}
tu_LIBT_PIT_MCR;

/* */
typedef union
{
   reg32_t u_reg32;
   struct
   {
      reg32_t s_reservedA   : 29;
      reg32_t s_CHN         : 1;
      reg32_t s_TIE         : 1;
      reg32_t s_TEN         : 1;
   } u_field;
}
tu_LIBT_PIT_TCTRL;

/* */
typedef union
{
   reg32_t u_reg32;
   struct
   {
      reg32_t s_reservedA   : 31;
      reg32_t s_TIF         : 1;
   } u_field;
}
tu_LIBT_PIT_TFLG;


typedef struct
{
   reg32_t s_PIT_LDVAL ;
   reg32_t s_PIT_CVAL ;
   tu_LIBT_PIT_TCTRL s_PIT_TCTRL ;
   tu_LIBT_PIT_TFLG s_PIT_TFLG ;
} ts_PIT_DESC_CHANNEL ;

typedef enum
{
   e_PIT_CHANNEL_0,
   e_PIT_CHANNEL_1,
   e_PIT_NB_CHANNEL
} te_PIT_CHANNEL_NAME;

#define LIBT_PIT_RSRVD_A_SIZE (55)
#define LIBT_PIT_RSRVD_B_SIZE (6)

typedef struct
{
   tu_LIBT_PIT_MCR   s_PIT_MCR;
   reg32_t           s_rsvdA[LIBT_PIT_RSRVD_A_SIZE];
   reg32_t           s_PIT_LTMR64H;
   reg32_t           s_PIT_LTMR64L;
   reg32_t           s_rsvdB[LIBT_PIT_RSRVD_B_SIZE];

   /* Channels description  */
   ts_PIT_DESC_CHANNEL	s_PIT_DESC_CHANNEL [ e_PIT_NB_CHANNEL ] ;

}  ts_LIBT_PIT_CTRL;
/* }}<SYNCHRONe_C_Code_8.17,SYNCHRONe_C_Code_5.4,SYNCHRONe_C_Code_6.6> */


extern volatile ts_LIBT_PIT_CTRL * const LIBT_pit_ctrl;

/* ---------- provided operations: ------------------------------------------ */
/* none */



#endif /* BOOT_LIBTIME_PRIVATE_H */
