/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : This file contains the DrvADC Analog read function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "DrvADC_Public.h"
#include "DrvADC_Private.h"


/* ---------- include required interface: ----------------------------------- */
#include "MCP_Types.h"


/* ---------- internal define constants: ------------------------------------ */
/* None */


/* ---------- internal types: ----------------------------------------------- */
/* None */


/* ---------- provided constants: ------------------------------------------- */
/* None */


/* ---------- provided data: ------------------------------------------------ */
/* None */


/* ---------- internal constants: ------------------------------------------- */
/* None */


/* ---------- internal data: ------------------------------------------------ */
/* None */


/* ---------- internal operations: ------------------------------------------ */
/* None */


/* ---------- provided operation bodies: ------------------------------------ */
/* DrvADC_Read : To read an Analog input
 *   Inputs:
 *     - p_Analog_Num: The analog number to be read
 *     - p_pt_ADC_Value: The read value
 *   Outputs: None
 *   Function return: None
 *   Pre-condition: None
*/
void DrvADC_Read (const uint32_t p_Analog_Num, float32_t * const p_pt_ADC_Value)
{
   uint32_t v_ADC_Controller_Id;

   if (p_Analog_Num < DRVADC_ANALOG_MAX_NB)
   {
      v_ADC_Controller_Id = C_DrvADC_Port_Def [p_Analog_Num].S_Controller_Id;

      C_DrvADC_Registers [v_ADC_Controller_Id]->S_SC1 [DRVADC_SC1A_ID] &= ~DRVADC_SC1_ADCH_MASK;
      C_DrvADC_Registers [v_ADC_Controller_Id]->S_SC1 [DRVADC_SC1A_ID] = C_DrvADC_Port_Def [p_Analog_Num].S_SC1A_Value;

      /* {{RELAX<SYNCHRONe_C_Code_10.7> There is no loss of precision. */
      /* The 32-bit Unsigned Integer acquired by the ADC is explicitly casted in float to avoid implicit conversion. */
      *p_pt_ADC_Value = (C_DrvADC_Port_Def [p_Analog_Num].S_ADC_Gain *
         ((float32_t) C_DrvADC_Registers [v_ADC_Controller_Id]->S_R [0])) -
         C_DrvADC_Port_Def [p_Analog_Num].S_ADC_Offset;
      /* }} RELAX<SYNCHRONe_C_Code_10.7> */
   }
   else
   {
      *p_pt_ADC_Value = 0.0f;
   }
}
