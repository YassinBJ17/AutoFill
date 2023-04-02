#include "BOOT_CLSW_LoadSW_Load_AESdecrypt.h"
#include "BOOT_CLSW_Buffers.h"
#include "BOOT_Consts.h"
#include "LIBUTI_AES.h"
#include "LIBUTI_CRC.h"
#include "LIBUTI_COMMON.h"
#include "LIBUTI_MEM.h"
#include "LIBBSP_ENVM.h"
#include "LIBBSP_MRAM.h"
#include "LIBBSP_RMM.h"

void BOOT_CLSW_LoadSW_Load_AESdecrypt(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   const uint32_t p_SIFAddress,
   /*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_ENVM_ErrorCode v_ENVM_ErrorCode;
   TE_LIBBSP_MRAM_ErrorCode v_MRAM_ErrorCode;
   boolean_t v_AES_Decode_Status;
   TE_LIBBSP_I2C_Code v_RMM_ErrorCode;
   uint16_t v_CRC16_Buffer;
   uint32_t v_AES_DecryptedSize;
   uint32_t v_Index;

   v_MRAM_ErrorCode = E_LIBBSP_MRAM_OK;
   v_RMM_ErrorCode = E_LIBBSP_I2C_OK;

   if ((p_SIFAddress & 0x80000000ul) == 0ul)
   {
      v_MRAM_ErrorCode = LIBBSP_MRAM_Open();
      if(v_MRAM_ErrorCode == E_LIBBSP_MRAM_OK)
      {
         LIBBSP_MRAM_Read(
            C_BOOT_MRAM_AESKEY_ZONE_OFFSET + ((p_SIFAddress & 0x1FFFFul) / 0x10ul),
            C_BOOT_AES_KEY_MAX_LENGTH,
            (uint8_t*)AES_KeyBuffer,
            &v_MRAM_ErrorCode
         );
         (void) LIBBSP_MRAM_Close();
      }
   }
   else
   {
      v_RMM_ErrorCode = LIBBSP_RMM_Open();
      if (v_RMM_ErrorCode == E_LIBBSP_I2C_OK)
      {
         LIBBSP_RMM_Read(
            C_BOOT_RMM_ADDR_AES_START + (((((p_SIFAddress & 0x7FFFFFFFul) - C_BOOT_RMM_ADDR_SIF_START) & 0x1000ul) / 0x1000ul) * 0x200ul),
            C_BOOT_AES_KEY_MAX_LENGTH,
            (uint8_t*)AES_KeyBuffer,
            &v_RMM_ErrorCode
         );
         (void) LIBBSP_RMM_Close();
      }
   }
   if(v_MRAM_ErrorCode != E_LIBBSP_MRAM_OK || v_RMM_ErrorCode != E_LIBBSP_I2C_OK)
   {
/*Out of operational condition MRAM*/
      *p_FlashReadFailed = TRUE;
      p_LoadStatus->OutOfOperationalCondition = TRUE;
      LIBUTI_MEM_MemSet(AES_KeyBuffer, (uint8_t)0, C_BOOT_AES_KEY_MAX_LENGTH);
      asm("nop");
      return;
   }
   v_ENVM_ErrorCode = LIBBSP_ENVM_Open(E_LIBBSP_ENVM_COMPAGNON);
   if(v_ENVM_ErrorCode == E_LIBBSP_ENVM_OK)
   {
      LIBBSP_ENVM_Read(
         E_LIBBSP_ENVM_COMPAGNON,
         C_BOOT_PLD_ENVM_ADDR_AES_START,
         C_BOOT_AES_KEY_MAX_LENGTH,
         (uint8_t*)AES_MaskBuffer,
         &v_ENVM_ErrorCode
      );
      (void) LIBBSP_ENVM_Close(E_LIBBSP_ENVM_COMPAGNON);
   }
   if(v_ENVM_ErrorCode != E_LIBBSP_ENVM_OK)
   {
      *p_FlashReadFailed = TRUE;
      p_LoadStatus->OutOfOperationalCondition = TRUE;
      LIBUTI_MEM_MemSet(AES_KeyBuffer, (uint8_t)0, C_BOOT_AES_KEY_MAX_LENGTH);
      LIBUTI_MEM_MemSet(AES_MaskBuffer, (uint8_t)0, C_BOOT_AES_KEY_MAX_LENGTH);
      return;
   }
   for (v_Index=0ul;v_Index<C_BOOT_AES_KEY_MAX_LENGTH;v_Index++)
   {
      AES_KeyBuffer[v_Index] ^= AES_MaskBuffer[v_Index];
   }
   LIBUTI_MEM_MemSet(AES_MaskBuffer, (uint8_t)0, C_BOOT_AES_KEY_MAX_LENGTH);
   v_AES_Decode_Status = LIBUTI_AES_decrypt_in_place(
      p_FileInfo->Address,
      (uint32_t)p_FileInfo->ARINC_665_FileInfo->Length, /* %RELAX<SYNCHRONe_C_Code_10.7> A665 v3 stores length on 64bits but we do not use files bigger than 4GB */
      AES_KeyBuffer,
      E_LIBUTI_AES_KEY_SIZE_256,
      &v_AES_DecryptedSize
   );
   if (v_AES_Decode_Status == FALSE)
   {
      /*Corrupted LUP*/
      p_LoadStatus->Corrupted = TRUE;
      asm("nop");
      return;
   }
   LIBUTI_MEM_MemSet(AES_KeyBuffer, (uint8_t)0, C_BOOT_AES_KEY_MAX_LENGTH);
   v_CRC16_Buffer = LIBUTI_CRC_ComputeCRC16(p_FileInfo->Address, v_AES_DecryptedSize);
   if(v_CRC16_Buffer != p_FileInfo->ExpectedCRC16)
   {
/*Corrupted LUP*/
      p_LoadStatus->Corrupted = TRUE;
      asm("nop");
      return;
   }
}
