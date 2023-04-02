/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_SHM_GetStatus.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_SHM_GetStatus(const TE_LIBBSP_SHM_Register v_RegName, TU_LIBBSP_SHM_RegValue * const v_RegValue)
{
   switch (v_RegName)
   {
      case E_LIBBSP_SHM_COMP_STATUS:
         v_RegValue->v_data = V_SHMRegs->comp_status;
         break;
      case E_LIBBSP_SHM_BOARD_STATUS:
         v_RegValue->v_data = V_SHMRegs->board_status;
         break;
      default:
         /*DO NOTHING*/
         break;
   }
}


/*==== END =============================================================================*/
