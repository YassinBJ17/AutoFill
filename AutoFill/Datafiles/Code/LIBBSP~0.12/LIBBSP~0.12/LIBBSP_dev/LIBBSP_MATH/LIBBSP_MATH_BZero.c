/***********************************************************************************************************************
 *
 *                                                Sagem Defense Securite
 *                                                     SAFRAN Group
 *
 * _BEGIN_FILE_HEADER --------------------------------------------------------------------------------------------------
 *
 * File name  : LIB_MATH_BZero.c
 * CSC name   : LIB_MATH
 * 
 * Description: Clear structures.
 *
 * Configuration management identification:
 *    %full_name: sknNEXT#1/csrc/LIBBSP_MATH_BZero.c/3 %
 *    Creation  : gt077281 on Fri Jul 18 11:41:44 2010
 *
 * _END_FILE_HEADER ----------------------------------------------------------------------------------------------------
 *
 * LANGUAGE: C - Source file
 *
 * ---------------------------------------------------------------------------------------------------------------------
 * Copyright (c) 2009, SAGEM DS
 * SAGEM Defense Securite document. Reproduction and disclosure forbidden.
 **********************************************************************************************************************/

/* _BEGIN_INCLUDE ================ INCLUDE FILES =========================== */
#include "LIBBSP_MATH_BZero.h"
/* _END_INCLUDE ============================================================ */

