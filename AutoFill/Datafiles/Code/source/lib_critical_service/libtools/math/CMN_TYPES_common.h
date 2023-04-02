/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef CMN_TYPES_COMMON_H
#define CMN_TYPES_COMMON_H

/* ---------- include required interface: ----------------------------------- */

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

/* Define the maximum length of a general name */
#define CMN_MAX_NAME_LENGTH 30

/* */
/* Define the value of infinite time */
#define CMN_INFINITE_TIME_VALUE ( (CMN_SYSTEM_TIME_t) -1  )

/* ---------- provided types: ----------------------------------------------- */
/* REGISTER TYPES */
/* Register type 32 bits*/
typedef volatile unsigned int reg32_t;

/* Register type 16 bits*/
typedef volatile unsigned short reg16_t;

/* Register type 8 bits*/
typedef volatile unsigned char reg8_t;


/* */
/* General Name type */
typedef uint8_t CMN_NAME_t[CMN_MAX_NAME_LENGTH];
/* */
/* General System Address type */
typedef void const *  CMN_SYSTEM_ADDR_t;
/* */
/* General System Address Value type */
typedef uint32_t  CMN_SYSTEM_ADDR_VAL_t;
/* */
/* General System Size type */
typedef uint32_t  CMN_SYSTEM_SIZE_t;

/* General System Time type */
typedef int64_t  CMN_SYSTEM_TIME_t;
#define CMN_SYSTEM_TIME_INVALID ((CMN_SYSTEM_TIME_t)0xFFFFFFFFFFFFFFFFll)

/* */
/* General System Error (generic type) */
typedef int32_t  CMN_SYSTEM_ERROR_t;

/*  */

/* flag for a binary state machine */
typedef enum
{
   e_CMN_FLAG_RUN  = 1,
   e_CMN_FLAG_STOP = 2
}
te_CMN_FLAG_RUN ;


/* flag for the treatment algorithm */
typedef enum
{
   e_CMN_FLAG_COMPLETE     = 1,
   e_CMN_FLAG_NOT_COMPLETE = 2
}
te_CMN_FLAG_COMPLETE;

/* flag for the research algo */
typedef enum
{
   e_CMN_FLAG_FOUND     = 1,
   e_CMN_FLAG_NOT_FOUND = 2
}
te_CMN_FLAG_FOUND;

/* flag for the field validity */
typedef enum
{
   e_CMN_FLAG_VALID     = 1,
   e_CMN_FLAG_NOT_VALID = 2
}
te_CMN_FLAG_VALIDITY;

/* flag to be used for question : field like "is_...". For instance :  */
/*  is_first_run, is_first_data. */
typedef enum
{
   e_CMN_FLAG_YES = 1,
   e_CMN_FLAG_NO  = 2
}
te_CMN_FLAG_QUESTION ;

/* flag for disable or enabling / de-activate or activate */
typedef enum
{
   e_CMN_FLAG_ACTIVATE     = 1,
   e_CMN_FLAG_NOT_ACTIVATE = 2
}
te_CMN_FLAG_ACTIVATION ;

/* Struct for low/high part of float32_t*/
typedef struct
{
   uint16_t s_HIGH_FIELD;
   uint16_t s_LOW_FIELD;
}
ts_CMN_BITFIELD;

/* u_word_bitfield: to separate low and high part of u_word */
typedef union
{
   ts_CMN_BITFIELD u_word_bitfield;
   float32_t       u_word;
}
tu_CMN_BITFIELD;

/* */
/* CMN standard return code type definition */
/* {{RELAX<SYNCHRONe_C_Code_8.17, SYNCHRONe_C_Code_6.6> Register structure definition. All fields should be defined. */
typedef union
{
   uint32_t u_r;
   struct
   {
      reg32_t s_RC_NO_ACTION       :  1 ;
      reg32_t s_RC_NOT_AVAILABLE   :  1 ;
      reg32_t s_RC_INVALID_PARAM   :  1 ;
      reg32_t s_RC_INVALID_CONFIG  :  1 ;
      reg32_t s_RC_INVALID_MODE    :  1 ;
      reg32_t s_RC_TIMED_OUT       :  1 ;
      reg32_t s_RC_HW_ERROR        :  1 ;
      reg32_t s_SPARE              :  25 ;
   } u_b ;
} tu_CMN_RC;
/* }}<SYNCHRONe_C_Code_8.17, SYNCHRONe_C_Code_6.6> */
/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* CMN_TYPES_COMMON_H */
