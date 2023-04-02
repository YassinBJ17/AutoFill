#ifndef HW_CONF_H
#define HW_CONF_H

#include "LIBMCP_Types.h"
#include "LIBBSP_ETSEC.h"

/*------------------------------------------------------------------------------*/
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : HW_CONF                                                           */
/* FILENAME : hw_conf.h                                                       */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*| DATE   |    Name/Company   | PR  |               PR                         */
/*|        |                   | Num |              Title                       */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*|01/01/01| My_Name/Sagem     | -   |  Header creation                         */
/*+--------+-------------------+-----+-----------------------------------------+*/

/* ---------- DLD symbol ---------------------------------------------------- */
/* none */

/* ---------- include required interface: ----------------------------------- */


/* ---------- provided define constants: ------------------------------------ */
 
 /* ----------------------- */
 /* eTsec nb                */
 /* ----------------------- */
 #define    NB_ETSEC    3   /* */
 
 /* ----------------------- */
 /* smi nb                  */ 
 /* ----------------------- */
 #define    NB_SMI          3   /* */
 
 /* ----------------------- */
 /* phy nb                  */ 
 /* ----------------------- */
 #define    NB_PHY          3   /* */


 /* On n'utilise que FCC1 et FCC2 */
 #define C_HW_FCC1_INDEX  ((uint32_t)0)
 #define C_HW_FCC2_INDEX  ((uint32_t)1)

 /* ----------------------- */
 /* network number          */ 
 /* ----------------------- */
 #define ETHERNET_NB_NETWORKS    ((uint32_t)3) 
 /*#define ETHERNET_NB_CONTROLLERS ((uint32_t)3)*/

/* Le Network externe sort sur le connecteur J11 */
#define C_NETWORK_ETSEC1     ((uint32_t)0)
#define C_NETWORK_ETSEC2     ((uint32_t)1)
#define C_NETWORK_ETSEC3     ((uint32_t)2)

 /* ----------------------- */
 /* frames registers number */
 /* ----------------------- */
 
/* #define ETHERNET_RX_BUFFER_SIZE            ((uint32_t)1536)    1536 bytes : shall be mutliple of 64 (cf datasheet)*/
/* #define ETHERNET_TX_BUFFER_SIZE            ((uint32_t)1536)    1536 bytes : shall be mutliple of 64 (cf datasheet)*/
/* #define ETHERNET_MAX_FRAME_SIZE            ((uint32_t)1518)    1518 bytes according to standard Ethernet 802.3    */
 
 /* ----------------------- */
 /* speed configuration     */
 /* ----------------------- */
 #define HW_CONF_LINK_SPEED_10_MBITS     0    /* ethernet speed = 10Mbit/s    */
 #define HW_CONF_LINK_SPEED_100_MBITS    1ul    /* ethernet speed = 100Mbit/s   */
 #define HW_CONF_LINK_SPEED_1000_MBITS   2ul    /* ethernet speed = 1000Mbit/s  */
 
 /* ----------------------- */
 /* duplex configuration    */
 /* ----------------------- */
 #define HW_CONF_LINK_FULL_DUPLEX        0ul  /* ethernet full duplex */
 #define HW_CONF_LINK_HALF_DUPLEX        1  /* ethernet half duplex */
 
 /* ----------------------- */
 /* link type               */
 /* ----------------------- */
 #define HW_CONF_LINK_TYPE_MII           0  /* link between eTSEC and PHY is MII    */
 #define HW_CONF_LINK_TYPE_RMII          1  /* link between eTSEC and PHY is RMII   */
 #define HW_CONF_LINK_TYPE_RGMII         2  /* link between eTSEC and PHY is RGMII  */
 #define HW_CONF_LINK_TYPE_SGMII         3ul  /* link between eTSEC and PHY is SGMII  */
 
 /* ----------------------- */
 /* CRC type                */
 /* ----------------------- */
 #define HW_CONF_CRC_TYPE_HW            0 /* ethernet frame crc computed by hw (cpu) */
 #define HW_CONF_CRC_TYPE_SW            1 /* ethernet frame crc computed by sw       */
 
 /* ----------------------- */
 /* BOARD type              */
 /* ----------------------- */
 #define HW_BOARD_P1020RDB   0
 #define HW_BOARD_GANAV      1
 
 /* ----------------------- */
 /* Ethernet Driver         */
 /* ----------------------- */
 #define ETSEC               0ul
 #define FEC                 1ul
 
 /* ----------------------- */
 /* PHY devices             */
 /* ----------------------- */
 #define  NO_PHY    0xFFFFFFFFul
 #define  PHY_1     0
 #define  PHY_2     1
 #define  PHY_3     2 

 /* ----------------------- */
 /* MMI Bus                 */
 /* ----------------------- */
 #define  MDIO_1         0
 #define  MDIO_2         1
 #define  MDIO_3         2
 #define  NB_MDIO        3
 
 /* ----------------------- */
 /* PHY chipsets            */
 /* ----------------------- */
 #define  PHY_GENERIC      0

 /* ----------------------- */
 /* PHY auto-negociation    */
 /* ----------------------- */
 /* If this is set to enable,the forced link modes above are completely ignored. */
 #define AUTONEG_DISABLE    0x00
 #define AUTONEG_ENABLE     0x01ul
 

 
/* ---------- provided types: ----------------------------------------------- */
typedef struct
{
   uint32_t   driver;           /* link to the driver = Vitesse  8221  */
   uint32_t   eth_device;       /* link to the ethernet device */
   uint32_t   bus;              /* link to the mii bus device  */
   uint32_t   speed;            /* forced or partner speed  */
   uint32_t   duplex;           /* forced or partner duplex */
   uint32_t   pause;            /* forced or partner pause  */
   uint32_t   auto_negociation; /* autonegociation of speed, duplex and pause */
   uint32_t   identity;         /* identity of the PHY */
   uint32_t   address;          /* address of the PHY */
} 
   TS_conf_hw_phy_init;   /* configuration structure linked to HARDWARE BOARD */

 
typedef struct
{
   uint32_t   driver;              /* type of ethernet controller       */
   uint32_t   tbi_bus;             /* mdc/mdio device for ethernet      */
   uint32_t   phy_device;          /* phy device                        */
   uint32_t   mdio_speed;          /* mdc/mdio bus speed                */
   uint32_t   interface;           /* type of ethernet link (xGMII)     */  
   uint32_t   crc_type;            /* type of CRC (hw computed of sw)   */    
   uint32_t   speed;               /* speed of ethernet link            */    
   uint32_t   duplex;              /* duplex mode                       */
   uint32_t   etsec_base_address;  /* base address of ETSEC x           */
   uint32_t   mdio_base_address;   /* base address of MDIO              */
   uint8_t    tbi_base_address;    /* base addresse of Ten Bit Interfaces (pour SGMII)      */   
}
   TS_conf_hw_cpu_init;       /* configuration structure linked to ETSEC */

typedef struct 
{
   TS_conf_hw_cpu_init init[NB_ETSEC];
}
   TS_conf_cpu;
   
typedef struct
{
   TS_conf_hw_phy_init init[NB_PHY];
}
   TS_conf_phy;

extern const TS_conf_phy             CONF_PHY;
extern const TS_conf_cpu             CONF_CPU;


/* ---------- provided operations: ------------------------------------------ */
extern uint32_t controller_of_network (const uint32_t network);

#endif /* HW_CONF_H */
