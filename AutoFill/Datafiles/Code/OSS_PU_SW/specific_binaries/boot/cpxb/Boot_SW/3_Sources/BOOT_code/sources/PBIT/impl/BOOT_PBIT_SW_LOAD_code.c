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

void BOOT_PBIT_SW_LOAD(
   /*IN*/
   uint8_t *               BOOT_Name,
   uint32_t                BOOT_NumberOfCompatibilityRules,
   TS_CompatibilityRule *  BOOT_CompatibilityRules,
   uint8_t *               PrimaryLoadLUH_FlashAddress,
   uint8_t *               PrimaryLoadSIF_HeaderENVM_Address,
   /*OUT*/
   te_CMN_FLAG_QUESTION *  LoadFailed,
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   uint8_t **              LoadedSoftwareLaunchAddress,
   TS_LoadStatus *         PrimaryLoadStatus,
   uint32_t *              NumberOfSecondaryLoads,
   TS_LoadStatus *         SecondaryLoadsStatus
)
{
   uint32_t                index;
   uint8_t                 PrimaryLoadName[K_FILE_NAME_MAX_LENGTH];
   uint32_t                PrimaryLoadNumberOfCompatibilityRules;
   TS_CompatibilityRule    PrimaryLoadCompatibilityRules[K_MAX_NUMBER_OF_COMPAT_RULES];
   TS_SecondaryLoadInfo    SecondaryLoadsInfo[K_MAX_NUMBER_OF_SECONDARY_LOAD];

   /* Check the Software primary load */
   BOOT_PBIT_SW_PrimaryLoad(
      /*IN*/
      BOOT_Name,
      BOOT_NumberOfCompatibilityRules,
      BOOT_CompatibilityRules,
      PrimaryLoadLUH_FlashAddress,
      PrimaryLoadSIF_HeaderENVM_Address,
      /*OUT*/
      PrimaryLoadName,
      &PrimaryLoadNumberOfCompatibilityRules,
      PrimaryLoadCompatibilityRules,
      NumberOfSecondaryLoads,
      SecondaryLoadsInfo,
      LoadFailed,
      FlashReadFailed,
      LoadedSoftwareLaunchAddress,
      PrimaryLoadStatus );

   if ( *LoadFailed == e_CMN_FLAG_NO )
   {
      /* Check the software secondary loads*/
      for ( index = 0; index < *NumberOfSecondaryLoads; index++ )
      {
         BOOT_LIBMEM_CPY(
            SecondaryLoadsStatus[index].Name,
            SecondaryLoadsInfo[index].Name,
            K_LOAD_NAME_MAX_LENGTH );

         BOOT_PBIT_SW_SecondaryLoad(
            /*IN*/
            PrimaryLoadName,
            PrimaryLoadNumberOfCompatibilityRules,
            PrimaryLoadCompatibilityRules,
            &(SecondaryLoadsInfo[index]),
            /*OUT*/
            FlashReadFailed,
            &(SecondaryLoadsStatus[index]) );

         if( *FlashReadFailed == e_CMN_FLAG_YES )
         {
            *LoadFailed = e_CMN_FLAG_YES;
            break;
         }
      }
   }
}
