/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ICDL_LG_PUBLIC_H
#define ICDL_LG_PUBLIC_H

/* ---------- include required interface: ----------------------------------- */
#include "type/common_type.h"
#include "middleware/icdl/ICDL_PLT_public.h"
#include "middleware/stack_ip/ETH_COMM_public.h"
#include "libtools/memory/LIB_MEM_public.h"

/* ---------- provided define constants: ------------------------------------ */
/*
 * Maximum number of command each channel can handle simultaneously
 */
#define CAPACITY_CMDLIST_DATA_LOG    1
#define CAPACITY_CMDLIST_TEMP_STREAM 1
#define CAPACITY_CMDLIST_POWERUPCOUNT 1
#define CAPACITY_CMDLIST_LASTPWRUPTIME 1
#define CAPACITY_CMDLIST_SECU_ALERT_ACK 1
#define CAPACITY_CMDLIST_SEND_TO_MU 1
#define CAPACITY_CMDLIST_TEST 1
#define ICDL_MAX_COMMANDS_PER_TYPE   1
#define ICDL_NUMBER_OF_COMMAND_LIST  7
#define ICDL_NUMBER_OF_COMMANDS      7

#define K_MAX_NB_CHANNEL ((uint32_t) 2)

#define K_SHIFT_CHANNEL_BLOCK_LENGTH ((uint32_t) 16)
#define K_MASK_CHANNEL_BLOCK_LENGTH ((uint32_t) 0xFFFF0000)
#define K_SHIFT_NB_ARG ((uint32_t) 10)
#define K_MASK_NB_ARG ((uint32_t) 0x0000FC00)
#define K_MASK_CHANNEL_BLOCK_LENGTH ((uint32_t) 0xFFFF0000)
#define K_SHIFT_DATA ((uint32_t) 9)
#define K_MASK_DATA ((uint32_t) 0x00000200)
#define K_SHIFT_COMMAND ((uint32_t) 0)
#define K_MASK_COMMAND ((uint32_t) 0x000001FF)

/**
 * Definition of the number of bytes in a 32-bits word */
#define K_NB_BYTES_IN_32_BITS ((uint32_t) 4)

/**
 * Number of 32 bits words composing the command charateristic
  */
#define K_COMMAND_CHARACT_LENGTH ((uint32_t) 1)

/* Event Block Command Characteristics */
#define K_DATA_LOG_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (8))
#define K_DATA_LOG_CMD_NB_ARG ((uint32_t) 1)
#define K_DATA_LOG_CMD_DATA_BOOL_FIELD ((uint32_t) 1)
#define K_DATA_LOG_CMD_IDENTIFIER ((uint32_t) 0x101)

#define K_TEMP_STREAM_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (8))
#define K_TEMP_STREAM_CMD_NB_ARG ((uint32_t) 1)
#define K_TEMP_STREAM_CMD_DATA_BOOL_FIELD ((uint32_t) 1)
#define K_TEMP_STREAM_CMD_IDENTIFIER ((uint32_t) 0x102)

#define K_POWERUPCOUNT_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (4))
#define K_POWERUPCOUNT_CMD_NB_ARG ((uint32_t) 0)
#define K_POWERUPCOUNT_CMD_DATA_BOOL_FIELD ((uint32_t) 0)
#define K_POWERUPCOUNT_CMD_IDENTIFIER ((uint32_t) 0x120)

#define K_LASTPWRUPTIME_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (4))
#define K_LASTPWRUPTIME_CMD_NB_ARG ((uint32_t) 0)
#define K_LASTPWRUPTIME_CMD_DATA_BOOL_FIELD ((uint32_t) 0)
#define K_LASTPWRUPTIME_CMD_IDENTIFIER ((uint32_t) 0x121)

#define K_SECU_ALERT_ACK_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (4))
#define K_SECU_ALERT_ACK_CMD_NB_ARG ((uint32_t) 0)
#define K_SECU_ALERT_ACK_CMD_DATA_BOOL_FIELD ((uint32_t) 0)
#define K_SECU_ALERT_ACK_CMD_IDENTIFIER ((uint32_t) 0x110)

#define K_SEND_TO_MU_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (4))
#define K_SEND_TO_MU_CMD_NB_ARG ((uint32_t) 0)
#define K_SEND_TO_MU_CMD_DATA_BOOL_FIELD ((uint32_t) 0)
#define K_SEND_TO_MU_CMD_IDENTIFIER ((uint32_t) 0xC5)

