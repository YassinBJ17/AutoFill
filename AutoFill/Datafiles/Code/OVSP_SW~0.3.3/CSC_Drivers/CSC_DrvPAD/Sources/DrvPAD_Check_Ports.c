/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the ...
 * -------------------------------------------------------------------------- */

/* ---------- include predefined types: ------------------------------------- */
#include "OVSP_SW_Public.h"
#include "MCP_Types.h"

/* ---------- include required interface: ----------------------------------- */
#include "DrvPAD_Private.h"
#include "DrvPAD_Public.h"
#include "Boot_Public.h"

/* ---------- provided define constants: ------------------------------------ */
/* None */

/* ---------- provided types: ----------------------------------------------- */
/* None */

/* -------------------------------------------------------------------------- */
/* None */

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */

/* PORT checking: To check all ports A, B, C, D, E
 *
 * Parameters:
 *   Inputs: None
 *   Outputs: None
 *
 *  */
void DrvPAD_check_ports(uint32_t * p_status)
{
   uint32_t pin_number;
   uint32_t port_number;
   ts_DrvPAD_PortCtrl * pt_port_ctrl;
   uint8_t v_OVSP_Side_Id;

   /* PADs checking */
   /* Store the driver registers in local variable */
   pt_port_ctrl = C_DrvPAD_PortCtrl;
   v_OVSP_Side_Id = Boot_Get_Side_Id ();

   *p_status = 0;

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
               if ((pin_number == (DRVPAD_MAX_PORTS_NB - 1)) && (pin_number >= DRVPAD_DEF_PINS_NB - 2))
               {
                  break;
               }
               else
               {
                  if ((C_DrvPAD_HS_Config [port_number] [pin_number] & DRVPAD_PIN_NOT_USED) != DRVPAD_PIN_NOT_USED)
                  {
                     /* Pin configurated */
                     if (pt_port_ctrl->Port [port_number].PCR [pin_number]
                        != C_DrvPAD_HS_Config [port_number] [pin_number])
                     {
                        *p_status |= (((port_number + 0x000AU) & 0xFFFFU) << 16U) | pin_number;
                        break;
                     }
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
                  if ((pin_number == (DRVPAD_MAX_PORTS_NB - 1)) && (pin_number >= (DRVPAD_DEF_PINS_NB - 2)))
                  {
                     break;
                  }
                  else
                  {
                     if ((C_DrvPAD_LS_Config [port_number] [pin_number] & DRVPAD_PIN_NOT_USED) != DRVPAD_PIN_NOT_USED)
                     {
                        /* Pin configurated */
                        if (pt_port_ctrl->Port [port_number].PCR [pin_number]
                           != C_DrvPAD_LS_Config [port_number] [pin_number])
                        {
                           *p_status |= (((port_number + 0x000AU) & 0xFFFFU) << 16U) | pin_number;
                           break;
                        }
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
      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
