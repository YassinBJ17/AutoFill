/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvLPSPI CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvLPSPI_Public.h"
#include "DrvLPSPI_Private.h"


/* ---------- include required interface: ----------------------------------- */
/* None */


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
/* DrvLPSPI_Initialize : To initialize the DrvLPSPI CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvLPSPI_Initialize (void)
{
   C_DrvLPSPI_Registers->S_CR = DRVLPSPI_CR_RESET;

   C_DrvLPSPI_Registers->S_IER = DRVLPSPI_IER_CONFIG;
   C_DrvLPSPI_Registers->S_DER = DRVLPSPI_DER_CONFIG;
   C_DrvLPSPI_Registers->S_CFGR0 = DRVLPSPI_CFGR0_CONFIG;
   C_DrvLPSPI_Registers->S_CFGR1 = DRVLPSPI_CFGR1_CONFIG;
   C_DrvLPSPI_Registers->S_CCR = DRVLPSPI_CCR_CONFIG;
   C_DrvLPSPI_Registers->S_FCR = DRVLPSPI_FCR_CONFIG;
   C_DrvLPSPI_Registers->S_TCR = DRVLPSPI_TCR_CONFIG;

   C_DrvLPSPI_Registers->S_CR = DRVLPSPI_CR_CONFIG;
}
