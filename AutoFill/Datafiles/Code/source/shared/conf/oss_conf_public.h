/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef OSS_CONF_PUBLIC_H
#define OSS_CONF_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */
/* Part number of OSS_CONF: format is MMMCC-SSSS-SSSS according to ARINC 665-3. */
#define OSS_CONF_PARTNUMBER_SIZE (uint32_t) 15
/* Table of couples SDI + Label to be received by the A429_1A link., Maximum ARINC messages: 128 */
#define A429_1A_RX_SDI_LABEL_SIZE (uint32_t) 128
/* Table of couples SDI + Label to be received by the A429_2AB link., Maximum ARINC messages: 128 */
#define A429_2AB_RX_SDI_LABEL_SIZE (uint32_t) 128
/* Sixth NG Overspeed Threshold for NTL Variable Threshold */
#define NG_OVSTHRESD_THRESHOLD_AR_SIZE (uint32_t) 6
/* Sixth value to determine NTL Overspeed Threshold function of NG */
#define NTL_OVSVARIABLE_THRESHOLD_AR_SIZE (uint32_t) 6

/* nb of spare bytes */
#define SPARE01_SIZE (uint32_t) 2
#define SPARE02_SIZE (uint32_t) 13
#define SPARE03_SIZE (uint32_t) 52
#define SPARE04_SIZE (uint32_t) 6
#define SPARE05_SIZE (uint32_t) 2
#define SPARE06_SIZE (uint32_t) 2
#define SPARE07_SIZE (uint32_t) 3
#define SPARE08_SIZE (uint32_t) 2
#define SPARE09_SIZE (uint32_t) 2
#define SPARE10_SIZE (uint32_t) 38


/* ---------- provided types: ----------------------------------------------- */


