/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */
#ifndef MCP_TYPES_H
#define MCP_TYPES_H

/* ---------- include required interface: ----------------------------------- */
/* None */

/* ---------- Linker command file symbol: ----------------------------------- */
/* None */

/* ---------- provided define constants: ------------------------------------ */
/** @brief Expression returns '0' */
#define FALSE ((boolean_t) (0 == 1))
/** @brief Expression returns '1' */
#define TRUE  ((boolean_t) (1 == 1))

/* ---------- provided types: ----------------------------------------------- */
/** @brief The type to use for a boolean value */
typedef signed   int       boolean_t;
/** @brief The type to use for an unsigned 8-bits value */
typedef unsigned char      uint8_t;
/** @brief The type to use for a signed 8-bits value */
typedef signed   char      int8_t;
/** @brief The type to use for an unsigned 16-bits value */
typedef unsigned short     uint16_t;
/** @brief The type to use for a signed 16-bits value */
typedef signed   short     int16_t;
/** @brief The type to use for an unsigned 32-bits value */
typedef unsigned long      uint32_t;
/** @brief The type to use for a signed 32-bits value */
typedef signed   long      int32_t;
/** @brief The type to use for an unsigned 64-bits value */
typedef unsigned long long uint64_t;
/** @brief The type to use for a signed 64-bits value */
typedef signed   long long int64_t;
/** @brief The type to use for a float 32-bits value */
typedef float              float32_t;
/** @brief The type to use for a float 64-bits value */
typedef double             float64_t;

/* ---------- provided constants: ------------------------------------------- */
/* None */

/* ---------- provided data: ------------------------------------------------ */
/* None */

/* ---------- provided operations: ------------------------------------------ */
/* None */

#endif /* MCP_TYPES_H */
