/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : PBRIDGES initial configuration tables
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */

#include "BOOT_CONF_public.h"

/****             PBRIDGE A        ******/

const ts_PBRIDGE_CONF c_CONF_PBRIDGEA =
{
   /* MPR A */
   0x77777777UL,
   /* MPR B */
   0x77777777UL,
   /* PACR */
   {
      0x11101111,
      0x10101001,
      0x10001111,
      0x111000,
      0x0,  /* PACRE not implemented on the MPC5777M */
      0x11001000,
      0x11111000,
      0x1000000
   }
   ,
   /* OPACR */
   {
      0x11111141,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111141,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111
   }
};


/****             PBRIDGE B        ******/

const ts_PBRIDGE_CONF c_CONF_PBRIDGEB =
{
   /* MPR A */
   0x77777777UL,
   /* MPR B */
   0x77777777UL,
   /* PACR */
   {
      0x10000000,
      0x0,
      0x0,
      0x0,
      0x0,  /* PACRE not implemented on the MPC5777M */
      0x0,
      0x0,
      0x0
   }
   ,
   /* OPACR */
   {
      0x11111111,
      0x11111110,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111,
      0x11111111
   }
};
