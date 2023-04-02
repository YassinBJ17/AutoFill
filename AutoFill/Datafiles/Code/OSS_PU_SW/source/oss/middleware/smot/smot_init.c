/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Smot initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "driver/adc/ADC_HAL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "middleware/smot/smot_fpga_reg_common.h"
#include "memory/memory_address_public.h"
#include "middleware/smot/smot_gpio_common.h"
#include "middleware/smot/smot_public.h"
#include "middleware/smot/smot_private.h"
#include "middleware/smot/smot_write_public.h"
#include "conf/oss_conf_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* smot PBIT fault word */
tu_smot_init_fault_word smot_pbit;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ------ --- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-SMOT-0030 */
/* Implements REQ_FADEX_OS_SRD-SMOT-0040 */
/* Smot initialization function */
void smot_init(void)
{
   /* smot position phases state value */
   uint32_t smot_position;

   /* Retrieve configuration data */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

   /* Assign the defined adress memory to the smot phase 1 state feedback  */
   smot_ph_1 = GPIO_20;

   /* Assign the defined adress memory to the smot phase 2 state feedback  */
   smot_ph_2 = GPIO_21;

   /* Assign the defined adress memory to the smot phase 3 state feedback  */
   smot_ph_3 = GPIO_59;

   /* Assign the defined adress memory to the smot phase 4 state feedback */
   smot_ph_4 = GPIO_77;

   /* Assign the defined adress to the FPGA smot register */
   smot_fpga_reg = SMOT_FPGA_MEMORY_ADDR;

   /***************** FOR TEST IN T32 **********************/
   /* smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint32_t)6; */
   /***************** FOR TEST IN T32 **********************/

   /* Smot speed time : TEMPORARY SOLUTION TO AVOID E0002 ERROR (ON T32) WHEN THE SMOT CRITICAL SERVICE IS CALLED */
   smot_speed_time = (1./(pt_oss_conf->s_sm_speed));

   /* Initialize the smot previous increment number command */
   smot_previous_incr_cmd = SMOT_PREV_CMD_INIT;

   /* Initialize the smot previous common phase state index */
   smot_ph_prev_state_idx = SMOT_PH_PREV_STATE_INIT;

   /* Store the smot phases state value */
   smot_position = (*smot_ph_4 * 8) + (*smot_ph_3 * 4) + (*smot_ph_2 * 2) + (*smot_ph_1 * 1);

   /* Set the configured smot speed time to the FPGA */
   smot_fpga_reg->s_smot_conf_reg.u_bit.s_tech = (uint32_t)((smot_speed_time - 0.001)/0.000001005);

   /* If the smot position is not equal to the expected state at initialization */
   if ((uint32_t)1 != smot_position)
   {
      /* Indicate the smot position at initialization is not at the expected default value */
      smot_pbit.u_bit.s_position_invalid_1 = (uint32_t)1;

      /* If the smot phases 1 and 4 are commanded at the initialization */
      if ((uint32_t)9 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)1;
      }

      /* If the smot phase 4 is commanded at the initialization */
      if ((uint32_t)8 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)2;
      }

      /* If the smot phases 3 and 4 are commanded at the initialization */
      if ((uint32_t)12 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)3;
      }

      /* If the smot phases 3 is commanded at the initialization */
      if ((uint32_t)4 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)4;
      }

      /* If the smot phases 2 and 3 are commanded at the initialization */
      if ((uint32_t)6 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)5;
      }

      /* If the smot phase 2 is commanded at the initialization */
      if ((uint32_t)2 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)6;
      }

      /* If the smot phases 1 and 2 are commanded at the initialization */
      if ((uint32_t)3 == smot_position)
      {
         /* Move the smot position to the default state = phase 1 is commanded */
         smot_fpga_reg->s_smot_cmd_reg.u_bit.s_inc_cmd = (uint8_t)7;
      }

      /* Store the smot phases state after the OSS_PU cmd */
      smot_position = (*smot_ph_4 * 8) + (*smot_ph_3 * 4) + (*smot_ph_2 * 2) + (*smot_ph_1 * 1);

      /* If the smot position is not equal to its expected default state after the OSS_PU command */
      if ((uint32_t)1 != smot_position)
      {
         /* Indicate the smot position is not equal to the expected state after the OSS_PU command  */
         smot_pbit.u_bit.s_position_invalid_2 = (uint32_t)1;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
