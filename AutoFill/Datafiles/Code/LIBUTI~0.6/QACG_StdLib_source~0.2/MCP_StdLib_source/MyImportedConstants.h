#ifndef _IMPORTEDCONSTANTS_H_
#define _IMPORTEDCONSTANTS_H_

/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : Safran                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : ImportedConstants                                                                                      */
/* FILENAME : ImportedConstants.h                                                                                    */
/*-------------------------------------------------------------------------------------------------------------------*/

#if defined (FLOAT_32)
/* SEEEEEEEEMMMMMMM MMMMMMMMMMMMMMMM */
/* 0111111101111111 1111111111111111 = x7f7fffff = (1 + (1 - 2^-23)) × 2^127 */
/* The Maximum single float value is approximately 3.402823466 × 10^38 */
/*#define K_MAX_KCG_REAL (t_float)((2.0 - 2.0^-23.0) * 2.0^127.0 )*/
#define K_MAX_KCG_REAL (t_float)3.402823466e38

#elif defined (FLOAT_64)
/* SEEEEEEEEEEEMMMM MMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMM MMMMMMMMMMMMMMMM */
/* 0111111111101111 1111111111111111 1111111111111111 1111111111111111 = x7fefffffffffffff = (1 + (1 - 2^-52)) × 2^1023 */
/* The Maximum double float value is approximately 1.7976931348623157 × 10^308 */
/*#define K_MAX_KCG_REAL (t_float)((2.0 - 2.0^-52.0) * 2.0^1023.0 )*/
#define K_MAX_KCG_REAL (t_float)1.7976931348623157e308

#endif

#define K_Imin (t_float)-2147483648.0
#define K_Imax (t_float)2147483647.0
#define K_R_zero (t_float)0.0
#define K_R_0one (t_float)0.1
#define K_R_one (t_float)1.0
#define K_R_half (t_float)0.5
#define K_R_two (t_float)2.0
#define K_R_four (t_float)4.0
#define K_R_minone (t_float)-1.0

#define K_MIN_KCG_INT (t_int_32)-2147483648
#define K_MAX_KCG_INT (t_int_32)2147483647
#define K_I_zero (t_int_32)0
#define K_I_one (t_int_32)1
#define K_I_two (t_int_32)2
#define K_U_zero (t_uint_32)0
#define K_U_one (t_uint_32)1

#define K_Inv_Ln2 (t_float)0.69314718055994528622676398299518
#define K_Inv_Log2_10 (t_float)0.30102999566398119521373889472449

#endif /* _IMPORTEDCONSTANTS_H_ */
