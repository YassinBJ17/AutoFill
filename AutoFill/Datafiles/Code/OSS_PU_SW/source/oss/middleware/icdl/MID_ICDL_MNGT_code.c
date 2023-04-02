/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
#include "middleware/icdl/MID_ICDL_public.h"
#include "type/common_type.h"
#include "conf/oss_conf_public.h"
#include "memory/lib_critical_service_section_def_data.h"
#include "middleware/stack_ip/ETH_public.h"
#include "middleware/stack_ip/ETH_UDP_public.h"
#include "middleware/stack_ip/ETH_UDP_private.h"
#include "middleware/icdl/ICDL_public.h"

#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/ethernet/DRV_COM_MNT_ETH_public.h"

#include "libtools/memory/LIB_MEM_public.h"
#include "middleware/logbook/logbook_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define TECU_STREAM_NB_SENSORS 2

/* ---------- internal types: ----------------------------------------------- */
#define ICDL_LGBK_FIELD_DEFAULT_VALUE ((uint32_t)0x00000000)

/* temporary values */
#define OSS_PN                         (uint32_t)0xAAAAAAAA
#define OSS_COMPATIBIITY_INDEX         (uint32_t)0xBBBBBBBB
#define DATALOADER_PN                  (uint32_t)0xCCCCCCCC
#define DATALOADER_COMPATIILITY_INDEX  (uint32_t)0xDDDDDDDD
#define CALC_PN                        (uint32_t)0xEEEEEEEE
#define CALC_SN                        (uint32_t)0xA1B2C3E4

/* temporary struct for trigger log */
typedef struct
{
   uint32_t s_orig_id;              /* Origin ID */
   uint32_t s_event_id;             /* Event ID */
   uint32_t s_timestamp;            /* Time of event */
   uint32_t s_pwr_up_counter;       /* Power-up counter of the platform */

   uint32_t s_exc_context_1;        /* Context */
   uint32_t s_raw_data_1;           /* Part 1 of the raw data */
   uint32_t s_raw_data_2;           /* Part 2 of the raw data */
   uint32_t s_short_occ_cnt;        /* ShortOccurrenceCounter */
   uint32_t s_long_occ_cnt;         /* LongOccurrenceCounter */

   uint32_t s_health_word;          /* health_word */

   uint32_t s_temp_calc_pn;         /* Internal and external temperatures or calculator part number */
   uint32_t s_speed_calc_sn;        /* NGOS and NGALT speeds or calculator serial number */

   uint32_t s_mission_id;           /* Identifier of the mission */
}
ts_trigger_block;

