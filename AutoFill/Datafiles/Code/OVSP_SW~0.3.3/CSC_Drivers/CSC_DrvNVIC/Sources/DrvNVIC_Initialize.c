/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvNVIC CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvNVIC_Public.h"
#include "DrvNVIC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvNVIC_Initialize : To initialize the DrvNVIC CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvNVIC_Initialize (const uint32_t p_IRQ_Selection)
{
   uint32_t v_Iter_IRQ;
   uint32_t v_Iter_IRQ_Reg;

   for (v_Iter_IRQ_Reg = 0UL; v_Iter_IRQ_Reg < DRVNVIC_IRQ_32BIT_NB ; v_Iter_IRQ_Reg++)
   {
      C_DrvNVIC_Registers->S_ICPR [v_Iter_IRQ_Reg] = DRVNVIC_IRQ_RESET_VALUE;

      C_DrvNVIC_Registers->S_ICER [v_Iter_IRQ_Reg] = DRVNVIC_IRQ_RESET_VALUE;
   }

   if (DRVNVIC_BOOT_IRQ_SELECTION == p_IRQ_Selection)
   {
      for (v_Iter_IRQ = 0UL; v_Iter_IRQ < DRVNVIC_BOOT_IRQ_NB ; v_Iter_IRQ++)
      {
         C_DrvNVIC_Registers->S_IP [C_DrvNVIC_Boot_IRQ_Config [v_Iter_IRQ].S_HW_IT_Id] =
            C_DrvNVIC_Boot_IRQ_Config [v_Iter_IRQ].S_IRQ_Priority << DRVNVIC_IRQ_PRIORITY_SHIFT;

         C_DrvNVIC_Registers->S_ISER [C_DrvNVIC_Boot_IRQ_Config [v_Iter_IRQ].S_HW_IT_Line] |=
            C_DrvNVIC_Boot_IRQ_Config [v_Iter_IRQ].S_HW_IT_Line_BitMask;
      }
   }
   else
   {
      for (v_Iter_IRQ = 0UL; v_Iter_IRQ < DRVNVIC_SEQ_IRQ_NB ; v_Iter_IRQ++)
      {
         C_DrvNVIC_Registers->S_IP [C_DrvNVIC_Seq_IRQ_Config [v_Iter_IRQ].S_HW_IT_Id] =
            C_DrvNVIC_Seq_IRQ_Config [v_Iter_IRQ].S_IRQ_Priority << DRVNVIC_IRQ_PRIORITY_SHIFT;

         C_DrvNVIC_Registers->S_ISER [C_DrvNVIC_Seq_IRQ_Config [v_Iter_IRQ].S_HW_IT_Line] |=
            C_DrvNVIC_Seq_IRQ_Config [v_Iter_IRQ].S_HW_IT_Line_BitMask;
      }
   }
}
