/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 *
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_private.h"

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */
#define OFFSET_DTL_LUP 0x2000

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */

void BOOT_PBIT_SW_SecondaryLoad(
   /*IN*/
   uint8_t *               PrimaryLoadName,
   uint32_t                PrimaryLoadNumberOfCompatibilityRules,
   TS_CompatibilityRule *  PrimaryLoadCompatibilityRules,
   TS_SecondaryLoadInfo *  LoadInfo,
   /*OUT*/
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   TS_LoadStatus *         LoadStatus
)
{
   uint32_t                   index;
   uint32_t                   index_bis;
   uint32_t                   LoadLUH_Length;
   uint32_t                   LoadSIF_HeaderLength;
   uint16_t                   CRC16_Buffer;
   uint16_t                   ExpectedCRC16;
   uint32_t                   NumberOfFiles;
   uint32_t                   NumberOfDataFiles;
   uint32_t                   NumberOfSupportFiles;
   TS_ARINC_665_FileInfo *    ARINC_665_DataFilesInfo;
   TS_ARINC_665_FileInfo *    ARINC_665_SupportFilesInfo;
   TS_FileInfo *              DataFilesInfo;
   TS_FileInfo *              SupportFilesInfo;
   te_CMN_FLAG_QUESTION       CMP_FileFound;
   TS_FileInfo *              CMP_FileInfo;
   te_CMN_FLAG_QUESTION       SUP_FileFound;
   TS_FileInfo *              SUP_FileInfo;
   te_CMN_FLAG_QUESTION       LUD_FileFound;
   TS_FileInfo *              LUD_FileInfo;
   te_CMN_FLAG_QUESTION       SIF_FileFound;
   TS_FileInfo *              SIF_FileInfo;
   te_CMN_FLAG_QUESTION       SKF_FileFound;
   TS_FileInfo *              SKF_FileInfo;
   te_CMN_FLAG_QUESTION       LoadLoadedByBoot;
   te_CMN_FLAG_QUESTION       LoadCheckedByBootInFlash;
   uint8_t                    DUMMY_AmendmentInfo[K_AMENDMENT_INFO_MAX_LENGTH];
   uint32_t                   DUMMY_Destination;
   uint32_t                   DUMMY_LoadType;
   te_CMN_FLAG_QUESTION       LaunchAddressFound;
   uint16_t                   PN_Length;
   uint8_t                    PN[K_PN_MAX_LENGTH];
   uint32_t                   DUMMY_PN_NumberOfTargetHW_IDs;
   TS_TargetHW_ID_WithLength  DUMMY_TargetHW_IDs_WithLengths[K_MAX_NUMBER_OF_TARGET_HW_IDS];
   uint32_t                   DUMMY_UDD_Offset;
   uint32_t                   DUMMY_CRC_16_Offset;
#ifdef A665_PART3
   uint32_t                   DUMMY_NumberOfTargetHW_ID_WithPositions;
   TS_TargetHW_ID_WithPositions DUMMY_TargetHW_ID_WithPositions[K_MAX_NUMBER_OF_TARGET_HW_IDS];
   uint16_t                   DUMMY_LoadDescription_Length;
   uint8_t                    DUMMY_LoadDescription[K_LOAD_TYPE_ID_MAX_LENGTH];
   uint16_t                   DUMMY_LoadTypeID;
   uint16_t                   DUMMY_LoadCheckValue_Length;
   uint8_t                    DUMMY_LoadCheckValue[K_LOAD_CHECK_VALUE_MAX_LENGTH];
   TE_ParseLUH_CheckValueType DUMMY_LoadCheckValue_Type;
#endif
   //ts_LIBUTI_SHA_SHA256    SHA256_Buffer;
   tu_LIBUTI_SIF_hash         Hash_Buffer;
   uint32_t                   SecondaryLoadNumberOfCompatibilityRules;
   TS_CompatibilityRule       SecondaryLoadCompatibilityRules[K_MAX_NUMBER_OF_COMPAT_RULES];
   uint8_t *                  DUMMY_LoadedSoftwareLaunchAddress;
   uint32_t                   NumberOfBufferSizedChunksInLUP;
   uint32_t                   SizeOfCurrentChunkOfLUP;
   uint32_t                   SizeOfLastChunkOfLUP;
   ts_LIBUTI_SHA_SHA256_ctx   SHA_256_ComputationContext;
   ts_LIBUTI_SHA_SHA512_ctx   SHA_512_ComputationContext;
   uint32_t                   AES_DecryptedSize;
   uint8_t                    LoadName[K_LOAD_NAME_MAX_LENGTH];
   TE_LIBUTI_SIF_check_algorithm SIF_hash_algo;

   *FlashReadFailed = e_CMN_FLAG_NO;

   BOOT_LIBMEM_SET(
      (uint8_t*)FilesInfoBuffer,
      0x00,
      (uint32_t)sizeof(FilesInfoBuffer) );

   for ( index = 0; index < K_MAX_NUMBER_OF_FILES;index++ )
   {
      FilesInfoBuffer[index].ARINC_665_FileInfo = &(ARINC_665_FilesInfoBuffer[index]);
   }

   /* LUH */
   LoadLUH_Length = *(uint32_t*)LoadInfo->FlashAddress;
   LoadLUH_Length = LoadLUH_Length * 2; /*16 bits words to 8 bits words*/

   if ( ( LoadLUH_Length < 6 ) || ( LoadLUH_Length > K_LUH_MAX_LENGTH ) )
   {
      LoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
      return;
   }
   LUH_Buffer = LoadInfo->FlashAddress;
   ExpectedCRC16 = *(uint16_t*)(((uint32_t)LUH_Buffer) + LoadLUH_Length - 6);

   /*Check LUH CRC16*/
   BOOT_LIBCHK_CRC16_COMPUTE( (uint16_t)0xFFFF, LUH_Buffer, LoadLUH_Length - 6, &CRC16_Buffer );
   if ( CRC16_Buffer != ExpectedCRC16 )
   {
      /*Corrupted LUH*/
      LoadStatus->Corrupted = e_CMN_FLAG_YES;
      return;
   }

   FilesInfoBuffer[0].Address = LUH_Buffer;
   FilesInfoBuffer[0].ARINC_665_FileInfo->Length = LoadLUH_Length - 4;

   LIBUTI_A665_ParseLUH
   (
   /*IN*/
      LUH_Buffer,
      LoadInfo->FlashAddress,
      (uint32_t)(K_MAX_NUMBER_OF_FILES - 1), /*LUH info takes one spot*/
      (uint32_t)K_MAX_NUMBER_OF_TARGET_HW_IDS,
#ifdef A665_PART3
      (uint32_t)K_MAX_NUMBER_OF_TARGET_HW_IDS,
#endif
   /*OUT*/
      &NumberOfFiles,
      &NumberOfDataFiles,
      &NumberOfSupportFiles,
#ifdef A665_PART3
      &DUMMY_NumberOfTargetHW_ID_WithPositions,
      DUMMY_TargetHW_ID_WithPositions,
      &DUMMY_LoadCheckValue_Length,
      &DUMMY_LoadCheckValue_Type,
      DUMMY_LoadCheckValue,
      &DUMMY_LoadDescription_Length,
      DUMMY_LoadDescription,
      &DUMMY_LoadTypeID,
#endif
      &(ARINC_665_FilesInfoBuffer[1]),
      &ARINC_665_DataFilesInfo,
      &ARINC_665_SupportFilesInfo,
      &(LoadStatus->CRC_32),
      &PN_Length,
      PN,
      &DUMMY_PN_NumberOfTargetHW_IDs,
      DUMMY_TargetHW_IDs_WithLengths,
      &DUMMY_UDD_Offset,
      &DUMMY_CRC_16_Offset,
      &(LoadStatus->OutOfOperationalCondition)
   );

   //Manage shift between LUH and LUP if any (cf shift introduced in DLD and in conf tool

//   for ( index = 0; index < NumberOfSupportFiles; index++ )
//   {
//      ARINC_665_SupportFilesInfo[index].Address = ARINC_665_SupportFilesInfo[index].Address - (*((uint32_t*)LoadInfo->FlashAddress)*2) + OFFSET_DTL_LUP;
//   }
//   for ( index = 0; index < NumberOfDataFiles; index++ )
//   {
//      ARINC_665_DataFilesInfo[index].Address= ARINC_665_DataFilesInfo[index].Address - (*((uint32_t*)LoadInfo->FlashAddress)*2) + OFFSET_DTL_LUP;
//   }

   if ( LoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      return;
   }

   LoadStatus->PartNumberSize = (uint8_t)PN_Length;
   BOOT_LIBMEM_CPY(
      LoadStatus->PartNumber,
      PN,
      K_LOAD_PN_LENGTH );

   DataFilesInfo = FilesInfoBuffer;
   SupportFilesInfo = FilesInfoBuffer;

   for ( index = 1; index < ( NumberOfFiles + 1 ); index++ )
   {
      if ( FilesInfoBuffer[index].ARINC_665_FileInfo == ARINC_665_DataFilesInfo )
      {
         DataFilesInfo = &(FilesInfoBuffer[index]);
         break;
      }
   }

   for ( index = 1; index < ( NumberOfFiles + 1 ); index++ )
   {
      if ( FilesInfoBuffer[index].ARINC_665_FileInfo == ARINC_665_SupportFilesInfo )
      {
         SupportFilesInfo = &(FilesInfoBuffer[index]);
         break;
      }
   }

   LIBUTI_CMN_IdentifySupportFiles(
      /*IN*/
      NumberOfSupportFiles,
      SupportFilesInfo,
      /*OUT*/
      &CMP_FileFound,
      &CMP_FileInfo,
      &SUP_FileFound,
      &SUP_FileInfo,
      &LUD_FileFound,
      &LUD_FileInfo,
      &SIF_FileFound,
      &SIF_FileInfo,
      &SKF_FileFound,
      &SKF_FileInfo,
      &(LoadStatus->OutOfOperationalCondition) );

   if ( ( CMP_FileFound == e_CMN_FLAG_NO ) || ( SUP_FileFound == e_CMN_FLAG_NO ) )
   {
      LoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
   }

   if ( LoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      return;
   }

   CMP_FileInfo->Address = NULL;
   SUP_FileInfo->Address = NULL;

   /* SIF */
   /* TODO PAULO : SIF address found in SIF_FileInfo is not the same as the real place where  it  has been downloaded */
   SIF_FileInfo->ARINC_665_FileInfo->Address = LoadInfo->SIF_HeaderENVM_Address;

   LoadSIF_HeaderLength = *(uint32_t*)LoadInfo->SIF_HeaderENVM_Address;

   if ( LoadSIF_HeaderLength > K_SIF_HEADER_MAX_LENGTH )
   {
      /*Out of operational condition SIF header*/
      LoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
      return;
   }

   SIF_HeaderBuffer = LoadInfo->SIF_HeaderENVM_Address;

   ExpectedCRC16 = *((uint16_t*)((uint32_t)SIF_HeaderBuffer + LoadSIF_HeaderLength));
   BOOT_LIBCHK_CRC16_COMPUTE( (uint16_t)0xFFFF, SIF_HeaderBuffer, LoadSIF_HeaderLength, &CRC16_Buffer );

   if ( CRC16_Buffer != ExpectedCRC16 )
   {
      /*Corrupted SIF header*/
      LoadStatus->Corrupted = e_CMN_FLAG_YES;
      return;
   }

   /*CMP */
   CMP_FileInfo->Address = CMP_FileInfo->ARINC_665_FileInfo->Address;

   /* CMP check-in algo */
   BOOT_PBIT_ComputeCRC32(
      /* InputOutput(s) parameter(s) */
      CMP_FileInfo,
      /* Output(s) parameter(s) */
      LoadStatus );

   if( LoadStatus->Corrupted == e_CMN_FLAG_YES )
   {
      /*Corrupted CMP*/
      return;
   }

   LIBUTI_CMN_ParseCMP(
      /*IN*/
      CMP_FileInfo->Address,
      (uint32_t) K_MAX_NUMBER_OF_COMPAT_RULES,
      /*OUT*/
      LoadName,
      &SecondaryLoadNumberOfCompatibilityRules,
      SecondaryLoadCompatibilityRules,
      &(LoadStatus->OutOfOperationalCondition) );

   if ( LoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      /*Out of operational condition CMP*/
      return;
   }

   /*SW compatibility check*/
   LIBUTI_CMN_TestCompatibilityBetweenLoads(
      /*IN*/
      LoadInfo->Name,
      SecondaryLoadNumberOfCompatibilityRules,
      SecondaryLoadCompatibilityRules,
      PrimaryLoadName,
      PrimaryLoadNumberOfCompatibilityRules,
      PrimaryLoadCompatibilityRules,
      /*OUT*/
      &(LoadStatus->Incompatible) );

   if ( LoadStatus->Incompatible == e_CMN_FLAG_YES )
   {
      /*Incompatible load*/
      return;
   }

   /* SUP */
   SUP_FileInfo->Address = SUP_FileInfo->ARINC_665_FileInfo->Address;

   /* SUP check-in algo */
   BOOT_PBIT_ComputeCRC32(
      /* InputOutput(s) parameter(s) */
      SUP_FileInfo,
      /* Output(s) parameter(s) */
      LoadStatus );

   if ( LoadStatus->Corrupted == e_CMN_FLAG_YES )
   {
      /*Corrupted SUP*/
      return;
   }

   LIBUTI_CMN_ParseSUP(
      /*IN*/
      SUP_FileInfo->Address,
      NumberOfDataFiles,
      /*INOUT*/
      DataFilesInfo,
      /*OUT*/
      &LaunchAddressFound,
      &DUMMY_LoadedSoftwareLaunchAddress,
      &LoadLoadedByBoot,
      &LoadCheckedByBootInFlash,
      DUMMY_AmendmentInfo,
      &DUMMY_Destination,
      &DUMMY_LoadType,
      &(LoadStatus->OutOfOperationalCondition) );

   if ( LaunchAddressFound == e_CMN_FLAG_YES )
   {
      LoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
   }

   if ( LoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES)
   {
      /*Out of operational condition SUP*/
      return;
   }

   if ( LoadLoadedByBoot == e_CMN_FLAG_YES )
   {
      /*LUPs are copied to at the RAM destination address*/
      for( index = 0;index < NumberOfDataFiles; index++ )
      {
         /* LUP */
         /* TODO PAULO : DataFilesInfo[index].Address has the correct address of the LUP, then use it */
         /* TODO PAULO : LIBUTI_A665_ParseLUH does not update DataFilesInfo[index].ARINC_665_FileInfo->Address */
         /*  since the SUP file is parsed after the LUH file */
         DataFilesInfo[index].ARINC_665_FileInfo->Address = DataFilesInfo[index].Address;

         /* LUP check-in algo */
         BOOT_PBIT_ComputeCRC32(
            /* InputOutput(s) parameter(s) */
            &DataFilesInfo[index],
            /* Output(s) parameter(s) */
            LoadStatus );

         if ( LoadStatus->Corrupted == e_CMN_FLAG_YES )
         {
            /*Corrupted LUP*/
            return;
         }

         if ( DataFilesInfo[index].Encrypted == e_CMN_FLAG_YES )
         {
            AES_KeyBuffer = (uint8_t*)( K_MRAM_AESKEY_ZONE_OFFSET + ((uint32_t)LoadInfo->SIF_HeaderENVM_Address >> 2) );

            for ( index_bis = 0; index_bis < (E_LIBUTI_AES_KEY_SIZE_256/8); index_bis++ )
            {
               AES_KeyBuffer[index_bis] ^= AES_MaskBuffer[index_bis];
            }
            LoadStatus->Corrupted = LIBUTI_AES_decrypt_in_place(
                                       DataFilesInfo[index].Address,
                                       (uint32_t)DataFilesInfo[index].ARINC_665_FileInfo->Length,
                                       AES_KeyBuffer,
                                       E_LIBUTI_AES_KEY_SIZE_256,
                                       &AES_DecryptedSize );

            if ( LoadStatus->Corrupted == e_CMN_FLAG_YES )
            {
               /*Corrupted LUP*/
               return;
            }

            BOOT_LIBCHK_CRC16_COMPUTE( (uint16_t)0xFFFF, DataFilesInfo[index].Address, AES_DecryptedSize, &CRC16_Buffer );
            if ( CRC16_Buffer != DataFilesInfo[index].ExpectedCRC16 )
            {
               /*Corrupted LUP*/
               LoadStatus->Corrupted = e_CMN_FLAG_YES;
               return;
            }
         }
      }
   }

   if ( LUD_FileFound == e_CMN_FLAG_YES )
   {
      LoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
   }
}
