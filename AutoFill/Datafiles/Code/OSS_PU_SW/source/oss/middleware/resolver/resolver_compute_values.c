/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : resolver_compute_values function which computes resolver
 *               related numerical values for CSS
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/resolver/resolver_public.h"
#include "middleware/resolver/resolver_private.h"
#include "libtools/math/LIB_MATH_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */
/* A comment */
#define         XR_GAIN_EXC 1.
#define         MY_SQR(OPERAND) (OPERAND*OPERAND)

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */
/* A comment */
/*const uint32_t c_MY_CSU_CONST;*/

/* ---------- provided data: ------------------------------------------------ */
/* XR computed values */
float32_t xr_vcos;
float32_t xr_vsin;
float32_t xr_measure;
float32_t xr_vsin_measure;
float32_t xr_vcos_measure;

/* Average values for vcos/vsin GND and REF */
float32_t xr_vcos_ref_avg;
float32_t xr_vcos_gnd_avg;
float32_t xr_vsin_ref_avg;
float32_t xr_vsin_gnd_avg;

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */
/* Reference table */

const float32_t ref90[REF_TABLE_SIZE] = {
   1.0,
   0.9972037971811801,
   0.9888308262251285,
   0.9749279121818236,
   0.9555728057861407,
   0.9308737486442042,
   0.9009688679024191,
   0.8660254037844387,
   0.8262387743159949,
   0.7818314824680298,
   0.7330518718298263,
   0.6801727377709195,
   0.6234898018587336,
   0.563320058063622,
   0.5000000000000001,
   0.4338837391175582,
   0.365341024366395,
   0.2947551744109041,
   0.22252093395631445,
   0.14904226617617464,
   0.07473009358642439,
   6.123233995736766e-17,
   -0.07473009358642405,
   -0.1490422661761743,
   -0.22252093395631434,
   -0.2947551744109042,
   -0.3653410243663951,
   -0.43388373911755806,
   -0.4999999999999998,
   -0.5633200580636221,
   -0.6234898018587335,
   -0.6801727377709192,
   -0.7330518718298263,
   -0.7818314824680297,
   -0.826238774315995,
   -0.8660254037844385,
   -0.900968867902419,
   -0.9308737486442044,
   -0.9555728057861406,
   -0.9749279121818236,
   -0.9888308262251285,
   -0.9972037971811801,
   -1.0,
   -0.9972037971811801,
   -0.9888308262251286,
   -0.9749279121818236,
   -0.9555728057861408,
   -0.9308737486442042,
   -0.9009688679024191,
   -0.8660254037844388,
   -0.8262387743159949,
   -0.7818314824680299,
   -0.7330518718298262,
   -0.6801727377709194,
   -0.6234898018587337,
   -0.563320058063622,
   -0.5000000000000004,
   -0.4338837391175583,
   -0.3653410243663949,
   -0.29475517441090465,
   -0.2225209339563146,
   -0.14904226617617433,
   -0.07473009358642473,
   -1.8369701987210297e-16,
   0.07473009358642436,
   0.14904226617617397,
   0.22252093395631423,
   0.2947551744109043,
   0.3653410243663954,
   0.43388373911755795,
   0.49999999999999933,
   0.5633200580636224,
   0.6234898018587334,
   0.6801727377709188,
   0.7330518718298266,
   0.7818314824680297,
   0.8262387743159945,
   0.8660254037844384,
   0.900968867902419,
   0.9308737486442042,
   0.9555728057861406,
   0.9749279121818235,
   0.9888308262251284,
   0.9972037971811801,
};

