/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef TECU_PRIVATE_H
#define TECU_PRIVATE_H

/* ---------- Linker command file symbol: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "middleware/tecu/tecu_private.h"

/* ---------- provided define constants: ------------------------------------ */

#define TECU_DUMMY_LSB_BYTE               ((uint16_t) 0x00FF)
#define TECU_DUMMY_MSB_BYTE               ((uint16_t) 0xFF00)

/* ADT7310 SPI Command Byte (8 bit)                                                     *
 *    Bit 0:      0                                                                     *
 *    Bit 1:      R/W (1= Read, 0=write)                                                *
 *    Bit 2..4:   Register (A)ddress (0x0 = status; 0x1 = config, 0x2 = Temp, 0x3 = ID) *
 *    Bit 5       (C)ontinuous read (1 = reading without command byte)                  *
 *    Bit 6..7    0                                                                     */

/* Read command on status register address 0100.0000 */
#define TECU_CMD_RD_STATUS_REG            ((uint16_t) 0x4000)

/* Read command on command register address 0110.0000 */
#define TECU_CMD_RD_CONFIG_REG            ((uint16_t) 0x6000)

/* Read command on temp value address 0101.0000 */
#define TECU_CMD_RD_TEMP_REG              ((uint16_t) 0x5000)

/* Read command on id register address 0101.1000 */
#define TECU_CMD_RD_ID_REG                ((uint16_t) 0x5800)

/* Write command on configuration register address 0000.1000 */
#define TECU_CMD_WR_CONFIG_REG            ((uint16_t) 0x0800)

/* ADT7310 Configuration Register (8 bit)
 *    Bit 0       (R)esolution (0 = 13bit; 1 = 16 bit)  -> MSB
 *    Bit 1..2:   (O)peration Mode (0x0 = continuous; 0x1 = one shot; 0x2 = SPS; 0x3=shutdown)
 *    Bit 3:      INT/CT (M)ode (0 = interrupt mode, 1 = comparator mode)
 *    Bit 4:      (I)NT polarity (0 = active low)
 *    Bit 5:      (C)T polarity (0 = active low)
 *    Bit 6..7:   Tolerance against (F)aults (0x0 .. 0x3 -> 1 .. 4 faults)
 * (13 bit resolution, one shot, 4 faults) 0010.0011 */

/* (Write command to configuration register) 0000.0000 */
#define TECU_CMD_WR_13B_CONT_MODE_LSB     ((uint16_t) 0x0000)

/* Command TX for dummy push : */
#define TECU_SPI_CMD_TX_DUMMY             (TECU_DUMMY_MSB_BYTE | TECU_DUMMY_LSB_BYTE)

/* Command TX for configuration : */
#define TECU_SPI_CMD_TX_13B_CONT_CFG      (TECU_CMD_WR_CONFIG_REG | TECU_CMD_WR_13B_CONT_MODE_LSB)

/* Command TX for ID : */
#define TECU_SPI_CMD_TX_ID_ACQ            (TECU_CMD_RD_ID_REG | TECU_DUMMY_LSB_BYTE)

/* Command TX for acquisition : */
#define TECU_SPI_CMD_TX_TEMP_ACQ          (TECU_CMD_RD_TEMP_REG | TECU_DUMMY_LSB_BYTE)

/* The positive primary power supply temperature limit value */
#define RAW_TPSF_LIMIT_VAL (uint16_t)0x8000

/* The TMP116 sensor coefficient conversion to Celsius */
#define TMP116_CONV_TO_CELSIUS (float32_t)0.0078125

/* The TMP116 sensor conversion offset */
#define TMP116_CONV_OFFSET (float32_t)512

/* ---------- provided types: ----------------------------------------------- */
/* Bits field of the TECU erroneous value indicators */
typedef struct
{
   uint32_t spare_31_to_7 : 25;    /* 31 to 07 : Spare */
   uint32_t tcu1_err      :  1;    /* 06 : Control unit temperature erroneous value indication */
   uint32_t tcu2_err      :  1;    /* 05 : Control processing core die temperature erroneous value indication */
   uint32_t taccom_err    :  1;    /* 04 : Accomodation temperature erroneous value indication */
   uint32_t tcj_err       :  1;    /* 03 : Cold junction temperature erroneous value indication */
   uint32_t tpsf_err      :  1;    /* 02 : Primary supply function temperature erroneous value indication */
   uint32_t tols_err      :  1;    /* 01 : Overspeed low side temperature erroneous value indication */
   uint32_t tohs_err      :  1;    /* 00 : overspeed high side temperature erroneous value indication */

}ts_tecu_err_indic_bit_type;

/* TECU erroneous value indicators */
typedef union
{
   uint32_t u_word;                      /* TECU erroneous indicators accessed by 32-bit word */
   ts_tecu_err_indic_bit_type u_bit;     /* TECU erroneous indicators accessed field by field */

}tu_tecu_err_indic_type;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* The completion of the accomodation temperature filtering computation indication */
extern boolean_t taccom_filt;

/* The completion of the control unit temperature filtering computation indication */
extern boolean_t tcu1_filt;

/* The completion of the control processing core die temperature filtering computation indication */
extern boolean_t tcu2_filt;

/* The completion of the primary supply function temperature filtering computation indication */
extern boolean_t tpsf_filt;

/* The completion of the cold junction temperature filtering computation indication */
extern boolean_t tcj_filt;

/* The completion of the overspeed high side temperature filtering computation indication */
extern boolean_t tohs_filt;

/* The completion of the overspeed low side temperature filtering computation indication */
extern boolean_t tols_filt;

/* TECU temperatures erroneous value indication */
extern tu_tecu_err_indic_type tecu_err_indic;

/* Raw temperature value retrieved from the ADT7310 temperature register (tcu1) */
extern uint16_t tcu1_raw_temperature;

/* The control unit temperature sensor ID (tcu1) */
extern uint16_t tcu1_sensor_id;

/* Temperature sensor output sampled by the SARADC_B (for the the control processing core die temperature) */
extern uint16_t tcu2_raw_temperature;
/* bandgap reference voltage sampled by the SARADC_B (for the the control processing core die temperature) */
extern uint16_t tcu2_vbg_data;

/* Raw value retrieved from the sensor (TMP116) (TPSF) */
extern uint16_t tpsf_raw_temperature;

/* ---------- provided operations: ------------------------------------------ */
/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Acquisition of the control unit temperature from the ADT7310 through the SPI controller  */
extern void tecu_acq_tcu1(uint16_t* p_sensor_id); /* out */

/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Acquisition of the control corde die temperature (tcu2) through the SARADC_B (ADC INT) */
extern void tecu_acq_tcu2(void); /* out */

/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* Acquisition of the power supply function temperature from the TMP116  */
extern void tecu_acq_tpsf(void); /* out */

/* Implements REQ_FADEX_OS_SRD-TECU_0001 */
/* TECU inconsistency check between the acquired temperature and the previous acquired temperature (<25% difference) */
extern void tecu_inconsistency_check(const float32_t p_prev_temp,           /* in  */
                                     const float32_t p_temp,                /* in  */
                                     uint32_t p_err,                        /* in  */
                                     boolean_t* p_inconsistency_flag);      /* out */

/* Implements REQ_FADEX_OS_SRD-TECU1_0001 */
/* Conversion of the data acquired from the ADT7310 to Celsius */
extern void tecu_convert_data_to_celsius(uint16_t* p_sensor_raw_temp,     /* in  */
                                         float32_t* p_converted_temp);    /* out */

#endif /* TECU_PRIVATE_H */
