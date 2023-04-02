/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "LIBUTI_SIF.h"
/* ---------- include required interface: ----------------------------------- */
#include "LIBUTI_SIF_getters.h"
#include "LIBUTI_SIF_iterators.h"
#include "LIBUTI_SIF_hashes.h"
#include "LIBUTI_SIF_getters_from_headers.h"
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

TE_LIBUTI_SIF_status LIBUTI_SIF_get_software_info( const uint8_t * DecodedHeaderAddress, ts_LIBUTI_SIF_software_info * const out )
{
   ts_LIBUTI_SIF_header header;
   ts_LIBUTI_SIF_header_iterator hiter;
   TE_LIBUTI_SIF_status ret;

   ret = LIBUTI_SIF_get_header( DecodedHeaderAddress, &header );

   if (ret == E_LIBUTI_SIF_SUCCESS)
   {
      hiter.header        = DecodedHeaderAddress;
      hiter.header_length = header.header_length;
      hiter.position      = header.software_chars_abs_ptr;
      LIBUTI_SIF_get_strl( &hiter, &(out->PN) );
      LIBUTI_SIF_get_strl( &hiter, &(out->Name) );
   }
   return  ( ret );
}

TE_LIBUTI_SIF_status LIBUTI_SIF_get_tool_chars( const uint8_t * DecodedHeaderAddress, ts_LIBUTI_SIF_tool_info * const out )
{
   ts_LIBUTI_SIF_header          header;
   ts_LIBUTI_SIF_header_iterator hiter;
   TE_LIBUTI_SIF_status          ret;

   ret = LIBUTI_SIF_get_header( DecodedHeaderAddress, &header );

   if ( ret == E_LIBUTI_SIF_SUCCESS )
   {
      hiter.header        = DecodedHeaderAddress;
      hiter.header_length = header.header_length;
      hiter.position      = header.tool_chars_abs_ptr;
      LIBUTI_SIF_get_strl( &hiter, &(out->Name) );
      LIBUTI_SIF_get_strl( &hiter, &(out->Version) );
   }
   return ( ret );
}

TE_LIBUTI_SIF_status LIBUTI_SIF_get_requester_info( const uint8_t * DecodedHeaderAddress, ts_LIBUTI_SIF_requester_info * const out )
{
   ts_LIBUTI_SIF_header          header;
   ts_LIBUTI_SIF_header_iterator hiter;
   TE_LIBUTI_SIF_status          ret;

   ret = LIBUTI_SIF_get_header( DecodedHeaderAddress, &header );
   if ( ret == E_LIBUTI_SIF_SUCCESS )
   {
      hiter.header        = DecodedHeaderAddress;
      hiter.header_length = header.header_length;
      hiter.position      = header.requester_info_abs_ptr;
      LIBUTI_SIF_get_str( &hiter, (uint32_t)14, out->DateTime );
      LIBUTI_SIF_get_strl( &hiter, &(out->Name) );
   }
   return ( ret );
}


te_CMN_FLAG_QUESTION LIBUTI_SIF_has_target( const uint8_t * DecodedHeaderAddress, const uint8_t * TargetName, const uint32_t TargetNameLength, 
                                            const uint8_t * HardwareID, const uint32_t HardwareIDLength )
{
   te_CMN_FLAG_QUESTION   is_target;
   ts_LIBUTI_SIF_target   v_target;
   ts_LIBUTI_SIF_iterator v_titer;
   TE_LIBUTI_SIF_status   status;

   status = LIBUTI_SIF_init_target_iterator( DecodedHeaderAddress, &v_titer );
   v_target.Name.Length = (uint16_t)0;
   v_target.hardware_identifier.Length = (uint16_t)0;

   is_target = e_CMN_FLAG_NO;
   if ( status == E_LIBUTI_SIF_SUCCESS )
   {
      status = LIBUTI_SIF_get_next_target( &v_target, &v_titer );
   }

   while( ( status != E_LIBUTI_SIF_FAILURE ) && ( is_target == e_CMN_FLAG_NO ) )
   {
      is_target = e_CMN_FLAG_YES;
      if ( TargetName != NULL )
      {
         if ( TargetNameLength == (uint32_t)(v_target.Name.Length) )
         {
            if ( BOOT_LIBMEM_NOTEQUAL(TargetName, v_target.Name.Name, v_target.Name.Length) == e_CMN_FLAG_NO )
            {
               is_target = e_CMN_FLAG_YES;
            }
            else
            {
               is_target = e_CMN_FLAG_NO;
            }
         }
         else
         {
            is_target = e_CMN_FLAG_NO;
         }
      }
      if ( ( is_target == e_CMN_FLAG_YES ) && ( HardwareID != NULL ) )
      {
         if ( HardwareIDLength == (uint32_t)(v_target.hardware_identifier.Length) )
         {
            if ( BOOT_LIBMEM_NOTEQUAL(HardwareID, v_target.hardware_identifier.Name, v_target.hardware_identifier.Length) == e_CMN_FLAG_NO )
            {
               is_target = e_CMN_FLAG_YES;
            }
            else
            {
               is_target = e_CMN_FLAG_NO;
            }
         }
         else
         {
            is_target = e_CMN_FLAG_NO;
         }
      }
      status = LIBUTI_SIF_get_next_target( &v_target, &v_titer );
   }
   return ( is_target );
}

