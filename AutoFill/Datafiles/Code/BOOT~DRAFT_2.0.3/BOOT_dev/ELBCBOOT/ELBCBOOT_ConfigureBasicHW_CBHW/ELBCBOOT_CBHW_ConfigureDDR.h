#ifndef _ELBCBOOT_CBHW_CONFIGURE_DDR_
#define _ELBCBOOT_CBHW_CONFIGURE_DDR_

#include "LIBMCP_Types.h"
#include "LIBBSP_CCSR.h"

#define C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS            (uint32_t)(C_LIBBSP_CCSR_START + 0x2000ul)
#define C_ELBCBOOT_CCSR_DDR_CS0_BNDS_ADDRESS        (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0000ul)
#define C_ELBCBOOT_CCSR_DDR_CS0_CONFIG_ADDRESS      (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0080ul)
#define C_ELBCBOOT_CCSR_DDR_CS0_CONFIG_2_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x00C0ul)
#define C_ELBCBOOT_CCSR_DDR_TIMING_CFG_3_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0100ul)
#define C_ELBCBOOT_CCSR_DDR_TIMING_CFG_0_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0104ul)
#define C_ELBCBOOT_CCSR_DDR_TIMING_CFG_1_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0108ul)
#define C_ELBCBOOT_CCSR_DDR_TIMING_CFG_2_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x010Cul)
#define C_ELBCBOOT_CCSR_DDR_SDRAM_CFG_ADDRESS       (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0110ul)
#define C_ELBCBOOT_CCSR_DDR_SDRAM_CFG_2_ADDRESS     (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0114ul)
#define C_ELBCBOOT_CCSR_DDR_SDRAM_MODE_ADDRESS      (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0118ul)
#define C_ELBCBOOT_CCSR_DDR_SDRAM_MODE_2_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x011Cul)
#define C_ELBCBOOT_CCSR_DDR_SDRAM_INTERVAL_ADDRESS  (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0124ul)
#define C_ELBCBOOT_CCSR_DDR_DATA_INIT_ADDRESS       (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0128ul)
#define C_ELBCBOOT_CCSR_DDR_SDRAM_CLK_CNTL_ADDRESS  (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0130ul)
#define C_ELBCBOOT_CCSR_DDR_INIT_ADDR_ADDRESS       (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0148ul)
#define C_ELBCBOOT_CCSR_DDR_INIT_EXT_ADR_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x014Cul)
#define C_ELBCBOOT_CCSR_DDR_TIMING_CFG_4_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0160ul)
#define C_ELBCBOOT_CCSR_DDR_TIMING_CFG_5_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0164ul)
#define C_ELBCBOOT_CCSR_DDR_ZQ_CNTL_ADDRESS         (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0170ul)
#define C_ELBCBOOT_CCSR_DDR_WRLVL_CNTL_ADDRESS      (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0174ul)
#define C_ELBCBOOT_CCSR_DDR_WRLVL_CNTL_2_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0190ul)
#define C_ELBCBOOT_CCSR_DDR_WRLVL_CNTL_3_ADDRESS    (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0194ul)
#define C_ELBCBOOT_CCSR_DDR_SR_CNTR_ADDRESS         (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x017Cul)
#define C_ELBCBOOT_CCSR_DDR_CDR_1_ADDRESS           (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0B28ul)
#define C_ELBCBOOT_CCSR_DDR_CDR_2_ADDRESS           (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0B2Cul)
#define C_ELBCBOOT_CCSR_DDR_ERR_DISABLE_ADDRESS     (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0E44ul)
#define C_ELBCBOOT_CCSR_DDR_ERR_INT_EN_ADDRESS      (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0E48ul)
#define C_ELBCBOOT_CCSR_DDR_ERR_SBE_ADDRESS         (uint32_t)(C_ELBCBOOT_CCSR_DDR_BASE_ADDRESS + 0x0E58ul)

