#ifndef _BOOT_CLSW_BUFFERS_
#define _BOOT_CLSW_BUFFERS_

#include "LIBUTI_ARINC_665.h"
#include "LIBUTI_COMMON.h"
#include "BOOT_Consts.h"


extern uint8_t LUH_Buffer[C_BOOT_LUH_MAX_LENGTH];
extern TS_ARINC_665_FileInfo ARINC_665_FilesInfoBuffer[C_BOOT_MAX_NUMBER_OF_FILES];
extern TS_FileInfo FilesInfoBuffer[C_BOOT_MAX_NUMBER_OF_FILES];
extern uint8_t SIF_HeaderBuffer[C_BOOT_SIF_HEADER_MAX_LENGTH];
extern uint8_t AES_KeyBuffer[C_BOOT_AES_KEY_MAX_LENGTH];
extern uint8_t AES_MaskBuffer[C_BOOT_AES_KEY_MAX_LENGTH];
extern uint8_t CMP_Buffer[C_BOOT_CMP_MAX_LENGTH];
extern uint8_t SUP_Buffer[C_BOOT_SUP_MAX_LENGTH];
extern uint8_t LUD_Buffer[C_BOOT_LUD_MAX_LENGTH];
extern uint8_t FlashIntegrityCheckLUP_Buffer[C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE];

#endif