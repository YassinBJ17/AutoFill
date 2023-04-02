/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SHM_SetMode.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_SHM_SetMode(const TE_LIBBSP_SHM_Mode v_SHM_Mode, const uint32_t v_SHM_User )
{
   switch (v_SHM_Mode)
   {
      case E_LIBBSP_SHM_IDLE_STATE:
         V_SHMRegs->shm_pbit_ok_user = v_SHM_User;
         break;
      case E_LIBBSP_SHM_FAILURE_STATE:
         V_SHMRegs->fail_switch_user = v_SHM_User;
         break;
      default:
         /*DO NOTHING*/
         break;
   }
}
/*==== END =============================================================================*/