typedef struct
{
   uint32_t MEM_EN         :1;   /* DDR SDRAM interface logic enable */
   uint32_t SREN           :1;   /* Self refresh enable (during sleep) */
   uint32_t ECC_EN         :1;   /* ECC enable */
   uint32_t RD_EN          :1;   /* Registered DIMM enable */
   uint32_t                :1;
   uint32_t SDRAM_TYPE     :3;   /* Type of SDRAM device to be used */
   uint32_t                :2;
   uint32_t DYN_PWR        :1;   /* Dynamic power management mode */
   uint32_t DBW            :2;   /* DRAM data bus width */
   uint32_t EIGHT_BE       :1;   /* 8-beat burst enable */
   uint32_t                :1;
   uint32_t THREE_T_EN     :1;   /* Enable 3T timing */
   uint32_t TWO_T_EN       :1;   /* Enable 2T timing */
   uint32_t BA_INTLV_CTL   :7;   /* Bank (chip select) interleaving control */
   uint32_t                :2;
   uint32_t x32_EN         :1;   /* x32 enable */
   uint32_t PCHB8          :1;   /* Precharge bit 8 enable */
   uint32_t HSE            :1;   /* Global half-strength override */
   uint32_t                :1;
   uint32_t MEM_HALT       :1;   /* DDR memory controller halt */
   uint32_t BI             :1;   /* Bypass initialization */
} ts_DDR_SDRAM_CFG_Fields;

