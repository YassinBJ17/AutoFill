/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/

/*==== Definitions =====================================================================*/
#ifndef LIBBSP_A429_H
#define LIBBSP_A429_H

#include "LIBMCP_Types.h"
#include "kcg_types.h"

#define C_A429_FIFO_ROLLOVER_COEFF 64ul


#define C_A429_TX_UNUSED_SIZE 2
#define C_A429_TX_USED_SIZE 5
#define C_A429_RX_UNUSED0_SIZE 502
#define C_A429_RX_USED_SIZE 512
#define C_A429_NB_RX_BUFF 2

#define TX_CONTROLLERS_COUNT 8ul //new PLD
#define RX_CONTROLLERS_COUNT 9ul //new PLD
#define A429_DEVICES_COUNT TX_CONTROLLERS_COUNT+RX_CONTROLLERS_COUNT


#define C_A429_MEGATICE_BLOCK_SIZE 1024
#define C_A429_RX_BUFFER_SIZE 64

#define C_A429_FILTER_TABLE_SIZE 8

/*#define rxID(dev) (dev - TX_CONTROLLERS_COUNT)*/
/*==== Types ===========================================================================*/

/* {{RELAX<NO.006_a> Justification can be found in Checklist SK-0000446696-01#R_3 */
typedef enum
{
    E_LIBBSP_A429_LABEL_0 = 00,
    E_LIBBSP_A429_LABEL_1 = 01,
    E_LIBBSP_A429_LABEL_2 = 02,
    E_LIBBSP_A429_LABEL_3 = 03,
    E_LIBBSP_A429_LABEL_4 = 04,
    E_LIBBSP_A429_LABEL_5 = 05,
    E_LIBBSP_A429_LABEL_6 = 06,
    E_LIBBSP_A429_LABEL_7 = 07,
    E_LIBBSP_A429_LABEL_10 = 010,
    E_LIBBSP_A429_LABEL_11 = 011,
    E_LIBBSP_A429_LABEL_12 = 012,
    E_LIBBSP_A429_LABEL_13 = 013,
    E_LIBBSP_A429_LABEL_14 = 014,
    E_LIBBSP_A429_LABEL_15 = 015,
    E_LIBBSP_A429_LABEL_16 = 016,
    E_LIBBSP_A429_LABEL_17 = 017,
    E_LIBBSP_A429_LABEL_20 = 020,
    E_LIBBSP_A429_LABEL_21 = 021,
    E_LIBBSP_A429_LABEL_22 = 022,
    E_LIBBSP_A429_LABEL_23 = 023,
    E_LIBBSP_A429_LABEL_24 = 024,
    E_LIBBSP_A429_LABEL_25 = 025,
    E_LIBBSP_A429_LABEL_26 = 026,
    E_LIBBSP_A429_LABEL_27 = 027,
    E_LIBBSP_A429_LABEL_30 = 030,
    E_LIBBSP_A429_LABEL_31 = 031,
    E_LIBBSP_A429_LABEL_32 = 032,
    E_LIBBSP_A429_LABEL_33 = 033,
    E_LIBBSP_A429_LABEL_34 = 034,
    E_LIBBSP_A429_LABEL_35 = 035,
    E_LIBBSP_A429_LABEL_36 = 036,
    E_LIBBSP_A429_LABEL_37 = 037,
    E_LIBBSP_A429_LABEL_40 = 040,
    E_LIBBSP_A429_LABEL_41 = 041,
    E_LIBBSP_A429_LABEL_42 = 042,
    E_LIBBSP_A429_LABEL_43 = 043,
    E_LIBBSP_A429_LABEL_44 = 044,
    E_LIBBSP_A429_LABEL_45 = 045,
    E_LIBBSP_A429_LABEL_46 = 046,
    E_LIBBSP_A429_LABEL_47 = 047,
    E_LIBBSP_A429_LABEL_50 = 050,
    E_LIBBSP_A429_LABEL_51 = 051,
    E_LIBBSP_A429_LABEL_52 = 052,
    E_LIBBSP_A429_LABEL_53 = 053,
    E_LIBBSP_A429_LABEL_54 = 054,
    E_LIBBSP_A429_LABEL_55 = 055,
    E_LIBBSP_A429_LABEL_56 = 056,
    E_LIBBSP_A429_LABEL_57 = 057,
    E_LIBBSP_A429_LABEL_60 = 060,
    E_LIBBSP_A429_LABEL_61 = 061,
    E_LIBBSP_A429_LABEL_62 = 062,
    E_LIBBSP_A429_LABEL_63 = 063,
    E_LIBBSP_A429_LABEL_64 = 064,
    E_LIBBSP_A429_LABEL_65 = 065,
    E_LIBBSP_A429_LABEL_66 = 066,
    E_LIBBSP_A429_LABEL_67 = 067,
    E_LIBBSP_A429_LABEL_70 = 070,
    E_LIBBSP_A429_LABEL_71 = 071,
    E_LIBBSP_A429_LABEL_72 = 072,
    E_LIBBSP_A429_LABEL_73 = 073,
    E_LIBBSP_A429_LABEL_74 = 074,
    E_LIBBSP_A429_LABEL_75 = 075,
    E_LIBBSP_A429_LABEL_76 = 076,
    E_LIBBSP_A429_LABEL_77 = 077,
    E_LIBBSP_A429_LABEL_100 = 0100,
    E_LIBBSP_A429_LABEL_101 = 0101,
    E_LIBBSP_A429_LABEL_102 = 0102,
    E_LIBBSP_A429_LABEL_103 = 0103,
    E_LIBBSP_A429_LABEL_104 = 0104,
    E_LIBBSP_A429_LABEL_105 = 0105,
    E_LIBBSP_A429_LABEL_106 = 0106,
    E_LIBBSP_A429_LABEL_107 = 0107,
    E_LIBBSP_A429_LABEL_110 = 0110,
    E_LIBBSP_A429_LABEL_111 = 0111,
    E_LIBBSP_A429_LABEL_112 = 0112,
    E_LIBBSP_A429_LABEL_113 = 0113,
    E_LIBBSP_A429_LABEL_114 = 0114,
    E_LIBBSP_A429_LABEL_115 = 0115,
    E_LIBBSP_A429_LABEL_116 = 0116,
    E_LIBBSP_A429_LABEL_117 = 0117,
    E_LIBBSP_A429_LABEL_120 = 0120,
    E_LIBBSP_A429_LABEL_121 = 0121,
    E_LIBBSP_A429_LABEL_122 = 0122,
    E_LIBBSP_A429_LABEL_123 = 0123,
    E_LIBBSP_A429_LABEL_124 = 0124,
    E_LIBBSP_A429_LABEL_125 = 0125,
    E_LIBBSP_A429_LABEL_126 = 0126,
    E_LIBBSP_A429_LABEL_127 = 0127,
    E_LIBBSP_A429_LABEL_130 = 0130,
    E_LIBBSP_A429_LABEL_131 = 0131,
    E_LIBBSP_A429_LABEL_132 = 0132,
    E_LIBBSP_A429_LABEL_133 = 0133,
    E_LIBBSP_A429_LABEL_134 = 0134,
    E_LIBBSP_A429_LABEL_135 = 0135,
    E_LIBBSP_A429_LABEL_136 = 0136,
    E_LIBBSP_A429_LABEL_137 = 0137,
    E_LIBBSP_A429_LABEL_140 = 0140,
    E_LIBBSP_A429_LABEL_141 = 0141,
    E_LIBBSP_A429_LABEL_142 = 0142,
    E_LIBBSP_A429_LABEL_143 = 0143,
    E_LIBBSP_A429_LABEL_144 = 0144,
    E_LIBBSP_A429_LABEL_145 = 0145,
    E_LIBBSP_A429_LABEL_146 = 0146,
    E_LIBBSP_A429_LABEL_147 = 0147,
    E_LIBBSP_A429_LABEL_150 = 0150,
    E_LIBBSP_A429_LABEL_151 = 0151,
    E_LIBBSP_A429_LABEL_152 = 0152,
    E_LIBBSP_A429_LABEL_153 = 0153,
    E_LIBBSP_A429_LABEL_154 = 0154,
    E_LIBBSP_A429_LABEL_155 = 0155,
    E_LIBBSP_A429_LABEL_156 = 0156,
    E_LIBBSP_A429_LABEL_157 = 0157,
    E_LIBBSP_A429_LABEL_160 = 0160,
    E_LIBBSP_A429_LABEL_161 = 0161,
    E_LIBBSP_A429_LABEL_162 = 0162,
    E_LIBBSP_A429_LABEL_163 = 0163,
    E_LIBBSP_A429_LABEL_164 = 0164,
    E_LIBBSP_A429_LABEL_165 = 0165,
    E_LIBBSP_A429_LABEL_166 = 0166,
    E_LIBBSP_A429_LABEL_167 = 0167,
    E_LIBBSP_A429_LABEL_170 = 0170,
    E_LIBBSP_A429_LABEL_171 = 0171,
    E_LIBBSP_A429_LABEL_172 = 0172,
    E_LIBBSP_A429_LABEL_173 = 0173,
    E_LIBBSP_A429_LABEL_174 = 0174,
    E_LIBBSP_A429_LABEL_175 = 0175,
    E_LIBBSP_A429_LABEL_176 = 0176,
    E_LIBBSP_A429_LABEL_177 = 0177,
    E_LIBBSP_A429_LABEL_200 = 0200,
    E_LIBBSP_A429_LABEL_201 = 0201,
    E_LIBBSP_A429_LABEL_202 = 0202,
    E_LIBBSP_A429_LABEL_203 = 0203,
    E_LIBBSP_A429_LABEL_204 = 0204,
    E_LIBBSP_A429_LABEL_205 = 0205,
    E_LIBBSP_A429_LABEL_206 = 0206,
    E_LIBBSP_A429_LABEL_207 = 0207,
    E_LIBBSP_A429_LABEL_210 = 0210,
    E_LIBBSP_A429_LABEL_211 = 0211,
    E_LIBBSP_A429_LABEL_212 = 0212,
    E_LIBBSP_A429_LABEL_213 = 0213,
    E_LIBBSP_A429_LABEL_214 = 0214,
    E_LIBBSP_A429_LABEL_215 = 0215,
    E_LIBBSP_A429_LABEL_216 = 0216,
    E_LIBBSP_A429_LABEL_217 = 0217,
    E_LIBBSP_A429_LABEL_220 = 0220,
    E_LIBBSP_A429_LABEL_221 = 0221,
    E_LIBBSP_A429_LABEL_222 = 0222,
    E_LIBBSP_A429_LABEL_223 = 0223,
    E_LIBBSP_A429_LABEL_224 = 0224,
    E_LIBBSP_A429_LABEL_225 = 0225,
    E_LIBBSP_A429_LABEL_226 = 0226,
    E_LIBBSP_A429_LABEL_227 = 0227,
    E_LIBBSP_A429_LABEL_230 = 0230,
    E_LIBBSP_A429_LABEL_231 = 0231,
    E_LIBBSP_A429_LABEL_232 = 0232,
    E_LIBBSP_A429_LABEL_233 = 0233,
    E_LIBBSP_A429_LABEL_234 = 0234,
    E_LIBBSP_A429_LABEL_235 = 0235,
    E_LIBBSP_A429_LABEL_236 = 0236,
    E_LIBBSP_A429_LABEL_237 = 0237,
    E_LIBBSP_A429_LABEL_240 = 0240,
    E_LIBBSP_A429_LABEL_241 = 0241,
    E_LIBBSP_A429_LABEL_242 = 0242,
    E_LIBBSP_A429_LABEL_243 = 0243,
    E_LIBBSP_A429_LABEL_244 = 0244,
    E_LIBBSP_A429_LABEL_245 = 0245,
    E_LIBBSP_A429_LABEL_246 = 0246,
    E_LIBBSP_A429_LABEL_247 = 0247,
    E_LIBBSP_A429_LABEL_250 = 0250,
    E_LIBBSP_A429_LABEL_251 = 0251,
    E_LIBBSP_A429_LABEL_252 = 0252,
    E_LIBBSP_A429_LABEL_253 = 0253,
    E_LIBBSP_A429_LABEL_254 = 0254,
    E_LIBBSP_A429_LABEL_255 = 0255,
    E_LIBBSP_A429_LABEL_256 = 0256,
    E_LIBBSP_A429_LABEL_257 = 0257,
    E_LIBBSP_A429_LABEL_260 = 0260,
    E_LIBBSP_A429_LABEL_261 = 0261,
    E_LIBBSP_A429_LABEL_262 = 0262,
    E_LIBBSP_A429_LABEL_263 = 0263,
    E_LIBBSP_A429_LABEL_264 = 0264,
    E_LIBBSP_A429_LABEL_265 = 0265,
    E_LIBBSP_A429_LABEL_266 = 0266,
    E_LIBBSP_A429_LABEL_267 = 0267,
    E_LIBBSP_A429_LABEL_270 = 0270,
    E_LIBBSP_A429_LABEL_271 = 0271,
    E_LIBBSP_A429_LABEL_272 = 0272,
    E_LIBBSP_A429_LABEL_273 = 0273,
    E_LIBBSP_A429_LABEL_274 = 0274,
    E_LIBBSP_A429_LABEL_275 = 0275,
    E_LIBBSP_A429_LABEL_276 = 0276,
    E_LIBBSP_A429_LABEL_277 = 0277,
    E_LIBBSP_A429_LABEL_300 = 0300,
    E_LIBBSP_A429_LABEL_301 = 0301,
    E_LIBBSP_A429_LABEL_302 = 0302,
    E_LIBBSP_A429_LABEL_303 = 0303,
    E_LIBBSP_A429_LABEL_304 = 0304,
    E_LIBBSP_A429_LABEL_305 = 0305,
    E_LIBBSP_A429_LABEL_306 = 0306,
    E_LIBBSP_A429_LABEL_307 = 0307,
    E_LIBBSP_A429_LABEL_310 = 0310,
    E_LIBBSP_A429_LABEL_311 = 0311,
    E_LIBBSP_A429_LABEL_312 = 0312,
    E_LIBBSP_A429_LABEL_313 = 0313,
    E_LIBBSP_A429_LABEL_314 = 0314,
    E_LIBBSP_A429_LABEL_315 = 0315,
    E_LIBBSP_A429_LABEL_316 = 0316,
    E_LIBBSP_A429_LABEL_317 = 0317,
    E_LIBBSP_A429_LABEL_320 = 0320,
    E_LIBBSP_A429_LABEL_321 = 0321,
    E_LIBBSP_A429_LABEL_322 = 0322,
    E_LIBBSP_A429_LABEL_323 = 0323,
    E_LIBBSP_A429_LABEL_324 = 0324,
    E_LIBBSP_A429_LABEL_325 = 0325,
    E_LIBBSP_A429_LABEL_326 = 0326,
    E_LIBBSP_A429_LABEL_327 = 0327,
    E_LIBBSP_A429_LABEL_330 = 0330,
    E_LIBBSP_A429_LABEL_331 = 0331,
    E_LIBBSP_A429_LABEL_332 = 0332,
    E_LIBBSP_A429_LABEL_333 = 0333,
    E_LIBBSP_A429_LABEL_334 = 0334,
    E_LIBBSP_A429_LABEL_335 = 0335,
    E_LIBBSP_A429_LABEL_336 = 0336,
    E_LIBBSP_A429_LABEL_337 = 0337,
    E_LIBBSP_A429_LABEL_340 = 0340,
    E_LIBBSP_A429_LABEL_341 = 0341,
    E_LIBBSP_A429_LABEL_342 = 0342,
    E_LIBBSP_A429_LABEL_343 = 0343,
    E_LIBBSP_A429_LABEL_344 = 0344,
    E_LIBBSP_A429_LABEL_345 = 0345,
    E_LIBBSP_A429_LABEL_346 = 0346,
    E_LIBBSP_A429_LABEL_347 = 0347,
    E_LIBBSP_A429_LABEL_350 = 0350,
    E_LIBBSP_A429_LABEL_351 = 0351,
    E_LIBBSP_A429_LABEL_352 = 0352,
    E_LIBBSP_A429_LABEL_353 = 0353,
    E_LIBBSP_A429_LABEL_354 = 0354,
    E_LIBBSP_A429_LABEL_355 = 0355,
    E_LIBBSP_A429_LABEL_356 = 0356,
    E_LIBBSP_A429_LABEL_357 = 0357,
    E_LIBBSP_A429_LABEL_360 = 0360,
    E_LIBBSP_A429_LABEL_361 = 0361,
    E_LIBBSP_A429_LABEL_362 = 0362,
    E_LIBBSP_A429_LABEL_363 = 0363,
    E_LIBBSP_A429_LABEL_364 = 0364,
    E_LIBBSP_A429_LABEL_365 = 0365,
    E_LIBBSP_A429_LABEL_366 = 0366,
    E_LIBBSP_A429_LABEL_367 = 0367,
    E_LIBBSP_A429_LABEL_370 = 0370,
    E_LIBBSP_A429_LABEL_371 = 0371,
    E_LIBBSP_A429_LABEL_372 = 0372,
    E_LIBBSP_A429_LABEL_373 = 0373,
    E_LIBBSP_A429_LABEL_374 = 0374,
    E_LIBBSP_A429_LABEL_375 = 0375,
    E_LIBBSP_A429_LABEL_376 = 0376,
    E_LIBBSP_A429_LABEL_377 = 0377,
    E_LIBBSP_A429_LABEL_KO = 0400
} TE_LIBBSP_A429_LabelNumber;
/* }}RELAX< NO.006_a > Justification can be found in Checklist SK-0000446696-01#R_3 */


