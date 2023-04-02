/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : LibTrig                                                                                                */
/* FILENAME : LibTrig.c                                                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "LibIEEE.h"
#include "Floor.h"
#include "IsInf.h"
#include "LibTrig.h"


const t_float C_SMALL_X = 1.0e-10;

#ifdef S_LITTLE_ENDIAN
/* Concat 32 bits words LSB and MSB to form a 64 bits words */
#define LIB_MATH_IEEE_DECL(A, B) {{ (B), (A) }}
#else /* BIG ENDIAN */
/* Concat 32 bits words LSB and MSB to form a 64 bits words */
#define LIB_MATH_IEEE_DECL(A, B) {{ (A), (B) }}
#endif /* S_LITTLE_ENDIANS */

/* Pi */
#if defined (FLOAT_64)
/* Pi 64 bits value             = 3.1415926535897932384626433832795 */
/* C_D_PI =  0x400921fb54442d18 = 3.14159265358979311599796346854  */
const TU_LIB_MATH_IEEE C_D_PI = LIB_MATH_IEEE_DECL( 0x400921FBuL, 0x54442D18uL );
/* C_D_PI_LOW = 0x3CA1A62633145CB1 = 1.224646799147395028841971693993751e-16 */
const TU_LIB_MATH_IEEE C_D_PI_LOW = LIB_MATH_IEEE_DECL( 0x3CA1A626uL, 0x33145CB1uL );
#elif defined (FLOAT_32)
/* Pi 32 bits value             = 3.1415926535897932384626433832795 */
/* C_D_PI = 0x40490fdb          = 3.1415927410125732421875          */
const TU_LIB_MATH_IEEE C_D_PI = LIB_MATH_IEEE_DECL( 0x4049uL, 0x0FDBuL);
/* C_D_PI_LOW = 0xb3bbbd2e      = -8.74227765734758577309548854828E-8   */
const TU_LIB_MATH_IEEE C_D_PI_LOW = LIB_MATH_IEEE_DECL( 0xB3BBuL, 0xBD23uL );
#endif

/* Pi/2 */
#if defined (FLOAT_64)
/* Pi/2 64 bits value                =   1.5707963267948966192313216916397514420985846996876   */
/* C_D_PI_2 = 0x3FF921FB54442D18     =   1.57079632679489655799898173427                       */
const TU_LIB_MATH_IEEE C_D_PI_2 = LIB_MATH_IEEE_DECL( 0x3FF921FBuL, 0x54442D18uL );
/* C_D_PI_2_LOW = 0x3C91A62633145CB1 =   6.12323399573697514420985846996876E-17                */                            
const TU_LIB_MATH_IEEE C_D_PI_2_LOW = LIB_MATH_IEEE_DECL( 0x3C91A626uL, 0x33145CB1uL );
#elif defined (FLOAT_32)
/* Pi/2 32 bits value                =   1.5707963267948966192313216916397514420985846996876   */
/* C_D_PI_2 = 0x3fc90fdb             =   1.57079637050628662109375E0                           */ 
const TU_LIB_MATH_IEEE C_D_PI_2 = LIB_MATH_IEEE_DECL( 0x3FC9uL, 0x0FDBuL );
/* C_D_PI_2_LOW   0xB33BBD2F         =   -4.3711391839451607665978372097E-8                    */
const TU_LIB_MATH_IEEE C_D_PI_2_LOW = LIB_MATH_IEEE_DECL( 0xB33BuL, 0xBD2FuL );
#endif

/* Pi/4 */
#if defined(FLOAT_64)                
/* Pi/4 64 bits value                =   0.7853981633974483096156608458198757210492923498437    */                                
/* C_D_PI_4 = 0x3FE921FB54442D18     =   0.785398163397448278999490867136  */
const TU_LIB_MATH_IEEE C_D_PI_4 = LIB_MATH_IEEE_DECL(0x3FE921FBuL, 0x54442D18uL);
/* C_D_PI_4_LOW = 0x3C81A62633145C0E =   3.06161699786838757210492923498437E-17                 */
const TU_LIB_MATH_IEEE C_D_PI_4_LOW = LIB_MATH_IEEE_DECL(0x3C81A626uL, 0x33145C0EuL);
#elif defined(FLOAT_32)
/* Pi/4 32 bits value                =   0.7853981633974483096156608458198757210492923498437    */
/* C_D_PI_4 = 0x3F490FDB             =   0.785398185253143310546875                             */
const TU_LIB_MATH_IEEE C_D_PI_4 = LIB_MATH_IEEE_DECL(0x3F49uL, 0x0FDBuL);
/* C_D_PI_4_LOW   0xB2BBBD2E         =   -2.185569500093121415418012427896E-8                   */
const TU_LIB_MATH_IEEE C_D_PI_4_LOW = LIB_MATH_IEEE_DECL(0xB2BBuL, 0xBD2EuL);
#endif

