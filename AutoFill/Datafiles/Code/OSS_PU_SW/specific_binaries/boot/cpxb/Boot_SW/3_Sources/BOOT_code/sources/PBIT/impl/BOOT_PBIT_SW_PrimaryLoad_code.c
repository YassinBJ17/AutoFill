/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Check the Primary Load
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

void BOOT_PBIT_SW_PrimaryLoad(
   /*IN*/
   uint8_t *               BOOT_Name,
   uint32_t                BOOT_NumberOfCompatibilityRules,
   TS_CompatibilityRule *  BOOT_CompatibilityRules,
   uint8_t *               PrimaryLoadLUH_FlashAddress,
   uint8_t *               PrimaryLoadSIF_HeaderENVM_Address,
   /*OUT*/
   uint8_t *               PrimaryLoadName,
   uint32_t *              PrimaryLoadNumberOfCompatibilityRules,
   TS_CompatibilityRule *  PrimaryLoadCompatibilityRules,
   uint32_t *              NumberOfSecondaryLoads,
   TS_SecondaryLoadInfo *  SecondaryLoadsInfo,
   te_CMN_FLAG_QUESTION *  LoadFailed,
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   uint8_t **              LoadedSoftwareLaunchAddress,
   TS_LoadStatus *         PrimaryLoadStatus
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
   te_CMN_FLAG_QUESTION       DUMMY_LoadLoadedByBoot;
   te_CMN_FLAG_QUESTION       DUMMY_LoadCheckedByBootInFlash;
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
   uint32_t                   AES_DecryptedSize;
   TE_LIBUTI_SIF_check_algorithm SIF_hash_algo;

   *FlashReadFailed = e_CMN_FLAG_NO;

   /*********************************************************************************/
   /*                     FileinfoBuffer Initialization                             */
   /*********************************************************************************/
   BOOT_LIBMEM_SET(
      (uint8_t*)FilesInfoBuffer,
      0x00,
      (uint32_t)sizeof(FilesInfoBuffer) );

   for ( index = 0 ; index < K_MAX_NUMBER_OF_FILES ; index++ )
   {
      FilesInfoBuffer[index].ARINC_665_FileInfo = &(ARINC_665_FilesInfoBuffer[index]);
   }

   /*********************************************************************************/
   /*                       Check the Load LUH Length                               */
   /*********************************************************************************/

   LoadLUH_Length = *(uint32_t *)PrimaryLoadLUH_FlashAddress;
   LoadLUH_Length = LoadLUH_Length * 2; /*16 bits words to 8 bits words*/

   if ( ( LoadLUH_Length < 6 ) || ( LoadLUH_Length > K_LUH_MAX_LENGTH ) )
   {
      *LoadFailed = e_CMN_FLAG_YES;
      PrimaryLoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
      return;
   }

   /*********************************************************************************/
   /*                 Check the Integrity of the Load LUH                           */
   /*********************************************************************************/
   LUH_Buffer = PrimaryLoadLUH_FlashAddress;

   ExpectedCRC16 = *(uint16_t*)(((uint32_t)LUH_Buffer) + LoadLUH_Length - 6);

   /*Check LUH CRC16*/
   BOOT_LIBCHK_CRC16_COMPUTE( (uint16_t)0xFFFF, LUH_Buffer, LoadLUH_Length - 6, &CRC16_Buffer );

   if ( CRC16_Buffer != ExpectedCRC16 )
   {
      /*Corrupted LUH*/
      *LoadFailed = e_CMN_FLAG_YES;
      PrimaryLoadStatus->Corrupted = e_CMN_FLAG_YES;
      return;
   }

   /*********************************************************************************/
   /*          Check each field of the LUH and get needed information               */
   /*********************************************************************************/
   FilesInfoBuffer[0].Address = (uint8_t*)LUH_Buffer;
   FilesInfoBuffer[0].ARINC_665_FileInfo->Length = LoadLUH_Length - 4;

   LIBUTI_A665_ParseLUH
   (
   /*IN*/
      LUH_Buffer,
      PrimaryLoadLUH_FlashAddress,
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
      &(PrimaryLoadStatus->CRC_32),
      &PN_Length,
      PN,
      &DUMMY_PN_NumberOfTargetHW_IDs,
      DUMMY_TargetHW_IDs_WithLengths,
      &DUMMY_UDD_Offset,
      &DUMMY_CRC_16_Offset,
      &(PrimaryLoadStatus->OutOfOperationalCondition)
   );

//   for ( index = 0; index < NumberOfSupportFiles; index++ )
//   {
//      ARINC_665_SupportFilesInfo[index].Address = ARINC_665_SupportFilesInfo[index].Address - (*((uint32_t*)PrimaryLoadLUH_FlashAddress)*2) + OFFSET_DTL_LUP;
//   }
//
//   for ( index = 0; index < NumberOfDataFiles; index++ )
//   {
//      ARINC_665_DataFilesInfo[index].Address= ARINC_665_DataFilesInfo[index].Address - (*((uint32_t*)PrimaryLoadLUH_FlashAddress)*2) + OFFSET_DTL_LUP;
//   }

   if ( PrimaryLoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      *LoadFailed = e_CMN_FLAG_YES;
      return;
   }

   PrimaryLoadStatus->PartNumberSize = (uint8_t)PN_Length;
   BOOT_LIBMEM_CPY(
      PrimaryLoadStatus->PartNumber,
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
      &(PrimaryLoadStatus->OutOfOperationalCondition) );

   if ( ( CMP_FileFound == e_CMN_FLAG_NO ) || ( SUP_FileFound == e_CMN_FLAG_NO ) )
   {
      PrimaryLoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
   }

   if ( PrimaryLoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      *LoadFailed = e_CMN_FLAG_YES;
      return;
   }

   CMP_FileInfo->Address = NULL;
   SUP_FileInfo->Address = NULL;
   LUD_FileInfo->Address = NULL;

   /*SIF */
   LoadSIF_HeaderLength = *(uint32_t*)PrimaryLoadSIF_HeaderENVM_Address;

   if ( LoadSIF_HeaderLength > K_SIF_HEADER_MAX_LENGTH )
   {
      /*Out of operational condition SIF header*/
      *LoadFailed = e_CMN_FLAG_YES;
      PrimaryLoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
      return;
   }

   SIF_HeaderBuffer = PrimaryLoadSIF_HeaderENVM_Address;

   ExpectedCRC16 = *((uint16_t*)((uint32_t)SIF_HeaderBuffer + LoadSIF_HeaderLength));
   BOOT_LIBCHK_CRC16_COMPUTE( (uint16_t)0xFFFF, SIF_HeaderBuffer, LoadSIF_HeaderLength, &CRC16_Buffer );
   if ( CRC16_Buffer != ExpectedCRC16 )
   {
      /*Corrupted SIF header*/
      *LoadFailed = e_CMN_FLAG_YES;
      PrimaryLoadStatus->Corrupted = e_CMN_FLAG_YES;
      return;
   }

   /* CMP */
   CMP_FileInfo->Address = CMP_FileInfo->ARINC_665_FileInfo->Address;

   /* CMP check-in algo */
   BOOT_PBIT_ComputeCRC32(
      /* InputOutput(s) parameter(s) */
      CMP_FileInfo,
      /* Output(s) parameter(s) */
      PrimaryLoadStatus );

   if ( PrimaryLoadStatus->Corrupted == e_CMN_FLAG_YES )
   {
      /*Corrupted CMP*/
      *LoadFailed = e_CMN_FLAG_YES;
      return;
   }

   LIBUTI_CMN_ParseCMP(
      /*IN*/
      CMP_FileInfo->Address,
      (uint32_t) K_MAX_NUMBER_OF_COMPAT_RULES,
      /*OUT*/
      PrimaryLoadName,
      PrimaryLoadNumberOfCompatibilityRules,
      PrimaryLoadCompatibilityRules,
      &(PrimaryLoadStatus->OutOfOperationalCondition) );

   BOOT_LIBMEM_CPY(
      PrimaryLoadStatus->Name,
      PrimaryLoadName,
      K_LOAD_NAME_MAX_LENGTH );

   if ( PrimaryLoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      /*Out of operational condition CMP*/
      *LoadFailed = e_CMN_FLAG_YES;
      return;
   }

   /*HW compatibility check*/
   LIBUTI_CMN_TestCompatibilityBetweenLoads(
      /*IN*/
      BOOT_Name,
      BOOT_NumberOfCompatibilityRules,
      BOOT_CompatibilityRules,
      PrimaryLoadName,
      *PrimaryLoadNumberOfCompatibilityRules,
      PrimaryLoadCompatibilityRules,
      /*OUT*/
      &(PrimaryLoadStatus->Incompatible) );

   if ( PrimaryLoadStatus->Incompatible == e_CMN_FLAG_YES )
   {
      /*Incompatible load*/
      *LoadFailed = e_CMN_FLAG_YES;
      return;
   }

   /* SUP */
   SUP_FileInfo->Address = SUP_FileInfo->ARINC_665_FileInfo->Address;

   /* SUP check-in algo */
   BOOT_PBIT_ComputeCRC32(
      /* InputOutput(s) parameter(s) */
      SUP_FileInfo,
      /* Output(s) parameter(s) */
      PrimaryLoadStatus );

   if ( PrimaryLoadStatus->Corrupted == e_CMN_FLAG_YES )
   {
      /*Corrupted SUP*/
      *LoadFailed = e_CMN_FLAG_YES;
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
      LoadedSoftwareLaunchAddress,
      &DUMMY_LoadLoadedByBoot,
      &DUMMY_LoadCheckedByBootInFlash,
      DUMMY_AmendmentInfo,
      &DUMMY_Destination,
      &DUMMY_LoadType,
      &(PrimaryLoadStatus->OutOfOperationalCondition) );

   if ( LaunchAddressFound == e_CMN_FLAG_NO )
   {
      PrimaryLoadStatus->OutOfOperationalCondition = e_CMN_FLAG_YES;
   }

   if ( PrimaryLoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
   {
      /*Out of operational condition SUP*/
      *LoadFailed = e_CMN_FLAG_YES;
      return;
   }

   if ( LUD_FileFound == e_CMN_FLAG_YES )
   {
      /* LUD */
      LUD_FileInfo->Address = LUD_FileInfo->ARINC_665_FileInfo->Address;

      /* LUD check-in algo */
      BOOT_PBIT_ComputeCRC32(
         /* InputOutput(s) parameter(s) */
         LUD_FileInfo,
         /* Output(s) parameter(s) */
         PrimaryLoadStatus );

      if ( PrimaryLoadStatus->Corrupted == e_CMN_FLAG_YES )
      {
         /*Corrupted LUD*/
         *LoadFailed = e_CMN_FLAG_YES;
         return;
      }

      LIBUTI_CMN_ParseLUD(
         /*IN*/
         LUD_FileInfo->Address,
         (uint32_t)K_MAX_NUMBER_OF_SECONDARY_LOAD,
         /*OUT*/
         NumberOfSecondaryLoads,
         SecondaryLoadsInfo,
         &(PrimaryLoadStatus->OutOfOperationalCondition) );

      if ( PrimaryLoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES )
      {
         /*Out of operational condition LUD*/
         *LoadFailed = e_CMN_FLAG_YES;
         return;
      }
   }

   for ( index = 0; index < NumberOfDataFiles; index++ )
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
         PrimaryLoadStatus );

      if ( PrimaryLoadStatus->Corrupted == e_CMN_FLAG_YES )
      {
         /*Corrupted LUP*/
         *LoadFailed = e_CMN_FLAG_YES;
         return;
      }

      if ( DataFilesInfo[index].Encrypted == e_CMN_FLAG_YES )
      {
         AES_KeyBuffer = (uint8_t*)( K_MRAM_AESKEY_ZONE_OFFSET + ((uint32_t)PrimaryLoadSIF_HeaderENVM_Address >> 2) );
         for ( index_bis = 0; index_bis < (E_LIBUTI_AES_KEY_SIZE_256/8); index_bis++ )
         {
            AES_KeyBuffer[index_bis] ^= AES_MaskBuffer[index_bis];
         }
         PrimaryLoadStatus->Corrupted = LIBUTI_AES_decrypt_in_place(
                                           DataFilesInfo[index].Address,
                                           (uint32_t)DataFilesInfo[index].ARINC_665_FileInfo->Length,
                                           AES_KeyBuffer,
                                           E_LIBUTI_AES_KEY_SIZE_256,
                                           &AES_DecryptedSize );

         if ( PrimaryLoadStatus->Corrupted == e_CMN_FLAG_YES )
         {
            /*Corrupted LUP*/
            return;
         }

         BOOT_LIBCHK_CRC16_COMPUTE( (uint16_t)0xFFFF, DataFilesInfo[index].Address, AES_DecryptedSize, &CRC16_Buffer );

         if ( CRC16_Buffer != DataFilesInfo[index].ExpectedCRC16 )
         {
            /*Corrupted LUP*/
            *LoadFailed = e_CMN_FLAG_YES;
            PrimaryLoadStatus->Corrupted = e_CMN_FLAG_YES;
            return;
         }
      }
   }
}
