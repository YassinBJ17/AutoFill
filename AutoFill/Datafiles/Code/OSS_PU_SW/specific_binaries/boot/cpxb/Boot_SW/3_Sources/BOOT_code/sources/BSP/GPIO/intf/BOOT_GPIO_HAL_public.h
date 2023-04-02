#ifndef GPIO_HAL_public_H
#define GPIO_HAL_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"
#include "CMN_IOSP_common.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided types: ----------------------------------------------- */
typedef uint8_t  GPIO_PIN_VALUE_t;
typedef uint16_t GPIO_PORT_VALUE_t;
typedef uint16_t GPIO_PORT_MASK_t;

#define GPIO_DINSHOP   ((CMN_IOSP_ID_t)0ul)
#define GPIO_DINOLL    ((CMN_IOSP_ID_t)1ul)
#define GPIO_DINTMODE  ((CMN_IOSP_ID_t)2ul)
#define GPIO_MDIN      ((CMN_IOSP_ID_t)3ul)
#define GPIO_MPC_LED4  ((CMN_IOSP_ID_t)4ul)
#define GPIO_NB        ((CMN_IOSP_ID_t)7ul)

/* ---------- provided constants: ------------------------------------------- */
/* */

/* ---------- provided datas: ----------------------------------------------- */
/* none */

/* ---------- provided operations: ------------------------------------------ */
/* */
extern void BOOT_GPIO_INIT( void );
/* */
extern void BOOT_GPIO_READ_IN_PIN ( CMN_IOSP_ID_t             const p_gpio_conf_id,
                                      GPIO_PIN_VALUE_t * const p_logic_value);
/* */
extern void BOOT_GPIO_WRITE_PIN ( CMN_IOSP_ID_t            const p_gpio_conf_id,
                                    GPIO_PIN_VALUE_t const p_pin_value);
/* */
extern void BOOT_GPIO_READ_IN_PORT ( CMN_IOSP_ID_t              const p_gpio_conf_id,
                                       GPIO_PORT_VALUE_t * const p_logic_value);
/* */
extern void BOOT_GPIO_WRITE_PORT ( CMN_IOSP_ID_t            const p_gpio_conf_id,
                                     GPIO_PORT_VALUE_t const p_logic_value);
/* */
extern void BOOT_GPIO_WRITE_WITH_MASK_PORT ( CMN_IOSP_ID_t            const p_gpio_conf_id,
                                               GPIO_PORT_VALUE_t const p_logic_value );
/* */

#endif /* GPIO_HAL_public_H */
