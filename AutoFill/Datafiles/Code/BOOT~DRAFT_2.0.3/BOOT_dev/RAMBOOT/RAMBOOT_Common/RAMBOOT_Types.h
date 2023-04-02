#ifndef _RAMBOOT_TYPES_
#define _RAMBOOT_TYPES_

#include "LIBMCP_Types.h"
#include "LIBUTI_SHA.h"

typedef struct 
{
	uint32_t size;
	ts_LIBUTI_SHA_SHA256 sha256;
} ts_RAMBOOT_Data;

#endif