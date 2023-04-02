/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef FPGA_REG_IIP08_PSF_MON_H
#define FPGA_REG_IIP08_PSF_MON_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* Union definition for register 's_uv_th_0_reg[8]' */
typedef struct
{
   uint32_t s_spare_31_to_28 :  4; /* Bits : 31:28 :                                                           */
   uint32_t s_uv_th_h[0]     : 12; /* Bits : 27:16 : Under-voltage threshold high value for the ADC channel 0. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                           */
   uint32_t s_uv_th_l[0]     : 12; /* Bits : 11:0  : Under-voltage threshold low value for the ADC channel 0.  */
}
ts_fpga_reg_iip08_psf_mon_uv_th_0_reg[8]_u_bit;

typedef union
{
   uint32_t                                       u_word;
   ts_fpga_reg_iip08_psf_mon_uv_th_0_reg[8]_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_uv_th_0_reg[8];

/* Union definition for register 's_uv_th_val0_reg' */
typedef struct
{
   uint32_t s_spare_31_to_28 :  4; /* Bits : 31:28 :                                                                          */
   uint32_t s_uv_th_h_val[0] : 12; /* Bits : 27:16 : 'Intermediate' Under-voltage threshold high value for the ADC channel 0. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                                          */
   uint32_t s_uv_th_l_val[0] : 12; /* Bits : 11:0  : 'Intermediate' Under-voltage threshold low value for the ADC channel 0.  */
   uint32_t s_uv_th_h_val[7] : 12; /* Bits : 27:16 : 'Intermediate' Under-voltage threshold high value for the ADC channel 7. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                                          */
   uint32_t s_uv_th_l_val[7] : 12; /* Bits : 11:0  : 'Intermediate' Under-voltage threshold low value for the ADC channel 7.  */
}
ts_fpga_reg_iip08_psf_mon_uv_th_val0_reg_u_bit;

typedef union
{
   uint32_t                                       u_word;
   ts_fpga_reg_iip08_psf_mon_uv_th_val0_reg_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_uv_th_val0_reg;

/* Union definition for register 's_ov_th_0_reg' */
typedef struct
{
   uint32_t s_spare_31_to_28 :  4; /* Bits : 31:28 :                                                          */
   uint32_t s_ov_th_h[0]     : 12; /* Bits : 27:16 : Over-voltage threshold high value for the ADC channel 0. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                          */
   uint32_t s_ov_th_l[0]     : 12; /* Bits : 11:0  : Over-voltage threshold low value for the ADC channel 0.  */
   uint32_t s_ov_th_h[7]     : 12; /* Bits : 27:16 : Over-voltage threshold high value for the ADC channel 7. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                          */
   uint32_t s_ov_th_l[7]     : 12; /* Bits : 11:0  : Over-voltage threshold low value for the ADC channel 7.  */
}
ts_fpga_reg_iip08_psf_mon_ov_th_0_reg_u_bit;

typedef union
{
   uint32_t                                    u_word;
   ts_fpga_reg_iip08_psf_mon_ov_th_0_reg_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_ov_th_0_reg;

/* Union definition for register 's_uv_th_0_reg' */
typedef struct
{
   uint32_t s_spare_31_to_28 :  4; /* Bits : 31:28 :                                                           */
   uint32_t s_uv_th_h[0]     : 12; /* Bits : 27:16 : Under-voltage threshold high value for the ADC channel 0. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                           */
   uint32_t s_uv_th_l[0]     : 12; /* Bits : 11:0  : Under-voltage threshold low value for the ADC channel 0.  */
   uint32_t s_uv_th_h[7]     : 12; /* Bits : 27:16 : Under-voltage threshold high value for the ADC channel 7. */
   uint32_t s_spare_15_to_12 :  4; /* Bits : 15:12 :                                                           */
   uint32_t s_uv_th_l[7]     : 12; /* Bits : 11:0  : Under-voltage threshold low value for the ADC channel 7.  */
}
ts_fpga_reg_iip08_psf_mon_uv_th_0_reg_u_bit;

typedef union
{
   uint32_t                                    u_word;
   ts_fpga_reg_iip08_psf_mon_uv_th_0_reg_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_uv_th_0_reg;

/* Group of registers in 'iip08_psf_mon' named 'configuration_values' */
typedef struct
{
   tu_fpga_reg_iip08_psf_mon_uv_th_0_reg[8] s_uv_th_0_reg[8];
   tu_fpga_reg_iip08_psf_mon_uv_th_val0_reg s_uv_th_val0_reg;
   tu_fpga_reg_iip08_psf_mon_ov_th_0_reg    s_ov_th_0_reg;
   tu_fpga_reg_iip08_psf_mon_uv_th_0_reg    s_uv_th_0_reg;
   uint32_t                                 s_update_key1_reg;
   uint32_t                                 s_update_key2_reg;
   uint32_t                                 s_update_dflt_key1_reg;
   uint32_t                                 s_update_dflt_key2_reg;
}
ts_fpga_reg_iip08_psf_mon_configuration_values;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_sts_reg' */
typedef struct
{
   uint32_t s_spare_31_to_24 : 8; /* Bits : 31:24 :                                                                                                                                     */
   uint32_t s_ov_sts         : 8; /* Bits : 23:16 : Over-voltage statusov_sts[$]:'1': an over-voltage is detected on vin[$]'0': no over-voltage is detected on vin[$]with $ = 0 to 7    */
   uint32_t s_spare_15_to_8  : 8; /* Bits : 15:8  :                                                                                                                                     */
   uint32_t s_uv_sts         : 8; /* Bits : 7:0   : Under-voltage statusuv_sts[$]:'1': an under-voltage is detected on vin[$]'0': no under-voltage is detected on vin[$]with $ = 0 to 7 */
}
ts_fpga_reg_iip08_psf_mon_sts_reg_u_bit;

typedef union
{
   uint32_t                                u_word;
   ts_fpga_reg_iip08_psf_mon_sts_reg_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_sts_reg;

/* Union definition for register 's_out_en_reg' */
typedef struct
{
   uint32_t s_ov_en_val : 8; /* Bits : 31:24 : 'Intermediate' Over-voltage enable                                                                                                               */
   uint32_t s_ov_en     : 8; /* Bits : 23:16 : Over-voltage enableov_en[$]:'1': over-voltage detection is enabled on vin[$] '0': over-voltage detection is disabled on vin[$]with $ = 0 to 7    */
   uint32_t s_uv_en_val : 8; /* Bits : 15:8  : 'Intermediate' Under-voltage enable                                                                                                              */
   uint32_t s_uv_en     : 8; /* Bits : 7:0   : Under-voltage enableuv_en[$]:'1': under-voltage detection is enabled on vin[$] '0': under-voltage detection is disabled on vin[$]with $ = 0 to 7 */
}
ts_fpga_reg_iip08_psf_mon_out_en_reg_u_bit;

typedef union
{
   uint32_t                                   u_word;
   ts_fpga_reg_iip08_psf_mon_out_en_reg_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_out_en_reg;

/* Group of registers in 'iip08_psf_mon' named 'status___enable' */
typedef struct
{
   tu_fpga_reg_iip08_psf_mon_sts_reg    s_sts_reg;
   tu_fpga_reg_iip08_psf_mon_out_en_reg s_out_en_reg;
}
ts_fpga_reg_iip08_psf_mon_status___enable;

/* ------------------------------------------------------------------------------- */

/* Union definition for register 's_vin_0_reg[8]' */
typedef struct
{
   uint32_t s_spare_31_to_13 : 19; /* Bits : 31:13 :                                                                                                                     */
   uint32_t s_vin_refresh[0] :  1; /* Bits : 12    : Refresh indicator for the ADC channel 0:'1': {vin}[0] is refreshed with a new value.'0': {vin}[0] is not refreshed. */
   uint32_t s_vin[0]         : 12; /* Bits : 11:0  : Voltage measurement for the ADC channel 0.                                                                          */
   uint32_t s_vin_refresh[7] :  1; /* Bits : 12    : Refresh indicator for the ADC channel 7:'1': {vin}[7] is refreshed with a new value.'0': {vin}[7] is not refreshed. */
   uint32_t s_vin[7]         : 12; /* Bits : 11:0  : Voltage measurement for the ADC channel 7.                                                                          */
}
ts_fpga_reg_iip08_psf_mon_vin_0_reg[8]_u_bit;

typedef union
{
   uint32_t                                     u_word;
   ts_fpga_reg_iip08_psf_mon_vin_0_reg[8]_u_bit u_bit;
}
tu_fpga_reg_iip08_psf_mon_vin_0_reg[8];

/* Group of registers in 'iip08_psf_mon' named 'voltage_measurement' */
typedef struct
{
   tu_fpga_reg_iip08_psf_mon_vin_0_reg[8] s_vin_0_reg[8];
}
ts_fpga_reg_iip08_psf_mon_voltage_measurement;

/* ------------------------------------------------------------------------------- */

/* General definition of registers in 'iip08_psf_mon' */

typedef struct
{
   ts_fpga_reg_iip08_psf_mon_configuration_values s_configuration_values_regs;
   ts_fpga_reg_iip08_psf_mon_status___enable      s_status___enable_regs;
   ts_fpga_reg_iip08_psf_mon_voltage_measurement  s_voltage_measurement_regs;
}
ts_fpga_reg_iip08_psf_mon;

#endif /* FPGA_REG_IIP08_PSF_MON_H */
