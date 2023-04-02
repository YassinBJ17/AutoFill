/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#ifndef AST_MPC5777M_XT_SOURCE_DEFS_H_
#define AST_MPC5777M_XT_SOURCE_DEFS_H_

# include <kstdint.h>

/* Bit operations */
# define __TO_BITVALUE(V, O, S, T) ( ( ( (T) (V) ) & ( (1 << (S)) - 1 ) ) << (O))
# define __AS_BITVALUE(V, O, S, T) ( (T) ( (V) >> (O) ) & ( (1 << (S)) - 1 ) )
# define __CL_BITVALUE(V, O, S, T) ( ( (T) (V) ) & ~( ( (1 << (S)) - 1 ) << (O) ) )

/**
 * Watchdog register types and operations.
 */
typedef volatile t_ast_uint32 SWT_SR_t;
typedef volatile t_ast_uint32 SWT_CR_t;
typedef volatile t_ast_uint32 SWT_TO_t;
typedef volatile t_ast_uint32 SWT_IR_t;

/* Watchdog 0 registers */
# define SWT_0 ((volatile t_ast_uint8 *) (0xFC050000UL))
# define SWT_0_CR               (*((volatile SWT_CR_t *) (SWT_0 + 0x0)))
# define SWT_0_IR               (*((volatile SWT_IR_t *) (SWT_0 + 0x4)))
# define SWT_0_TO               (*((volatile SWT_TO_t *) (SWT_0 + 0x8)))
# define SWT_0_SR               (*((volatile SWT_SR_t *) (SWT_0 + 0x10)))

