/*----------------------------------------------------------------------------*/
/* File name  : LIBUTI_SIF_get_next_file_skip.c
 * CSC name   : LIBUTI_SIF
 *
 * Description:
 *
 *    Creation: Divided from  LIBUTI_SIF_get_next_file in LIBUTI_SIF_iterators.c on 23-03-2022
 *
 * Copyright (c) 2019,
 * Safran Electronics & Defense document. Reproduction and disclosure forbidden.
 *----------------------------------------------------------------------------*/

/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */


/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF_get_next_file_skip.h"
/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_SIF_getters_from_headers.h"
/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal macros: ---------------------------------------------- */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal operation bodies: ------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */


void LIBUTI_SIF_get_next_file_skip(ts_LIBUTI_SIF_file_info * const file, ts_LIBUTI_SIF_iterator * const iter)
{
	uint32_t v_idx, skip_ptr;
	TE_LIBUTI_SIF_check_algorithm algo;
	
	if (iter->data.position != (uint32_t)0)
	{
		file->global_check_number = LIBUTI_SIF_get_short(&(iter->data));
		if (file->global_check_number != (uint16_t)0)
		{
			file->first_check_addr = iter->data.position;
			for(v_idx = (uint32_t)0; v_idx < (uint32_t)(file->global_check_number); v_idx++)
			{
				if (iter->data.position > iter->data.header_length)
				{
					break;
				}
				skip_ptr = LIBUTI_SIF_get_long(&(iter->data));
				if (skip_ptr != (uint32_t)0)
				{
					iter->data.position += skip_ptr - (uint32_t)4;
				}
			}
			algo = (TE_LIBUTI_SIF_check_algorithm) LIBUTI_SIF_get_short(&(iter->data));
			iter->data.position += LIBUTI_SIF_get_hash_length(algo) + (uint32_t)4; 
		}
	}
}