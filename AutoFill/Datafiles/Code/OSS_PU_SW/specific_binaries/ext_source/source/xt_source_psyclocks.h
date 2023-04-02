/************ Copyright Krono-Safe S.A. 2020, All rights reserved ************/
#ifndef AST_XT_SOURCE_PSYCLOCKS_H_
#define AST_XT_SOURCE_PSYCLOCKS_H_

/*!
 * Declarations of clocks based on the XT source
 */

source xt_source;

/* Source "xt_source" period is set to 50 us */
clock ast_xt_clock_ms = 20 * xt_source;
clock ast_xt_clock_s = 1000 * ast_xt_clock_ms;

#endif /* !AST_XT_SOURCE_PSYCLOCKS_H_ */
