
#ifndef LL_H
#define LL_H

#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "LIBBSP_ETSEC.h"

/* Buffer Descriptor (BD) MPC8280RM.pdf 14.5.1 */ 
#ifdef _DIAB_TOOL
#pragma pack(1,1,0)
#else
#pragma pack(push, 1)
#endif
/*typedef struct
{
    uint16_t volatile status;
    uint16_t volatile length;
    uint8_t * volatile address;
} TS_LIBBSP_ETSEC_t_ll_tx_bd;

typedef struct 
{
    uint16_t volatile status;
    uint16_t volatile length;
    uint8_t * volatile address;
} TS_LIBBSP_ETSEC_t_ll_rx_bd;*/
#ifdef _DIAB_TOOL
#pragma pack(0,0,0)
#else
#pragma pack(pop)
#endif

extern void LL_MANAGEMENT_configure (const uint32_t controller);

extern void LL_MANAGEMENT_init (const uint32_t controller,
                                const TS_LIBBSP_ETSEC_ConfHostMac * const p_mac);

extern void LL_MANAGEMENT_stop (const uint32_t controller, 
                                const boolean_t rx_stop, 
                                const boolean_t tx_stop);

extern void LL_MANAGEMENT_start (const uint32_t controller, 
                                 const boolean_t rx_start, 
                                 const boolean_t tx_start);


#endif

