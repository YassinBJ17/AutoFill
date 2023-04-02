/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the function to initialize the VTOR in SRAM
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvNVIC_Public.h"
#include "DrvNVIC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CBIT_Public.h"
#include "DrvCAN_Public.h"
#include "DrvMCM_Public.h"
#include "DrvFTM_Public.h"
#include "Seq_Public.h"

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
/* DrvNVIC_Init_VTOR_InSRAM: To initialize the VTOR in SRAM
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvNVIC_Init_VTOR_InSRAM (void)
{
   uint32_t v_Iter;

   uint32_t * const v_VTOR_Offset_Register = (uint32_t *) DRVNVIC_VTOR_OFFSET_REG_ADDR;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as they are 32-bit Unsigned Long address */
   /* converted to pointers which are also an 32-bit Unsigned Long. */
   /* >RELAX<SYNCHRONe_C_Code_16.11> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* All the functions pointed are identical in the number and type of parameters and the return type. */
   volatile TPTF_DrvNVIC_VectorsTable * v_SRAM_VectorTable = (TPTF_DrvNVIC_VectorsTable *) DRVNVIC_VTOR_SRAM_ADDR;

   /* {{RELAX<SYNCHRONe_C_Code_17.4> Waiting for SYNCHONe analyze, it seems to be a false violation. */
   /* The used form of pointer arithmetic is array indexing. */
   for (v_Iter = 0UL; v_Iter < DRVNVIC_CPU_VECTORS_NB ; v_Iter++)
   {
      v_SRAM_VectorTable [v_Iter] = C_DrvNVIC_VectorsTable_CPU [v_Iter];
   }

   for (v_Iter = DRVNVIC_CPU_VECTORS_NB; v_Iter < DRVNVIC_VTOR_SIZE ; v_Iter++)
   {
      v_SRAM_VectorTable [v_Iter] = &DrvNVIC_Unmapped_IRQ;
   }

   v_SRAM_VectorTable [DRVNVIC_VTOR_FPU_INDEX]           = &DrvMCM_Check_CBIT_FPU_IRQ;
   v_SRAM_VectorTable [DRVNVIC_VTOR_FTFC_INDEX]          = &CBIT_ECC_FTFC_Int_Double_Bit_Err;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ECC_SINGLE_INDEX]    = &CBIT_Test_ECC_Int_Single;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ECC_MULTI_INDEX]     = &CBIT_Test_ECC_Int_Multiple;
   v_SRAM_VectorTable [DRVNVIC_VTOR_TASK_MAIN_INDEX]     = &Seq_Task_Main;
   v_SRAM_VectorTable [DRVNVIC_VTOR_CAN1_INDEX]          = &DrvCAN_Read;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ACQ_TSPEED_HS_INDEX] = C_PtF_DrvFTM_Acq_Raw_TSpeed;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ACQ_NTLOS1_INDEX]    = C_PtF_DrvFTM_Acq_NTLOS1;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ACQ_NGOS1_INDEX]     = C_PtF_DrvFTM_Acq_NGOS1;
   v_SRAM_VectorTable [DRVNVIC_VTOR_CNT_FTM0_OVF_INDEX]  = C_PtF_DrvFTM_Count_FTM0_Overflow;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ACQ_TSPEED_LS_INDEX] = C_PtF_DrvFTM_Acq_Raw_TSpeed;
   v_SRAM_VectorTable [DRVNVIC_VTOR_CNT_FTM1_OVF_INDEX]  = C_PtF_DrvFTM_Count_FTM1_Overflow;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ACQ_NGOS2_INDEX]     = C_PtF_DrvFTM_Acq_NGOS2;
   v_SRAM_VectorTable [DRVNVIC_VTOR_ACQ_NTLOS2_INDEX]    = C_PtF_DrvFTM_Acq_NTLOS2;
   v_SRAM_VectorTable [DRVNVIC_VTOR_CNT_FTM3_OVF_INDEX]  = C_PtF_DrvFTM_Count_FTM3_Overflow;
   /* }} RELAX<SYNCHRONe_C_Code_17.4> */
   /* }} RELAX<SYNCHRONe_C_Code_10.7> */

   asm("DMB");

   *v_VTOR_Offset_Register = DRVNVIC_VTOR_SRAM_ADDR;

   asm("DSB");
}