/* Status registers manipulation */
# define SWT_CR_MAP0(X)               __TO_BITVALUE(X, 31, 1, t_ast_uint32)
# define SWT_CR_MAP0_GET(V)           __AS_BITVALUE(V, 31, 1, t_ast_uint32)
# define SWT_CR_MAP0_SET(V,X)        (__CL_BITVALUE(V, 31, 1, t_ast_uint32) | __TO_BITVALUE(X, 31, 1, t_ast_uint32))
# define SWT_CR_MAP1(X)               __TO_BITVALUE(X, 30, 1, t_ast_uint32)
# define SWT_CR_MAP1_GET(V)           __AS_BITVALUE(V, 30, 1, t_ast_uint32)
# define SWT_CR_MAP1_SET(V,X)        (__CL_BITVALUE(V, 30, 1, t_ast_uint32) | __TO_BITVALUE(X, 30, 1, t_ast_uint32))
# define SWT_CR_MAP2(X)               __TO_BITVALUE(X, 29, 1, t_ast_uint32)
# define SWT_CR_MAP2_GET(V)           __AS_BITVALUE(V, 29, 1, t_ast_uint32)
# define SWT_CR_MAP2_SET(V,X)        (__CL_BITVALUE(V, 29, 1, t_ast_uint32) | __TO_BITVALUE(X, 29, 1, t_ast_uint32))
# define SWT_CR_MAP3(X)               __TO_BITVALUE(X, 28, 1, t_ast_uint32)
# define SWT_CR_MAP3_GET(V)           __AS_BITVALUE(V, 28, 1, t_ast_uint32)
# define SWT_CR_MAP3_SET(V,X)        (__CL_BITVALUE(V, 28, 1, t_ast_uint32) | __TO_BITVALUE(X, 28, 1, t_ast_uint32))
# define SWT_CR_MAP4(X)               __TO_BITVALUE(X, 27, 1, t_ast_uint32)
# define SWT_CR_MAP4_GET(V)           __AS_BITVALUE(V, 27, 1, t_ast_uint32)
# define SWT_CR_MAP4_SET(V,X)        (__CL_BITVALUE(V, 27, 1, t_ast_uint32) | __TO_BITVALUE(X, 27, 1, t_ast_uint32))
# define SWT_CR_MAP5(X)               __TO_BITVALUE(X, 26, 1, t_ast_uint32)
# define SWT_CR_MAP5_GET(V)           __AS_BITVALUE(V, 26, 1, t_ast_uint32)
# define SWT_CR_MAP5_SET(V,X)        (__CL_BITVALUE(V, 26, 1, t_ast_uint32) | __TO_BITVALUE(X, 26, 1, t_ast_uint32))
# define SWT_CR_MAP6(X)               __TO_BITVALUE(X, 25, 1, t_ast_uint32)
# define SWT_CR_MAP6_GET(V)           __AS_BITVALUE(V, 25, 1, t_ast_uint32)
# define SWT_CR_MAP6_SET(V,X)        (__CL_BITVALUE(V, 25, 1, t_ast_uint32) | __TO_BITVALUE(X, 25, 1, t_ast_uint32))
# define SWT_CR_MAP7(X)               __TO_BITVALUE(X, 24, 1, t_ast_uint32)
# define SWT_CR_MAP7_GET(V)           __AS_BITVALUE(V, 24, 1, t_ast_uint32)
# define SWT_CR_MAP7_SET(V,X)        (__CL_BITVALUE(V, 24, 1, t_ast_uint32) | __TO_BITVALUE(X, 24, 1, t_ast_uint32))
# define SWT_CR_SMD(X)                __TO_BITVALUE(X, 9, 2, t_ast_uint32)
# define SWT_CR_SMD_GET(V)            __AS_BITVALUE(V, 9, 2, t_ast_uint32)
# define SWT_CR_SMD_SET(V,X)         (__CL_BITVALUE(V, 9, 2, t_ast_uint32) | __TO_BITVALUE(X, 9, 2, t_ast_uint32))
# define SWT_CR_RIA(X)                __TO_BITVALUE(X, 8, 1, t_ast_uint32)
# define SWT_CR_RIA_GET(V)            __AS_BITVALUE(V, 8, 1, t_ast_uint32)
# define SWT_CR_RIA_SET(V,X)         (__CL_BITVALUE(V, 8, 1, t_ast_uint32) | __TO_BITVALUE(X, 8, 1, t_ast_uint32))
# define SWT_CR_WND(X)                __TO_BITVALUE(X, 7, 1, t_ast_uint32)
# define SWT_CR_WND_GET(V)            __AS_BITVALUE(V, 7, 1, t_ast_uint32)
# define SWT_CR_WND_SET(V,X)         (__CL_BITVALUE(V, 7, 1, t_ast_uint32) | __TO_BITVALUE(X, 7, 1, t_ast_uint32))
# define SWT_CR_ITR(X)                __TO_BITVALUE(X, 6, 1, t_ast_uint32)
# define SWT_CR_ITR_GET(V)            __AS_BITVALUE(V, 6, 1, t_ast_uint32)
# define SWT_CR_ITR_SET(V,X)         (__CL_BITVALUE(V, 6, 1, t_ast_uint32) | __TO_BITVALUE(X, 6, 1, t_ast_uint32))
# define SWT_CR_HLK(X)                __TO_BITVALUE(X, 5, 1, t_ast_uint32)
# define SWT_CR_HLK_GET(V)            __AS_BITVALUE(V, 5, 1, t_ast_uint32)
# define SWT_CR_HLK_SET(V,X)         (__CL_BITVALUE(V, 5, 1, t_ast_uint32) | __TO_BITVALUE(X, 5, 1, t_ast_uint32))
# define SWT_CR_SLK(X)                __TO_BITVALUE(X, 4, 1, t_ast_uint32)
# define SWT_CR_SLK_GET(V)            __AS_BITVALUE(V, 4, 1, t_ast_uint32)
# define SWT_CR_SLK_SET(V,X)         (__CL_BITVALUE(V, 4, 1, t_ast_uint32) | __TO_BITVALUE(X, 4, 1, t_ast_uint32))
# define SWT_CR_STP(X)                __TO_BITVALUE(X, 2, 1, t_ast_uint32)
# define SWT_CR_STP_GET(V)            __AS_BITVALUE(V, 2, 1, t_ast_uint32)
# define SWT_CR_STP_SET(V,X)         (__CL_BITVALUE(V, 2, 1, t_ast_uint32) | __TO_BITVALUE(X, 2, 1, t_ast_uint32))
# define SWT_CR_FRZ(X)                __TO_BITVALUE(X, 1, 1, t_ast_uint32)
# define SWT_CR_FRZ_GET(V)            __AS_BITVALUE(V, 1, 1, t_ast_uint32)
# define SWT_CR_FRZ_SET(V,X)         (__CL_BITVALUE(V, 1, 1, t_ast_uint32) | __TO_BITVALUE(X, 1, 1, t_ast_uint32))
# define SWT_CR_WEN(X)                __TO_BITVALUE(X, 0, 1, t_ast_uint32)
# define SWT_CR_WEN_GET(V)            __AS_BITVALUE(V, 0, 1, t_ast_uint32)
# define SWT_CR_WEN_SET(V,X)         (__CL_BITVALUE(V, 0, 1, t_ast_uint32) | __TO_BITVALUE(X, 0, 1, t_ast_uint32))

