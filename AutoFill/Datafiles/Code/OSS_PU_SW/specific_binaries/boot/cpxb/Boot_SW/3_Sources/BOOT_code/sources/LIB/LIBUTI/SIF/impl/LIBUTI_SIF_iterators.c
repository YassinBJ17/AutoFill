/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */


/* in the following file, CSU is the file name without extension and XXX the */
/* file name in upper case letters  */
/* CSU name begins with the CSC file */


/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF_iterators.h"
/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_getters_from_headers.h"
#include "LIBUTI_SIF_get_next_file_skip.h"
#include "BOOT_LIBMEM_public.h"

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

TE_LIBUTI_SIF_status LIBUTI_SIF_init_target_iterator( const uint8_t * const DecodedHeaderAddress, ts_LIBUTI_SIF_iterator * const iter )
{
   ts_LIBUTI_SIF_header header;
   TE_LIBUTI_SIF_status ret;

   ret = LIBUTI_SIF_get_header( DecodedHeaderAddress, &header );

   if ( ret == E_LIBUTI_SIF_SUCCESS )
   {
      iter->data.header        = DecodedHeaderAddress;
      iter->data.header_length = header.header_length;
      iter->data.position      = header.targets_chars_abs_ptr;
      iter->item_count         = LIBUTI_SIF_get_short( &(iter->data) );
      iter->format_version     = header.format_version;
      iter->format_revision    = header.format_revision;
   }

   return ( ret );
}

/* Returns 1 if no more targets */
TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_target( ts_LIBUTI_SIF_target * const target, ts_LIBUTI_SIF_iterator * const iter )
{
   uint32_t next_ptr;
   TE_LIBUTI_SIF_status ret;

   ret = E_LIBUTI_SIF_FAILURE;
   if ( iter->data.position < iter->data.header_length )
   {
      BOOT_LIBMEM_SET( (uint8_t *) target, 0, sizeof(ts_LIBUTI_SIF_target) );
      next_ptr = LIBUTI_SIF_get_long( &(iter->data) );
      iter->item_count--;
      if ( ( next_ptr == (uint32_t)0 ) || ( iter->item_count == (uint16_t)0 ) )
      {
         next_ptr = iter->data.header_length;
      }
      else
      {
         next_ptr += iter->data.position - (uint32_t)4;
      }

      LIBUTI_SIF_get_strl( &(iter->data), &(target->hardware_identifier) );
      LIBUTI_SIF_get_strl( &(iter->data), &(target->Name) );
      ret = E_LIBUTI_SIF_SUCCESS;
      iter->data.position = next_ptr;
   }
   return ( ret );
}

TE_LIBUTI_SIF_status LIBUTI_SIF_init_file_iterator( const uint8_t * const DecodedHeaderAddress, ts_LIBUTI_SIF_iterator * const iter )
{
   ts_LIBUTI_SIF_header header;
   TE_LIBUTI_SIF_status ret;

   ret = LIBUTI_SIF_get_header( DecodedHeaderAddress, &header );
   if ( ret == E_LIBUTI_SIF_SUCCESS )
   {
      iter->data.header        = DecodedHeaderAddress;
      iter->data.header_length = header.header_length;
      iter->data.position      = header.files_chars_abs_ptr;
      iter->item_count         = LIBUTI_SIF_get_short( &(iter->data) );
      iter->format_version     = header.format_version;
      iter->format_revision    = header.format_revision;
   }
   return ( ret );
}

/* Returns 1 if no more files */
TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_file( ts_LIBUTI_SIF_file_info * const file, ts_LIBUTI_SIF_iterator * const iter )
{
   uint32_t next_ptr;
   TE_LIBUTI_SIF_status ret;
   uint32_t name_ptr, nb_global_chk_ptr, nb_datapacket_chk_ptr;

   ret = E_LIBUTI_SIF_FAILURE;
   nb_global_chk_ptr = (uint32_t)0;
   nb_datapacket_chk_ptr = (uint32_t)0;
   if ( iter->data.position < iter->data.header_length )
   {
      BOOT_LIBMEM_SET((uint8_t *)file, 0, sizeof(ts_LIBUTI_SIF_file_info));

      next_ptr = LIBUTI_SIF_get_long(&(iter->data));

      iter->item_count--;

      if ( ( next_ptr == (uint32_t)0 ) || ( iter->item_count == (uint16_t)0 ) )
      {
         next_ptr = iter->data.header_length;
      }
      else
      {
         next_ptr += iter->data.position - (uint32_t)4;
      }
      if (iter->format_version >= (uint16_t)0xB002)
      {
         name_ptr = LIBUTI_SIF_get_long(&(iter->data));
         name_ptr += iter->data.position - (uint32_t)4;
         nb_global_chk_ptr = LIBUTI_SIF_get_long(&(iter->data));
         if (nb_global_chk_ptr != (uint32_t)0)
         {
            nb_global_chk_ptr += iter->data.position - (uint32_t)4;
         }
         nb_datapacket_chk_ptr = LIBUTI_SIF_get_long(&(iter->data));
         if (nb_datapacket_chk_ptr != (uint32_t)0)
         {
            nb_datapacket_chk_ptr += iter->data.position - (uint32_t)4;
         }
         iter->data.position = name_ptr;
      }
      LIBUTI_SIF_get_strl(&(iter->data), &(file->Name));

      file->file_length = LIBUTI_SIF_get_long(&(iter->data));
      if (iter->format_version >= (uint16_t)0xB002)
      {
         iter->data.position = nb_global_chk_ptr;
      }

      LIBUTI_SIF_get_next_file_skip( file, iter );

      if (iter->format_version >= (uint16_t)0xB002)
      {
         iter->data.position = nb_datapacket_chk_ptr;
      }
      if (iter->data.position != (uint32_t)0)
      {
         file->packet_check_number = LIBUTI_SIF_get_short(&(iter->data));
         file->first_packet_check_addr = iter->data.position;
      }
      if ( iter->data.position < iter->data.header_length )
      {
         ret = E_LIBUTI_SIF_SUCCESS;
         iter->data.position = next_ptr;
      }
      else
      {
         iter->data.position = iter->data.header_length;
      }
   }
   return ( ret );
}

