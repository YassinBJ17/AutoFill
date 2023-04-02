/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Boot CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Boot_Public.h"
#include "Boot_Private.h"


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
/* Boot_Handle_HardFault : To handle HardFault interrupts
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Boot_Handle_HardFault (void)
{ /* %RELAX<SYNCHRONe_C_Code_14.2> This function is mapped in the vectors table, but has nothing to do */
   /* Nothing to do */
}


/* Boot_Handle_NMI : To handle Non Masquable Interrupt (NMI)
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Boot_Handle_NMI (void)
{ /* %RELAX<SYNCHRONe_C_Code_14.2> This function is mapped in the vectors table, but has nothing to do */
   /* Nothing to do */
}


/* Boot_Get_Side_Id : To provide the OVSP side identification
 *   Inputs: None
 *   Outputs: None
 *   Function return: OVSP side identification
 *   Pre-condition: None
*/
uint8_t Boot_Get_Side_Id (void)
{
   return (V_Boot_OVSP_Side_Id);
}
