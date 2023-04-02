/*------------------------------------------------------------------------------*/
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : HW_CONF_Board_Table                                               */
/* FILENAME : HW_CONF_Board_Table.c                                             */
/* DESCRIPTION : this CSU is used to HW enable the PHY                          */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*| DATE   |    Name/Company   | PR  |               PR                         */
/*|        |                   | Num |              Title                       */
/*+--------+-------------------+-----+-----------------------------------------+*/
/*|01/01/01| My_Name/Sagem     | -   |  Header creation                         */
/*+--------+-------------------+-----+-----------------------------------------+*/

/* ---------- include provided interface: ------------------------------------- */
#include "LIBMCP_Types.h"

/* ---------- include required interface: ------------------------------------- */
#include "HW_CONF.h"
#include "smi.h"
#include "etsec.h"

 
/* ---------- internal define constants: -------------------------------------- */

const TS_conf_phy CONF_PHY =
{
    /*{    PHY 1 for ETSEC 1 */
        PHY_GENERIC,                        /* link to the driver = Atheros 8021 */
        ETSEC1_ID,                          /* link to the ethernet device */
        MDIO_1,                             /* link to the mii bus device  */
        HW_CONF_LINK_SPEED_100_MBITS,       /* speed forced or autonegotiated  */
        HW_CONF_LINK_FULL_DUPLEX,           /* duplex forced or autonegotiated */
        0,                                  /* pause */
        AUTONEG_DISABLE,                    /* autonegociation flag */
        0x004DD04E,                         /* identity of the PHY */
        1,                                  /* address of the PHY */
    /*} */ 
    /*{    PHY 2 for ETSEC 2 */
        PHY_GENERIC,                        /* link to the driver = Vitesse  8221  */
        ETSEC2_ID,                          /* link to the ethernet device */
        MDIO_1,                             /* link to the mii bus device  */
        HW_CONF_LINK_SPEED_100_MBITS,       /* speed forced or autonegotiated  */
        HW_CONF_LINK_FULL_DUPLEX,           /* duplex forced or autonegotiated */
        0,                                  /* pause */
        AUTONEG_DISABLE,                    /* autonegociation flag */
        0x000FC551,                         /* identity of the PHY */
        0,                                  /* address of the PHY */
    /*}, */ 
    /*{    PHY 3 for ETSEC 3 */
        PHY_GENERIC,                        /* link to the driver = Atheros 8021 */
        ETSEC3_ID,                          /* link to the ethernet device */
        MDIO_3,                             /* link to the mii bus device  */
        HW_CONF_LINK_SPEED_100_MBITS,       /* speed forced or autonegotiated  */
        HW_CONF_LINK_FULL_DUPLEX,           /* duplex forced or autonegotiated */
        0,                                  /* pause */
        AUTONEG_DISABLE,                    /* autonegociation flag */
        0x004DD04E,                         /* identity of the PHY */
        2,                                  /* address of the PHY */
    /*} */  
};

/* ---------- internal define constants: -------------------------------------- */
const TS_conf_cpu CONF_CPU =
{
    /* Note that ETSEC_1 options are : MII, RMII, RGMII */
    /*{ */
       ETSEC,                               /* etsec driver             */
       MDIO_1,                              /* bus device               */
       PHY_1,                               /* phy device               */
       /*MIIMCFG_CLK_1_4,                      mdio_speed               */
       /*MIIMCFG_CLK_1_6,                      mdio_speed               */
       /*MIIMCFG_CLK_1_8,                      mdio_speed               */
       /*MIIMCFG_CLK_1_10,                     mdio_speed               */
       /*MIIMCFG_CLK_1_14,                     mdio_speed               */
       /*MIIMCFG_CLK_1_20,                     mdio_speed               */
       MIIMCFG_CLK_1_28,                    /* mdio_speed               */
       HW_CONF_LINK_TYPE_RGMII,             /* interface                */
       HW_CONF_CRC_TYPE_HW,                 /* type of CRC              */
       HW_CONF_LINK_SPEED_100_MBITS,        /* speed of ethernet link   */
       HW_CONF_LINK_FULL_DUPLEX,            /* duplex */
       ETSEC1_BASE_ADDR,                    /* etsec_base_address ETSEC 1*/
       ETSEC1_MDIO_BASE_ADDR,               /* mdio_base_address ETSEC 1 */
       0x0A,                                /* tbi_base_address[TBI0]    */       
    /*}, */
    /* Note that ETSEC_2 options are : SGMII */
    /*{ */
       ETSEC,                               /* etsec driver             */
       MDIO_2,                              /* bus device               */
       PHY_2,                               /* phy device               */
       /*MIIMCFG_CLK_1_4,                      mdio_speed               */
       /*MIIMCFG_CLK_1_6,                      mdio_speed               */
       /*MIIMCFG_CLK_1_8,                      mdio_speed               */
       /*MIIMCFG_CLK_1_10,                     mdio_speed               */
       /*MIIMCFG_CLK_1_14,                     mdio_speed               */
       /*MIIMCFG_CLK_1_20,                     mdio_speed               */
       MIIMCFG_CLK_1_28,                    /* mdio_speed               */
       HW_CONF_LINK_TYPE_SGMII,             /* interface                */
       HW_CONF_CRC_TYPE_HW,                 /* type of CRC              */
       HW_CONF_LINK_SPEED_100_MBITS,        /* speed of ethernet link   */
       HW_CONF_LINK_FULL_DUPLEX,            /* duplex */
       ETSEC2_BASE_ADDR,                    /* etsec_base_address ETSEC 2*/
       ETSEC2_MDIO_BASE_ADDR,               /* mdio_base_address ETSEC 2 */
       0x0A,                                /* tbi_base_address[TBI1]    */       
    /*}, */
    /* Note that ETSEC_3 options are : RMII, RGMII, SGMII */
    /*{ */
       ETSEC,                               /* etsec driver             */
       MDIO_3,                              /* bus device               */
       PHY_3,                               /* phy device               */
       /*MIIMCFG_CLK_1_4,                      mdio_speed               */
       /*MIIMCFG_CLK_1_6,                      mdio_speed               */
       /*MIIMCFG_CLK_1_8,                      mdio_speed               */
       /*MIIMCFG_CLK_1_10,                     mdio_speed               */
       /*MIIMCFG_CLK_1_14,                     mdio_speed               */
       /*MIIMCFG_CLK_1_20,                     mdio_speed               */
       MIIMCFG_CLK_1_28,                    /* mdio_speed               */
       HW_CONF_LINK_TYPE_RGMII,             /* interface                */
       HW_CONF_CRC_TYPE_HW,                 /* type of CRC              */
       HW_CONF_LINK_SPEED_100_MBITS,        /* speed of ethernet link   */
       HW_CONF_LINK_FULL_DUPLEX,            /* duplex */
       ETSEC3_BASE_ADDR,                    /* etsec_base_address ETSEC 3*/
       ETSEC3_MDIO_BASE_ADDR,               /* mdio_base_address ETSEC 3 */
       0x0A                                 /* tbi_base_address[TBI2]    */              
    /*} */
};

uint32_t controller_of_network (const uint32_t network)
{
   uint32_t controller;
   
   switch( network )
   {
        case C_NETWORK_ETSEC1 :
            controller = ETSEC1_ID;
            break;

        case C_NETWORK_ETSEC2 :
            controller = ETSEC2_ID;
            break;

        case C_NETWORK_ETSEC3 :
            controller = ETSEC3_ID;
            break;

        default:
            controller = ETSEC2_ID;
            break;
   }
 
   return (controller);
}
