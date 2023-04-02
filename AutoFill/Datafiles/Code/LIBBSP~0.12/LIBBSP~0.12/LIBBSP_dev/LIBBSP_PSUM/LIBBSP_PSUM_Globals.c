/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#include "LIBBSP_PSUM_Globals.h"

/*==== Definitions =====================================================================*/


/*==== Variables =======================================================================*/
uint32_t * const V_PSUMonitoring_BaseAddress = (uint32_t * const) C_LIBBSP_CMPREG_PSU;
const uint32_t C_PSUM_DRV_ADC_ADCn_DELTA[E_LIBBSP_PSUM_NB_ADC] =
{
   C_PSUM_ADC1_DELTA,
   C_PSUM_ADC2_DELTA,
   C_PSUM_ADC3_DELTA,
   C_PSUM_ADC4_DELTA,
   C_PSUM_ADC5_DELTA,
   C_PSUM_ADC6_DELTA,
   C_PSUM_ADC7_DELTA
};

const TS_LIBBSP_PSUM_AdcConversion C_PSUM_CONV_SCALE_OFFSET [E_LIBBSP_PSUM_NB_ADC][E_LIBBSP_PSUM_NB_CHANNEL] =
{ /* valeurs trouvees dans 3300781920-R18-000-03_GANAV_BSIS.pdf */
   { /* 1 */
      {1.0, 0.0},
      {5.22, 0.0},
      {2.47, 0.0},
      {3.94589178, -6.03318637},
      {1.68027211, 0.0},
      {5.22, 0.0},
      { 9.54670106, -17.3197595},
      { 1.0, 0.0}
   },
   { /* 2 */
      {1.0, 0.0},
      {2.47, 0.0},
      {9.54670106, -6.03318637},
      {5.22, 0.0},
      {9.45691383, -17.3197595},
      {1.68027211, 0.0},
      {1.0, 0.0},
      {1.0, 0.0}
   },
   { /* 3 */
      {1.0, 0.0},
      {11.0, 0.0},
      {9.45691383, -17.3197595},
      {2.47, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0}
   },
   { /* 4 */
      {1.0, 0.0},
      {1.68027211, 0.0},
      {1.01, 0.0},
      {1.01, 0.0},
      {1.01, 0.0},
      {1.01, 0.0},
      {2.47, 0.0},
      {1.0, 0.0},
   },
   { /* 5 */
      {1.0, 0.0},
      {1.01, 0.0},
      {1.01, 0.0},
      {1.68027211, 0.0},
      {2.0, 0.0},
      {2.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0}
   },
   { /* 6 */
      {1.0, 0.0},
      {1.68027211, 0.0},
      {3.94589178, -6.03318637},
      {5.22, 0.0},
      {9.45691383, -17.3197595},
      {10.9733066, -13.6259719},
      {10.9733066, -13.6259719},
      {1.0, 0.0}
   },
   { /* 7 */ /* not used */
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0},
      {1.0, 0.0}
   }
};

const float64_t C_PSUM_ADC_SAMPLE_LSB = 2.5 / 4096.0;

