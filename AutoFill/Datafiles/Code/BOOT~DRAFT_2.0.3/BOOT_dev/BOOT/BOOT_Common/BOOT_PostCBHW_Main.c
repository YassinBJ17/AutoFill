#include "BOOT_Types.h"
#include "LIBUTI_MEM.h"
#include "BOOT_TestAndConfigureAdditionalHW.h"
#include "BOOT_ChooseAndLoadSW.h"
#include "BOOT_ManageFailuresAndLaunchSW.h"
#include "BOOT_InitStatus.h"

/* >RELAX<SYNCHRONe_C_Code_24.4> Called from VECT_Reset, not a local function  */
void BOOT_PostCBHW_Main(void) /* %RELAX<SYNCHRONe_C_Code_8.1> main() do not need a prototype */
{
   boolean_t v_PinProgPBIT_Failed;
   boolean_t v_CriticalPBIT_Failed;
   boolean_t v_MajorPBIT_Failed;
   ts_PBIT_Results v_PBIT_Results;
   ts_PinProgrammingInputsValues v_PinProgrammingInputsValues;
   boolean_t v_LoadFailed;
   boolean_t v_FlashReadFailed;
   uint32_t v_LoadedSoftwareLaunchAddress;
   ts_LoadStatus v_PrimaryLoadStatus;
   uint32_t v_NumberOfSecondaryLoads;
   ts_LoadStatus v_SecondaryLoadsStatus[C_BOOT_MAX_NUMBER_OF_SECONDARY_LOAD];
   
   BOOT_InitStatus(
      /* OUT */
      &v_PinProgPBIT_Failed,
      &v_CriticalPBIT_Failed,
      &v_MajorPBIT_Failed,
      &v_PBIT_Results,
      &v_PinProgrammingInputsValues,
      &v_LoadFailed,
      &v_FlashReadFailed,
      &v_LoadedSoftwareLaunchAddress,
      &v_PrimaryLoadStatus,
      &v_NumberOfSecondaryLoads,
      v_SecondaryLoadsStatus
   );

   BOOT_TestAndConfigureAdditionalHW
   (
      /*OUT*/
      &v_PinProgPBIT_Failed,
      &v_CriticalPBIT_Failed,
      &v_MajorPBIT_Failed,
      &v_PBIT_Results,
      &v_PinProgrammingInputsValues
   );

   BOOT_ChooseAndLoadSW
   (
   /*IN*/
      v_PinProgPBIT_Failed,
      v_MajorPBIT_Failed,
      v_CriticalPBIT_Failed,
      &v_PinProgrammingInputsValues,
   /*OUT*/
      &v_LoadFailed,
      &v_FlashReadFailed,
      &v_LoadedSoftwareLaunchAddress,
      &v_PrimaryLoadStatus,
      &v_NumberOfSecondaryLoads,
      v_SecondaryLoadsStatus
   );

   BOOT_ManageFailuresAndLaunchSW
   (
   /*IN*/
      &v_PBIT_Results,
      &v_PinProgrammingInputsValues,
      v_LoadFailed,
      v_FlashReadFailed,
      v_LoadedSoftwareLaunchAddress,
      &v_PrimaryLoadStatus,
      v_NumberOfSecondaryLoads,
      v_SecondaryLoadsStatus
   );

   /* Infinite loop - Robustness */
   LIBUTI_CMN_WaitUntilPowerDown( );
}