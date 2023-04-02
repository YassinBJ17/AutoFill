/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Acquisition and check of channel identifier
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/calres/calres_gpio_common.h"
#include "middleware/calres/calres_public.h"
#include "middleware/calres/calres_private.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Definition of all GPIO inputs */
uint8_t *p_accom_gpi_002; /* SELECT_XRB_CALRES_RX_N */
uint8_t *p_accom_gpo_003; /* SELECT_XRB_CALRES_TX1 */
uint8_t *p_accom_gpo_232; /* PBIT_CALRES_RETURN_OPEN_N */
uint8_t *p_accom_gpo_289; /* CALRES_XRB_SEL */
uint8_t *p_accom_gpi_289; /* CALRES_XRB_SEL */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-CALRES-0010 */
/**
 *  Function to initialize GPIO inputs/outputs.
 */
void calres_gpio_init(const boolean_t is_calres_sensor_enabled,
                      const boolean_t channel_is_a)
{
   /* Initialization of pointers */
   p_accom_gpi_002 = GPDI_002; /* SELECT_XRB_CALRES_RX_N */
   p_accom_gpo_003 = GPDO_003; /* SELECT_XRB_CALRES_TX1 */
   p_accom_gpo_232 = GPDO_232; /* PBIT_CALRES_RETURN_OPEN_N */

   /* Initialization of GPDO's values, on channel A (CPMB) */
   if (channel_is_a)
   {
      if (is_calres_sensor_enabled)
      {
         /* PBIT_CALRES_RETURN_OPEN_N = 1 to activate the switch */
         *p_accom_gpo_232 = (uint8_t) 1;
      }
      else /* XRB sensor is enabled, Calres has to be disabled. */
      {
         /* PBIT_CALRES_RETURN_OPEN_N = 0 to disable the switch */
         *p_accom_gpo_232 = (uint8_t) 0;
      }
   }
   else /* Initialization of GPDO's values, on channel B (CPB) */
   {
      if (is_calres_sensor_enabled)
      {
         /* SELECT_XRB_CALRES_TX1 = 0 to activate the switch */
         *p_accom_gpo_003 = (uint8_t) 0;
         /* PBIT_CALRES_RETURN_OPEN_N = 1 to activate the switch */
         *p_accom_gpo_232 = (uint8_t) 1;
      }
      else /* XRB sensor is enabled, Calres has to be disabled. */
      {
         /* SELECT_XRB_CALRES_TX1 = 1 to disable the switch */
         *p_accom_gpo_003 = (uint8_t) 1;
         /* PBIT_CALRES_RETURN_OPEN_N = 0 to disable the switch */
         *p_accom_gpo_232 = (uint8_t) 0;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