#define K_TEST_CMD_CH_BLK_LENGTH_WO_DATA ((uint32_t) (4))
#define K_TEST_CMD_NB_ARG ((uint32_t) 0)
#define K_TEST_CMD_DATA_BOOL_FIELD ((uint32_t) 0)
#define K_TEST_CMD_IDENTIFIER ((uint32_t) 0x0C1)

/**
 * Index (offset) of the the ARG SET in ArgumentSetAndDataSet
 */
#define K_ARG_SET_BUFFER_IDX ((uint32_t) (0))

/**
 * Index (offset) of the DATA SET section
 */
#define K_DATA_SET_BUFFER_IDX ((uint32_t) (K_ARG_SET_BUFFER_IDX + 4))

/**
 * Number of 32 bits words composing the command charateristic
  */
#define K_COMMAND_CHARACT_LENGTH ((uint32_t) 1)

/**
 * Maximal size of the ARGUMENT_SET in a functional frame
 * expressed in Bytes
 */
#define K_ARGUMENT_SET_AND_DATA_SET_MAX_SIZE ((uint32_t) 100)

#define UNDEF_CHANNEL              -1

/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   /** Length of the command stored in the channel */
   uint16_t u16_ChannelBlockLength;
   /** Number of arguments associated to the command stored in the
    * channel */
   uint16_t u16_NbArg;
   /** Indicator of presence of data within the command stored
    * in the channel */
   boolean_t bool_Data;
   /** Command identifier of the command stored in the channel */
   uint16_t u16_Command;
} t_CmdCharacteristics;

typedef enum
{
   ID_CMD_NONE                = 0x00000000,
   ID_CMD_DATA_LOG            = 0x00000001,
   ID_CMD_TEMP_STREAM         = 0x00000002,
   ID_CMD_POWERUPCOUNT        = 0x00000003,
   ID_CMD_LASTPWRUPTIME       = 0x00000004,
   ID_CMD_SECU_ALERT_ACK      = 0x00000005,
   ID_CMD_SEND_TO_MU          = 0x00000006,
   ID_CMD_TEST                = 0x00000007
} t_command_id;


typedef enum
{
   ID_CMDLIST_NONE            = ID_CMD_NONE,
   ID_CMDLIST_DATA_LOG        = ID_CMD_DATA_LOG,
   ID_CMDLIST_TEMP_STREAM     = ID_CMD_TEMP_STREAM,
   ID_CMDLIST_POWERUPCOUNT    = ID_CMD_POWERUPCOUNT,
   ID_CMDLIST_LASTPWRUPTIME   = ID_CMD_LASTPWRUPTIME,
   ID_CMDLIST_SECU_ALERT_ACK  = ID_CMD_SECU_ALERT_ACK,
   ID_CMDLIST_SEND_TO_MU      = ID_CMD_SEND_TO_MU,
   ID_CMDLIST_TEST            = ID_CMD_TEST
} t_command_list_id;

typedef struct {
   t_command_id            id;
   t_CmdCharacteristics    s_CmdCharacteristics;
   ts_PortUdpInfo          ethUdpInfo;
} t_command_descriptor;

typedef enum
{
   FLAG_IN_PROGRESS  = 0x01,
   FLAG_AVAILABLE    = 0x02
} t_command_flag;


typedef struct t_command_st
{
   t_command_id          e_id;
   t_command_flag        e_flag;
   t_command_descriptor  *st_descriptor;
   uint32_t              u32_channel_id;
   ts_CMN_IOSP_BUFFER    udpBuffer;
} t_command;

typedef struct
{
   t_command_list_id     e_id;
   uint32_t              u32_commands_number;
   t_command             st_commands[ICDL_MAX_COMMANDS_PER_TYPE];
} t_command_list;

typedef enum
{
   /** The channel is ready for the encoding of a functional frame */
   E_READY_FOR_FF_USE = 0x00000001,
   /** The encoded functional frame is ready for transmission */
   E_READY_FOR_FF_TRANSMISSION = 0x00000030,
   /** The transmission of the functional frame is in progress */
   E_FF_TRANSMISSION_IN_PROGRESS = 0x000000C0
} t_FFStatus_E;

