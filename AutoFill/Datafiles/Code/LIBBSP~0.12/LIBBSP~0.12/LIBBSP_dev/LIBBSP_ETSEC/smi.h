#ifndef SMI_H
#define SMI_H

/*------------------------------------------------------------------------------*/
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : SMI                                                               */
/* FILENAME : smi.h                                                             */
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
 /* smi id                  */ 
 /* ----------------------- */
 #define    SMI_ETSEC_1     0   /* */
 #define    SMI_ETSEC_2     1   /* */
 #define    SMI_ETSEC_3     2   /* */
 
 /* ------------------------ */
 /* smi registers (PHY / TBI)*/ 
 /* ------------------------ */
 #define PHY_REG0_ADDR          0x00000000
 #define PHY_REG1_ADDR          0x00000001
 #define PHY_REG2_ADDR          0x00000002
 #define PHY_REG3_ADDR          0x00000003
 #define PHY_REG4_ADDR          0x00000004
 #define PHY_REG5_ADDR          0x00000005
 #define PHY_REG6_ADDR          0x00000006
 #define PHY_REG7_ADDR          0x00000007
 #define PHY_REG8_ADDR          0x00000008
 #define PHY_REG9_ADDR          0x00000009
 #define PHY_REG10_ADDR         0x0000000A
 #define PHY_REG11_ADDR         0x0000000B
 #define PHY_REG12_ADDR         0x0000000C
 #define PHY_REG13_ADDR         0x0000000D
 #define PHY_REG14_ADDR         0x0000000E
 #define PHY_REG15_ADDR         0x0000000F
 #define PHY_REG16_ADDR         0x00000010
 #define PHY_REG17_ADDR         0x00000011
 #define PHY_REG18_ADDR         0x00000012
 #define PHY_REG19_ADDR         0x00000013
 #define PHY_REG20_ADDR         0x00000014
 #define PHY_REG21_ADDR         0x00000015
 #define PHY_REG22_ADDR         0x00000016
 #define PHY_REG23_ADDR         0x00000017
 #define PHY_REG24_ADDR         0x00000018
 #define PHY_REG25_ADDR         0x00000019
 #define PHY_REG26_ADDR         0x0000001A
 #define PHY_REG27_ADDR         0x0000001B
 #define PHY_REG28_ADDR         0x0000001C
 #define PHY_REG29_ADDR         0x0000001D
 #define PHY_REG30_ADDR         0x0000001E
 #define PHY_REG31_ADDR         0x0000001F
 
 /* Generic MII registers. */

 #define MII_BMCR           0x00    /* Basic mode control register */
 #define MII_BMSR           0x01    /* Basic mode status register  */
 #define MII_PHYSID1        0x02    /* PHYS ID 1               */
 #define MII_PHYSID2        0x03    /* PHYS ID 2               */
 #define MII_ADVERTISE      0x04    /* Advertisement control reg   */
 #define MII_LPA            0x05    /* Link partner ability reg    */
 #define MII_EXPANSION      0x06    /* Expansion register          */
 #define MII_CTRL1000       0x09    /* 1000BASE-T control          */
 #define MII_STAT1000       0x0a    /* 1000BASE-T status           */
 #define MII_ESTATUS        0x0f    /* Extended Status */
 #define MII_DCOUNTER       0x12    /* Disconnect counter          */
 #define MII_FCSCOUNTER     0x13    /* False carrier counter       */
 #define MII_NWAYTEST       0x14    /* N-way auto-neg test reg     */
 #define MII_RERRCOUNTER    0x15    /* Receive error counter       */
 #define MII_PAGEADDR       0x16    /* Page address                */
 #define MII_RESV1          0x17    /* Reserved...             */
 #define MII_LBRERROR       0x18    /* Lpback, rx, bypass error    */
 #define MII_PHYADDR        0x19    /* PHY address             */
 #define MII_RESV2          0x1a    /* Reserved...             */
 #define MII_TPISTATUS      0x1b    /* TPI status for 10mbps       */
 #define MII_NCONFIG        0x1c    /* Network interface config    */

 #define TBI_CR         0x00
 #define TBI_SR         0x01
 #define TBI_ANA        0x04
 #define TBI_ANLPBPA    0x05
 #define TBI_ANEX       0x06
 #define TBI_CON        0x11

 /* Basic mode control register. */
 #define BMCR_RESV          0x003f  /* Unused...               */
 #define BMCR_SPEED1000     0x0040  /* MSB of Speed (1000)         */
 #define BMCR_CTST          0x0080  /* Collision test          */
 #define BMCR_FULLDPLX      0x0100  /* Full duplex             */
 #define BMCR_ANRESTART     0x0200  /* Auto negotiation restart    */
 #define BMCR_ISOLATE       0x0400  /* Disconnect DP83840 from MII */
 #define BMCR_PDOWN         0x0800  /* Powerdown the DP83840       */
 #define BMCR_ANENABLE      0x1000  /* Enable auto negotiation     */
 #define BMCR_SPEED100      0x2000  /* Select 100Mbps          */
 #define BMCR_LOOPBACK      0x4000  /* TXD loopback bits           */
 #define BMCR_RESET         0x8000  /* Reset the DP83840           */

 /* Basic mode status register. */
 #define BMSR_ERCAP         0x0001  /* Ext-reg capability          */
 #define BMSR_JCD           0x0002  /* Jabber detected         */
 #define BMSR_LSTATUS       0x0004  /* Link status             */
 #define BMSR_ANEGCAPABLE   0x0008  /* Able to do auto-negotiation */
 #define BMSR_RFAULT        0x0010  /* Remote fault detected       */
 #define BMSR_ANEGCOMPLETE  0x0020  /* Auto-negotiation complete   */
 #define BMSR_RESV          0x00c0  /* Unused...               */
 #define BMSR_ESTATEN       0x0100  /* Extended Status in R15 */
 #define BMSR_100HALF2      0x0200  /* Can do 100BASE-T2 HDX */
 #define BMSR_100FULL2      0x0400  /* Can do 100BASE-T2 FDX */
 #define BMSR_10HALF        0x0800  /* Can do 10mbps, half-duplex  */
 #define BMSR_10FULL        0x1000  /* Can do 10mbps, full-duplex  */
 #define BMSR_100HALF       0x2000  /* Can do 100mbps, half-duplex */
 #define BMSR_100FULL       0x4000  /* Can do 100mbps, full-duplex */
 #define BMSR_100BASE4      0x8000  /* Can do 100mbps, 4k packets  */

 /* Advertisement control register. */
 #define ADVERTISE_SLCT         0x001f  /* Selector bits           */
 #define ADVERTISE_CSMA         0x0001  /* Only selector supported     */
 #define ADVERTISE_10HALF       0x0020  /* Try for 10mbps half-duplex  */
 #define ADVERTISE_1000XFULL    0x0020  /* Try for 1000BASE-X full-duplex */
 #define ADVERTISE_10FULL       0x0040  /* Try for 10mbps full-duplex  */
 #define ADVERTISE_1000XHALF    0x0040  /* Try for 1000BASE-X half-duplex */
 #define ADVERTISE_100HALF      0x0080  /* Try for 100mbps half-duplex */
 #define ADVERTISE_1000XPAUSE   0x0080  /* Try for 1000BASE-X pause    */
 #define ADVERTISE_100FULL      0x0100  /* Try for 100mbps full-duplex */
 #define ADVERTISE_1000XPSE_ASYM 0x0100 /* Try for 1000BASE-X asym pause */
 #define ADVERTISE_100BASE4     0x0200  /* Try for 100mbps 4k packets  */
 #define ADVERTISE_PAUSE_CAP    0x0400  /* Try for pause           */
 #define ADVERTISE_PAUSE_ASYM   0x0800  /* Try for asymetric pause     */
 #define ADVERTISE_RESV         0x1000  /* Unused...               */
 #define ADVERTISE_RFAULT       0x2000  /* Say we can detect faults    */
 #define ADVERTISE_LPACK        0x4000  /* Ack link partners response  */
 #define ADVERTISE_NPAGE        0x8000  /* Next page bit           */

 #define ADVERTISE_FULL (ADVERTISE_100FULL | ADVERTISE_10FULL | \
             ADVERTISE_CSMA)
 #define ADVERTISE_ALL (ADVERTISE_10HALF | ADVERTISE_10FULL | \
                ADVERTISE_100HALF | ADVERTISE_100FULL)

 /* Link partner ability register. */
 #define LPA_SLCT           0x001f  /* Same as advertise selector  */
 #define LPA_10HALF         0x0020  /* Can do 10mbps half-duplex   */
 #define LPA_1000XFULL      0x0020  /* Can do 1000BASE-X full-duplex */
 #define LPA_10FULL         0x0040  /* Can do 10mbps full-duplex   */
 #define LPA_1000XHALF      0x0040  /* Can do 1000BASE-X half-duplex */
 #define LPA_100HALF        0x0080  /* Can do 100mbps half-duplex  */
 #define LPA_1000XPAUSE     0x0080  /* Can do 1000BASE-X pause     */
 #define LPA_100FULL        0x0100  /* Can do 100mbps full-duplex  */
 #define LPA_1000XPAUSE_ASYM    0x0100  /* Can do 1000BASE-X pause asym*/
 #define LPA_100BASE4       0x0200  /* Can do 100mbps 4k packets   */
 #define LPA_PAUSE_CAP      0x0400  /* Can pause               */
 #define LPA_PAUSE_ASYM     0x0800  /* Can pause asymetrically     */
 #define LPA_RESV           0x1000  /* Unused...               */
 #define LPA_RFAULT         0x2000  /* Link partner faulted        */
 #define LPA_LPACK          0x4000  /* Link partner acked us       */
 #define LPA_NPAGE          0x8000  /* Next page bit           */

 #define LPA_DUPLEX     (LPA_10FULL | LPA_100FULL)
 #define LPA_100            (LPA_100FULL | LPA_100HALF | LPA_100BASE4)

 /* Expansion register for auto-negotiation. */
 #define EXPANSION_NWAY         0x0001  /* Can do N-way auto-nego      */
 #define EXPANSION_LCWP         0x0002  /* Got new RX page code word   */
 #define EXPANSION_ENABLENPAGE  0x0004  /* This enables npage words    */
 #define EXPANSION_NPCAPABLE    0x0008  /* Link partner supports npage */
 #define EXPANSION_MFAULTS      0x0010  /* Multiple faults detected    */
 #define EXPANSION_RESV         0xffe0  /* Unused...               */

 #define ESTATUS_1000_TFULL 0x2000  /* Can do 1000BT Full */
 #define ESTATUS_1000_THALF 0x1000  /* Can do 1000BT Half */

 /* N-way test register. */
 #define NWAYTEST_RESV1     0x00ff  /* Unused...               */
 #define NWAYTEST_LOOPBACK  0x0100  /* Enable loopback for N-way   */
 #define NWAYTEST_RESV2     0xfe00  /* Unused...               */

 /* 1000BASE-T Control register */
 #define ADVERTISE_1000FULL     0x0200  /* Advertise 1000BASE-T full duplex */
 #define ADVERTISE_1000HALF     0x0100  /* Advertise 1000BASE-T half duplex */
 #define MIIM_CTRL1000_MS_VAL   0x0800  /* Master/Slave Configuration Value */
 #define MIIM_CTRL1000_MS_EN    0x1000  /* Master/Slave Configuration Enable */

 /* 1000BASE-T Status register */
 #define LPA_1000LOCALRXOK  0x2000  /* Link partner local receiver status */
 #define LPA_1000REMRXOK    0x1000  /* Link partner remote receiver status */
 #define LPA_1000FULL       0x0800  /* Link partner 1000BASE-T full duplex */
 #define LPA_1000HALF       0x0400  /* Link partner 1000BASE-T half duplex */

 /* Flow control flags */
 #define FLOW_CTRL_TX       0x01
 #define FLOW_CTRL_RX       0x02



 /* MIIMCFG register values */
 #define MIIMCFG_RESET                  0x80000000
 #define MIIMCFG_NOPRE                  0x00000010
 #define MIIMCFG_CLK_1_4                0x00000000
 #define MIIMCFG_CLK_1_6                0x00000002
 #define MIIMCFG_CLK_1_8                0x00000003
 #define MIIMCFG_CLK_1_10               0x00000004
 #define MIIMCFG_CLK_1_14               0x00000005
 #define MIIMCFG_CLK_1_20               0x00000006
 #define MIIMCFG_CLK_1_28               0x00000007
 
 #define MIIMCFG_CLK_DEF                0x00000005
 #define MIIMCFG_INIT                   MIIMCFG_CLK_1_14
  
 /* MIIMCOM register values */
 #define MIIMCOM_INIT                   0x00000000
 #define MIIMCOM_READ_CYCLE_EN          0x00000001
 
 /* MIIMCON register values */
 #define MIIMCON_SPEED_100MBPS          0x00002000 /* 100Mbps */
 #define MIIMCON_SPEED_1000MBPS         0x00000040 /* 1000Mbps */
 #define MIIMCON_FULL_DUPLEX            0x00000100 /* full duplex */
 #define MIIMCON_AUTO_NEG_EN            0x00001000 /* auto neg activation */
 #define MIIMCON_AUTO_NEG_RESTART       0x00000200 /* full duplex */
 #define MMIMCON_MODE_RGMII             0x00001000 /* mode RGMII */
 #define MMIMCON_MODE_SKEW              0x00000100 /* RGMII skew enable*/
 #define MMIMCON_MODE_LOOPBACK          0x00004000 /* mode loopback */
 #define MMIMCON_1000BT_EX_DIS          0x00000002 /* disable 1000 baseT automatic next page exchange */
 #define MMIMCON_PARA_DETECT            0x00000008 /* parammem detect control */
 
 /* MIIMIND register values */
 #define MIIMIND_NOT_VALID              0x00000004
 #define MIIMIND_SCAN_IN_PROGRESS       0x00000002
 #define MIIMIND_BUSY                   0x00000001
 
 /* ---------- provided types: ----------------------------------------------- */
