/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTFC ECC Test Configuration function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTFC_Private.h"

/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvFTFC_Configure_ECC_Test : To configure the FTFC for ECC double bit error test
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Configure_ECC_Test (void)
{
   while (DRVFTFC_FSTAT_CMD_COMPLETED == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_CCIF_MASK))
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (DRVFTFC_FSTAT_NO_ERROR != (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_FPVIOL_ACCERR_MASK))
   {
      C_DrvFTFC_Registers->S_FSTAT = DRVFTFC_FSTAT_FPVIOL_ACCERR_MASK;
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   C_DrvFTFC_Registers->S_FERCNFG |= DRVFTFC_FERCNFG_DFDIE_MASK;

   C_DrvFTFC_Registers->S_FERCNFG |= DRVFTFC_FERCNFG_FDFD_CONFIG;

   while (DRVFTFC_FSTAT_CMD_COMPLETED == (C_DrvFTFC_Registers->S_FSTAT & DRVFTFC_FSTAT_CCIF_MASK))
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
