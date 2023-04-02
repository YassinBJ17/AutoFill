/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This function launch the integrity and the compatibility
 *               of software, and, starts results records.
 * -------------------------------------------------------------------------- */


/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_PBIT_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "BOOT_PBIT_private.h"

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

#pragma section SECTION_BOOT_OPEN_CLOSE_FLS_PBIT "" ".BOOT_OPEN_CLOSE_FLS_PBIT"
#pragma use_section SECTION_BOOT_OPEN_CLOSE_FLS_PBIT BOOT_FLS_PBIT
uint32_t BOOT_FLS_PBIT;


void BOOT_PBIT_SW_MAIN(void)
{
   te_CMN_FLAG_QUESTION LoadFailed;
   te_CMN_FLAG_QUESTION FlashReadFailed;
   uint8_t *            LoadedSoftwareLaunchAddress;
   TS_LoadStatus        PrimaryLoadStatus;
   uint32_t             NumberOfSecondaryLoads;
   TS_LoadStatus        SecondaryLoadsStatus[K_MAX_NUMBER_OF_SECONDARY_LOAD];
   uint32_t             index;

   /* Check the BOOT Integrity */
   BOOT_PBIT_SW_SELF_INTEGRITY();

  /* Initialization of local variables */
  LoadFailed = e_CMN_FLAG_NO;
  FlashReadFailed = e_CMN_FLAG_NO;
  LoadedSoftwareLaunchAddress = (uint8_t*)0xFFFFFFFF;
  return;
  
  // if (BOOT_FLS_PBIT == 0xBAEBAE){
     // return;
  // }
  // else{
     // BOOT_LIBMEM_SET(
        // PrimaryLoadStatus.Name,
        // 0,
        // (uint32_t)K_LOAD_NAME_MAX_LENGTH );

     // PrimaryLoadStatus.Corrupted = e_CMN_FLAG_NO;
     // PrimaryLoadStatus.OutOfOperationalCondition = e_CMN_FLAG_NO;
     // PrimaryLoadStatus.Incompatible = e_CMN_FLAG_NO;
     // PrimaryLoadStatus.CRC_32 = 0x00000000;
     // NumberOfSecondaryLoads = 0;

     // for ( index = 0; index < K_MAX_NUMBER_OF_SECONDARY_LOAD; index++ )
     // {
        // BOOT_LIBMEM_SET(
           // SecondaryLoadsStatus[index].Name,
           // 0,
           // (uint32_t)K_LOAD_NAME_MAX_LENGTH );

        // SecondaryLoadsStatus[index].Corrupted = e_CMN_FLAG_NO;
        // SecondaryLoadsStatus[index].OutOfOperationalCondition = e_CMN_FLAG_NO;
        // SecondaryLoadsStatus[index].Incompatible = e_CMN_FLAG_NO;
        // SecondaryLoadsStatus[index].CRC_32 = 0x00000000;
     // }
     // /* */

     // /* Launch the test for the selected mode (dataloader or asterios)*/
     // BOOT_PBIT_SW_SELECT_LOAD(
        // /*OUT*/
        // &LoadFailed,
        // &FlashReadFailed,
        // &LoadedSoftwareLaunchAddress,
        // &PrimaryLoadStatus,
        // &NumberOfSecondaryLoads,
        // SecondaryLoadsStatus );

     // /* Records SW Validity test results */
     // BOOT_PBIT_SW_RECORD(
        // /*IN*/
        // &PrimaryLoadStatus,
        // NumberOfSecondaryLoads,
        // SecondaryLoadsStatus );
  // }
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
