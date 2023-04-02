#ifndef BOOT_INTC_PUBLIC_H
#define BOOT_INTC_PUBLIC_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include  ------------------------------------------------------ */
#include "CMN_TYPES_common.h"

/* ---------- external define constants: ------------------------------------ */
/* none */

/* ---------- external types: ----------------------------------------------- */
typedef void (*INTC_EXCEP_FUNC)(void);


/* ---------- external operations: ------------------------------------------ */
/* none */

/* ---------- external datas: ----------------------------------------------- */
/* {{RELAX<SYNCHRONe_C_Code_8.12> The size of these tables is defined in the linker file. */
/* {{RELAX<SYNCHRONe_C_Code_8.15> The vector table need to be declared here but are initialized in assembly */
/* files which are not analysed by rulechecker*/
extern INTC_EXCEP_FUNC BOOT_INTC_VECTOR_TABLE_C0[] ;
extern INTC_EXCEP_FUNC BOOT_INTC_VECTOR_TABLE_C1[] ;
extern INTC_EXCEP_FUNC BOOT_INTC_VECTOR_TABLE_C2[] ;
/* }}<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.15>*/

/* ---------- external constants: ------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------- */


/* */
extern void BOOT_INTC_INIT( void );
extern uint32_t BOOT_INTC_GET_EXT_IT_SRC( uint32_t const p_core_nb);

#endif /* BOOT_INTC_PUBLIC_H */