/* PI/6 */
#if defined (FLOAT_64)
/* Pi/6 64 bits value                = 0.52359877559829887307710723054658381403286156656252     */
/* C_D_PI_6 =  0x3fe0c152382d7366    = 0.523598775598298926681195553101                     */
const TU_LIB_MATH_IEEE C_D_PI_6 = LIB_MATH_IEEE_DECL( 0x3FE0C152uL, 0x382D7366uL );
/* C_D_PI_6_LOW = 0xBC8EE6913347C290 = -5.36040883225544136565446258537E-17                */ 
const TU_LIB_MATH_IEEE C_D_PI_6_LOW = LIB_MATH_IEEE_DECL( 0xBC8EE691uL, 0x3347C290uL );
#elif defined (FLOAT_32)
/* Pi/6 32 bits value                = 0.52359877559829887307710723054658381403286156656252 */
/* C_D_PI_6 =                        = 0.52359879016876220703125                            */
const TU_LIB_MATH_IEEE C_D_PI_6 = LIB_MATH_IEEE_DECL( 0x3F06uL, 0x0A92uL );
/* C_D_PI_6_LOW = 0xb27a5194         = -1.4570463946483869221992790699E-8                   */
const TU_LIB_MATH_IEEE C_D_PI_6_LOW = LIB_MATH_IEEE_DECL( 0xB27AuL, 0x5194uL );
#endif


/* Tan Pi/12 */
#if defined (FLOAT_64)
/* Tan Pi/12 64 bits value                  = 0.267949192431122751312244645305327139794826507568359375*/
/* C_D_TAN_PI_12  = 0x3FD126145E9ECD57      = 0.267949192431122751312244645305                 */
const TU_LIB_MATH_IEEE C_D_TAN_PI_12 = LIB_MATH_IEEE_DECL( 0x3FD12614uL, 0x5E9ECD57uL );
/* C_D_TAN_PI_12_LOW =  0x399A8A6D7ECA5621  = 3.27139794826507585520654412937E-31               */
const TU_LIB_MATH_IEEE C_D_TAN_PI_12_LOW = LIB_MATH_IEEE_DECL( 0x399A8A6DuL, 0x7ECA5621uL );
#elif defined (FLOAT_32)
/* Tan Pi/12 32 bits value                  = 0.267949192431122751312244645305327139794826507568359375*/
/* C_D_TAN_PI_12  = 0x3E8930A3              = 0.2679491937160491943359375                 */
const TU_LIB_MATH_IEEE C_D_TAN_PI_12 = LIB_MATH_IEEE_DECL( 0x3E89uL, 0x30A3uL );
/* C_D_TAN_PI_12_LOW =  0xB0B09955          = -1.28492649853484408595249988139E-9                */
const TU_LIB_MATH_IEEE C_D_TAN_PI_12_LOW = LIB_MATH_IEEE_DECL( 0xB0B0uL, 0x9955uL );
#endif

/* Tan Pi/6 */
#if defined (FLOAT_64)
/* Tan Pi/6 64 bits value                   = 0.57735026918962584208117050366126932203769683837890625 */
/* C_D_TAN_PI_6   = 0x3FE279A74590331D      = 0.577350269189625842081170503661                                */
const TU_LIB_MATH_IEEE C_D_TAN_PI_6 = LIB_MATH_IEEE_DECL( 0x3FE279A7uL, 0x4590331DuL );
/* C_D_TAN_PI_6_LOW = 0x3995D99991CE4902    = 2.69322037696838378422940738047E-31  */
const TU_LIB_MATH_IEEE C_D_TAN_PI_6_LOW = LIB_MATH_IEEE_DECL( 0x3995D999uL, 0x91CE4902uL );
#elif defined (FLOAT_32)
/* Tan Pi/6 32 bits value                   = 0.57735026918962584208117050366126932203769683837890625 */
/* C_D_TAN_PI_6   = 0x3F13CD3A              = 0.57735025882720947265625                   */
const TU_LIB_MATH_IEEE C_D_TAN_PI_6 = LIB_MATH_IEEE_DECL( 0x3F13uL, 0xCD3AuL );
/* C_D_TAN_PI_6_LOW = 0x32320664            = 1.03624167024918278912082314491E-8  */
const TU_LIB_MATH_IEEE C_D_TAN_PI_6_LOW = LIB_MATH_IEEE_DECL( 0x3232uL, 0x0664uL );
#endif

