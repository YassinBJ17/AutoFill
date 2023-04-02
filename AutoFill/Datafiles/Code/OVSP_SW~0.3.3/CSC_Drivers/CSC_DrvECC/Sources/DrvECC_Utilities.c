/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvECC CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvECC_Public.h"
#include "DrvECC_Private.h"


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
/* DrvECC_Generate_SingMultErr : To generate single and multiple errors
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvECC_Generate_SingMultErr (void)
{
   volatile uint32_t v_Read_Value;

   C_DrvECC_EIM_Registers->S_EICHD0_WORD1 = DRVECC_EIM_EICHD0_SING_ERROR;
   C_DrvECC_EIM_Registers->S_EICHD1_WORD1 = DRVECC_EIM_EICHD1_MULT_ERROR;
   C_DrvECC_EIM_Registers->S_EICHEN = DRVECC_EIM_EICHEN_ENABLE;
   C_DrvECC_EIM_Registers->S_EIMCR = DRVECC_EIM_EIMCR_ENABLE;

   v_Read_Value = (*(uint32_t *) (DRVECC_SRAM_L_ADDRESS));
   v_Read_Value = (*(uint32_t *) (DRVECC_SRAM_U_ADDRESS));

   C_DrvECC_EIM_Registers->S_EICHD0_WORD1 = DRVECC_EIM_EICHDN_NO_ERROR;
   C_DrvECC_EIM_Registers->S_EICHD1_WORD1 = DRVECC_EIM_EICHDN_NO_ERROR;
   C_DrvECC_EIM_Registers->S_EICHEN = DRVECC_EIM_EICHEN_DISABLE;
   C_DrvECC_EIM_Registers->S_EIMCR = DRVECC_EIM_EIMCR_DISABLE;

   C_DrvECC_ERM_Registers->S_CR0 = DRVECC_ERM_CR0_VALUE;
}


/* DrvECC_ERM_Clear_Single_Err : To clear the Single error
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvECC_ERM_Clear_Single_Err (void)
{
   C_DrvECC_ERM_Registers->S_CR0 = C_DrvECC_ERM_Registers->S_CR0 & DRVECC_ERM_CR0_DISABLE_S;
}


/* DrvECC_ERM_Clear_Multiple_Err : To clear the Multiple error
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvECC_ERM_Clear_Multiple_Err (void)
{
   C_DrvECC_ERM_Registers->S_CR0 = C_DrvECC_ERM_Registers->S_CR0 & DRVECC_ERM_CR0_DISABLE_M;
}
