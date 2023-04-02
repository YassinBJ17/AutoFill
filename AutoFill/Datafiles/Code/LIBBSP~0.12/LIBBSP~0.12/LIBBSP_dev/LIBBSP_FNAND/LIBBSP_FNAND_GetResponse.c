/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_GetResponse.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Get command response and update the P_LIBBSP_FNAND_Op->CMD_RSP[] structure field.
 * Parameters : (TE_LIBBSP_FNAND_RSP_TYPE) v_RspType -> Response type expected
 * Return : None
 */
void GetResponse(const TE_LIBBSP_FNAND_RSP_TYPE v_RspType)
{
   P_LIBBSP_FNAND_Op->CMD_RSP[0] = 0ul;
   P_LIBBSP_FNAND_Op->CMD_RSP[1] = 0ul;
   P_LIBBSP_FNAND_Op->CMD_RSP[2] = 0ul;
   P_LIBBSP_FNAND_Op->CMD_RSP[3] = 0ul;

   switch(v_RspType)
   {
      case E_LIBBSP_FNAND_R1_R1B_RSP:
         P_LIBBSP_FNAND_Op->CMD_RSP[0] = P_LIBBSP_FNAND_Host->CMDRSP0;
         P_LIBBSP_FNAND_StatusCard->R = P_LIBBSP_FNAND_Host->CMDRSP0; /* Update status card */
         break;

      case E_LIBBSP_FNAND_R1B_ACMD13_RSP:
         P_LIBBSP_FNAND_Op->CMD_RSP[0] = P_LIBBSP_FNAND_Host->CMDRSP3;
         break;
      case E_LIBBSP_FNAND_R3_R4_R6_RSP:
         P_LIBBSP_FNAND_Op->CMD_RSP[0] = P_LIBBSP_FNAND_Host->CMDRSP0;
         break;

      case E_LIBBSP_FNAND_R2_RSP:
         P_LIBBSP_FNAND_Op->CMD_RSP[0] = ((P_LIBBSP_FNAND_Host->CMDRSP3 & 0x00FFFFFFul) << 8) | ((P_LIBBSP_FNAND_Host->CMDRSP2 & 0xFF000000ul) >> 24);
         P_LIBBSP_FNAND_Op->CMD_RSP[1] = ((P_LIBBSP_FNAND_Host->CMDRSP2 & 0x00FFFFFFul) << 8) | ((P_LIBBSP_FNAND_Host->CMDRSP1 & 0xFF000000ul) >> 24);
         P_LIBBSP_FNAND_Op->CMD_RSP[2] = ((P_LIBBSP_FNAND_Host->CMDRSP1 & 0x00FFFFFFul) << 8) | ((P_LIBBSP_FNAND_Host->CMDRSP0 & 0xFF000000ul) >> 24);
         P_LIBBSP_FNAND_Op->CMD_RSP[3] = ((P_LIBBSP_FNAND_Host->CMDRSP0 & 0x00FFFFFFul) << 8);
         break;

      case E_LIBBSP_FNAND_NO_RSP:
         break;

      default:
         break;
   }
}
/*==== END =============================================================================*/
