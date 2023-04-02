#include "BOOT_CLSW_Buffers.h"

#pragma section SECTION_BOOT_LUH_BUFFER "" ".BOOT_LUH_BUFFER"
#pragma use_section SECTION_BOOT_LUH_BUFFER LUH_Buffer
uint8_t LUH_Buffer[C_BOOT_LUH_MAX_LENGTH];

#pragma section SECTION_ARINC_665_FILES_INFO_BUFFER "" ".BOOT_ARINC_665_FILES_INFO_BUFFER"
#pragma use_section SECTION_ARINC_665_FILES_INFO_BUFFER ARINC_665_FilesInfoBuffer
TS_ARINC_665_FileInfo ARINC_665_FilesInfoBuffer[C_BOOT_MAX_NUMBER_OF_FILES];

#pragma section SECTION_FILES_INFO_BUFFER "" ".BOOT_FILES_INFO_BUFFER"
#pragma use_section SECTION_FILES_INFO_BUFFER FilesInfoBuffer
TS_FileInfo FilesInfoBuffer[C_BOOT_MAX_NUMBER_OF_FILES];

#pragma section SECTION_BOOT_SIF_HEADER_BUFFER "" ".BOOT_SIF_HEADER_BUFFER"
#pragma use_section SECTION_BOOT_SIF_HEADER_BUFFER SIF_HeaderBuffer
uint8_t SIF_HeaderBuffer[C_BOOT_SIF_HEADER_MAX_LENGTH];

#pragma section SECTION_BOOT_AES_KEY_BUFFER "" ".BOOT_AES_KEY_BUFFER"
#pragma use_section SECTION_BOOT_AES_KEY_BUFFER AES_KeyBuffer
uint8_t AES_KeyBuffer[C_BOOT_AES_KEY_MAX_LENGTH];

#pragma section SECTION_BOOT_AES_MSK_BUFFER "" ".BOOT_AES_MSK_BUFFER"
#pragma use_section SECTION_BOOT_AES_MSK_BUFFER AES_MaskBuffer
uint8_t AES_MaskBuffer[C_BOOT_AES_KEY_MAX_LENGTH];

#pragma section SECTION_BOOT_CMP_BUFFER "" ".BOOT_CMP_BUFFER"
#pragma use_section SECTION_BOOT_CMP_BUFFER CMP_Buffer
uint8_t CMP_Buffer[C_BOOT_CMP_MAX_LENGTH];

#pragma section SECTION_BOOT_SUP_BUFFER "" ".BOOT_SUP_BUFFER"
#pragma use_section SECTION_BOOT_SUP_BUFFER SUP_Buffer
uint8_t SUP_Buffer[C_BOOT_SUP_MAX_LENGTH];

#pragma section SECTION_BOOT_LUD_BUFFER "" ".BOOT_LUD_BUFFER"
#pragma use_section SECTION_BOOT_LUD_BUFFER LUD_Buffer
uint8_t LUD_Buffer[C_BOOT_LUD_MAX_LENGTH];

/*Buffer for LUP integrity check in flash*/
#pragma section SECTION_BOOT_LUP_FIC_BUFFER "" ".BOOT_LUP_FIC_BUFFER"
#pragma use_section SECTION_BOOT_LUP_FIC_BUFFER FlashIntegrityCheckLUP_Buffer
uint8_t FlashIntegrityCheckLUP_Buffer[C_BOOT_FLASH_INTEGRITY_LUP_BUFFER_SIZE];