typedef struct
{
   /** 32-bit word holding the COMMAND_CHARACTERISTICS section information
    * (COMMAND, BOOLEAN_DATA, NB_ARGUMENT, FUNCTIONAL_FRAME_LENGTH) */
   uint32_t u32_CmdCharacteristicsWord;

   /** Pointer on a buffer holding ARGUMENT_SET and DATA_SET sections of a
    * command or result */
   uint8_t a_ArgumentSetAndDataSet[K_ARGUMENT_SET_AND_DATA_SET_MAX_SIZE];
} t_FunctionalFrame;

typedef struct
{
   /** Status of communication (processing progress indicator) */
   t_FFStatus_E e_Status;
   /** Indicates the command received */
   uint32_t u32_CommandType ;
   /** Size of the functional frame hold in p_ElectedFFInfo */
   uint32_t u32_Size;
   /** Pointer on the functional frame to be sent or decoded */
   t_FunctionalFrame * p_ElectedFFInfo;
   /** Port Src/dst of the functional frame */
   ts_PortUdpInfo ethUdpInfo;
} t_ChannelDescriptor;

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided datas: ----------------------------------------------- */
extern t_ChannelDescriptor *   p_ElectedFFInTransmission;
extern t_command_list          command_list[ICDL_NUMBER_OF_COMMAND_LIST];
extern t_command_descriptor    command_descriptor[ICDL_NUMBER_OF_COMMANDS];
extern const t_command_list       c_command_list[ICDL_NUMBER_OF_COMMAND_LIST];
extern const t_command_descriptor c_command_descriptor[ICDL_NUMBER_OF_COMMANDS];
extern t_ChannelDescriptor     a_ChannelDescriptors[K_MAX_NB_CHANNEL];
extern t_FunctionalFrame       a_FunctionalFrames[K_MAX_NB_CHANNEL] ;


/* ---------- provided operations: ------------------------------------------ */
extern boolean_t ICDL_LG_ChangeChannelStatus(const uint32_t p_ChannelID, t_FFStatus_E p_NewState);

extern void ICDL_LG_ComputeMsgDataSet(int8_t * const p_buff_addr , uint32_t const p_buff_size, t_command *p_command_ptr);

extern void ICDL_LG_ComputeMsgArgSet(int8_t * const p_buff_addr , uint32_t const p_buff_size, t_command *p_command_ptr);

extern void ICDL_LG_FillChannelFirstFunctionnalWord(uint32_t p_ChannelID, const t_CmdCharacteristics * const p_CmdCharacteristics , uint32_t p_data_size);

extern void ICDL_LG_GetChannelArgDataBuffer(const uint32_t p_ChannelID, uint8_t ** p_ArgDataBuffer );

extern t_FFStatus_E ICDL_LG_GetChannelStatus(const uint32_t p_ChannelID);

extern boolean_t ICDL_LG_GetChannelToFree(uint32_t * p_ChannelId);

extern t_command_descriptor *ICDL_LG_GetCommandDescriptor(t_command_id  p_command_id);

extern boolean_t ICDL_LG_GetFreeChannelID(uint32_t *p_ChannelId);

extern boolean_t ICDL_LG_InitializeChannel(const uint32_t p_ChannelId);

extern boolean_t ICDL_LG_PrepareTxChannel(t_command *p_command_ptr);

extern void ICDL_LG_RemoveCommand(t_command  *p_command_ptr);

extern boolean_t ICDL_LG_SearchFuncFrameToTransmit(uint32_t * p_ChannelId);

extern void ICDL_LG_SendCommand(t_command *p_command_ptr);

extern void ICDL_LG_SetCmdType(const uint32_t p_ChannelId, const uint32_t p_CmdType);

extern void ICDL_LG_SetUDPPorts(const uint32_t p_ChannelId, const uint32_t p_PortsSrc, const uint32_t p_PortsDst);

extern t_command *ICDL_LG_TriggerCommand(t_command_id p_command_id, uint16_t p_dataSize);

extern void ICDL_LG_UpdateFFLength (const uint32_t p_ChannelID, const uint32_t p_Size);

extern uint32_t ICDL_LG_EncodeWordOn32Bits(uint32_t p_initial_value, uint32_t p_value_to_encode, uint32_t p_offset, uint32_t p_mask);

extern boolean_t ICDL_LG_Init(void);

#endif /* ICDL_LG_PUBLIC_H */

