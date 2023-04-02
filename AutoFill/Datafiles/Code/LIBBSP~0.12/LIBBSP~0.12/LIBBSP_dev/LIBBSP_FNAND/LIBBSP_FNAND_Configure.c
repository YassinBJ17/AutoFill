/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_Configure.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/
/* {{RELAX<SYNCHRONe_C_Code_10.7> access to registers do not imply loss of precision */
/* }} RELAX<SYNCHRONe_C_Code_10.7> */

/*==== Services ========================================================================*/

/* Public function
 * Start initialization and configuration sequence of the eSDHC controller (HOST) and NAND memory (card)
 * Parameters : v_StartSequence -> if TRUE, the boot sequence of the card is performed
 * Return : TE_LIBBSP_FNAND_INIT
 */
boolean_t LIBBSP_FNAND_Configure(const boolean_t v_StartSequence)
{
   boolean_t v_ErrorInit;
   TE_LIBBSP_FNAND_INIT_HOST v_ErrorHost;
   TE_LIBBSP_FNAND_INIT_CARD v_ErrorCard;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> No precision lost: same type */
   P_LIBBSP_FNAND_StatusCard = &V_LIBBSP_FNAND_StatusCard;
   P_LIBBSP_FNAND_Op = &V_LIBBSP_FNAND_Op;
   P_LIBBSP_FNAND_Status = &V_LIBBSP_FNAND_Status;
   /* }} RELAX<SYNCHRONe_C_Code_10.7> */

   if (v_StartSequence != FALSE)
   {
      v_ErrorHost = InitHost();
      if(v_ErrorHost == E_LIBBSP_FNAND_HOST_OK)
      {
         v_ErrorCard = InitCard();
         if(v_ErrorCard == E_LIBBSP_FNAND_CARD_OK)
         {
            (void) LIBBSP_FNAND_GetStatus(P_LIBBSP_FNAND_StatusCard);
            v_ErrorInit = TRUE;
         }
         else
         {
            v_ErrorInit = FALSE;
         }
      }
      else
      {
         v_ErrorInit = FALSE;
      }
   }
   else
   {
      v_ErrorInit = TRUE;
   }

   P_LIBBSP_FNAND_Status->COMMAND = TRUE;
   P_LIBBSP_FNAND_Status->TRANSFER = E_LIBBSP_FNAND_NO_TRAN;

   return (v_ErrorInit);
}
/*==== END =============================================================================*/
