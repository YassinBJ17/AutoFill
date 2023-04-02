#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_RMM.h"
#include "LIBBSP_RMM.h"

uint32_t BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_RMM(
/*IN*/
   const uint32_t p_SIFAddress,
/*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   ts_BOOT_Data* p_BootData,
   boolean_t* p_FlashReadFailed,
   TE_ParseLUH_CheckValueType* p_LoadStatus
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_I2C_Code v_RMM_ErrorCode;

   v_RMM_ErrorCode = LIBBSP_RMM_Open();
   if (v_RMM_ErrorCode != E_LIBBSP_I2C_OK)
   {
      if (v_RMM_ErrorCode == E_LIBBSP_I2C_NO_ACK)
      {
         p_LoadStatus->OutOfOperationalCondition = TRUE;
      }
      else
      {
         *p_FlashReadFailed = TRUE;
      }
      return;
   }

   LIBBSP_RMM_Read(
      C_BOOT_RMM_ADDR_SHA_START + (((((p_SIFAddress & 0x7FFFFFFFul) - C_BOOT_RMM_ADDR_SIF_START) & 0x1000ul) / 0x1000ul) * 0x200ul),
      sizeof(ts_BOOT_Data),
      (uint8_t*)p_BootData, /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> convertion needed to use variable memory area as buffer */
      &v_RMM_ErrorCode
   );
   (void) LIBBSP_RMM_Close();
   if (v_RMM_ErrorCode != E_LIBBSP_I2C_OK){*p_FlashReadFailed = TRUE;}
}
