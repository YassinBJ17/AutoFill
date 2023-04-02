#ifndef _BASETYPE_H_
#define _BASETYPE_H_

/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : SAGEM                                                                                                   */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : BaseType                                                                                               */
/* FILENAME : BaseType.h                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

/*-----------------------*/
/*   TYPE DEFINITION     */
/*-----------------------*/
#ifndef T_INT_32
#define T_INT_32 T_INT_32
typedef long t_int_32;
#endif

#ifndef T_INT_16
#define T_INT_16 T_INT_16
typedef short t_int_16;
#endif

#ifndef T_INT_8
#define T_INT_8 T_INT_8
typedef char t_int_8;
#endif

#ifndef T_UINT_32
#define T_UINT_32 T_UINT_32
typedef unsigned long t_uint_32;
#endif

#ifndef T_UINT_16
#define T_UINT_16 T_UINT_16
typedef unsigned short t_uint_16;
#endif

#ifndef T_UINT_8
#define T_UINT_8 T_UINT_8
typedef unsigned char t_uint_8;
#endif

#ifndef T_BOOLEAN
#define T_BOOLEAN T_BOOLEAN
typedef unsigned long t_boolean;
#endif
/*-----------------------*/
/* TRUE FALSE DEFINITION */
/*-----------------------*/
#ifndef FALSE
#define FALSE ((t_boolean)(0ul))
#endif
#ifndef TRUE
#define TRUE  ((t_boolean)(1ul))
#endif

/* #if defined (FLOAT_64)
typedef double t_float;
#elif defined (FLOAT_32)
typedef float t_float;
#endif  */

#if defined (FLOAT_64)
#define kcg_float64 kcg_float64
typedef double kcg_float64;
#elif defined (FLOAT_32)
#define kcg_float32 kcg_float32
typedef float kcg_float32;
#endif /* t_float */

#if defined (FLOAT_64)
typedef kcg_float64 t_float;
#elif defined (FLOAT_32)
typedef kcg_float32 t_float;
#endif  


#ifndef kcg_copy_t_float
extern t_float kcg_copy_t_float(t_float *kcg_C1, t_float *kcg_C2);
#endif /* kcg_copy_T_Float_user */


#ifndef kcg_comp_t_float
extern t_boolean kcg_comp_t_float(t_float *kcg_c1, t_float *kcg_c2);
#endif /* kcg_comp_T_Float_user */

extern void t_float_init(t_float *kcg_c1);





#define kcg_lit_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_float64_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_size_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_uint64_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_uint32_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_uint16_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_uint8_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_int64_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_int32_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_int8_to_t_float(kcg_C1) ((t_float) (kcg_C1))
#define kcg_float32_to_t_float(kcg_C1) ((t_float) (kcg_C1))

#if defined (FLOAT_64)
#ifdef S_LITTLE_ENDIAN
typedef struct
{
   t_uint_32 low;
   t_uint_32 high;
} t_bitfield_ieee;
#else /* BIG ENDIAN */
typedef struct
{
   t_uint_32 high;
   t_uint_32 low;
} t_bitfield_ieee;
#endif /* S_LITTLE_ENDIAN */
#elif defined (FLOAT_32)
#ifdef S_LITTLE_ENDIAN
typedef struct
{
   t_uint_16 low;
   t_uint_16 high;
} t_bitfield_ieee;
#else /* BIG ENDIAN */
typedef struct
{
   t_uint_16 high;
   t_uint_16 low;
} t_bitfield_ieee;
#endif /* S_LITTLE_ENDIAN */
#endif

typedef union
{
   t_bitfield_ieee i;
   t_float d;
} TU_LIB_MATH_IEEE;

#endif /* _BASETYPE_H_ */
