#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_RMM.h"
#include "LIBBSP_RMM.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_Header_RMM(
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
   TE_LIBBSP_I2C_Code v_RMM_ErrorCode;

   v_RMM_ErrorCode = LIBBSP_RMM_Open();
   if(v_RMM_ErrorCode != E_LIBBSP_I2C_OK){*p_FlashReadFailed = TRUE;return;}
   LIBBSP_RMM_Read(
      p_SIFAddress & 0x7FFFFFFFul,
      p_BootData->size,
      p_SIF_HeaderBuffer,
      &v_RMM_ErrorCode
   );
   (void) LIBBSP_RMM_Close();
   if (v_RMM_ErrorCode != E_LIBBSP_I2C_OK){*p_FlashReadFailed = TRUE;}
}
