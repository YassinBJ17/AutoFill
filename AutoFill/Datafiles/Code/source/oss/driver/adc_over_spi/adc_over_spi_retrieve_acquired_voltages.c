/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : <short description of the operations of the .c file>
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "type/common_type.h"

/* ---------- include required interface: ----------------------------------- */
#include "driver/adc_over_spi/adc_over_spi_private.h"
#include "driver/adc_over_spi/ADC_AD7327_HAL_common.h"
#include "driver/adc_over_spi/ADC_AD7327_CFEX_common.h"
#include "driver/adc_over_spi/adc_over_spi_public.h"
#include "driver/spi/SPI_HAL_public.h"
#include "driver/spi/SPI_CFEX_public.h"
#include "middleware/uod_bypass/uod_bypass_public.h"
#include "conf/oss_conf_public.h"
#include "memory/memory_address_public.h"

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- internal operations: ------------------------------------------ */

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

extern uint16_t adc_over_spi_rx_buffer_adc_1[ADC_AD7327_CFEX_ADC1_SAMPLES_NB];
extern uint16_t adc_over_spi_rx_buffer_adc_2[ADC_AD7327_CFEX_ADC2_SAMPLES_NB];
extern uint16_t adc_over_spi_rx_buffer_adc_3[ADC_AD7327_CFEX_ADC3_SAMPLES_NB];

/*TODO : To remove once acquisitions are OK*/
uint32_t adc_over_spi_nb_ob_bytes;
uint32_t adc_over_spi_nb_of_retries;
/*TODO : To remove once acquisitions are OK*/

#ifdef INSTRUM_RSF_WITH_GPIO
extern uint8_t * gpioPtr;
#endif /* INSTRUM_RSF_WITH_GPIO */

/* ---------- provided operation bodies: ------------------------------------ */

void updateVoltageBuffer(float32_t offset,
                   float32_t     maxValue,
                   uint32_t      indexStart,
                   uint32_t      indexStop,
                   uint16_t *    rx,
                   float32_t *   rx_voltage,
                   uint8_t       incrementInBuffer,
                   uint16_t      uod_bypass_value)
{
   uint32_t rx_voltage_index = 0;
   uint32_t iter;
   uint16_t val;


   if(uod_bypass.enable_bypass_adcOverSpi)
   {
      for(iter = indexStart ; iter <= indexStop ; iter = iter + incrementInBuffer)
      {
         val = uod_bypass_value & 0b0001111111111111;
         if(val & 0b0001000000000000)
         {
            rx_voltage[rx_voltage_index] = -((~(val - 1)) & 0b0001111111111111);
         }
         else
         {
            rx_voltage[rx_voltage_index] = val;
         }
         rx_voltage[rx_voltage_index] = offset + rx_voltage[rx_voltage_index] * maxValue / 4096.;
         rx_voltage_index++;
      }
   }
   else /* Code is duplicated to reduce uod bypass cpu load  */
   {
      for(iter = indexStart ; iter <= indexStop ; iter = iter + incrementInBuffer)
      {
         val = rx[iter] & 0b0001111111111111;
         if(val & 0b0001000000000000)
         {
            rx_voltage[rx_voltage_index] = -((~(val - 1)) & 0b0001111111111111);
         }
         else
         {
            rx_voltage[rx_voltage_index] = val;
         }
         rx_voltage[rx_voltage_index] = offset + rx_voltage[rx_voltage_index] * maxValue / 4096.;
         rx_voltage_index++;
      }
   }
}