typedef enum {
    E_LIBBSP_A429_VALID_ADDR  = 0,
    E_LIBBSP_A429_INVALID_ADDR= 1
} TE_LIBBSP_A429_AddrStatus;


/*typedef enum {
    E_LIBBSP_A429_RX_OK                   = 0,
    E_LIBBSP_A429_RX_INVALID_ID           = 1,
    E_LIBBSP_A429_RX_ROLLOVER          = 2,
    E_LIBBSP_A429_RX_PARITY_ERROR      = 3,
    E_LIBBSP_A429_RX_GAP_ERROR         = 4,
    E_LIBBSP_A429_RX_FORMAT_ERROR      = 5,
    E_LIBBSP_A429_RX_TOO_MANY_LABELS   = 6,
	E_LIBBSP_A429_RX_INCONSISTENT_ROLLOVER = 7,
    E_LIBBSP_A429_POST_KO              = 8
} TE_LIBBSP_A429_RxErrorCode;*/


/*FUTUR PLD*/
/* Devices according GANAV board and Megatice */
// typedef enum {
    // E_LIBBSP_A429_RX_1 = 0,
    // E_LIBBSP_A429_RX_2 = 1,
    // E_LIBBSP_A429_RX_3 = 2,
    // E_LIBBSP_A429_RX_4 = 3,
    // E_LIBBSP_A429_RX_5 = 4,
    // E_LIBBSP_A429_RX_6 = 5,
    // E_LIBBSP_A429_RX_7 = 6,
    // E_LIBBSP_A429_RX_8 = 7,
    // E_LIBBSP_A429_RX_9 = 8
