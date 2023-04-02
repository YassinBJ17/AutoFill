/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the Boot CSC initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "Boot_Public.h"
#include "Boot_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "CAN_Public.h"
#include "CBIT_Public.h"
#include "Config_Public.h"

#include "DrvADC_Public.h"
#include "DrvCAN_Public.h"
#include "DrvCPU_Public.h"
#include "DrvFTFC_Public.h"
#include "DrvFTM_Public.h"
#include "DrvGPIO_Public.h"
#include "DrvLPIT_Public.h"
#include "DrvLPSPI_Public.h"
#include "DrvMCM_Public.h"
#include "DrvNVIC_Public.h"
#include "DrvPAD_Public.h"
#include "DrvPCC_Public.h"
#include "DrvSBC_Public.h"
#include "DrvSCG_Public.h"
#include "DrvWDOG_Public.h"

#include "IO_Public.h"
#include "Logbook_Public.h"
#include "Modes_Public.h"
#include "OVSP_Public.h"
#include "PBIT_Public.h"
#include "Seq_Public.h"

#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* Boot_Initialize : To initialize the Boot CSC and peripherals
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void Boot_Initialize (void)
{
   DrvCPU_Initialize ();

   DrvWDOG_Initialize ();

   DrvCPU_Init_Stack ();

   DrvCPU_Exit_Crit_Sect ();

   PBIT_Test_RAM ();

   DrvFTFC_Copy_Data_To_RAM ();

   /* >RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision as it is a 32-bit Unsigned Long address */
   /* converted to a pointer which is also an 32-bit Unsigned Long. */
   V_Boot_OVSP_Side_Id = *((uint8_t *) BOOT_OVSP_SW_SIDE_ID_ADDR);

   switch (V_Boot_OVSP_Side_Id)
   {
      case BOOT_SIDE_ID_HS:
      case BOOT_SIDE_ID_LS:
      { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
         /* Nothing to do */
      }
      break;

      default:
      {
         V_Boot_OVSP_Side_Id = BOOT_SIDE_ID_INVALID;
      }
      break;

   }

   /* Drivers initializations order has not to be changed */
   DrvSCG_Initialize ();

   DrvPCC_Initialize ();

   DrvPAD_Initialize ();

   DrvGPIO_Initialize ();

   DrvNVIC_Initialize (DRVNVIC_BOOT_IRQ_SELECTION);

   DrvLPSPI_Initialize ();

   DrvSBC_Initialize ();

   DrvCAN_Initialize ();

   DrvADC_Initialize ();

   DrvFTM_Initialize ();

   DrvMCM_Initialize ();

   DrvLPIT_Initialize ();


   CAN_Initialize ();

   CBIT_Initialize ();

   Config_Initialize ();

   IO_Initialize ();

   Logbook_Initialize ();

   Modes_Initialize ();

   OVSP_Initialize ();

   PBIT_Initialize ();


   PBIT_Treatments ();

   Modes_Treatments ();

   Seq_Initialize ();

   Seq_Task_BckGrnd ();

   while (TRUE)
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}