///* _BEGIN_TYPE_CONSTANT ========== CONSTANTS FOR TYPES ===================== */
///* None                                                                      */
///* _END_TYPE_CONSTANT ====================================================== */
//
///* _BEGIN_TYPE ===================== TYPES ================================= */
///* None                                                                      */
///* _END_TYPE =============================================================== */
//
///* _BEGIN_CONSTANT =============== CONSTANTS =============================== */
///* None                                                                      */
///* _END_CONSTANT =========================================================== */
//
///* _BEGIN_STATIC_PROTO ==== STATIC FUNCTIONS DECLARATIONS ================== */
///* None                                                                      */
///* _END_STATIC_PROTO ======================================================= */
//
///* _BEGIN_VARIABLE ============= STATIC VARIABLES ========================== */
///* None                                                                      */
///* _END_VARIABLE =========================================================== */
//
///* _BEGIN_STATIC_FUNCTION ==== STATIC FUNCTIONS DEFINITIONS ================ */
///* None                                                                       */
///* _END_STATIC_FUNCTION ===================================================== */
//
///* _BEGIN_VARIABLE ============= GLOBAL VARIABLES =========================== */
///* None                                                                       */
///* _END_VARIABLE ============================================================ */
//
///* _BEGIN_MACRO =================== MACROS ================================= */
//
//
//
///* ============================================================================== */
///* Instead of using operator MODULO 2^(x) we can use BINARY AND 2^(x)-1           */
///* ============================================================================== */
//
//
//#define C_MODULO_8 ((tUInt32) 7)
//
//#define C_MODULO_4 ((tUInt32) 3)
//
//#define C_MODULO_32  ((tUInt32) 31)
///* Address aligned (modulo X) */
//#define C_ALIGNED (0) 
//
///* Literal */
//#define C_LITERAL_32 (32)
///* Literal */
//#define C_LITERAL_8  (8)
///* Literal */
//#define C_LITERAL_4  (4)
///* Literal */
//#define C_LITERAL_0  (0)
//
//
///* ============================================================================== */
///* NOTE:                                                                          */
///*     See LIB_MATH_MemCpy.c file for explanations about byte management macros   */
///*                                                                                */
///* ============================================================================== */
//
//
//
///* ============================================================================== */
///* 1 byte managment                                                               */
///* ============================================================================== */
//
///* 1 byte management (load 0) */
///* {{RELAX <ST.015> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_1_LOAD(l_c)		                                        \
//   ((l_c) = (tUInt8) C_LITERAL_0)
//
///* 1 byte management (store 0) */
//#define ZERO_1_STORE(pa_Dest, l_n, l_c)                                         \
//   (((tUInt8*) (pa_Dest))[(l_n)] = (tUInt8) (l_c))
//
///* Clear byte Dest[n] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_1(pa_Dest, l_n, l_c)                                               \
//{                                                                               \
//        ZERO_1_LOAD((l_c));                                                     \
//        ZERO_1_STORE((pa_Dest), (l_n), (l_c));                                  \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* ============================================================================== */
///* 2 bytes managment                                                              */
///* ============================================================================== */
//
///* 2 bytes management (load 0) */
//#define ZERO_2_LOAD(l_s)                                                        \
//    ((l_s) = (tUInt16) C_LITERAL_0)
//
///* 2 bytes management (store 0) */
//#define ZERO_2_STORE(pa_Dest, l_n, l_s)                                         \
//    (((tUInt16*) (pa_Dest))[(l_n)] = (tUInt16) (l_s))
//
///* Clear bytes Dest[n] .. Dest[n+1] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_2(pa_Dest, l_n, l_s)                                               \
//{                                                                               \
//        ZERO_2_LOAD((l_s));                                                     \
//        ZERO_2_STORE((pa_Dest), (l_n), (l_s));                                  \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* ============================================================================== */
///* 4 bytes managment                                                              */
///* ============================================================================== */
//
///* 4 bytes management (load 0) */
//#define ZERO_4_LOAD(l_u)                                                        \
//    ((l_u) = (tUInt32) C_LITERAL_0)
//
///* 4 bytes management (store 0) */
//#define ZERO_4_STORE(pa_Dest, l_n, l_u)                                         \
//    (((tUInt32*)(pa_Dest))[(l_n)] = (tUInt32) (l_u))
//
///* Clear bytes Dest[n] .. Dest[n+3] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_4(pa_Dest, l_n, l_u)                                               \
//{                                                                               \
//        ZERO_4_LOAD((l_u));                                                     \
//        ZERO_4_STORE((pa_Dest), (l_n), (l_u));                                  \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* 4 bytes management (load 0) */
//#define ZERO_4_LAST_LOAD(l_u)		                                        \
//    (ZERO_4_LOAD((l_u)))
//
///* Clear bytes Dest[n-3] .. Dest[n] */
//#define ZERO_4_LAST_STORE(pa_Dest, l_m, l_u)                                    \
//    (((tUInt32*)&(((tUInt8*)(pa_Dest))[(l_m) - C_LITERAL_4]))[0]=(tUInt32) (l_u))
//
//
//
///* ============================================================================== */
///* 8 bytes managment                                                              */
///* ============================================================================== */
//
///* 8 bytes management (load 0) */
//#define ZERO_8_ALIGNED_LOAD(l_d)                                                \
//    ((l_d) = (tFloat64) C_LITERAL_0)
//
///* 8 bytes management (store 0) */
//#define ZERO_8_ALIGNED_STORE(pa_Dest, l_n, l_d)                                 \
//    (((tFloat64*)(pa_Dest))[(l_n)] = (tFloat64) (l_d))
//
///* Clear bytes Dest[n] .. Dest[n+7] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_8(pa_Dest, l_n, l_u0, l_u1)                                        \
//{                                                                               \
//        ZERO_4_LOAD((l_u0));                                                    \
//        ZERO_4_LOAD((l_u1));                                                    \
//        ZERO_4_STORE((pa_Dest), (l_n) + 1, (l_u0));                             \
//        ZERO_4_STORE((pa_Dest), (l_n), (l_u1));                                 \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* Clear bytes Dest[n] .. Dest[n+7] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_8_ALIGNED(pa_Dest, l_i, l_d)                                       \
//{                                                                               \
//        ZERO_8_ALIGNED_LOAD((l_d));                                             \
//        ZERO_8_ALIGNED_STORE((pa_Dest), (l_i), (l_d));                          \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* Clear bytes Dest[n] .. Dest[n+7] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_8_ALIGNED_LAST(pa_Dest, l_m, l_d)                                  \
//{                                                                               \
//        ZERO_8_ALIGNED_LAST_LOAD((l_d));                                        \
//        ZERO_8_ALIGNED_LAST_STORE((pa_Dest), (l_m), (l_d));                     \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* 8 bytes management (load 0) */
//#define ZERO_8_ALIGNED_LAST_LOAD(l_d)	                                        \
//   ((l_d) = (tFloat64) C_LITERAL_0)
//
///* Clear bytes Dest[n-7] .. Dest[n] */
//#define ZERO_8_ALIGNED_LAST_STORE(pa_Dest, l_m, l_d)	                        \
//   (((tFloat64*)&(((tUInt8*)(pa_Dest))[(l_m) - C_LITERAL_8]))[0] = (tFloat64) (l_d))
//
//
//
//
///* ============================================================================== */
///* 32 bytes managment                                                             */
///* ============================================================================== */
//
///* Clear bytes Dest[n] .. Dest[n+31] */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define ZERO_32_ALIGNED(pa_Dest, l_d0, l_d1, l_d2, l_d3)                        \
//{                                                                               \
//        ZERO_8_ALIGNED_LOAD((l_d3));                                            \
//        ZERO_8_ALIGNED_LOAD((l_d2));                                            \
//        ZERO_8_ALIGNED_LOAD((l_d1));                                            \
//        ZERO_8_ALIGNED_LOAD((l_d0));                                            \
//        ZERO_8_ALIGNED_STORE((pa_Dest), 3, (l_d3));                             \
//        ZERO_8_ALIGNED_STORE((pa_Dest), 2, (l_d2));                             \
//        ZERO_8_ALIGNED_STORE((pa_Dest), 1, (l_d1));                             \
//        ZERO_8_ALIGNED_STORE((pa_Dest), 0, (l_d0));                             \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* _BEGIN_FUNCTION_HEADER --------------------------------------------------- */
///*                                                                            */
///* Function:   BZERO_CASE_MORE_64_BYTES                                       */
///* Description: Macro function which set to NULL memory areas on more than    */
///*              64 bytes.                                                     */
///* LLR: SDD-LIB-FNC-044                                                       */ 
///*                                                                            */
///* _END_FUNCTION_HEADER ----------------------------------------------------- */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
///* {{RELAX <PR.009> - Justification can be found in checklist SK-0000464380 */	
//#define BZERO_CASE_MORE_64_BYTES()                                              \
//{								                \
//                                                                                \
//    /* Clear the last bytes */                                                  \
//    if (C_ALIGNED != ((v_Nbytes) & C_MODULO_8))                                 \
//    {                                                                           \
//        ZERO_4_LAST_LOAD((l_u1));                                               \
//        ZERO_4_LAST_LOAD((l_u0));                                               \
//        ZERO_4_LAST_STORE((pa_Dest_8), (v_Nbytes), (l_u1));                     \
//        ZERO_4_LAST_STORE((pa_Dest_8), (v_Nbytes) - C_LITERAL_4, (l_u0));       \
//    }                                                                           \
//                                                                                \
//    /* Clear non aligned bytes */                                               \
//    (pa_Dest_32) = (tUInt8 *) (((tUInt32) (pa_Dest_8)) & (~C_MODULO_32));       \
//    (al_32) = ((tUInt32) (pa_Dest_8)) - ((tUInt32) (pa_Dest_32));               \
//    (al_32) = C_LITERAL_32 - (al_32);                                           \
//    (l_t) = (al_32) / C_LITERAL_8;                                              \
//    switch ((l_t))                                                              \
//    {                                                                           \
//        case 4:                                                                 \
//            ZERO_8_ALIGNED((pa_Dest_8), 3, (l_d0));                             \
//            ZERO_8_ALIGNED((pa_Dest_8), 2, (l_d1));                             \
//            ZERO_8_ALIGNED((pa_Dest_8), 1, (l_d2));                             \
//            ZERO_8_ALIGNED((pa_Dest_8), 0, (l_d3));                             \
//        break;                                                                  \
//        case 3:                                                                 \
//            ZERO_8_ALIGNED((pa_Dest_8), 2, (l_d1));                             \
//            ZERO_8_ALIGNED((pa_Dest_8), 1, (l_d2));                             \
//            ZERO_8_ALIGNED((pa_Dest_8), 0, (l_d3));                             \
//        break;                                                                  \
//        case 2:                                                                 \
//            ZERO_8_ALIGNED((pa_Dest_8), 1, (l_d2));                             \
//            ZERO_8_ALIGNED((pa_Dest_8), 0, (l_d3));                             \
//        break;                                                                  \
//        case 1:                                                                 \
//            ZERO_8_ALIGNED((pa_Dest_8), 0, (l_d3));                             \
//        break;                                                                  \
//        default:                                                                \
//            /* do nothing */                                                    \
//        break;                                                                  \
//    }                                                                           \
//                                                                                \
//    /* Set to NULL memory area by block (32 bytes) */                           \
//    (l_t) = ((v_Nbytes) - (al_32)) / C_LITERAL_32;                              \
//    for ((l_i) = 0; (l_i) < (l_t); (l_i)++)                                     \
//    {                                                                           \
//        pa_Dest_32 = pa_Dest_32 + C_LITERAL_32;                                 \
//        ZERO_32_ALIGNED(pa_Dest_32, (l_d0), (l_d1), (l_d2), (l_d3));            \
//    }                                                                           \
//    (pa_Dest_32) = (pa_Dest_32) + C_LITERAL_32;                                 \
//                                                                                \
//    /* Finish the last line by 8 bytes blocs */                                 \
//    (l_t) = ((v_Nbytes) - ((C_LITERAL_32 * (l_i)) + (al_32))) / C_LITERAL_8;    \
//    switch ((l_t))                                                              \
//    {                                                                           \
//        case 3:                                                                 \
//            ZERO_8_ALIGNED(pa_Dest_32, 2, (l_d0));                              \
//            ZERO_8_ALIGNED(pa_Dest_32, 1, (l_d1));                              \
//            ZERO_8_ALIGNED(pa_Dest_32, 0, (l_d2));                              \
//        break;                                                                  \
//        case 2:                                                                 \
//            ZERO_8_ALIGNED(pa_Dest_32, 1, (l_d1));                              \
//            ZERO_8_ALIGNED(pa_Dest_32, 0, (l_d2));                              \
//        break;                                                                  \
//        case 1:                                                                 \
//            ZERO_8_ALIGNED(pa_Dest_32, 0, (l_d2));                              \
//        break;                                                                  \
//        default:                                                                \
//            /* do nothing */                                                    \
//        break;                                                                  \
//    }                                                                           \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* _BEGIN_FUNCTION_HEADER --------------------------------------------------- */
///*                                                                            */
///* Function:   BZERO_CASE_MORE_16_BYTES                                       */
///* Description: Macro function which set to NULL memory areas on more than    */
///*              16 bytes.                                                     */
///* LLR: SDD-LIB-FNC-045                                                       */ 
///*                                                                            */
///* _END_FUNCTION_HEADER ----------------------------------------------------- */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define BZERO_CASE_MORE_16_BYTES()                                              \
//{                                                                               \
//    /* Clear the last bytes */                                                  \
//    if (C_ALIGNED == ((v_Nbytes) & C_MODULO_4))                                 \
//    {                                                                           \
//        ZERO_8_ALIGNED_LAST((pa_Dest_8), (v_Nbytes), (l_d0));                   \
//    }                                                                           \
//    else                                                                        \
//    {                                                                           \
//        ZERO_4_LAST_LOAD((l_u1));                                               \
//        ZERO_4_LAST_LOAD((l_u0));                                               \
//        ZERO_4_LAST_STORE((pa_Dest_8), (v_Nbytes), (l_u1));                     \
//        ZERO_4_LAST_STORE((pa_Dest_8), (v_Nbytes) - C_LITERAL_4, (l_u0));       \
//    }                                                                           \
//                                                                                \
//    /* Set to NULL memory area by block */                                      \
//    (l_t) = (v_Nbytes) / C_LITERAL_8;                                           \
//    for ((l_i) = 0; (l_i) < (l_t); (l_i)++)                                     \
//    {                                                                           \
//        ZERO_8_ALIGNED((pa_Dest_8), (l_i), (l_d0));                             \
//    }                                                                           \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* _BEGIN_FUNCTION_HEADER --------------------------------------------------- */
///*                                                                            */
///* Function:   BZERO_CASE_LESS_16_BYTES                                       */
///* Description: Macro function which set to NULL memory areas on less than    */
///*              or equal to 16 bytes.                                         */
///* LLR: SDD-LIB-FNC-046                                                       */ 
///*                                                                            */
///* _END_FUNCTION_HEADER ----------------------------------------------------- */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define BZERO_CASE_LESS_16_BYTES()                                              \
//{                                                                               \
//    switch ((v_Nbytes))                                                         \
//    {                                                                           \
//        case 16:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_8_ALIGNED_LOAD((l_d1));                                        \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 1, (l_d0));/* byte num 8 --> 15 */\
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d1));/* byte num 0 --> 7  */\
//        break;                                                                  \
//        case 1:                                                                 \
//            ZERO_1((pa_Dest_8), 0, (l_c0));                                     \
//        break;                                                                  \
//        case 2:                                                                 \
//            ZERO_2((pa_Dest_8), 0, (l_s0));                                     \
//        break;                                                                  \
//        case 3:                                                                 \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_2_STORE((pa_Dest_8), 0, (l_s0)); /* byte num 0 --> 1 */        \
//            ZERO_1_STORE((pa_Dest_8), 2, (l_c0)); /* byte num 3       */        \
//        break;                                                                  \
//        case 4:                                                                 \
//            ZERO_4((pa_Dest_8), 0, (l_u0));                                     \
//        break;                                                                  \
//        case 5:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_4_STORE((pa_Dest_8), 0, (l_u0));                               \
//            ZERO_1_STORE((pa_Dest_8), 4, (l_c0)); /* byte num 5 */              \
//        break;                                                                  \
//        case 6:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_4_STORE((pa_Dest_8), 0, (l_u0)); /* byte num 0 --> 3 */        \
//            ZERO_2_STORE((pa_Dest_8), 2, (l_s0)); /* byte num 4, 5    */        \
//        break;                                                                  \
//        case 7:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LAST_LOAD((l_u1));                                           \
//            ZERO_4_STORE((pa_Dest_8), 0, (l_u0)); /* byte num 0, 1, 2, 3 */     \
//            ZERO_4_LAST_STORE((pa_Dest_8), 7, (l_u1)); /* byte num 3 -> 6 */    \
//        break;                                                                  \
//        case 8:                                                                 \
//            ZERO_8_ALIGNED((pa_Dest_8), 0, (l_d0));                             \
//        break;                                                                  \
//        case 9:                                                                 \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0));/* byte num 0 --> 7 */ \
//            ZERO_1_STORE((pa_Dest_8), 8, (l_c0)); /* byte num 8              */ \
//        break;                                                                  \
//        case 10:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0));/* byte num 0 --> 7 */ \
//            ZERO_2_STORE((pa_Dest_8), 4, (l_s0)); /* byte num 8, 9           */ \
//        break;                                                                  \
//        case 11:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0)); /* byte num 0, 1, 2, 3, 4, 5, 6, 7 */  \
//            ZERO_4_LAST_LOAD((l_u0)); /* byte num 7, 8, 9, 10,        */        \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0));/* byte num 0 --> 7 */ \
//            ZERO_4_LAST_STORE((pa_Dest_8), 11, (l_u0)); /* byte num 7 -> 10*/   \
//        break;                                                                  \
//        case 12:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0)); /* byte num 0 --> 7*/ \
//            ZERO_4_STORE((pa_Dest_8), 2, (l_u0)); /* byte num 8, 9, 10, 11  */  \
//        break;                                                                  \
//        case 13:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0)); /* byte num 0 -> 7*/  \
//            ZERO_4_STORE((pa_Dest_8), 2, (l_u0)); /* byte num 8, 9, 10, 11  */  \
//            ZERO_1_STORE((pa_Dest_8), 12, (l_c0)); /* byte num 12           */  \
//        break;                                                                  \
//        case 14:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0)); /* byte num 0 --> 7*/ \
//            ZERO_4_STORE((pa_Dest_8), 2, (l_u0)); /* byte num 8, 9, 10, 11   */ \
//            ZERO_2_STORE((pa_Dest_8), 6, (l_s0)); /* byte num 12, 13         */ \
//        break;                                                                  \
//        case 15:                                                                \
//            ZERO_8_ALIGNED_LOAD((l_d0));                                        \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LAST_LOAD((l_u1));                                           \
//            ZERO_8_ALIGNED_STORE((pa_Dest_8), 0, (l_d0)); /* byte num 0 -> 7 */ \
//            ZERO_4_STORE((pa_Dest_8), 2, (l_u0)); /* byte num 8, 9, 10, 11   */ \
//            ZERO_4_LAST_STORE((pa_Dest_8), 15, (l_u1)); /* byte num 11 -> 14 */ \
//        break;                                                                  \
//        default:                                                                \
//        break;                                                                  \
//    }                                                                           \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
///* _BEGIN_FUNCTION_HEADER --------------------------------------------------- */
///*                                                                            */
///* Function:   BZERO_CASE_ALIGN_4_BYTES                                       */
///* Description: Macro function which set to NULL memory areas that are only   */
///*              aligned 4 bytes.                                              */
///* LLR: SDD-LIB-FNC-047                                                       */ 
///*                                                                            */
///* _END_FUNCTION_HEADER ----------------------------------------------------- */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define BZERO_CASE_ALIGN_4_BYTES()                                              \
//{                                                                               \
//    /* to align pa_Dest on 4 bytes */                                           \
//    ZERO_4((pa_Dest), 0, (l_u2));                                               \
//    (pa_Dest_8) = (pa_Dest_8) + C_LITERAL_4;                                    \
//    (l_nb) = (v_Nbytes) - C_LITERAL_4;                                          \
//                                                                                \
//    /* Set to NULL memory area by block */                                      \
//    (l_t) = (l_nb) / C_LITERAL_32;                                              \
//    for ((l_i) = 0; (l_i) < (l_t); (l_i)++)                                     \
//    {                                                                           \
//        ZERO_32_ALIGNED((pa_Dest_8), (l_d0), (l_d1), (l_d2), (l_d3));           \
//        (pa_Dest_8) = (pa_Dest_8) + C_LITERAL_32;                               \
//    }                                                                           \
//                                                                                \
//    /* Set to NULL memory area by block */                                      \
//    (l_t) = ((l_nb) - (C_LITERAL_32 * (l_i))) / C_LITERAL_8;                    \
//    for ((l_i) = 0; (l_i) < (l_t); (l_i)++)                                     \
//    {                                                                           \
//        ZERO_8_ALIGNED((pa_Dest_8), (l_i), (l_d0));                             \
//    }                                                                           \
//                                                                                \
//    /* Finish the last line by 4B blocs */                                      \
//    if (C_ALIGNED != ((l_nb) & C_MODULO_8))                                     \
//    {                                                                           \
//        ZERO_4_LAST_LOAD((l_u1));                                               \
//        ZERO_4_LAST_LOAD((l_u0));                                               \
//        ZERO_4_LAST_STORE((pa_Dest), (v_Nbytes), (l_u1));                       \
//        ZERO_4_LAST_STORE((pa_Dest), (v_Nbytes) - C_LITERAL_4, (l_u0));         \
//    }                                                                           \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//
//
///* _BEGIN_FUNCTION_HEADER --------------------------------------------------- */
///*                                                                            */
///* Function:   BZERO_CASE_NO_ALIGN                                            */
///* Description: Macro function which set to NULL memory areas that are not    */
///*              aligned.                                                      */
///* LLR: SDD-LIB-FNC-048                                                       */ 
///*                                                                            */
///* _END_FUNCTION_HEADER ----------------------------------------------------- */
///* {{RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
//#define BZERO_CASE_NO_ALIGN()                                                   \
//{                                                                               \
//    switch ((v_Nbytes))                                                         \
//    {                                                                           \
//        case 0:                                                                 \
//        break;                                                                  \
//        case 1:                                                                 \
//            ZERO_1((pa_Dest), 0, (l_c0));                                       \
//        break;                                                                  \
//        case 2:                                                                 \
//            ZERO_2((pa_Dest), 0, (l_s0));                                       \
//        break;                                                                  \
//        case 3:                                                                 \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_2_STORE((pa_Dest), 0, (l_s0)); /* byte num 0 num 1 */          \
//            ZERO_1_STORE((pa_Dest), 2, (l_c0)); /* byte num 3     */            \
//        break;                                                                  \
//        case 4:                                                                 \
//            ZERO_4((pa_Dest), 0, (l_u0));                                       \
//        break;                                                                  \
//        case 5:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0));                                 \
//            ZERO_1_STORE((pa_Dest), 4, (l_c0)); /* byte num 5 */                \
//        break;                                                                  \
//        case 6:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3 */       \
//            ZERO_2_STORE((pa_Dest), 2, (l_s0)); /* byte num 4, 5     */         \
//        break;                                                                  \
//        case 7:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LAST_LOAD((l_u1));                                           \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3 */       \
//            ZERO_4_LAST_STORE((pa_Dest), 7, (l_u1)); /* byte num 3, 4, 5, 6 */  \
//        break;                                                                  \
//        case 8:                                                                 \
//            ZERO_8((pa_Dest), 0, (l_u0), (l_u1));                               \
//        break;                                                                  \
//        case 9:                                                                 \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3 */       \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7 */       \
//            ZERO_1_STORE((pa_Dest), 8, (l_c0)); /* byte num 8       */          \
//        break;                                                                  \
//        case 10:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3 */       \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7 */       \
//            ZERO_2_STORE((pa_Dest), 4, (l_s0)); /* byte num 8, 9     */         \
//        break;                                                                  \
//        case 11:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_4_LAST_LOAD((l_u2));                                           \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3  */      \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7  */      \
//            ZERO_4_LAST_STORE((pa_Dest), 11, (l_u2)); /* byte num 7 -> 10 */    \
//        break;                                                                  \
//        case 12:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_4_LOAD((l_u2));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3   */     \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7   */     \
//            ZERO_4_STORE((pa_Dest), 2, (l_u2)); /* byte num 8, 9, 10, 11 */     \
//        break;                                                                  \
//        case 13:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_4_LOAD((l_u2));                                                \
//            ZERO_1_LOAD((l_c0));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3   */     \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7   */     \
//            ZERO_4_STORE((pa_Dest), 2, (l_u2)); /* byte num 8, 9, 10, 11 */     \
//            ZERO_1_STORE((pa_Dest), 12, (l_c0)); /* byte num 12        */       \
//        break;                                                                  \
//        case 14:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_4_LOAD((l_u2));                                                \
//            ZERO_2_LOAD((l_s0));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3   */     \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7   */     \
//            ZERO_4_STORE((pa_Dest), 2, (l_u2)); /* byte num 8, 9, 10, 11 */     \
//            ZERO_2_STORE((pa_Dest), 6, (l_s0)); /* byte num 12, 13     */       \
//        break;                                                                  \
//        case 15:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_4_LOAD((l_u2));                                                \
//            ZERO_4_LAST_LOAD((l_u3));                                           \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3     */   \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7     */   \
//            ZERO_4_STORE((pa_Dest), 2, (l_u2)); /* byte num 8, 9, 10, 11   */   \
//            ZERO_4_LAST_STORE((pa_Dest), 15, (l_u3)); /* byte num 11 -> 14 */   \
//        break;                                                                  \
//        case 16:                                                                \
//            ZERO_4_LOAD((l_u0));                                                \
//            ZERO_4_LOAD((l_u1));                                                \
//            ZERO_4_LOAD((l_u2));                                                \
//            ZERO_4_LOAD((l_u3));                                                \
//            ZERO_4_STORE((pa_Dest), 0, (l_u0)); /* byte num 0, 1, 2, 3     */   \
//            ZERO_4_STORE((pa_Dest), 1, (l_u1)); /* byte num 4, 5, 6, 7     */   \
//            ZERO_4_STORE((pa_Dest), 2, (l_u2)); /* byte num 8, 9, 10, 11   */   \
//            ZERO_4_STORE((pa_Dest), 3, (l_u3)); /* byte num 12, 13, 14, s15 */  \
//        break;                                                                  \
//        default:                                                                \
//            /* (v_Nbytes) > 16 */                                               \
//            (l_t) = (v_Nbytes) / C_LITERAL_4;                                   \
//            for ((l_i) = 0; (l_i) < (l_t); (l_i)++)                             \
//            {                                                                   \
//                ZERO_4((pa_Dest), (l_i), (l_u0));                               \
//            }                                                                   \
//            ZERO_4_LAST_LOAD((l_u1));                                           \
//            ZERO_4_LAST_STORE((pa_Dest), (v_Nbytes), (l_u1));/* byte num 4 --> 1 */  \
//        break;                                                                  \
//    }                                                                           \
//}
///* }}RELAX <ST.029_b> - Justification can be found in checklist SK-0000464380 */
///* }}RELAX <PR.009> - Justification can be found in checklist SK-0000464380 */ 
///* }}RELAX <ST.015> - Justification can be found in checklist SK-0000464380 */
//
///* _END_MACRO ============================================================== */
//
/* _BEGIN_EXTERN_FUNCTION ========EXTERN FUNCTIONS DEFINITIONS ============== */

