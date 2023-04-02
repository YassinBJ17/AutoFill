/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_SendConfig.h"


/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

/* Public function
 * Get the current configuration register from the FNAND.
 * Update the global structure field : P_LIBBSP_FNAND_Status->StatusCard
 * Parameters : (TE_LIBBSP_FNAND_CONFIG_REG) v_ConfigReg : Select the register to return (CID, CSD or ExtCSD)
 *              (uint32_t*) p_Config : pointer where return data (array of 4 uint32_t elements for CID and CSD, array of 128 uint32_t elements for ExtCSD)
 * Return : TE_LIBBSP_FNAND_ERROR_OP
 */
TE_LIBBSP_FNAND_ERROR_OP LIBBSP_FNAND_SendConfig(const TE_LIBBSP_FNAND_CONFIG_REG v_ConfigReg, uint32_t* const p_Config)
{
   TE_LIBBSP_FNAND_ERROR_OP v_Error;

   if((v_ConfigReg == E_LIBBSP_FNAND_CID) || (v_ConfigReg == E_LIBBSP_FNAND_CSD))
   {
      /* Deselect card */
      (void) SelectCard(0x00ul);
      if(v_ConfigReg == E_LIBBSP_FNAND_CID)
      {
         v_Error = SendCID(p_Config);
      }
      else
      {
         v_Error = SendCSD(p_Config);
      }
      /* Reselect Card */
      (void) SelectCard(C_FNAND_RCA);
   }
   else
   {
      v_Error = SendExtCSD(p_Config);
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}

/*==== END =============================================================================*/
