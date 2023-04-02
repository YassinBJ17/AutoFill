/* ---------- include provided interface: ------------------------------------- */
#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "smi.h"

/* ---------- include required interface: ------------------------------------- */
#include "tbi.h"

/* ---------- internal define constants: -------------------------------------- */
/* none */

/* ---------- internal types: ------------------------------------------------- */
/* none */

/* ---------- internal operations: -------------------------------------------- */
/* none */

/* ---------- internal data: -------------------------------------------------- */
/* none */

/* ---------- provided operation bodies: -------------------------------------- */
void tbi_config( const uint32_t device )
/* in linux, it is called tsec_configure_serdes */
{
   uint32_t tbi_base_address;
   uint32_t bus;
   int32_t mask;
   
   /* {{RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> possible lost of precision: Hexa 32 bits casted to uint32 and now casted to int32 */
   tbi_base_address = (uint32_t)(CONF_CPU.init[device].tbi_base_address & (uint8_t)0x1F);
   bus              = CONF_CPU.init[device].tbi_bus;
   
   /* TBI access is managed as a PHI access via the MMI bus */
   
   /* Write to register 0 : TBI Control register */
   mask = (int32_t)(TBI_TBICR_AUTONEG_ENABLE | TBI_TBICR_1000MBIT_MAX_SPEED  | TBI_TBICR_FULL_DUPLEX);
   mii_phy_write( bus, tbi_base_address, (uint32_t)TBI_CR, mask);

   /* Write to register 17 : TBI control register */
   mask = (int32_t)TBI_TBICON_ENABLE_CLOCK;
   mii_phy_write( bus, tbi_base_address, (uint32_t)TBI_CON, mask );
            
   /* Write to register 4 : TBI AN advertisement register */
   mask = (int32_t)TBI_TBIAN_SGMII_AUTONEG;
   mii_phy_write( bus, tbi_base_address, (uint32_t)TBI_ANA, mask ); //GCH

   /* Reset AN */
   mask = (int32_t)(TBI_TBICR_AUTONEG_ENABLE | TBI_TBICR_AUTONEG_RESET | TBI_TBICR_1000MBIT_MAX_SPEED  | TBI_TBICR_FULL_DUPLEX);
   mii_phy_write( bus, tbi_base_address, (uint32_t)TBI_CR, mask);
   /* }} RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> */
}