/* _BEGIN_FUNCTION_HEADER -------------------------------------------------- */
/* Function:   LIBBSP_MATH_BZero                                                */
/* Description: Clear v_Nbytes bytes from the object pointed by pa_Dest.     */
/* Comments:                                                                 */
/*                                                                           */
/*                                                                           */
/* Tracability: SRS-LIB-FNC-001, SRS-LIB-ITF-119, SRS-LIB-FNC-120            */
/*              SRS-LIB-POR-101, SRS-LIB-POR-104, SRS-LIB-SAF-103            */
/*              SRS-LIB-PRF-123                                              */
/* LRR: SDD-LIB-FNC-024                                                      */ 
/* Activation:                                                               */
/* Frequency:                                                                */
/* Initialization:                                                           */
/*                                                                           */
/* Input: pa_Dst: address of object to clear                                 */
/*        v_Nbytes : number of bytes to clear                                */
/* Output: none                                                              */
/* Modified global: none                                                     */
/* Return: NA                                                                */
/* _END_FUNCTION_HEADER ---------------------------------------------------- */
void LIBBSP_MATH_BZero(void *  /* IN/OUT */     const Dest, /* %RELAX<SYNCHRONe_C_Code_8.18> Output is used */
                       const uint32_t /* IN */        N_Bytes)
{
   uint32_t v_i;
   for ( v_i = 0ul; v_i < N_Bytes; v_i++ )
   {
	  /*{{RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_11.1>*/
	  /*Pointer conversion because to initialize Dest to (uint8_t)0*/
      *(((uint8_t*)(Dest)) + v_i ) = (uint8_t)0;
	  /*}}RELAX<SYNCHRONe_C_Code_17.4,SYNCHRONe_C_Code_11.1> */
   }
}
/* {{RELAX<SP.004> - Justification can be found in checklist SK-0000464380 */
/* {{RELAX<SP.100> - Justification can be found in checklist SK-0000464380 */
/* {{RELAX<DA.013, SP.008> - Justification can be found in checklist SK-0000464380 */
/* >RELAX <SP.006> - Justification can be found in checklist SK-0000464380 */
//void LIB_MATH_BZero(      void   /* IN */  *const pa_Dest,
///* }}RELAX<DA.013, SP.008> - Justification can be found in checklist SK-0000464380 */
//                    const tUInt32 /* IN */         v_Nbytes)
//{
//    /*local data declared by descending order,  should be allocated in register */
//    tFloat64 l_d0;
//    tFloat64 l_d1;
//    tFloat64 l_d2;
//    tFloat64 l_d3;
//    tUInt32 l_i;
//    tUInt32 l_u0;
//    tUInt32 l_u1;
//    tUInt32 l_u2;
//    tUInt32 l_u3;
//    tUInt32 l_t;
//    tUInt32 al_32;
//    tUInt32 l_nb;
//    /* {{RELAX<DA.013> - Justification can be found in checklist SK-0000464380 */
//    tUInt8 *pa_Dest_8;
//    tUInt8 *pa_Dest_32;
//    /* }}RELAX<DA.013> - Justification can be found in checklist SK-0000464380 */
//    tUInt16 l_s0;
//    tUInt8 l_c0;
//
//    /* Init */
//    /* Local data declared by descending order,  should be allocated in register */
//
//    pa_Dest_8 = (tUInt8 *) pa_Dest;
//
//    /* Address alignement on 8 bytes (modulo 8) */
//    /* {{RELAX<DA.008> - Justification can be found in checklist SK-0000464380 */
//    if (C_ALIGNED == (((tUInt32) pa_Dest) & C_MODULO_8))
//    {
//    	/* >RELAX <DA.002> - Justification can be found in checklist SK-0000464380 */
//        if (v_Nbytes > 64)
//        {
//	    /* {{RELAX<PR.007> - Justification can be found in checklist SK-0000464380 */
//            BZERO_CASE_MORE_64_BYTES();
//	    /* }}RELAX<PR.007> - Justification can be found in checklist SK-0000464380 */
//        }
//        else
//        {
//	    /* >RELAX <DA.002> - Justification can be found in checklist SK-0000464380 */
//            if (v_Nbytes > 16)
//            {
//	    	/* {{RELAX<PR.007> - Justification can be found in checklist SK-0000464380 */
//                BZERO_CASE_MORE_16_BYTES();
//		/* }}RELAX<PR.007> - Justification can be found in checklist SK-0000464380 */
//            }
//            else /* v_Nbytes <= 16 */
//            {
//	    	/* {{RELAX<ST.001, PR.007> - Justification can be found in checklist SK-0000464380 */
//                BZERO_CASE_LESS_16_BYTES();
//		/* }}RELAX<ST.001, PR.007> - Justification can be found in checklist SK-0000464380 */
//            }
//        } 
//    }
//    else
//    {
//        /* Address alignement on 4 bytes (modulo 4)  */
//        if ((C_ALIGNED == (((tUInt32) pa_Dest) & C_MODULO_4)) &&
//	    /* >RELAX <DA.002> - Justification can be found in checklist SK-0000464380 */
//            (v_Nbytes >= 8))
//        {
//	    /* {{RELAX<PR.007> - Justification can be found in checklist SK-0000464380 */
//            BZERO_CASE_ALIGN_4_BYTES();
//	    /* }}RELAX<PR.007> - Justification can be found in checklist SK-0000464380 */
//	    /* }}RELAX<DA.008> - Justification can be found in checklist SK-0000464380 */
//        }
//        else
//        {
//            /* For small size on all alignement */
//	    /* {{RELAX<ST.001, PR.007> - Justification can be found in checklist SK-0000464380 */
//            BZERO_CASE_NO_ALIGN();
//	    /* }}RELAX<ST.001, PR.007> - Justification can be found in checklist SK-0000464380 */
//        }
//    }
//}
/* }}RELAX<SP.004> - Justification can be found in checklist SK-0000464380 */
/* }}RELAX<SP.100> - Justification can be found in checklist SK-0000464380 */
