/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_MEGIT_H
#define LIBBSP_MEGIT_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/

/*==== Types ===========================================================================*/
typedef enum
{
   E_LIBBSP_MEGIT_VALID_ADDR = 0,
   E_LIBBSP_MEGIT_INVALID_ADDR = 1
} TE_LIBBSP_MEGIT_AddrStatus;

/*typedef enum
{
   E_LIBBSP_MEGIT_CPU_NO_SOURCE = 0,
   E_LIBBSP_MEGIT_CPU_SYNC_APPL = 1,
   E_LIBBSP_MEGIT_CPU_TIC_RDY = 2,
   E_LIBBSP_MEGIT_CPU_RT_RDY = 3,
   E_LIBBSP_MEGIT_CPU_IRQ_2KH_ALL = 4,
   E_LIBBSP_MEGIT_CPU_IRQ_APPL_ALL = 5,
   E_LIBBSP_MEGIT_CPU_IRQ_APPL_TIC = 6,
   E_LIBBSP_MEGIT_CPU_RTC_8K = 7,
   E_LIBBSP_MEGIT_CPU_NB_SOURCE = 8
} TE_LIBBSP_MEGIT_CpuSyncSource;*/

/*typedef enum
{
   E_LIBBSP_MEGIT_IT_SOURCE_INVALID = 0,
   E_LIBBSP_MEGIT_IT_SOURCE_VALID = 1
} TE_LIBBSP_MEGIT_ItStatus;*/

/*typedef enum
{
   E_LIBBSP_MEGIT_RS_NO_SOURCE = 0,
   E_LIBBSP_MEGIT_RS_SYNC_100HZ = 1,
   E_LIBBSP_MEGIT_RS_SYNC_APPL = 2,
   E_LIBBSP_MEGIT_RS_RTC_IDA = 3,
   E_LIBBSP_MEGIT_RS_RTC_2K = 4,
   E_LIBBSP_MEGIT_RS_CPU_RTC = 5,
   E_LIBBSP_MEGIT_RS_NB_SOURCE = 6
} TE_LIBBSP_MEGIT_RsSyncSource;*/

typedef union
{
   uint32_t R;
   struct
   {
      uint32_t reserved1 : 21;
      uint32_t rs_rtc_sel : 3;
      uint32_t reserved2 : 5;
      uint32_t cpu_rtc_sel : 3;
   } TS_RegFields;
} TS_LIBBSP_MEGIT_SourceRegister;

typedef union
{
   uint32_t R;
   struct
   {
      uint32_t force_rtc : 1;
      uint32_t reserved : 30;
      uint32_t cpu_rtc_en : 1;
   } TS_RegFields;
} TS_LIBBSP_MEGIT_EnableRegister;

typedef struct
{
   uint8_t reserved[52];
   TS_LIBBSP_MEGIT_SourceRegister v_SyncSourcesReg;
   TS_LIBBSP_MEGIT_EnableRegister v_RtcConfReg;
} TS_LIBBSP_MEGIT_Registers;

/*==== Variables========================================================================*/

// extern volatile TS_LIBBSP_MEGIT_Registers * const V_MegItRegs;

/*==== Services ========================================================================*/

extern TE_LIBBSP_MEGIT_ItStatus LIBBSP_MEGIT_Conf(const TE_LIBBSP_MEGIT_CpuSyncSource v_CpuSyncSource,
                                                  const TE_LIBBSP_MEGIT_RsSyncSource v_RsSyncSource,
                                                  const boolean_t v_GlobalDebugEnable,
                                                  const boolean_t v_SyncSignalsEnable);

/*==== END =============================================================================*/
#endif /* LIBBSP_PLDCMP_H */
