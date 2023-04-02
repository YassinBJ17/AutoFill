LIB_NAME := LIBBSP_ETSEC
SCI := LIBBSP
SOURCES_FILES:=\
HW_TB.c\
HW_TBL.c\
LL_RX.c\
LL_RX_check_overrun.c\
LL_RX_flush.c\
LL_TX.c\
LL_management.c\
HW_CONF.c\
etsec.c\
tbi.c\
smi.c\
phy.c\
phy_connect.c\
phy_get_identity.c\
phy_is_link_up.c\
phy_read.c\
phy_write.c\
LIBBSP_ETSEC_Init.c\
LIBBSP_ETSEC_InitAddress.c\
LIBBSP_ETSEC_Configure.c\
LIBBSP_ETSEC_Start.c\
LIBBSP_ETSEC_Stop.c\
LIBBSP_ETSEC_Write.c\
LIBBSP_ETSEC_Read.c\
LIBBSP_ETSEC_GetError.c\
LIBBSP_ETSEC_AckError.c\
LL_RX_bd_mapping.c\
LL_RX_pools_mapping.c\
LL_TX_bd_mapping.c\
LL_TX_pools_mapping.c\
LIBBSP_ETSEC_PhyReset.c\
LIBBSP_ETSEC_InitRxTx.c\
LIBBSP_ETSEC_GetPhyState.c\
Initialize_ECNTRL.c\
Initialize_MACCFG2.c\
LIBBSP_ETSEC_Consts.c\







INCLUDE_FILES := ../../LIBBSP_api/LIBBSP_ETSEC ../../LIBBSP_api/LIBBSP_CMN ../../QACG_StdLib_source/MCP_StdLib_source\
../../LIBBSP_api/LIBBSP_TYPE/inc_gen\
../../LIBBSP_api/LIBBSP_TYPE/inc_man\
../../LIBBSP_api/LIBBSP_CCSR







include ../../Makefile/MakefileLib.mk




