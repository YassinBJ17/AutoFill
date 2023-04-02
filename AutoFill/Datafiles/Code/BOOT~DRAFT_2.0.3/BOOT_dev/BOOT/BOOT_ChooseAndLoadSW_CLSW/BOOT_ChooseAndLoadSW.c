#include "BOOT_ChooseAndLoadSW.h"
#include "BOOT_BootDescriptor.h"
#include "BOOT_CLSW_LoadSW.h"
#include "LIBBSP_ENVM.h"



void BOOT_ChooseAndLoadSW(
/*IN*/
   const boolean_t v_PinProgPBIT_Failed,
   const boolean_t v_MajorPBIT_Failed,
   const boolean_t v_CriticalPBIT_Failed,
   const ts_PinProgrammingInputsValues* const p_PinProgrammingInputsValues,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_LoadFailed,
   boolean_t* p_FlashReadFailed,
   uint32_t* p_LoadedSoftwareLaunchAddress,
   ts_LoadStatus* p_PrimaryLoadStatus,
   uint32_t* p_NumberOfSecondaryLoads,
   ts_LoadStatus p_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD]
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_ENVM_ErrorCode v_ENVM_ErrorCode;

   if (v_CriticalPBIT_Failed != FALSE)
   {
      *p_LoadFailed = TRUE;
      return;
   }

   v_ENVM_ErrorCode = LIBBSP_ENVM_Configure(E_LIBBSP_ENVM_COMPAGNON, sizeof(PLD_ENVM_Config) / sizeof(TS_LIBBSP_ENVM_CompagnonMap), &PLD_ENVM_Config[0]);
   if(v_ENVM_ErrorCode != E_LIBBSP_ENVM_OK)
      {*p_LoadFailed = TRUE;return;}

   asm("nop");
   if( v_PinProgPBIT_Failed == FALSE
      && p_PinProgrammingInputsValues->LABO /*Labo=Maintenance*/
      && p_PinProgrammingInputsValues->DTL /*DTL enabled*/
   )
   {
      /*DTL SW*/
      BOOT_CLSW_LoadSW(
      /*IN*/
         C_BOOT_DESCRIPTOR.HardwareCompatibilityID,
         C_BOOT_DESCRIPTOR.NumberOfCompatibilityCriteria,
         C_BOOT_DESCRIPTOR.CompatibilityCriterias,
         /* {{RELAX<SYNCHRONe_C_Code_11.1> Those are external memory addresses and do not point anywhere into mapped memory */
         (uint32_t)C_BOOT_DESCRIPTOR.DTL_LoadFlashAddress,
         (uint32_t)C_BOOT_DESCRIPTOR.DTL_LoadSIF_HeaderENVM_Address,
         C_BOOT_PLD_ENVM_ADDR_DTL_START,
         /* }} RELAX<SYNCHRONe_C_Code_11.1> */
      /*OUT*/
         p_LoadFailed,
         p_FlashReadFailed,
         p_LoadedSoftwareLaunchAddress,
         p_PrimaryLoadStatus,
         p_NumberOfSecondaryLoads,
         p_SecondaryLoadsStatus
      );
      asm("nop");
   }
   else if (v_MajorPBIT_Failed == FALSE)
   {
      /*APPLICATIVE SW*/
      BOOT_CLSW_LoadSW(
      /*IN*/
         C_BOOT_DESCRIPTOR.HardwareCompatibilityID,
         C_BOOT_DESCRIPTOR.NumberOfCompatibilityCriteria,
         C_BOOT_DESCRIPTOR.CompatibilityCriterias,
         /* {{RELAX<SYNCHRONe_C_Code_11.1> Those are external memory addresses and do not point anywhere into mapped memory */
         (uint32_t)C_BOOT_DESCRIPTOR.OpeLoadFlashAddress,
         (uint32_t)C_BOOT_DESCRIPTOR.OpeLoadSIF_HeaderENVM_Address,
         C_BOOT_PLD_ENVM_ADDR_OPR_START + (((uint32_t)C_BOOT_DESCRIPTOR.OpeLoadSIF_HeaderENVM_Address & 0x1FFFFul) / 0x10ul),
         /* }} RELAX<SYNCHRONe_C_Code_11.1> */
      /*OUT*/
         p_LoadFailed,
         p_FlashReadFailed,
         p_LoadedSoftwareLaunchAddress,
         p_PrimaryLoadStatus,
         p_NumberOfSecondaryLoads,
         p_SecondaryLoadsStatus
      );
      asm("nop");
   }
   else
   {
      /*ABORT BOOT*/
      *p_LoadFailed = TRUE;
      asm("nop");
   }
}