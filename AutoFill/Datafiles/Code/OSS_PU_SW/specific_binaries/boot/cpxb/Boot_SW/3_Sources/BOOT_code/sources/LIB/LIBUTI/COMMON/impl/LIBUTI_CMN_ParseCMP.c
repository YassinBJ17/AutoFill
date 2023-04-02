/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#include "LIBUTI_COMMON.h"

typedef struct
{
   uint32_t CMP_Size;
   uint32_t CMP_Version;
   uint8_t  Identifier[K_LOAD_NAME_MAX_LENGTH_CMP];
   uint32_t NumberOfCompatibilityCriteria;
}__attribute__((packed)) TS_CMP_FileConstantSizeFirstFields;

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointers. Poiter used as buffer with files infos in it.*/
/*Can't use anrray because size is unknow.*/
/*Overflow avoid by for instructions where index is compare to a max value*/

void LIBUTI_CMN_ParseCMP
(
   /*IN*/
   const uint8_t * const         CMP_Address,
   const uint32_t                MaxNumberOfCompatibilityRules,
   /*OUT*/
   uint8_t * const               LoadName,
   uint32_t * const              NumberOfCompatibilityRules,
   TS_CompatibilityRule * const  CompatibilityRules,
   te_CMN_FLAG_QUESTION * const  OutOfOperationalConditionCMP
)
{
   uint32_t                             index;
   TS_CMP_FileConstantSizeFirstFields * CMP_FileConstantSizeFirstFields;
   TS_CompatibilityRule *               CompatibilityRulesIterator;

   *OutOfOperationalConditionCMP = e_CMN_FLAG_NO;

   CMP_FileConstantSizeFirstFields = ((TS_CMP_FileConstantSizeFirstFields*)CMP_Address); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion from generic ptr to ptr to specific structure */

   for ( index = ((uint32_t)0); index < K_LOAD_NAME_MAX_LENGTH_CMP; index++ )
   {
      LoadName[index] = (CMP_FileConstantSizeFirstFields->Identifier)[index];
   }

   *NumberOfCompatibilityRules = CMP_FileConstantSizeFirstFields->NumberOfCompatibilityCriteria;

   if ( *NumberOfCompatibilityRules > MaxNumberOfCompatibilityRules )
   {
      *OutOfOperationalConditionCMP = e_CMN_FLAG_YES;
      return;
   }

   CompatibilityRulesIterator = (TS_CompatibilityRule*)( (uint32_t)CMP_Address + sizeof(TS_CMP_FileConstantSizeFirstFields) ); /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */

   for ( index = ((uint32_t)0); index < *NumberOfCompatibilityRules; index++ )
   {
      CompatibilityRules[index] = CompatibilityRulesIterator[index];
   }
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
