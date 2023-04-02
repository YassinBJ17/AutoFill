/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Select the load to test according to the mode
 *               (ASTERIOS or DTLD)
 *
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_private.h"
#include "BOOT_MAIN_public.h"
#include "BOOT_CART_HardwareID.h"
#include "BOOT_FAULT_public.h"

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

void BOOT_PBIT_SW_SELECT_LOAD(
   /*OUT*/
   te_CMN_FLAG_QUESTION *  LoadFailed,
   te_CMN_FLAG_QUESTION *  FlashReadFailed,
   uint8_t **              LoadedSoftwareLaunchAddress,
   TS_LoadStatus *         PrimaryLoadStatus,
   uint32_t *              NumberOfSecondaryLoads,
   TS_LoadStatus*          SecondaryLoadsStatus
)
{
   switch ( V_BOOT_MAIN_Cores_Running_Mode )
   {
      case e_MODE_CHOICE_ASTERIOS:
         /* Check OS SW Load */
         BOOT_PBIT_SW_LOAD(
            /*IN*/
            (uint8_t*)              K_BOOT_DESCRIPTOR.HardwareCompatibilityID,
            (uint32_t)              K_BOOT_DESCRIPTOR.NumberOfCompatibilityCriteria,
            (TS_CompatibilityRule*) K_BOOT_DESCRIPTOR.CompatibilityCriterias,
            (uint8_t*)              K_BOOT_DESCRIPTOR.OpeLoadFlashAddress,
            (uint8_t*)              K_BOOT_DESCRIPTOR.OpeLoadSIF_HeaderENVM_Address,

            /*OUT*/
            LoadFailed,
            FlashReadFailed,
            LoadedSoftwareLaunchAddress,
            PrimaryLoadStatus,
            NumberOfSecondaryLoads,
            SecondaryLoadsStatus );
		   if (*LoadFailed==e_CMN_FLAG_YES)
		   {
		      BOOT_FAULT_LOG(BOOT_FAULT_OS_INTEGRITY, PBIT_ORIGIN, PrimaryLoadStatus->Corrupted, PrimaryLoadStatus->CRC_32, SecondaryLoadsStatus->CRC_32, SecondaryLoadsStatus->Corrupted);
		      BOOT_FAULT_INFINITELOOP();
		   }
      break;

      case e_MODE_CHOICE_DTLD:
         /* Check of DTL SW*/
         BOOT_PBIT_SW_LOAD(
            /*IN*/
            (uint8_t*)              K_BOOT_DESCRIPTOR.HardwareCompatibilityID,
            (uint32_t)              K_BOOT_DESCRIPTOR.NumberOfCompatibilityCriteria,
            (TS_CompatibilityRule*) K_BOOT_DESCRIPTOR.CompatibilityCriterias,
            (uint8_t*)              K_BOOT_DESCRIPTOR.DTL_LoadFlashAddress,
            (uint8_t*)              K_BOOT_DESCRIPTOR.DTL_LoadSIF_HeaderENVM_Address,

            /*OUT*/
            LoadFailed,
            FlashReadFailed,
            LoadedSoftwareLaunchAddress,
            PrimaryLoadStatus,
            NumberOfSecondaryLoads,
            SecondaryLoadsStatus );
		   if (*LoadFailed==e_CMN_FLAG_YES)
		   {
		      BOOT_FAULT_LOG(BOOT_FAULT_DTLD_INTEGRITY, PBIT_ORIGIN, PrimaryLoadStatus->Corrupted, PrimaryLoadStatus->CRC_32, SecondaryLoadsStatus->CRC_32, SecondaryLoadsStatus->Corrupted);
		      BOOT_FAULT_INFINITELOOP();
		   }
      break;

      default:
         while( 1==1 );
      break;
   }
}
