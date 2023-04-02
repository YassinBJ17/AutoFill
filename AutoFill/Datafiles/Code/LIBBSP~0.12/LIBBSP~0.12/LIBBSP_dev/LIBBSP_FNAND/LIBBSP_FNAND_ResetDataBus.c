/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_ResetDataBus.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Private function
 * Reset data part of the eSDHC controller.
 * Parameters : None
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP ResetDataBus(void)
{
   TE_LIBBSP_FNAND_ERROR_OP v_Error = E_LIBBSP_FNAND_NO_ERROR;

   uint32_t v_Timeout = C_FNAND_T_100_US;

   P_LIBBSP_FNAND_Host->SYSCTL.B.RSTD = 0x01ul;
   do
   {
      (void) IsElapsed((uint32_t*)&v_Timeout);
   }
   while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_Host->SYSCTL.B.RSTD == 0x01ul));

   if(v_Timeout == 0ul)
   {
      v_Error = E_LIBBSP_FNAND_ERROR_STOP;
   }
   else
   {
      /* Nothing to do */
   }
   P_LIBBSP_FNAND_Host->PROCTL.B.DTW = 0x01ul;
   P_LIBBSP_FNAND_Host->DSADDR = 0ul;
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.BRRSEN   = 0x00ul;
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.BWRSEN   = 0x00ul;
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.DINTSEN  = 0x01ul;
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.BGESEN   = 0x00ul;
   P_LIBBSP_FNAND_Host->IRQSTATEN.B.TCSEN    = 0x01ul;

   Wait(C_FNAND_T_100_US);

   return (v_Error);
}
/*==== END =============================================================================*/
