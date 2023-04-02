/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvFTFC CSC Utilities functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTFC_Public.h"
#include "DrvFTFC_Private.h"


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
/* DrvFTFC_Copy_Data_To_RAM : To copy initialized data to their execution address in RAM
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Copy_Data_To_RAM (void)
{
   uint32_t * v_pt_Source;
   uint32_t * v_pt_Data_Start;
   uint32_t * v_pt_Data_End;
   uint32_t   v_Area_Size;
   uint32_t   v_Iter_Area;

   /* {{RELAX<SYNCHRONe_C_Code_11.1> The conversion is mandatory for addresses provided by */
   /* identifiers defined in the linker command file. */
   v_pt_Source = (uint32_t *) &__Linker_Code_End;
   v_pt_Data_Start = (uint32_t *) &__Linker_Data_Start;
   v_pt_Data_End = (uint32_t *) &__Linker_Data_End;
   /* }} RELAX<SYNCHRONe_C_Code_11.1> */

   /* >RELAX<SYNCHRONe_C_Code_11.1> The conversion is mandatory to get the value of the address */
   v_Area_Size = ((uint32_t) v_pt_Data_End - (uint32_t) v_pt_Data_Start) / OVSP_SW_NB_BYTE_IN_LONG;

   for (v_Iter_Area = 0UL; v_Iter_Area < v_Area_Size ; v_Iter_Area++)
   {
      /* >RELAX<SYNCHRONe_C_Code_17.4> Waiting for SYNCHONe analyze, it seems to be a false violation. */
      /* The used form of pointer arithmetic is array indexing. */
      v_pt_Data_Start [v_Iter_Area] = v_pt_Source [v_Iter_Area];
   }
}


/* DrvFTFC_Enable_Flash_Fault_It : To enable the Flash fault interruption
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Set_Status: Status of the setting
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Enable_Flash_Fault_It (uint32_t * const p_pt_Set_Status)
{
   C_DrvFTFC_Registers->S_FERCNFG |= DRVFTFC_FERCNFG_DFDIE_MASK;

   if (DRVFTFC_FERCNFG_DFDIE_MASK == (C_DrvFTFC_Registers->S_FERCNFG & DRVFTFC_FERCNFG_DFDIE_MASK))
   {
      *p_pt_Set_Status = OVSP_SW_RESULT_OK;
   }
   else
   {
      *p_pt_Set_Status = OVSP_SW_RESULT_FAILED;
   }
}


/* DrvFTFC_Clear_Flash_Fault : To clear the Flash fault
 *   Inputs: None
 *   Outputs:
 *     - p_pt_Clear_Status: Status of the clearing
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTFC_Clear_Flash_Fault (uint32_t * const p_pt_Clear_Status)
{
   if (DRVFTFC_FERSTAT_DFDIF_MASK == (C_DrvFTFC_Registers->S_FERSTAT & DRVFTFC_FERSTAT_DFDIF_MASK))
   {
      C_DrvFTFC_Registers->S_FERCNFG = DRVFTFC_FERCNFG_CLEAR_VALUE;
      C_DrvFTFC_Registers->S_FERSTAT |= DRVFTFC_FERSTAT_DFDIF_MASK;

      if (DRVFTFC_FERSTAT_DFDIF_RESET == (C_DrvFTFC_Registers->S_FERSTAT & DRVFTFC_FERSTAT_DFDIF_MASK))
      {
         *p_pt_Clear_Status = OVSP_SW_RESULT_OK;
      }
      else
      {
         *p_pt_Clear_Status = OVSP_SW_RESULT_FAILED;
      }
   }
   else
   {
      *p_pt_Clear_Status = OVSP_SW_RESULT_FAILED;
   }
}
