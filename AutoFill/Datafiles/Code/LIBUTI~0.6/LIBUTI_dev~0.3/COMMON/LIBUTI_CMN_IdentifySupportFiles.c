#include "LIBUTI_COMMON.h"
#include "LIBUTI_CMN_TestSupportFile.h"

void LIBUTI_CMN_IdentifySupportFiles
(
/*IN*/
    const uint32_t NumberOfSupportFiles,
    const TS_FileInfo* const SupportFilesInfo,
/*OUT*/
    boolean_t* const CMP_FileFound,
    const TS_FileInfo** const CMP_FileInfo,
    boolean_t* const SUP_FileFound,
    const TS_FileInfo** const SUP_FileInfo,
    boolean_t* const LUD_FileFound,
    const TS_FileInfo** const LUD_FileInfo,
    boolean_t* const SIF_FileFound,
    const TS_FileInfo** const SIF_FileInfo,
    boolean_t* const SKF_FileFound,
    const TS_FileInfo** const SKF_FileInfo,
    boolean_t* const OutOfOperationalConditionLoad
)
{
    uint32_t index;
    uint32_t FileNameLengthBuffer;
    uint8_t* FileNameAddressBuffer;
	boolean_t FileFound;
	
	const uint8_t CMP[4] = {'.','C','M','P'};
	const uint8_t SUP[4] = {'.','S','U','P'};
	const uint8_t LUD[4] = {'.','L','U','D'};
	const uint8_t SIF[4] = {'.','S','I','F'};
	const uint8_t SKF[4] = {'.','S','K','F'};
    
    *CMP_FileFound = FALSE;
    *SUP_FileFound = FALSE;
    *LUD_FileFound = FALSE;
    *SIF_FileFound = FALSE;
    *SKF_FileFound = FALSE;
    *OutOfOperationalConditionLoad = FALSE;
    for(index=0ul; index < NumberOfSupportFiles; index++)
    {
		if (*OutOfOperationalConditionLoad != FALSE){
			break;
		}
		/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on SupportFilesInfo. Poiter used as buffer with support files infos in it.*/
		/*Can't use anrray because size depend on number of sup files.*/
		/*Overflow avoid by check index<NumberOfSupportFiles in the for instruction*/
        FileNameLengthBuffer = (uint32_t)(SupportFilesInfo[index].ARINC_665_FileInfo->NameLength);
        FileNameAddressBuffer = (uint8_t*)(SupportFilesInfo[index].ARINC_665_FileInfo->Name);

		FileFound = LIBUTI_CMN_TestSupportFile(FileNameLengthBuffer , FileNameAddressBuffer, &(SupportFilesInfo[index]), CMP, CMP_FileFound, CMP_FileInfo, OutOfOperationalConditionLoad);
		if(FileFound != FALSE)
		{
			continue;
		}

		FileFound = LIBUTI_CMN_TestSupportFile(FileNameLengthBuffer , FileNameAddressBuffer, &(SupportFilesInfo[index]), SUP, SUP_FileFound, SUP_FileInfo, OutOfOperationalConditionLoad);
		if(FileFound != FALSE)
		{
			continue;
		}
		
		FileFound = LIBUTI_CMN_TestSupportFile(FileNameLengthBuffer , FileNameAddressBuffer, &(SupportFilesInfo[index]), LUD, LUD_FileFound, LUD_FileInfo, OutOfOperationalConditionLoad);
		if(FileFound != FALSE)
		{
			continue;
		}
		
		FileFound = LIBUTI_CMN_TestSupportFile(FileNameLengthBuffer , FileNameAddressBuffer, &(SupportFilesInfo[index]), SIF, SIF_FileFound, SIF_FileInfo, OutOfOperationalConditionLoad);
		if(FileFound != FALSE)
		{
			continue;
		}
		
		(void) LIBUTI_CMN_TestSupportFile(FileNameLengthBuffer , FileNameAddressBuffer, &(SupportFilesInfo[index]), SKF, SKF_FileFound, SKF_FileInfo, OutOfOperationalConditionLoad);
		/*}}RELAX<SYNCHRONe_C_Code_17.4> */
    }
}