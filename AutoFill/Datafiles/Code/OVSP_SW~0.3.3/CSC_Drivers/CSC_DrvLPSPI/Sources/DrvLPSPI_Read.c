/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvLPSPI read function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvLPSPI_Public.h"
#include "DrvLPSPI_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "OVSP_SW_Public.h"
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
/* DrvLPSPI_Read : To read data on LPSPI
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Read_Value : Read value on LPSPI
 *     - p_pt_Status: Status of the reading
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPSPI_Read (uint32_t * const p_pt_Read_Value, uint32_t * const p_pt_Status)
{
   while (DRVLPSPI_SR_RDF_READY_MASK != (C_DrvLPSPI_Registers->S_SR & DRVLPSPI_SR_RDF_READY_MASK))
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }

   if (DRVLPSPI_FSR_RX_EMPTY != (C_DrvLPSPI_Registers->S_FSR & DRVLPSPI_FSR_RXCOUNT_MASK))
   {
      *p_pt_Read_Value = C_DrvLPSPI_Registers->S_RDR;
      *p_pt_Status = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Status = OVSP_SW_RESULT_FAILED;
   }
}
