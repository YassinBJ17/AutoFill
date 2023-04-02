#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSUP.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTest.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSUP(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   const uint32_t p_NumberOfDataFiles,
   /*INOUT*/
   /* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   TS_FileInfo* p_DataFilesInfo,
   /*OUT*/
   uint32_t* p_LoadedSoftwareLaunchAddress,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
   /* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   boolean_t v_LaunchAddressFound;
   uint8_t* v_LaunchAddress;

   BOOT_CLSW_LoadSW_Load_LoadAndTest(p_FileInfo, p_FlashReadFailed, p_LoadStatus);
   if(*p_FlashReadFailed || p_LoadStatus->Corrupted)
   {
      return;
   }

   LIBUTI_CMN_ParseSUP
   (
   /*IN*/
      p_FileInfo->Address,
      p_NumberOfDataFiles,
   /*INOUT*/
      p_DataFilesInfo,
   /*OUT*/
      &v_LaunchAddressFound,
      &v_LaunchAddress,
      &(p_LoadStatus->OutOfOperationalCondition)
   );
   /* >RELAX<SYNCHRONe_C_Code_10.7> Pointer comparison with NULL do not imply loss of precision */
   if(p_LoadedSoftwareLaunchAddress != NULL)
   {
      if (v_LaunchAddressFound)
      {
         *p_LoadedSoftwareLaunchAddress = (uint32_t) v_LaunchAddress; /* %RELAX<SYNCHRONe_C_Code_11.1> Address will be handled as uint32_t */
      }
      else
      {
         p_LoadStatus->OutOfOperationalCondition = TRUE;
      }
   }
   else
   {
      if (v_LaunchAddressFound)
      {
         p_LoadStatus->OutOfOperationalCondition = TRUE;
      }
   }
}
