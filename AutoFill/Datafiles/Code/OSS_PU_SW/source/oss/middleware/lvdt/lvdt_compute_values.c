/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : lvdt_compute_values function which computes lvdt
 *               related numerical values for CSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/lvdt/lvdt_public.h"
#include "middleware/lvdt/lvdt_private.h"

/* ---------- include required interface: ----------------------------------- */
#include "libtools/math/LIB_MATH_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define         LVDT_GAIN_EXC 1.
#define         MY_SQR(OPERAND) (OPERAND*OPERAND)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* LVDT computed values */
float32_t lvdt_s1;
float32_t lvdt_s2;

float32_t lvdt_vs1_measure;
float32_t lvdt_vs2_measure;
float32_t lvdt_ratio_measure;

/* Average values for s1/s2 GND and REF */
float32_t lvdt_s1_ref_avg;
float32_t lvdt_s1_gnd_avg;
float32_t lvdt_s2_ref_avg;
float32_t lvdt_s2_gnd_avg;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Reference table */

extern const float32_t ref90[REF_TABLE_SIZE];
extern const float32_t ref[REF_TABLE_SIZE];

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-lvdt-xxxx */
void lvdt_compute_values(const boolean_t use_data_from_lvdt_a_or_lvdt_b,
                         float32_t * const lvdt_exc)
{
   float32_t * lvdt_s1_raw;
   float32_t * lvdt_s2_raw;
   float32_t * lvdt_exc_raw;

   /* Select appropriate source for voltage acquisitions  */
   if(FALSE == use_data_from_lvdt_a_or_lvdt_b)
   {
      lvdt_s1_raw  = lvdt_c_s1_raw;
      lvdt_s2_raw  = lvdt_c_s2_raw;
      lvdt_exc_raw = lvdt_c_exc_raw;
   }
   else
   {
      lvdt_s1_raw  = lvdt_a_b_s1_raw;
      lvdt_s2_raw  = lvdt_a_b_s2_raw;
      lvdt_exc_raw = lvdt_a_b_exc_raw;
   }

   /* Compute LVDT values */
   {
      /* Compute lvdt_xxx_avg variables */
      lvdt_s1_ref_avg = 0;
      lvdt_s1_gnd_avg = 0;
      lvdt_s2_ref_avg = 0;
      lvdt_s2_gnd_avg = 0;
      {
         uint32_t sample_id;
         /* >RELAX<SYNCHRONe_C_Code_23.2> Too long line (>120 characters) : => split over multiple lines  */
         for(sample_id = LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG ;
            sample_id < (LVDT_SPI_NB_OF_ADC_SAMPLES_MON - LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG) ;
            sample_id++)
         {
            lvdt_s1_ref_avg += xr_vsin_ref[sample_id];   /* XR VSIN and LVDT S1 share the same ref on ADC1 */
            lvdt_s1_gnd_avg += xr_vsin_gnd[sample_id];   /* XR VSIN and LVDT S1 share the same ref on ADC1 */
            lvdt_s2_ref_avg += xr_vcos_ref[sample_id];   /* XR VCOS and LVDT S2 share the same ref on ADC2 */
            lvdt_s2_gnd_avg += xr_vcos_gnd[sample_id];   /* XR VCOS and LVDT S2 share the same ref on ADC2 */
         }
         lvdt_s1_ref_avg /= LVDT_SPI_NB_OF_ADC_SAMPLES_MON - 2 * LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG;
         lvdt_s1_gnd_avg /= LVDT_SPI_NB_OF_ADC_SAMPLES_MON - 2 * LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG;
         lvdt_s2_ref_avg /= LVDT_SPI_NB_OF_ADC_SAMPLES_MON - 2 * LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG;
         lvdt_s2_gnd_avg /= LVDT_SPI_NB_OF_ADC_SAMPLES_MON - 2 * LVDT_NB_OF_IGNORED_MON_SAMPLES_AVG;
      }

      /* Compute lvdt_xxx */
      {
         uint32_t ref_shift         = 0;
         float32_t sigma_s1_ref     = 0;
         float32_t sigma_s2_ref     = 0;
         float32_t sigma_exc_ref    = 0;
         float32_t sigma_s1_ref90   = 0;
         float32_t sigma_s2_ref90   = 0;
         float32_t sigma_exc_ref90  = 0;
         {
            uint32_t sample_id;
            for(sample_id = LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N ;
                sample_id < (LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + REF_TABLE_SIZE) ;
               ++sample_id)
            {
               if((lvdt_exc_raw[sample_id] < 0) && (lvdt_exc_raw[sample_id + 1] >= 0))
               {
                  ref_shift = sample_id + 1;

                  /* Do not break here to reduce jitter*/

                  /*  TODO : si la frontiere est entre les deux, il ne sera jamais trouve => vrifier shift = 0 OK !*/
               }
            }
            /* Back to REF_TABLE_SIZE referential : */
            if(ref_shift >= LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N)
            {
               ref_shift -= LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N;
            }
         }
         {
            uint32_t sample_id;
            uint32_t shifted_index;
            for(sample_id = 0 ; sample_id < REF_TABLE_SIZE ; sample_id++)
            {
               shifted_index    = (sample_id + REF_TABLE_SIZE - ref_shift) % REF_TABLE_SIZE;
               sigma_s1_ref    += lvdt_s1_raw [LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref  [shifted_index];
               sigma_s2_ref    += lvdt_s2_raw [LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref  [shifted_index];
               sigma_exc_ref   += lvdt_exc_raw[LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref  [shifted_index];
               sigma_s1_ref90  += lvdt_s1_raw [LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref90[shifted_index];
               sigma_s2_ref90  += lvdt_s2_raw [LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref90[shifted_index];
               sigma_exc_ref90 += lvdt_exc_raw[LVDT_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref90[shifted_index];
            }
         }
         {
            float32_t sqrt_s2;
            float32_t sqrt_s1;
            float32_t sqrt_exc;
            sqrt_s2  = sqrt(MY_SQR(sigma_s2_ref) + MY_SQR(sigma_s2_ref90));
            sqrt_s1  = sqrt(MY_SQR(sigma_s1_ref) + MY_SQR(sigma_s1_ref90));
            sqrt_exc = sqrt(MY_SQR(sigma_exc_ref)+ MY_SQR(sigma_exc_ref90));
            lvdt_s1 = (2 * sqrt_s1 * 2.5) / ((REF_TABLE_SIZE) *   (lvdt_s1_ref_avg - lvdt_s1_gnd_avg));
            lvdt_s2 = (2 * sqrt_s2 * 2.5) / ((REF_TABLE_SIZE) *   (lvdt_s2_ref_avg - lvdt_s2_gnd_avg));
            *lvdt_exc  = (2 *            sqrt_exc  * LVDT_GAIN_EXC ) / REF_TABLE_SIZE ;
         }
         lvdt_ratio_measure = (lvdt_s1 - lvdt_s2) / (lvdt_s1 + lvdt_s2);
         lvdt_vs1_measure   = (lvdt_s1          ) / *lvdt_exc;
         lvdt_vs2_measure   = (lvdt_s2          ) / *lvdt_exc;
      }
   }
}

/* ---------- internal operations: ------------------------------------------ */
