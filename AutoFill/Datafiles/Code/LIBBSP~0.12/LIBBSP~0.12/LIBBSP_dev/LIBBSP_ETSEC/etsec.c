/* ---------- include provided interface: ------------------------------------- */
#include "LIBMCP_Types.h"
#include "HW_CONF.h"
#include "HW_TB.h"

#include "tbi.h"
#include "phy.h"
#include "smi.h"

#include "Initialize_MACCFG2.h"
#include "Initialize_ECNTRL.h"

#include "LIBBSP_ETSEC_InitAddress.h"
/* ---------- include required interface: ------------------------------------- */
#include "etsec.h"



/* ---------- internal define constants: -------------------------------------- */
/* none */

/* ---------- internal types: ------------------------------------------------- */
/* none */

/* ---------- internal operations: -------------------------------------------- */
/* none */

/* ---------- internal data: -------------------------------------------------- */
/* none */

/* ---------- provided operation bodies: -------------------------------------- */

void etsec_reset( const uint32_t device )
{
   uint32_t          tbi_base_address;
   t_ETSEC         *p_etsec; 

   p_etsec = (t_ETSEC*)((uint32_t)(CONF_CPU.init[device].etsec_base_address) + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> Explicite adresse manipulation*/
   tbi_base_address =   (uint32_t)CONF_CPU.init[device].tbi_base_address;
   
   /* Reset the MAC */
   /*setbits_be32(&priv->regs->maccfg1, ETSEC_MACCFG1_SOFT_RESET);*/
   /*HW_TB_wait(2);   Soft Reset must be asserted for 3 TX clocks */
   /*out_be32(&priv->regs->maccfg2, MACCFG2_INIT_SETTINGS);*/
   /*clrbits_be32(&priv->regs->maccfg1, ETSEC_MACCFG1_SOFT_RESET);*/

                                       /* set MACCFG1[Soft_Reset] bit  */
   asm("sync");
   p_etsec->MACCFG1 = p_etsec->MACCFG1 | ETSEC_MACCFG1_SOFT_RESET;        

                                       /* Soft Reset must be asserted for 3 TX clocks */
   HW_TB_wait(0x6ul);

                                       /* clear MACCFG1[Soft_Reset] bit  */
   asm("sync");
   p_etsec->MACCFG1 = p_etsec->MACCFG1 & (~ETSEC_MACCFG1_SOFT_RESET) ;

                                       /* program TBIPA reg */
   p_etsec->TBIPA = tbi_base_address;  
}

/* BEGIN FUNCTION HEADER------------------------------------------------------- */
/* <<LLR:  >>  SDD_xxx_LLR_REQ_xxxxxx                                           */
/*                                                                              */
/* <<FUNCTION:  >>  etsec_init                                                  */
/*                                                                              */
/* <<BRIEF:  >>  This function initialize an ETSECx                             */
/*                                                                              */
/* <<DESCRIPTION:  >>   This function initialize :                              */
/*                      - the ETSECx registers                                  */
/*                      - the ETSEC_MDIOx register                              */
/*                      - the PHYs registers                                    */
/* END FUNCTION HEADER--------------------------------------------------------- */
void etsec_init (const uint32_t device,
                 const uint8_t * const txbd_addr, 
                 const uint8_t * const rxbd_addr,
                 const TS_LIBBSP_ETSEC_ConfHostMac * const p_mac)
{
    volatile t_ETSEC         *p_etsec; 
    uint32_t          init_value;
    uint32_t          interface;
    uint32_t          speed;
    uint32_t          crc_type;
    uint32_t          phy;
    uint32_t          duplex;
    
    /* ------------------------------ */
    /* Get the registers base addresse */
    /* ------------------------------ */
    p_etsec = (t_ETSEC*)((uint32_t)(CONF_CPU.init[device].etsec_base_address) + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> Explicite adresse manipulation*/
    
    /* get typee from CPU dependant parameter table */
    interface = CONF_CPU.init[device].interface;
    crc_type  = CONF_CPU.init[device].crc_type;
    phy       = CONF_CPU.init[device].phy_device;
    speed     = CONF_CPU.init[device].speed;
    duplex    = CONF_CPU.init[device].duplex;

    if( phy != NO_PHY )
    {
       /* get the autonegotiated values */
       speed     = CONF_PHY.init[phy].speed;
       duplex    = CONF_PHY.init[phy].duplex;
    }
    
    /********************************************************/
    /*                                                      */
    /*  STEP1 : ETSEC AND PHY REGISTERS INITIALIZATION      */
    /*          (to establish link betewen ETSEC and PHY)   */
    /*                                                      */
    /********************************************************/
    
    /* ------------------------------------ */
    /* 0. Initialize the DMACTRL register   */
    /* ------------------------------------ */
    p_etsec->DMACTRL = (ETSEC_DMACTRL_GRS | ETSEC_DMACTRL_GTS) ;          
    
    /* ------------------------------------ */
    /* 1. Set and clear MACCFG1[Soft_Reset] */
    /* ------------------------------------ */
    p_etsec->MACCFG1 = ETSEC_MACCFG1_SOFT_RESET;        /* set MACCFG1[Soft_Reset] bit  */
    p_etsec->MACCFG1 = 0ul;                               /* clear MACCFG1[Soft_Reset] bit*/
	
    /*p_etsec->MACCFG1 = ETSEC_MACCFG1_LOOPBACK;			 set loopback for testing purpose */
    
    /* ------------------------------------ */
    /* 2. Initialize MACCFG2                */
    /* ------------------------------------ */
    Initialize_MACCFG2(&init_value, speed, crc_type, duplex);
    
    /* assign initialization value to ETSEC register */
    p_etsec->MACCFG2 = init_value;  
    
    /* ------------------------------------ */
    /* 3. Initialise ECNTRL                 */
    /* ------------------------------------ */
    
    Initialize_ECNTRL(&init_value, interface, speed);
    
    /* assign initialization value to ETSEC register */
    p_etsec->ECNTRL = init_value;
    
    /* ------------------------------------ */
    /* 4. Initialize MAC station address     */
    /* ------------------------------------ */    
    p_etsec->MACSTNADDR2 = (((uint32_t)p_mac->mac_addr[0]) << 16)   /* set 1st byte of mac address */
                         | (((uint32_t)p_mac->mac_addr[1]) << 24);  /* set 2nd byte of mac address */
    p_etsec->MACSTNADDR1 = ((uint32_t)p_mac->mac_addr[2])         /* set 3rd byte of mac address */
                         | (((uint32_t)p_mac->mac_addr[3]) << 8)    /* set 4rd byte of mac address */
                         | (((uint32_t)p_mac->mac_addr[4]) << 16)   /* set 5rd byte of mac address */
                         | (((uint32_t)p_mac->mac_addr[5]) << 24);  /* set 6rd byte of mac address */

    /* ---------------------------------------- */
    /* 5. remap TBI address                      */
    /* ---------------------------------------- */        
    
    /* re-map the TBI in order to not conflict with external PHYs */
    p_etsec->TBIPA = (uint32_t)(CONF_CPU.init[device].tbi_base_address);  /* program TBIPA reg */
   
    p_etsec->IEVENTGx = 0ul;             /* Clear IEVENTGg                     */
    p_etsec->IMASKGx = 0ul;              /* Clear IMASKGg                     */
    p_etsec->RCTRL = ETSEC_RCTRL_INIT; /* accept all frames : not parametrable for the moment */

    /* Set RxBD base address */
    /*p_etsec->RBASEH = ((uint32_t)rxbd_addr & ETSEC_BASEH_MASK); */
    /*p_etsec->RBASE0 = ((uint32_t)rxbd_addr & ETSEC_BASE0_MASK); */
    p_etsec->RBASE0 = (uint32_t)rxbd_addr; /* %RELAX<SYNCHRONe_C_Code_11.1> Conversion of pointer because adresse manipulation*/
      
    /* Set Receive Buffer Descriptor Pointers 0 */
    /*p_etsec->RBDBPH = ((uint32_t)rxbd_addr & ETSEC_BASEH_MASK); */
    /*p_etsec->RBPTR0 = ((uint32_t)rxbd_addr & ETSEC_BASE0_MASK); */

    /* Set TxBD base address */
    p_etsec->TBASE0 = (uint32_t)txbd_addr; /* %RELAX<SYNCHRONe_C_Code_11.1> Conversion of pointer because adresse manipulation*/
    /*p_etsec->TBASEH = ((uint32_t)txbd_addr & ETSEC_BASEH_MASK); */
    /*p_etsec->TBASE0 = ((uint32_t)txbd_addr & ETSEC_BASE0_MASK); */
        
    /* Set Receive Buffer Descriptor Pointers 0 */
    /*p_etsec->TBDBPH = ((uint32_t)txbd_addr & ETSEC_BASEH_MASK); */
    /*p_etsec->TBPTR0 = ((uint32_t)txbd_addr & ETSEC_BASE0_MASK); */
    
    /* Set Maximum receive frame length */
    p_etsec->MAXFRM = ETSEC_MAXFRM_FRAME_SIZE;
    
    /* Set Maximum receive buffer length */
    p_etsec->MRBLR = ETSEC_MRBLR_BUFFER_SIZE;
    
    /* Init Tx and Rx Queue Control Register */
    /*p_etsec->TQUEUE = ETSEC_TQUEUE_0_EN; */
    /*p_etsec->RQUEUE = ETSEC_RQUEUE_0_EN; */
    
    /* ---------------------------------------- */
    /* 10. Initialise DMACTRL                    */
    /* ---------------------------------------- */           
    
    /* clear GRS/GTS control bits and set SNOOP bits */
    p_etsec->DMACTRL &= ETSEC_DMACTRL_DATA_SNOOP | ETSEC_DMACTRL_TXBD_SNOOP;
}

/* BEGIN FUNCTION HEADER------------------------------------------------------- */
/* <<LLR:  >>  SDD_xxx_LLR_REQ_xxxxxx                                           */
/*                                                                              */
/* <<FUNCTION:  >>  etsec_rx_enable                                      */
/*                                                                              */
/* <<BRIEF:  >>  This function enable or disbale Reception of a selected ETSECx */
/*                                                                              */
/* <<DESCRIPTION:  >>   This function enable the reception of the ETSECx ID     */ 
/*                      passed in argument by writing the correspondong bit     */
/*                      in the MACCFG1 register                                 */
/* END FUNCTION HEADER--------------------------------------------------------- */
void etsec_rx_enable (const uint32_t device, 
                      const boolean_t enable)
{      
    t_ETSEC* p_etsec;  /* base address value */
    
    p_etsec = (t_ETSEC*)((uint32_t)(CONF_CPU.init[device].etsec_base_address) + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> Explicite adresse manipulation*/  
    
    if(enable != FALSE)
    {
       p_etsec->MACCFG1 = p_etsec->MACCFG1 | ETSEC_MACCFG1_RX_EN;
    }
    else
    {
       p_etsec->MACCFG1 = p_etsec->MACCFG1 & (~ETSEC_MACCFG1_RX_EN);
    }
}

/* BEGIN FUNCTION HEADER------------------------------------------------------- */
/* <<LLR:  >>  SDD_xxx_LLR_REQ_xxxxxx                                           */
/*                                                                              */
/* <<FUNCTION:  >>  etsec_tx_enable                                      */
/*                                                                              */
/* <<BRIEF:  >>  This function enable or disbale Reception of a selected ETSECx */
/*                                                                              */
/* <<DESCRIPTION:  >>   This function enable the reception of the ETSECx ID     */ 
/*                      passed in argument by writing the correspondong bit     */
/*                      in the MACCFG1 register                                 */
/* END FUNCTION HEADER--------------------------------------------------------- */
void etsec_tx_enable (const uint32_t device, 
                      const boolean_t enable)
{
    t_ETSEC* p_etsec;  /* base address value */
    
    p_etsec = (t_ETSEC*)((uint32_t)(CONF_CPU.init[device].etsec_base_address) + (uint32_t)V_LIBBSP_ETSEC_ccsr_base_address); /* %RELAX<SYNCHRONe_C_Code_10.7> Explicite adresse manipulation*/  
    
    if(enable != FALSE)
    {
        p_etsec->MACCFG1 = p_etsec->MACCFG1 | ETSEC_MACCFG1_TX_EN;
    }
    else
    {
       p_etsec->MACCFG1 = p_etsec->MACCFG1 & (~ETSEC_MACCFG1_TX_EN);
    }
}