/* For debug */
#if 1
#include "libtools/time/LIB_TIME_public.h"
int64_t g_send_data_log_time;
#endif
/* */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */
/*---------------------------------------------------------------------------
-- mid_icdl_mngt
---------------------------------------------------------------------------*/
void mid_icdl_mngt ( const boolean_t p_channel_is_a )
{
   /* Local variables */
   boolean_t readState;
   ts_event_block v_event_block, v_trigger_log;
   ts_temp_stream_log v_temp_stream_log;
   uint32_t mu_alive_status;

   te_ETH_UDP_PORT_Status l_eth_status;
   ts_CMN_IOSP_BUFFER buffer;
   uint32_t i;
#if 1
   int64_t current_time_beg, current_time_end;
#endif
   g_compteur_htr = ( g_compteur_htr + 1 ) % 0x7FFFFFFF;

   for ( i = 0; i < ICDL_AS_NB_PORT; i++ )
   {
      /* create Rx ports */
      if ( shmem.s_icdl_rx.rx_message_tab[i].s_port != 0 )
      {
         buffer.s_buffer = (int8_t*)(&(shmem.s_icdl_rx.rx_message_tab[i].s_data_buffer));
         buffer.s_buffer_size = shmem.s_icdl_rx.rx_message_tab[i].s_length;
         DRV_COM_MNT_ETH_HANDLE_PORT( K_OPEN_PORT,
                                      shmem.s_icdl_rx.rx_message_tab[i].s_port,
                                      e_CMN_FLAG_NO,
                                      (ts_CMN_IOSP_BUFFER *)&(buffer),
                                      &l_eth_status );
      }
   }

   DRV_COM_MNT_ETH_HANDLE_RECEPTION();

#if 0
   if ( ( g_compteur_htr % (13u) ) == 0u )
   {
      icdl_read();
      icdl_write();
   }
#endif

   /* #MU_ALIVE frame */
   /* Need to wait MU_ALIVE frame before starting communication with CDM */
   if ( g_mu_is_alive == FALSE )
   {
      uint32_t size;
      uint8_t pt_buff[64];

      mu_alive_status = ICDL_PLT_ReceiveMuAlive( pt_buff, &size );
      if ( mu_alive_status == TRUE )
      {
         g_mu_is_alive = TRUE;
         if(size > 4)
         {
            size = 4;
         }
         LIB_MEM_CPY( (int8_t*)&(shmem.s_cdm_state.mu_alive_frame), (int8_t*)pt_buff, size * 4 );
      }
      else
      {
         LIB_MEM_SET( (int8_t*)&(shmem.s_cdm_state.mu_alive_frame), 0, sizeof(shmem.s_cdm_state.mu_alive_frame) );
      }
   }

   if ( g_mu_is_alive == TRUE )
   {
      /* #LOG frame */
      if ( g_init_log_sent == 0u )
      {
         /* Record the default event block in Log Area */
         LIB_MEM_SET( (void *)&v_event_block, 0x0, sizeof(v_event_block) );
         /* TODO recuperer les ID depuis logbook_public.h */
         /* TODO :  => a trouver dans la conf en MRAM */
         /* TODO recuperer le calc_pn et le calc_sn dans la MRAM ?*/

         logbook_fill_event_block ( &v_event_block, /* INIT_LOG_ID */(uint32_t)1, /* CALC_INIT_MODE */ (uint32_t)0x000000A0,
                                    /* SPARE */ 0, OSS_PN, OSS_COMPATIBIITY_INDEX, DATALOADER_PN, DATALOADER_COMPATIILITY_INDEX,
                                    CALC_PN, CALC_SN );

#if 1
         /* Get the current time */
         LIBT_TIME_GET(&current_time_beg);
#endif
         ICDL_PLT_SendDataLog ( &v_event_block , sizeof (v_event_block) , e_INIT_LOG );
#if 1
         /* Get the current time */
         LIBT_TIME_GET(&current_time_end);
         g_send_data_log_time = current_time_end - current_time_beg;
#endif
         g_init_log_sent ++;
         g_compteur_htr_init_log_sent = g_compteur_htr;
      }

      if ( g_init_log_sent == 1u )
      {
         /* send second init log 100ms after first one */
         if ( ( g_compteur_htr_init_log_sent % (10u) == 0u ) && ( g_compteur_htr_init_log_sent > 10u ))
         {
            /* Record the default event block in Log Area */
            LIB_MEM_SET( (void *)&v_event_block, 0x0, sizeof(v_event_block) );
            /* TODO recuperer les ID depuis logbook_public.h */
            /* TODO :  => a trouver dans la conf en MRAM */
            /* TODO recuperer le calc_pn et le calc_sn dans la MRAM ?*/

            logbook_fill_event_block ( &v_event_block, /* INIT_LOG_ID */(uint32_t)1, /* CALC_OPERATIONAL_MODE */ (uint32_t)0x000000B0,
                                       /* SPARE */ 0, OSS_PN, OSS_COMPATIBIITY_INDEX, DATALOADER_PN, DATALOADER_COMPATIILITY_INDEX,
                                       CALC_PN, CALC_SN );
            ICDL_PLT_SendDataLog ( &v_event_block , sizeof (v_event_block) , e_INIT_LOG );
            g_init_log_sent ++;
         }
         else
         {
            g_compteur_htr_init_log_sent ++;
         }
      }

      if ( g_init_log_sent == 2u )
      {
         /* Send PLTF LOG 20ms after second init log */
         if ( ( ( g_compteur_htr_init_log_sent % (2u) ) == 0u ) && ( g_init_log_sent == 2u ) )
         {
            /* PLATEFORM_LOG */
            /* TODO recuperer le platform log */
            /* creer un p_evnt log qui va bien */
            LIB_MEM_SET( (void *)&v_event_block, 0x0, sizeof(v_event_block) );
            logbook_fill_event_block ( &v_event_block, /* INIT_LOG_ID */(uint32_t)1, /* CALC_OPERATIONAL_MODE */ (uint32_t)0x000000B0,
                                       ICDL_LGBK_FIELD_DEFAULT_VALUE, ICDL_LGBK_FIELD_DEFAULT_VALUE,
                                       ICDL_LGBK_FIELD_DEFAULT_VALUE, ICDL_LGBK_FIELD_DEFAULT_VALUE, ICDL_LGBK_FIELD_DEFAULT_VALUE,
                                       /* TODO recuperer le temp_calc  ?*/
                                       /* temp_calc */(uint32_t)0xDECACAFE, /*SPEED_PREBLUE_VALUE*/ (uint32_t)0xCAFEDECA );
            ICDL_PLT_SendDataLog ( &v_event_block , sizeof (v_event_block) , e_PLATFORM_LOG );
            g_init_log_sent ++;
         }
         else
         {
            g_compteur_htr_init_log_sent++;
         }
      }

      /* Send PLTF LOG every 25s */
      if ( ( ( g_compteur_htr % (2500u) ) == 0u ) && ( g_init_log_sent == 3u ) )
      {
         /* TODO recuperer le platform log */
         /* creer un p_evnt log qui va bien */
         LIB_MEM_SET( (void *)&v_event_block, 0x0, sizeof(v_event_block) );
         logbook_fill_event_block ( &v_event_block, /* INIT_LOG_ID */(uint32_t)1, /* CALC_OPERATIONAL_MODE */ (uint32_t)0x000000B0,
                                    ICDL_LGBK_FIELD_DEFAULT_VALUE, ICDL_LGBK_FIELD_DEFAULT_VALUE,
                                    ICDL_LGBK_FIELD_DEFAULT_VALUE, ICDL_LGBK_FIELD_DEFAULT_VALUE, ICDL_LGBK_FIELD_DEFAULT_VALUE,
                                    /* TODO recuperer le temp_calc  ?*/
                                    /* temp_calc */(uint32_t)0xDECACAFE, /*SPEED_PREBLUE_VALUE*/ (uint32_t)0xCAFEDECA );
         ICDL_PLT_SendDataLog ( &v_event_block , sizeof (v_event_block) , e_PLATFORM_LOG );
      }

      /* Send TEMP STREAM LOG every 30s */
      if ( ( ( g_compteur_htr % (3000u) ) == 0u ) && ( g_init_log_sent == 3u ) )
      {
         /* #TECU_STREAM frame */
         LIB_MEM_SET( (void *)&v_temp_stream_log, 0x0, sizeof(v_temp_stream_log) );
         logbook_fill_temp_stream_log ( &v_temp_stream_log, p_channel_is_a );
         ICDL_PLT_SendDataLog ( &v_temp_stream_log , sizeof (v_temp_stream_log) , e_TEMP_STREAM_LOG );
      }

      /* Send TRIGGER LOG if ShortOccurrenceCounter reaches ShortOccurrenceTrigger */
      if ( g_init_log_sent == 3u )
      {
         ts_trigger_block * trigger_block_pt;
         /* declaration of the struc to retrieve conf in MRAM */
         ts_oss_conf_table * oss_conf;
         /* retrieve conf in MRAM */
         oss_conf = (ts_oss_conf_table *)(OSS_CONF_START_ADDR);

         trigger_block_pt = (ts_trigger_block *)&v_trigger_log;

         /* TRIGGER_LOG */
         LIB_MEM_SET( (void *)&v_trigger_log, 0x0, sizeof(v_trigger_log) );
         readState = logbook_read_oldest_trigger_log ( &v_trigger_log );
         /* TODO : ShortOccurrenceTrigger en flash  */
         if ( ( readState == TRUE ) && (trigger_block_pt->s_short_occ_cnt == oss_conf->s_shortoccurrencetrigger ) )
         {
            ICDL_PLT_SendDataLog ( &v_trigger_log , sizeof (v_trigger_log) , e_TRIGGER_LOG );
         }
      }


      /* TODO regarder les dates auxquelles il faut envoyer les logs */
      if ( ( ( g_compteur_htr % (1500u) ) == 0u ) && ( g_init_log_sent == 3u ) )
      {
         /* CRITICAL_LOG */
         LIB_MEM_SET( (void *)&v_event_block, 0x0, sizeof(v_event_block) );
         readState = logbook_read_oldest_critical_log ( &v_event_block );
         if ( readState == TRUE )
         {
            ICDL_PLT_SendDataLog ( &v_event_block , sizeof (v_event_block) , e_CRITICAL_LOG );
         }
      }

      if ( g_init_log_sent == 3u )
      {
         /* #LASTPWRUPTIME frame */
         if ( ( g_compteur_htr % (10u) ) == 0u )
         {
            ICDL_PLT_SendLastPwrUptime( &(shmem.s_oss_counter.s_last_power_up_time), sizeof (uint32_t) );
         }

         /* #POWERUPCOUNT frame */
         if ( ( g_compteur_htr % (11u) ) == 0u )
         {
            ICDL_PLT_SendPowerUpCount( &(shmem.s_oss_counter.s_pw_up_count), sizeof (uint32_t) );
         }

         /* #SECU_ALERT_ACK frame */
         if ( ( g_compteur_htr % (12u) ) == 0u )
         {
            uint32_t dummy = 0x41434b00; /* ACK */
            boolean_t secu_alert_status;
            secu_alert_status = ICDL_PLT_ReceiveSecuAlert();
            if ( secu_alert_status != FALSE )
            {
               /* if receive secu alert */
               /* TODO : quoi faire sur reception de l'alerte ??? */
               ICDL_PLT_SendSecuAlertAck( &dummy, sizeof (uint32_t) );
            }
         }

      }
   }

   return;
}
