
#include "LIBUTI_CMN_TestSupportFile.h"

/*{{RELAX<SYNCHRONe_C_Code_17.4> Array indexing used on pointer FileNameAddressBuffer because its used as buffer.*/ 
/*Can't use a fix array, depends on the FileNameLengthBuffer*/
/*Solution kept.*/

boolean_t LIBUTI_CMN_TestSupportFile
(
/*IN*/
	const uint32_t FileNameLengthBuffer, 
	uint8_t* const FileNameAddressBuffer,
	const TS_FileInfo* const Pointer_to_SupportFilesInfo,
	const uint8_t FileExtensionBuffer[4],
/*OUT*/
	boolean_t* const FileFound,
	const TS_FileInfo** const FileInfo,
    boolean_t* const OutOfOperationalConditionLoad
)
{
	boolean_t v_Found;

	v_Found = FALSE;
	if(		(FileNameAddressBuffer[FileNameLengthBuffer-4ul] == FileExtensionBuffer[0])
		&& 	(FileNameAddressBuffer[FileNameLengthBuffer-3ul] == FileExtensionBuffer[1])
		&& 	(FileNameAddressBuffer[FileNameLengthBuffer-2ul] == FileExtensionBuffer[2])
		&& 	(FileNameAddressBuffer[FileNameLengthBuffer-1ul] == FileExtensionBuffer[3]))
	{
		v_Found = TRUE;
		if(*FileFound == FALSE)
		{
			*FileInfo = Pointer_to_SupportFilesInfo;
			*FileFound = TRUE;
		}
		else
		{
			*OutOfOperationalConditionLoad = TRUE;
		}
	}
	return v_Found;
}
/*}}RELAX<SYNCHRONe_C_Code_17.4> */