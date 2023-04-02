/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : VRT Initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/vrt/vrt_public.h"
#include "middleware/vrt/vrt_private.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
/* Address register */
#define SIUL2_GPDO_64_ADDR     ((uint8_t *)0xFFFC1340)     /* VRT_T1_PT100_PT1000_N */
#define SIUL2_GPDO_68_ADDR     ((uint8_t *)0xFFFC1344)     /* VRT_T2_PT100_PT1000_N */
#define SIUL2_GPDO_75_ADDR     ((uint8_t *)0xFFFC134B)     /* VRT_TFF_PT100_PT1000_N */


/* Configuration value */
#define SIUL2_CONF_PT1000      (uint8_t)0x0      /* VRT_Tx_PT1000_N */
#define SIUL2_CONF_PT100       (uint8_t)0x1      /* VRT_Tx_PT100_N */




/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-VRT-0020 */
/* Implements REQ_FADEX_OS_SRD-VRT-0030 */
/* VRT initialization function */
void vrt_init(const boolean_t channel_is_a)
{

   /* Retrieve configuration data */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;


   /**** Initialization of the VRTx thermal temperature ****/

   /* Key registers address settings  */
   uint8_t * siul2_gpdo_64_reg = SIUL2_GPDO_64_ADDR;
   uint8_t * siul2_gpdo_68_reg = SIUL2_GPDO_68_ADDR;
   uint8_t * siul2_gpdo_75_reg = SIUL2_GPDO_75_ADDR;

   gnd_voltage_avg_min = GND_AVG_MIN;
   gnd_voltage_avg_max = GND_AVG_MAX;

   /* If we are on the channel A */
   if(channel_is_a)
   {
      float32_t vrt2_pib_gain = VRT2A_PIB_GAIN;        /* VRT2 PIB gain compensation for channel A */
      float32_t vrtff_pib_gain = VRTFFA_PIB_GAIN;      /* VRTFF PIB gain compensation for channel A */
   }
   /* Else channel B */
   else
   {
      float32_t vrt2_pib_gain = VRT2B_PIB_GAIN;        /* VRT2 PIB gain compensation for channel B */
      float32_t vrtff_pib_gain = VRTFFB_PIB_GAIN;      /* VRTFF PIB gain compensation for channel B */

   }

   /* If PT1000 configuration for VRT1 */
   if((uint32_t)1 == pt_oss_conf->s_t1_configuration)
   {
      vrt1_cal_volt_min = PT1000_VRT1_CAL_VOLT_MIN;
      vrt1_cal_volt_max = PT1000_VRT1_CAL_VOLT_MAX;
      vrt1_shunt_cal_current_min = PT1000_VRT1_SHUNT_CAL_CURR_MIN;
      vrt1_shunt_cal_current_max = PT1000_VRT1_SHUNT_CAL_CURR_MAX;
      vrt1_cal_resistor_min = VRT1_PT1000_RESISTOR_MIN_EXPECTED;
      vrt1_cal_resistor_max = VRT1_PT1000_RESISTOR_MAX_EXPECTED;

      /* Set VRT1 hardware to PT1000 configuration */
      *siul2_gpdo_64_reg = SIUL2_CONF_PT1000;

   }
   /* If PT100 configuration for VRT1 */
   else
   {
      vrt1_cal_volt_min = PT100_VRT1_CAL_VOLT_MIN;
      vrt1_cal_volt_max = PT100_VRT1_CAL_VOLT_MAX;
      vrt1_shunt_cal_current_min = PT100_VRT1_SHUNT_CAL_CURR_MIN;
      vrt1_shunt_cal_current_max = PT100_VRT1_SHUNT_CAL_CURR_MAX;
      vrt1_cal_resistor_min = VRT1_PT100_RESISTOR_MIN_EXPECTED;
      vrt1_cal_resistor_max = VRT1_PT100_RESISTOR_MAX_EXPECTED;

      /* Set VRT1 hardware to PT100 configuration */
      *siul2_gpdo_64_reg = SIUL2_CONF_PT100;
   }

   /* If PT1000 configuration for VRT2 */
   if((uint32_t)1 == pt_oss_conf->s_t2_configuration)
   {
      vrt2_cal_volt_min = PT1000_VRT2_CAL_VOLT_MIN;
      vrt2_cal_volt_max = PT1000_VRT2_CAL_VOLT_MAX;
      vrt2_shunt_cal_current_min = PT1000_VRT2_SHUNT_CAL_CURR_MIN;
      vrt2_shunt_cal_current_max = PT1000_VRT2_SHUNT_CAL_CURR_MAX;
      vrt2_cal_resistor_min = VRT_PT1000_RESISTOR_MIN_EXPECTED;
      vrt2_cal_resistor_max = VRT_PT1000_RESISTOR_MAX_EXPECTED;

      /* Set VRT2 hardware to PT1000 configuration */
      *siul2_gpdo_68_reg = SIUL2_CONF_PT1000;
   }
   /* If PT100 configuration for VRT2 */
   else
   {
      vrt2_cal_volt_min = PT100_VRT2_CAL_VOLT_MIN;
      vrt2_cal_volt_max = PT100_VRT2_CAL_VOLT_MAX;
      vrt2_shunt_cal_current_min = PT100_VRT2_SHUNT_CAL_CURR_MIN;
      vrt2_shunt_cal_current_max = PT100_VRT2_SHUNT_CAL_CURR_MAX;
      vrt2_cal_resistor_min = VRT_PT100_RESISTOR_MIN_EXPECTED;
      vrt2_cal_resistor_max = VRT_PT100_RESISTOR_MAX_EXPECTED;

      /* Set VRT2 hardware to PT100 configuration */
      *siul2_gpdo_68_reg = SIUL2_CONF_PT100;
   }

   /* If PT1000 configuration for VRTFF */
   if((uint32_t)1 == pt_oss_conf->s_tff_configuration)
   {
      vrtff_cal_volt_min = PT1000_VRTFF_CAL_VOLT_MIN;
      vrtff_cal_volt_max = PT1000_VRTFF_CAL_VOLT_MAX;
      vrtff_shunt_cal_current_min = PT1000_VRTFF_SHUNT_CAL_CURR_MIN;
      vrtff_shunt_cal_current_max = PT1000_VRTFF_SHUNT_CAL_CURR_MAX;
      vrtff_cal_resistor_min = VRT_PT1000_RESISTOR_MIN_EXPECTED;
      vrtff_cal_resistor_max = VRT_PT1000_RESISTOR_MAX_EXPECTED;

      /* Set VRTFF hardware to PT1000 configuration */
      *siul2_gpdo_75_reg = SIUL2_CONF_PT1000;
   }
   /* If PT100 configuration for VRTFF */
   else
   {
      vrtff_cal_volt_min = PT100_VRTFF_CAL_VOLT_MIN;
      vrtff_cal_volt_max = PT100_VRTFF_CAL_VOLT_MAX;
      vrtff_shunt_cal_current_min = PT100_VRTFF_SHUNT_CAL_CURR_MIN;
      vrtff_shunt_cal_current_max = PT100_VRTFF_SHUNT_CAL_CURR_MAX;
      vrtff_cal_resistor_min = VRT_PT100_RESISTOR_MIN_EXPECTED;
      vrtff_cal_resistor_max = VRT_PT100_RESISTOR_MAX_EXPECTED;

      /* Set VRTFF hardware to PT100 configuration */
      *siul2_gpdo_75_reg = SIUL2_CONF_PT100;
   }

}

/* ---------- internal operations: ------------------------------------------ */