// } TE_LIBBSP_A429_RxLine;

/*
typedef enum {
    E_LIBBSP_A429_RX_1 = 0,
    E_LIBBSP_A429_RX_2 = 1,
    E_LIBBSP_A429_RX_3 = 2,
    E_LIBBSP_A429_RX_4 = 3,
    E_LIBBSP_A429_RX_5 = 4,
    E_LIBBSP_A429_RX_6 = 5,
    E_LIBBSP_A429_RX_7 = 6,
    E_LIBBSP_A429_RX_8 = 7,
    E_LIBBSP_A429_RX_9 = 8,
    //E_LIBBSP_A429_RX_10 = 9, //6 spare dans le mapping
    //E_LIBBSP_A429_RX_11 = 10
    //E_LIBBSP_A429_RX_12 = 11
    //E_LIBBSP_A429_RX_13 = 12
    //E_LIBBSP_A429_RX_14 = 13
    //E_LIBBSP_A429_RX_15 = 14
} TE_LIBBSP_A429_RxLine;*/


/* Baud rates */
/*typedef enum {
    E_LIBBSP_A429_BAUDS_12              = 0,
    E_LIBBSP_A429_BAUDS_100             = 1
} TE_LIBBSP_A429_Speed;*/

/*typedef enum {
    E_LIBBSP_A429_LABELS_NOT_AUTHORIZED      = 0,
    E_LIBBSP_A429_LABELS_AUTHORIZED  = 1
} TE_LIBBSP_A429_Label;*/


