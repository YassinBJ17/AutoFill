/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvLPSPI write function
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
/* DrvLPSPI_Write : To write data on LPSPI
 *   Inputs:
 *     - p_Value : Value to write
 *   Outputs:
 *     - p_pt_Status: Status of the writing
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPSPI_Write (const uint32_t p_Value, uint32_t * const p_pt_Status)
{
   if (DRVLPSPI_TX_RX_FIFO_SIZE > (C_DrvLPSPI_Registers->S_FSR & DRVLPSPI_FSR_TXCOUNT_MASK))
   {
      C_DrvLPSPI_Registers->S_TDR = p_Value;
      *p_pt_Status = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Status = OVSP_SW_RESULT_FAILED;
   }
}
