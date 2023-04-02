/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : Expo                                                                                                   */
/* FILENAME : Expo.c                                                                                                 */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Description: This function calculates the value of e^(x)                                                          */
/*                                                                                                                   */
/* Pre-condition: None                                                                                               */
/*                                                                                                                   */
/* Input: X - exponent of the function.                                                                              */
/* Output: none                                                                                                      */
/* Return: result - value of e^(x)                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* Method                                                                                                            */
/*   1. Argument reduction:                                                                                          */
/*      Given x, find r and integer k such that                                                                      */
/*                                                                                                                   */
/*               x = k*ln2 + r,  |r| <= 0.5*ln2 ~ 0.34658                                                            */
/*                                                                                                                   */
/*      the error in r when rounded to a floating-point number.                                                      */
/*                                                                                                                   */
/*         r = ( x - k*ln2)                                                                                          */
/*         k = (1/ln2) * (x-r) = (1/ln2) * (x-0.5)                                                                   */
/*                                                                                                                   */
/*         Before the recalculation of r , it has been consider x~r .                                                */
/*                                                                                                                   */
/*   2. Approximating Expo(r) by a special rational function on                                                      */
/*      the interval [0,0.34658]:                                                                                    */
/*      Since                                                                                                        */
/*          r*(exp(r)+1)/(exp(r)-1) = 2+ r^2/6 - r^4/360 + ...                                                       */
/*      we define R1(r*r) by                                                                                         */
/*          r*(exp(r)+1)/(exp(r)-1) = 2+ r^2/6 * R1(r*r)                                                             */
/*      That is,                                                                                                     */
/*          R1(r**2) = 6/r *((exp(r)+1)/(exp(r)-1) - 2/r)                                                            */
/*                   = 6/r * ( 1 + 2.0*(1/(exp(r)-1) - 1/r))                                                         */
/*                   = 1 - r^2/60 + r^4/2520 - r^6/100800 + ...                                                      */
/*      We use a special Remez algorithm on [0,0.347] to generate                                                    */
/*      a polynomial of degree 5 in r*r to approximate R1. The                                                       */
/*      maximum error of this polynomial approximation is bounded                                                    */
/*      by 2**-61. In other words,                                                                                   */
/*          R1(z) ~ 1.0 + Q1*z + Q2*z**2 + Q3*z**3 + Q4*z**4 + Q5*z**5                                               */
/*      where   Q1  =  -1.6666666666666567384E-2,                                                                    */
/*              Q2  =   3.9682539681370365873E-4,                                                                    */
/*              Q3  =  -9.9206344733435987357E-6,                                                                    */
/*              Q4  =   2.5051361420808517002E-7,                                                                    */
/*              Q5  =  -6.2843505682382617102E-9;                                                                    */
/*                                                                                                                   */
/*      The values of the Remez algorithm using the following assignment to z                                        */
/*              z   =  0.5* r*r                                                                                      */
/*      have been replaced by:                                                                                       */
/*                                                                                                                   */
/*              Q1  =  -3.33333333333331316428e-02 * 0.5,                                                            */
/*              Q2  =   1.58730158725481460165e-03 * 0.5^2,                                                          */
/*              Q3  =  -7.93650757867487942473e-05 * 0.5^3,                                                          */
/*              Q4  =  4.00821782732936239552e-06  * 0.5^4                                                           */
/*              Q5  =  -2.01099218183624371326e-07 * 0.5^5;                                                          */
/*                                                                                                                   */
/*                                                                                                                   */
/*     (where z= 0.5 * r*r, and the values of Q1 to Q5 are listed below)                                             */
/*   with error bounded by                                                                                           */
/*          |                  5           |     -61                                                                 */
/*          | 1.0+Q1*z+...+Q5*z   -  R1(z) | <= 2                                                                    */
/*          |                              |                                                                         */
/*                                                                                                                   */
/*      Expo(r) -1  is then computed by the following                                                                */
/*      specific way which minimize the accumulation rounding error:                                                 */
/*                              2     3                                                                              */
/*                             r     r    [ 3 - (R1 + R1*r/2)  ]                                                     */ 
/*        Expo(r) -1.0 =  r + --- + --- * [--------------------]                                                     */
/*                             2     2    [ 6 - r*(3 - R1*r/2) ]                                                     */
/*                                                                                                                   */
/*      To compensate the error in the argument reduction, we use                                                    */
/*              Expo(r+c) = Expo(r) + c + Expo(r)*c                                                                  */
/*                         ~ Expo(r) + c + r*c                                                                       */
/*      Thus c+r*c will be added in as the correction terms for                                                      */
/*      Expo(r+c). Now rearrange the term to avoid optimization                                                      */
/*      screw up:                                                                                                    */
/*                          (      2                                   2 )                                           */
/*                          ({  ( r    [ R1 -  (3 - R1*r/2) ]  )  }   r  )                                           */
/*       Expo(r+c)-1 ~ +r - ({r*(---* [-------------------- ]-c)-c} - ---)                                           */
/*                          ({  ( 2    [ 6 - r*(3 - R1*r/2) ]  )  }   2  )                                           */
/*                          (                                            )                                           */
/*                                                                                                                   */
/*               (      2                        2 )                                                                 */
/*               ({  ( r    [ R1 -  t ]  )  }   r  )                                                                 */
/*        ~ +r - ({r*(---* [----------]-c)-c} - ---)  , where t  = 3 - ( R1 * *r/2 ) ;                               */
/*               ({  ( 2    [ 6 - r*t ]  )  }   2  )                                                                 */
/*               (                                 )                                                                 */
/*               (                  2                  2                                                             */
/*                                r  )             ( r    [ R1 -  t ]  )       [ R1 -  t ]                           */
/*        ~ +r - ({r* (e -c)-c} - ---) , where e = (--- * [----------] ) = Z * ----------                            */
/*                                2  )             ( 2    [ 6 - r*t ]  )       [ 6 - r*t ]                           */
/*                                                                                                                   */
/*         = r - E                                                                                                   */
/*                                                                                                                   */
/*         Expo(r+c) ~ 1 + r - E                                                                                     */
/*                                                                                                                   */
/*   3. Scale back to obtain Expo(x):                                                                                */
/*      From step 1, we have                                                                                         */
/*         Expo(x) = either  2^k*[Expo(r)+1] - 1                                                                     */
/*                  = or     2^k*[Expo(r) + (1-2^-k)]                                                                */
/*   4. Implementation notes:                                                                                        */
/*      (A). To save one multiplication, we scale the coefficient Qi                                                 */
/*           to Qi*2^i, and replace z by (x^2)/2.                                                                    */
/*      (B). To achieve maximum accuracy, we compute Expo(x) by                                                      */
/*        (i)   if x < -56 *ln2, return -1.0, (raise inexact if x!=inf)                                              */
/*        (ii)  if k=0, return r-E +0.1                                                                              */
/*        (iii) if k=-1, return 0.5 *(r-E)-0.5 +1.0                                                                  */
/*        (iv)  if k=1 if r < -0.25, return 2*((r+0.5)- E) +1.0                                                      */
/*                     else          return  2.0+ 2.0*(r-E);                                                         */
/*        (v)   if (k<-2||k>56) return 2^k(1-(E-r)) - 1 (or exp(x)-1)                                                */
/*        (vi)  if k (k>1 && k<56), return 2^k((1-2^-k)-(E-r)), else                                                 */
/*        (vii) return 2^k(1-((E+2^-k)-r))                                                                           */
/*                                                                                                                   */
/* Special cases:                                                                                                    */
/*      Expo(INF) is INF, Expo(NaN) is NaN;                                                                          */
/*      Expo(-INF) is 0, and                                                                                         */
/*      for finite argument, only Expo(0)=1 is exact.                                                                */
/*                                                                                                                   */
/* Misc. info.                                                                                                       */
/*      For t_float 64 bits                                                                                          */
/*          if x >  7.09782712893383973096e+02 then Expo(x) overflow                                                 */
/*      For t_float 32 bits                                                                                          */
/*          if x >  88.699 then Expo(x) overflow                                                                     */
/*                                                                                                                   */
/* Constants:                                                                                                        */
/* The hexadecimal values are the intended ones for the following                                                    */
/* constants. The decimal values may be used, provided that the                                                      */
/* compiler will convert from decimal to binary accurately enough                                                    */
/* to produce the hexadecimal values shown.                                                                          */
/*-------------------------------------------------------------------------------------------------------------------*/


