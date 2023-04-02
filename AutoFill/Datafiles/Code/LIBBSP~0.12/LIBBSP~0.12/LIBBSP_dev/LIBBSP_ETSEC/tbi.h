#ifndef TBI_H
#define TBI_H

/*------------------------------------------------------------------------------*/
/* COMPANY : Sagem Defense Securite                                             */
/* CSU NAME : TBI                                                               */
/* FILENAME : tbi.h                                                             */
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
#define SMI_MASK_ADDR_TBI               ((uint32_t)0x80)   /* the purpose of this bit is to make difference    */
                                       /* between a PHY component and a TBI interface as   */
                                       /* the addresses on SMI link are on 5 bits (0 to 31) */
 
 
/* TBICON register values */ 
#define TBI_TBICON_ENABLE_CLOCK         ((uint32_t)0x00000020)   

/* TBI AN advertisement register */
#define TBI_TBIAN_ADV_SYM_PAUSE         ((uint32_t)0x00000100)   
#define TBI_TBIAN_ADV_ASYM_PAUSE        ((uint32_t)0x00000080)   
#define TBI_TBIAN_ADV_BOTH_PAUSE        (TBI_TBIAN_ADV_SYM_PAUSE | TBI_TBIAN_ADV_ASYM_PAUSE)  
#define TBI_TBIAN_ADV_HALF_DUPLEX       ((uint32_t)0x00000040)   
#define TBI_TBIAN_ADV_FULL_DUPLEX       ((uint32_t)0x00000020)   
#define TBI_TBIAN_SGMII_AUTONEG         ((uint32_t)0x00004001)
//#define TBI_TBIAN_ADV_INIT             (TBI_TBIAN_ADV_BOTH_PAUSE | TBI_TBIAN_ADV_FULL_DUPLEX)   

/* TBI Control register */
#define TBI_TBICR_1000MBIT_MAX_SPEED    ((uint32_t)0x00000040)
#define TBI_TBICR_AUTONEG_ENABLE        ((uint32_t)0x00001000)
#define TBI_TBICR_AUTONEG_RESET         ((uint32_t)0x00000200)
#define TBI_TBICR_FULL_DUPLEX           ((uint32_t)0x00000100)
  
/* ---------- provided types: ----------------------------------------------- */
/* none */
 
/* ---------- provided operations: ------------------------------------------ */
extern void tbi_config( const uint32_t device );

#endif /* TBI_H */
