/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SHM_GetMode.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
TE_LIBBSP_SHM_Mode LIBBSP_SHM_GetMode(void)
{
   TE_LIBBSP_SHM_Mode v_BoardMode;
   uint32_t v_state;
   
   v_state = V_SHMRegs->shm_state;
   
   switch (v_state)
   {
      case (uint32_t)1: /* (uint32_t)E_LIBBSP_SHM_POWER_UP_STATE */
         v_BoardMode = E_LIBBSP_SHM_POWER_UP_STATE;
         break;
      case (uint32_t)2:
         v_BoardMode = E_LIBBSP_SHM_INITIALIZATION_STATE;
         break;
      case (uint32_t)4:
         v_BoardMode = E_LIBBSP_SHM_IDLE_STATE;
         break;
      case (uint32_t)8:
         v_BoardMode = E_LIBBSP_SHM_OPERATIONNAL_UP_STATE;
         break;
      case (uint32_t)16:
         v_BoardMode = E_LIBBSP_SHM_DEGRADED_STATE;
         break;
      default:
         v_BoardMode = E_LIBBSP_SHM_FAILURE_STATE;
         break;
   }
   
   return v_BoardMode;
}

/*==== END =============================================================================*/