void LIBUTI_SIF_init_global_check_iterator( const ts_LIBUTI_SIF_file_info * const finfo, const ts_LIBUTI_SIF_iterator * const fiter, ts_LIBUTI_SIF_iterator * const iter )
{
   iter->data            = fiter->data;
   iter->item_count      = finfo->global_check_number;
   iter->format_version  = fiter->format_version;
   iter->format_revision = fiter->format_revision;
   if ( finfo->global_check_number == (uint16_t)0 )
   {
      iter->data.position = iter->data.header_length;
   }
   else
   {
      iter->data.position = finfo->first_check_addr;
   }
}


TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_global_check( ts_LIBUTI_SIF_global_check * const check, ts_LIBUTI_SIF_iterator * const iter )
{

   uint32_t next_ptr, hash_length;
   TE_LIBUTI_SIF_status ret;
   ret = E_LIBUTI_SIF_FAILURE;
   if ( iter->data.position < iter->data.header_length )
   {
      next_ptr = LIBUTI_SIF_get_long(&(iter->data));
      iter->item_count--;
      if ( ( next_ptr == (uint32_t)0 ) || ( iter->item_count == (uint16_t)0 ) )
      {
         next_ptr = iter->data.header_length;
      }
      else
      {
         next_ptr += iter->data.position - (uint32_t)4;
      }

      check->check_type = (TE_LIBUTI_SIF_check_algorithm) LIBUTI_SIF_get_short( &(iter->data) );

      hash_length = LIBUTI_SIF_get_hash_length( check->check_type );

      LIBUTI_SIF_get_str( &(iter->data), hash_length, check->check );

      iter->data.position = next_ptr;
      ret = E_LIBUTI_SIF_SUCCESS;
   }
   return ( ret );
}

void LIBUTI_SIF_init_packet_check_iterator( const ts_LIBUTI_SIF_file_info * const finfo, const ts_LIBUTI_SIF_iterator * const fiter, ts_LIBUTI_SIF_iterator * const iter )
{
   iter->data            = fiter->data;
   iter->item_count      = finfo->packet_check_number;
   iter->format_version  = fiter->format_version;
   iter->format_revision = fiter->format_revision;
   if ( finfo->packet_check_number == (uint16_t)0 )
   {
      iter->data.position = iter->data.header_length;
   }
   else
   {
      iter->data.position = finfo->first_packet_check_addr;
   }
}

TE_LIBUTI_SIF_status LIBUTI_SIF_get_next_packet_check( ts_LIBUTI_SIF_data_packet_check * const check, ts_LIBUTI_SIF_iterator * const iter )
{
   uint32_t next_ptr, v_idx, hash_length;
   TE_LIBUTI_SIF_status ret;
   ret = E_LIBUTI_SIF_FAILURE;
   if ( iter->data.position < iter->data.header_length )
   {
      next_ptr = LIBUTI_SIF_get_long(&(iter->data));
      iter->item_count--;

      if ( ( next_ptr == (uint32_t)0 ) || ( iter->item_count == (uint16_t)0 ) )
      {
         next_ptr = (uint32_t)0;
      }
      else
      {
         next_ptr += iter->data.position - (uint32_t)4;
      }

      check->packet_length = LIBUTI_SIF_get_long( &(iter->data) );
      check->packet_number = LIBUTI_SIF_get_long( &(iter->data) );
      check->check_type = (TE_LIBUTI_SIF_check_algorithm) LIBUTI_SIF_get_short( &(iter->data) );

      for( v_idx = (uint32_t)0; v_idx < check->packet_number; v_idx++ )
      {
         hash_length = LIBUTI_SIF_get_hash_length( check->check_type );
         LIBUTI_SIF_get_str( &(iter->data), hash_length, check->check_list[v_idx] );
         if ( iter->data.position >= iter->data.header_length )
         {
            next_ptr = iter->data.header_length;
            break;
         }
      }
      iter->data.position = next_ptr;
      ret = E_LIBUTI_SIF_SUCCESS;
   }
   return ( ret );
}
/* if the function is in an exported api */
/* Declaration of the function is in CSC_api.h */
