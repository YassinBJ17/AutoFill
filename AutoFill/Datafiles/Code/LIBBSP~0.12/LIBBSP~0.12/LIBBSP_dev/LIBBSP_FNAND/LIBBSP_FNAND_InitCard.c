/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_InitCard.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* Private function
 * Start initialization card sequence.
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_INIT_CARD
 */
TE_LIBBSP_FNAND_INIT_CARD InitCard(void)
{
   TE_LIBBSP_FNAND_INIT_CARD v_Error;

   uint32_t v_Timeout = C_FNAND_T_100_US;

   if((P_LIBBSP_FNAND_Host->PRSSTAT.B.CIHB != 0x00ul) || (P_LIBBSP_FNAND_Host->PRSSTAT.B.CDIHB != 0x00ul))
   {
      return (E_LIBBSP_FNAND_CARD_ERR_INHIBIT); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
   }

   P_LIBBSP_FNAND_Host->SYSCTL.B.INITA = 0x01ul; /* Send 80 clocks to the card */
   do
   {
      (void) IsElapsed(&v_Timeout);
   }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_Host->SYSCTL.B.INITA == 0x01ul));

   if(v_Timeout == 0ul)
   {
      return (E_LIBBSP_FNAND_CARD_TIMEOUT); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
   }

   v_Error = ResetCard();
   if(v_Error == E_LIBBSP_FNAND_CARD_OK)
   {
      v_Error = VoltageValidation();
      if(v_Error == E_LIBBSP_FNAND_CARD_OK)
      {
         v_Error = CardIdentification();
         if(v_Error == E_LIBBSP_FNAND_CARD_OK)
         {
            v_Error = SetBusConf();
            if(v_Error == E_LIBBSP_FNAND_CARD_OK)
            {
               Wait(C_FNAND_T_1_MS);
            }
            else
            {
               /* Nothing to do */
            }
         }
         else
         {
            /* Nothing to do */
         }
      }
      else
      {
         /* Nothing to do */
      }
   }
   else
   {
      /* Nothing to do */
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
