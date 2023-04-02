#include "BOOT_CLSW_LoadSW_Load_LoadAndTest.h"
#include "LIBBSP_FNOR.h"
#include "LIBUTI_MEM.h"
#include "LIBBSP_RMM.h"
#include "LIBUTI_SHA.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTest(
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
   TE_LIBBSP_I2C_Code v_RMM_ErrorCode;
   ts_LIBUTI_SHA_SHA256 v_SHA256_Buffer;

   if (((uint32_t)(p_FileInfo->ARINC_665_FileInfo->Address) & 0x80000000ul) == 0ul) /* %RELAX<SYNCHRONe_C_Code_11.1> convertion needed to use check location of memory */
   {
      v_FNOR_ErrorCode = LIBBSP_FNOR_Open(E_LIBBSP_SPI_FLASH_PROGRAM);
      if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK) {*p_FlashReadFailed = TRUE;return;}

      v_FNOR_ErrorCode = LIBBSP_FNOR_FastRead(
         E_LIBBSP_SPI_FLASH_PROGRAM,
         (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Address), /* %RELAX<SYNCHRONe_C_Code_11.1> Both APIs are using different conventions for addresses */
         (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Length), /* %RELAX<SYNCHRONe_C_Code_10.7> A665 v3 stores length on 64bits but we do not use files bigger than 4GB */
         p_FileInfo->Address
      );
      LIBBSP_FNOR_Close();
      if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK) {*p_FlashReadFailed = TRUE;return;}
   }
   else
   {
      v_RMM_ErrorCode = LIBBSP_RMM_Open();
      if(v_RMM_ErrorCode != E_LIBBSP_I2C_OK) {*p_FlashReadFailed = TRUE;return;}

      LIBBSP_RMM_Read(
         (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Address) & 0x7FFFFFFFul, /* %RELAX<SYNCHRONe_C_Code_11.1> Both APIs are using different conventions for addresses */
         (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Length), /* %RELAX<SYNCHRONe_C_Code_10.7> A665 v3 stores length on 64bits but we do not use files bigger than 4GB */
         p_FileInfo->Address,
         &v_RMM_ErrorCode
      );
      (void) LIBBSP_RMM_Close();
      if(v_RMM_ErrorCode != E_LIBBSP_I2C_OK) {*p_FlashReadFailed = TRUE;return;}
   }

   LIBUTI_SHA_ComputeSHA256(
      p_FileInfo->Address,
      (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Length), /* %RELAX<SYNCHRONe_C_Code_10.7> A665 v3 stores length on 64bits but we do not use files bigger than 4GB */
      &v_SHA256_Buffer
   );
   p_LoadStatus->Corrupted = LIBUTI_MEM_MemsNotEqual(
      v_SHA256_Buffer.Data,
      p_FileInfo->ExpectedSHA256.Data,
      (uint32_t)SHA256_BLOCK_SIZE
   );
}
