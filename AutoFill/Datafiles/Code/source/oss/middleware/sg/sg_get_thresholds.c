/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/sg/sg_private.h"
#include "middleware/sg/sg_get_thresholds.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
#define C_SG_THRES_P3            0
#define C_SG_THRES_SG1_SG2_SG5   1
#define C_SG_THRES_SG3_SG4       2
#define C_SG_THRES_SAI           3

/* P3 sensors threshold values */
#define C_P3_THRESHOLD_1   ((float32_t)-0.120)
#define C_P3_THRESHOLD_2   ((float32_t)+0.120)
#define C_P3_THRESHOLD_3   ((float32_t)+9.7)
#define C_P3_THRESHOLD_4   ((float32_t)-0.003)
#define C_P3_THRESHOLD_5   ((float32_t)+7.6)
#define C_P3_THRESHOLD_6   ((float32_t)+9.9)
#define C_P3_THRESHOLD_7   ((float32_t)+0.015)
#define C_P3_THRESHOLD_10  ((float32_t)+8.0E-4)
#define C_P3_THRESHOLD_11  ((float32_t)-2.0E-5)
#define C_P3_THRESHOLD_12  ((float32_t)+4.018)

/* SG1 - SG2 - SG5 sensors threshold values */
#define C_SG125_THRESHOLD_1   ((float32_t)-0.030)
#define C_SG125_THRESHOLD_2   ((float32_t)+0.030)
#define C_SG125_THRESHOLD_3   ((float32_t)+8.7)
#define C_SG125_THRESHOLD_4   ((float32_t)-0.003)
#define C_SG125_THRESHOLD_5   ((float32_t)+7.6)
#define C_SG125_THRESHOLD_6   ((float32_t)+9.9)
#define C_SG125_THRESHOLD_7   ((float32_t)+0.015)
#define C_SG125_THRESHOLD_10  ((float32_t)+14.0E-4)
#define C_SG125_THRESHOLD_11  ((float32_t)-6.65E-2)
#define C_SG125_THRESHOLD_12  ((float32_t)+15.08)

/* SG3 - SG4 sensors threshold values */
#define C_SG34_THRESHOLD_1   ((float32_t)-0.030)
#define C_SG34_THRESHOLD_2   ((float32_t)+0.030)
#define C_SG34_THRESHOLD_3   ((float32_t)+8.7)
#define C_SG34_THRESHOLD_4   ((float32_t)-0.003)
#define C_SG34_THRESHOLD_5   ((float32_t)+7.6)
#define C_SG34_THRESHOLD_6   ((float32_t)+9.9)
#define C_SG34_THRESHOLD_7   ((float32_t)+0.025)
#define C_SG34_THRESHOLD_10  ((float32_t)+14.0E-4)
#define C_SG34_THRESHOLD_11  ((float32_t)-6.65E-2)
#define C_SG34_THRESHOLD_12  ((float32_t)+15.08)

/* SAI sensors threshold values */
#define C_SAI_THRESHOLD_1   ((float32_t)-0.030)
#define C_SAI_THRESHOLD_2   ((float32_t)+0.030)
#define C_SAI_THRESHOLD_3   ((float32_t)+5.2)
#define C_SAI_THRESHOLD_4   ((float32_t)-0.2)
#define C_SAI_THRESHOLD_5   ((float32_t)+9.4)
#define C_SAI_THRESHOLD_6   ((float32_t)+10.6)
#define C_SAI_THRESHOLD_7   ((float32_t)+0.015)
#define C_SAI_THRESHOLD_8   ((float32_t)+5.0E-4)
#define C_SAI_THRESHOLD_9   ((float32_t)+9.4)
#define C_SAI_THRESHOLD_10  ((float32_t)+5.0E-4)
#define C_SAI_THRESHOLD_11  ((float32_t)0.0)
#define C_SAI_THRESHOLD_12  ((float32_t)+5.0)

/* ---------- provided data: ------------------------------------------------ */
const ts_sg_thresholds v_check_values[C_SG_THRES_COUNT] ={
                                                            {
                                                               C_P3_THRESHOLD_1,
                                                               C_P3_THRESHOLD_2,
                                                               C_P3_THRESHOLD_3,
                                                               C_P3_THRESHOLD_4,
                                                               C_P3_THRESHOLD_5,
                                                               C_P3_THRESHOLD_6,
                                                               C_P3_THRESHOLD_7,
                                                               0,
                                                               0,
                                                               C_P3_THRESHOLD_10,
                                                               C_P3_THRESHOLD_11,
                                                               C_P3_THRESHOLD_12,
                                                            },
                                                            {
                                                               C_SG125_THRESHOLD_1,
                                                               C_SG125_THRESHOLD_2,
                                                               C_SG125_THRESHOLD_3,
                                                               C_SG125_THRESHOLD_4,
                                                               C_SG125_THRESHOLD_5,
                                                               C_SG125_THRESHOLD_6,
                                                               C_SG125_THRESHOLD_7,
                                                               0,
                                                               0,
                                                               C_SG125_THRESHOLD_10,
                                                               C_SG125_THRESHOLD_11,
                                                               C_SG125_THRESHOLD_12,
                                                            },
                                                            {
                                                               C_SG34_THRESHOLD_1,
                                                               C_SG34_THRESHOLD_2,
                                                               C_SG34_THRESHOLD_3,
                                                               C_SG34_THRESHOLD_4,
                                                               C_SG34_THRESHOLD_5,
                                                               C_SG34_THRESHOLD_6,
                                                               C_SG34_THRESHOLD_7,
                                                               0,
                                                               0,
                                                               C_SG34_THRESHOLD_10,
                                                               C_SG34_THRESHOLD_11,
                                                               C_SG34_THRESHOLD_12,
                                                            },
                                                            {
                                                               C_SAI_THRESHOLD_1,
                                                               C_SAI_THRESHOLD_2,
                                                               C_SAI_THRESHOLD_3,
                                                               C_SAI_THRESHOLD_4,
                                                               C_SAI_THRESHOLD_5,
                                                               C_SAI_THRESHOLD_6,
                                                               C_SAI_THRESHOLD_7,
                                                               C_SAI_THRESHOLD_8,
                                                               C_SAI_THRESHOLD_9,
                                                               C_SAI_THRESHOLD_10,
                                                               C_SAI_THRESHOLD_11,
                                                               C_SAI_THRESHOLD_12,
                                                            }
                                                         };

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
const ts_sg_thresholds * sg_get_thresholds(uint8_t p_sendor_id)
{
   const ts_sg_thresholds * pv_thresholds;

   switch (p_sendor_id)
   {
      case e_p3a:
      case e_p3b:
         pv_thresholds = &v_check_values[C_SG_THRES_P3];
         break;

      case e_sg1:
      case e_sg2:
      case e_sg5b:
         pv_thresholds = &v_check_values[C_SG_THRES_SG1_SG2_SG5];
         break;

      case e_sg3:
      case e_sg4:
         pv_thresholds = &v_check_values[C_SG_THRES_SG3_SG4];
         break;

      case e_sai1:
      case e_sai2:
      case e_sai3:
      case e_sai4:
         pv_thresholds = &v_check_values[C_SG_THRES_SAI];
         break;

      default:
         pv_thresholds = v_check_values;
         break;
   }

   return pv_thresholds;
}


/* ---------- internal operations: ------------------------------------------ */
