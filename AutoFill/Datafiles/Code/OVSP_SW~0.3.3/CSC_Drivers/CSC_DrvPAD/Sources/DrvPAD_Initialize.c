/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ...
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "MCP_Types.h"

/* ---------- include required interface: ----------------------------------- */
#include "DrvPAD_Public.h"
#include "DrvPAD_Private.h"
#include "Boot_Public.h"
#include "OVSP_SW_Public.h"

/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* -------------------------------------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* Register mapping */
ts_DrvPAD_Registers * const PAD_Registers[DRVPAD_MAX_PORTS_NB];

/* ---------- provided operation bodies: ------------------------------------ */


/* PORT Initialize: To initialize all ports A, B, C, D, E
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void DrvPAD_Initialize (void)
{
   uint32_t pin_number;
   uint32_t port_number;
   ts_DrvPAD_PortCtrl * pt_port_ctrl;
   uint8_t v_OVSP_Side_Id;

   /* PADs initialization */
   /* Store the driver registers in local variable */
   pt_port_ctrl = C_DrvPAD_PortCtrl;
   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   /* Initialize descriptor */
   if (pt_port_ctrl != OVSP_SW_NULL_POINTER)
   {
      /* Ports configuration */
      for (port_number = DRVPAD_UINT32_0; port_number < DRVPAD_MAX_PORTS_NB ; port_number++)
      {
         for (pin_number = DRVPAD_UINT32_0; pin_number < DRVPAD_DEF_PINS_NB ; pin_number++)
         {
            if (v_OVSP_Side_Id == BOOT_SIDE_ID_HS) /* HS configuration */
            {
               if ((pin_number == (DRVPAD_MAX_PORTS_NB - 1UL)) && (pin_number >= (DRVPAD_DEF_PINS_NB - 2UL)))
               {
                  break;
               }
               else
               {
                  if ((C_DrvPAD_HS_Config [port_number] [pin_number] & DRVPAD_PIN_NOT_USED) != DRVPAD_PIN_NOT_USED)
                  {
                     /* Pin configurated */
                     pt_port_ctrl->Port [port_number].PCR [pin_number] = C_DrvPAD_HS_Config [port_number] [pin_number];
                  }
                  else
                  { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
                     /* Nothing to do */
                  }
               }
            }
            else
            {
               if (v_OVSP_Side_Id == BOOT_SIDE_ID_LS)
               {
                  if ((pin_number == (DRVPAD_MAX_PORTS_NB - 1UL)) && (pin_number >= (DRVPAD_DEF_PINS_NB - 2UL)))
                  {
                     break;
                  }
                  else
                  {
                     if ((C_DrvPAD_LS_Config [port_number] [pin_number] & DRVPAD_PIN_NOT_USED) != DRVPAD_PIN_NOT_USED)
                     {
                        /* Pin configurated */
                        pt_port_ctrl->Port [port_number].PCR [pin_number] =
                           C_DrvPAD_LS_Config [port_number] [pin_number];
                     }
                     else
                     { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
                        /* Nothing to do */
                     }
                  }
               }
               else
               { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
                  /* Do nothing */
               }
            }
         }
         /* Global Pin control is configured with default value */
         pt_port_ctrl->Port [port_number].GPCLR = DRVPAD_UINT32_0;
         pt_port_ctrl->Port [port_number].GPCHR = DRVPAD_UINT32_0;

         /* Interrup Status Flag is configured by PCR register */
         /* pt_port_ctrl->ISFR                  */
         /* Digital Filter parameters are configured to "No Filtering" */
         pt_port_ctrl->Port [port_number].DFER = DRVPAD_UINT32_0;
         pt_port_ctrl->Port [port_number].DFCR = DRVPAD_UINT32_0;
         pt_port_ctrl->Port [port_number].DFWR = DRVPAD_UINT32_0;
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
