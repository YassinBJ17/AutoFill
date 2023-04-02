#ifndef _CONFIG_TYPES_H_
#define _CONFIG_TYPES_H_

/*-------------------------------------------------------------------------------------------------------------------*/
/* PROJECT : Unified Standard Library                                                                                */
/*-------------------------------------------------------------------------------------------------------------------*/
/* COMPANY : Safran                                                                                                  */
/*-------------------------------------------------------------------------------------------------------------------*/
/* CSU NAME : config_types                                                                                           */
/* FILENAME : config_types.h                                                                                         */
/*-------------------------------------------------------------------------------------------------------------------*/

#include "BaseType.h"
#include "MyImportedConstants.h"
#include "MyImportedFunctions.h"

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef t_boolean kcg_bool;
#endif /* kcg_bool */

#if defined (FLOAT_32)
   #ifndef kcg_float32
   #define kcg_float32 kcg_float32
   typedef float kcg_float32;
   #endif /* kcg_float32 */
#endif /* FLOAT_32 */

#if defined (FLOAT_64)
   #ifndef kcg_float64
   #define kcg_float64 kcg_float64
   typedef double kcg_float64;
   #endif /* kcg_float64 */
#endif /* FLOAT_64 */

#ifndef kcg_uint32
#define kcg_uint32 kcg_uint32
typedef t_uint_32 kcg_uint32;
#endif /* kcg_uint32 */

#ifndef kcg_uint16
#define kcg_uint16 kcg_uint16
typedef t_uint_16 kcg_uint16;
#endif /* kcg_uint16 */

#ifndef kcg_uint8
#define kcg_uint8 kcg_uint8
typedef t_uint_8 kcg_uint8;
#endif /* kcg_uint8 */

#ifndef kcg_int32
#define kcg_int32 kcg_int32
typedef t_int_32 kcg_int32;
#endif /* kcg_int32 */

#ifndef kcg_int16
#define kcg_int16 kcg_int16
typedef t_int_16 kcg_int16;
#endif /* kcg_int16 */

#ifndef kcg_int8
#define kcg_int8 kcg_int8
typedef t_int_8 kcg_int8;
#endif /* kcg_int8 */

#ifndef kcg_false
#define kcg_false ((t_boolean)(0ul))
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((t_boolean)(1ul))
#endif /* kcg_true */

#endif /* _CONFIG_TYPES_H_ */


