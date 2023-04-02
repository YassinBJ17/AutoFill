/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_MatchingFiles.h"

typedef struct
{
   uint16_t SUP_Size;
   uint16_t SUP_Version;
   uint8_t  AmendmentInformation[K_AMENDMENT_INFO_MAX_LENGTH];
   uint32_t Destination;
   uint32_t LoadType;
   uint32_t OnBoardRunningLoad;
   uint16_t NumberOfLUP_Files;
}__attribute__((packed)) TS_SUP_FileConstantSizeFirstFields;

typedef struct
{
   uint8_t   LUP_Name[K_FILE_NAME_MAX_LENGTH];
   uint16_t  LUP_Type;
   uint16_t  LUP_EncryptionStatus;
   uint8_t * LUP_DestinationAddress;
   uint32_t  LUP_EntryPointDelta;
   uint16_t  LUP_EncryptedCRC16;
}__attribute__((packed)) TS_SUP_LUP_Infos;

#define K_MAIN_APPLICATION_FILE (uint16_t)0x0000

#define K_NOT_ENCRYPTED (uint16_t)0x0000
#define K_ENCRYPTED     (uint16_t)0x0001

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on SupportFilesInfo. Poiter used as buffer with sup file infos in it.*/
/*Can't use anrray because size depend on number infos in it.*/
/*Overflow avoid by check index_bis<NumberOfDataFiles in the for instruction*/

void LIBUTI_CMN_ParseSUP
(
   /*IN*/
   const uint8_t * const         SUP_Address,
   const uint32_t                NumberOfDataFiles,
   /*INOUT*/
   TS_FileInfo * const           DataFilesInfo,
   /*OUT*/
   te_CMN_FLAG_QUESTION * const  LaunchAddressFound,
   uint8_t ** const              LaunchAddress,
   te_CMN_FLAG_QUESTION * const  LoadLoadedByBoot,
   te_CMN_FLAG_QUESTION * const  LoadCheckedByBootInFlash,
   uint8_t * const               AmendmentInfo,
   uint32_t * const              Destination,
   uint32_t * const              LoadType,
   te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionSUP
)
{

   uint32_t index;
   uint32_t index_bis;
   te_CMN_FLAG_QUESTION DataFileFound;
   te_CMN_FLAG_QUESTION MatchingFileName;
   TS_SUP_LUP_Infos * SUP_LUP_InfoIterator;

   *OutOfOperationalConditionSUP = e_CMN_FLAG_NO;
   *LoadLoadedByBoot = e_CMN_FLAG_NO;
   *LoadCheckedByBootInFlash = e_CMN_FLAG_NO;
   *LaunchAddressFound = e_CMN_FLAG_NO;

   if ( (uint32_t)(((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->NumberOfLUP_Files) /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion from generic ptr to ptr to specific structure */
         != NumberOfDataFiles )
   {
      *OutOfOperationalConditionSUP = e_CMN_FLAG_YES;
      return;
   }

   if ( (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->OnBoardRunningLoad) == 0xFFFFFFFF )
   {
      *LoadLoadedByBoot = e_CMN_FLAG_YES;
   }
   else if ( (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->OnBoardRunningLoad) == 0x00000000 )
   {
      *LoadCheckedByBootInFlash = e_CMN_FLAG_YES;
   }
   else if ( (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->OnBoardRunningLoad) != 0x55555555 )
   {
      *OutOfOperationalConditionSUP = e_CMN_FLAG_YES;
      return;
   }

   for ( index = (uint32_t)0; index < K_AMENDMENT_INFO_MAX_LENGTH; index++ )
   {
      AmendmentInfo[index] = (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->AmendmentInformation)[index];
   }
   
   *LoadType = (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->LoadType);
   *Destination = (((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->Destination);

   SUP_LUP_InfoIterator = (TS_SUP_LUP_Infos*)( (uint32_t)SUP_Address /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
   + sizeof(TS_SUP_FileConstantSizeFirstFields) );

   for ( index = (uint32_t)0; index < NumberOfDataFiles; index++ )
   {
      DataFileFound = e_CMN_FLAG_NO;
      for ( index_bis = (uint32_t)0; index_bis < NumberOfDataFiles; index_bis++ )
      {
         LIBUTI_CMN_MatchingFiles(DataFilesInfo[index].ARINC_665_FileInfo->Name, DataFilesInfo[index].ARINC_665_FileInfo->NameLength, SUP_LUP_InfoIterator[index_bis].LUP_Name, &MatchingFileName);

         if ( MatchingFileName == e_CMN_FLAG_YES )
         {
            DataFileFound = e_CMN_FLAG_YES;
            DataFilesInfo[index].Address = SUP_LUP_InfoIterator[index_bis].LUP_DestinationAddress;
            if ( SUP_LUP_InfoIterator[index_bis].LUP_EncryptionStatus == K_ENCRYPTED )
            {
               DataFilesInfo[index].Encrypted = e_CMN_FLAG_YES;
            }
            else
            {
               DataFilesInfo[index].Encrypted = e_CMN_FLAG_NO;
            }
            DataFilesInfo[index].ExpectedCRC16
                    = SUP_LUP_InfoIterator[index_bis].LUP_EncryptedCRC16;
            if ( SUP_LUP_InfoIterator[index_bis].LUP_Type == K_MAIN_APPLICATION_FILE )
            {
               if ( *LaunchAddressFound == e_CMN_FLAG_NO )
               {
                  *LaunchAddress = (uint8_t*)(((uint32_t)SUP_LUP_InfoIterator[index_bis].LUP_DestinationAddress) /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
                                 + SUP_LUP_InfoIterator[index_bis].LUP_EntryPointDelta );
                  *LaunchAddressFound = e_CMN_FLAG_YES;
               }
               else
               {
                  *OutOfOperationalConditionSUP = e_CMN_FLAG_YES;
                  return;
               }
            }
            break;
         }
      }
      if ( DataFileFound == e_CMN_FLAG_NO )
      {
         *OutOfOperationalConditionSUP = e_CMN_FLAG_YES;
         return;
      }
   }
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
