/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function launch the integrity test of one specific
 *               software and verify that the test is OK.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_LIBCHK_public.h"
#include "BOOT_FAULT_public.h"
#include "BOOT_PBIT_private.h"
#include "CMN_TYPES_common.h"

/* ---------- internal define constants: ------------------------------------ */

#define END_FLASH 0x0177FFFF
#define START_FLASH 0x00FC0000

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_[User Project Name]_BOOT-LLR_007 */
void BOOT_PBIT_SW_SELF_INTEGRITY (void)
{

   te_CMN_FLAG_VALIDITY v_pbit_res;

   v_pbit_res = BOOT_LIBCHK_CARTRIDGE ( &BOOT_HEADER ,
                                        (uint32_t) START_FLASH ,
                                        (uint32_t) END_FLASH );

   if( v_pbit_res == e_CMN_FLAG_NOT_VALID )
   {
      /* never returns */
      BOOT_FAULT_LOG ( BOOT_FAULT_BOOT_INTEGRITY,
                       PBIT_ORIGIN,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE,
                       LGBK_FIELD_DEFAULT_VALUE );
   }

}
