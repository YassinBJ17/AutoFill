/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ENVM_H
#define LIBBSP_ENVM_H

#include "LIBMCP_Types.h"

/*==== Definitions =====================================================================*/


/*==== Types ===========================================================================*/

typedef enum {
   E_LIBBSP_ENVM_OK = 0,
   E_LIBBSP_ENVM_OVERSIZED = 1,
   E_LIBBSP_ENVM_INVALID_DEVICE = 3,
   E_LIBBSP_ENVM_INVALID_ADDR = 2,
   E_LIBBSP_ENVM_TIMEOUT = 4
} TE_LIBBSP_ENVM_ErrorCode;

typedef enum {
   E_LIBBSP_ENVM_MEGATICE = 0,
   E_LIBBSP_ENVM_COMPAGNON = 1
} TE_LIBBSP_ENVM_Device;

typedef struct
{
   uint32_t start;
   uint32_t end;
   uint32_t read;
   uint32_t write;
   uint32_t erase;
} TS_LIBBSP_ENVM_CompagnonMap;

/*==== Variables========================================================================*/

/*==== Services ========================================================================*/

extern TE_LIBBSP_ENVM_ErrorCode LIBBSP_ENVM_Configure(const TE_LIBBSP_ENVM_Device device, const uint32_t nb, const TS_LIBBSP_ENVM_CompagnonMap * const p_Envm_Map);
extern TE_LIBBSP_ENVM_ErrorCode LIBBSP_ENVM_Open(const TE_LIBBSP_ENVM_Device device);
extern TE_LIBBSP_ENVM_ErrorCode LIBBSP_ENVM_Close(const TE_LIBBSP_ENVM_Device device);
extern void LIBBSP_ENVM_Read(const TE_LIBBSP_ENVM_Device device, const uint32_t address, const uint32_t size, uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret);
extern void LIBBSP_ENVM_Write(const TE_LIBBSP_ENVM_Device device, const uint32_t address, const uint32_t size, const uint8_t * const buffer, TE_LIBBSP_ENVM_ErrorCode * const v_ret);

extern void LIBBSP_ENVM_ReadAddrs(const TE_LIBBSP_ENVM_Device device, const uint32_t * const v_read_add_envm, const uint32_t v_nb_word,
                             uint32_t * const v_read_data, TE_LIBBSP_ENVM_ErrorCode * const v_ret);

/*==== END =============================================================================*/
#endif /* LIBBSP_ENVM_H */
