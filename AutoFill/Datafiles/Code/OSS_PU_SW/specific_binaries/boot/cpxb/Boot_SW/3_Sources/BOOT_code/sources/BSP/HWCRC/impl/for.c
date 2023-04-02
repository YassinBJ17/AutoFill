#include "HWCRC_CFEX_public.h"
#include "CMN_TYPES_common.h"
#include "HWCRC_REG_common.h"
#include "HWCRC_HAL_public.h"

    for ( v_hwcrc_index = 0ul ; v_hwcrc_index < c_HWCRC_CFEX_tab_SIZE ; v_hwcrc_index++ )    {       pt_hwcrc_conf = &(c_HWCRC_CFEX_CONFIGURATION_tab[v_hwcrc_index]);       pt_hwcrc_reg = (ts_HWCRC_REG volatile *)c_HWCRC_ctrler_addr[pt_hwcrc_conf->s_module_nb];       if ( pt_hwcrc_conf->s_crc_poly == e_HWCRC_CFEX_CRC32_POLY )       {     	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_POLYG = (reg32_t)e_HWCRC_CRC32_POLY;     	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_SWAP_BYTEWISE_CRC_32 = 1;     	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_SWAP = 1;     	  pt_hwcrc_reg->s_CRC_CFG.u_B.s_INV = 1;       }       else          {       }       if ( pt_hwcrc_conf->s_transfer_mode == e_HWCRC_CFEX_TRANSFER_MODE_SW )       {       }       else        {       }       HWCRC_CFEX_descriptor_tab[v_hwcrc_index].s_address = c_HWCRC_ctrler_addr[pt_hwcrc_conf->s_module_nb];       HWCRC_CFEX_descriptor_tab[v_hwcrc_index].s_dma_conf_nb = pt_hwcrc_conf->s_dma_conf_nb;    }
