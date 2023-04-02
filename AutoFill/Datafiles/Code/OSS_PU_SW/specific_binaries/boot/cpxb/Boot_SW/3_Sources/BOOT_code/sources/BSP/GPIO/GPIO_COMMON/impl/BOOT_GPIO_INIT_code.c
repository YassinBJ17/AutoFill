/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : GPIO Initialization function
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "BOOT_GPIO_CFEX_public.h"
#include "BOOT_GPIO_HAL_public.h"
/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- internal define constants: ------------------------------------ */
/* none */

/* ---------- internal types: ----------------------------------------------- */
/* none */

/* ---------- internal operations: ------------------------------------------ */
/* none */

/* ---------- internal constants: ------------------------------------------- */
/* none */

/* ---------- internal data: ------------------------------------------------ */
/* none */

/* ---------- provided operation bodies: ------------------------------------ */
/* */

void BOOT_GPIO_INIT( void )
{
   /* Local Variable Declaration */
   ts_GPIO_CFEX_ELT const * pt_conf ;
   uint32_t                v_conf_ind;

   /* */
   for( v_conf_ind = 0UL; v_conf_ind < c_GPIO_CFEX_tab_SIZE; v_conf_ind++ )
   {
      /* Get Configuration descriptor */
      pt_conf = &(c_GPIO_CFEX_CONFIGURATION_tab[v_conf_ind]);

      /* */
      if ( pt_conf->s_direction == e_GPIO_CFEX_DIR_OUTPUT )
      {
         /* Gpio Output */
         /* */
         if ( pt_conf->s_access == e_GPIO_CFEX_ACCESS_PIN )
         {
            /* Gpio Descriptor init - GPIO identifier */
            /*  */
            GPIO_CFEX_descriptor_tab[v_conf_ind].s_gpio_id = pt_conf->s_gpio_id.u_gpio_pin_rw_id;

            /* Gpio s_access PIN */
            /* Init GPIO Pin */
            BOOT_GPIO_WRITE_PIN ( v_conf_ind, pt_conf->s_reset_value);
         }
         else
         {
            /* Gpio s_access PORT */
            /* Gpio Descriptor init - GPIO identifier */
            /*   */
            GPIO_CFEX_descriptor_tab[v_conf_ind].s_gpio_id = pt_conf->s_gpio_id.u_gpio_port_id;
            /* */
            if ( pt_conf->s_mask_used == e_GPIO_CFEX_MASK_UNUSED )
            {
               /* Gpio Mask Not USED */
               /* Init GPIO Port */
               /* {{RELAX<SYNCHRONe_C_Code_10.7> The cast is safe as GPIO_PORT_VALUE_t is unsigned short */
               /* (16 bits) and s_reset_value is unsigned char (8 bits). */
               BOOT_GPIO_WRITE_PORT ( v_conf_ind, (GPIO_PORT_VALUE_t)pt_conf->s_reset_value);
               /* }}<SYNCHRONe_C_Code_10.7> */
            }
            else
            {
               /* Gpio Mask USED */
               /* Gpio Descriptor init - GPIO mask value */
               GPIO_CFEX_descriptor_tab[v_conf_ind].s_mask_value = pt_conf->s_mask_value;
               /* Init GPIO Port with Mask */
               BOOT_GPIO_WRITE_WITH_MASK_PORT ( v_conf_ind, (GPIO_PORT_VALUE_t)pt_conf->s_reset_value );
            }
         }
      }
      else
      {
         if ( pt_conf->s_access == e_GPIO_CFEX_ACCESS_PIN )
         {
            /* Gpio Descriptor init - GPIO identifier */
            /*  */
            GPIO_CFEX_descriptor_tab[v_conf_ind].s_gpio_id = pt_conf->s_gpio_id.u_gpio_pin_ro_id;
         }
         else
         {
            /* Gpio Descriptor init - GPIO identifier */
            /*  */
            GPIO_CFEX_descriptor_tab[v_conf_ind].s_gpio_id = pt_conf->s_gpio_id.u_gpio_port_id;
         }
      }
   }
}

/* ---------- internal operation bodies: ------------------------------------ */
/* none */