/*typedef enum {*/
/*    E_LIBBSP_A429_TX_OK                  = 0,*/
/*    E_LIBBSP_A429_TX_INVALID_ID          = 1,*/
/*    E_LIBBSP_A429_TX_OVERFLOW_CMD     = 2,*/
/*    E_LIBBSP_A429_TX_OVERFLOW_FIFO    = 3*/
/*} TE_LIBBSP_A429_TxErrorCode;*/
/* defined in kcg_types.h */


/*NEW PLD*/

/*typedef enum {*/
/*    E_LIBBSP_A429_TX_1 = 15,*/
/*    E_LIBBSP_A429_TX_2 = 16,*/
/*    E_LIBBSP_A429_TX_3 = 17,*/
/*    E_LIBBSP_A429_TX_4 = 18,*/
/*    E_LIBBSP_A429_TX_5 = 19,*/
/*    E_LIBBSP_A429_TX_6 = 20,*/
/*    E_LIBBSP_A429_TX_7 = 21,*/
/*    E_LIBBSP_A429_TX_8 = 22*/
/*} TE_LIBBSP_A429_TxLine;*/
/* defined in kcg_types */

typedef union
{
    uint32_t R;
    struct                      /* RX Status */
    {
        uint32_t RXERRFORMAT        :1;             /* Format error 0: no error, 1: one error at least */
        uint32_t RXERRPARITY        :1;             /* Parity error 0: no error, 1: one error at least */
        uint32_t RXERRGAP           :1;             /* Gap error 0: no error, 1: one error at least */
        uint32_t RXBUFROLLOVER      :2;             /* Incremented at 0 transitions of buffer */
        uint32_t                    :3;             /* Reserved */
        uint32_t RXERRCOUNT     :8;             /* Error counter (format + gap + parity) */
        uint32_t                    :8;             /* Reserved */
        uint32_t RXWORDADDR     :8;             /* Address of next word to store in circular buffer */

    } RXSTAT;
} TU_LIBBSP_A429_RxState;