const float32_t ref[REF_TABLE_SIZE] = {
   0.0,
   0.07473009358642425,
   0.14904226617617444,
   0.2225209339563144,
   0.2947551744109042,
   0.365341024366395,
   0.4338837391175581,
   0.49999999999999994,
   0.5633200580636221,
   0.6234898018587335,
   0.6801727377709194,
   0.7330518718298262,
   0.7818314824680298,
   0.8262387743159949,
   0.8660254037844386,
   0.9009688679024191,
   0.9308737486442042,
   0.9555728057861408,
   0.9749279121818236,
   0.9888308262251285,
   0.9972037971811801,
   1.0,
   0.9972037971811801,
   0.9888308262251285,
   0.9749279121818236,
   0.9555728057861408,
   0.9308737486442042,
   0.9009688679024191,
   0.8660254037844387,
   0.8262387743159948,
   0.7818314824680299,
   0.7330518718298265,
   0.6801727377709194,
   0.6234898018587336,
   0.5633200580636218,
   0.5000000000000003,
   0.43388373911755823,
   0.3653410243663948,
   0.2947551744109046,
   0.2225209339563145,
   0.14904226617617472,
   0.07473009358642467,
   1.2246467991473532e-16,
   -0.07473009358642398,
   -0.14904226617617403,
   -0.22252093395631428,
   -0.29475517441090393,
   -0.36534102436639504,
   -0.433883739117558,
   -0.4999999999999997,
   -0.5633200580636221,
   -0.6234898018587334,
   -0.6801727377709195,
   -0.7330518718298263,
   -0.7818314824680297,
   -0.8262387743159949,
   -0.8660254037844385,
   -0.900968867902419,
   -0.9308737486442042,
   -0.9555728057861406,
   -0.9749279121818236,
   -0.9888308262251285,
   -0.9972037971811801,
   -1.0,
   -0.9972037971811801,
   -0.9888308262251286,
   -0.9749279121818236,
   -0.9555728057861407,
   -0.9308737486442041,
   -0.9009688679024193,
   -0.866025403784439,
   -0.8262387743159947,
   -0.7818314824680299,
   -0.7330518718298269,
   -0.6801727377709191,
   -0.6234898018587337,
   -0.5633200580636227,
   -0.5000000000000004,
   -0.43388373911755834,
   -0.36534102436639493,
   -0.2947551744109047,
   -0.22252093395631464,
   -0.14904226617617528,
   -0.0747300935864239,
};

/* ---------- provided operation bodies: ------------------------------------ */