/* Implements REQ_OSS_CONF_SRD-xxxx */
/* Content of the OSS CONFIGURATION TABLE */
typedef struct
{
   /* File Compatibility for SW/SW compatibility verification with OSS_PU., First byte is 0xCC, then second is modified at each compatibility change. */
   uint16_t s_oss_conf_filecompatibility;

   /* Spare data for 32-bit alignment */
   uint8_t s_spare_01[SPARE01_SIZE];

   /* Part number of OSS_CONF: format is MMMCC-SSSS-SSSS according to ARINC 665-3. */
   uint8_t s_oss_conf_partnumber[OSS_CONF_PARTNUMBER_SIZE];

   /* Spare data for 32-bit alignment and to start OSS_PU Configuration area at a rounded address */
   uint8_t s_spare_02[SPARE02_SIZE];

   /* Configuration of CSS_PU tasks to be sequenced :, 0xFADEC111 = 1_PERIODIC_TASK, 0x444FADEC = 4_PERIODIC_TASK */
   uint32_t s_css_pu_task_config;

   /* MCSS attendance :, 0 = MCCS not activated / not loaded, 1 = MCSS activated */
   uint32_t s_mcss_configuration;

   /* Start address of communication zone between CSS_PU_FAST_TASK to CSS_PU_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_css_slow_start;

   /* Destination address of communication zone between CSS_PU_FAST_TASK to CSS_PU_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_css_slow_dest;

   /* Start address of communication zone between CSS_PU_FAST_TASK to CSS_PU_VERY_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_css_vslow_start;

   /* Destination address of communication zone between CSS_PU_FAST_TASK to CSS_PU_VERY_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_css_vslow_dest;

   /* Start address of a communication zone between CSS_PU_FAST_TASK to CSS_PU_BACKGROUND_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_css_bgrnd_start;

   /* Destination address of a communication zone between CSS_PU_FAST_TASK to CSS_PU_BACKGROUND_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_css_bgrnd_dest;

   /* Start address of a communication zone between CSS_PU_FAST_TASK to MCSS_PU_PERIODIC_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_mcss_period_start;

   /* Destination address of a communication zone between CSS_PU_FAST_TASK to MCSS_PU_PERIODIC_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_fast_to_mcss_period_dest;

   /* Start address of a communication zone between CSS_PU_SLOW_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_slow_to_css_fast_start;

   /* Destination address of a communication zone between CSS_PU_SLOW_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_slow_to_css_fast_dest;

   /* Start address of a communication zone between CSS_PU_SLOW_TASK to CSS_PU_VERY_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_slow_to_css_vslow_start;

   /* Destination address of a communication zone between CSS_PU_SLOW_TASK to CSS_PU_VERY_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_slow_to_css_vslow_dest;

   /* Start address of a communication zone between CSS_PU_SLOW_TASK to CSS_PU_BACKGROUND_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_slow_to_css_bgrnd_start;

   /* Destination address of a communication zone between CSS_PU_SLOW_TASK to CSS_PU_BACKGROUND_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_slow_to_css_bgrnd_dest;

   /* Start address of a communication zone between CSS_PU_VERY_SLOW_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_vslow_to_css_fast_start;

   /* Destination address of a communication zone between CSS_PU_VERY_SLOW_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_vslow_to_css_fast_dest;

   /* Start address of a communication zone between CSS_PU_VERY_SLOW_TASK to CSS_PU_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_vslow_to_css_slow_start;

   /* Destination address of a communication zone between CSS_PU_VERY_SLOW_TASK to CSS_PU_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_vslow_to_css_slow_dest;

   /* Start address of a communication zone between CSS_PU_VERY_SLOW_TASK to CSS_PU_BACKGROUND_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_vslow_to_css_bgrnd_dest;

   /* Destination address of a communication zone between CSS_PU_VERY_SLOW_TASK to CSS_PU_BACKGROUND_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_vslow_to_css_bgrnd_start;

   /* Start address of a communication zone between CSS_PU_BACKGROUND_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_bgrnd_to_css_fast_start;

   /* Destination address of a communication zone between CSS_PU_BACKGROUND_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_bgrnd_to_css_fast_dest;

   /* Start address of a communication zone between CSS_PU_BACKGROUND_TASK to CSS_PU_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_bgrnd_to_css_slow_start;

   /* Destination address of a communication zone between CSS_PU_BACKGROUND_TASK to CSS_PU_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_bgrnd_to_css_slow_dest;

   /* Start address of a communication zone between CSS_PU_BACKGROUND_TASK to CSS_PU_VERY_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_bgrnd_to_css_vslow_start;

   /* Destination address of a communication zone between CSS_PU_BACKGROUND_TASK to CSS_PU_VERY_SLOW_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_css_bgrnd_to_css_vslow_dest;

   /* Start address of a communication zone between MCSS_PU_PERIODIC_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_mcss_period_to_css_fast_start;

   /* Destination address of a communication zone between MCSS_PU_PERIODIC_TASK to CSS_PU_FAST_TASK, 0xFFFFFFFF value is used when communication is not used */
   uint32_t s_mcss_period_to_css_fast_dest;

   /* Number of Authorized CPU reset in case of Fatal anomaly */
   uint32_t s_definitive_reset_threshold;

   /* Number of occurrences to reach before sending Trigger Log. */
   uint32_t s_shortoccurrencetrigger;

   /* XRB inputs or CALRES inputs sensor, 0 = Sensor CALRES inputs, 1 = Sensor XRB inputs */
   uint32_t s_xrb_calres_select;

   /* Type of LVDTA Sensor, 0 = Sensor LVDT type 1, 1 = Sensor LVDT type 2 */
   uint32_t s_lvdta_sensor_type;

   /* Frequency of LVDTA Sensor excitation, 0 = 2500 Hz, 1 = 2900 Hz */
   uint32_t s_lvdta_exc_freq;

   /* Type of LVDTB Sensor, 0 = Sensor LVDT type 1, 1 = Sensor LVDT type 2 */
   uint32_t s_lvdtb_sensor_type;

   /* Frequency of LVDTB Sensor excitation, 0 = 2500 Hz, 1 = 2900 Hz */
   uint32_t s_lvdtb_exc_freq;

   /* Type of LVDTC Sensor, 0 = Sensor LVDT type 1, 1 = Sensor LVDT type 2 */
   uint32_t s_lvdtc_sensor_type;

   /* Frequency of LVDTC Sensor excitation, 0 = 2500 Hz, 1 = 2900 Hz */
   uint32_t s_lvdtc_exc_freq;

   /* Maximum number of periods for NGALT measurement */
   uint32_t s_ngalt_nmax;

   /* Minimum number of periods for NGALT measurement */
   uint32_t s_ngalt_nmin;

   /* Number of revolution periods for NGALT measurement */
   uint32_t s_ngalt_nrev;

   /* Inconsistency 1 threshold selection for NGALT measurement */
   uint32_t s_ngalt_inc_1_th_sel;

   /* Maximum frequency for NGALT measurement */
   float32_t s_ngalt_th_frequency;

   /* Time-out for NGALT measurement, defined in multiple of RTC. */
   uint32_t s_ngalt_timeout;

   /* Maximum number of periods for NFREQ2 measurement */
   uint32_t s_nfreq2_nmax;

   /* Minimum number of periods for NFREQ2 measurement */
   uint32_t s_nfreq2_nmin;

   /* Number of revolution periods for NFREQ2 measurement */
   uint32_t s_nfreq2_nrev;

   /* Inconsistency 1 threshold selection for NFREQ2 measurement */
   uint32_t s_nfreq2_inc_1_th_sel;

   /* Maximum frequency for NFREQ2 measurement */
   float32_t s_nfreq2_th_frequency;

   /* Time-out for NFREQ2 measurement, defined in multiple of RTC. */
   uint32_t s_nfreq2_timeout;

   /* Maximum number of periods for NFREQ4 measurement */
   uint32_t s_nfreq4_nmax;

   /* Minimum number of periods for NFREQ4 measurement */
   uint32_t s_nfreq4_nmin;

   /* Number of revolution periods for NFREQ4 measurement */
   uint32_t s_nfreq4_nrev;

   /* Inconsistency 1 threshold selection for NFREQ4 measurement */
   uint32_t s_nfreq4_inc_1_th_sel;

   /* Maximum frequency for NFREQ4 measurement */
   float32_t s_nfreq4_th_frequency;

   /* Time-out for NFREQ4 measurement, defined in multiple of RTC. */
   uint32_t s_nfreq4_timeout;

   /* Number of periods for NFREQ3 measurement */
   uint32_t s_nfreq3_nrev;

   /* Inconsistency 2 threshold selection for NFREQ3 measurement */
   uint32_t s_nfreq3_inc_2_th_sel;

   /* Maximum frequency for NFREQ3 measurement */
   float32_t s_nfreq3_th_frequency;

   /* Time-out for NFREQ3 measurement, defined in multiple of RTC. */
   uint32_t s_nfreq3_timeout;

   /* Maximum Ratio for NFREQ3 */
   uint32_t s_nfreq3_ratio;

   /* Number of cycles for the filtering of DIN1 to DIN 16 */
   uint32_t s_din_n_filter;

   /* Number of cycles for the filtering of the SVOI */
   uint32_t s_svoi_n_filter;

   /* Number of cycles for the filtering of the EMAN */
   uint32_t s_eman_n_filter;

   /* Frequency of Stepper Motor */
   uint32_t s_sm_speed;

   /* Configuration of command of Torque Mortor when system is in state "Control is frozen", 0 = command of TM is deactivated for the 2 channels, 1 = command of TM is activated only for active channel */
   uint32_t s_tm_freeze_conf;

   /* Speed of RS422_A link, 0 = 9600 baud, 1 = 19200 baud, 2 = 115 200 baud, 3 = 460 800 baud, 4 = 921 600 baud, 5 = 1 000 000 baud */
   uint32_t s_rs422a_baud;

   /* Bit parity setting of RS422_A link :, 0 = No parity, 1 = Odd parity , 2 = Even parity */
   uint32_t s_rs422a_parity_bit;

   /* Bit stop setting of RS422_A link :, 0 = 1 stop bit, 1 = 2 stop bits */
   uint32_t s_rs422a_stop_bit;

   /* Speed of RS422_B link, 0 = 9600 baud, 1 = 19200 baud, 2 = 115 200 baud, 3 = 460 800 baud, 4 = 921 600 baud, 5 = 1 000 000 baud */
   uint32_t s_rs422b_baud;

   /* Bit parity setting of RS422_B link :, 0 = No parity, 1 = Odd parity, 2 = Even parity */
   uint32_t s_rs422b_parity_bit;

   /* Bit stop setting of RS422_B link :, 0 = 1 stop bit, 1 = 2 stop bits */
   uint32_t s_rs422b_stop_bit;

   /* Speed for A429_1A data link, 0 = 12.5 kHz, 1 = 100 kHz */
   uint32_t s_a429_1a_baud;

   /* Table of couples SDI + Label to be received by the A429_1A link., Maximum ARINC messages: 128 */
   uint16_t s_a429_1a_rx_sdi_label[A429_1A_RX_SDI_LABEL_SIZE];

   /* TX activation on ARINC during IBIT (loopback test):, 0 = Not enabled, 1 = Enabled */
   uint32_t s_a429_ibit_tx_enable;

   /* Speed for A429_2AB data link, 0 = 12.5 kHz, 1 = 100 kHz */
   uint32_t s_a429_2ab_baud;

   /* Table of couples SDI + Label to be received by the A429_2AB link., Maximum ARINC messages: 128 */
   uint16_t s_a429_2ab_rx_sdi_label[A429_2AB_RX_SDI_LABEL_SIZE];

   /* A429_2AB transmit data link is controlled by:, 0 = Channel A, 1 = Channel B, 2 = Channel in control */
   uint32_t s_a429_2ab_config;

   /* Standard to use for CAN1 according to ISO 11898 :, 0 = CAN 2.0A (11 bits identifiers), 1 = CAN 2.0B (29 bits identifiers) */
   uint32_t s_can1_02b_authorized;

   /* Presence of the 120 Ohms adaptation series resistor in the calculator for CAN1:, 0 = False (Resistance connected), 1 = True (Resistance disconnected) */
   uint32_t s_can1_adapt_presence;

   /* CAN1 link speed :, 0 = 125 kbit/s, 1 = 250 kbit/s, 2 = 500 kbit/s, 3 = 1000 kbit/s */
   uint32_t s_can1_baud;

   /* Standard to use for CAN2 according to ISO 11898 :, 0 = CAN 2.0A (11 bits identifiers), 1 = CAN 2.0B (29 bits identifiers) */
   uint32_t s_can2_02b_authorized;

   /* CAN2 link speed :, 0 = 125 kbit/s, 1 = 250 kbit/s, 2 = 500 kbit/s, 3 = 1000 kbit/s */
   uint32_t s_can2_baud;

   /* T1 configuration, 0 = PT100 configuration, 1 = PT1000 configuration */
   uint32_t s_t1_configuration;

   /* T2 configuration, 0 = PT100 configuration, 1 = PT1000 configuration */
   uint32_t s_t2_configuration;

   /* TFF configuration, 0 = PT100 configuration, 1 = PT1000 configuration */
   uint32_t s_tff_configuration;

   /* SAI1 selection, 0 = Strain Gauge Bridge Input 1, 1 = Standardized Analog Input 1 */
   uint32_t s_sai1_select;

   /* SAI2 selection, 0 = Strain Gauge Bridge Input 1, 1 = Standardized Analog Input 1 */
   uint32_t s_sai2_select;

   /* SAI3 selection, 0 = Strain Gauge Bridge Input 1, 1 = Standardized Analog Input 1 */
   uint32_t s_sai3_select;

   /* SAI4 selection, 0 = Strain Gauge Bridge Input 1, 1 = Standardized Analog Input 1 */
   uint32_t s_sai4_select;

   /* POT1 sensor type :, 0 = Potentiometer type, 1 = Differential type */
   uint32_t s_pot1_sensor_type;

   /* POT2 sensor type :, 0 = Potentiometer type, 1 = Differential type */
   uint32_t s_pot2_sensor_type;

   /* Thermal wear counter parameter A */
   float32_t s_twear_a;

   /* Thermal wear counter parameter B */
   float32_t s_twear_b;

   /* Spare data with respect of 32-bit alignment */
   uint8_t s_spare_03[SPARE03_SIZE];

   /* NGOS1 / NGALT ratio for NGALTA */
   float32_t s_ovs_ngos1ngaltaratio;

   /* NGOS2 / NGALT ratio for NGALTA */
   float32_t s_ovs_ngos2ngaltaratio;

   /* NGOS1 / NGALT ratio for NGALTB */
   float32_t s_ovs_ngos1ngaltbratio;

   /* NGOS2 / NGALT ratio for NGALTB */
   float32_t s_ovs_ngos2ngaltbratio;

   /* NTLOS1 / NFREQ2 ratio for NTLA */
   float32_t s_ovs_ntlos1ntlaratio;

   /* NTLOS2 / NFREQ2 ratio for NTLA */
   float32_t s_ovs_ntlos2ntlaratio;

   /* NTLOS1 / NFREQ2 ratio for NTLB */
   float32_t s_ovs_ntlos1ntlbratio;

   /* NTLOS2 / NFREQ2 ratio for NTLB */
   float32_t s_ovs_ntlos2ntlbratio;

   /* Identification of NTL sensor on channel A, 0 = FREQ1A, 1 = FREQ2A */
   uint8_t s_ovs_ntla_ident;

   /* Identification of NTL sensor on channel B, 0 = FREQ1B, 1 = FREQ2B */
   uint8_t s_ovs_ntlb_ident;

   /* Spare data to split memory area, for 32-bit alignment and to start OVSP Configuration area at a rounded address */
   uint8_t s_spare_04[SPARE04_SIZE];

   /* Inhibition of the NTL Overspeed Threshold detection logic, 0 = Not_Inhibited, 1 = Inhibited */
   uint8_t s_ovs_ntlthresholdinhib;

   /* Inhibition of the NG Overspeed detection logic, 0 = Not_Inhibited, 1 = Inhibited */
   uint8_t s_ovs_nginhib;

   /* Inhibition of the CSS_PU Overspeed detection logic, 0 = Not_Inhibited, 1 = Inhibited */
   uint8_t s_ovs_cssinhib;

   /* Inhibition of the capacity to operate of the overspeed protection function with only one NG sensor available, 0 = Not_Inhibited, 1 = Inhibited */
   uint8_t s_ovs_onesensornginhib;

   /* Inhibition of the capacity to operate of the overspeed protection function with only one NTL sensor available, 0 = Not_Inhibited, 1 = Inhibited */
   uint8_t s_ovs_onesensorntlinhib;

   /* Inhibition of the activation of DOUTINHIB output (Only for NG Overspeed detection), 0 = Not_Inhibited, 1 = Inhibited */
   uint8_t s_interlock_inhib;

   /* Spare data for 32-bit alignment */
   uint8_t s_spare_05[SPARE05_SIZE];

   /* Number of periods for NTLOS1 Low Side channel measurement */
   uint8_t s_ntlos1_nl;

   /* Number of periods for NTLOS1 High Side channel measurement */
   uint8_t s_ntlos1_nh;

   /* Number of periods for NTLOS2 Low Side channel measurement */
   uint8_t s_ntlos2_nl;

   /* Number of periods for NTLOS2 High Side channel measurement */
   uint8_t s_ntlos2_nh;

   /* Number of confirmations for the NTL overspeed threshold detection logic */
   uint8_t s_ntl_ovsthresd_n;

   /* NTL overspeed threshold configuration, 1 = fixed parameter, 2 = variable parameter function of NG overspeed measures */
   uint8_t s_ntl_ovs_function;

   /* Spare data for 32-bit alignment */
   uint8_t s_spare_06[SPARE06_SIZE];

   /* Number of periods for NGOS1 Low Side channel measurement */
   uint8_t s_ngos1_nl;

   /* Number of periods for NGOS1 High Side channel measurement */
   uint8_t s_ngos1_nh;

   /* Number of periods for NGOS2 Low Side channel measurement */
   uint8_t s_ngos2_nl;

   /* Number of periods for NGOS2 High Side channel measurement */
   uint8_t s_ngos2_nh;

   /* Number of confirmations for the NG overspeed threshold detection logic */
   uint8_t s_ng_ovsthresd_n;

   /* Spare data for 32-bit alignment */
   uint8_t s_spare_07[SPARE07_SIZE];

   /* Sixth NG Overspeed Threshold for NTL Variable Threshold */
   uint8_t s_ng_ovsthresd_threshold_ar[NG_OVSTHRESD_THRESHOLD_AR_SIZE];

   /* Spare data for 32-bit alignment */
   uint8_t s_spare_08[SPARE08_SIZE];

   /* Sixth value to determine NTL Overspeed Threshold function of NG */
   uint8_t s_ntl_ovsvariable_threshold_ar[NTL_OVSVARIABLE_THRESHOLD_AR_SIZE];

   /* Spare data for 32-bit alignment */
   uint8_t s_spare_09[SPARE09_SIZE];

   /* Time-out for NGOS1 measurement */
   float32_t s_ngos1_timeout;

   /* NGOS1 frequency corresponding to 100 % NG rotation speed */
   float32_t s_ngos1_100;

   /* Time-out for NGOS2 measurement */
   float32_t s_ngos2_timeout;

   /* NGOS2 frequency corresponding to 100 % NG rotation speed */
   float32_t s_ngos2_100;

   /* Time-out for NTLOS1 measurement */
   float32_t s_ntlos1_timeout;

   /* NTLOS1 frequency corresponding to 100 % NTL rotation speed */
   float32_t s_ntlos1_100;

   /* Time-out for NTLOS2 measurement */
   float32_t s_ntlos2_timeout;

   /* NTLOS2 frequency corresponding to 100 % NTL rotation speed */
   float32_t s_ntlos2_100;

   /* NTL overspeed threshold */
   float32_t s_ntl_ovsthresd_threshold;

   /* NTL overspeed confirmation window */
   float32_t s_ntl_ovsthresd_window;

   /* NG overspeed threshold */
   float32_t s_ng_ovsthresd_threshold;

   /* NG overspeed confirmation window */
   float32_t s_ng_ovsthresd_window;

   /* Spare data is used to make the OVSP Configuration area size equal to 128 Bytes */
   uint8_t s_spare_10[SPARE10_SIZE];

   /* 16-bit CRC of OVSP Configuration section. */
   uint16_t s_ovsp_config_16bitcrc;

   /* 32-bit CRC of whole OSS_CONF file. */
   uint32_t s_oss_conf_32bitcrc;
}
ts_oss_conf_table;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* OSS_CONF_PUBLIC_H */