typedef struct
{
   uint32_t Addr;
   union
   {
      ts_DDR_SDRAM_CFG_Fields Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SDRAM_CFG;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t       :4;
         uint32_t SAn   :12;  /* Starting address */
         uint32_t       :4;
         uint32_t EAn   :12;  /* Ending address */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_CSn_BNDS;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t CS_n_EN        :1;   /* Enable */
         uint32_t                :7;
         uint32_t AP_n_EN        :1;   /* Auto-precharge enable */
         uint32_t ODT_RD_CFG     :3;   /* ODT for reads configuration */
         uint32_t                :1;
         uint32_t ODT_WR_CFG     :3;   /* ODT for writes configuration. */
         uint32_t BA_BITS_CS_n   :2;   /* Number of bank bits for SDRAM */
         uint32_t                :3;
         uint32_t ROW_BITS_CS_n  :3;   /* Number of row bits for SDRAM */
         uint32_t                :5;
         uint32_t COL_BITS_CS_n  :3;   /* Number of column bits for SDRAM */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_CSn_CONFIG;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t          :5;
         uint32_t PASR_CFG :3; /* Partial array self refresh config */
         uint32_t          :24;
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_CSn_CONFIG_2;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t                :7;
         uint32_t EXT_ACTTOPRE   :1;   /* Extended Activate to precharge interval (t RAS ) */
         uint32_t                :4;
         uint32_t EXT_REFREC     :4;   /* Extended refresh recovery time (t RFC ) */
         uint32_t                :3;
         uint32_t EXT_CASLAT     :1;   /* Extended MCAS latency from READ command */
         uint32_t                :9;
         uint32_t CNTL_ADJ       :3;   /* Control Adjust */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_TIMING_CFG_3;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t RWT         :2;   /* Read-to-write turnaround (tRTW ) */
         uint32_t WRT         :2;   /* Write-to-read turnaround */
         uint32_t RRT         :2;   /* Read-to-read turnaround */
         uint32_t WWT         :2;   /* Write-to-write turnaround */
         uint32_t             :1;
         uint32_t ACT_PD_EXIT :3;   /* Active powerdown exit timing ( DDR2: t XARD and t XARDS and DDR3 : t XP ) */
         uint32_t PRE_PD_EXIT :4;   /* Precharge powerdown exit timing (t XP ) */
         uint32_t             :4;
         uint32_t ODT_PD_EXIT :4;   /* ODT powerdown exit timing ( DDR2: t AXPD , DDR3 : set to 1) */
         uint32_t             :4;
         uint32_t MRS_CYC     :4;   /* Mode register set cycle time (t MRD ) */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_TIMING_CFG_0;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t PRETOACT :4;   /* Precharge-to-activate interval (t RP ) */
         uint32_t ACTTOPRE :4;   /* Activate to precharge interval (t RAS ) */
         uint32_t ACTTORW  :4;   /* Activate to read/write interval for SDRAM (t RCD ) */
         uint32_t CASLAT   :4;   /* MCAS latency from READ command */
         uint32_t REFREC   :4;   /* Refresh recovery time (t RFC ) */
         uint32_t WRREC    :4;   /* Last data to precharge minimum interval (t WR ) */
         uint32_t          :1;
         uint32_t ACTTOACT :3;   /* Activate-to-activate interval (t RRD ) */
         uint32_t          :1;
         uint32_t WRTORD   :3;   /* Last write data pair to read command issue interval (t WTR ) */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_TIMING_CFG_1;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t ADD_LAT        :4;   /* Additive latency */
         uint32_t CPO            :5;   /* MCAS -to-preamble override */
         uint32_t WR_LAT         :4;   /* Write latency */
         uint32_t                :3;
         uint32_t RD_TO_PRE      :3;   /* Read to precharge (t RTP ) */
         uint32_t WR_DATA_DELAY  :3;   /* Write command to write data strobe timing adjustment */
         uint32_t                :1;
         uint32_t CKE_PLS        :3;   /* Minimum CKE pulse width (t CKE ) */
         uint32_t FOUR_ACT       :6;   /* Window for four activates (t FAW ) */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_TIMING_CFG_2;
   
typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t FRC_SR      :1;   /* Force self-refresh */
         uint32_t SR_IE       :1;   /* Self-refresh interrupt enable */
         uint32_t DLL_RST_DIS :1;   /* DLL reset disable */
         uint32_t             :1;
         uint32_t DQS_CFG     :2;   /* DQS configuration */
         uint32_t             :3;
         uint32_t ODT_CFG     :2;   /* ODT configuration */
         uint32_t             :5;
         uint32_t NUM_PR      :4;   /* Number of posted refreshes */
         uint32_t             :5;
         uint32_t             :1;
         uint32_t AP_EN       :1;   /* Address Parity Enable */
         uint32_t D_INIT      :1;   /* DRAM data initialization */
         uint32_t             :1;
         uint32_t RCW_EN      :1;   /* Register Control Word Enable */
         uint32_t             :1;
         uint32_t MD_EN       :1;   /* Mirrored DIMM Enable */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SDRAM_CFG_2;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t ESDMODE  :16;  /* Extended SDRAM mode */
         uint32_t SDMODE   :16;  /* SDRAM mode */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SDRAM_MODE;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t ESDMODE2 :16;  /* Extended SDRAM mode 2 */
         uint32_t ESDMODE3 :16;  /* Extended SDRAM mode 3*/
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SDRAM_MODE_2;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t REFINT   :16;  /* Refresh interval */
         uint32_t          :2;
         uint32_t BSTOPRE  :14;  /* Precharge interval */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SDRAM_INTERVAL;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t INIT_VALUE  :32;  /* Initialization value */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_DATA_INIT;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t             :5;
         uint32_t CLK_ADJUST  :4;   /* Clock adjust */
         uint32_t             :23;
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SDRAM_CLK_CNTL;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t INIT_ADDR   :32;  /* Initialization address */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_INIT_ADDR;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t UIA            :1;   /* Use initialization address */
         uint32_t                :27;
         uint32_t INIT_EXT_ADDR  :4;   /* Initialization extended address */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_INIT_EXT_ADR;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t RWT      :4;   /* Read-to-write turnaround for same chip select */
         uint32_t WRT      :4;   /* Write-to-read turnaround for same chip select */
         uint32_t RRT      :4;   /* Read-to-read turnaround for same chip select */
         uint32_t WWT      :4;   /* Write-to-write turnaround for same chip select */
         uint32_t          :14;
         uint32_t DLL_LOCK :2;   /* DDR SDRAM DLL Lock Time */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_TIMING_CFG_4;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t          :3;
         uint32_t RODT_ON  :5;   /* Read to ODT on */
         uint32_t          :1;
         uint32_t RODT_OFF :3;   /* Read to ODT off */
         uint32_t          :3;
         uint32_t WODT_ON  :5;   /* Write to ODT On */
         uint32_t          :1;
         uint32_t WODT_OFF :3;   /* Write to ODT Off */
         uint32_t          :8;
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_TIMING_CFG_5;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t ZQ_EN    :1;   /* ZQ Calibration Enable */
         uint32_t          :3;
         uint32_t ZQINIT   :4;   /* POR ZQ Calibration Time (t ZQinit ) */
         uint32_t          :4;
         uint32_t ZQOPER   :4;   /* Normal Operation Full Calibration Time (t ZQoper ) */
         uint32_t          :4;
         uint32_t ZQCS     :4;   /* Normal Operation Short Calibration Time (t ZQCS ) */
         uint32_t          :8;
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_ZQ_CNTL;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t WRLVL_EN    :1;   /* Write Leveling Enable */
         uint32_t             :4;
         uint32_t WRLVL_MRD   :3;   /* First DQS pulse rising edge after margining mode is programmed (t WL_MRD ) */
         uint32_t             :1;
         uint32_t WRLVL_ODTEN :3;   /* ODT delay after margining mode is programmed (t WL_ODTEN ) */
         uint32_t             :1;
         uint32_t WRLVL_DQSEN :3;   /* DQS/ DQS delay after margining mode is programmed (t WL_DQSEN ) */
         uint32_t WRLVL_SMPL  :4;   /* Write leveling sample time */
         uint32_t             :1;
         uint32_t WRLVL_WLR   :3;   /* Write leveling repetition time */
         uint32_t             :4;
         uint32_t WRLVL_START :4;   /* Write leveling start time */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_WRLVL_CNTL;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t                :3;
         uint32_t WRLVL_START_1  :5;   /* Write leveling start time for DQS[1] */
         uint32_t                :3;
         uint32_t WRLVL_START_2  :5;   /* Write leveling start time for DQS[2] */
         uint32_t                :3;
         uint32_t WRLVL_START_3  :5;   /* Write leveling start time for DQS[3] */
         uint32_t                :3;
         uint32_t WRLVL_START_4  :5;   /* Write leveling start time for DQS[4] */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_WRLVL_CNTL_2;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t                :3;
         uint32_t WRLVL_START_5  :5;   /* Write leveling start time for DQS[5] */
         uint32_t                :3;
         uint32_t WRLVL_START_6  :5;   /* Write leveling start time for DQS[6] */
         uint32_t                :3;
         uint32_t WRLVL_START_7  :5;   /* Write leveling start time for DQS[7] */
         uint32_t                :3;
         uint32_t WRLVL_START_8  :5;   /* Write leveling start time for DQS[8] */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_WRLVL_CNTL_3;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t       :12;
         uint32_t SR_IT :4;   /* Self Refresh Idle Threshold */
         uint32_t       :16;
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_SR_CNTR;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t DHC_EN         :1;   /* DDR driver hardware compensation enable */
         uint32_t DSO_MDIC_EN    :1;   /* Driver software override enable for MDIC */
         uint32_t DSO_MDICPZ     :4;   /* DDR driver software MDIC p-impedance override */
         uint32_t DSO_MDICNZ     :4;   /* DDR driver software MDIC n-impedance override */
         uint32_t DSO_MDIC_PZ_OE :1;   /* Driver software override p-impedance output enable */
         uint32_t DSO_MDIC_NZ_OE :1;   /* Driver software override n-impedance output enable */
         uint32_t ODT            :2;   /* ODT termination value for IOs */
         uint32_t DSO_C_EN       :1;   /* Driver software override enable for address/command */
         uint32_t DSO_D_EN       :1;   /* Driver software override enable for data */
         uint32_t DSO_CPZ        :4;   /* DDR driver software command p-impedance override */
         uint32_t DSO_CNZ        :4;   /* DDR driver software command n-impedance override */
         uint32_t DSO_DPZ        :4;   /* Driver software data p-impedance override */
         uint32_t DSO_DNZ        :4;   /* Driver software data n-impedance override */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_CDR_1;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t DSO_CLK_EN  :1;   /* Driver software override enable for clocks */
         uint32_t             :3;
         uint32_t DSO_CLKPZ   :4;   /* Driver software clocks p-impedance override */
         uint32_t DSO_CLKNZ   :4;   /* Driver software clocks n-impedance override */
         uint32_t             :19;
         uint32_t ODT         :1;   /* ODT termination value for IOs */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_CDR_2;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
   {
      uint32_t       :23;
      uint32_t APED  :1;   /* Address parity error disable */
      uint32_t ACED  :1;   /* Automatic calibration error disable */
      uint32_t       :3;
      uint32_t MBED  :1;   /* Multiple-bit ECC error disable */
      uint32_t SBED  :1;   /* Single-bit ECC error disable */
      uint32_t       :1;
      uint32_t MSED  :1;   /* Memory select error disable */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_ERR_DISABLE;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t       :23;
         uint32_t APEE  :1;   /* Address parity interrupt disable */
         uint32_t ACEE  :1;   /* Automatic calibration interrupt disable */
         uint32_t       :3;
         uint32_t MBEE  :1;   /* Multiple-bit ECC interrupt disable */
         uint32_t SBEE  :1;   /* Single-bit ECC interrupt disable */
         uint32_t       :1;
         uint32_t MSEE  :1;   /* Memory select interrupt disable */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_ERR_INT_EN;

typedef struct
{
   uint32_t Addr;
   union
   {
      struct
      {
         uint32_t       :8;
         uint32_t SBET  :8;   /* Single-bit error threshold */
         uint32_t       :8;
         uint32_t SBEC  :8;   /* Single-bit error counter */
      } Fields;
      uint32_t Value;
   } Register;
} ts_DDR_ERR_SBE;

typedef struct
{
   ts_DDR_SDRAM_CFG DDR_SDRAM_CFG;
   ts_DDR_CSn_BNDS DDR_CS0_BNDS;
   ts_DDR_CSn_CONFIG DDR_CS0_CONFIG;
   ts_DDR_CSn_CONFIG_2 DDR_CS0_CONFIG_2;
   ts_DDR_TIMING_CFG_3 DDR_TIMING_CFG_3;
   ts_DDR_TIMING_CFG_0 DDR_TIMING_CFG_0;
   ts_DDR_TIMING_CFG_1 DDR_TIMING_CFG_1;
   ts_DDR_TIMING_CFG_2 DDR_TIMING_CFG_2;
   ts_DDR_SDRAM_CFG_2 DDR_SDRAM_CFG_2;
   ts_DDR_SDRAM_MODE DDR_SDRAM_MODE;
   ts_DDR_SDRAM_MODE_2 DDR_SDRAM_MODE_2;
   ts_DDR_SDRAM_INTERVAL DDR_SDRAM_INTERVAL;
   ts_DDR_DATA_INIT DDR_DATA_INIT;
   ts_DDR_SDRAM_CLK_CNTL DDR_SDRAM_CLK_CNTL;
   ts_DDR_INIT_ADDR DDR_INIT_ADDR;
   ts_DDR_INIT_EXT_ADR DDR_INIT_EXT_ADR;
   ts_DDR_TIMING_CFG_4 DDR_TIMING_CFG_4;
   ts_DDR_TIMING_CFG_5 DDR_TIMING_CFG_5;
   ts_DDR_ZQ_CNTL DDR_ZQ_CNTL;
   ts_DDR_WRLVL_CNTL DDR_WRLVL_CNTL;
   ts_DDR_WRLVL_CNTL_2 DDR_WRLVL_CNTL_2;
   ts_DDR_WRLVL_CNTL_3 DDR_WRLVL_CNTL_3;
   ts_DDR_SR_CNTR DDR_SR_CNTR;
   ts_DDR_CDR_1 DDR_CDR_1;
   ts_DDR_CDR_2 DDR_CDR_2;
   ts_DDR_ERR_DISABLE DDR_ERR_DISABLE;
   ts_DDR_ERR_INT_EN DDR_ERR_INT_EN;
   ts_DDR_ERR_SBE DDR_ERR_SBE;
} ts_DDR_Registers;

typedef union
{
   ts_DDR_Registers Registers;
   struct
   {
      uint32_t Addr;
      uint32_t Value;
   } Register[sizeof(ts_DDR_Registers)/sizeof(ts_DDR_CSn_BNDS)];
}  tu_DDR_Config;

void ELBCBOOT_CBHW_ConfigureDDR(void);

#endif