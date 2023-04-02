/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ADC_HAL_PUBLIC_H
#define ADC_HAL_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc/ADC_CFEX_common.h"
#include "type/common_type.h"

/* ---------- provided define constants: ------------------------------------ */

/* ---------- provided types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
extern uint32_t v_adc_int_buffer[e_CFEX_ADC_INT_ANx_NB][ADC_INT_NB_MEAS] ;

/* ---------- provided operations: ------------------------------------------ */

/* */
extern void ADC_BUFFER_READ( CMN_IOSP_ID_t      const p_adc_conf_id,
                             CMN_SYSTEM_ADDR_t  const p_buff_addr);

/* */
extern void ADC_INIT(void);

/* */
extern void ADC_STOP( CMN_IOSP_ID_t const p_adc_conf_id );

/* */
extern void ADC_START( CMN_IOSP_ID_t const p_adc_conf_id );

/* */
extern void ADC_DMA_READ ( CMN_IOSP_ID_t       const p_adc_conf_id,
                           CMN_SYSTEM_ADDR_t   const p_buff_addr);

/* */
extern void ADC_DMA_START( CMN_IOSP_ID_t const p_adc_conf_id );

#endif /* ADC_HAL_PUBLIC_H */