void adc_over_spi_retrieve_acquired_voltages(void)
{
   uint32_t read_size_adc;

   /* Retrieve configuration data */
   ts_oss_conf_table * pt_oss_conf = (ts_oss_conf_table *)OSS_CONF_START_ADDR;

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 0;
#endif /* INSTRUM_RSF_WITH_GPIO */

   adc_over_spi_nb_of_retries = 0;

   /* Read Status SPI Line ADC1 */
   read_size_adc = 0;
   while(read_size_adc < (2 * ADC_AD7327_CFEX_ADC1_SAMPLES_NB))
   {
      SPI_DMA_STATUS_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_1].spi_conf_id,
                               &read_size_adc);
      adc_over_spi_nb_of_retries++;
   }
   /* Read Status SPI Line ADC2 */
   read_size_adc = 0;
   while(read_size_adc < (2 * ADC_AD7327_CFEX_ADC2_SAMPLES_NB))
   {
      SPI_DMA_STATUS_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_2].spi_conf_id,
                               &read_size_adc);
   }
   /* Read Status SPI Line ADC3 */
   read_size_adc = 0;
   while(read_size_adc < (2 * ADC_AD7327_CFEX_ADC3_SAMPLES_NB))
   {
      SPI_DMA_STATUS_READ_DATA(ADC_AD7327_CFEX_descriptor_tab[AD7327_CONF_3].spi_conf_id,
                               &read_size_adc);
   }

#ifdef INSTRUM_RSF_WITH_GPIO
   *gpioPtr = 1;