te_CMN_FLAG_QUESTION LIBUTI_SIF_has_file( const uint8_t * DecodedHeaderAddress, const uint8_t * FileName, const uint32_t FileNameLength )
{
   ts_LIBUTI_SIF_file_info v_finfo;
   ts_LIBUTI_SIF_iterator  v_fiter;
   te_CMN_FLAG_QUESTION    is_file;
   TE_LIBUTI_SIF_status    status;

   is_file = e_CMN_FLAG_NO;
   v_finfo.Name.Length = (uint16_t)0;
   status = LIBUTI_SIF_init_file_iterator( DecodedHeaderAddress, &v_fiter );

   if ( status == E_LIBUTI_SIF_SUCCESS )
   {
      status = LIBUTI_SIF_get_next_file( &v_finfo, &v_fiter );
   }

   while( ( status != E_LIBUTI_SIF_FAILURE ) && ( is_file == e_CMN_FLAG_NO ) )
   {
      if ( (uint32_t)(v_finfo.Name.Length) == FileNameLength )
      {
            if ( BOOT_LIBMEM_NOTEQUAL(FileName, v_finfo.Name.Name, v_finfo.Name.Length) == e_CMN_FLAG_NO )
            {
               is_file = e_CMN_FLAG_YES;
            }
            else
            {
               is_file = e_CMN_FLAG_NO;
            }
      }
      else
      {
          is_file = e_CMN_FLAG_NO;
      }
      status = LIBUTI_SIF_get_next_file( &v_finfo, &v_fiter );

   }
   return ( is_file );
}

uint16_t LIBUTI_SIF_file_count( const uint8_t * DecodedHeaderAddress )
{
   ts_LIBUTI_SIF_iterator fiter;
   TE_LIBUTI_SIF_status   status;
   uint16_t               ret;

   status = LIBUTI_SIF_init_file_iterator( DecodedHeaderAddress, &fiter );

   if ( status == E_LIBUTI_SIF_SUCCESS )
   {
      ret = fiter.item_count;
   }
   else
   {
      ret = (uint16_t)0;
   }
   return ( ret );
}


TE_LIBUTI_SIF_status LIBUTI_SIF_get_SHA2_256( const uint8_t * DecodedHeaderAddress, const uint8_t * FileName,
                                              const uint32_t FileNameLength, ts_LIBUTI_SHA_SHA256 * const p_out )
{
   TE_LIBUTI_SIF_status ret;
   tu_LIBUTI_SIF_hash buf;

   ret = LIBUTI_SIF_get_hash( DecodedHeaderAddress, FileName, FileNameLength, E_LIBUTI_SIF_CHECK_ALGORITHM_SHA2_256, &buf );
   if ( ret == E_LIBUTI_SIF_SUCCESS )
   {
      *p_out = buf.sha256;
   }
   return ( ret );
}

te_CMN_FLAG_QUESTION LIBUTI_SIF_has_hashmode(
   /* Input(s) parameter(s) */
   const uint8_t                  *DecodedHeaderAddress,
   const uint8_t                  *FileName,
   const uint32_t                 FileNameLength,
   /* InputOutput(s) parameter(s) */

   /* Output(s) parameter(s) */
   TE_LIBUTI_SIF_check_algorithm       *hashmode
)
{
/* Declaration of local variables ------------------------------------------- */

   ts_LIBUTI_SIF_file_info     v_finfo;
   ts_LIBUTI_SIF_global_check  v_gcheck;
   ts_LIBUTI_SIF_iterator      v_fiter, v_giter;
   TE_LIBUTI_SIF_status        status;
   te_CMN_FLAG_QUESTION        is_hashmode;

/* Function body ------------------------------------------------------------ */

   status = LIBUTI_SIF_init_file_iterator( DecodedHeaderAddress, &v_fiter );

   while ( status == E_LIBUTI_SIF_SUCCESS )
   {
      status = LIBUTI_SIF_get_next_file( &v_finfo, &v_fiter );
      if ( ( status == E_LIBUTI_SIF_SUCCESS ) && ( FileNameLength == v_finfo.Name.Length ) )
      {
         if ( BOOT_LIBMEM_NOTEQUAL( FileName, v_finfo.Name.Name, v_finfo.Name.Length ) == e_CMN_FLAG_NO )
         {
            break;
         }
      }
   }

   LIBUTI_SIF_init_global_check_iterator( &v_finfo, &v_fiter, &v_giter );
   status = LIBUTI_SIF_get_next_global_check( &v_gcheck, &v_giter );

   if ( status == E_LIBUTI_SIF_SUCCESS )
   {
      is_hashmode = e_CMN_FLAG_YES;
      *hashmode = v_gcheck.check_type;
   }
   else
   {
      *hashmode = E_LIBUTI_SIF_CHECK_ALGORITHM_MD5;
      is_hashmode = e_CMN_FLAG_NO;
   }
   return ( is_hashmode );
}

/* if the function is in an exported api */
/* Declaration of the function is in CSC_api.h */
