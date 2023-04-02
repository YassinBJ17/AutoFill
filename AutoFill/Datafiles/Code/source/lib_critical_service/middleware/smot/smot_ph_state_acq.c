/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Smot initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/smot/smot_gpio_common.h"
#include "middleware/smot/smot_write_public.h"
#include "middleware/smot/smot_private.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ------ --- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SMOT-0001 */
/* Implements REQ_FADEX_OS_SRD-SMOT-0010 */
/* Acquire the smot phases state from GPIO */
void smot_ph_state_acq(uint32_t* p_smot_ph_state_idx /* out */)
{
/* If the smot phase 1 is commanded */
   if ((uint8_t)1 == *smot_ph_1 && (uint8_t)0 == *smot_ph_2 && (uint8_t)0 == *smot_ph_3 && (uint8_t)0 == *smot_ph_4)
   {
      /* Set the corresponding index to the smot state feedback */
      *p_smot_ph_state_idx = SMOT_PH1_IDX;
   }
   /* If the smot phases 1 and 4 are commanded */
   else if((uint8_t)1 == *smot_ph_1 && (uint8_t)0 == *smot_ph_2 && (uint8_t)0 == *smot_ph_3 && (uint8_t)1 == *smot_ph_4)
   {
      /* Set the corresponding index to the smot state feedback */
      *p_smot_ph_state_idx = SMOT_PH1_PH4_IDX;
   }

   /* If the smot phase 2 is commanded */
   if ((uint8_t)0 == *smot_ph_1 && (uint8_t)1 == *smot_ph_2 && (uint8_t)0 == *smot_ph_3 && (uint8_t)0 == *smot_ph_4)
   {
      /* Set the corresponding index to the smot state feedback */
      *p_smot_ph_state_idx = SMOT_PH2_IDX;
   }
   /* If the smot phases 2 and 3 are commanded */
   else if((uint8_t)0 == *smot_ph_1 && (uint8_t)1 == *smot_ph_2 && (uint8_t)1 == *smot_ph_3 && (uint8_t)0 == *smot_ph_4)
   {
      /* Set the corresponding index to the smot state feedback */
      *p_smot_ph_state_idx = SMOT_PH2_PH3_IDX;
   }

   /* If the smot phase 1 and 2 are not commanded */
   if ((uint8_t)0 == *smot_ph_1 && (uint8_t)0 == *smot_ph_2)
   {
      /* And the smot phase 3 is commanded */
      if ((uint8_t)1 == *smot_ph_3 && (uint8_t)0 == *smot_ph_4)
      {
         /* Set the corresponding index to the smot state feedback */
         *p_smot_ph_state_idx = SMOT_PH3_IDX;
      }
      /* And the smot phase 4 is commanded */
      else if ((uint8_t)0 == *smot_ph_3 && (uint8_t)1 == *smot_ph_4)
      {
         /* Set the corresponding index to the smot state feedback */
         *p_smot_ph_state_idx = SMOT_PH4_IDX;
      }
      /* And the smot phase 3 and 4 are simultaneously commanded */
      else if ((uint8_t)1 == *smot_ph_3 && (uint8_t)1 == *smot_ph_4)
      {
         /* Set the corresponding index to the smot state feedback */
         *p_smot_ph_state_idx = SMOT_PH3_PH4_IDX;
      }
   }
   /* If the smot phase 1 and 2 are simultaneously commanded */
   if ((uint8_t)1 == *smot_ph_1 && (uint8_t)1 == *smot_ph_2 && (uint8_t)0 == *smot_ph_3 && (uint8_t)0 == *smot_ph_4)
   {
      /* Set the corresponding index to the smot state feedback */
      *p_smot_ph_state_idx = SMOT_PH1_PH2_IDX;
   }
}

/* ---------- internal operations: ------------------------------------------ */
