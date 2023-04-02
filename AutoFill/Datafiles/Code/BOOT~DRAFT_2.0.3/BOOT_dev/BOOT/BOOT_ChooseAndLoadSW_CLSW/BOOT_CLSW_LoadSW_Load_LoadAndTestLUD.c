#include "BOOT_CLSW_LoadSW_Load_LoadAndTestLUD.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTest.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestLUD(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   /*OUT*/
   /* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   uint32_t* p_NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo* p_SecondaryLoadsInfo,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
   /* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   BOOT_CLSW_LoadSW_Load_LoadAndTest(p_FileInfo, p_FlashReadFailed, p_LoadStatus);
   if(*p_FlashReadFailed || p_LoadStatus->Corrupted)
   {
      return;
   }

   /* >RELAX<SYNCHRONe_C_Code_10.7> Pointer comparison with NULL do not imply loss of precision */
   if(p_NumberOfSecondaryLoads != NULL && p_SecondaryLoadsInfo != NULL)
   {
      LIBUTI_CMN_ParseLUD
      (
      /*IN*/
         p_FileInfo->Address,
         C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD,
      /*OUT*/
         p_NumberOfSecondaryLoads,
         p_SecondaryLoadsInfo,
         &(p_LoadStatus->OutOfOperationalCondition)
      );
   }
   else
   {
      p_LoadStatus->OutOfOperationalCondition = TRUE;
   }
}
