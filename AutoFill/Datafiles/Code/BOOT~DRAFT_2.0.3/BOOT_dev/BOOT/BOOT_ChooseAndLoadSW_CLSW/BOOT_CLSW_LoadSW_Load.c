#include "BOOT_CLSW_LoadSW_Load.h"
#include "BOOT_CLSW_Buffers.h"
#include "BOOT_CLSW_GetFilesSHA256_FromSIF_Header.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestLUH.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF.h"
#include "BOOT_CLSW_LoadSW_Load_Files.h"
#include "BOOT_Consts.h"
#include "LIBUTI_SIF.h"
#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_COMMON.h"
#include "LIBUTI_MEM.h"
#include "Memcpy.h"

void BOOT_CLSW_LoadSW_Load(
/*IN*/
   const uint8_t* const p_Master_Name,
   const uint32_t p_Master_NumberOfCompatibilityRules,
   const TS_CompatibilityRule* const p_Master_CompatibilityRules,
   const uint32_t p_FlashAddress,
   const uint32_t p_SIFAddress,
   const uint32_t p_ENVMAddress,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   uint32_t* p_NumberOfCompatibilityRules,
   TS_CompatibilityRule* p_CompatibilityRules,
   uint32_t* p_NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo* p_SecondaryLoadsInfo,
   uint32_t* p_LoadedSoftwareLaunchAddress,
   boolean_t* p_LoadFailed,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus *p_LoadStatus
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_Index;
   ts_LIBUTI_SIF_software_info v_SIF_Info;
   uint32_t v_NumberOfFiles;
   uint32_t v_NumberOfDataFiles;
   uint32_t v_NumberOfSupportFiles;
   TS_ARINC_665_FileInfo* pt_ARINC_665_DataFilesInfo;
   TS_ARINC_665_FileInfo* pt_ARINC_665_SupportFilesInfo;
   TE_LIBUTI_SIF_status v_SIF_Status;

   LIBUTI_MEM_MemSet(
      (uint8_t*)&FilesInfoBuffer[0], /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Using area as buffer to initialize */
      (uint8_t)0,
      sizeof(FilesInfoBuffer)
   );
   
   for(v_Index=0ul;v_Index<C_BOOT_MAX_NUMBER_OF_FILES;v_Index++)
   {
      FilesInfoBuffer[v_Index].ARINC_665_FileInfo = (TS_ARINC_665_FileInfo*) &(ARINC_665_FilesInfoBuffer[v_Index]); /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> Each TS_FileInfo stores a pointer to a dedicated TS_ARINC_665_FileInfo */
   }

   BOOT_CLSW_LoadSW_Load_LoadAndTestSIF(p_SIFAddress, p_ENVMAddress, p_FlashReadFailed, p_LoadStatus);
   if (*p_FlashReadFailed || p_LoadStatus->OutOfOperationalCondition || p_LoadStatus->Corrupted)
   {
      *p_LoadFailed = TRUE;
      asm("nop");
      return;
   }   

   v_SIF_Status = LIBUTI_SIF_get_software_info(SIF_HeaderBuffer, &v_SIF_Info);
   if (v_SIF_Status != E_LIBUTI_SIF_SUCCESS)
   {
      *p_LoadFailed = TRUE;
      asm("nop");
      return;
   }

   LibC_Memcpy(
      FilesInfoBuffer[0].ARINC_665_FileInfo->Name,
      v_SIF_Info.PN.Name,
      (uint32_t)v_SIF_Info.PN.Length
   );
   LibC_Memcpy(
      &FilesInfoBuffer[0].ARINC_665_FileInfo->Name[v_SIF_Info.PN.Length],
      C_BOOT_LUH_EXT,
      C_BOOT_LUH_EXT_LENGTH
   );
   FilesInfoBuffer[0].ARINC_665_FileInfo->NameLength = v_SIF_Info.PN.Length + (uint16_t)C_BOOT_LUH_EXT_LENGTH; /* %RELAX<SYNCHRONe_C_Code_10.7> Final name size is 15 + 4 = 19 */
   FilesInfoBuffer[0].ARINC_665_FileInfo->Address = (uint8_t*) p_FlashAddress; /* %RELAX<SYNCHRONe_C_Code_10.7> Library stores address as pointer */
   FilesInfoBuffer[0].Address = LUH_Buffer;

/*Load LUH info from SIF*/
   BOOT_CLSW_GetFilesSHA256_FromSIF_Header
   (
   /*IN*/
      SIF_HeaderBuffer,
      1ul,
      FALSE, NULL, /* %RELAX<SYNCHRONe_C_Code_10.7> No need to filter SIF file right now as the only file in the list is the LUH */
   /*INOUT*/
      FilesInfoBuffer,
   /*OUT*/
      &(p_LoadStatus->OutOfOperationalCondition)
   );
   if(p_LoadStatus->OutOfOperationalCondition)
   {
      return;
   }

   BOOT_CLSW_LoadSW_Load_LoadAndTestLUH(
      &FilesInfoBuffer[0],
      &v_NumberOfFiles,
      &v_NumberOfDataFiles,
      &v_NumberOfSupportFiles,
      &pt_ARINC_665_DataFilesInfo,
      &pt_ARINC_665_SupportFilesInfo,
      p_FlashReadFailed,
      p_LoadStatus);
   if (*p_FlashReadFailed || p_LoadStatus->Corrupted)
   {
      *p_LoadFailed = TRUE;
      asm("nop");
      return;
   }

   LibC_Memcpy(
      p_LoadStatus->PartNumber,
      FilesInfoBuffer[0].ARINC_665_FileInfo->PN,
      (uint32_t)FilesInfoBuffer[0].ARINC_665_FileInfo->PN_Length
   );
   p_LoadStatus->PartNumberSize = FilesInfoBuffer[0].ARINC_665_FileInfo->PN_Length;

   BOOT_CLSW_LoadSW_Load_Files(
      p_Master_Name,
      p_Master_NumberOfCompatibilityRules,
      p_Master_CompatibilityRules,
      p_SIFAddress,
      v_NumberOfFiles,
      v_NumberOfDataFiles,
      v_NumberOfSupportFiles,
      pt_ARINC_665_DataFilesInfo,
      pt_ARINC_665_SupportFilesInfo,
      p_NumberOfCompatibilityRules,
      p_CompatibilityRules,
      p_NumberOfSecondaryLoads,
      p_SecondaryLoadsInfo,
      p_LoadedSoftwareLaunchAddress,
      p_FlashReadFailed,
      p_LoadStatus
   );
   if (  *p_FlashReadFailed
      || p_LoadStatus->Corrupted
      || p_LoadStatus->Incompatible
      || p_LoadStatus->OutOfOperationalCondition)
   {
      *p_LoadFailed = TRUE;
      asm("nop");
      return;
   }
}