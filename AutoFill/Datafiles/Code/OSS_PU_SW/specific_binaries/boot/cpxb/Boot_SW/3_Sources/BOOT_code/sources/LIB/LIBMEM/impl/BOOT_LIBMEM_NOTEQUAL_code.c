/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function verify the integrity of a given software
 *               (checksum 32 and CRC 32).
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_LIBMEM_public.h"

/* ---------- internal define constants: ------------------------------------ */


/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */

te_CMN_FLAG_QUESTION BOOT_LIBMEM_NOTEQUAL(
   const uint8_t * const FirstAddress,
   const uint8_t * const SecondAddress,
   const uint32_t        Size)
{
   uint32_t index;
   te_CMN_FLAG_QUESTION MemsNotEqual;

   MemsNotEqual = e_CMN_FLAG_NO;
   for ( index = 0; index < Size; index++ )
   {
       if (FirstAddress[index] != SecondAddress[index] )
       {
           MemsNotEqual = e_CMN_FLAG_YES;
           break;
       }
   }
   return ( MemsNotEqual );
}
