
/* ---------- include provided interface: ------------------------------------- */
#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "etsec.h"
#include "tbi.h"
#include "LIBBSP_ETSEC_InitAddress.h"

/* ---------- include required interface: ------------------------------------- */
#include "smi.h"

/* ---------- internal define constants: -------------------------------------- */
/* none */

/* ---------- internal types: ------------------------------------------------- */
/* none */

/* ---------- internal operations: -------------------------------------------- */
#if 0
extern inline u32 in_be32(const volatile u32 __iomem * const addr)
{
    u32 ret;

    __asm__ __volatile__("sync; lwz%U1%X1 %0,%1;\n"
                 "twi 0,%0,0;\n"
                 "isync" : "=r" (ret) : "m" (*addr));
    return ret;
}
#endif /* 0 */


#if 0
inline void out_be32(volatile u32 __iomem * const addr, const u32 val)
{
    __asm__ __volatile__("sync; stw%U0%X0 %1,%0" : "=m" (*addr) : "r" (val));
}
#endif /* 0 */

/* ---------- internal data: -------------------------------------------------- */
/* none */

/* ---------- provided operation bodies: -------------------------------------- */
void mii_reset (const uint32_t bus)
{
   TS_ETSEC_MDIO* volatile p_etsec_mdio;
   uint32_t value;
   uint32_t timeout;

   p_etsec_mdio = (TS_ETSEC_MDIO*) ((uint32_t)CONF_CPU.init[bus].mdio_base_address + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */

   p_etsec_mdio->IEVENTM = 0ul;
   p_etsec_mdio->IMASKM = 0ul;
   p_etsec_mdio->EMAPM = 0ul;

   asm("sync");
   p_etsec_mdio->MIIMCFG = (uint32_t)MIIMCFG_RESET;
   
   asm("sync");
   p_etsec_mdio->MIIMCFG = CONF_CPU.init[bus].mdio_speed;
   
   asm("sync");
   value = p_etsec_mdio->MIIMIND; /*This value setting is justified by P1020 documentation, 15.9.2 and table 15-1111*/
   
   for( timeout = 1000000ul ; (timeout > 0ul) ; timeout --)
   {
       asm("sync");
       value = p_etsec_mdio->MIIMIND;    

       if((value & (uint32_t)MIIMIND_BUSY) == 0ul)
       {
    	   break;
       }
   }
}

void mii_phy_write(const uint32_t bus, const uint32_t address, const uint32_t reg_number, int32_t value )
{
   int32_t timeout;
   TS_ETSEC_MDIO* volatile p_etsec_mdio;

   p_etsec_mdio = (TS_ETSEC_MDIO*) ((uint32_t)CONF_CPU.init[bus].mdio_base_address | (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */
   
   asm("sync");
   p_etsec_mdio->MIIMADD = ((address & 0x1Ful) << 8) | (reg_number & 0x1Ful);
   
   asm("sync");
   p_etsec_mdio->MIIMCON = (uint32_t)value; /* %RELAX<SYNCHRONe_C_Code_10.7> possible loss of precision because of signedness: int to uint */
   
   asm("sync");
   /*This value setting is justified by P1020 documentation.*/
   value = (int32_t)p_etsec_mdio->MIIMIND; /* %RELAX<SYNCHRONe_C_Code_10.7> possible loss of precision because of signedness: uint to int */
   
   for( timeout = (int32_t)1000000 ; (timeout > (int32_t)0) ; timeout --)
   {
       asm("sync");
       value = (int32_t)p_etsec_mdio->MIIMIND; /* %RELAX<SYNCHRONe_C_Code_10.7> possible loss of precision because of signedness: uint to int */

       if((value & (int32_t)MIIMIND_BUSY) == (int32_t)0)
       {
    	   break;
       }
   }

   // out_be32(&p_etsec_mdio->MIIMADD, ( address << 8) | (reg_number & 0x1F));
   // out_be32(&p_etsec_mdio->MIIMCON, value);
   // while ((in_be32(&p_eTSEC_MDIO->MIIMIND) & MIIMIND_BUSY) && timeout--)
   //   ;
}

int32_t mii_phy_read(const uint32_t bus, const uint32_t address, const uint32_t reg_number )
{
   int32_t timeout;
   TS_ETSEC_MDIO* volatile p_etsec_mdio;
   int32_t value;
   int32_t invalid_mask = MIIMIND_BUSY | MIIMIND_NOT_VALID; /* %RELAX<> Hexa on 32 bits */

  p_etsec_mdio = (TS_ETSEC_MDIO*) ((uint32_t)CONF_CPU.init[bus].mdio_base_address | (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> No precision lost */

   asm("sync");
   p_etsec_mdio->MIIMADD = ( (address & 0x1Ful) << 8) | (reg_number & 0x1Ful);

   /* toggle MMI_COM "Read Cycle" bit */
   asm("sync");
   p_etsec_mdio->MIIMCOM = 0ul;
   asm("sync");
   p_etsec_mdio->MIIMCOM = (uint32_t)MIIMCOM_READ_CYCLE_EN;

   /* wait for the indication the the read is done  */
   asm("sync");
   /*This value setting is justified by P1020 documentation.*/
   value = (int32_t)p_etsec_mdio->MIIMIND; /* %RELAX<SYNCHRONe_C_Code_10.7> possible loss of precision because of signedness: uint to int */
   
   for( timeout = (int32_t)1000000 ; (timeout > (int32_t)0) ; timeout --)
   {
       asm("sync");
       value = (int32_t)p_etsec_mdio->MIIMIND; /* %RELAX<SYNCHRONe_C_Code_10.7> possible loss of precision because of signedness: uint to int */

       if((value & invalid_mask ) == (int32_t)0)
       {
    	   break;
       }
   }

   /* PHY is no more busy so the value can be read in MIIMSTAT register */
   asm("sync");
   value = (int32_t)(p_etsec_mdio->MIIMSTAT & 0xFFFFul); /* %RELAX<SYNCHRONe_C_Code_10.3, SYNCHRONe_C_Code_10.7> cast on a mask operation and possible loss of precision because of signedness: uint to int */

   if( timeout == (int32_t)1 )
   {
      value = (int32_t)(-1);
   }
   else
   {
      value = value & (int32_t)0xFFFF;
   }
   return value;

//   /* Put the address of the phy, and the register
//     * number into MIIMADD */
//   out_be32(&p_etsec_mdio->MIIMADD, (address << 8) | (reg_number & 0x1f));
//
//   /* Clear the command register, and wait */
//   out_be32(&p_etsec_mdio->MIIMCON, 0);
//   asm("sync");
//
//   /* Initiate a read command, and wait */
//   out_be32(&p_etsec_mdio->MIIMCON, MIIMCOM_READ_CYCLE);
//   asm("sync");
//
//   /* Wait for the the indication that the read is done */
//   while ((in_be32(&p_etsec_mdio->MIIMIND) & (MIIMIND_NOTVALID | MIIMIND_BUSY))
//           && timeout--)
//       ;
//
//   /* Grab the value read from the PHY */
//   value = in_be32(&p_etsec_mdio->MIIMSTAT);
//
//   return value;
}

/* BEGIN FUNCTION HEADER------------------------------------------------------- */
/* <<LLR:  >>  SDD_xxx_LLR_REQ_xxxxxx                                           */
/*                                                                              */
/* <<FUNCTION:  >>  HW_CPU_SMI_get_base_address                                  */
/*                                                                              */
/* <<BRIEF:  >>  This function return the base address of a SMI (MDIO)           */
/*                                                                              */
/* <<DESCRIPTION:  >>   This function takes the SMI ID as input and return its  */
/*                      hardware base address                                    */
/* END FUNCTION HEADER--------------------------------------------------------- */
// TS_ETSEC_MDIO* HW_CPU_SMI_get_base_address(uint32_t smi_id)
// {
//     TS_ETSEC_MDIO* base_addr;      /* base address value */
// 
//     base_addr = (TS_ETSEC_MDIO*)(CONF_CPU.init[smi_id].mdio_base_address);   /* set ETSECx_MDIO base address */ 
// 
//     return base_addr;
// }
// 
/* BEGIN FUNCTION HEADER------------------------------------------------------- */
/* <<LLR:  >>  SDD_xxx_LLR_REQ_xxxxxx                                           */
/*                                                                              */
/* <<FUNCTION:  >>  HW_CPU_SMI_link_init                                        */
/*                                                                              */
/* <<BRIEF:  >>  This function initialize the MDIO link                         */
/*                                                                              */
/* <<DESCRIPTION:  >>   This function initialize :                              */
/*                      - MMIMCFG register                                      */
/* END FUNCTION HEADER--------------------------------------------------------- */
// void HW_CPU_SMI_link_init (uint32_t bus)
// {
//     TS_ETSEC_MDIO    *p_etsec_mdio;  /* pointer to ETSEC_MDIO mapping structure */
//     
//     /* Get the registers base addresse */
//     p_etsec_mdio = HW_CPU_SMI_get_base_address( bus );  /* Get ETSEC_MDIO base corresponding to ETSEC1_ID   */ 
//                                                     /* because all PHYs smi links are driven by ETSEC1  */
//     
//     /* MII management configuration : set the MDI link configuration    */
//     /* -> MDIO conf is set only on ETSEC1 for all PHYs because          */
//     /*    only ETSEC1 is linked to all external PHYs                    */
//     if( 
//     p_etsec_mdio->MIIMCFG = CONF_CPU.init[bus].mdio_speed;
//             
//     /* check for PHY busy = 0 */
//     while ( (p_etsec_mdio->MIIMIND & MIIMIND_BUSY_MASK) != 0); /* wait for Busy bit reset */ 
//     
//     HW_CPU_SMI_wait_idle(etsec_id);
// }
    


/* BEGIN FUNCTION HEADER------------------------------------------------------- */
/* <<LLR:  >>  SDD_xxx_LLR_REQ_xxxxxx                                           */
/*                                                                              */
/* <<FUNCTION:  >>  HW_CPU_SMI_read                                                */
/*                                                                              */
/* <<BRIEF:  >>  This function read a phy register                              */
/*                                                                              */
/* <<DESCRIPTION:  >>   This function read a value in a phy register            */
/*                      of an ETSECx_MDIO (identifies by its id "mdio_id") and  */
/*                      return it.                                              */
/* END FUNCTION HEADER--------------------------------------------------------- */
// uint16_t HW_CPU_SMI_read(uint32_t etsec_id, uint32_t phy_id, uint32_t smi_reg)
// {
//     uint16_t smi_value;                 /*  */
//     TS_ETSEC_MDIO* p_eTSEC_MDIO;        /*  */  
//     uint32_t phy_addr;                   /*  */
//     
//     smi_value = 0; /* init mdio value */
//     
//     p_eTSEC_MDIO = HW_CPU_SMI_get_base_address(etsec_id);               /* get mdio base addresss    */
//     
//     phy_addr = HW_BOARD_PHY_get_address(phy_id);
//     
//     if (smi_reg < 0x20) 
//     {
//         /* program the register address to read */
//         p_eTSEC_MDIO->MIIMADD = smi_reg | (((uint32_t)(phy_addr))<<8);      /* set phy and register address    */
//     
//         /* toggle MMI_COM "Read Cycle" bit */
//         p_eTSEC_MDIO->MIIMCOM = p_eTSEC_MDIO->MIIMCOM &~ MIIMCOM_READ_CYCLE_EN; /* reset Read Rycle bit */
//         asm("sync");
//         
//         p_eTSEC_MDIO->MIIMCOM = p_eTSEC_MDIO->MIIMCOM | MIIMCOM_READ_CYCLE_EN;  /* set Read Rycle bit */
//         asm("sync");
// 
//         /* wait for Busy bit reset */
//         HW_CPU_SMI_wait_idle(etsec_id);
//     
//         /* PHY is no more busy so the value can be read in MIIMSTAT register */
//         smi_value = (uint16_t)p_eTSEC_MDIO->MIIMSTAT;                                     /* get register value */
//     }
//     else
//     {
//         /* error treatment */        
//     }
//     return smi_value;
// }
// 
// void HW_CPU_SMI_write(uint32_t bus, uint32_t device_id, uint32_t reg_number, uint32_t mdio_value)
// {
//     
//     TS_ETSEC_MDIO* volatile p_etsec_mdio;     /*  */  
//     uint32_t device_addr;               /*  */  
//         
//     p_etsec_mdio = HW_CPU_SMI_get_base_address(bus);
//     
//     if( (device_id & SMI_MASK_ADDR_TBI) == SMI_MASK_ADDR_TBI)
//     {   /* device_id is a TBI id */
//         device_id &= ~SMI_MASK_ADDR_TBI; /* reset TBI mask address bit */
//         device_addr = HW_CPU_TBI_get_address(device_id);
//     }
//     else
//     {   /* device_id is a PHY id */
//         device_addr = HW_BOARD_PHY_get_address(device_id);    
//     }
//     
//     address = CONF_PHY.init[phy].
//     
//     /* then, verify the range of the input parameters */
//      /* set PHY register address */
//      p_etsec_mdio->MIIMADD = reg_number | (((uint32_t)(device_addr))<<8);   /* set phy and register address          */
// 
//      /* set PHY register value */
//      p_etsec_mdio->MIIMCON = mdio_value;   /* set control register address      */
//      
//      /* check for "busy" bit = 0 */
//      HW_CPU_SMI_wait_idle(etsec_id);         
// }
