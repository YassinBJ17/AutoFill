/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : 
 * -------------------------------------------------------------------------- */


 
/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_private.h"
#include "BOOT_LIBMEM_public.h"
#include "LIBUTI_SIF.h"

/* ---------- include required interface: ----------------------------------- */


/* ---------- internal define constants: ------------------------------------ */
/* none */

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

void BOOT_PBIT_SW_GetFilesHASH_FromSIF_Header(
   /*IN*/
   const uint8_t * const           SIF_HeaderAddress,
   const uint32_t                  NumberOfFiles,
   const te_CMN_FLAG_QUESTION      SIF_FileFound,
   const TS_FileInfo * const       SIF_FileInfo,
   /*INOUT*/
   TS_FileInfo * const             FilesInfo,
   /*OUT*/
   te_CMN_FLAG_QUESTION * const    OutOfOperationalConditionSIF,
   TE_LIBUTI_SIF_check_algorithm * p_SIF_hashmode
)
{
   /* Declaration of local variables ------------------------------------------- */

   uint32_t             index;
   uint32_t             LIBUTI_SIF_GetHashReturnCode;
   te_CMN_FLAG_QUESTION AllFiles_Found;
   te_CMN_FLAG_QUESTION l_hashmodeStatus;
   uint8_t              hash_buffer[64];
   tu_LIBUTI_SIF_hash * pt_hash_buffer;

   /* Function body ------------------------------------------------------------ */ 

   AllFiles_Found = e_CMN_FLAG_YES;
   pt_hash_buffer = (tu_LIBUTI_SIF_hash *)hash_buffer;

   for ( index = 0; index < NumberOfFiles; index++ )
   {
      if ( ( SIF_FileFound == e_CMN_FLAG_NO ) || ( (&FilesInfo[index]) != SIF_FileInfo) )
      {
         l_hashmodeStatus = LIBUTI_SIF_has_hashmode(
                                    SIF_HeaderAddress,
                                    FilesInfo[index].ARINC_665_FileInfo->Name,
                                    FilesInfo[index].ARINC_665_FileInfo->NameLength,
                                    p_SIF_hashmode );

         if ( l_hashmodeStatus == e_CMN_FLAG_YES )
         {
            LIBUTI_SIF_GetHashReturnCode = LIBUTI_SIF_get_hash(
                                              SIF_HeaderAddress,
                                              FilesInfo[index].ARINC_665_FileInfo->Name,
                                              FilesInfo[index].ARINC_665_FileInfo->NameLength,
                                              *p_SIF_hashmode,
                                              pt_hash_buffer );

            if (LIBUTI_SIF_GetHashReturnCode == E_LIBUTI_SIF_SUCCESS)
            {
               switch ( *p_SIF_hashmode )
               {
                  case E_LIBUTI_SIF_CHECK_ALGORITHM_MD5:
                     /* code */
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA1:
                     /* code */
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256:
                     BOOT_LIBMEM_CPY(FilesInfo[index].ExpectedSHA256, pt_hash_buffer->sha256.Data_SHA256, 32);
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_512:
                     BOOT_LIBMEM_CPY(FilesInfo[index].ExpectedSHA512, pt_hash_buffer->sha512.Data_SHA512, 64); /* Error ? TOBE Verified, SHA2-512 is implemtend not SHA3: Impact on FADEX, M88 and COBRA*/
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_256:
                     /* code */
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_SHA3_512:
                     /* code */
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_256:
                     /* code */
                     break;

                  case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2B_512:
                     /* code */
                     break;
                  case E_LIBUTI_SIF_CHECK_ALGORITHM_BLAKE2S_256:
                     /* code */
                     break;
                  
                  default:
                     break;
               }
            }
            if ( LIBUTI_SIF_GetHashReturnCode != E_LIBUTI_SIF_SUCCESS )
            {
               AllFiles_Found = e_CMN_FLAG_NO;
            }
         }
      }
   }

   if ( AllFiles_Found == e_CMN_FLAG_NO )
   {
      *OutOfOperationalConditionSIF = e_CMN_FLAG_YES;
   }
   else
   {
      *OutOfOperationalConditionSIF = e_CMN_FLAG_NO;
   }

}