# define SWT_SR_WSC(X)                __TO_BITVALUE(X, 0, 16, t_ast_uint32)
# define SWT_SR_WSC_GET(V)            __AS_BITVALUE(V, 0, 16, t_ast_uint32)
# define SWT_SR_WSC_SET(V,X)         (__CL_BITVALUE(V, 0, 16, t_ast_uint32) | __TO_BITVALUE(X, 0, 16, t_ast_uint32))

# define SWT_IR_TIF(X)                __TO_BITVALUE(X, 0, 1, t_ast_uint32)
# define SWT_IR_TIF_GET(V)            __AS_BITVALUE(V, 0, 1, t_ast_uint32)
# define SWT_IR_TIF_SET(V,X)         (__CL_BITVALUE(V, 0, 1, t_ast_uint32) | __TO_BITVALUE(X, 0, 1, t_ast_uint32))

/* INTC registers definitions */
typedef t_ast_uint32 INTC_EOIR_t;
# define INTC_0 ((volatile t_ast_uint8 *) (0xFC040000UL))
# define INTC_0_EOIR(Y)         (((volatile INTC_EOIR_t *) (INTC_0 + 0x30))[Y])

# define INTC_EOIR_EOI(X)                __TO_BITVALUE(X, 0, 32, t_ast_uint32)
# define INTC_EOIR_EOI_GET(V)            __AS_BITVALUE(V, 0, 32, t_ast_uint32)
# define INTC_EOIR_EOI_SET(V,X)         (__CL_BITVALUE(V, 0, 32, t_ast_uint32) | __TO_BITVALUE(X, 0, 32, t_ast_uint32))

/* Timer related definitions */
typedef t_ast_uint32 STM_CR_t;
typedef t_ast_uint32 STM_CNT_t;
typedef t_ast_uint32 STM_CHANNEL_CCR_t;
typedef t_ast_uint32 STM_CHANNEL_CIR_t;
typedef t_ast_uint32 STM_CHANNEL_CMP_t;

# define STM_2 ((volatile t_ast_uint8 *) (0xFC070000UL))
# define STM_2_CR               (*((volatile STM_CR_t *) (STM_2 + 0x0)))
# define STM_2_CNT              (*((volatile STM_CNT_t *) (STM_2 + 0x4)))
# define STM_2_CHANNEL_CCR(Z)   (*((volatile STM_CHANNEL_CCR_t *) (STM_2 + 0x10 + ((Z) * 0x10))))
# define STM_2_CHANNEL_CIR(Z)   (*((volatile STM_CHANNEL_CIR_t *) (STM_2 + 0x14 + ((Z) * 0x10))))
# define STM_2_CHANNEL_CMP(Z)   (*((volatile STM_CHANNEL_CMP_t *) (STM_2 + 0x18 + ((Z) * 0x10))))

