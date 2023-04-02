/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#include "LIBUTI_CMN_MatchingFiles.h"

void LIBUTI_CMN_MatchingFiles( const uint8_t Name[], const uint16_t NameLength, const uint8_t LUP_Name[], te_CMN_FLAG_QUESTION* const ret) /* %RELAX<SYNCHRONe_C_Code_8.12> The size of the arrays are not known at this point */
{

   uint32_t index;
   *ret = e_CMN_FLAG_YES;
   for( index = ((uint32_t) 0); index < (uint32_t)NameLength; index++ )
   {
      if( Name[index] != LUP_Name[index] )
      {
         *ret = e_CMN_FLAG_NO;
         break;
      }
   }

}