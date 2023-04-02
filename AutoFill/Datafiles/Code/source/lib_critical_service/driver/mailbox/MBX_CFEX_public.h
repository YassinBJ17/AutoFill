/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef MBX_CFEX_PUBLIC_H
#define MBX_CFEX_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "middleware/ethernet/ETH_MAC_public.h"

/* ---------- provided define constants: ------------------------------------ */
/* Length of FIFO RX and TX */
#define MBX_CFEX_FIFO_SIZE      0x1000ul     /* 4 kwords */
/* Length of DATA RX and TX */
#define MBX_CFEX_DATA_SIZE      4ul     /* 32 bits = 4 octets */
/* Length of CMD TX */
#define MBX_CFEX_CMD_SIZE       2ul     /* 16 bits = 2 octets */
/* Length of CMD & DATA TX */
#define MBX_CFEX_CMD_DATA_SIZE  (MBX_CFEX_CMD_SIZE + MBX_CFEX_DATA_SIZE)

/* ---------- provided types: ----------------------------------------------- */
/* */
typedef enum
{
   e_CFEX_MBX_CONF_0 = 0 ,
   e_CFEX_MBX_CONF_NB
}
te_CFEX_MBX_CONF ;

typedef struct
{
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t    s_mbx_rx_fifo_address;
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t    s_mbx_tx_fifo_address;
   /* Register s_address */
   CMN_SYSTEM_ADDR_VAL_t    s_mbx_tx_cmd_fifo_address;
}
ts_MBX_CFEX_ELT;

typedef enum
{
   e_MBX_STATUS_INIT = 0 ,
   e_MBX_STATUS_AUTONEGO = 1,
   e_MBX_STATUS_CONNECTION = 2,
   e_MBX_STATUS_READY = 3,
   e_MBX_STATUS_FAILED = 4

} te_MBX_STATUS ;

/* */
typedef struct
{
   MAC_ETH_MACAddr_t s_mac_addr;
   te_MBX_STATUS s_status ;
}
ts_MBX_CONFIG_DESC;


/* ---------- provided constants: ------------------------------------------- */
/* */
/* {{RELAX<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> : the table c_MBX_CFEX_CONFIGURATION_tab and MBX_CFEX_descriptor_tab share the same size : c_MBX_CFEX_tab_SIZE. This size is a integration value so the table are declared without a size. */
extern const uint32_t c_MBX_CFEX_tab_SIZE;
extern const ts_MBX_CFEX_ELT c_MBX_CFEX_CONFIGURATION_tab[];
extern const MAC_ETH_MACAddr_t c_mac_CDRAaddr;
extern const MAC_ETH_MACAddr_t c_mac_CDRBaddr;
/* ---------- provided data: ------------------------------------------------ */
/* */
extern ts_MBX_CONFIG_DESC MBX_CFEX_descriptor ;

/* ---------- provided operations: ------------------------------------------ */
/* */

#endif /* MBX_CFEX_PUBLIC_H */
