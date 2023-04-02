#include "BOOT_CLSW_LoadSW_Load_LoadAndTestCMP.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTest.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestCMP(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   const uint8_t* const p_Master_Name,
   const uint32_t p_Master_NumberOfCompatibilityRules,
   const TS_CompatibilityRule* const p_Master_CompatibilityRules,
   /*OUT*/
   /* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_LoadedByBoot,
   boolean_t* p_CheckedByBootInFlash,
   uint32_t* p_NumberOfCompatibilityRules,
   TS_CompatibilityRule* p_CompatibilityRules,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
   /* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint8_t v_DUMMY_AmendmentInfo[C_AMENDMENT_INFO_MAX_LENGTH];
   uint32_t v_DUMMY_Destination;
   uint32_t v_DUMMY_LoadType;

   BOOT_CLSW_LoadSW_Load_LoadAndTest(p_FileInfo, p_FlashReadFailed, p_LoadStatus);
   if(*p_FlashReadFailed || p_LoadStatus->Corrupted)
   {
      return;
   }

   LIBUTI_CMN_ParseCMP
   (
   /*IN*/
      p_FileInfo->Address,
      C_BOOT_MAX_NUMBER_OF_COMPAT_RULES,
   /*OUT*/
      &(p_LoadStatus->Name[0]),
      p_NumberOfCompatibilityRules,
      p_CompatibilityRules,
      p_LoadedByBoot,
      p_CheckedByBootInFlash,
      v_DUMMY_AmendmentInfo,
      &v_DUMMY_Destination,
      &v_DUMMY_LoadType,
      &(p_LoadStatus->OutOfOperationalCondition)
   );
   if(p_LoadStatus->OutOfOperationalCondition)
   {
      return;
   }
/*HW compatibility check*/
   LIBUTI_CMN_TestCompatibilityBetweenLoads
   (
   /*IN*/
      p_Master_Name,
      p_Master_NumberOfCompatibilityRules,
      p_Master_CompatibilityRules,
      p_LoadStatus->Name,
      *p_NumberOfCompatibilityRules,
      p_CompatibilityRules,
   /*OUT*/
      &(p_LoadStatus->Incompatible)
   );
}