typedef union
{
    uint32_t R;
    struct                      /* TX Status */
    {
        uint32_t TXOVFFIFO          :1;             /* TX FIFO overflow 0: no error, 1: one error at least */
        uint32_t TXOVFCMD           :1;             /* Transmit command while transmit 0: no error, 1: one error at least */
        uint32_t                    :5;             /* Reserved */
        uint32_t TXSTATE            :1;             /* Transmisson in progress 0: no frame, 1: in progress */
        uint32_t TXERRCOUNT     :8;             /* Error counter of overflows (Cmd + FIFO) */
        uint32_t                    :10;            /* Reserved */
        uint32_t TXWORDCNT          :6;             /* Number of words in TX FIFO */

    } TXSTAT;
} TU_LIBBSP_A429_TxState;


/* Registers of Megatice ARINC interface */
typedef union
{
    uint32_t R;
    struct                      /* TX Command Register */
    {
        uint32_t TXENABLE           :1;             /* Enable port 0: disabled, 1: enabled */
        uint32_t TXBAUDRATE         :1;             /* Baud rate 0: 12,5Kb:s 1: 100Kb/s */
        uint32_t                    :29;            /* Reserved */
        uint32_t TXCOMMAND          :1;             /* Command 0: no effect, 1: start FIFO transmission */
    } TXCOM;
    struct                      /* TX Status */
    {
        uint32_t TXOVFFIFO          :1;             /* TX FIFO overflow 0: no error, 1: one error at least */
        uint32_t TXOVFCMD           :1;             /* Transmit command while transmit 0: no error, 1: one error at least */
        uint32_t                    :5;             /* Reserved */
        uint32_t TXSTATE            :1;             /* Transmisson in progress 0: no frame, 1: in progress */
        uint32_t TXERRCOUNT     :8;             /* Error counter of overflows (Cmd + FIFO) */
        uint32_t                    :10;            /* Reserved */
        uint32_t TXWORDCNT          :6;             /* Number of words in TX FIFO */

    } TXSTAT;
    struct                      /* TX FIFO */
    {
        uint32_t                    :1;             /* Reserved */
        uint32_t TXDATA         :31;            /* Data word to transmit */
    } TXFIFO;
    struct                      /* RX Command Register */
    {
        uint32_t RXENABLE           :1;             /* Enable port 0: disabled, 1: enabled */
        uint32_t RXBAUDRATE     :1;             /* Baud rate 0: 12,5Kb:s 1: 100Kb/s */
        uint32_t                    :30;            /* Reserved */

    } RXCOM;
    struct                      /* RX Status */
    {
        uint32_t RXERRFORMAT        :1;             /* Format error 0: no error, 1: one error at least */
        uint32_t RXERRPARITY        :1;             /* Parity error 0: no error, 1: one error at least */
        uint32_t RXERRGAP           :1;             /* Gap error 0: no error, 1: one error at least */
        uint32_t RXBUFROLLOVER      :2;             /* Incremented at 0 transitions of buffer */
        uint32_t                    :3;             /* Reserved */
        uint32_t RXERRCOUNT     :8;             /* Error counter (format + gap + parity) */
        uint32_t                    :8;             /* Reserved */
        uint32_t RXWORDADDR     :8;             /* Address of next word to store in circular buffer */

    } RXSTAT;
    struct                      /* RX Time tag */
    {
        uint32_t RXTIMETAG          :32;            /* Time tag of word of circular buffer (resolution 250 microsecond) */
    } RXTIME;
    union {
        uint32_t       u32;
        uint16_t      u16;
        uint8_t       u8;
    } SPRXREG;
} TU_LIBBSP_A429_Register;