/* MDIO registers definition */
 typedef struct
 {
    /* MDIO General Control and Status Registers */
    uint32_t volatile     Reserved000[0x4];      // OFFSET_x000 -> OFFSET_x0C
    uint32_t volatile     IEVENTM;               // OFFSET_x010
    uint32_t volatile     IMASKM;                // OFFSET_x014
    uint32_t volatile     Reserved001[0x1];      // OFFSET_x018 
    uint32_t volatile     EMAPM;                 // OFFSET_x01C 
    uint32_t volatile     Reserved002[0x140];    // OFFSET_x020 -> OFFSET_x51C
    uint32_t volatile     MIIMCFG;               // OFFSET_x520
    uint32_t volatile     MIIMCOM;               // OFFSET_x524
    uint32_t volatile     MIIMADD;               // OFFSET_x528
    uint32_t volatile     MIIMCON;               // OFFSET_x52C
    uint32_t volatile     MIIMSTAT;              // OFFSET_x530
    uint32_t volatile     MIIMIND;               // OFFSET_x534
 } TS_ETSEC_MDIO; 
 
 /* ---------- provided operations: ------------------------------------------ */
// extern void HW_CPU_SMI_link_init (uint32_t bus); 
// extern TS_ETSEC_MDIO* HW_CPU_SMI_get_base_address(uint32_t bus);
// extern void HW_CPU_SMI_write(uint32_t bus, uint32_t device_id, uint32_t mdio_reg, uint32_t mdio_value);
// extern void HW_CPU_SMI_wait_idle(uint32_t bus);
// extern uint16_t HW_CPU_SMI_read(uint32_t bus, uint32_t phy_id, uint32_t mdio_reg);

extern void  mii_reset     ( const uint32_t bus);
extern void  mii_phy_write ( const uint32_t bus, const uint32_t address, const uint32_t reg_number, int32_t value );
extern int32_t mii_phy_read  (const uint32_t bus, const uint32_t address, const uint32_t reg_number );


#endif /* SMI_H */