#include "Expo.h"
#include "LibIEEE.h"
#include "IsSubnormal.h"


t_float Expo_L_Calculation (const t_float E, const t_float r, const t_int_32 k);

t_float Expo(const t_float x)
{
   const t_float C_HALF_FLOAT = 0.5;
   const t_float C_SIX_FLOAT = 6.0;
   const t_int_32 C_K_MINUS_ONE = -1;
   const t_int_32 C_K_ZERO = 0;
   const t_int_32 C_K_ONE = 1;

   t_float r;
   t_float hfx;
   t_float Z;
   t_float R1;
   t_float E;

   t_float hi;
   t_float lo;
   t_float c = C_ZERO_FLOAT;
   t_float t;

   t_int_32 k = C_K_ZERO;
   t_int_32 xsb;
   t_float result;
   t_float AbsX;
   t_boolean IsSubnormalX;

   /* Declarations */
   TU_LIB_MATH_IEEE mdx;

   /* if the processor is 64 bits */
   #if defined (FLOAT_64)

   /* Value of Logarithm natural of 2 - Hight part */
   const t_float ln2HI = 6.93147180369123816490e-01;
   /* Value of Logarithm natural of 2 - Low part */
   const t_float ln2LO = 1.90821492927058770002e-10;
   /* Value of Invers of Logarithm natural of 2 */
   const t_float InvLn2 = 1.44269504088896338700e+00;
   /* Parameters of Remez Algortihm */
   const t_float Q1 = -3.33333333333331316428e-02;
   const t_float Q2 =  1.58730158725481460165e-03;
   const t_float Q3 = -7.93650757867487942473e-05;
   const t_float Q4 =  4.00821782732936239552e-06;
   const t_float Q5 = -2.01099218183624371326e-07;

   /* Value of overflow threshold */
   const t_float O_THRESHOLD = 708.396418532; /* ln(2**1022) */
   /* value of 0.5 ln2 - 32 msv */
   const t_uint_32 C_HALF_LNAT2 = 0x3fd62e42;
   /* value of 1.5 ln2 - 32 msv */
   const t_uint_32 C_ONEANHALF_LNAT2 = 0x3FF0A2B2;
   /*  value of 2**-54 - 32 msv */
   const t_uint_32 C_SMALL = 0x3c900000; 
   /* sign bit in 64 bits */
   const t_uint_32 C_SIGN_BIT = 31;

   /* high word of input x */
   t_uint_32 hx;

   /* if the processor is 32 bits */
   #elif defined (FLOAT_32)

   /* Value of Logarithm natural of 2 - Hight part */
   const t_float ln2HI = 6.93147182464599609375e-1;
   /* Value of Logarithm natural of 2 - Low part */
   const t_float ln2LO =1.90821497492166258780343923718e-10;
   /* Value of Invers of Logarithm natural of 2 */
   const t_float InvLn2 = 1.44269502162933349609375E0;
   /* Parameters of Remez Algortihm */
   const t_float Q1 =  -3.33333350718021392822265625e-2;
   const t_float Q2 =  1.58730160910636186599731445313e-3;
   const t_float Q3 = -7.93650760897435247898101806641e-5;
   const t_float Q4 =  4.00821772927884012460708618164e-6;
   const t_float Q5 = -2.01099211949440359603613615036e-7;

   /* Value of overflow threshold */
   const t_float O_THRESHOLD = 87.3365447506; /* ln(2**126) */
   /* value of 0.5 ln2 - 16 msv */
   const t_uint_16 C_HALF_LNAT2 = 0x3EB1;
   /* value of 1.5 ln2 - 16 msv */
   const t_uint_16 C_ONEANHALF_LNAT2 = 0x3F85;
   /*  value of 2**-54 - 16 msv */
   const t_uint_16 C_SMALL = 0x2480; 
   /* sign bit in 32 bits */
   const t_uint_16 C_SIGN_BIT = 15;

   /* high word of input x */
   t_uint_16 hx;

   #endif

   mdx.d = x;

   /* Statements */
   hx = mdx.i.high;

   /* Initializations */
   AbsX = Abs(x);
   IsSubnormalX = IsSubnormal(x);
   r = x;

   /* sign bit of x */
   xsb = (t_int_32) ((hx >> C_SIGN_BIT) & 1);
   /* high word of |x| */
   hx = hx & C_SIGN_MASK_HIGH;      
   /* filter out non-finite argument */
   /* if |x|>=709.78... 64 bits */
   /* if |x|>=87.49... 32 bits */
   
   if (IsSubnormalX != FALSE)
   {
      result = M_D_NAN;
      
      return (result);
   }
   else if(AbsX >= O_THRESHOLD)
   {
      if (xsb ==C_K_ONE)
      { 
         /* exp(+-inf)={inf,0} */
         result = C_ZERO_FLOAT;
      }
      else
      {
         /* undeflow- overflow - returns not a number */
         result = M_D_NAN;
      }
   }
   else
   {
      /* argument reduction */
      /* if  |x| > 0.5 ln2 */
      if(hx > C_HALF_LNAT2) 
      {
         /* and |x| < 1.5 ln2 */
         if(hx < C_ONEANHALF_LNAT2)
         {  
            if (xsb == C_K_ONE) 
            {
               hi = r + ln2HI;
               lo = -ln2LO;
               k = C_K_MINUS_ONE;
            }
            else
            {
               hi = r - ln2HI;
               lo = ln2LO;
               k =  C_K_ONE;
            } /* end if(xsb == 0) */
         }/* end if(hx < C_ONEANHALF_LNAT2) */
         else
         {
            if (xsb == C_K_ONE)
            {
               k  = (t_int_32) ((InvLn2 * r) - C_HALF_FLOAT);
               t  = (t_float) k;
               hi = r - (t * ln2HI);
               lo = (t * ln2LO);
            }
            else
            {
               k  = (t_int_32) ((InvLn2 * r) + C_HALF_FLOAT);
               t  = (t_float) k;
               hi = r - (t * ln2HI);
               lo = (t * ln2LO);
            }
         }
         r = hi - lo;
         c = (hi-r)-lo;
      }
      else if ((hx < C_SMALL) && (hx != 0))
      {
         /* |x| < 2**-54, return x */
         result = C_ONE_FLOAT;
         return(result);
      }
      else
      {
         k = C_K_ZERO;
      } /* end if(hx > C_HALF_LNAT2 ) - else if - else k=0 */     

      /* x (r) is now in primary range */ 
      hfx = C_HALF_FLOAT * r;
      /* calculate Z = 0.5 * r^2 */
      Z  = r * hfx;
      /* calculate R1 */
      R1 = C_ONE_FLOAT + (Z *(Q1 + (Z * ( Q2 + (Z * ( Q3 + (Z * ( Q4 + (Z * Q5) ))))))));
      /* calculate t */
      t  = C_THREE_FLOAT - ( R1 * hfx );
      /* calculate E */
      E  = Z * ((R1 - t)/(C_SIX_FLOAT - (r * t)));
      E  = (r * (E - c)) - c;
      E  = E -  Z;

      result = Expo_L_Calculation (E, r, k);

   }/* if (hx >= 0x4043687A) - main if */
   
   return(result); 
}

