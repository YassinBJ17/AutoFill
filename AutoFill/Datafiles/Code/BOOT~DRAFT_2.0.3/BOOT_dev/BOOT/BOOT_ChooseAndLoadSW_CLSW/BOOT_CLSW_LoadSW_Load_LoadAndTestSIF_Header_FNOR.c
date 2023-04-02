#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_FNOR.h"
#include "LIBBSP_FNOR.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_FNOR(
/*IN*/
   const uint32_t p_SIFAddress,
   const ts_BOOT_Data* const p_BootData,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   uint8_t* p_SIF_HeaderBuffer,
   boolean_t* p_FlashReadFailed
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_FNOR_ErrorCode v_FNOR_ErrorCode;

   v_FNOR_ErrorCode = LIBBSP_FNOR_Open(E_LIBBSP_SPI_FLASH_PROGRAM);
   if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK){*p_FlashReadFailed = TRUE;return;}

   v_FNOR_ErrorCode = LIBBSP_FNOR_FastRead(
      E_LIBBSP_SPI_FLASH_PROGRAM,
      p_SIFAddress,
      p_BootData->size,
      p_SIF_HeaderBuffer
   );
   LIBBSP_FNOR_Close();
   if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK){*p_FlashReadFailed = TRUE;}
}
