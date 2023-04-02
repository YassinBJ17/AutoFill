/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

#ifndef ETH_INTEG_COMMON_H
#define ETH_INTEG_COMMON_H

/* ===================== IP Integration data ============== */
/*
 * ICDL_MSG_RX_MAX -> 6000
 */
#define INTEG_ETH_IP_SIZE_MAX_DATA_EXCHANGE (6UL*1024UL)

/* ===================== UDP Integration data ============== */
/* Number of simultaneous UDP reception ports / IP */
#define INTEG_ETH_UDP_OF_PORTS       (10ul)
/* Number of reception buffers per port */
#define INTEG_ETH_UDP_NB_IP_BY_PORT (2)

/* IP packet time to live  in secs */
#define INTEG_ETH_UDP_TIME_TO_LIVE        (64ul)


/* ===================== ARP Integration data ============== */
/* Number of simultaneous ARP reception ports */
#define INTEG_ETH_ARP_NUM_BUFFERS (2)

#define INTEG_ETH_ARP_MAX_ARP_ENTRIES (5ul)
/* 3 Seconds in nanoseconds */
#define INTEG_ETH_ARP_ARP_REQUEST_TIME_OUT (3UL*1000UL*1000UL*1000UL)
/* 1 Second in nanoseconds */
#define INTEG_ETH_ARP_ARP_REQUEST_TIME_BEFORE_RELAUNCH (1UL*1000UL*1000UL*1000UL)


/* ===================== ICMP Integration data ============== */

#endif /* ETH_INTEG_COMMON_H */
