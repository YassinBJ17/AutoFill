/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PSUM_GetValueV.h"

/*==== Definitions =====================================================================*/

/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

TE_LIBBSP_PSUM_Status LIBBSP_PSUM_GetValueV(const TE_LIBBSP_PSUM_Adc        v_ADC, /*IN*/
                                       const TE_LIBBSP_PSUM_AdcChannel v_ADCChannel, /*IN*/
                                       float64_t *               const v_value /*OUT*/)
{
   TE_LIBBSP_PSUM_Status v_ret;
   uint32_t v_reg;
   
   const TS_LIBBSP_PSUM_AdcConversion * pt_conv;
   *v_value = (float64_t)0.0;
   v_ret = LIBBSP_PSUM_GetValue(v_ADC, v_ADCChannel, &v_reg );
   if ( v_ret == E_LIBBSP_PSUM_SUCCEEDED )
   {
      /* calcul de la valeur en flottant */
      *v_value = LIBBSP_MATH_ConvertUInt64ToFloat64((uint64_t)v_reg) * C_PSUM_ADC_SAMPLE_LSB;
      
      /* application des scale et offset */
      pt_conv = &(C_PSUM_CONV_SCALE_OFFSET[v_ADC][v_ADCChannel]);
      *v_value = ((*v_value * pt_conv->v_scale)) + pt_conv->v_offset ;
   }
   return v_ret; /* %RELAX<SYNCHRONe_C_Code_16.12> correct value returned */
}
/*==== END =============================================================================*/