#define C_ATAN_POLY_ORDER (4)


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ReducedSin                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Find the Sine of an angle in [-Pi/4..Pi/4] with an accuracy of about 5e-17.                          */
/*    Special case: if X = 0.0, the function returns exactly 0.0                                                     */
/*                                                                                                                   */
/* Pre-condition: X has its value between -Pi/4 and Pi/4                                                             */
/*                                                                                                                   */
/* Input: X : input value from which the sine is computed                                                            */
/* Output: none                                                                                                      */
/* Return: sinX : result of the sine computation                                                                     */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float ReducedSin(const t_float X)
{
   /* Declarations */   
   const t_float C_S[7] =
   {
      (1.0 / (2.0 * 3.0)),
      (1.0 / (4.0 * 5.0)),
      (1.0 / (6.0 * 7.0)),
      (1.0 / (8.0 * 9.0)),
      (1.0 / (10.0 * 11.0)),
      (1.0 / (12.0 * 13.0)),
      (1.0 / (14.0 * 15.0))
   };

   const t_float C_Z = X * X;

   /* Declarations */
   t_float AbsX;
   t_float sinX;
   t_boolean IsZeroOrSubnormalX;

   /* Initializations */
   AbsX = Abs(X);
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);
   
   /* If X is outside the range defined by the precondition */
   if (AbsX > ((M_D_PI_4 + M_D_PI_4_LOW)))
   {
      /* Return the NaN value */
      sinX = M_D_NAN;
   }
   else 
   {
      /* Statements */
      /* If X = 0 (or subnormal), then return exactely 0.0 without further calculation */
      if (IsZeroOrSubnormalX != FALSE)
      {
         sinX = C_ZERO_FLOAT;
      }
      else
      {
         /* When AbsX <C_SMALL_X, the relative error between sin x and x is below FP relative precision capabilities */
         /* Thus sin of X and X cannot be distinguished */
         if (AbsX < C_SMALL_X)
         {
            sinX = X;
         }
         else
         {
            /* Taylor serie rearranged to avoid catastrophic bit cancellations */
            /* The maximum difference between the sine function and the 15th order Taylor serie */
            /* in the range of [-Pi/4..Pi/4]  is about 5e-17 */

            sinX = ((-C_S[6]) * C_Z) + C_ONE_FLOAT;
            sinX = ((sinX * C_S[5]) * C_Z) - C_ONE_FLOAT;
            sinX = ((sinX * C_S[4]) * C_Z) + C_ONE_FLOAT;
            sinX = ((sinX * C_S[3]) * C_Z) - C_ONE_FLOAT;
            sinX = ((sinX * C_S[2]) * C_Z) + C_ONE_FLOAT;
            sinX = ((sinX * C_S[1]) * C_Z) - C_ONE_FLOAT;
            sinX = ((sinX * C_S[0]) * C_Z) + C_ONE_FLOAT;
            sinX = sinX * X;
         }
      }
   }
   
   /* Return data is set in any condition case */
   return (sinX);
}


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   ReducedCos                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Find the Cosine of an angle in [-Pi/4..Pi/4] with an accuracy of about 1e-17.                        */
/*                                                                                                                   */
/* Pre-condition: X has its value between -Pi/4 and Pi/4                                                             */
/*                                                                                                                   */
/* Input: X : input value from which the cosine is computed                                                          */
/* Output: none                                                                                                      */
/* Return: cosX : result of the cosine computation                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float ReducedCos(const t_float X)
{
   /* Declarations */
   const t_float C_C[7] =
   {
      (1.0 / (1.0 * 2.0)),
      (1.0 / (3.0 * 4.0)),
      (1.0 / (5.0 * 6.0)),
      (1.0 / (7.0 * 8.0)),
      (1.0 / (9.0 * 10.0)),
      (1.0 / (11.0 * 12.0)),
      (1.0 / (13.0 * 14.0))
   };

   const t_float C_Z = X * X;  

   /* Declarations */
   t_float cosX;
   t_float AbsX;

   /* Initializations */
   AbsX = Abs(X);
   
   /* If X is outside the range defined by the precondition */
   if (AbsX > ((M_D_PI_4 + M_D_PI_4_LOW)))
   {
      /* Return the NaN value */
      cosX = M_D_NAN;
   }
   else
   {
      /* Statements */
      /* When AbsX<C_SMALL_X, the relative error between cos of x */
      /* and 1-X*X/2 is below FP relative precision capabilities */
      /* Thus cos X  and 1-X*X/2 cannot be distinguished */
      if (AbsX < C_SMALL_X)
      {
         cosX = C_ONE_FLOAT - ((X * X) / C_TWO_FLOAT);
      }
      else
      {
         /* Taylor serie rearranged to avoid catastrophic bit cancellations */
         /* The maximum difference between the cosine function and the 15th order Taylor serie */
         /*  in the range of [-Pi/4..Pi/4] is about 6e-17 */
         cosX = ((-C_C[6]) * C_Z) + C_ONE_FLOAT;
         cosX = ((cosX * C_C[5]) * C_Z) - C_ONE_FLOAT;
         cosX = ((cosX * C_C[4]) * C_Z) + C_ONE_FLOAT;
         cosX = ((cosX * C_C[3]) * C_Z) - C_ONE_FLOAT;
         cosX = ((cosX * C_C[2]) * C_Z) + C_ONE_FLOAT;
         cosX = ((cosX * C_C[1]) * C_Z) - C_ONE_FLOAT;
         cosX = ((cosX * C_C[0]) * C_Z) + C_ONE_FLOAT;
      }
   }
   
   /* Return data is set in any condition case */
   return (cosX);
}


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   PositiveAtan                                                                                          */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Returns the arc tangent of a positive value with an accuracy is less than 2E-16.                     */
/*     Special: if X=INF, then PositiveAtan returns Pi/2                                                             */
/*                                                                                                                   */
/* Pre-condition:  none                                                                                              */
/*                                                                                                                   */
/* Input: x : input value for the computation                                                                        */
/* Output: none                                                                                                      */
/* Return: result : the arc tangent of the input value.                                                              */
/*-------------------------------------------------------------------------------------------------------------------*/

