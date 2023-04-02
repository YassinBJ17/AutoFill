/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/MID_ICDL_public.h"

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/icdl/ICDL_public.h"
#include "driver/mailbox/MBX_HAL_public.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/ethernet/ETH_porting.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"

/* ---------- internal define constants: ------------------------------------ */



/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */
const ICDL_command_type ICDL_command_list[ICDL_NB_COMMAND] =
{
   /* #FREAD */
   {
      {
         FREAD,
         0,
         4,
         144
      },
      PORT_49400,
   },

   /* #FWRITE */
   {
      {
         FWRITE,
         1,
         5,
         148
      },
      PORT_49400,
   },

   /* #Send_to_MU */
   {
      {
         SEND_TO_MU,
         1,
         1,
         251
      },
      PORT_50000,
   },

   /* #LOG */
   {
      {
         LOG,
         1,
         1,
         8
      },
      PORT_49500,
   },

   /* #TECU_STREAM */
   {
      {
         TECU_STREAM,
         1,
         1,
         8
      },
      PORT_49700,
   },

   /* #SECU_ALERT_ACK */
   {
      {
         SECU_ALERT_ACK,
         0,
         0,
         4
      },
      PORT_49200,
   },

   /* #POWERUPCOUNT */
   {
      {
         POWERUPCOUNT,
         0,
         1,
         8
      },
      PORT_49900,
   },

   /* #LASTPWRUPTIME */
   {
      {
         LASTPWRUPTIME,
         0,
         1,
         8
      },
      PORT_49300,
   },

   /* #MU_Alive */
   {
      {
         MU_ALIVE,
         1,
         4,
         5
      },
      PORT_49300,
   }
};


const ICDL_port_list_type c_os_port_list[ICDL_OS_NB_PORT] =
{
   PORT_49100, /* LASTPWRUPTIME_CMD */
   PORT_49200, /* SECU_ALERT_ACK_CMD */
   PORT_49300, /* MU_ALIVE_CMD */
   PORT_49500, /* DATA_LOG_CMD */
   PORT_49700, /* TEMP_CMD */
   PORT_49900  /* POWERUPCOUNT_CMD */
};

/* UOD PORT */
/*#define K_UOD_UDP_PORTS_SRC      (uint32_t)49800*/


/* ---------- internal data: ------------------------------------------------ */
int32_t   g_init_log_sent;
int32_t   g_compteur_htr;
int32_t   g_compteur_htr_init_log_sent;
int32_t   g_pltf_log_sent;
boolean_t g_mu_is_alive;

te_ETH_UDP_PORT_Status v_ETH_Init_status;



/* ---------- provided data: ------------------------------------------------ */


/* ---------- provided operation bodies: ------------------------------------ */
/*---------------------------------------------------------------------------
-- mid_icdl_init
---------------------------------------------------------------------------*/
void mid_icdl_init ( void )
{
   uint32_t i;
   ts_CMN_IOSP_BUFFER buffer;

   v_ETH_Init_status = e_ETH_UDP_PORT_ACTION_FAILED;

   /* Initialize Ethernet - Mailbox - Mac Eth - ICDL */
   DRV_COM_MNT_ETH_INIT();
   ICDL_PLT_Init();

   /* Create OS ports  */
   for ( i = 0; i < ICDL_OS_NB_PORT; i++ )
   {
      buffer.s_buffer = (int8_t*)(&(udpOSBuffer[i]));
      buffer.s_buffer_size = sizeof(udpOSBuffer[i]);
      DRV_COM_MNT_ETH_HANDLE_PORT( K_OPEN_PORT,
                                   c_os_port_list[i],
                                   e_CMN_FLAG_NO,
                                   (ts_CMN_IOSP_BUFFER *)&(buffer),
                                   &v_ETH_Init_status );
   }


   /* Create UOD port  */
   shmem.s_icdl_rx.rx_message_tab[ICDL_UOD_MSG_INDEX].s_port = K_UOD_UDP_PORTS_SRC;
   shmem.s_icdl_tx.tx_message_tab[ICDL_UOD_MSG_INDEX].s_port = K_UOD_UDP_PORTS_SRC;
   buffer.s_buffer = (int8_t*)(&udpUODBuffer[0]);
   buffer.s_buffer_size = sizeof(udpUODBuffer);
   DRV_COM_MNT_ETH_HANDLE_PORT( K_OPEN_PORT,
                                K_UOD_UDP_PORTS_SRC,
                                e_CMN_FLAG_YES,
                                (ts_CMN_IOSP_BUFFER *)&(buffer),
                                &v_ETH_Init_status );


   g_init_log_sent = 0u;
   g_compteur_htr  = 0u;
   g_compteur_htr_init_log_sent = 0u;
   g_pltf_log_sent = 0u;
   g_mu_is_alive   = FALSE;
}
