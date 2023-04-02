#include "RAMBOOT_CopyAndBootBoot.h"
#include "RAMBOOT_Consts.h"
#include "RAMBOOT_Types.h"
#include "LIBBSP_SPI.h"
#include "LIBBSP_FNOR.h"
#include "LIBUTI_SHA.h"
#include "LIBUTI_MEM.h"
#include "RAMBOOT_FailMode.h"
#include "RAMBOOT_JumpToAddress.h"
#include "RAMBOOT_RamBootEndMarker.h"

void RAMBOOT_CopyAndBootBoot( )
{
   TE_LIBBSP_FNOR_ErrorCode v_FNOR_ErrorCode;
   ts_LIBUTI_SHA_SHA256 v_BootSHA256;
   boolean_t v_SHA256NotEgual;
   uint32_t v_Addr;

   const ts_RAMBOOT_Data * const p_BootData = (ts_RAMBOOT_Data*)((&C_RAMBOOT_CODE_END_MARKER) + 1)[1];
   
   v_Addr = C_BOOT_START + p_BootData->size;
   v_Addr -= (v_Addr % sizeof(uint32_t));
   while (v_Addr < C_RAMBOOT_START)
   {
      *((uint32_t *)v_Addr) = v_Addr;
      v_Addr+=sizeof(uint32_t);
   }
   v_Addr = C_BOOT_DATA_START;
   while (v_Addr < C_BOOT_DATA_END)
   {
      *((uint32_t *)v_Addr) = v_Addr;
      v_Addr+=sizeof(uint32_t);
   }

   v_FNOR_ErrorCode = LIBBSP_FNOR_Open(E_LIBBSP_SPI_FLASH_PROGRAM);
   if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK)
   {
      RAMBOOT_FailMode();
      return;
   }

   v_FNOR_ErrorCode = LIBBSP_FNOR_FastRead(
      E_LIBBSP_SPI_FLASH_PROGRAM,
      C_BOOT_FLASHADDR,
      p_BootData->size,
      (uint8_t*)C_BOOT_START /* %RELAX<SYNCHRONe_C_Code_10.7> C_BOOT_START is an address */
   );
   if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK)
   {
      RAMBOOT_FailMode();
      return;
   }

   LIBBSP_FNOR_Close();

   LIBUTI_SHA_ComputeSHA256((uint8_t *) C_BOOT_START, p_BootData->size, &v_BootSHA256); /* %RELAX<SYNCHRONe_C_Code_10.7> C_BOOT_START is an address */

   v_SHA256NotEgual = LIBUTI_MEM_MemsNotEqual(  p_BootData->sha256.Data,
                                                v_BootSHA256.Data,
                                                (uint32_t)SHA256_BLOCK_SIZE);
   if(v_SHA256NotEgual == FALSE)
   {
      /* If the test is successful, jump to the BOOT soft */
      RAMBOOT_JumpToAddress( C_BOOT_START + C_BOOT_OFFSET );
   } else {
      RAMBOOT_FailMode();
   }
}