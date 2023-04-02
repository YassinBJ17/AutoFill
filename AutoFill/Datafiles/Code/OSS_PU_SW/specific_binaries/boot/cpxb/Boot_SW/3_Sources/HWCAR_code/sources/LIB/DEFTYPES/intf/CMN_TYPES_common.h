#ifndef CMN_TYPES_COMMON_H
#define CMN_TYPES_COMMON_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/*--------------------------------------------------------------------------
__packed__ ([[max_member_alignment], [min_structure_alignment] [, byte-swap]])
------------------------------------------------------------------------------*/
#if defined(__CDT_PARSER__) || defined(RULECHECKER)

#define PACKED_U08
#define PACKED_U16
#define PACKED_U32
/* >RELAX<SYNCHRONe_C_Code_5.7, SYNCHRONe_C_Code_19.23> macro not managed by rulechecker */
#define __attribute__(x_dummy)

#else

/*#info using packed structure*/

#define PACKED_U08 __packed__ (1,1,0)
#define PACKED_U16 __packed__ (2,2,0)
#define PACKED_U32 __packed__ (4,4,0)

#endif



/*  =============== SYNCHRONe Types ========================================= */
/* NOTE : boolean type should not be used. Use instead the enumerate values  */

/* ---------- provided types: ----------------------------------------------- */
typedef unsigned char      uint8_t ;
typedef signed   char      int8_t;
typedef unsigned short     uint16_t;
typedef signed   short     int16_t;
typedef unsigned long      uint32_t;
typedef signed   long      int32_t;
typedef unsigned long long uint64_t;
typedef signed   long long int64_t;
typedef float              float32_t;
typedef double             float64_t;
/* END OF  SYNCHRONe Types ================================================== */

/* COMPLEMENT OF TYPES for MODULE =========================================== */
/*  Note : all following variables are prefixed with CMN (which stands for    */ 
/*  COMMON) */

/* */
#ifndef NULL
#define NULL ((void*) 0)
#endif

/* ---------- provided types: ----------------------------------------------- */
/* REGISTER TYPES */
/* Register type 32 bits*/
typedef volatile unsigned long reg32_t;

/* Register type 16 bits*/
typedef volatile unsigned short reg16_t;

/* Register type 8 bits*/
typedef volatile unsigned char reg8_t;

/* */
/* General System Address type */
typedef void const *  CMN_SYSTEM_ADDR_t;
/* */
/* General System Address Value type */
typedef uint32_t  CMN_SYSTEM_ADDR_VAL_t;

/* ---------- provided constants: ------------------------------------------- */
/* none */

/* ---------- provided data: ------------------------------------------------ */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* none */

#endif /* CMN_TYPES_COMMON_H */
