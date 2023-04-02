/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_IsCompatible.h"


/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on FirstLoadCompatibilityRules and SecondLoadCompatibilityRules.*/
/* Poiter used as buffer with compatibility rules in it.*/
/*Can't use anrray because size depend on number of rules.*/
/*Overflow avoid by for instructions where index is compare to a max value*/

void LIBUTI_CMN_TestCompatibilityBetweenLoads
(
   /*IN*/
   const uint8_t * const              FirstLoadName,
   const uint32_t                     FirstLoadNumberOfCompatibilityRules,
   const TS_CompatibilityRule * const FirstLoadCompatibilityRules,
   const uint8_t * const              SecondLoadName,
   const uint32_t                     SecondLoadNumberOfCompatibilityRules,
   const TS_CompatibilityRule * const SecondLoadCompatibilityRules,
   /*OUT*/
   te_CMN_FLAG_QUESTION * const       LoadsAreIncompatible
)
{
   uint32_t               index;
   uint32_t               index_bis;
   TS_CompatibilityRule * FirstLoadCompatRuleTargetingSecondLoad;
   TS_CompatibilityRule * SecondLoadCompatRuleTargetingFirstLoad;
   te_CMN_FLAG_QUESTION   FirstLoadRuleTargetingSecondLoad;
   te_CMN_FLAG_QUESTION   SecondLoadRuleTargetingFirstLoad;
   te_CMN_FLAG_QUESTION   oss_cu_found;

   *LoadsAreIncompatible = e_CMN_FLAG_NO;
   FirstLoadRuleTargetingSecondLoad = e_CMN_FLAG_NO;
   SecondLoadRuleTargetingFirstLoad = e_CMN_FLAG_NO;
   
   /* Only on FADEX : CDM asks for read bi-voie, cmp name is either OSS_CU1/CU2 or CU. Compatibility check has to be name with OSS_CU*/
   oss_cu_found = e_CMN_FLAG_NO;
   
   FirstLoadCompatRuleTargetingSecondLoad = NULL;
   SecondLoadCompatRuleTargetingFirstLoad = NULL;

   for ( index = (uint32_t)0; index < FirstLoadNumberOfCompatibilityRules; index++ )
   {
      FirstLoadRuleTargetingSecondLoad = e_CMN_FLAG_YES;
         
      if (oss_cu_found == e_CMN_FLAG_YES)
      {
         break;
      }

      for ( index_bis = (uint32_t)0; index_bis < K_LOAD_NAME_MAX_LENGTH_CMP; index_bis++ )
      {
         if (index_bis == 6)
         {
            if(  ( FirstLoadCompatibilityRules[index].TargetName[index_bis-6] == 'O' )
               && ( FirstLoadCompatibilityRules[index].TargetName[index_bis-5] == 'S' )
               && ( FirstLoadCompatibilityRules[index].TargetName[index_bis-4] == 'S' )
               && ( FirstLoadCompatibilityRules[index].TargetName[index_bis-3] == '_' )
               && ( FirstLoadCompatibilityRules[index].TargetName[index_bis-2] == 'C' )
               && ( FirstLoadCompatibilityRules[index].TargetName[index_bis-1] == 'U' ) 
            )
            {
               if(  ( SecondLoadName[index_bis-6] == 'O' )
               && ( SecondLoadName[index_bis-5] == 'S' )
               && ( SecondLoadName[index_bis-4] == 'S' )
               && ( SecondLoadName[index_bis-3] == '_' )
               && ( SecondLoadName[index_bis-2] == 'C' )
               && ( SecondLoadName[index_bis-1] == 'U' ) 
               )
               {
                  oss_cu_found = e_CMN_FLAG_YES;
                  break;
               }
            }
         }

         if ( FirstLoadCompatibilityRules[index].TargetName[index_bis] != SecondLoadName[index_bis] )
         {
            FirstLoadRuleTargetingSecondLoad = e_CMN_FLAG_NO;
            if (index_bis > 6)
            {
               break;
            }
         }
      }

      if ( FirstLoadRuleTargetingSecondLoad == e_CMN_FLAG_YES )
      {
         FirstLoadCompatRuleTargetingSecondLoad = (TS_CompatibilityRule*) &(FirstLoadCompatibilityRules[index]);
         break;
      }
   }
   
   oss_cu_found = e_CMN_FLAG_NO;
   
   for ( index = (uint32_t)0; index < SecondLoadNumberOfCompatibilityRules; index++ )
   {
      SecondLoadRuleTargetingFirstLoad = e_CMN_FLAG_YES;
      
      if (oss_cu_found == e_CMN_FLAG_YES)
      {
         break;
      }
      
      for ( index_bis = (uint32_t)0; index_bis < K_LOAD_NAME_MAX_LENGTH_CMP; index_bis++ )
      {
         if (index_bis == 6)
         {
            if(  ( SecondLoadCompatibilityRules[index].TargetName[index_bis-6] == 'O' )
               && ( SecondLoadCompatibilityRules[index].TargetName[index_bis-5] == 'S' )
               && ( SecondLoadCompatibilityRules[index].TargetName[index_bis-4] == 'S' )
               && ( SecondLoadCompatibilityRules[index].TargetName[index_bis-3] == '_' )
               && ( SecondLoadCompatibilityRules[index].TargetName[index_bis-2] == 'C' )
               && ( SecondLoadCompatibilityRules[index].TargetName[index_bis-1] == 'U' ) 
            )
            {
               if(  ( FirstLoadName[index_bis-6] == 'O' )
               && ( FirstLoadName[index_bis-5] == 'S' )
               && ( FirstLoadName[index_bis-4] == 'S' )
               && ( FirstLoadName[index_bis-3] == '_' )
               && ( FirstLoadName[index_bis-2] == 'C' )
               && ( FirstLoadName[index_bis-1] == 'U' ) 
               )
               {
                  oss_cu_found = e_CMN_FLAG_YES;
                  break;
               }
            }
         }
         
         if ( SecondLoadCompatibilityRules[index].TargetName[index_bis] != FirstLoadName[index_bis] )
         {
            SecondLoadRuleTargetingFirstLoad = e_CMN_FLAG_NO;
            if (index_bis > 6)
            {
               break;
            }
         }
      }

      if ( SecondLoadRuleTargetingFirstLoad == e_CMN_FLAG_YES )
      {
         SecondLoadCompatRuleTargetingFirstLoad = (TS_CompatibilityRule*) &(SecondLoadCompatibilityRules[index]);
         break;
      }
   }

   LIBUTI_CMN_IsCompatible( FirstLoadRuleTargetingSecondLoad,
                            SecondLoadRuleTargetingFirstLoad,
                            FirstLoadCompatRuleTargetingSecondLoad,
                            SecondLoadCompatRuleTargetingFirstLoad,
                            LoadsAreIncompatible );
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */
