/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** Command: kcg66.exe -config P:/OVSP_SW/CSC_OVSP/.SCADE/KCG/config.txt
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */
#ifndef _KCG_TYPES_H_
#define _KCG_TYPES_H_

#include "stddef.h"

#define KCG_MAPW_CPY

#include "./user_macros.h"

#ifndef kcg_char
#define kcg_char kcg_char
typedef char kcg_char;
#endif /* kcg_char */

#ifndef kcg_bool
#define kcg_bool kcg_bool
typedef unsigned char kcg_bool;
#endif /* kcg_bool */

#ifndef kcg_float32
#define kcg_float32 kcg_float32
typedef float kcg_float32;
#endif /* kcg_float32 */

#ifndef kcg_float64
#define kcg_float64 kcg_float64
typedef double kcg_float64;
#endif /* kcg_float64 */

#ifndef kcg_size
#define kcg_size kcg_size
typedef ptrdiff_t kcg_size;
#endif /* kcg_size */

#ifndef kcg_uint64
#define kcg_uint64 kcg_uint64
typedef unsigned long long kcg_uint64;
#endif /* kcg_uint64 */

#ifndef kcg_uint32
#define kcg_uint32 kcg_uint32
typedef unsigned long kcg_uint32;
#endif /* kcg_uint32 */

#ifndef kcg_uint16
#define kcg_uint16 kcg_uint16
typedef unsigned short kcg_uint16;
#endif /* kcg_uint16 */

#ifndef kcg_uint8
#define kcg_uint8 kcg_uint8
typedef unsigned char kcg_uint8;
#endif /* kcg_uint8 */

#ifndef kcg_int64
#define kcg_int64 kcg_int64
typedef signed long long kcg_int64;
#endif /* kcg_int64 */

#ifndef kcg_int32
#define kcg_int32 kcg_int32
typedef signed long kcg_int32;
#endif /* kcg_int32 */

#ifndef kcg_int16
#define kcg_int16 kcg_int16
typedef signed short kcg_int16;
#endif /* kcg_int16 */

#ifndef kcg_int8
#define kcg_int8 kcg_int8
typedef signed char kcg_int8;
#endif /* kcg_int8 */

#ifndef kcg_lit_float32
#define kcg_lit_float32(kcg_C1) ((kcg_float32) (kcg_C1))
#endif /* kcg_lit_float32 */

#ifndef kcg_lit_float64
#define kcg_lit_float64(kcg_C1) ((kcg_float64) (kcg_C1))
#endif /* kcg_lit_float64 */

#ifndef kcg_lit_size
#define kcg_lit_size(kcg_C1) ((kcg_size) (kcg_C1))
#endif /* kcg_lit_size */

#ifndef kcg_lit_uint64
#define kcg_lit_uint64(kcg_C1) ((kcg_uint64) (kcg_C1))
#endif /* kcg_lit_uint64 */

#ifndef kcg_lit_uint32
#define kcg_lit_uint32(kcg_C1) ((kcg_uint32) (kcg_C1))
#endif /* kcg_lit_uint32 */

#ifndef kcg_lit_uint16
#define kcg_lit_uint16(kcg_C1) ((kcg_uint16) (kcg_C1))
#endif /* kcg_lit_uint16 */

#ifndef kcg_lit_uint8
#define kcg_lit_uint8(kcg_C1) ((kcg_uint8) (kcg_C1))
#endif /* kcg_lit_uint8 */

#ifndef kcg_lit_int64
#define kcg_lit_int64(kcg_C1) ((kcg_int64) (kcg_C1))
#endif /* kcg_lit_int64 */

#ifndef kcg_lit_int32
#define kcg_lit_int32(kcg_C1) ((kcg_int32) (kcg_C1))
#endif /* kcg_lit_int32 */

#ifndef kcg_lit_int16
#define kcg_lit_int16(kcg_C1) ((kcg_int16) (kcg_C1))
#endif /* kcg_lit_int16 */

#ifndef kcg_lit_int8
#define kcg_lit_int8(kcg_C1) ((kcg_int8) (kcg_C1))
#endif /* kcg_lit_int8 */

#ifndef kcg_false
#define kcg_false ((kcg_bool) 0)
#endif /* kcg_false */

#ifndef kcg_true
#define kcg_true ((kcg_bool) 1)
#endif /* kcg_true */

#ifndef kcg_lsl_uint64
#define kcg_lsl_uint64(kcg_C1, kcg_C2)                                        \
  ((kcg_uint64) ((kcg_C1) << (kcg_C2)) & 0xffffffffffffffff)
#endif /* kcg_lsl_uint64 */

#ifndef kcg_lsl_uint32
#define kcg_lsl_uint32(kcg_C1, kcg_C2)                                        \
  ((kcg_uint32) ((kcg_C1) << (kcg_C2)) & 0xffffffff)
#endif /* kcg_lsl_uint32 */

#ifndef kcg_lsl_uint16
#define kcg_lsl_uint16(kcg_C1, kcg_C2)                                        \
  ((kcg_uint16) ((kcg_C1) << (kcg_C2)) & 0xffff)
#endif /* kcg_lsl_uint16 */

#ifndef kcg_lsl_uint8
#define kcg_lsl_uint8(kcg_C1, kcg_C2)                                         \
  ((kcg_uint8) ((kcg_C1) << (kcg_C2)) & 0xff)
#endif /* kcg_lsl_uint8 */

#ifndef kcg_lnot_uint64
#define kcg_lnot_uint64(kcg_C1) ((kcg_C1) ^ 0xffffffffffffffff)
#endif /* kcg_lnot_uint64 */

#ifndef kcg_lnot_uint32
#define kcg_lnot_uint32(kcg_C1) ((kcg_C1) ^ 0xffffffff)
#endif /* kcg_lnot_uint32 */

#ifndef kcg_lnot_uint16
#define kcg_lnot_uint16(kcg_C1) ((kcg_C1) ^ 0xffff)
#endif /* kcg_lnot_uint16 */

#ifndef kcg_lnot_uint8
#define kcg_lnot_uint8(kcg_C1) ((kcg_C1) ^ 0xff)
#endif /* kcg_lnot_uint8 */

#ifndef kcg_assign
#include "kcg_assign.h"
#endif /* kcg_assign */

#ifndef kcg_assign_struct
#define kcg_assign_struct kcg_assign
#endif /* kcg_assign_struct */

#ifndef kcg_assign_array
#define kcg_assign_array kcg_assign
#endif /* kcg_assign_array */

/* TE_Validity/ */
typedef enum kcg_tag_TE_Validity { E_Valid = 0, E_NotValid = 1 } TE_Validity;
/* TE_Test_Result/ */
typedef enum kcg_tag_TE_Test_Result {
  E_Test_Passed = 0,
  E_Test_Failed = 1,
  E_Fatal_Error = 2
} TE_Test_Result;
/* TE_Speed_Level/ */
typedef enum kcg_tag_TE_Speed_Level {
  E_NCD_Speed = 0,
  E_Low_Speed = 1,
  E_Running_Speed = 2,
  E_Overspeed = 3
} TE_Speed_Level;
/* TE_Request/ */
typedef enum kcg_tag_TE_Request {
  E_NotRequested = 0,
  E_Requested = 1
} TE_Request;
/* TE_OVSP_Side/ */
typedef enum kcg_tag_TE_OVSP_Side { E_OVSP_HS = 0, E_OVSP_LS = 1 } TE_OVSP_Side;
/* TE_OVSP_Mode/ */
typedef enum kcg_tag_TE_OVSP_Mode {
  E_Mode_Init = 0,
  E_Mode_Degraded = 1,
  E_Mode_Operational = 2,
  E_Mode_TriggTest = 3,
  E_Mode_Fail = 4
} TE_OVSP_Mode;
/* TE_OneSensor_Authorization/ */
typedef enum kcg_tag_TE_OneSensor_Authorization {
  E_NotAuthorized = 0,
  E_Authorized = 1
} TE_OneSensor_Authorization;
/* TE_NTL_Threshold_Type/ */
typedef enum kcg_tag_TE_NTL_Threshold_Type {
  E_NTL_Fixed_Thres = 0,
  E_NTL_Variable_Thres = 1
} TE_NTL_Threshold_Type;
/* TE_Inhibition/ */
typedef enum kcg_tag_TE_Inhibition {
  E_Not_Inhibited = 0,
  E_Inhibited = 1
} TE_Inhibition;
/* TE_Cmd_Status/ */
typedef enum kcg_tag_TE_Cmd_Status {
  E_Cmd_Off = 0,
  E_Cmd_On = 1
} TE_Cmd_Status;
/* TE_Answer/ */
typedef enum kcg_tag_TE_Answer { E_No = 0, E_Yes = 1 } TE_Answer;
typedef kcg_float32 array_float32_6[6];

typedef kcg_uint32 array_uint32_101[101];

#ifndef kcg_copy_array_float32_6
#define kcg_copy_array_float32_6(kcg_C1, kcg_C2)                              \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_float32_6)))
#endif /* kcg_copy_array_float32_6 */

#ifndef kcg_copy_array_uint32_101
#define kcg_copy_array_uint32_101(kcg_C1, kcg_C2)                             \
  (kcg_assign_array((kcg_C1), (kcg_C2), sizeof (array_uint32_101)))
#endif /* kcg_copy_array_uint32_101 */

#ifdef kcg_use_array_float32_6
#ifndef kcg_comp_array_float32_6
extern kcg_bool kcg_comp_array_float32_6(
  array_float32_6 *kcg_c1,
  array_float32_6 *kcg_c2);
#endif /* kcg_comp_array_float32_6 */
#endif /* kcg_use_array_float32_6 */

#ifdef kcg_use_array_uint32_101
#ifndef kcg_comp_array_uint32_101
extern kcg_bool kcg_comp_array_uint32_101(
  array_uint32_101 *kcg_c1,
  array_uint32_101 *kcg_c2);
#endif /* kcg_comp_array_uint32_101 */
#endif /* kcg_use_array_uint32_101 */

#endif /* _KCG_TYPES_H_ */
/* $********** SCADE Suite KCG 32-bit 6.6 (build i19) ***********
** kcg_types.h
** Generation date: 2022-11-16T17:38:35
*************************************************************$ */

