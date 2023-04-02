/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_AD7327_HAL_COMMON_H
#define ADC_AD7327_HAL_COMMON_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */

#define ADC_AD7327_HAL_INIT_WORD_NB         2

#define ADC_AD7327_HAL_CMD_WRITE            0x8000

#define ADC_AD7327_HAL_LINE_0               0x0000
#define ADC_AD7327_HAL_LINE_1               0x0400
#define ADC_AD7327_HAL_LINE_2               0x0800
#define ADC_AD7327_HAL_LINE_3               0x0C00
#define ADC_AD7327_HAL_LINE_4               0x1000
#define ADC_AD7327_HAL_LINE_5               0x1400
#define ADC_AD7327_HAL_LINE_6               0x1800
#define ADC_AD7327_HAL_LINE_7               0x1C00

#define ADC_AD7327_HAL_MODE_8_SINGLE_ENDED  0x0000
#define ADC_AD7327_HAL_MODE_4_PSEUDO_DIFF   0x0100
#define ADC_AD7327_HAL_MODE_4_FULLY_DIF     0x0200
#define ADC_AD7327_HAL_MODE_7_PSEUDO_DIF    0x0300

#define ADC_AD7327_HAL_CODING_2COMP         0x0000
#define ADC_AD7327_HAL_CODING_BIN           0x0020

#define ADC_AD7327_HAL_REF_EXT              0x0000
#define ADC_AD7327_HAL_REF_IN               0x0010

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void ADC_AD7327_SINGLE_READ ( const uint32_t         adc_conf_id,
                                     uint16_t *             read_data_pt,
                                     uint32_t *             read_size_pt);

/* */
extern void ADC_AD7327_SINGLE_WRITE ( const uint32_t         adc_conf_id,
                                      uint32_t *             written_size_pt);

/* */
extern void ADC_AD7327_MULTIPLE_READ ( const uint32_t         adc_conf_id,
                                       const CMN_SYSTEM_ADDR_t   buff_addr,
                                       const uint32_t         buff_size,
                                       uint32_t *      read_size_pt);

/* */
extern void ADC_AD7327_MULTIPLE_WRITE ( const uint32_t               adc_conf_id,
                                        const CMN_SYSTEM_ADDR_t   buff_addr,
                                        const uint32_t               buff_size,
                                        uint32_t *                   written_size_pt);

/* */
extern void ADC_AD7327_MULTIPLE_WRITE_FRAME ( const uint32_t         adc_conf_id,
                                              const CMN_SYSTEM_ADDR_t   buff_addr,
                                              const uint32_t         buff_size,
                                              uint32_t *             written_size_pt);

/* */
extern void ADC_AD7327_MULTIPLE_WRITE_FRAME_HOLD ( const uint32_t         adc_conf_id,
                                                   const CMN_SYSTEM_ADDR_t   buff_addr,
                                                   const uint32_t         buff_size,
                                                   uint32_t *             written_size_pt);

/* */
extern void ADC_AD7327_MULTIPLE_WRITE_FRAME_START ( const uint32_t adc_conf_id);


#endif /* ADC_AD7327_HAL_COMMON_H */
