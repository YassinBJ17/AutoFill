/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvLPIT CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include external interface: ----------------------------------- */
/* None */

/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"

#include "DrvLPIT_Private.h"
#include "DrvLPIT_Public.h"

/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operation bodies: ------------------------------------ */

/* DrvLPIT_Initialize : To initialize the DrvLPIT CSC for sequencer timer
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPIT_Initialize (void)
{
   uint32_t v_wait;

   /* Enable peripheral clock and do a software reset (Resets all timer channels and registers, except the Module Control Register)*/
   DrvLPIT_LPIT_Registers->S_MCR = 
      ((1UL << DRVLPIT_MCR_M_CEN_SHIFT) & DRVLPIT_MCR_M_CEN_MASK) | 
      ((0UL << DRVLPIT_MCR_DBG_EN_SHIFT) & DRVLPIT_MCR_DBG_EN_MASK) |
      ((0UL << DRVLPIT_MCR_DOZE_EN_SHIFT) & DRVLPIT_MCR_DOZE_EN_MASK) | 
      ((1UL << DRVLPIT_MCR_SW_RST_SHIFT) & DRVLPIT_MCR_SW_RST_MASK);

   /* Before clearing the Software Reset bit, software must wait for 4 peripheral clocks (for clock
    synchronization and reset propagation). Wait 4 peripheral clock for sync */
   for (v_wait = 0UL ; v_wait < DRVLPIT_WAIT_CYCLES_NB ; v_wait++)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   /* Disable software reset */
   DrvLPIT_LPIT_Registers->S_MCR = 
      ((1UL << DRVLPIT_MCR_M_CEN_SHIFT) & DRVLPIT_MCR_M_CEN_MASK) | 
      ((0UL << DRVLPIT_MCR_DBG_EN_SHIFT) & DRVLPIT_MCR_DBG_EN_MASK) |
      ((0UL << DRVLPIT_MCR_DOZE_EN_SHIFT) & DRVLPIT_MCR_DOZE_EN_MASK) | 
      ((0UL << DRVLPIT_MCR_SW_RST_SHIFT) & DRVLPIT_MCR_SW_RST_MASK);

   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [OVSP_SW_LONG_0].S_TCTRL = 
      ((1UL << DRVLPIT_TCTRL_TRG_SEL_SHIFT) & DRVLPIT_TCTRL_TRG_SEL_MASK);
   
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [OVSP_SW_LONG_1].S_TCTRL = 
      ((1UL << DRVLPIT_TCTRL_TRG_SEL_SHIFT) & DRVLPIT_TCTRL_TRG_SEL_MASK);

   /* Do not need to configure MIER register since it is reset just before */
   /* Set counter to 0xFFFF_FFFF_FFFF_FFFF */
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [OVSP_SW_LONG_3].S_TVAL = DRVLPIT_TVAL_TMR_CONFIG;
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [OVSP_SW_LONG_2].S_TVAL = DRVLPIT_TVAL_TMR_CONFIG;

   /* Link channel 3 to channel 2 */
   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [OVSP_SW_LONG_3].S_TCTRL = 
      ((1UL << DRVLPIT_TCTRL_CHAIN_SHIFT) & DRVLPIT_TCTRL_CHAIN_MASK) | 
      ((1UL << DRVLPIT_TCTRL_T_EN_SHIFT) & DRVLPIT_TCTRL_T_EN_MASK);

   DrvLPIT_LPIT_Registers->S_TVAL_CVAL_TCTRL [OVSP_SW_LONG_2].S_TCTRL = 
      ((1UL << DRVLPIT_TCTRL_T_EN_SHIFT) & DRVLPIT_TCTRL_T_EN_MASK);

   /* Reset timers */
   DrvLPIT_Reset ();
}