t_float PositiveAtan(const t_float X)
{
   /* Declarations constants for continued fraction */
   const t_float C_N[C_ATAN_POLY_ORDER] = {
      (91.0 / 51.0),
      (249.0 / 455.0),
      (1289.0 / 7553.0),
      (16384.0 / 638055.0)
   };
   const t_float C_D[C_ATAN_POLY_ORDER] = {
      (36.0 / 17.0),
      (7.0 / 10.0),
      (10.0 / 39.0),
      (3.0 / 44.0)
   };

   /* Threshold above which the effective result and the asymptotic */
   /* value cannot be distinguished on a 64bit FP data */
   const t_float C_LIBMATH_X_HIGHLIMIT = 1.0e+20;
   
   /* Declarations */
   t_float atanX;
   t_float redX;
   t_float x2;
   t_float n_x;
   t_float d_x;
   t_boolean comp;
   t_boolean hi_seg;
   t_boolean IsInfX;

   /* Initializations */
   redX = X;
   comp = FALSE;
   hi_seg = FALSE;
   IsInfX = IsInf(X);

   /* Statements */
   /* PositiveAtan INF returns Pi/2 */
   if (IsInfX != FALSE)
   {
      atanX = M_D_PI_2 + M_D_PI_2_LOW;
   }
   else
   {
      /* When X<C_SMALL_X, the relative error between atan x  and x is */
      /* below FP relative precision capabilities. Thus atan X  and X */
      /* cannot be distinguished */
      if (X < C_SMALL_X)
      {
         atanX = X;
      }
      else
      {
         /* When X>C_LIBMATH_X_HIGHLIMIT, the relative error between atan x and the */
         /* asymptotic value is below FP relative precision */
         /* capabilities. Thus atan X and Pi/2 cannot be distinguished */
         if (X > C_LIBMATH_X_HIGHLIMIT)
         {
            atanX = M_D_PI_2 + M_D_PI_2_LOW;
         }
         else
         {
            /* Limit argument to [0..1] */
            if (redX > C_ONE_FLOAT)
            {
               comp = TRUE;
               redX = C_ONE_FLOAT / redX;
            }
            /* Range reduction */
            /* Determine segmentation */
            if (redX > (M_D_TAN_PI_12 + M_D_TAN_PI_12_LOW))
            {
               hi_seg = TRUE;
               redX = ((redX - M_D_TAN_PI_6) - M_D_TAN_PI_6_LOW) / (C_ONE_FLOAT + ((M_D_TAN_PI_6 + M_D_TAN_PI_6_LOW) * redX));
            }
            /* Argument is now < tan Pi/12 */
            x2 = redX * redX;
            n_x = C_ONE_FLOAT + (C_N[0] * (x2 * (C_ONE_FLOAT + (C_N[1] * (x2 * (C_ONE_FLOAT + (C_N[2] * (x2 * (C_ONE_FLOAT + (C_N[3] * x2))))))))));
            d_x = C_ONE_FLOAT + (C_D[0] * (x2 * (C_ONE_FLOAT + (C_D[1] * (x2 * (C_ONE_FLOAT + (C_D[2] * (x2 * (C_ONE_FLOAT + (C_D[3] * x2))))))))));
            atanX = redX * (n_x / d_x);
            /* Now restore offset if needed */
            if (hi_seg != FALSE)
            {
               atanX = (atanX + M_D_PI_6) + M_D_PI_6_LOW;
            }
            /* Restore complement if needed */
            if (comp != FALSE)
            {
               atanX = (M_D_PI_2 - atanX) + M_D_PI_2_LOW;
            }
         }
      }
   }

   return (atanX);
}


