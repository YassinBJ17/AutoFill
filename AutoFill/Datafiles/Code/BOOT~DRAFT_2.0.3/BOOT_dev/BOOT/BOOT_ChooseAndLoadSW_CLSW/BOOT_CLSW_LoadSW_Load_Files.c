#include "BOOT_CLSW_LoadSW_Load_Files.h"
#include "BOOT_CLSW_Buffers.h"
#include "BOOT_CLSW_GetFilesSHA256_FromSIF_Header.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndDecrypt.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestCMP.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestLUD.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSUP.h"

void BOOT_CLSW_LoadSW_Load_Files(
   /*IN*/
   const uint8_t* const p_Master_Name,
   const uint32_t p_Master_NumberOfCompatibilityRules,
   const TS_CompatibilityRule* const p_Master_CompatibilityRules,
   const uint32_t p_SIFAddress,
   const uint32_t p_NumberOfFiles,
   const uint32_t p_NumberOfDataFiles,
   const uint32_t p_NumberOfSupportFiles,
   const TS_ARINC_665_FileInfo* const p_ARINC_665_DataFilesInfo,
   const TS_ARINC_665_FileInfo* const p_ARINC_665_SupportFilesInfo,
   /*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   uint32_t* p_NumberOfCompatibilityRules,
   TS_CompatibilityRule* p_CompatibilityRules,
   uint32_t* p_NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo* p_SecondaryLoadsInfo,
   uint32_t* p_LoadedSoftwareLaunchAddress,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TS_FileInfo* pt_DataFilesInfo;
   TS_FileInfo* pt_SupportFilesInfo;
   boolean_t v_CMP_FileFound;
   TS_FileInfo* pt_CMP_FileInfo;
   boolean_t v_SUP_FileFound;
   TS_FileInfo* pt_SUP_FileInfo;
   boolean_t v_LUD_FileFound;
   TS_FileInfo* pt_LUD_FileInfo;
   boolean_t v_SIF_FileFound;
   TS_FileInfo* pt_SIF_FileInfo;
   boolean_t v_SKF_FileFound;
   TS_FileInfo* pt_SKF_FileInfo;
   boolean_t v_LoadedByBoot;
   boolean_t v_CheckedByBootInFlash;
   uint32_t v_Index;

   /* {{RELAX<SYNCHRONe_C_Code_10.7> Init entry point for DataFilesInfo */
   pt_DataFilesInfo = &FilesInfoBuffer[1];
   pt_SupportFilesInfo = &FilesInfoBuffer[1];
   /* }} RELAX<SYNCHRONe_C_Code_10.7> */
   for(v_Index=1ul;v_Index<=p_NumberOfFiles;v_Index++)
   {
      if(FilesInfoBuffer[v_Index].ARINC_665_FileInfo == p_ARINC_665_DataFilesInfo)
      {
         pt_DataFilesInfo = &(FilesInfoBuffer[v_Index]); /* %RELAX<SYNCHRONe_C_Code_10.7> Storing entry point for DataFilesInfo */
      }
      if(FilesInfoBuffer[v_Index].ARINC_665_FileInfo == p_ARINC_665_SupportFilesInfo)
      {
         pt_SupportFilesInfo = &(FilesInfoBuffer[v_Index]); /* %RELAX<SYNCHRONe_C_Code_10.7> Storing entry point for SupportFilesInfo */
      }
   }

   LIBUTI_CMN_IdentifySupportFiles
   (
   /*IN*/
      p_NumberOfSupportFiles,
      pt_SupportFilesInfo,
   /*OUT*/
      &v_CMP_FileFound,
      &pt_CMP_FileInfo,
      &v_SUP_FileFound,
      &pt_SUP_FileInfo,
      &v_LUD_FileFound,
      &pt_LUD_FileInfo,
      &v_SIF_FileFound,
      &pt_SIF_FileInfo,
      &v_SKF_FileFound,
      &pt_SKF_FileInfo,
      &(p_LoadStatus->OutOfOperationalCondition)
   );
   if((p_LoadStatus->OutOfOperationalCondition)
   || (v_CMP_FileFound == FALSE)
   || (v_SUP_FileFound == FALSE))
   {
      p_LoadStatus->OutOfOperationalCondition = TRUE;
      return;
   }
   
   BOOT_CLSW_GetFilesSHA256_FromSIF_Header
   (
   /*IN*/
      SIF_HeaderBuffer,
      p_NumberOfFiles,
      v_SIF_FileFound,
      pt_SIF_FileInfo,
   /*INOUT*/
      &(FilesInfoBuffer[1]),
   /*OUT*/
      &(p_LoadStatus->OutOfOperationalCondition)
   );
   if(p_LoadStatus->OutOfOperationalCondition)
   {
      return;
   }

   pt_CMP_FileInfo->Address = CMP_Buffer;
   BOOT_CLSW_LoadSW_Load_LoadAndTestCMP(
      pt_CMP_FileInfo,
      p_Master_Name,
      p_Master_NumberOfCompatibilityRules,
      p_Master_CompatibilityRules,
      &v_LoadedByBoot,
      &v_CheckedByBootInFlash,
      p_NumberOfCompatibilityRules,
      p_CompatibilityRules,
      p_FlashReadFailed,
      p_LoadStatus
   );
   if (  *p_FlashReadFailed
      || p_LoadStatus->Corrupted
      || p_LoadStatus->Incompatible
      || p_LoadStatus->OutOfOperationalCondition)
   {
      return;
   }

   pt_SUP_FileInfo->Address = SUP_Buffer;
   BOOT_CLSW_LoadSW_Load_LoadAndTestSUP(
      pt_SUP_FileInfo,
      p_NumberOfDataFiles,
      pt_DataFilesInfo,
      p_LoadedSoftwareLaunchAddress,
      p_FlashReadFailed,
      p_LoadStatus
   );
   if (  *p_FlashReadFailed
      || p_LoadStatus->Corrupted
      || p_LoadStatus->OutOfOperationalCondition)
   {
      return;
   }

   if(v_LUD_FileFound)
   {
      pt_LUD_FileInfo->Address = LUD_Buffer;
      BOOT_CLSW_LoadSW_Load_LoadAndTestLUD(
         pt_LUD_FileInfo,
         p_NumberOfSecondaryLoads,
         p_SecondaryLoadsInfo,
         p_FlashReadFailed,
         p_LoadStatus
      );
      if (  *p_FlashReadFailed
         || p_LoadStatus->Corrupted
         || p_LoadStatus->OutOfOperationalCondition)
      {
         return;
      }
   }

   BOOT_CLSW_LoadSW_Load_LoadAndDecrypt(
      pt_DataFilesInfo,
      p_SIFAddress,
      p_NumberOfDataFiles,
      v_LoadedByBoot,
      v_CheckedByBootInFlash,
      p_FlashReadFailed,
      p_LoadStatus
   );
}
