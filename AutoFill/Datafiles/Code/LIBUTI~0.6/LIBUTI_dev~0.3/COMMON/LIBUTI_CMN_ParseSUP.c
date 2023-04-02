#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_MatchingFiles.h"

typedef struct{
    uint16_t SUP_Size;
    uint16_t SUP_Version;
    uint16_t NumberOfLUP_Files;
}__attribute__((packed)) TS_SUP_FileConstantSizeFirstFields;

typedef struct{
    uint8_t LUP_Name[C_FILE_NAME_MAX_LENGTH];
    uint16_t LUP_Type;
    uint16_t LUP_EncryptionStatus;
    uint8_t* LUP_DestinationAddress;
    uint32_t LUP_EntryPointDelta;
    uint16_t LUP_EncryptedCRC16;
}__attribute__((packed)) TS_SUP_LUP_Infos;

#define C_MAIN_APPLICATION_FILE 0x0000

#define C_NOT_ENCRYPTED 0x0000
#define C_ENCRYPTED 0x0001

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on SupportFilesInfo. Poiter used as buffer with sup file infos in it.*/
/*Can't use anrray because size depend on number infos in it.*/
/*Overflow avoid by check index_bis<NumberOfDataFiles in the for instruction*/

void LIBUTI_CMN_ParseSUP
(
/*IN*/
    const uint8_t* const SUP_Address,
    const uint32_t NumberOfDataFiles,
/*INOUT*/
    TS_FileInfo* const DataFilesInfo,
/*OUT*/
    boolean_t* const LaunchAddressFound,
    uint8_t** const LaunchAddress,
    boolean_t* const OutOfOperationalConditionSUP
)
{
    uint32_t index;
    uint32_t index_bis;
    /*uint32_t index_ter;*/
    boolean_t DataFileFound;
    boolean_t MatchingFileName;
    TS_SUP_LUP_Infos* SUP_LUP_InfoIterator;
    
    *OutOfOperationalConditionSUP = FALSE;
    *LaunchAddressFound = FALSE;
    
    if((uint32_t)(((TS_SUP_FileConstantSizeFirstFields*)SUP_Address)->NumberOfLUP_Files) /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion from generic ptr to ptr to specific structure */
        != NumberOfDataFiles)
    {
        *OutOfOperationalConditionSUP = TRUE;
        return;
    }
    SUP_LUP_InfoIterator = (TS_SUP_LUP_Infos*)((uint32_t)SUP_Address /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
        + sizeof(TS_SUP_FileConstantSizeFirstFields));
    for(index=((uint32_t) 0);index<NumberOfDataFiles;index++)
    {
        DataFileFound = FALSE;
        for(index_bis=((uint32_t) 0);index_bis<NumberOfDataFiles;index_bis++)
        {
			/*
            MatchingFileName = TRUE;
            for(index_ter=((uint32_t) 0);
                index_ter<((uint32_t) DataFilesInfo[index].ARINC_665_FileInfo->NameLength);index_ter++)
            {
                if(DataFilesInfo[index].ARINC_665_FileInfo->Name[index_ter]
                    != SUP_LUP_InfoIterator[index_bis].LUP_Name[index_ter])
                {
                    MatchingFileName = FALSE;
                    break;
                }
            }
			*/
			LIBUTI_CMN_MatchingFiles(DataFilesInfo[index].ARINC_665_FileInfo->Name, DataFilesInfo[index].ARINC_665_FileInfo->NameLength, SUP_LUP_InfoIterator[index_bis].LUP_Name, &MatchingFileName);

            if(MatchingFileName)
            {
                DataFileFound = TRUE;
                DataFilesInfo[index].Address
                    = SUP_LUP_InfoIterator[index_bis].LUP_DestinationAddress;
                if (SUP_LUP_InfoIterator[index_bis].LUP_EncryptionStatus == (uint16_t)C_ENCRYPTED)
                {
                    DataFilesInfo[index].Encrypted = TRUE;
                }
                else
                {
                    DataFilesInfo[index].Encrypted = FALSE;
                }
                DataFilesInfo[index].ExpectedCRC16
                    = SUP_LUP_InfoIterator[index_bis].LUP_EncryptedCRC16;
                if(SUP_LUP_InfoIterator[index_bis].LUP_Type == (uint16_t)C_MAIN_APPLICATION_FILE)
                {
                    if(*LaunchAddressFound == FALSE)
                    {
                        *LaunchAddress = (uint8_t*)(((uint32_t)SUP_LUP_InfoIterator[index_bis].LUP_DestinationAddress) /*%RELAX<SYNCHRONe_C_Code_10.7, SYNCHRONe_C_Code_11.1> Pointer conversion because explicit computation of adress */
                            + SUP_LUP_InfoIterator[index_bis].LUP_EntryPointDelta);
                        *LaunchAddressFound = TRUE;
                    }
                    else
                    {
                        *OutOfOperationalConditionSUP = TRUE;
                        return;
                    }
                }
                break;
            }
        }
        if(DataFileFound == FALSE)
        {
            *OutOfOperationalConditionSUP = TRUE;
            return;
        }
    }
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */