#include "RAMBOOT_TestSelfIntegrity.h"
#include "RAMBOOT_Consts.h"
#include "LIBUTI_SHA.h"
#include "LIBUTI_MEM.h"
#include "RAMBOOT_FailMode.h"
#include "RAMBOOT_RamBootEndMarker.h"

void RAMBOOT_TestSelfIntegrity( )
{
	uint32_t v_RAMBOOTSize;
	ts_LIBUTI_SHA_SHA256 v_RAMBOOTSHA256;
	boolean_t v_SHA256NotEgual;
	ts_RAMBOOT_Data *pt_BootData;

	const ts_RAMBOOT_Data * const p_BootData = (ts_RAMBOOT_Data*)((&C_RAMBOOT_CODE_END_MARKER) + 1)[0];

	v_RAMBOOTSize = (((uint32_t)&C_RAMBOOT_CODE_END_MARKER) + sizeof(uint32_t)) - C_RAMBOOT_START; /* %RELAX<SYNCHRONe_C_Code_11.1> C_RAMBOOT_CODE_END_MARKER marks the end of our code. Its address is needed to get the actual size of RAMBOOT */
	if(v_RAMBOOTSize != p_BootData->size)
	{
		RAMBOOT_FailMode();
		return;
	}
	/* Compute boot SHA256 */
	LIBUTI_SHA_ComputeSHA256((uint8_t*) C_RAMBOOT_START, v_RAMBOOTSize, &v_RAMBOOTSHA256); /* %RELAX<SYNCHRONe_C_Code_10.7> C_RAMBOOT_START is an address */
	v_SHA256NotEgual = LIBUTI_MEM_MemsNotEqual(p_BootData->sha256.Data, v_RAMBOOTSHA256.Data, (uint32_t)SHA256_BLOCK_SIZE);
	if(v_SHA256NotEgual)
	{
		RAMBOOT_FailMode();
	}
}