t_float Expo_L_Calculation (const t_float E, const t_float r, const t_int_32 k)
{
   /* Declarations */
   TU_LIB_MATH_IEEE mdy;
   TU_LIB_MATH_IEEE mdt;

   const t_int_32 C_K_MINUS_ONE = -1;
   const t_int_32 C_K_ZERO = 0;
   const t_int_32 C_K_ONE = 1;
   const t_int_32 C_K_TWENTY = 20;
   const t_int_32 C_K_HIG_RANGE = 56;
   const t_int_32 C_K_LOW_RANGE = -2;
   const t_float C_HALF_FLOAT = 0.5;
   const t_float C_MINUS_TWO_FLOAT = -2.0;
   const t_float C_MQUART_FLOAT = - 0.25;
   
   t_float result;
   t_float val;
   t_float y;

   /* if the processor is 64 bits */
   #if defined (FLOAT_64)
   /* value of 1.0 - 32 msv */
   const t_uint_32 C_ONE_UNSIGNED_MSV = 0x3ff00000; 
   /* Set the bit exponent of 1.0 - 32 msv - bit 32 ( lsv) + 22 */
   const t_uint_32 C_EXPONENT = 0x200000;
   /* Set the the minimum value to be masked in the exponent - 64 bits */
   const t_int_32 C_MINIMUM_TO_MASK = 0x000003ff;

   /* Set the bit exponent */
   const t_int_32 C_EXP = 20;
   const t_float t = C_ONE_FLOAT ;

   /* high word of output */
   t_uint_32 hy;
   /* low word of output */
   t_uint_32 ly;
   /* high word of output */
   t_uint_32 ht;

   /* if the processor is 32 bits */
   #elif defined (FLOAT_32)
   /* value of 1.0 - 32 bits */
   const t_uint_32 C_ONE_UNSIGNED = 0x3F800000; 
   /* value of Mask last 16 bits */
   const t_uint_32 C_MASK_LAST_16 = 0xFFFF0000;
   /* value of Mask last 16 bits */
   const t_uint_32 C_MASK_FIRST_16 = 0x0000FFFF;
   /* value of bits to set high and word */
   const t_uint_32 C_HIGW_WORD = 16;
   /* Set the bit exponent */
   const t_int_32 C_EXP = 23;
   /* Element  exponent */
   const t_uint_32 C_EXP_PO = 0x1000000;
   /* Set the the minimum value to be masked in the exponent - 32 bits */
   const t_int_32 C_MINIMUM_TO_MASK = 0x0000007f;

   /* high word of output */
   t_uint_16 hy;
   /* low word of output */
   t_uint_16 ly;
   /* high word of output */
   t_uint_16 ht;
   /* low word of output */
   t_uint_16 lt;
   /* intermediate word */
   t_uint_16 kk;
   /* intermediate word */
   t_uint_32 KP;
   t_uint_32 KS;

   #endif

   if ( k == C_K_MINUS_ONE)
   {
      /* set the value to 0.5 *(r-E)-0.5 +1.0 */
      result = ((C_HALF_FLOAT * ( r - E )) - C_HALF_FLOAT) + C_ONE_FLOAT;
   } 
   else if(k == C_K_ZERO)
   {
      result= C_ONE_FLOAT + (r - E);
   }
   else if(k == C_K_ONE)
   {
      if (r < C_MQUART_FLOAT)
      {
         /* set the value to2*((r+0.5)- E) +1.0 */
         result =  (C_MINUS_TWO_FLOAT * ( E - (r + C_HALF_FLOAT))) + C_ONE_FLOAT;
      }
      else
      {
         /* set the value to 2.0+ 2.0*(r-E) */
         result =  C_TWO_FLOAT + (C_TWO_FLOAT * ( r - E));
      }/* end (X<-0.25 ) */
   }
   else if((k <= C_K_LOW_RANGE) || (k >= C_K_HIG_RANGE))
   {
      /* set the value to 2^k(1-(E-r)) */
      mdy.d = C_ONE_FLOAT - (E - r);
      hy = mdy.i.high;
      ly = mdy.i.low;
      #if defined (FLOAT_64)
      hy = hy + (t_uint_32) (k << C_SHIFT_EXPONENT);
      #elif defined (FLOAT_32)
      kk = (t_uint_16) (k << C_SHIFT_EXPONENT);
      hy = hy + kk;
      #endif

      mdy.i.high = hy;
      mdy.i.low  = ly;
      result = mdy.d;
   }
   else if((k > C_K_ONE) && (k < C_K_TWENTY))
   { 
      #if defined (FLOAT_64)
      
      /* Calculation of  2^k((1-2^-k)-(E-r)) */
      /* Calculates  (1-2^-k) */
      mdt.d = t; 
      ht = C_ONE_UNSIGNED_MSV - (t_uint_32) (C_EXPONENT >> k);
      mdt.i.high = ht;
      val = mdt.d;
      /* Calculates  ((1-2^-k)-(E-r)) */
      mdy.d = val - (E-r);
      hy = mdy.i.high;
      /* Calculates  2^k((1-2^-k)-(E-r)) */
      hy = hy+ (t_uint_32)(k << C_SHIFT_EXPONENT);
      mdy.i.high = hy;
      /* returns double + 1.0 */
      result =  mdy.d + C_ONE_FLOAT;

      #elif defined (FLOAT_32)
      
      /* Calculation of  2^k((1-2^-k)-(E-r)) */
      /* Calculates  (1-2^-k) */   
      KS = C_ONE_UNSIGNED - (t_uint_32) (C_EXP_PO >> k);

      mdy.i.high = (t_uint_16) (( KS & C_MASK_LAST_16) >> C_HIGW_WORD);   
      mdy.i.low  = (t_uint_16) ( KS & C_MASK_FIRST_16);        

      val = mdy.d; 
      /* Calculates  ((1-2^-k)-(E-r)) */
      y= val - (E-r);
      /* Calculates  2^k */
      KP = C_ONE_UNSIGNED + (t_uint_32) (k << C_EXP);    

      ht  = (t_uint_16) (( KP & C_MASK_LAST_16)>> C_HIGW_WORD);
      lt  = (t_uint_16) ( KP & C_MASK_FIRST_16);
      mdt.i.high = ht;
      mdt.i.low  = lt; 
      /* Calculation of  2^k((1-2^-k)-(E-r)) */
      /*result =  y * mdt.d +1.0; */
      result = (y * mdt.d) +C_ONE_FLOAT;
      
      #endif
   }
   else
   {
      #if defined (FLOAT_64)
      
      /* Calculation of  2^k(1-((E+2^(-k))-r)) = */
      /* 2^k * ( 1 + ( r - (E + 2^(-k)))) */
      /* Calculates 2^(-k) */
      mdt.d = t; 
      ht = (t_uint_32)(C_MINIMUM_TO_MASK-k) << C_EXP;

      mdt.i.high = ht;
      val = mdt.d;
      /* Calculates ( r - (E + 2^(-k))) */
      y = r - (E+val);
      /* Calculates  ( 1 + ( r - (E + 2^(-k)))) */
      mdy.d = y + C_ONE_FLOAT;
      /* Calculates 2^k * ( 1 + ( r - (E + 2^(-k)))) */
      hy = mdy.i.high;
      hy = hy + (t_uint_32) (k << C_EXP); 
      mdy.i.high = hy;
      result = mdy.d + C_ONE_FLOAT; 
      
      #elif defined (FLOAT_32)
      
      /* Calculation of  2^k(1-((E+2^(-k))-r)) = */
      /* 2^k * ( 1 + ( r - (E + 2^(-k)))) */
      /* Calculates  2^(-k) */
      KS =(t_uint_32) (C_MINIMUM_TO_MASK-k) << C_EXP ;
      mdy.i.high = (t_uint_16) (( KS & C_MASK_LAST_16) >> C_HIGW_WORD);
      mdy.i.low  = (t_uint_16) ( KS & C_MASK_FIRST_16);

      val = mdy.d;
      /* Calculates  ( r - (E + 2^(-k)))*/
      y = r - (E+val);
      /* Calculates  ( r - (E + 2^(-k)))*/
      mdy.d = C_ONE_FLOAT + y;
      
      /* Calculates  2^k  */
      KP = C_ONE_UNSIGNED + (t_uint_32) (k << C_EXP);    
      ht  = (t_uint_16) (( KP & C_MASK_LAST_16)>> C_HIGW_WORD);
      lt  = (t_uint_16) ( KP & C_MASK_FIRST_16);
      mdt.i.high = ht;
      mdt.i.low  = lt;
      /* set the value to    2^k((1-2^-k)-(E-r)) */
      result = (mdy.d* mdt.d) + C_ONE_FLOAT;
      
      #endif

   }/* if ( k==-1) - cases k=0 ... else */
   return(result);
}