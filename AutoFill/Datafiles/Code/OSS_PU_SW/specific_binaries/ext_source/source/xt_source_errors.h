/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#ifndef XT_SOURCE_ERRORS
#define XT_SOURCE_ERRORS

/*!
 * XT source error codes definitions
 */
typedef enum
{
    ERR_XT_NO_ERROR = 0,
    ERR_XT_UNKNOWN, /*< unknown error for XT source */
    ERR_XT_INVALID_FPGA_PERIOD,
    ERR_XT_INVALID_FPGA_TIMEOUT,
    ERR_XT_FIRST_TICK_IS_NOT_FPGA,
    ERR_XT_MISSING_NEXT_FPGA_TICK,
    ERR_XT_INVALID_TRANSITION,
    ERR_XT_INVALID_WAKEUP_VALUE,
    ERR_XT_WATCHDOG_TIMEOUT
} t_xt_source_error;

/**
 * Global variable to store current external source error code
 */
extern t_xt_source_error xt_source_error_code;

/**
 * raise_xt_source_error
 * @param t_xt_source_error   error code
 * Raise a source error and log information in memory
 * related to the error code
 */
void raise_xt_source_error(t_xt_source_error error_code);

#endif /* XT_SOURCE_ERRORS */
