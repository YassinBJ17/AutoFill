#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_FNOR.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_RMM.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_ENVM.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_RMM.h"
#include "BOOT_CLSW_Buffers.h"
#include "LIBUTI_MEM.h"
#include "LIBUTI_SHA.h"
boolean_t BOOT_CLSW_LoadSW_Load_LoadAndTestSIF(const uint32_t p_SIFAddress,
const uint32_t p_ENVMAddress,
boolean_t* p_FlashReadFailed,
TE_ParseLUH_CheckValueTpe p_LoadStatu)
{
   ts_BOOT_Data v_BootData;
   ts_LIBUTI_SHA_SHA256 v_SHA256_Buffer;

   v_BootData.size = C_BOOT_SIF_HEADER_MAX_LENGTH;
   if ((p_SIFAddress & 0x80000000ul) == 0ul)
   {
      BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_ENVM(p_ENVMAddress, &v_BootData, p_FlashReadFailed);
   }
   else
   {
      BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_RMM(p_SIFAddress, &v_BootData, p_FlashReadFailed, p_LoadStatus);
   }
   if (*p_FlashReadFailed != FALSE){return;}

   /* Check if the checksum is relevant */
   if(v_BootData.size > C_BOOT_SIF_HEADER_MAX_LENGTH)
   {
      p_LoadStatus->OutOfOperationalCondition = TRUE;
      return;
   }

   if ((p_SIFAddress & 0x80000000ul) == 0ul)
   {
      BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_FNOR(p_SIFAddress, &v_BootData, SIF_HeaderBuffer, p_FlashReadFailed);
   }
   else
   {
      BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_RMM(p_SIFAddress, &v_BootData, SIF_HeaderBuffer, p_FlashReadFailed);
   }
   if (*p_FlashReadFailed != FALSE){return;}

   /* Compare checksums */
   LIBUTI_SHA_ComputeSHA256(SIF_HeaderBuffer, v_BootData.size, &v_SHA256_Buffer);
   p_LoadStatus->Corrupted = LIBUTI_MEM_MemsNotEqual(
      v_SHA256_Buffer.Data,
      v_BootData.sha256.Data,
      (uint32_t)SHA256_BLOCK_SIZE
   );
}
