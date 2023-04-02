/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : OVSP get sw info command send
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */

#include "middleware/pbit/pbit_private.h"
#include "middleware/logbook/logbook_public.h"
#include "middleware/reset/reset_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

void pbit_pld_pll(void)
{
   uint32_t* pld_status_reg;

   uint32_t pll_lock_ebi_64m_bit;
   uint32_t pll_lock_ebi_80m_bit;
   uint32_t pll_lock_wd_80m_bit;

   pld_status_reg = PLD_PLL_REG_ADD;

   pll_lock_ebi_64m_bit = (*pld_status_reg & PLD_PLL_LOCK_EBI_64M_BIT_MASK) >> SHIFT_31;
   pll_lock_ebi_80m_bit = (*pld_status_reg & PLD_PLL_LOCK_EBI_80M_BIT_MASK) >> SHIFT_30;
   pll_lock_wd_80m_bit  = (*pld_status_reg & PLD_PLL_LOCK_WD_80M_BIT_MASK) >> SHIFT_29;

   if(pll_lock_ebi_64m_bit != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   if(pll_lock_ebi_80m_bit != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }

   if(pll_lock_wd_80m_bit != (uint32_t)1)
   {
      /* Log fatal fault */
      logbook_pbit_fatal(0, 0);

      /* WD reset */
      reset_critical();
   }
}

/* ---------- internal operations: ------------------------------------------ */
