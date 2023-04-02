/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PSUM_GetValue.h"

/*==== Definitions =====================================================================*/
/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PSUM_Status LIBBSP_PSUM_GetValue(const TE_LIBBSP_PSUM_Adc        v_ADC, /*IN*/
                                           const TE_LIBBSP_PSUM_AdcChannel v_ADCChannel, /*IN*/
                                           uint32_t *                const v_value /*OUT*/)
{
   TE_LIBBSP_PSUM_Status v_ret;
   uint32_t v_reg;
   uint32_t v_offset_adc;
   uint32_t v_offset_adc_channel;
   volatile uint32_t* pt_reg;
   uint32_t * const c_nullAddress = { 0 };
   /* verification of the initialisation and of the bounds */
   if (
      ( V_PSUMonitoring_BaseAddress != c_nullAddress ) &&
      ( v_ADC >= E_LIBBSP_PSUM_ADC_1 ) &&
      ( v_ADC < E_LIBBSP_PSUM_NB_ADC ) &&
      ( v_ADCChannel >= E_LIBBSP_PSUM_ADC_1 ) &&
      ( v_ADCChannel < E_LIBBSP_PSUM_NB_CHANNEL )
   )
   {
      v_offset_adc = C_PSUM_DRV_ADC_ADCn_DELTA[v_ADC];
      
      /* ADC Sample values are in their correct index position in last DSIS PLD CMP */
      v_offset_adc_channel = ((uint32_t)v_ADCChannel) * (uint32_t)sizeof(v_offset_adc_channel) ; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: max value of enum is 8 so we can cast to uint32 */
	  
      /*{{RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
	  /*Array indexing  and pointer conversion because explicit computation of an adress */ 
      pt_reg = (volatile uint32_t*)(((uint8_t*)V_PSUMonitoring_BaseAddress) +
         v_offset_adc +
         C_PSUM_ADC_SAMPLE + v_offset_adc_channel);
      /*}}RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
      v_reg = *pt_reg;
      
      /* application du mask  */
      v_reg = v_reg & C_PSUM_ADC_SAMPLE_MASK;
      
      v_ret = E_LIBBSP_PSUM_SUCCEEDED;
   }
   else
   {
      v_ret = E_LIBBSP_PSUM_FAILED;
      v_reg = 0ul;
   }
   
   *v_value = v_reg;
   
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct value returned */
}
/*==== END =============================================================================*/