const TS_LIBBSP_PSUM_Conf C_PSUM_Initialisation_Couples[C_PSUM_ADC_NB_INITIALISATION_COUPLES] =
{
   /* parametrage des seuils */ /* valeurs trouvees dans 3300781920-R18-000-03_GANAV_BSIS.pdf */
   /* ADC 1 */
   {C_PSUM_ADC1_UVD_THRESHOLD_0 , 0}, /*Under voltage threshold for channel 0 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_1 , 2904}, /*Under voltage threshold for channel 1 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_2 , 2646}, /*Under voltage threshold for channel 2 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_3 , 657}, /*Under voltage threshold for channel 3 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_4 , 3002}, /*Under voltage threshold for channel 4 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_5 , 3563}, /*Under voltage threshold for channel 5 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_6 , 800}, /*Under voltage threshold for channel 6 of ADC1*/
   {C_PSUM_ADC1_UVD_THRESHOLD_7 , 3335}, /*Under voltage threshold for channel 7 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_0 , 40}, /*Over voltage threshold for channel 0 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_1 , 3372}, /*Over voltage threshold for channel 1 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_2 , 2925}, /*Over voltage threshold for channel 2 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_3 , 864}, /*Over voltage threshold for channel 3 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_4 , 3432}, /*Over voltage threshold for channel 4 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_5 , 3969}, /*Over voltage threshold for channel 5 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_6 , 1041}, /*Over voltage threshold for channel 6 of ADC1*/
   {C_PSUM_ADC1_OVD_THRESHOLD_7 , 3375}, /*Over voltage threshold for channel 7 of ADC1*/
   /* ADC 2 */
   {C_PSUM_ADC2_UVD_THRESHOLD_0 , 0}, /*Under voltage threshold for channel 0 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_1 , 3216}, /*Under voltage threshold for channel 1 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_2 , 1410}, /*Under voltage threshold for channel 2 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_3 , 3324}, /*Under voltage threshold for channel 3 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_4 , 945}, /*Under voltage threshold for channel 4 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_5 , 3002}, /*Under voltage threshold for channel 5 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_6 , 0}, /*Under voltage threshold for channel 6 of ADC2*/
   {C_PSUM_ADC2_UVD_THRESHOLD_7 , 3335}, /*Under voltage threshold for channel 7 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_0 , 40}, /*Over voltage threshold for channel 0 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_1 , 3416}, /*Over voltage threshold for channel 1 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_2 , 1523}, /*Over voltage threshold for channel 2 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_3 , 3705}, /*Over voltage threshold for channel 3 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_4 , 1174}, /*Over voltage threshold for channel 4 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_5 , 3432}, /*Over voltage threshold for channel 5 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_6 , 40}, /*Over voltage threshold for channel 6 of ADC2*/
   {C_PSUM_ADC2_OVD_THRESHOLD_7 , 3375}, /*Over voltage threshold for channel 7 of ADC2*/
   /* ADC 3 */
   {C_PSUM_ADC3_UVD_THRESHOLD_0 , 0}, /*Under voltage threshold for channel 0 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_1 , 2059}, /*Under voltage threshold for channel 1 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_2 , 207}, /*Under voltage threshold for channel 2 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_3 , 3147}, /*Under voltage threshold for channel 3 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_4 , 0}, /*Under voltage threshold for channel 4 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_5 , 0}, /*Under voltage threshold for channel 5 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_6 , 0}, /*Under voltage threshold for channel 6 of ADC3*/
   {C_PSUM_ADC3_UVD_THRESHOLD_7 , 3335}, /*Under voltage threshold for channel 7 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_0 , 40}, /*Over voltage threshold for channel 0 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_1 , 2408}, /*Over voltage threshold for channel 1 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_2 , 595}, /*Over voltage threshold for channel 2 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_3 , 3486}, /*Over voltage threshold for channel 3 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_4 , 4095}, /*Over voltage threshold for channel 4 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_5 , 4095}, /*Over voltage threshold for channel 5 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_6 , 3432}, /*Over voltage threshold for channel 6 of ADC3*/
   {C_PSUM_ADC3_OVD_THRESHOLD_7 , 3375}, /*Over voltage threshold for channel 7 of ADC3*/
   /* ADC 4 */
   {C_PSUM_ADC4_UVD_THRESHOLD_0 , 0}, /*Under voltage threshold for channel 0 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_1 , 3002}, /*Under voltage threshold for channel 1 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_2 , 2776}, /*Under voltage threshold for channel 2 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_3 , 2313}, /*Under voltage threshold for channel 3 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_4 , 1541}, /*Under voltage threshold for channel 4 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_5 , 1154}, /*Under voltage threshold for channel 5 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_6 , 3216}, /*Under voltage threshold for channel 6 of ADC4*/
   {C_PSUM_ADC4_UVD_THRESHOLD_7 , /*0*/3335}, /*Under voltage threshold for channel 7 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_0 , 40}, /*Over voltage threshold for channel 0 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_1 , 3422}, /*Over voltage threshold for channel 1 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_2 , 3121}, /*Over voltage threshold for channel 2 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_3 , 2601}, /*Over voltage threshold for channel 3 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_4 , 1735}, /*Over voltage threshold for channel 4 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_5 , 1303}, /*Over voltage threshold for channel 5 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_6 , 3416}, /*Over voltage threshold for channel 6 of ADC4*/
   {C_PSUM_ADC4_OVD_THRESHOLD_7 , /*40*/3375}, /*Over voltage threshold for channel 7 of ADC4*/
   /* ADC 5 */
   {C_PSUM_ADC5_UVD_THRESHOLD_0 , 0}, /*Under voltage threshold for channel 0 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_1 , 1848}, /*Under voltage threshold for channel 1 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_2 , 1848}, /*Under voltage threshold for channel 2 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_3 , 3002}, /*Under voltage threshold for channel 3 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_4 , 0}, /*Under voltage threshold for channel 4 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_5 , 0}, /*Under voltage threshold for channel 5 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_6 , 0}, /*Under voltage threshold for channel 6 of ADC5*/
   {C_PSUM_ADC5_UVD_THRESHOLD_7 , 3335}, /*Under voltage threshold for channel 7 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_0 , 40}, /*Over voltage threshold for channel 0 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_1 , 2083}, /*Over voltage threshold for channel 1 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_2 , 2083}, /*Over voltage threshold for channel 2 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_3 , 3432}, /*Over voltage threshold for channel 3 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_4 , 4095}, /*Over voltage threshold for channel 4 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_5 , 4095}, /*Over voltage threshold for channel 5 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_6 , 40}, /*Over voltage threshold for channel 6 of ADC5*/
   {C_PSUM_ADC5_OVD_THRESHOLD_7 , 3375}, /*Over voltage threshold for channel 7 of ADC5*/
   /* ADC 6 */
   {C_PSUM_ADC6_UVD_THRESHOLD_0 , 0}, /*Under voltage threshold for channel 0 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_1 , 3440}, /*Under voltage threshold for channel 1 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_2 , 873}, /*Under voltage threshold for channel 2 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_3 , 3324}, /*Under voltage threshold for channel 3 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_4 , 945}, /*Under voltage threshold for channel 4 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_5 , 0}, /*Under voltage threshold for channel 5 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_6 , 0}, /*Under voltage threshold for channel 6 of ADC6*/
   {C_PSUM_ADC6_UVD_THRESHOLD_7 , 3335}, /*Under voltage threshold for channel 7 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_0 , 40}, /*Over voltage threshold for channel 0 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_1 , 3775}, /*Over voltage threshold for channel 1 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_2 , 1063}, /*Over voltage threshold for channel 2 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_3 , 3705}, /*Over voltage threshold for channel 3 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_4 , 1174}, /*Over voltage threshold for channel 4 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_5 , 4095}, /*Over voltage threshold for channel 5 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_6 , 4095}, /*Over voltage threshold for channel 6 of ADC6*/
   {C_PSUM_ADC6_OVD_THRESHOLD_7 , 3375}, /*Over voltage threshold for channel 7 of ADC6*/
   /* ADC 7 */
   {C_PSUM_ADC7_UVD_THRESHOLD_0 , 0x00000000}, /*Under voltage threshold for channel 0 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_1 , 0x00000000}, /*Under voltage threshold for channel 1 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_2 , 0x00000000}, /*Under voltage threshold for channel 2 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_3 , 0x00000000}, /*Under voltage threshold for channel 3 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_4 , 0x00000000}, /*Under voltage threshold for channel 4 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_5 , 0x00000000}, /*Under voltage threshold for channel 5 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_6 , 0x00000000}, /*Under voltage threshold for channel 6 of ADC7*/
   {C_PSUM_ADC7_UVD_THRESHOLD_7 , 0x00000000}, /*Under voltage threshold for channel 7 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_0 , 0x00000000}, /*Over voltage threshold for channel 0 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_1 , 0x00000000}, /*Over voltage threshold for channel 1 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_2 , 0x00000000}, /*Over voltage threshold for channel 2 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_3 , 0x00000000}, /*Over voltage threshold for channel 3 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_4 , 0x00000000}, /*Over voltage threshold for channel 4 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_5 , 0x00000000}, /*Over voltage threshold for channel 5 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_6 , 0x00000000}, /*Over voltage threshold for channel 6 of ADC7*/
   {C_PSUM_ADC7_OVD_THRESHOLD_7 , 0x00000000}, /*Over voltage threshold for channel 7 of ADC7*/

   {C_PSUM_ADC1234_CFG, 0xFEFEFEFE  }, /* activation de tous les canaux */
   {C_PSUM_ADC567_CFG,    0x0000FEFE  }, /* activation de tous les canaux */
   /* l'adc 7 est un spare et le monitoring n'est pas activ� sur ce spare */
};


/*==== Services ========================================================================*/

/*==== END =============================================================================*/
