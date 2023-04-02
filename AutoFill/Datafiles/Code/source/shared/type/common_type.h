/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef COMMON_TYPE_H
#define COMMON_TYPE_H

/* ---------- include required interface: ----------------------------------- */
#include "type/mcp_types.h"

/* ---------- Linker command file symbol: ----------------------------------- */


/* ---------- provided define constants: ------------------------------------ */
/* Define the interdiction of padding when one of the following #define is used (according to the size) */
#define PACKED_U08 __packed__ (1,1,0)
#define PACKED_U16 __packed__ (2,2,0)
#define PACKED_U32 __packed__ (4,4,0)

/* Null pointer */
#ifndef NULL
#define NULL ((void*)0)
#endif

/* ---------- provided types: ----------------------------------------------- */
/* 32-bit register definition */
typedef volatile unsigned int reg32_t;

/* 16-bit register definition */
typedef volatile unsigned short reg16_t;

/* 8-bit register definition */
typedef volatile unsigned char reg8_t;

/* General system address type */
typedef void const* CMN_SYSTEM_ADDR_t;

/* General system address value type */
typedef uint32_t CMN_SYSTEM_ADDR_VAL_t;

/* General system size type */
typedef uint32_t CMN_SYSTEM_SIZE_t;

/* General system time type */
typedef int64_t CMN_SYSTEM_TIME_t;

/* Define IOSP ID type */
typedef uint32_t CMN_IOSP_ID_t;

/* Flag for a binary state machine */
typedef enum
{
   e_CMN_FLAG_RUN = 1,
   e_CMN_FLAG_STOP = 2
}
te_CMN_FLAG_RUN;

/* Flag for a treatment algorithm */
typedef enum
{
   e_CMN_FLAG_COMPLETE = 1,
   e_CMN_FLAG_NOT_COMPLETE = 2
}
te_CMN_FLAG_COMPLETE;

/* Flag for searching algorithm */
typedef enum
{
   e_CMN_FLAG_FOUND = 1,
   e_CMN_FLAG_NOT_FOUND = 2
}
te_CMN_FLAG_FOUND;

/* Flag for searching algorithm */
typedef enum
{
   e_found = 1,
   e_not_found = 2
}
te_flag_found_state;

/* Flag for the field validity */
typedef enum
{
   e_CMN_FLAG_VALID = 1,
   e_CMN_FLAG_NOT_VALID = 2
}
te_CMN_FLAG_VALIDITY;

/* Flag to be used for question : field like "is_...". For instance : is_first_run, is_first_data. */
typedef enum
{
   e_CMN_FLAG_YES = 1,
   e_CMN_FLAG_NO = 2
}
te_CMN_FLAG_QUESTION;

/* Flag for disable or enabling / de-activate or activate */
typedef enum
{
   e_CMN_FLAG_ACTIVATE = 1,
   e_CMN_FLAG_NOT_ACTIVATE = 2
}
te_CMN_FLAG_ACTIVATION;

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

/* Standard return code type definition */
typedef struct
{
   reg32_t s_RC_NO_ACTION : 1;
   reg32_t s_RC_NOT_AVAILABLE : 1;
   reg32_t s_RC_INVALID_PARAM : 1;
   reg32_t s_RC_INVALID_CONFIG : 1;
   reg32_t s_RC_INVALID_MODE : 1;
   reg32_t s_RC_TIMED_OUT : 1;
   reg32_t s_RC_HW_ERROR : 1;
   reg32_t s_SPARE : 25;
}
tu_CMN_RC_u_b;

typedef union
{
   uint32_t u_r;
   tu_CMN_RC_u_b u_b;
}
tu_CMN_RC;

/* Buffer structure to have the buffer size information */
typedef struct
{
   int8_t* s_buffer;
   uint32_t s_buffer_size;
}
ts_CMN_IOSP_BUFFER;

/* CAN status */
typedef struct
{
   reg32_t s_no_action : 1;
   reg32_t s_not_available : 1;
   reg32_t s_invalid_param : 1;
   reg32_t s_invalid_config : 1;
   reg32_t s_invalid_mode : 1;
   reg32_t s_timed_out : 1;
   reg32_t s_hw_error : 1;
   reg32_t s_spare : 25;
}
tu_can_status_u_bit;

typedef union
{
   uint32_t u_word;
   tu_can_status_u_bit u_bit;
}
tu_can_status;

/* CAN configuration */
typedef struct
{
   uint32_t sfid1;
   uint32_t sfid2;
}
ts_can_sfid;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operations: ------------------------------------------ */

#endif /* COMMON_TYPE_H */