/* Megatice blocks of functionnal interface */
typedef union
{
    TU_LIBBSP_A429_Register mRegister[C_A429_MEGATICE_BLOCK_SIZE]; /* 4-bytes registers of a megatice block */
    struct                      /* ARINC Tramsmit Controller registers */
    {
        TU_LIBBSP_A429_Register txCommand;             /* Command register */
        TU_LIBBSP_A429_Register txStatus;              /* Status register */
        TU_LIBBSP_A429_Register txUnused0[C_A429_TX_UNUSED_SIZE];          /* Unused */
        TU_LIBBSP_A429_Register txFIFO;                /* FIFO registers */
        TU_LIBBSP_A429_Register txUnused1[C_A429_MEGATICE_BLOCK_SIZE-C_A429_TX_USED_SIZE]; /* Unused */
    } TXA429;
    struct                      /* ARINC Receive Controller registers */
    {
        TU_LIBBSP_A429_Register rxCommand;             /* Command register */
        TU_LIBBSP_A429_Register rxStatus;              /* Status register */
        TU_LIBBSP_A429_Register rxLabelFilterTable[C_A429_FILTER_TABLE_SIZE]; /* Nouveau PLD*/
        TU_LIBBSP_A429_Register rxUnused0[C_A429_RX_UNUSED0_SIZE];        /* Unused // Nouveau PLD*/
        /*TU_LIBBSP_A429_Register txUnused0[510];*/        /* Unused*/
        TU_LIBBSP_A429_Register rxBuffer[C_A429_RX_BUFFER_SIZE];    /* Buffer registers */
        TU_LIBBSP_A429_Register rxTimetags[C_A429_RX_BUFFER_SIZE];  /* Timetag registers */
        TU_LIBBSP_A429_Register rxUnused1[C_A429_MEGATICE_BLOCK_SIZE-(C_A429_RX_USED_SIZE+(C_A429_RX_BUFFER_SIZE*C_A429_NB_RX_BUFF))]; /* Unused */
    } RXA429;
} TU_LIBBSP_A429_MegaticeBlock;


