/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#include "source_xt-source.h"

#include <xt_source_errors.h>


t_xt_source_error xt_source_error_code = ERR_XT_NO_ERROR;

/**
 * raise_xt_source_error
 * @param t_xt_source_error   error code
 * Raise a source error and log information in memory
 * related to the error code
 */
void raise_xt_source_error(t_xt_source_error error_code)
{
    xt_source_error_code = error_code;
    AST_RAISE_ERROR();
}


