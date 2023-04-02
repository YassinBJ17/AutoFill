/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ...
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include external interface: ----------------------------------- */
/* None */

/* ---------- include required interface: ----------------------------------- */
#include "DrvLPIT_Private.h"
#include "DrvLPIT_Public.h"
/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */

/* DrvLPIT_Start : To start the timer for the RTC of sequencer
 *   Inputs: 
 *    - p_TimerId: Identifier of timer to stop
 *    - p_Timeout: Timeout value of timer
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPIT_Start (uint32_t const p_TimerId, uint32_t const p_Timeout)
{
   uint32_t v_wait;
   uint32_t v_timeout;

   /* Timeout is given in number of 10us */
   /* 1 tick corresponds to 1 / SPLLDIV2_CLK seconds */
   /* SPLLDIV2_CLK = (SEQ_CORE_TIMER_DIV_FACTOR / 10) * 10^6 */
   /* 10us needs 1 * 10^-5 / (1 / SPLLDIV2_CLK ) ticks */
   v_timeout = p_Timeout * DRVLPIT_DIV_FACTOR_375;

   /* Enable peripheral clock */
   DrvLPIT_LPIT_Registers->S_MCR = 
      ((1UL << DRVLPIT_MCR_M_CEN_SHIFT) & DRVLPIT_MCR_M_CEN_MASK);

   /* Wait 4 peripheral clock for sync */
   for (v_wait = 0UL ; v_wait < 4UL ; v_wait++)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (p_TimerId == DRVLPIT_IDENT_0)
   {
      /* Enable timer interrupt */
      DrvLPIT_LPIT_Registers->S_MIER |= 
         ((1UL << DRVLPIT_MIER_TIE_0_SHIFT) & DRVLPIT_MIER_TIE_0_MASK);
   }
   else
   {
      /* Enable timer interrupt */
      DrvLPIT_LPIT_Registers->S_MIER |= 
         ((1UL << DRVLPIT_MIER_TIE_1_SHIFT) & DRVLPIT_MIER_TIE_1_MASK);
   }

   /* Set timer value */
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [p_TimerId].S_TVAL = v_timeout - 1UL;

   /* Enable timer */
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [p_TimerId].S_TCTRL |= 
      ((1UL << DRVLPIT_TCTRL_T_EN_SHIFT) & DRVLPIT_TCTRL_T_EN_MASK);
}


/* DrvLPIT_Stop : To stop the timer for the RTC of sequencer
 *   Inputs: 
 *    - p_TimerId: Identifier of timer to stop
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPIT_Stop (uint32_t const p_TimerId)
{
   uint32_t v_wait;

   /* Enable peripheral clock */
   DrvLPIT_LPIT_Registers->S_MCR = 
      ((1UL << DRVLPIT_MCR_M_CEN_SHIFT) & DRVLPIT_MCR_M_CEN_MASK);

   /* Wait 4 peripheral clock for sync */
   for (v_wait = 0UL ; v_wait < 4UL ; v_wait++)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (p_TimerId == 0UL)
   {
      /* Disable timer interrupt */
      DrvLPIT_LPIT_Registers->S_MIER &= 
         ~((1UL << DRVLPIT_MIER_TIE_0_SHIFT) & DRVLPIT_MIER_TIE_0_MASK);
   }
   else
   {
      /* Disable timer interrupt */
      DrvLPIT_LPIT_Registers->S_MIER &= 
         ~((1UL << DRVLPIT_MIER_TIE_1_SHIFT) & DRVLPIT_MIER_TIE_1_MASK);
   }

   /* Disable timer */
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [p_TimerId].S_TCTRL &= 
      ~(((1UL << DRVLPIT_TCTRL_T_EN_SHIFT) & DRVLPIT_TCTRL_T_EN_MASK));
}

/* DrvLPIT_Reset : To reset the timer for the RTC of sequencer
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPIT_Reset (void)
{
   uint32_t timer_id;
   uint32_t timer_tif;

   /* Determine which timer is reached */
   timer_tif = DrvLPIT_LPIT_Registers->S_MSR & DRVLPIT_MSR_TIF_MASK;

   if ((timer_tif & DRVLPIT_MSR_TIF_0_MASK ) == DRVLPIT_MSR_TIF_0_MASK)
   {
      /* Select timer 0 */
      timer_id = DRVLPIT_IDENT_0;
   }
   else
   {
      if ((timer_tif & DRVLPIT_MSR_TIF_1_MASK ) == DRVLPIT_MSR_TIF_1_MASK)
      {
         /* Select timer 1 */
         timer_id = DRVLPIT_IDENT_1;
      }
      else
      {
         /* Error */
         timer_id = DRVLPIT_IDENT_ERROR;
      }
   }

   /* Clear timer interrupt flag */
   if (timer_id == DRVLPIT_IDENT_0)
   {
      DrvLPIT_LPIT_Registers->S_MSR = 
         (1UL << DRVLPIT_MSR_TIF_0_SHIFT) & DRVLPIT_MSR_TIF_0_MASK;
   }
   else
   {
      /* Reset timer 1 */
      if (timer_id == DRVLPIT_IDENT_1)
      {
         DrvLPIT_LPIT_Registers->S_MSR = 
            (1UL << DRVLPIT_MSR_TIF_1_SHIFT) & DRVLPIT_MSR_TIF_1_MASK;
      }
      else
      {
         /* Reset both timers 1 and 2 */
         DrvLPIT_LPIT_Registers->S_MSR = 
            (1UL << DRVLPIT_MSR_TIF_0_SHIFT) & DRVLPIT_MSR_TIF_0_MASK;
         
         DrvLPIT_LPIT_Registers->S_MSR = 
            (1UL << DRVLPIT_MSR_TIF_1_SHIFT) & DRVLPIT_MSR_TIF_1_MASK;
      }
   }
}
