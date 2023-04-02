#include "BOOT_CLSW_LoadSW_Load_LoadAndDecrypt.h"
#include "BOOT_CLSW_LoadSW_Load_AESdecrypt.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTest.h"
#include "BOOT_CLSW_LoadSW_Load_TestOnly.h"

void BOOT_CLSW_LoadSW_Load_LoadAndDecrypt(
   /*IN*/
   const TS_FileInfo p_DataFilesInfo[C_BOOT_MAX_NUMBER_OF_DATA_FILES],
   const uint32_t p_SIFAddress,
   const uint32_t p_NumberOfDataFiles,
   const boolean_t p_LoadedByBoot,
   const boolean_t p_CheckedByBootInFlash,
   /*OUT*/
   /* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
   /* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_Index;

   if (p_LoadedByBoot)
   {
      for(v_Index=0ul;v_Index<p_NumberOfDataFiles;v_Index++)
      {
         BOOT_CLSW_LoadSW_Load_LoadAndTest(&p_DataFilesInfo[v_Index], p_FlashReadFailed, p_LoadStatus);
         if(*p_FlashReadFailed || p_LoadStatus->Corrupted)
         {
            return;
         }
         if (p_DataFilesInfo[v_Index].Encrypted != FALSE)
         {
            BOOT_CLSW_LoadSW_Load_AESdecrypt
            (
            /*IN*/
               &p_DataFilesInfo[v_Index],
               p_SIFAddress,
            /*OUT*/
               p_FlashReadFailed,
               p_LoadStatus
            );
            if (*p_FlashReadFailed || p_LoadStatus->Corrupted)
            {
               return;
            }
         }
      }
   }
   else if (p_CheckedByBootInFlash)
   {
      for(v_Index=0ul;v_Index<p_NumberOfDataFiles;v_Index++)
      {
         BOOT_CLSW_LoadSW_Load_TestOnly(&p_DataFilesInfo[v_Index], p_FlashReadFailed, p_LoadStatus);
         if(*p_FlashReadFailed || p_LoadStatus->Corrupted)
         {
            return;
         }
      }
   }
}