# define STM_CR_CPS(X)                __TO_BITVALUE(X, 8, 8, t_ast_uint32)
# define STM_CR_CPS_GET(V)            __AS_BITVALUE(V, 8, 8, t_ast_uint32)
# define STM_CR_CPS_SET(V,X)         (__CL_BITVALUE(V, 8, 8, t_ast_uint32) | __TO_BITVALUE(X, 8, 8, t_ast_uint32))
# define STM_CR_FRZ(X)                __TO_BITVALUE(X, 1, 1, t_ast_uint32)
# define STM_CR_FRZ_GET(V)            __AS_BITVALUE(V, 1, 1, t_ast_uint32)
# define STM_CR_FRZ_SET(V,X)         (__CL_BITVALUE(V, 1, 1, t_ast_uint32) | __TO_BITVALUE(X, 1, 1, t_ast_uint32))
# define STM_CR_TEN(X)                __TO_BITVALUE(X, 0, 1, t_ast_uint32)
# define STM_CR_TEN_GET(V)            __AS_BITVALUE(V, 0, 1, t_ast_uint32)
# define STM_CR_TEN_SET(V,X)         (__CL_BITVALUE(V, 0, 1, t_ast_uint32) | __TO_BITVALUE(X, 0, 1, t_ast_uint32))

# define STM_CNT_CNT(X)                __TO_BITVALUE(X, 0, 32, t_ast_uint32)
# define STM_CNT_CNT_GET(V)            __AS_BITVALUE(V, 0, 32, t_ast_uint32)
# define STM_CNT_CNT_SET(V,X)         (__CL_BITVALUE(V, 0, 32, t_ast_uint32) | __TO_BITVALUE(X, 0, 32, t_ast_uint32))

# define STM_CHANNEL_CCR_CEN(X)                __TO_BITVALUE(X, 0, 1, t_ast_uint32)
# define STM_CHANNEL_CCR_CEN_GET(V)            __AS_BITVALUE(V, 0, 1, t_ast_uint32)
# define STM_CHANNEL_CCR_CEN_SET(V,X)         (__CL_BITVALUE(V, 0, 1, t_ast_uint32) | __TO_BITVALUE(X, 0, 1, t_ast_uint32))

# define STM_CNT_CNT(X)                __TO_BITVALUE(X, 0, 32, t_ast_uint32)
# define STM_CNT_CNT_GET(V)            __AS_BITVALUE(V, 0, 32, t_ast_uint32)
# define STM_CNT_CNT_SET(V,X)         (__CL_BITVALUE(V, 0, 32, t_ast_uint32) | __TO_BITVALUE(X, 0, 32, t_ast_uint32))

# define STM_CHANNEL_CIR_CIF(X)                __TO_BITVALUE(X, 0, 1, t_ast_uint32)
# define STM_CHANNEL_CIR_CIF_GET(V)            __AS_BITVALUE(V, 0, 1, t_ast_uint32)
# define STM_CHANNEL_CIR_CIF_SET(V,X)         (__CL_BITVALUE(V, 0, 1, t_ast_uint32) | __TO_BITVALUE(X, 0, 1, t_ast_uint32))

# define STM_CHANNEL_CMP_CMP(X)                __TO_BITVALUE(X, 0, 32, t_ast_uint32)
# define STM_CHANNEL_CMP_CMP_GET(V)            __AS_BITVALUE(V, 0, 32, t_ast_uint32)
# define STM_CHANNEL_CMP_CMP_SET(V,X)         (__CL_BITVALUE(V, 0, 32, t_ast_uint32) | __TO_BITVALUE(X, 0, 32, t_ast_uint32))


#endif /* !AST_MPC5777M_XT_SOURCE_H_ */
