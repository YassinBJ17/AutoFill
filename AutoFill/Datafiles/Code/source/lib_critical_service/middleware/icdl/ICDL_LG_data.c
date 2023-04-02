/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION :
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "middleware/icdl/ICDL_LG_public.h"

/* ---------- internal define constants: ------------------------------------ */
#define NO_DATA 0

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal data: ------------------------------------------------ */
t_ChannelDescriptor a_ChannelDescriptors[K_MAX_NB_CHANNEL];

t_ChannelDescriptor * p_ElectedFFInTransmission;

t_FunctionalFrame a_FunctionalFrames[K_MAX_NB_CHANNEL] ;

const t_command_list c_command_list[ICDL_NUMBER_OF_COMMAND_LIST] =
{
   {
      ID_CMDLIST_DATA_LOG, /* e_id */
      CAPACITY_CMDLIST_DATA_LOG, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   },
   {
      ID_CMDLIST_TEMP_STREAM, /* e_id */
      CAPACITY_CMDLIST_TEMP_STREAM, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   },
   {
      ID_CMDLIST_POWERUPCOUNT, /* e_id */
      CAPACITY_CMDLIST_POWERUPCOUNT, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   },
   {
      ID_CMDLIST_LASTPWRUPTIME, /* e_id */
      CAPACITY_CMDLIST_LASTPWRUPTIME, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   },
   {
      ID_CMDLIST_SECU_ALERT_ACK, /* e_id */
      CAPACITY_CMDLIST_SECU_ALERT_ACK, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   },
   {
      ID_CMDLIST_SEND_TO_MU, /* e_id */
      CAPACITY_CMDLIST_SEND_TO_MU, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   },
   {
      ID_CMDLIST_TEST, /* e_id */
      CAPACITY_CMDLIST_TEST, /* u32_commands_number */
      {
         ID_CMD_NONE, /* e_id */
         FLAG_AVAILABLE, /* e_flag */
         NULL, /* *st_descriptor */
         NO_DATA, /* u32_channel_id */
         NULL, /* *s_buffer */
         NO_DATA /* s_buffer_size */
      }
   }
};

const t_command_descriptor c_command_descriptor[ICDL_NUMBER_OF_COMMANDS] =
{
   {
      ID_CMD_DATA_LOG,
      {
         K_DATA_LOG_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_DATA_LOG_CMD_NB_ARG,
         K_DATA_LOG_CMD_DATA_BOOL_FIELD,
         K_DATA_LOG_CMD_IDENTIFIER
      }
   },
   {
      ID_CMD_TEMP_STREAM,
      {
         K_TEMP_STREAM_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_TEMP_STREAM_CMD_NB_ARG,
         K_TEMP_STREAM_CMD_DATA_BOOL_FIELD,
         K_TEMP_STREAM_CMD_IDENTIFIER
      }
   },
   {
      ID_CMD_POWERUPCOUNT,
      {
         K_POWERUPCOUNT_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_POWERUPCOUNT_CMD_NB_ARG,
         K_POWERUPCOUNT_CMD_DATA_BOOL_FIELD,
         K_POWERUPCOUNT_CMD_IDENTIFIER
      }
   },
   {
      ID_CMD_LASTPWRUPTIME,
      {
         K_LASTPWRUPTIME_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_LASTPWRUPTIME_CMD_NB_ARG,
         K_LASTPWRUPTIME_CMD_DATA_BOOL_FIELD,
         K_LASTPWRUPTIME_CMD_IDENTIFIER
      }
   },
   {
      ID_CMD_SECU_ALERT_ACK,
      {
         K_SECU_ALERT_ACK_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_SECU_ALERT_ACK_CMD_NB_ARG,
         K_SECU_ALERT_ACK_CMD_DATA_BOOL_FIELD,
         K_SECU_ALERT_ACK_CMD_IDENTIFIER
      }
   },
   {
      ID_CMD_SEND_TO_MU,
      {
         K_SEND_TO_MU_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_SEND_TO_MU_CMD_NB_ARG,
         K_SEND_TO_MU_CMD_DATA_BOOL_FIELD,
         K_SEND_TO_MU_CMD_IDENTIFIER
      }
   },
   {
      ID_CMD_TEST,
      {
         K_TEST_CMD_CH_BLK_LENGTH_WO_DATA, /* u16_ChannelBlockLength */
         K_TEST_CMD_NB_ARG,
         K_TEST_CMD_DATA_BOOL_FIELD,
         K_TEST_CMD_IDENTIFIER
      }
   }
};

t_command_list       command_list[ICDL_NUMBER_OF_COMMAND_LIST];
t_command_descriptor command_descriptor[ICDL_NUMBER_OF_COMMANDS];
