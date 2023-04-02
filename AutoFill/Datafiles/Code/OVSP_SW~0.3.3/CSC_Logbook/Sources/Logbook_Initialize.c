/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Logbook CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Logbook_Public.h"
#include "Logbook_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "DrvFTFC_Public.h"

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
/* Logbook_Initialize : To initialize the Logbook CSC
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Logbook_Initialize (void)
{
   uint32_t v_Iter_Logbook;
   TU_Logbook_FlexNVM_Mapping *pt_Logbook;

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long address */
   /* converted to a pointer which is also an 32-bit Unsigned Long. */
   pt_Logbook = (TU_Logbook_FlexNVM_Mapping *) DRVFTFC_LOGBOOK_START_ADDR;

   for (v_Iter_Logbook = 0UL; v_Iter_Logbook < DRVFTFC_LOGBOOK_32BIT_NB; v_Iter_Logbook++)
   {
      V_Logbook.U_Array_32BitUint [v_Iter_Logbook] = pt_Logbook->U_Array_32BitUint [v_Iter_Logbook];
   }

   V_Logbook_Failure_to_Write = FALSE;

   V_Logbook_Previous_PBIT_Failure.S_Failure_Code = LOGBOOK_PBIT_FAILURE_ID;
   V_Logbook_Previous_PBIT_Failure.S_Failure_Detail = LOGBOOK_NO_FAILURE_CODE;

   V_Logbook_Previous_CBIT_Failure.S_Failure_Code = LOGBOOK_CBIT_FAILURE_ID;
   V_Logbook_Previous_CBIT_Failure.S_Failure_Detail = LOGBOOK_NO_FAILURE_CODE;
}