/*-------------------------------------------------------------------------------------------------------------------*/
/* Function:   SinCosRangeReduc                                                                                      */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: Reduce X to RedX in the interval -Pi/4, Pi/4                                                         */
/*    Special case: if X = 0.0, the function returns exactly 0.0                                                     */
/*                                                                                                                   */
/* Pre-condition: ABS(X) shall be less than or equal to 1.0e+04 (32 bits) or 1.0e+05 (64 bits)                       */
/*                                                                                                                   */
/* Input: X : input value from which the range reduction is perform                                                  */
/* Output: pa_RedX : result of the range reduction computation                                                       */
/* Return: quadrant : quadrant relatives to the range reduction                                                      */
/*-------------------------------------------------------------------------------------------------------------------*/

t_int_32 SinCosRangeReduc(const t_float X, t_float *const pa_RedX)
{
   /* Declarations */
   t_float absX;
   t_float y;
   t_float tmp;
   t_int_32 quadrant;
   t_int_32 pEx;
   const t_float C_ONE_HALF_FLOAT = 0.5;
   const t_int_32 C_TWO_INT32 = 2;
   t_boolean IsZeroOrSubnormalX;
   t_float reduceAngle;

   /* Initializations */
   *pa_RedX = C_ZERO_FLOAT;
   quadrant = (t_int_32)C_ZERO_FLOAT;

   /* Statements */
   absX = Abs(X);
   IsZeroOrSubnormalX = IsZeroOrSubnormal(X);

   /* if X is outside the range */
   if (absX > C_MAX_INPUT)
   {
      /* Return the NaN value */
      *pa_RedX = M_D_NAN;
   }
   else
   {
      /* tmp is set to the value of angle in radians/ divide by Pi/2 + 0.5 */
      /* reducing the angle between Pi/4 and -Pi/4 */
      tmp = (absX / (M_D_PI_2 + M_D_PI_2_LOW)) + C_ONE_HALF_FLOAT;

      /* return the floor of tmp, the largest integer less than or equal to tmp */
      y = Floor(tmp);

      /* quadrant = y modulo 4 = y-E * y/4 *4 */
      /* set the exponent to -2 */
      pEx = -C_TWO_INT32;
      /* return the value of y* (2**(-2))   */
      tmp = LdExp(y, pEx);
      /* return the floor of tmp, the largest integer less tahn or equal to tmp */
      tmp = Floor(tmp);
      /* set the exponent to 2 */
      pEx = C_TWO_INT32;
      /* return the value of tmp* (2**(2))   */
      tmp = LdExp(tmp, pEx);
      /* calculate the quadrant ( not reduced angle) */
      quadrant = (t_int_32)(y - tmp);

      /* If X = 0 (or subnormal), then return exactely 0.0 without further calculation */
      /* This if-branch can't be done before as we need the regular calulation for the */
      /* quadrant                                                                      */
      if (IsZeroOrSubnormalX != FALSE)
      {
         *pa_RedX = C_ZERO_FLOAT;
      }
      else
      {   
         /* Enhance offseting precision using two words to approximate Pi/2 */
         reduceAngle = (absX - (y * M_D_PI_2)) - (y * M_D_PI_2_LOW);
         
         /* Avoid the output of a reduceAngle < Pi/4 due to possible rounding error */
         if (reduceAngle < -(M_D_PI_4 + M_D_PI_4_LOW))
         {
            reduceAngle = -(M_D_PI_4 + M_D_PI_4_LOW);
         }
         
         *pa_RedX = reduceAngle;
      }
   }
   return (quadrant);
}

