#ifndef PHY_H
#define PHY_H

#include "HW_CONF.h"
#include "smi.h"
/*------------------------------------------------------------------------------*/
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : PHY                                                               */
/* FILENAME : phy.h                                                             */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*| DATE   |    Name/Company   | PR  |               PR                         */
/*|        |                   | Num |              Title                       */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*|01/01/01| My_Name/Sagem     | -   |  Header creation                         */
/*+--------+-------------------+-----+-----------------------------------------+*/

/* ---------- DLD symbol ---------------------------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */
/* none */

/* ---------- provided define constants: ------------------------------------ */
 
/* ----------------------- */
/* phy id                  */ 
/* ----------------------- */ 
/* there is no PHY on the board for ETSEC 0 */

#define SMI_PHY_LINK_STATUS_DISCONNECTED    (uint16_t)(0x2000)
#define SMI_PHY_LINK_STATUS_ACTIVE          (uint16_t)(0x1000)    
#define SMI_PHY_LINK_IS_UP                  (uint16_t)(0x0004)  
#define SMI_PHY_REMOTE_RECEIVER_OK          (uint16_t)(0x1000)                        


/* ---------- provided types: ----------------------------------------------- */
/* none */
 
 /* ---------- provided operations: ------------------------------------------ */
typedef    uint32_t     t_phy_handle;

/* interface of the PHY driver            */
/* (that depends on the chipset)          */
/* (so as freesacle boot)                 */           
/*  - config  : to configure the hardware */          
/*  - startup : to start the phy          */
/*  - probe : for future use              */
/*  - loopback : for future use           */
/*  - shutdown : for future use           */

extern void  phy_config       (const t_phy_handle phy);
/*extern void  phy_startup      (const t_phy_handle phy);*/ /*unused */
extern void  phy_shutdwon     (const t_phy_handle phy);
extern void  phy_probe        (const t_phy_handle phy);

/* interface of the PHY                   */
extern void  phy_reset        (const t_phy_handle phy);
extern void  phy_connect      (const t_phy_handle phy);
extern int32_t phy_get_identity (const t_phy_handle phy);
extern boolean_t phy_is_link_up (const t_phy_handle phy);

/* internal subdision of the phy functions */
/*extern void  phy_advertise     (const t_phy_handle phy);*/ /*unused*/
/*extern void  phy_auto_negotiate(const t_phy_handle phy);*/ /*unused*/
/*extern void  phy_update_link   (const t_phy_handle phy);*/ /*unused*/
/*extern void  phy_parse_link    (const t_phy_handle phy);*/ /*unused*/

extern int32_t phy_read( const t_phy_handle phy, const uint32_t reg_number );

extern void phy_write( const t_phy_handle phy, const uint32_t reg_number, const uint16_t value);


//-----extern uint8_t  HW_BOARD_PHY_get_address(uint32_t phy_device);
//-----extern uint32_t HW_BOARD_PHY_get_type(uint32_t phy_device)
//-----extern uint32_t HW_BOARD_PHY_get_mii(uint32_t phy_device)
//-----extern void   HW_BOARD_PHY_init(uint32_t phy_device); 

#endif /* PHY_H */
