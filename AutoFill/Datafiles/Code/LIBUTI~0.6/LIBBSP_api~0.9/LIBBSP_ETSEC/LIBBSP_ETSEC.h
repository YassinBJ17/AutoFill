/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2017                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_ETSEC_H
#define LIBBSP_ETSEC_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

/*==== Definitions =====================================================================*/
#define C_LIBBSP_ETSEC_FRAME_SIZE_MAX 					1518
#define C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS 			((uint32_t)3)
#define C_LIBBSP_ETSEC_ETHERNET_RX_BUFFER_SIZE          ((uint32_t)1536)   /* 1536 bytes : shall be mutliple of 64 (cf datasheet)*/
#define C_LIBBSP_ETSEC_ETHERNET_TX_BUFFER_SIZE          ((uint32_t)1536)   /* 1536 bytes : shall be mutliple of 64 (cf datasheet)*/
#define C_LIBBSP_ETSEC_ETHERNET_MAX_FRAME_SIZE          ((uint32_t)1518)   /* 1518 bytes according to standard Ethernet 802.3    */
#define C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE     		((uint32_t)20)
#define C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE    		((uint32_t)20)

/*==== Types ===========================================================================*/
/*
#ifndef _KCG_IMPORTED_FUNCTIONS_H_
typedef enum {
    E_LIBBSP_ETSEC_NETWORK_1  = 0,
	E_LIBBSP_ETSEC_NETWORK_2  = 1,
	E_LIBBSP_ETSEC_NETWORK_3  = 2,
	E_LIBBSP_ETSEC_NB_NETWORK  = 3
} TE_LIBBSP_ETSEC_Network;
#endif
*/

/*
typedef enum {
	E_LIBBSP_ETSEC_START_NETWORK_TX  = 1,
	E_LIBBSP_ETSEC_START_NETWORK_RX  = 2,
	E_LIBBSP_ETSEC_START_NETWORK_RX_TX  = 3
} TE_LIBBSP_ETSEC_NetConfigStart;
*/


/*typedef enum {
	E_LIBBSP_ETSEC_STOP_NETWORK_TX  = 1,
	E_LIBBSP_ETSEC_STOP_NETWORK_RX  = 2,
	E_LIBBSP_ETSEC_STOP_NETWORK_RX_TX  = 3
} TE_LIBBSP_ETSEC_NetConfigStop;*/

/*
#ifndef _KCG_IMPORTED_FUNCTIONS_H_
typedef enum {
    E_LIBBSP_ETSEC_OK  = 0,
	E_LIBBSP_ETSEC_KO  = 1
} TE_LIBBSP_ETSEC_NetworkStatus;
#endif
*/

typedef struct
{
	uint8_t  data[C_LIBBSP_ETSEC_FRAME_SIZE_MAX];
	uint32_t  nb_data;
	boolean_t  new_message;
} TS_LIBBSP_ETSEC_Msg;

/*
typedef enum
{
    E_LIBBSP_ETSEC_NO_PHYSICAL_ERROR,
    E_LIBBSP_ETSEC_PHYSICAL_ERROR,
    E_LIBBSP_ETSEC_NO_FRAME_RECEIVED,
    E_LIBBSP_ETSEC_SOFTWARE_OVERRUN
} TE_LIBBSP_ETSEC_FrameStatus;*/


typedef struct
{
	uint8_t  eTSECx_RSTAT_QHLT0;
	uint8_t  eTSECx_TSTAT_THLT0;
} TS_LIBBSP_ETSEC_Error;  /* ETSEC registers definition */


/*typedef struct
{
   uint8_t  mac_addr[6];
} TS_LIBBSP_ETSEC_ConfHostMac;*/

 typedef struct
 {
     uint8_t txbyte [C_LIBBSP_ETSEC_ETHERNET_TX_BUFFER_SIZE];
 } TS_LIBBSP_ETSEC_t_ll_txbuffer;

 typedef struct
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
 } TS_LIBBSP_ETSEC_t_ll_rx_bd;


/* Table de BDs associe a une interface reseau */
typedef struct {
	TS_LIBBSP_ETSEC_t_ll_rx_bd rxbd[C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE];
} TS_LIBBSP_ETSEC_t_ll_rx_bd_table;


