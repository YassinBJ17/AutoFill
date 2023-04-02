#include "BOOT_CLSW_GetFilesSHA256_FromSIF_Header.h"
#include "LIBUTI_SIF.h"

void BOOT_CLSW_GetFilesSHA256_FromSIF_Header
(
/*IN*/
   const uint8_t* const p_SIF_HeaderAddress,
   const uint32_t p_NumberOfFiles,
   const boolean_t p_SIF_FileFound,
   const TS_FileInfo* const p_SIF_FileInfo,
/*INOUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   TS_FileInfo p_FilesInfo[C_BOOT_MAX_NUMBER_OF_FILES],
/*OUT*/
   boolean_t* p_OutOfOperationalConditionSIF
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   uint32_t v_index;
   TE_LIBUTI_SIF_status v_LIBUTI_SIF_GetHashReturnCode;
   boolean_t v_AllFilesSHA256_Found;

   v_AllFilesSHA256_Found = TRUE;
   for(v_index=0ul;v_index<p_NumberOfFiles;v_index++)
   {
      if((p_SIF_FileFound == FALSE) || ((&p_FilesInfo[v_index]) != p_SIF_FileInfo))
      {
         v_LIBUTI_SIF_GetHashReturnCode = LIBUTI_SIF_get_SHA2_256(
            p_SIF_HeaderAddress,
            p_FilesInfo[v_index].ARINC_665_FileInfo->Name,
            (uint32_t)p_FilesInfo[v_index].ARINC_665_FileInfo->NameLength,
            &p_FilesInfo[v_index].ExpectedSHA256
         );
         if(v_LIBUTI_SIF_GetHashReturnCode != E_LIBUTI_SIF_SUCCESS)
         {
            v_AllFilesSHA256_Found = FALSE;
         }
      }
   }
   *p_OutOfOperationalConditionSIF = !v_AllFilesSHA256_Found;
}