#endif /* INSTRUM_RSF_WITH_GPIO */

   adc_over_spi_nb_ob_bytes = read_size_adc;

   /* SG~SAI */
   updateVoltageBuffer(0.0,10.0,  3,  26,adc_over_spi_rx_buffer_adc_1,sg1_sg3_sg4_sai1_sai3_gnd ,2,uod_bypass.sg1_sg3_sai1_sai3_sig);
   updateVoltageBuffer(0.0,10.0, 30,  53,adc_over_spi_rx_buffer_adc_1,sg1_sg3_sai1_sai3_sig     ,2,uod_bypass.sg1_sg3_sg4_sai1_sai3_gnd);
   updateVoltageBuffer(0.0,10.0, 57,  80,adc_over_spi_rx_buffer_adc_1,sg1_sg3_sg4_sai1_sai3_exc ,2,uod_bypass.sg1_sg3_sg4_sai1_sai3_exc);
   updateVoltageBuffer(0.0,10.0, 88, 111,adc_over_spi_rx_buffer_adc_1,sg4_sig                   ,2,uod_bypass.sg4_sig);

   updateVoltageBuffer(0.0,10.0,  3,  26,adc_over_spi_rx_buffer_adc_2,sg2_sg5b_sai2_sai4_gnd    ,2,uod_bypass.sg2_sai2_sig);
   updateVoltageBuffer(0.0,10.0, 30,  53,adc_over_spi_rx_buffer_adc_2,sg2_sai2_sig              ,2,uod_bypass.sg2_sg5b_sai2_sai4_gnd);
   updateVoltageBuffer(0.0,10.0, 57,  80,adc_over_spi_rx_buffer_adc_2,sg2_sg5b_sai2_sai4_exc    ,2,uod_bypass.sg2_sg5b_sai2_sai4_exc);
   updateVoltageBuffer(0.0,10.0, 88, 111,adc_over_spi_rx_buffer_adc_2,sg5_sai4_sig              ,2,uod_bypass.sg5_sai4_sig);

   /* POT */
   updateVoltageBuffer(0.0,2.5,115, 138,adc_over_spi_rx_buffer_adc_3,pot_signal_1_2_raw         ,2,uod_bypass.pot_1_2_signal_raw);
   updateVoltageBuffer(0.0,2.5,146, 169,adc_over_spi_rx_buffer_adc_3,pot_exc_1_2_raw            ,2,uod_bypass.pot_1_2_exc_raw);
   updateVoltageBuffer(0.0,2.5,173, 196,adc_over_spi_rx_buffer_adc_3,pot_gnd_raw                ,2,uod_bypass.pot_gnd_raw);
   updateVoltageBuffer(0.0,2.5,200, 223,adc_over_spi_rx_buffer_adc_3,pot_ref_raw                ,2,uod_bypass.pot_ref_raw);
   updateVoltageBuffer(0.0,2.5,231, 254,adc_over_spi_rx_buffer_adc_3,pot_signal_3_raw           ,2,uod_bypass.pot_3_signal_raw);
   updateVoltageBuffer(0.0,2.5,262, 285,adc_over_spi_rx_buffer_adc_3,pot_exc_3_raw              ,2,uod_bypass.pot_3_exc_raw);

   /* VRT */
   if((uint32_t)1 == (uint32_t)1 == pt_oss_conf->s_t1_configuration)
   {
      /* If VRT1 PT1000 Configuration */
      updateVoltageBuffer(0.0,2.5,289, 312,adc_over_spi_rx_buffer_adc_3,vrt1_shunt_curr_raw     ,2,uod_bypass.vrt1_shunt_curr_raw);
      updateVoltageBuffer(5.0,5.0,320, 343,adc_over_spi_rx_buffer_adc_3,vrt1_voltage_raw        ,2,uod_bypass.vrt1_voltage_raw);
   }
   else
   {
      /* If VRT1 PT100 Configuration */
      updateVoltageBuffer(5.0,5.0,289, 312,adc_over_spi_rx_buffer_adc_3,vrt1_shunt_curr_raw     ,2,uod_bypass.vrt1_shunt_curr_raw);
      updateVoltageBuffer(0.0,2.5,320, 343,adc_over_spi_rx_buffer_adc_3,vrt1_voltage_raw        ,2,uod_bypass.vrt1_voltage_raw);
   }

   updateVoltageBuffer(0.0,2.5,347, 370,adc_over_spi_rx_buffer_adc_3,gnd_voltage_raw            ,2,uod_bypass.gnd_voltage_raw);

   if((uint32_t)1 == pt_oss_conf->s_t2_configuration)
   {
      /* If VRT2 PT1000 Configuration */
      updateVoltageBuffer(0.0,2.5,374, 397,adc_over_spi_rx_buffer_adc_3,vrt2_shunt_curr_raw     ,2,uod_bypass.vrt2_shunt_curr_raw);
      updateVoltageBuffer(5.0,5.0,405, 428,adc_over_spi_rx_buffer_adc_3,vrt2_voltage_raw        ,2,uod_bypass.vrt2_voltage_raw);
   }
   else
   {
      /* If VRT2 PT100 Configuration */
      updateVoltageBuffer(5.0,5.0,374, 397,adc_over_spi_rx_buffer_adc_3,vrt2_shunt_curr_raw     ,2,uod_bypass.vrt2_shunt_curr_raw);
      updateVoltageBuffer(0.0,2.5,405, 428,adc_over_spi_rx_buffer_adc_3,vrt2_voltage_raw        ,2,uod_bypass.vrt2_voltage_raw);
   }

   if((uint32_t)1 == pt_oss_conf->s_tff_configuration)
   {
      /* If VRTFF PT1000 Configuration */
      updateVoltageBuffer(5.0,5.0,436, 459,adc_over_spi_rx_buffer_adc_3,vrtff_voltage_raw       ,2,uod_bypass.vrtff_voltage_raw);
      updateVoltageBuffer(0.0,2.5,467, 490,adc_over_spi_rx_buffer_adc_3,vrtff_shunt_curr_raw    ,2,uod_bypass.vrtff_shunt_curr_raw);
   }
   else
   {
      /* If VRTFF PT100 Configuration */
      updateVoltageBuffer(0.0,2.5,436, 459,adc_over_spi_rx_buffer_adc_3,vrtff_voltage_raw       ,2,uod_bypass.vrtff_voltage_raw);
      updateVoltageBuffer(5.0,5.0,467, 490,adc_over_spi_rx_buffer_adc_3,vrtff_shunt_curr_raw    ,2,uod_bypass.vrtff_shunt_curr_raw);
   }

   /* CALRES */
   updateVoltageBuffer(5.0,5.0,493, 508,adc_over_spi_rx_buffer_adc_1,calres_signal_2_4_raw      ,1,uod_bypass.calres_2_4_signal_raw);
   updateVoltageBuffer(5.0,5.0,493, 508,adc_over_spi_rx_buffer_adc_2,calres_signal_1_3_raw      ,1,uod_bypass.calres_1_3_signal_raw);
   updateVoltageBuffer(5.0,5.0,511, 526,adc_over_spi_rx_buffer_adc_1,calres_ref_2_4_raw         ,1,uod_bypass.calres_2_4_ref_raw);
   updateVoltageBuffer(5.0,5.0,511, 526,adc_over_spi_rx_buffer_adc_2,calres_ref_1_3_raw         ,1,uod_bypass.calres_1_3_ref_raw);
   updateVoltageBuffer(0.0,2.5,529, 544,adc_over_spi_rx_buffer_adc_1,calres_gnd_2_4_raw         ,1,uod_bypass.calres_2_4_gnd_raw);
   updateVoltageBuffer(0.0,2.5,529, 544,adc_over_spi_rx_buffer_adc_2,calres_gnd_1_3_raw         ,1,uod_bypass.calres_1_3_gnd_raw);

   /* T4 */
   updateVoltageBuffer(0.0,10.0,548, 571,adc_over_spi_rx_buffer_adc_3,t4_sig                    ,2,uod_bypass.t4_sig);
   updateVoltageBuffer(0.0,10.0,575, 598,adc_over_spi_rx_buffer_adc_3,t4_gnd                    ,2,uod_bypass.t4_gnd);
   updateVoltageBuffer(0.0,10.0,602, 625,adc_over_spi_rx_buffer_adc_3,t4_ref                    ,2,uod_bypass.t4_ref);

   /* P3 */
   updateVoltageBuffer(0.0,10.0,629, 652,adc_over_spi_rx_buffer_adc_3,p3_sig                    ,2,uod_bypass.p3_sig);
   updateVoltageBuffer(0.0,10.0,656, 679,adc_over_spi_rx_buffer_adc_3,p3_gnd                    ,2,uod_bypass.p3_gnd);
   updateVoltageBuffer(0.0,10.0,683, 706,adc_over_spi_rx_buffer_adc_3,p3_exc                    ,2,uod_bypass.p3_exc);

   /* LVDT */
   updateVoltageBuffer(0.0,10.0,709, 796,adc_over_spi_rx_buffer_adc_1,lvdt_a_b_s1_raw           ,1,uod_bypass.lvdt_a_b_s1_raw);
   updateVoltageBuffer(0.0,10.0,799, 886,adc_over_spi_rx_buffer_adc_1,lvdt_c_s1_raw             ,1,uod_bypass.lvdt_c_s1_raw);

   updateVoltageBuffer(0.0,10.0,709, 796,adc_over_spi_rx_buffer_adc_2,lvdt_a_b_s2_raw           ,1,uod_bypass.lvdt_a_b_s2_raw);
   updateVoltageBuffer(0.0,10.0,799, 886,adc_over_spi_rx_buffer_adc_2,lvdt_c_s2_raw             ,1,uod_bypass.lvdt_c_s2_raw);

   updateVoltageBuffer(0.0,10.0,709, 796,adc_over_spi_rx_buffer_adc_3,lvdt_a_b_exc_raw          ,1,uod_bypass.lvdt_a_b_exc_raw);
   updateVoltageBuffer(0.0,10.0,799, 886,adc_over_spi_rx_buffer_adc_3,lvdt_c_exc_raw            ,1,uod_bypass.lvdt_c_exc_raw);

   /* XR */
   updateVoltageBuffer(0.0,10.0,889, 976,adc_over_spi_rx_buffer_adc_1,xr_vsin_raw               ,1,uod_bypass.xr_vsin_raw);
   updateVoltageBuffer(0.0,10.0,979, 990,adc_over_spi_rx_buffer_adc_1,xr_vsin_ref               ,1,uod_bypass.xr_vsin_ref);
   updateVoltageBuffer(0.0,10.0,993,1004,adc_over_spi_rx_buffer_adc_1,xr_vsin_gnd               ,1,uod_bypass.xr_vsin_gnd);

   updateVoltageBuffer(0.0,10.0,889, 976,adc_over_spi_rx_buffer_adc_2,xr_vcos_raw               ,1,uod_bypass.xr_vcos_raw);
   updateVoltageBuffer(0.0,10.0,979, 990,adc_over_spi_rx_buffer_adc_2,xr_vcos_ref               ,1,uod_bypass.xr_vcos_ref);
   updateVoltageBuffer(0.0,10.0,993,1004,adc_over_spi_rx_buffer_adc_2,xr_vcos_gnd               ,1,uod_bypass.xr_vcos_gnd);

   updateVoltageBuffer(0.0,10.0,889, 976,adc_over_spi_rx_buffer_adc_3,xr_exc_raw                ,1,uod_bypass.xr_exc_raw);
}

/* ---------- internal operation bodies: ------------------------------------ */
