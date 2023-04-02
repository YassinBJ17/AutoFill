/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Alternator rearm service function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/powersup/powersup_public.h"
#include "middleware/powersup/powersup_private.h"
#include "middleware/pca9535e/pca9535e_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "memory/oss_section_def_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "driver/i2c/drv_I2C_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------- */
/* Implements REQ_FADEX_OS_SRD-POWERSUP-0020 */
/* Alternator rearm service function */
void powersup_alt_rearm(void)
{
   /* Force GPIO to OFF if GPDI is ON during last RTC */
   if( *GPDI_205_REARM_PMA == (reg8_t)1 )
   {
      /* Pass GPIO to OFF */
      *GPDO_205_REARM_PMA = (reg8_t)0;
      /* Return REARM OFF */
      shmem.s_alt_rearm = (uint32_t)0;
   }else
   {
      /* Pass GPIO to ON */
      *GPDO_205_REARM_PMA = (reg8_t)1;
   }

   return;
}

/* ---------- internal operations: ------------------------------------------ */
