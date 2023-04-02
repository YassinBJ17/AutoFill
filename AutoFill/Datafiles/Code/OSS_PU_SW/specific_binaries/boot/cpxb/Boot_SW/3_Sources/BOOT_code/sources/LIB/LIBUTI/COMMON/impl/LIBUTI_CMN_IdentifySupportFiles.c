/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_TestSupportFile.h"

void LIBUTI_CMN_IdentifySupportFiles
(
   /*IN*/
   const uint32_t               NumberOfSupportFiles,
   const TS_FileInfo *    const SupportFilesInfo,
   /*OUT*/
   te_CMN_FLAG_QUESTION * const CMP_FileFound,
   const TS_FileInfo **   const CMP_FileInfo,
   te_CMN_FLAG_QUESTION * const SUP_FileFound,
   const TS_FileInfo **   const SUP_FileInfo,
   te_CMN_FLAG_QUESTION * const LUD_FileFound,
   const TS_FileInfo **   const LUD_FileInfo,
   te_CMN_FLAG_QUESTION * const SIF_FileFound,
   const TS_FileInfo **   const SIF_FileInfo,
   te_CMN_FLAG_QUESTION * const SKF_FileFound,
   const TS_FileInfo **   const SKF_FileInfo,
   te_CMN_FLAG_QUESTION * const OutOfOperationalConditionLoad
)
{
   uint32_t  index;
   uint32_t  FileNameLengthBuffer;
   uint8_t * FileNameAddressBuffer;
   te_CMN_FLAG_QUESTION FileFound;

   const uint8_t CMP[4] = {'.','C','M','P'};
   const uint8_t SUP[4] = {'.','S','U','P'};
   const uint8_t LUD[4] = {'.','L','U','D'};
   const uint8_t SIF[4] = {'.','S','I','F'};
   const uint8_t SKF[4] = {'.','S','K','F'};

   *CMP_FileFound = e_CMN_FLAG_NO;
   *SUP_FileFound = e_CMN_FLAG_NO;
   *LUD_FileFound = e_CMN_FLAG_NO;
   *SIF_FileFound = e_CMN_FLAG_NO;
   *SKF_FileFound = e_CMN_FLAG_NO;
   *OutOfOperationalConditionLoad = e_CMN_FLAG_NO;

   for ( index = (uint32_t)0; index < NumberOfSupportFiles; index++ )
   {
      /*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on SupportFilesInfo. Poiter used as buffer with support files infos in it.*/
      /*Can't use anrray because size depend on number of sup files.*/
      /*Overflow avoid by check index<NumberOfSupportFiles in the for instruction*/
      FileNameLengthBuffer = (uint32_t)(SupportFilesInfo[index].ARINC_665_FileInfo->NameLength);
      FileNameAddressBuffer = (uint8_t*)(SupportFilesInfo[index].ARINC_665_FileInfo->Name);

      FileFound = LIBUTI_CMN_TestSupportFile( FileNameLengthBuffer,
                                              FileNameAddressBuffer,
                                              &(SupportFilesInfo[index]),
                                              CMP,
                                              CMP_FileFound,
                                              CMP_FileInfo,
                                              OutOfOperationalConditionLoad );
      if( FileFound != e_CMN_FLAG_NO )
      {
         continue;
      }

      FileFound = LIBUTI_CMN_TestSupportFile( FileNameLengthBuffer,
                                              FileNameAddressBuffer,
                                              &(SupportFilesInfo[index]),
                                              SUP,
                                              SUP_FileFound,
                                              SUP_FileInfo,
                                              OutOfOperationalConditionLoad );
      if( FileFound != e_CMN_FLAG_NO )
      {
         continue;
      }

      FileFound = LIBUTI_CMN_TestSupportFile( FileNameLengthBuffer,
                                              FileNameAddressBuffer,
                                              &(SupportFilesInfo[index]),
                                              LUD,
                                              LUD_FileFound,
                                              LUD_FileInfo,
                                              OutOfOperationalConditionLoad );
      if( FileFound != e_CMN_FLAG_NO )
      {
         continue;
      }

      FileFound = LIBUTI_CMN_TestSupportFile( FileNameLengthBuffer,
                                              FileNameAddressBuffer,
                                              &(SupportFilesInfo[index]),
                                              SIF,
                                              SIF_FileFound,
                                              SIF_FileInfo,
                                              OutOfOperationalConditionLoad );
      if( FileFound != e_CMN_FLAG_NO )
      {
         continue;
      }

      (void) LIBUTI_CMN_TestSupportFile( FileNameLengthBuffer,
                                         FileNameAddressBuffer,
                                         &(SupportFilesInfo[index]),
                                         SKF,
                                         SKF_FileFound,
                                         SKF_FileInfo,
                                         OutOfOperationalConditionLoad );
      /*}}RELAX<SYNCHRONe_C_Code_17.4> */
      if ( *OutOfOperationalConditionLoad != e_CMN_FLAG_NO )
      {
         break;
      }
   }
}
