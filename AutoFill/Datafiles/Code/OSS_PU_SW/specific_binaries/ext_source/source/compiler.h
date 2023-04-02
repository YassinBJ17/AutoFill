/************ Copyright Krono-Safe S.A. 2019, All rights reserved ************/

/**
 * @file        compiler.h
 * @brief       Documentation file Compiler-specific definitions.
 * @copyright   Copyright Krono-Safe S.A. 2019, All rights reserved.
 */

#ifndef AST_HELPERS_COMPILER_H_
# define AST_HELPERS_COMPILER_H_

/**
 * @brief Force the use of a single machine-word copy instruction (32-bit).
 * @param [out] A Destination variable
 * @param [in]  B Source variable
 *
 * The Source and Destination variables are casted into unsigned int
 * variables. This tells the compiler it is safe to use an `lwz`
 * instruction.
 */
# define COPY_WORD(A, B) \
  *((volatile t_ast_uint32 *) &(A)) = *((volatile t_ast_uint32 *) &(B))

/**
 * @brief Force the use of a half-machine-word copy instruction (16-bit).
 * @param [out] A Destination variable
 * @param [in]  B Source variable
 *
 * The Source and Destination variables are casted into unsigned short
 * variables. This tells the compiler it is safe to use an `lwh`
 * instruction.
 */
# define COPY_HALF(A, B) \
  *((volatile t_ast_uint16 *) &(A)) = *((volatile t_ast_uint16 *) &(B))

/**
 * @brief Force the use of a single byte copy instruction (8-bit).
 * @param [out] A Destination variable
 * @param [in]  B Source variable
 *
 * The Source and Destination variables are casted into unsigned char
 * variables. This tells the compiler it is safe to use an `lwb`
 * instruction.
 */
# define COPY_BYTE(A, B) \
  *((volatile  t_ast_uint8 *)  &(A)) = *((volatile t_ast_uint8 *)  &(B))

/**  Empty structure initializer */
# define ARCH_EMPTY_STRUCT { 0 }

/**  Hardware context default initializer */
# define HAL_HWCTX_DEFAULT ARCH_EMPTY_STRUCT

/**  Hardware context initial default initializer */
# define HAL_INIT_HWCTX_DEFAULT ARCH_EMPTY_STRUCT

/**  Compiler specific definition for packed structure */
# define KPACKED(Def) __packed__(1,1) Def


/* Some C funtions are called directly by agent runtime code. As the code
 * can be relocated in different memory areas, a simple "branch" instruction
 * to (PC + offset) is immposible. The offset would be too large to fit in
 * the instruction word.
 * So, declare that these functions are in a new code section, with the
 * "far-absolute" attribute. The compiler will be forced to generate far
 * jump instructions when calling these functions.
 * This is only when building application, the kernel does not need that
 * as it is built as a monolithic binary.
 */
# ifndef ASTERIOS_KERNEL_MPC5777M /* DISABLE THIS CODE WHEN COMPILING K2 */
  /* Little trick: this macro is only defined when buidling the kernel.
   * So, here, we know we are building an application. */

  /* New code section with the "far-absolute" memory attribute */
#  pragma section CODE_FAR ".text_vle" far-absolute RX
  /* Use this section for the required functions */
  /* TODO generate this for all exported symbols */
#  pragma use_section CODE_FAR  get_previous_tick_index, ast_memset, ast_memcpy,  \
            ast_error_raise, hal_trap_error_raise, hal_enter_psyslayer_psy,       \
            ast_khi_job_preprocessing_psy, ast_khi_job_postprocessing_psy,        \
            hal_cpu_id,                                                           \
            ast_stream_lastsender, ast_stream_lasttimestamp,                      \
            ast_stream_pusher_refresh, ast_stream_popper_refresh,                 \
            ast_stream_push, ast_khi_stream_push, ast_stream_pop,                 \
            ast_stream_pop_froMCSS_TASK, ast_stream_count,                           \
            ast_stream_count_froMCSS_TASK, ast_stream_clear,                         \
            ast_stream_clear_froMCSS_TASK, ast_tv_consult,                           \
            ast_tv_lasttimestamp, ast_tv_get_displayer_status
# endif /* ! ASTERIOS_KERNEL_MPC5777M */

#endif  /* !AST_HELPERS_COMPILER_H_ */
