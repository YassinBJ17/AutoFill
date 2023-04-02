#include "BOOT_CLSW_LoadSW_Load_LoadAndTestLUH.h"
#include "BOOT_CLSW_Buffers.h"
#include "BOOT_CLSW_LoadSW_Load_LoadAndTest.h"
#include "LIBBSP_FNOR.h"
#include "LIBBSP_RMM.h"
#include "LIBUTI_CRC.h"

void BOOT_CLSW_LoadSW_Load_LoadAndTestLUH(
   /*IN*/
   const TS_FileInfo* const p_FileInfo,
   /*OUT*/
/* {{RELAX<SYNCHRONe_C_Code_8.18> Those parameters are outputs */
   HW_WordBitField* p_NumberOfFiles,
   uint32_t* p_NumberOfDataFiles,
   uint32_t* p_NumberOfSupportFiles,
   TS_ARINC_665_FileInfo** p_ARINC_665_DataFilesInfo,
   TS_ARINC_665_FileInfo** p_ARINC_665_SupportFilesInfo,
   boolean_t* p_FlashReadFailed,
   ts_LoadStatus* p_LoadStatus
/* }} RELAX<SYNCHRONe_C_Code_8.18> */
)
{
   TE_LIBBSP_FNOR_ErrorCode v_FNOR_ErrorCode;
   TE_LIBBSP_I2C_Code v_RMM_ErrorCode;
   TE_ParseLUH_ReturnCode v_LUH_ParseStatus;
   uint16_t v_CRC16_Buffer;
   uint32_t v_CRC16_Offset;

   uint32_t v_DUMMY_PN_NumberOfTargetHW_IDs;
   TS_TargetHW_ID_WithLength v_DUMMY_TargetHW_IDs_WithLengths[C_BOOT_MAX_NUMBER_OF_TARGET_HW_IDS];
   uint32_t v_DUMMY_UDD_Offset;
#ifdef A665_PART3
   uint32_t v_DUMMY_NumberOfTargetHW_ID_WithPositions;
   TS_TargetHW_ID_WithPositions v_DUMMY_TargetHW_ID_WithPositions[C_BOOT_MAX_NUMBER_OF_TARGET_HW_IDS];
   uint16_t v_DUMMY_LoadDescription_Length;
   uint8_t v_DUMMY_LoadDescription[C_LOAD_TYPE_ID_MAX_LENGTH];
   uint16_t v_DUMMY_LoadTypeID;
   uint16_t v_DUMMY_LoadCheckValue_Length;
   uint8_t DUMMY_LoadCheckValue[C_LOAD_CHECK_VALUE_MAX_LENGTH];
   TE_ParseLUH_CheckValueType v_DUMMY_LoadCheckValue_Type;
#endif

   if (((uint32_t)(p_FileInfo->ARINC_665_FileInfo->Address) & 0x80000000ul) == 0ul) /* %RELAX<SYNCHRONe_C_Code_11.1> convertion needed to use check location of memory */
   {
      v_FNOR_ErrorCode = LIBBSP_FNOR_Open(E_LIBBSP_SPI_FLASH_PROGRAM);
      if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK) {*p_FlashReadFailed = TRUE;return;}
      v_FNOR_ErrorCode = LIBBSP_FNOR_FastRead(
         E_LIBBSP_SPI_FLASH_PROGRAM,
         (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Address), /* %RELAX<SYNCHRONe_C_Code_11.1> convertion needed to use as uint32_t */
         sizeof(uint32_t),
         (uint8_t*)(&p_FileInfo->ARINC_665_FileInfo->LengthInWords) /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> convertion needed to use variable memory area as buffer */
      );
      LIBBSP_FNOR_Close();
      if(v_FNOR_ErrorCode != E_LIBBSP_FNOR_OK) {*p_FlashReadFailed = TRUE;return;}
   }
   else
   {
      v_RMM_ErrorCode = LIBBSP_RMM_Open();
      if(v_RMM_ErrorCode != E_LIBBSP_I2C_OK) {*p_FlashReadFailed = TRUE;return;}
      LIBBSP_RMM_Read(
         (uint32_t)(p_FileInfo->ARINC_665_FileInfo->Address) & 0x7FFFFFFFul, /* %RELAX<SYNCHRONe_C_Code_11.1> convertion needed to use as uint32_t */
         sizeof(uint32_t),
         (uint8_t*)(&p_FileInfo->ARINC_665_FileInfo->LengthInWords), /* %RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1> convertion needed to use variable memory area as buffer */
         &v_RMM_ErrorCode
      );
      (void) LIBBSP_RMM_Close();
      if(v_RMM_ErrorCode != E_LIBBSP_I2C_OK) {*p_FlashReadFailed = TRUE;return;}
   }
   p_FileInfo->ARINC_665_FileInfo->Length = (uint64_t)(p_FileInfo->ARINC_665_FileInfo->LengthInWords) * (uint64_t)(sizeof(uint16_t)); /*16 bits words to 8 bits words*/
   if((p_FileInfo->ARINC_665_FileInfo->Length < C_BOOT_LUH_MIN_LENGTH) || (p_FileInfo->ARINC_665_FileInfo->Length > C_BOOT_LUH_MAX_LENGTH))
   {
      p_LoadStatus->OutOfOperationalCondition = TRUE;
      return;
   }

   BOOT_CLSW_LoadSW_Load_LoadAndTest(p_FileInfo, p_FlashReadFailed, p_LoadStatus);
   if(*p_FlashReadFailed || p_LoadStatus->Corrupted)
   {
      return;
   }
      
   v_LUH_ParseStatus = LIBUTI_A665_ParseLUH
   (
   /*IN*/
      p_FileInfo->Address,
      p_FileInfo->ARINC_665_FileInfo->Address,
      C_BOOT_MAX_NUMBER_OF_FILES - 1ul, /*LUH info takes one spot*/
      C_BOOT_MAX_NUMBER_OF_TARGET_HW_IDS,
#ifdef A665_PART3
      C_BOOT_MAX_NUMBER_OF_TARGET_HW_IDS,
#endif
   /*OUT*/
      p_NumberOfFiles,
      p_NumberOfDataFiles,
      p_NumberOfSupportFiles,
#ifdef A665_PART3
      &v_DUMMY_NumberOfTargetHW_ID_WithPositions,
      v_DUMMY_TargetHW_ID_WithPositions,
      &v_DUMMY_LoadCheckValue_Length,
      &v_DUMMY_LoadCheckValue_Type,
      DUMMY_LoadCheckValue,
      &v_DUMMY_LoadDescription_Length,
      v_DUMMY_LoadDescription,
      &v_DUMMY_LoadTypeID,
#endif
      &(ARINC_665_FilesInfoBuffer[1]),
      p_ARINC_665_DataFilesInfo,
      p_ARINC_665_SupportFilesInfo,
      &(p_LoadStatus->CRC_32),
      &(p_FileInfo->ARINC_665_FileInfo->PN_Length),
      p_FileInfo->ARINC_665_FileInfo->PN,
      &v_DUMMY_PN_NumberOfTargetHW_IDs,
      v_DUMMY_TargetHW_IDs_WithLengths,
      &v_DUMMY_UDD_Offset,
      &v_CRC16_Offset,
      &(p_LoadStatus->OutOfOperationalCondition)
   );
   if(v_LUH_ParseStatus == E_LIBUTI_PARSE_LUH_OK)
   {
      /* >RELAX<SYNCHRONe_C_Code_11.1> convertion needed to retrieve CRC16 */
      /* >RELAX<SYNCHRONe_C_Code_17.4> can not use an array here since the size and location of area depend on file and is only known at runtime */
      p_FileInfo->ARINC_665_FileInfo->ExpectedCRC16 = *(uint16_t*)(&p_FileInfo->Address[v_CRC16_Offset]);
      /* >RELAX<SYNCHRONe_C_Code_10.7> A665 v3 stores length on 64bits but we do not use files bigger than 4GB */
      v_CRC16_Buffer = LIBUTI_CRC_ComputeCRC16(p_FileInfo->Address, (uint32_t)p_FileInfo->ARINC_665_FileInfo->Length - (sizeof(uint16_t) + sizeof(uint32_t)));
      if(v_CRC16_Buffer != p_FileInfo->ARINC_665_FileInfo->ExpectedCRC16)
      {
         p_LoadStatus->Corrupted = TRUE;
      }
   }
   else
   {
      p_LoadStatus->OutOfOperationalCondition = TRUE;
   }
}
