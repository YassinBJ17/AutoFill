/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
 
#include "LIBUTI_CMN_TestSupportFile.h"

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointer FileNameAddressBuffer because its used as buffer.*/ 
/*Can't use a fix array, depends on the FileNameLengthBuffer*/
/*Solution kept.*/

te_CMN_FLAG_QUESTION LIBUTI_CMN_TestSupportFile
(
/*IN*/
   const uint32_t FileNameLengthBuffer, 
   uint8_t * const FileNameAddressBuffer,
   const TS_FileInfo * const Pointer_to_SupportFilesInfo,
   const uint8_t FileExtensionBuffer[4],
/*OUT*/
   te_CMN_FLAG_QUESTION * const FileFound,
   const TS_FileInfo** const FileInfo,
   te_CMN_FLAG_QUESTION * const OutOfOperationalConditionLoad
)
{
   te_CMN_FLAG_QUESTION v_Found;

   v_Found = e_CMN_FLAG_NO;
   if(      ( FileNameAddressBuffer[FileNameLengthBuffer-4ul] == FileExtensionBuffer[0] )
      &&    ( FileNameAddressBuffer[FileNameLengthBuffer-3ul] == FileExtensionBuffer[1] )
      &&    ( FileNameAddressBuffer[FileNameLengthBuffer-2ul] == FileExtensionBuffer[2] )
      &&    ( FileNameAddressBuffer[FileNameLengthBuffer-1ul] == FileExtensionBuffer[3] ) )
   {
      v_Found = e_CMN_FLAG_YES;
      if( *FileFound == e_CMN_FLAG_NO )
      {
         *FileInfo = Pointer_to_SupportFilesInfo;
         *FileFound = e_CMN_FLAG_YES;
      }
      else
      {
         *OutOfOperationalConditionLoad = e_CMN_FLAG_YES;
      }
   }
   return ( v_Found );
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
