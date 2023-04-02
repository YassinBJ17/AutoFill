#include "BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_ENVM.h"
#include "LIBBSP_ENVM.h"
boolean_t BOOT_CLSW_LoadSW_Load_LoadAndTestSIF_SHA_ENVM(
   const uint32_t p_ENVMAddress,
   ts_BOOT_Data* p_BootData,
   boolean_t* p_FlashReadFailed
)
{
   TE_LIBBSP_ENVM_ErrorCode v_ENVM_ErrorCode;

   v_ENVM_ErrorCode = LIBBSP_ENVM_Open(E_LIBBSP_ENVM_COMPAGNON);
   if(v_ENVM_ErrorCode != E_LIBBSP_ENVM_OK){*p_FlashReadFailed = TRUE;return;}

   LIBBSP_ENVM_Read(
      E_LIBBSP_ENVM_COMPAGNON,
      p_ENVMAddress,
      sizeof(ts_BOOT_Data),
      (uint8_t*)p_BootData, /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> convertion needed to use variable memory area as buffer */
      &v_ENVM_ErrorCode
   );
   (void) LIBBSP_ENVM_Close(E_LIBBSP_ENVM_COMPAGNON);
   if(v_ENVM_ErrorCode != E_LIBBSP_ENVM_OK){*p_FlashReadFailed = TRUE;}
}
