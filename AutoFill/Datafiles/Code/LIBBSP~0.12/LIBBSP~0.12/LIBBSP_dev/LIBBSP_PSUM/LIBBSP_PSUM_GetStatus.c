/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PSUM_GetStatus.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/

/*==== Services ========================================================================*/

void LIBBSP_PSUM_GetStatus(const TE_LIBBSP_PSUM_Adc             v_ADC, /*IN*/
                           TS_LIBBSP_PSUM_AdcErrorFlags * const p_ADCErrorFlags,
                           uint16_t *                     const v_RegValue,
                           TE_LIBBSP_PSUM_Status *        const v_ret)
{
   uint32_t v_offset_adc;
   uint32_t v_buffGetSta;
   volatile uint32_t* pt_reg;
   uint32_t * const c_nullAddress = { 0 };
   
   if (
      ( V_PSUMonitoring_BaseAddress != c_nullAddress )
      && ( v_ADC < E_LIBBSP_PSUM_NB_ADC )
      && ( v_ADC >= E_LIBBSP_PSUM_ADC_1 )
     )
   {
      v_offset_adc = C_PSUM_DRV_ADC_ADCn_DELTA[v_ADC];
      /*{{RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> Conversion of pointer because explicit computation of an adress*/ 
      pt_reg = (volatile uint32_t*)((uint32_t)((uint8_t*)(V_PSUMonitoring_BaseAddress))
              + (v_offset_adc));
      /*}}RELAX<SYNCHRONe_C_Code_11.1,SYNCHRONe_C_Code_10.7> */
      v_buffGetSta = *pt_reg;
      *v_RegValue = (uint16_t) v_buffGetSta; /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost: Only a part of the orignal uint32 is affected to the uint16 variable */
      
      if( v_ADC == E_LIBBSP_PSUM_ADC_3 || v_ADC == E_LIBBSP_PSUM_ADC_7)
      {
         p_ADCErrorFlags->PresFail_or_Vin6Failure = (kcg_bool) (((v_buffGetSta & (uint32_t)(1ul<<C_PSUM_ADC7_VIN6_FAIL_ADC3_PRES_FAIL)))>>
         C_PSUM_ADC7_VIN6_FAIL_ADC3_PRES_FAIL);
      }
      else
      {
         p_ADCErrorFlags->PresFail_or_Vin6Failure = kcg_false;
      }
      p_ADCErrorFlags->OverVoltage = (kcg_bool) ((v_buffGetSta & (uint32_t)(1ul<<C_PSUM_ADC_OVD_FLAG))>>C_PSUM_ADC_OVD_FLAG);
      p_ADCErrorFlags->UnderVoltage = (kcg_bool) ((v_buffGetSta & (uint32_t)(1ul<<C_PSUM_ADC_UVD_FLAG))>>C_PSUM_ADC_UVD_FLAG);
      p_ADCErrorFlags->Vin7NotInRange = (kcg_bool) ((v_buffGetSta & (uint32_t)(1ul<<C_PSUM_ADC_VIN7_FAIL))>>C_PSUM_ADC_VIN7_FAIL);
      p_ADCErrorFlags->GeneralFailure =(kcg_bool) ((v_buffGetSta & (uint32_t)(1ul<<C_PSUM_ADC_FAIL))>>C_PSUM_ADC_FAIL);
      *v_ret = E_LIBBSP_PSUM_SUCCEEDED;
   }
   else
   {
      *v_ret = E_LIBBSP_PSUM_FAILED;
   }
}
/*==== END =============================================================================*/
