/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2021                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_FNAND_InitHost.h"


/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/
/* Private function
 * Start host initialization sequence
 * Parameters : (uint32_t) v_Address -> CCSR eSDHC address
 * Return : TE_LIBBSP_FNAND_INIT_HOST
 */
TE_LIBBSP_FNAND_INIT_HOST InitHost(void){

   TE_LIBBSP_FNAND_INIT_HOST v_Error = E_LIBBSP_FNAND_HOST_OK;
   uint32_t v_Timeout = C_FNAND_T_100_US;

   /*
    * GPIO Configuration
    */
   P_LIBBSP_FNAND_PMUXCRReg->SD_DATA = 0x00ul;  /* Not exposes FNAND_DAT[4:7] signals (work in 4-bits mode) */
   P_LIBBSP_FNAND_PMUXCRReg->FNAND_CD = 0x01ul; /* Exposes FNAND_CD_B signal used for Secure Digital card detection. */
   P_LIBBSP_FNAND_PMUXCRReg->FNAND_WP = 0x01ul; /* Exposes FNAND_WP signal used for Secure Digital write protect detection. */

   P_LIBBSP_FNAND_Host->SYSCTL.B.RSTA = 0x01ul; /* Hardware reset for FNAND controller. */
   do
   {
      (void) IsElapsed(&v_Timeout);
   }while((v_Timeout > 0ul) && (P_LIBBSP_FNAND_Host->SYSCTL.B.RSTA == 0x01ul));

   if(v_Timeout == 0ul)
   {
      return (E_LIBBSP_FNAND_HOST_TIMEOUT); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
   }
   /* Check if a memory is present */
   if(P_LIBBSP_FNAND_Host->PRSSTAT.B.CDPL == 0x01ul)
   {
      P_LIBBSP_FNAND_Host->IRQSTATEN.R = 0x00ul; /* Disable all status interruptions */
      P_LIBBSP_FNAND_Host->IRQSIGEN.R = 0x00ul; /* Disable all signal interruptions */

      P_LIBBSP_FNAND_FNAND_DCRReg->B.PRI = 0x03ul; /* eSDHC DMA highest priority */

      P_LIBBSP_FNAND_Host->BLKATTR.B.BLKSZE = C_FNAND_BLOCK_SIZE;

      /* Registers configuration according to BSIS document */
      /*
      * Protocol control (eSDHC_PROCTL)
      */
      P_LIBBSP_FNAND_Host->PROCTL.B.WECRM    = 0x00ul;
      P_LIBBSP_FNAND_Host->PROCTL.B.WECINS   = 0x00ul;
      P_LIBBSP_FNAND_Host->PROCTL.B.CDSS     = 0x00ul;
      P_LIBBSP_FNAND_Host->PROCTL.B.EMODE    = 0x00ul;
      P_LIBBSP_FNAND_Host->PROCTL.B.D3CD     = 0x00ul;

      /*
       * System control (eSDHC_SYSCTL)
       */
      P_LIBBSP_FNAND_Host->SYSCTL.B.RSTD     = 0x00ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.RSTC     = 0x00ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.RSTA     = 0x00ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.DTOCV    = 0x02ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.PEREN    = 0x01ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.HCKEN    = 0x01ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.IPGEN    = 0x01ul;

      /*
       * Interrupt Status enable (eSDHC_IRQSTATEN)
       */
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.DMAESEN  = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.AC12ESEN = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.DEBESEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.DCESEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.DTOESEN  = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CIESEN   = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CEBESEN  = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CCESEN   = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CTOESEN  = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CRMSEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CINSEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.BRRSEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.BWRSEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.DINTSEN  = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.BGESEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.TCSEN    = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSTATEN.B.CCSEN    = 0x01ul;

      /*
       * Interrupt signal enable (eSDHC_IRQSIGEN)
       */
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.DMAEIEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.AC12EIEN = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.DEBEIEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.DCEIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.DTOEIEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CIEIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CEBEIEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CCEIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CTOEIEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CRMIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CINSIEN  = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.BRRIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.BWRIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.DINTIEN  = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.BGEIEN   = 0x00ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.TCIEN    = 0x01ul;
      P_LIBBSP_FNAND_Host->IRQSIGEN.B.CCIEN    = 0x01ul;

      /*
       * Specific configuration to init the eSDHC controller
       */
      P_LIBBSP_FNAND_Host->SYSCTL.B.SDCLKEN  = 0x00ul;
      Wait(C_FNAND_T_10_MS); /* Wait for stabilize clock */
      P_LIBBSP_FNAND_Host->SYSCTL.B.DVS  = 0x00ul;
      P_LIBBSP_FNAND_Host->SYSCTL.B.SDCLKFS  = 0x40ul; /* base clock (166MHz) / [(SDCLKFS(128) x 2) x (DVS(1) + 1)] = 0.3125MHz */
      P_LIBBSP_FNAND_Host->SYSCTL.B.SDCLKEN  = 0x01ul;
      Wait(C_FNAND_T_10_MS); /* Wait for stabilize clock */

      do
      {
         (void) IsElapsed(&v_Timeout);
      }while((v_Timeout > 0ul)
             && ((P_LIBBSP_FNAND_Host->PRSSTAT.B.CIHB != 0x00ul) || (P_LIBBSP_FNAND_Host->PRSSTAT.B.CDIHB != 0x00ul)));

      if(v_Timeout == 0ul)
      {
         v_Error = E_LIBBSP_FNAND_HOST_TIMEOUT;
      }
      else
      {
         /* OK - Nothing to do */
      }
   }
   else
   {
      v_Error = E_LIBBSP_FNAND_HOST_NO_MEM;
   }

   return (v_Error); /* %RELAX<SYNCHRONe_C_Code_16.12> correct type returned */
}
/*==== END =============================================================================*/
