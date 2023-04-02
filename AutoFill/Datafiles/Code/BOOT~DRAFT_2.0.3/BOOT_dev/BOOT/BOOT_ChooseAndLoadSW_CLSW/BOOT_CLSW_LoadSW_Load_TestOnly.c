#include "BOOT_CLSW_LoadSW_Load_TestOnly.h"
#include "BOOT_Consts.h"
#include "BOOT_CLSW_Buffers.h"
#include "LIBBSP_FNOR.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SHA.h"

void BOOT_CLSW_LoadSW_Load_TestOnly(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   /*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_FNOR_ErrorCode v_FNOR_ErrorCode;
   uint32_t v_NumberOfBufferSizedChunksInLUP;
   uint32_t v_SizeOfCurrentChunkOfLUP;
   uint32_t v_SizeOfLastChunkOfLUP;
   ts_LIBUTI_SHA_SHA256_ctx v_SHA_256_ComputationContext;
   ts_LIBUTI_SHA_SHA256 v_SHA256_Buffer;
   uint32_t v_Index;
   uint32_t v_FileSize;

   v_FileSize = (uint32_t)p_FileInfo->ARINC_665_FileInfo->Length; /* %RELAX<SYNCHRONe_C_Code_10.7> A665 v3 stores length on 64bits but we do not use files bigger than 4GB */
   v_SizeOfLastChunkOfLUP = v_FileSize % C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE;
   if(v_SizeOfLastChunkOfLUP == 0ul)
   {
      v_NumberOfBufferSizedChunksInLUP = v_FileSize / C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE;
      v_SizeOfLastChunkOfLUP = C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE;
   }
   else
   {
      v_NumberOfBufferSizedChunksInLUP = (v_FileSize - v_SizeOfLastChunkOfLUP) / C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE;
   }
   if(v_NumberOfBufferSizedChunksInLUP != 0ul)
   {
      LIBUTI_SHA_initSHA256(&v_SHA_256_ComputationContext);
      v_SizeOfCurrentChunkOfLUP = C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE;
      for(v_Index=0ul;v_Index<v_NumberOfBufferSizedChunksInLUP;v_Index++)
      {
         if(v_Index == v_NumberOfBufferSizedChunksInLUP - 1ul)
         {
            v_SizeOfCurrentChunkOfLUP = v_SizeOfLastChunkOfLUP;
         }
         v_FNOR_ErrorCode = LIBBSP_FNOR_FastRead(
            E_LIBBSP_SPI_FLASH_PROGRAM,
            (uint32_t)p_FileInfo->ARINC_665_FileInfo->Address /* %RELAX<SYNCHRONe_C_Code_11.1> Both APIs are using different conventions for addresses */
               + (v_Index * C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE),
            v_SizeOfCurrentChunkOfLUP,
            (uint8_t*)FlashIntegrityCheckLUP_Buffer
         );
         if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK)
            {*p_FlashReadFailed = TRUE;LIBBSP_FNOR_Close();return;}
         LIBUTI_SHA_updateSHA256(
            &v_SHA_256_ComputationContext,
            (uint8_t*) FlashIntegrityCheckLUP_Buffer,
            v_SizeOfCurrentChunkOfLUP
         );
      }
      LIBBSP_FNOR_Close();
      LIBUTI_SHA_finalSHA256(&v_SHA_256_ComputationContext, &v_SHA256_Buffer);
      p_LoadStatus->Corrupted = LIBUTI_MEM_MemsNotEqual(
         v_SHA256_Buffer.Data,
         p_FileInfo->ExpectedSHA256.Data,
         (uint32_t)SHA256_BLOCK_SIZE
      );
   }
}
