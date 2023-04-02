#ifndef USER_MACROS_H
#define USER_MACROS_H

#include "LIBMCP_Types.h"

#define kcg_assign(kcg_C1, kcg_C2, kcg_size)

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned long kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_char
#define kcg_char kcg_char
typedef int8_t kcg_char;
#endif /* kcg_char */

#ifndef  kcg_float32
#define kcg_float32 kcg_float32
typedef float32_t kcg_float32;
#endif /* kcg_float32 */

#ifndef kcg_float64
#define kcg_float64 kcg_float64
typedef float64_t kcg_float64;
#endif /* kcg_float64 */

#ifndef kcg_uint64
#define kcg_uint64 kcg_uint64
typedef uint64_t kcg_uint64;
#endif /* kcg_uint64 */

#ifndef kcg_uint32
#define kcg_uint32 kcg_uint32
typedef uint32_t kcg_uint32;
#endif /* kcg_uint32 */

#ifndef kcg_uint16
#define kcg_uint16 kcg_uint16
typedef uint16_t kcg_uint16;
#endif /* kcg_uint16 */

#ifndef kcg_uint8
#define kcg_uint8 kcg_uint8
typedef uint8_t kcg_uint8;
#endif /* kcg_uint8 */

#ifndef kcg_int64
#define kcg_int64 kcg_int64
typedef int64_t kcg_int64;
#endif /* kcg_int64 */

#ifndef kcg_int32
#define kcg_int32 kcg_int32
typedef int32_t kcg_int32;
#endif /* kcg_int32 */

#ifndef kcg_int16
#define kcg_int16 kcg_int16
typedef int16_t kcg_int16;
#endif /* kcg_int16 */

#ifndef kcg_int8
#define kcg_int8 kcg_int8
typedef int8_t kcg_int8;
#endif /* kcg_int8 */

#ifndef kcg_assume
#define kcg_assume(x)
#endif

#ifndef kcg_guarantee
#define kcg_guarantee(x)
#endif

#endif /*USER_MACROS_H*/