/* Implements REQ_FADEX_OS_SRD-RESOLVER-0020 */
void resolver_compute_values(float32_t * const xr_exc)
{
   /* Compute resolver_xr_vxxx_xxx_avg variables */
   xr_vcos_ref_avg = 0;
   xr_vcos_gnd_avg = 0;
   xr_vsin_ref_avg = 0;
   xr_vsin_gnd_avg = 0;
   {
    uint32_t sample_id;

    /* >RELAX<SYNCHRONe_C_Code_23.2> Too long line (>120 characters) : => split over multiple lines  */
    for(sample_id = RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG ;
      sample_id < (RESOLVER_SPI_NB_OF_ADC_SAMPLES_MON - RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG) ;
      sample_id++)
    {
      xr_vcos_ref_avg += xr_vcos_ref[sample_id];
      xr_vcos_gnd_avg += xr_vcos_gnd[sample_id];
      xr_vsin_ref_avg += xr_vsin_ref[sample_id];
      xr_vsin_gnd_avg += xr_vsin_gnd[sample_id];
    }
    xr_vcos_ref_avg /= RESOLVER_SPI_NB_OF_ADC_SAMPLES_MON - 2 * RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG;
    xr_vcos_gnd_avg /= RESOLVER_SPI_NB_OF_ADC_SAMPLES_MON - 2 * RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG;
    xr_vsin_ref_avg /= RESOLVER_SPI_NB_OF_ADC_SAMPLES_MON - 2 * RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG;
    xr_vsin_gnd_avg /= RESOLVER_SPI_NB_OF_ADC_SAMPLES_MON - 2 * RESOLVER_NB_OF_IGNORED_MON_SAMPLES_AVG;
   }

   /* Compute resolver_xr_xxx */
   {
    uint32_t ref_shift = 0;
    float32_t sigma_vcos_ref   = 0;
    float32_t sigma_vsin_ref   = 0;
    float32_t sigma_exc_ref    = 0;
    float32_t sigma_vcos_ref90 = 0;
    float32_t sigma_vsin_ref90 = 0;
    float32_t sigma_exc_ref90  = 0;
    float32_t sign_sin;
    float32_t sign_cos;
    {
      uint32_t sample_id;
      for(sample_id = RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N ;
         sample_id < (RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + REF_TABLE_SIZE) ;
         ++sample_id)
      {
         if((xr_exc_raw[sample_id] < 0) && (xr_exc_raw[sample_id + 1] >= 0))
         {
           ref_shift = sample_id + 1;

           /* Do not break here to reduce jitter*/
         }
      }
      /* Back to REF_TABLE_SIZE referential : */
      if(ref_shift >= RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N)
      {
         ref_shift -= RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N;
      }
    }

    {
      uint32_t sample_id;
      uint32_t shifted_index;
      for(sample_id = 0 ;   sample_id < REF_TABLE_SIZE; sample_id++)
      {
         shifted_index = (sample_id + REF_TABLE_SIZE - ref_shift) % REF_TABLE_SIZE;
         sigma_vsin_ref   += xr_vsin_raw[RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref  [shifted_index];
         sigma_vcos_ref   += xr_vcos_raw[RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref  [shifted_index];
         sigma_exc_ref    += xr_exc_raw [RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref  [shifted_index];
         sigma_vsin_ref90 += xr_vsin_raw[RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref90[shifted_index];
         sigma_vcos_ref90 += xr_vcos_raw[RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref90[shifted_index];
         sigma_exc_ref90  += xr_exc_raw [RESOLVER_NB_OF_IGNORED_RAW_SAMPLES_AVG_N + sample_id] * ref90[shifted_index];
      }
      if(sigma_vsin_ref < 0 )
      {
         sign_sin = -1;
      }
      else
      {
         sign_sin = 1;
      }
      if(sigma_vcos_ref < 0 )
      {
         sign_cos = -1;
      }
      else
      {
         sign_cos = 1;
      }
    }

    {
      float32_t sqrt_vcos;
      float32_t sqrt_vsin;
      float32_t sqrt_exc;
      sqrt_vcos = sqrt(MY_SQR(sigma_vcos_ref) + MY_SQR(sigma_vcos_ref90));
      sqrt_vsin = sqrt(MY_SQR(sigma_vsin_ref) + MY_SQR(sigma_vsin_ref90));
      sqrt_exc  = sqrt(MY_SQR(sigma_exc_ref)  + MY_SQR(sigma_exc_ref90 ));

      xr_vcos = (2 * sign_cos * sqrt_vcos * 2.5) /
      ((REF_TABLE_SIZE) *   (xr_vcos_ref_avg - xr_vcos_gnd_avg));

      xr_vsin = (2 * sign_sin * sqrt_vsin * 2.5) /
      ((REF_TABLE_SIZE) *   (xr_vsin_ref_avg - xr_vsin_gnd_avg));

      *xr_exc  = (2 *            sqrt_exc  * XR_GAIN_EXC ) /
      REF_TABLE_SIZE ;

      xr_vcos_measure = xr_vcos / *xr_exc;
      xr_vsin_measure = xr_vsin / *xr_exc;
    }

    {
      float32_t angle_xr = 180. * LIB_MATH_ATAN_CALC(xr_vsin / xr_vcos) / 3.1415926535897932384626433832795;

      if(xr_vcos > 0)
      {
         xr_measure = angle_xr;
      }
      else if((xr_vcos < 0) && (xr_vsin > 0))
      {
         xr_measure = 180 + angle_xr;
      }
      else if((xr_vcos < 0) && (xr_vsin < 0))
      {
         xr_measure = -180 + angle_xr;
      }
      else if((xr_vcos == 0) && (xr_vsin > 0))
      {
         xr_measure = 90;
      }
      else if((xr_vcos == 0) && (xr_vsin < 0))
      {
         xr_measure = -90;
      }
      else if (xr_vsin == 0)
      {
         xr_measure = -90;
      }
      else
      {
         xr_measure = 0;
         /*??? TODO : TBC*/
      }
    }
   }
}

/* ---------- internal operations: ------------------------------------------ */
