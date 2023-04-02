#include "BOOT_CLSW_LoadSW.h"
#include "BOOT_CLSW_LoadSW_Load.h"
#include "BOOT_Consts.h"

void BOOT_CLSW_LoadSW(
/*IN*/
   const uint8_t* const p_BOOT_Name,
   const uint32_t p_BOOT_NumberOfCompatibilityRules,
   const TS_CompatibilityRule p_BOOT_CompatibilityRules[C_BOOT_MAX_NUMBER_OF_COMPAT_RULES],
   const uint32_t p_PrimaryLoadLUH_FlashAddress,
   const uint32_t p_PrimaryLoadSIF_Header_FlashAddress,
   const uint32_t p_PrimaryLoadSIF_SHA_EnvmAddress,
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
   uint32_t v_index;
   uint32_t v_PrimaryLoadNumberOfCompatibilityRules;
   TS_CompatibilityRule v_PrimaryLoadCompatibilityRules[C_BOOT_MAX_NUMBER_OF_COMPAT_RULES];
   TS_SecondaryLoadInfo v_SecondaryLoadsInfo[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD];
   uint32_t v_SecondaryLoadNumberOfCompatibilityRules;
   TS_CompatibilityRule v_SecondaryLoadCompatibilityRules[C_BOOT_MAX_NUMBER_OF_COMPAT_RULES];

/*Applicative software primary load*/
   BOOT_CLSW_LoadSW_Load(
   /*IN*/
      p_BOOT_Name,
      p_BOOT_NumberOfCompatibilityRules,
      p_BOOT_CompatibilityRules,
      p_PrimaryLoadLUH_FlashAddress,
      p_PrimaryLoadSIF_Header_FlashAddress,
      p_PrimaryLoadSIF_SHA_EnvmAddress,
   /*OUT*/
      &v_PrimaryLoadNumberOfCompatibilityRules,
      &(v_PrimaryLoadCompatibilityRules[0]),
      p_NumberOfSecondaryLoads,
      v_SecondaryLoadsInfo,
      p_LoadedSoftwareLaunchAddress,
      p_LoadFailed,
      p_FlashReadFailed,
      p_PrimaryLoadStatus
   );
   if (*p_LoadFailed == FALSE)
   {
/*Applicative software secondary loads*/
      for(v_index=0ul;v_index<*p_NumberOfSecondaryLoads;v_index++)
      {
         BOOT_CLSW_LoadSW_Load(
         /*IN*/
            p_PrimaryLoadStatus->Name,
            v_PrimaryLoadNumberOfCompatibilityRules,
            &(v_PrimaryLoadCompatibilityRules[0]),
            /* {{RELAX<SYNCHRONe_C_Code_11.1> Those are external memory addresses and do not point anywhere into mapped memory */
            (uint32_t)v_SecondaryLoadsInfo[v_index].FlashAddress,
            (uint32_t)v_SecondaryLoadsInfo[v_index].SIF_HeaderENVM_Address,
            C_BOOT_PLD_ENVM_ADDR_OPR_START + (((uint32_t)v_SecondaryLoadsInfo[v_index].SIF_HeaderENVM_Address & 0x1FFFFul) / 0x10ul),
            /* }} RELAX<SYNCHRONe_C_Code_11.1> */
         /*OUT*/
            &v_SecondaryLoadNumberOfCompatibilityRules,
            &(v_SecondaryLoadCompatibilityRules[0]),
            NULL, NULL, NULL, /* %RELAX<SYNCHRONe_C_Code_10.7> Those parameters are not needed for secondary loads */
            p_LoadFailed,
            p_FlashReadFailed,
            &(p_SecondaryLoadsStatus[v_index])
         );
         *p_LoadFailed = *p_FlashReadFailed;
         if(*p_LoadFailed)
         {
            break;
         }
      }
   }
}