typedef union
{
    struct {
        volatile TU_LIBBSP_A429_MegaticeBlock rxController[RX_CONTROLLERS_COUNT]; /* Blocks of Transmit Controllers */
        volatile TU_LIBBSP_A429_MegaticeBlock txController[TX_CONTROLLERS_COUNT]; /* Blocks of Transmit Controllers */
    } RXTXCTL;
    struct {
        volatile TU_LIBBSP_A429_MegaticeBlock a429Controller[A429_DEVICES_COUNT];   /* Blocks of all Controllers */
    } ALLCTL;
} TU_LIBBSP_A429_Registers;

/*==== Variables========================================================================*/

// extern const uint32_t C_A429_AUTHORIZED;
// extern const uint32_t C_A429_NOT_AUTHORIZED;
// extern const uint32_t C_A429_RX_DIVIDED_COEFF;

// extern volatile TU_LIBBSP_A429_Registers * const V_A429Regs;
extern uint32_t V_A429ReceivePointers[RX_CONTROLLERS_COUNT];

/*==== Services ========================================================================*/

extern TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_InitInputLink(const TE_LIBBSP_A429_RxLine devID, const TE_LIBBSP_A429_Speed baudRate,const uint32_t NbAuthLabel, const uint8_t * const AuthLabel);
extern TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_ActivateRead(const TE_LIBBSP_A429_RxLine devID, const boolean_t AuthRead);
extern TE_LIBBSP_A429_RxErrorCode LIBBSP_A429_Read(const TE_LIBBSP_A429_RxLine devID, const uint32_t NbLabToRead,
                                                   uint32_t * const buffer,  uint32_t * const timetags, uint32_t * const NbLabRead, TU_LIBBSP_A429_RxState * const ErrorState);
extern TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_ActivateWrite(const TE_LIBBSP_A429_TxLine devID, const boolean_t AuthWrite);
extern TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_InitOutputLink(const TE_LIBBSP_A429_TxLine devID, const TE_LIBBSP_A429_Speed baudRate);
extern TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_Launch(const TE_LIBBSP_A429_TxLine devID, TU_LIBBSP_A429_TxState * const ErrorState);
extern TE_LIBBSP_A429_TxErrorCode LIBBSP_A429_Write(const TE_LIBBSP_A429_TxLine devID, const uint32_t size, const uint32_t * const buffer, uint32_t * const count, TU_LIBBSP_A429_TxState * const ErrorState);

    
/*==== END =============================================================================*/
#endif
