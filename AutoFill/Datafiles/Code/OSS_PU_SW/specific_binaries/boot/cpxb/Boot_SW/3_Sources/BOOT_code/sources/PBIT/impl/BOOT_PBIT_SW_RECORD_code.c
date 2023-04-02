/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : 
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

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* none */

/* ---------- internal operation bodies: ------------------------------------ */
/* none */

#pragma section SECTION_BOOT_LOG_VALIDITY_TEST "" ".BOOT_LOG_VALIDITY_TEST"
#pragma use_section SECTION_BOOT_LOG_VALIDITY_TEST BOOT_SDRAM_Log
TS_BOOT_SDRAM_Log BOOT_SDRAM_Log;

void BOOT_PBIT_SW_RECORD(
   TS_LoadStatus *      PrimaryLoadStatus,
   uint32_t             NumberOfSecondaryLoads,
   TS_LoadStatus *      SecondaryLoadsStatus
)
{
   uint32_t index;

   /* [TODO] add the results of the BOOT validity check */
   /*SDRAM log*/
   BOOT_LIBMEM_SET(
      (uint8_t*)&BOOT_SDRAM_Log,
      0,
      (uint32_t)sizeof(TS_BOOT_SDRAM_Log) );

   BOOT_LIBMEM_CPY(
      BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.Name,
      PrimaryLoadStatus->Name,
      (uint32_t)K_LOAD_NAME_MAX_LENGTH );

   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.PartNumberSize = PrimaryLoadStatus->PartNumberSize;
   BOOT_LIBMEM_CPY(
      BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.PartNumber,
      PrimaryLoadStatus->PartNumber,
      (uint32_t)K_LOAD_PN_LENGTH );
   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.BitField.Corrupted
      = (PrimaryLoadStatus->Corrupted == e_CMN_FLAG_YES ? 1 : 0 );

   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.BitField.OutOfOperationalCondition
      = (PrimaryLoadStatus->OutOfOperationalCondition == e_CMN_FLAG_YES ? 1 : 0 );

   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.BitField.Incompatible
      = (PrimaryLoadStatus->Incompatible == e_CMN_FLAG_YES ? 1 : 0 );

   BOOT_SDRAM_Log.LoadsStatus.PrimaryLoadStatus.CRC_32 = PrimaryLoadStatus->CRC_32;
   BOOT_SDRAM_Log.LoadsStatus.NumberOfSecondaryLoads = NumberOfSecondaryLoads;

   for ( index = 0; index < NumberOfSecondaryLoads; index++ )
   {
      BOOT_LIBMEM_CPY(
         BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].Name,
         SecondaryLoadsStatus[index].Name,
         (uint32_t)K_LOAD_NAME_MAX_LENGTH );

      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].PartNumberSize = SecondaryLoadsStatus[index].PartNumberSize;
      BOOT_LIBMEM_CPY(
         BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].PartNumber,
         SecondaryLoadsStatus[index].PartNumber,
         (uint32_t)K_LOAD_PN_LENGTH );
      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].BitField.Corrupted
         = (SecondaryLoadsStatus[index].Corrupted == e_CMN_FLAG_YES ? 1 : 0 );

      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].BitField.OutOfOperationalCondition
         = (SecondaryLoadsStatus[index].OutOfOperationalCondition == e_CMN_FLAG_YES ? 1 : 0 );

      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].BitField.Incompatible
         = (SecondaryLoadsStatus[index].Incompatible == e_CMN_FLAG_YES ? 1 : 0 );

      BOOT_SDRAM_Log.LoadsStatus.SecondaryLoadsStatus[index].CRC_32
         = SecondaryLoadsStatus[index].CRC_32;
   }

}

