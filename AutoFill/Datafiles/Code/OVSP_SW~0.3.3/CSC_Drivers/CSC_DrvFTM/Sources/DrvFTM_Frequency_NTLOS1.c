/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the NTLOS1 frequency input acquisition functions
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvFTM_Private.h"
#include "DrvFTM_Public.h"


/* ---------- include required interface: ----------------------------------- */
#include "Boot_Public.h"
#include "OVSP_Public.h"

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
/* DrvFTM_Start_NTLOS1_Acquisition : To start the NTLOS1 frequency acquisition
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Start_NTLOS1_Acquisition (void)
{
   volatile TS_DrvFTM_Registers * pt_FLEXTIMER0 =
      C_DrvFTM_Controller [DRVFTM_TIMER_0];

   uint8_t v_OVSP_Side_Id;

   if (0UL ==
       ((pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC & DRVFTM_CNSC_ELSA_MASK) >>
       DRVFTM_CNSC_ELSA_SHIFT))
   {
      v_OVSP_Side_Id = Boot_Get_Side_Id ();

      switch (v_OVSP_Side_Id)
      {
         case BOOT_SIDE_ID_HS:
         {
            pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC |=
               ((0UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);

            pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC |=
               ((1UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);
         }
         break;

         case BOOT_SIDE_ID_LS:
         {
            pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC |=
               ((1UL << DRVFTM_CNSC_ELSA_SHIFT) & DRVFTM_CNSC_ELSA_MASK);

            pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC |=
               ((1UL << DRVFTM_CNSC_ELSB_SHIFT) & DRVFTM_CNSC_ELSB_MASK);
         }
         break;

         default:
         { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
           /* Nothing to do */
         }
         break;

      }
   }
   else
   { /* %RELAX<SYNCHRONe_C_Code_14.2> To avoid suspicion of missing statement */
      /* Nothing to do */
   }
}


/* DrvFTM_Stop_NTLOS1_Acquisition : To stop the NTLOS1 frequency acquisition
 *   Inputs: None
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvFTM_Stop_NTLOS1_Acquisition (void)
{
   volatile TS_DrvFTM_Registers * pt_FLEXTIMER0 =
      C_DrvFTM_Controller [DRVFTM_TIMER_0];

   pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC &= ~DRVFTM_CNSC_ELSA_MASK;
   pt_FLEXTIMER0->S_CONTROLS [DRVFTM_CHAN_2].S_CnSC &= ~DRVFTM_CNSC_ELSB_MASK;
}
