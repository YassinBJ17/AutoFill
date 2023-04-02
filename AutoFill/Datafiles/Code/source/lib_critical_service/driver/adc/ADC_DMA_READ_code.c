/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */
#include "driver/adc/ADC_HAL_public.h"

void ADC_DMA_READ ( CMN_IOSP_ID_t       const p_adc_conf_id,
                    CMN_SYSTEM_ADDR_t   const p_buff_addr)
{
   /* Local variables declaration */
   uint32_t                      * pt_adc_read;
   uint32_t                      v_i;
   uint16_t                      * pt_buff;

   /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: cast is safe, address consistent with ptr type */
   pt_adc_read = (uint32_t * )( &(v_adc_int_buffer[p_adc_conf_id]) );

   /* >RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7>: no loss, (uint32_t*) fits on (uint16_t*) */
   pt_buff = (uint16_t * ) p_buff_addr;

   /* Operation : v_i is incremented 2 by 2 from 0 to ADC_INT_NB_MEAS*2 since pt_buff need to be filled with the
      last 16 bits of 32 bits buffer pt_adc_read. */

   /* >RELAX<SYNCHRONe_C_Code_10.2,SYNCHRONe_C_Code_10.7>: Initialisation Litteral constant : no problem of implicit cast nor loss of precision. */
   for ( v_i = 0UL; v_i < ((uint32_t)ADC_INT_NB_MEAS)*(uint32_t)(sizeof(uint16_t)) ; v_i+=2 )
   {
      /* >RELAX<SYNCHRONe_C_Code_10.7,SYNCHRONe_C_Code_11.1>: no loss, (uint32_t*) fits on (uint16_t*). */
      /* >RELAX<SYNCHRONe_C_Code_10.2>: Apply a litteral constant : no problem of implicit cast. */
      /* >RELAX<SYNCHRONe_C_Code_17.4>: operation is safe, pt_adc_read is read as a buffer. */
      pt_buff[v_i/2] = *( (uint16_t * )pt_adc_read + ( (uint16_t)v_i + (uint16_t)1) );
   }
}