typedef struct {
	uint8_t rxbyte[C_LIBBSP_ETSEC_ETHERNET_RX_BUFFER_SIZE];
} TS_LIBBSP_ETSEC_t_ll_rxbuffer;


typedef struct {
	TS_LIBBSP_ETSEC_t_ll_rxbuffer rxbuffer[C_LIBBSP_ETSEC_ETHERNET_RX_FIFO_SIZE];
} TS_LIBBSP_ETSEC_t_ll_rx_pool;


/* Interface de reception sur une interface reseau */
typedef struct {
	uint32_t controller;
	uint32_t next_frame_to_get;
} TS_LIBBSP_ETSEC_t_ll_rx_interface; //why is there also not one for tx?


/* Buffer d'emission TX a associer aux BD TX */
typedef struct
{
    TS_LIBBSP_ETSEC_t_ll_txbuffer txbuffer [C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE];
} TS_LIBBSP_ETSEC_t_ll_tx_pool;


typedef struct
{
    TS_LIBBSP_ETSEC_t_ll_tx_bd txbd [C_LIBBSP_ETSEC_ETHERNET_TX_FIFO_SIZE];
} TS_LIBBSP_ETSEC_t_ll_tx_bd_table;

typedef struct 
{
    TS_LIBBSP_ETSEC_t_ll_tx_pool V_LL_TX_pools [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
} TS_LIBBSP_ETSEC_t_ll_p_tx_pools;

typedef struct 
{
    TS_LIBBSP_ETSEC_t_ll_tx_bd_table V_LL_TX_bd_tables [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
} TS_LIBBSP_ETSEC_t_ll_p_tx_bd_tables;

typedef struct 
{
    TS_LIBBSP_ETSEC_t_ll_rx_pool V_LL_RX_pools [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
} TS_LIBBSP_ETSEC_t_ll_p_rx_pools;

typedef struct 
{
    TS_LIBBSP_ETSEC_t_ll_rx_bd_table V_LL_RX_bd_tables [C_LIBBSP_ETSEC_ETHERNET_NB_CONTROLLERS];
} TS_LIBBSP_ETSEC_t_ll_p_rx_bd_tables;

/*==== Variables========================================================================*/

/*==== Services ========================================================================*/
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Init( const TE_LIBBSP_ETSEC_Network network );
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_InitAddress( const uint32_t * const txpool , const uint32_t * const txbd,
                                                        const uint32_t * const rxpool,  const uint32_t * const rxbd);
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Configure( const TE_LIBBSP_ETSEC_Network network );
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Start( const TE_LIBBSP_ETSEC_Network network, const TS_LIBBSP_ETSEC_ConfHostMac * const mac_addr);
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Stop( const TE_LIBBSP_ETSEC_Network network, const TE_LIBBSP_ETSEC_NetConfigStop network_config  );

extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_Write ( const TE_LIBBSP_ETSEC_Network network, const uint8_t * const v_BuffWrite, const uint32_t v_size);
extern void LIBBSP_ETSEC_Read ( const TE_LIBBSP_ETSEC_Network network,
								uint8_t * const Buffer_read,
								uint32_t * const v_size,
								TE_LIBBSP_ETSEC_FrameStatus * const v_frame_status_out,
								TE_LIBBSP_ETSEC_NetworkStatus * const v_ret);
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_AckError( const TE_LIBBSP_ETSEC_Network network );
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_GetError( const TE_LIBBSP_ETSEC_Network network, TS_LIBBSP_ETSEC_Error * const ErrorStatus );

extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_InitRxTx( const TE_LIBBSP_ETSEC_Network network, const TE_LIBBSP_ETSEC_NetConfigStart network_config);
extern TE_LIBBSP_ETSEC_NetworkStatus LIBBSP_ETSEC_PhyReset( const TE_LIBBSP_ETSEC_Network network);
extern void LIBBSP_ETSEC_GetPhyState( const TE_LIBBSP_ETSEC_Network network, boolean_t * const PhyState, TE_LIBBSP_ETSEC_NetworkStatus *const v_ret);
extern boolean_t LIBBSP_ETSEC_LLRX_Verify(const uint32_t controller);
extern boolean_t LIBBSP_ETSEC_LLTX_Verify(const uint32_t controller);
/*==== END =============================================================================*/
#endif /* LIBBSP_ETSEC_H */
