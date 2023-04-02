#ifndef GPIO_CFEX_public_H
#define GPIO_CFEX_public_H

/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * -------------------------------------------------------------------------- */

/* ---------- include required interface: ----------------------------------- */
/* LPOS Common Interface */
#include "CMN_TYPES_common.h"

/* LPOS Public Interface */
/* none */

/* LPOS Private Interface */
/* none */

/* ---------- provided define constants: ------------------------------------ */
/* none */

/* ---------- provided types: ----------------------------------------------- */
/* none */

/* ---------- provided constants: ------------------------------------------- */

/* */
typedef uint32_t GPIO_CFEX_GPIO_ID_t;

/* */
typedef enum
{
   /* */
   e_GPIO_CFEX_ACCESS_PIN = 0,
   /* */
   e_GPIO_CFEX_ACCESS_PORT = 1
}
te_GPIO_CFEX_ACCES;


/* */
typedef enum
{
   /* */
   e_GPIO_CFEX_DIR_INPUT = 0,
   /* */
   e_GPIO_CFEX_DIR_OUTPUT = 1
}
te_GPIO_CFEX_DIR;

/* */
typedef enum
{
   /* */
   e_GPIO_CFEX_MASK_UNUSED = 0,
   /* */
   e_GPIO_CFEX_MASK_USED = 1
}
te_GPIO_CFEX_MASK_USED;


/* READ/WRITE PINS IDs */
typedef enum
{	
   e_GPIO_PIN_RW_ID_0 = 0,
   e_GPIO_PIN_RW_ID_1 = 1,
   e_GPIO_PIN_RW_ID_2 = 2,
   e_GPIO_PIN_RW_ID_3 = 3,
   e_GPIO_PIN_RW_ID_4 = 4,
   /* PA[5], PA[6], PA[7], PA[9] are used by JTAG*/
   e_GPIO_PIN_RW_ID_8 = 8,
   e_GPIO_PIN_RW_ID_10 = 10,
   e_GPIO_PIN_RW_ID_11 = 11,
   e_GPIO_PIN_RW_ID_12 = 12,
   e_GPIO_PIN_RW_ID_13 = 13,
   e_GPIO_PIN_RW_ID_14 = 14,
   e_GPIO_PIN_RW_ID_15 = 15,
   e_GPIO_PIN_RW_ID_24 = 24,
   e_GPIO_PIN_RW_ID_25 = 25,
   e_GPIO_PIN_RW_ID_26 = 26,
   e_GPIO_PIN_RW_ID_27 = 27,
   e_GPIO_PIN_RW_ID_32 = 32,
   e_GPIO_PIN_RW_ID_33 = 33,
   e_GPIO_PIN_RW_ID_34 = 34,
   e_GPIO_PIN_RW_ID_35 = 35,
   e_GPIO_PIN_RW_ID_36 = 36,
   e_GPIO_PIN_RW_ID_37 = 37,
   e_GPIO_PIN_RW_ID_38 = 38,
   e_GPIO_PIN_RW_ID_39 = 39,
   e_GPIO_PIN_RW_ID_40 = 40,
   e_GPIO_PIN_RW_ID_41 = 41,
   e_GPIO_PIN_RW_ID_42 = 42,
   e_GPIO_PIN_RW_ID_43 = 43,
   e_GPIO_PIN_RW_ID_44 = 44,
   e_GPIO_PIN_RW_ID_45 = 45,
   e_GPIO_PIN_RW_ID_46 = 46,
   e_GPIO_PIN_RW_ID_47 = 47,
   e_GPIO_PIN_RW_ID_48 = 48,
   e_GPIO_PIN_RW_ID_49 = 49,
   e_GPIO_PIN_RW_ID_50 = 50,
   e_GPIO_PIN_RW_ID_51 = 51,
   e_GPIO_PIN_RW_ID_52 = 52,
   e_GPIO_PIN_RW_ID_53 = 53,
   e_GPIO_PIN_RW_ID_54 = 54,
   e_GPIO_PIN_RW_ID_55 = 55,
   e_GPIO_PIN_RW_ID_56 = 56,
   e_GPIO_PIN_RW_ID_57 = 57,
   e_GPIO_PIN_RW_ID_58 = 58,
   e_GPIO_PIN_RW_ID_60 = 60,
   e_GPIO_PIN_RW_ID_61 = 61,
   e_GPIO_PIN_RW_ID_62 = 62,
   e_GPIO_PIN_RW_ID_63 = 63,
   e_GPIO_PIN_RW_ID_64 = 64,
   e_GPIO_PIN_RW_ID_65 = 65,
   e_GPIO_PIN_RW_ID_66 = 66,
   e_GPIO_PIN_RW_ID_67 = 67,
   e_GPIO_PIN_RW_ID_68 = 68,
   e_GPIO_PIN_RW_ID_69 = 69,
   e_GPIO_PIN_RW_ID_70 = 70,
   e_GPIO_PIN_RW_ID_71 = 71,
   e_GPIO_PIN_RW_ID_72 = 72,
   e_GPIO_PIN_RW_ID_73 = 73,
   e_GPIO_PIN_RW_ID_74 = 74,
   e_GPIO_PIN_RW_ID_75 = 75,
   e_GPIO_PIN_RW_ID_76 = 76,
   e_GPIO_PIN_RW_ID_80 = 80,
   e_GPIO_PIN_RW_ID_81 = 81,
   e_GPIO_PIN_RW_ID_82 = 82,
   e_GPIO_PIN_RW_ID_83 = 83,
   e_GPIO_PIN_RW_ID_84 = 84,
   e_GPIO_PIN_RW_ID_85 = 85,
   e_GPIO_PIN_RW_ID_86 = 86,
   e_GPIO_PIN_RW_ID_87 = 87,
   e_GPIO_PIN_RW_ID_88 = 88,
   e_GPIO_PIN_RW_ID_89 = 89,
   e_GPIO_PIN_RW_ID_90 = 90,
   e_GPIO_PIN_RW_ID_91 = 91,
   e_GPIO_PIN_RW_ID_92 = 92,
   e_GPIO_PIN_RW_ID_93 = 93,
   e_GPIO_PIN_RW_ID_94 = 94,
   e_GPIO_PIN_RW_ID_95 = 95,
   e_GPIO_PIN_RW_ID_96 = 96,
   e_GPIO_PIN_RW_ID_109 = 109,
   e_GPIO_PIN_RW_ID_110 = 110,
   e_GPIO_PIN_RW_ID_111 = 111,
   e_GPIO_PIN_RW_ID_112 = 112,
   e_GPIO_PIN_RW_ID_113 = 113,
   e_GPIO_PIN_RW_ID_114 = 114,
   e_GPIO_PIN_RW_ID_115 = 115,
   e_GPIO_PIN_RW_ID_116 = 116,
   e_GPIO_PIN_RW_ID_117 = 117,
   e_GPIO_PIN_RW_ID_118 = 118,
   e_GPIO_PIN_RW_ID_119 = 119,
   e_GPIO_PIN_RW_ID_120 = 120,
   e_GPIO_PIN_RW_ID_121 = 121,
   e_GPIO_PIN_RW_ID_122 = 122,
   e_GPIO_PIN_RW_ID_123 = 123,
   e_GPIO_PIN_RW_ID_124 = 124,
   e_GPIO_PIN_RW_ID_125 = 125,
   e_GPIO_PIN_RW_ID_126 = 126,
   e_GPIO_PIN_RW_ID_127 = 127,
   e_GPIO_PIN_RW_ID_136 = 136,
   e_GPIO_PIN_RW_ID_137 = 137,
   e_GPIO_PIN_RW_ID_138 = 138,
   e_GPIO_PIN_RW_ID_139 = 139,
   e_GPIO_PIN_RW_ID_140 = 140,
   e_GPIO_PIN_RW_ID_141 = 141,
   e_GPIO_PIN_RW_ID_142 = 142,
   e_GPIO_PIN_RW_ID_143 = 143,
   e_GPIO_PIN_RW_ID_144 = 144,
   e_GPIO_PIN_RW_ID_145 = 145,
   e_GPIO_PIN_RW_ID_146 = 146,
   e_GPIO_PIN_RW_ID_147 = 147,
   e_GPIO_PIN_RW_ID_148 = 148,
   e_GPIO_PIN_RW_ID_149 = 149,
   e_GPIO_PIN_RW_ID_150 = 150,
   e_GPIO_PIN_RW_ID_151 = 151,
   e_GPIO_PIN_RW_ID_152 = 152,
   e_GPIO_PIN_RW_ID_153 = 153,
   e_GPIO_PIN_RW_ID_154 = 154,
   e_GPIO_PIN_RW_ID_155 = 155,
   e_GPIO_PIN_RW_ID_156 = 156,
   e_GPIO_PIN_RW_ID_157 = 157,
   e_GPIO_PIN_RW_ID_158 = 158,
   e_GPIO_PIN_RW_ID_159 = 159,
   e_GPIO_PIN_RW_ID_172 = 172,
   e_GPIO_PIN_RW_ID_173 = 173,
   e_GPIO_PIN_RW_ID_174 = 174,
   e_GPIO_PIN_RW_ID_175 = 175,
   e_GPIO_PIN_RW_ID_176 = 176,
   e_GPIO_PIN_RW_ID_177 = 177,
   e_GPIO_PIN_RW_ID_178 = 178,
   e_GPIO_PIN_RW_ID_179 = 179,
   e_GPIO_PIN_RW_ID_180 = 180,
   e_GPIO_PIN_RW_ID_181 = 181,
   e_GPIO_PIN_RW_ID_182 = 182,
   e_GPIO_PIN_RW_ID_183 = 183,
   e_GPIO_PIN_RW_ID_184 = 184,
   e_GPIO_PIN_RW_ID_185 = 185,
   e_GPIO_PIN_RW_ID_186 = 186,
   e_GPIO_PIN_RW_ID_187 = 187,
   e_GPIO_PIN_RW_ID_188 = 188,
   e_GPIO_PIN_RW_ID_189 = 189,
   e_GPIO_PIN_RW_ID_190 = 190,
   e_GPIO_PIN_RW_ID_191 = 191,
   e_GPIO_PIN_RW_ID_192 = 192,
   e_GPIO_PIN_RW_ID_193 = 193,
   e_GPIO_PIN_RW_ID_194 = 194,
   e_GPIO_PIN_RW_ID_195 = 195,
   e_GPIO_PIN_RW_ID_196 = 196,
   e_GPIO_PIN_RW_ID_197 = 197,
   e_GPIO_PIN_RW_ID_198 = 198,
   e_GPIO_PIN_RW_ID_199 = 199,
   e_GPIO_PIN_RW_ID_200 = 200,
   e_GPIO_PIN_RW_ID_201 = 201,
   e_GPIO_PIN_RW_ID_202 = 202,
   e_GPIO_PIN_RW_ID_203 = 203,
   e_GPIO_PIN_RW_ID_204 = 204,
   e_GPIO_PIN_RW_ID_205 = 205,
   e_GPIO_PIN_RW_ID_206 = 206,
   e_GPIO_PIN_RW_ID_207 = 207,
   e_GPIO_PIN_RW_ID_208 = 208,
   e_GPIO_PIN_RW_ID_209 = 209,
   e_GPIO_PIN_RW_ID_210 = 210,
   e_GPIO_PIN_RW_ID_211 = 211,
   e_GPIO_PIN_RW_ID_212 = 212,
   e_GPIO_PIN_RW_ID_213 = 213,
   e_GPIO_PIN_RW_ID_214 = 214,
   e_GPIO_PIN_RW_ID_215 = 215,
   e_GPIO_PIN_RW_ID_216 = 216,
   e_GPIO_PIN_RW_ID_217 = 217,
   e_GPIO_PIN_RW_ID_218 = 218,
   e_GPIO_PIN_RW_ID_219 = 219,
   e_GPIO_PIN_RW_ID_220 = 220,
   e_GPIO_PIN_RW_ID_221 = 221,
   e_GPIO_PIN_RW_ID_222 = 222,
   e_GPIO_PIN_RW_ID_223 = 223,
   e_GPIO_PIN_RW_ID_224 = 224,
   e_GPIO_PIN_RW_ID_225 = 225,
   e_GPIO_PIN_RW_ID_226 = 226,
   e_GPIO_PIN_RW_ID_227 = 227,
   e_GPIO_PIN_RW_ID_228 = 228,
   e_GPIO_PIN_RW_ID_229 = 229,
   e_GPIO_PIN_RW_ID_230 = 230,
   e_GPIO_PIN_RW_ID_231 = 231,
   e_GPIO_PIN_RW_ID_232 = 232,
   e_GPIO_PIN_RW_ID_233 = 233,
   e_GPIO_PIN_RW_ID_234 = 234,
   e_GPIO_PIN_RW_ID_235 = 235,
   e_GPIO_PIN_RW_ID_236 = 236,
   e_GPIO_PIN_RW_ID_237 = 237,
   e_GPIO_PIN_RW_ID_238 = 238,
   e_GPIO_PIN_RW_ID_239 = 239,
   e_GPIO_PIN_RW_ID_240 = 240,
   e_GPIO_PIN_RW_ID_257 = 257,
   e_GPIO_PIN_RW_ID_258 = 258,
   e_GPIO_PIN_RW_ID_259 = 259,
   e_GPIO_PIN_RW_ID_260 = 260,
   e_GPIO_PIN_RW_ID_261 = 261,
   e_GPIO_PIN_RW_ID_262 = 262,
   e_GPIO_PIN_RW_ID_263 = 263,
   e_GPIO_PIN_RW_ID_264 = 264,
   e_GPIO_PIN_RW_ID_265 = 265,
   e_GPIO_PIN_RW_ID_266 = 266,
   e_GPIO_PIN_RW_ID_267 = 267,
   e_GPIO_PIN_RW_ID_268 = 268,
   e_GPIO_PIN_RW_ID_269 = 269,
   e_GPIO_PIN_RW_ID_270 = 270,
   e_GPIO_PIN_RW_ID_271 = 271,
   e_GPIO_PIN_RW_ID_272 = 272,
   e_GPIO_PIN_RW_ID_273 = 273,
   e_GPIO_PIN_RW_ID_274 = 274,
   e_GPIO_PIN_RW_ID_275 = 275,
   e_GPIO_PIN_RW_ID_276 = 276,
   e_GPIO_PIN_RW_ID_277 = 277,
   e_GPIO_PIN_RW_ID_278 = 278,
   e_GPIO_PIN_RW_ID_279 = 279,
   e_GPIO_PIN_RW_ID_280 = 280,
   e_GPIO_PIN_RW_ID_281 = 281,
   e_GPIO_PIN_RW_ID_282 = 282,
   e_GPIO_PIN_RW_ID_283 = 283,
   e_GPIO_PIN_RW_ID_284 = 284,
   e_GPIO_PIN_RW_ID_285 = 285,
   e_GPIO_PIN_RW_ID_286 = 286,
   e_GPIO_PIN_RW_ID_287 = 287,
   e_GPIO_PIN_RW_ID_288 = 288,
   e_GPIO_PIN_RW_ID_289 = 289,
   e_GPIO_PIN_RW_ID_290 = 290,
   e_GPIO_PIN_RW_ID_291 = 291,
   e_GPIO_PIN_RW_ID_292 = 292,
   e_GPIO_PIN_RW_ID_293 = 293,
   e_GPIO_PIN_RW_ID_294 = 294,
   e_GPIO_PIN_RW_ID_295 = 295,
   e_GPIO_PIN_RW_ID_296 = 296,
   e_GPIO_PIN_RW_ID_297 = 297,
   e_GPIO_PIN_RW_ID_298 = 298,
   e_GPIO_PIN_RW_ID_299 = 299,
   e_GPIO_PIN_RW_ID_300 = 300,
   e_GPIO_PIN_RW_ID_301 = 301,
   e_GPIO_PIN_RW_ID_302 = 302,
   e_GPIO_PIN_RW_ID_303 = 303,
   e_GPIO_PIN_RW_ID_304 = 304,
   e_GPIO_PIN_RW_ID_305 = 305,
   e_GPIO_PIN_RW_ID_306 = 306,
   e_GPIO_PIN_RW_ID_307 = 307,
   e_GPIO_PIN_RW_ID_308 = 308,
   e_GPIO_PIN_RW_ID_309 = 309,
   e_GPIO_PIN_RW_ID_310 = 310,
   e_GPIO_PIN_RW_ID_311 = 311,
   e_GPIO_PIN_RW_ID_312 = 312,
   e_GPIO_PIN_RW_ID_313 = 313,
   e_GPIO_PIN_RW_ID_314 = 314,
   e_GPIO_PIN_RW_ID_315 = 315,
   e_GPIO_PIN_RW_ID_316 = 316,
   e_GPIO_PIN_RW_ID_317 = 317,
   e_GPIO_PIN_RW_ID_318 = 318,
   e_GPIO_PIN_RW_ID_319 = 319,
   e_GPIO_PIN_RW_ID_320 = 320,
   e_GPIO_PIN_RW_ID_321 = 321,
   e_GPIO_PIN_RW_ID_322 = 322,
   e_GPIO_PIN_RW_ID_323 = 323,
   e_GPIO_PIN_RW_ID_324 = 324,
   e_GPIO_PIN_RW_ID_325 = 325,
   e_GPIO_PIN_RW_ID_326 = 326,
   e_GPIO_PIN_RW_ID_327 = 327,
   e_GPIO_PIN_RW_ID_328 = 328,
   e_GPIO_PIN_RW_ID_329 = 329,
   e_GPIO_PIN_RW_ID_330 = 330,
   e_GPIO_PIN_RW_ID_331 = 331,
   e_GPIO_PIN_RW_ID_340 = 340
}
te_GPIO_CFEX_PIN_RW_ID;

/* READ ONLY PINS IDs */
typedef enum
{
   e_GPIO_PIN_RO_ID_16 = 16,
   e_GPIO_PIN_RO_ID_17 = 17,
   e_GPIO_PIN_RO_ID_18 = 18,
   e_GPIO_PIN_RO_ID_19 = 19,
   e_GPIO_PIN_RO_ID_20 = 20,
   e_GPIO_PIN_RO_ID_21 = 21,
   e_GPIO_PIN_RO_ID_22 = 22,
   e_GPIO_PIN_RO_ID_23 = 23,
   e_GPIO_PIN_RO_ID_28 = 28,
   e_GPIO_PIN_RO_ID_29 = 29,
   e_GPIO_PIN_RO_ID_30 = 30,
   e_GPIO_PIN_RO_ID_31 = 31,
   e_GPIO_PIN_RO_ID_59 = 59,
   e_GPIO_PIN_RO_ID_77 = 77,
   e_GPIO_PIN_RO_ID_78 = 78,
   e_GPIO_PIN_RO_ID_79 = 79,
   e_GPIO_PIN_RO_ID_97 = 97,
   e_GPIO_PIN_RO_ID_98 = 98,
   e_GPIO_PIN_RO_ID_99 = 99,
   e_GPIO_PIN_RO_ID_100 = 100,
   e_GPIO_PIN_RO_ID_101 = 101,
   e_GPIO_PIN_RO_ID_102 = 102,
   e_GPIO_PIN_RO_ID_103 = 103,
   e_GPIO_PIN_RO_ID_104 = 104,
   e_GPIO_PIN_RO_ID_105 = 105,
   e_GPIO_PIN_RO_ID_106 = 106,
   e_GPIO_PIN_RO_ID_107 = 107,
   e_GPIO_PIN_RO_ID_108 = 108,
   e_GPIO_PIN_RO_ID_128 = 128,
   e_GPIO_PIN_RO_ID_129 = 129,
   e_GPIO_PIN_RO_ID_130 = 130,
   e_GPIO_PIN_RO_ID_131 = 131,
   e_GPIO_PIN_RO_ID_132 = 132,
   e_GPIO_PIN_RO_ID_133 = 133,
   e_GPIO_PIN_RO_ID_134 = 134,
   e_GPIO_PIN_RO_ID_135 = 135,
   e_GPIO_PIN_RO_ID_160 = 160,
   e_GPIO_PIN_RO_ID_161 = 161,
   e_GPIO_PIN_RO_ID_162 = 162,
   e_GPIO_PIN_RO_ID_163 = 163,
   e_GPIO_PIN_RO_ID_164 = 164,
   e_GPIO_PIN_RO_ID_165 = 165,
   e_GPIO_PIN_RO_ID_166 = 166,
   e_GPIO_PIN_RO_ID_167 = 167,
   e_GPIO_PIN_RO_ID_168 = 168,
   e_GPIO_PIN_RO_ID_169 = 169,
   e_GPIO_PIN_RO_ID_170 = 170,
   e_GPIO_PIN_RO_ID_171 = 171,
   e_GPIO_PIN_RO_ID_241 = 241,
   e_GPIO_PIN_RO_ID_242 = 242,
   e_GPIO_PIN_RO_ID_243 = 243,
   e_GPIO_PIN_RO_ID_244 = 244,
   e_GPIO_PIN_RO_ID_245 = 245,
   e_GPIO_PIN_RO_ID_246 = 246,
   e_GPIO_PIN_RO_ID_247 = 247,
   e_GPIO_PIN_RO_ID_248 = 248,
   e_GPIO_PIN_RO_ID_249 = 249,
   e_GPIO_PIN_RO_ID_250 = 250,
   e_GPIO_PIN_RO_ID_251 = 251,
   e_GPIO_PIN_RO_ID_252 = 252,
   e_GPIO_PIN_RO_ID_253 = 253,
   e_GPIO_PIN_RO_ID_254 = 254,
   e_GPIO_PIN_RO_ID_255 = 255,
   e_GPIO_PIN_RO_ID_256 = 256,
   e_GPIO_PIN_RO_ID_332 = 332,
   e_GPIO_PIN_RO_ID_333 = 333,
   e_GPIO_PIN_RO_ID_334 = 334,
   e_GPIO_PIN_RO_ID_335 = 335,
   e_GPIO_PIN_RO_ID_336 = 336,
   e_GPIO_PIN_RO_ID_337 = 337,
   e_GPIO_PIN_RO_ID_338 = 338,
   e_GPIO_PIN_RO_ID_339 = 339
}
te_GPIO_CFEX_PIN_RO_ID;


/* Port IDs */
typedef enum
{
   /* PA[5], PA[6], PA[7], PA[9] are used by JTAG*/
   e_GPIO_PORT_ID_0 = 0,
   e_GPIO_PORT_ID_1 = 1,
   e_GPIO_PORT_ID_2 = 2,
   e_GPIO_PORT_ID_3 = 3,
   e_GPIO_PORT_ID_4 = 4,
   e_GPIO_PORT_ID_5 = 5,
   e_GPIO_PORT_ID_6 = 6,
   e_GPIO_PORT_ID_7 = 7,
   e_GPIO_PORT_ID_8 = 8,
   e_GPIO_PORT_ID_9 = 9,
   e_GPIO_PORT_ID_10 = 10,
   e_GPIO_PORT_ID_11 = 11,
   e_GPIO_PORT_ID_12 = 12,
   e_GPIO_PORT_ID_13 = 13,
   e_GPIO_PORT_ID_14 = 14,
   e_GPIO_PORT_ID_15 = 15,
   e_GPIO_PORT_ID_16 = 16,
   e_GPIO_PORT_ID_17 = 17,
   e_GPIO_PORT_ID_18 = 18,
   e_GPIO_PORT_ID_19 = 19,
   e_GPIO_PORT_ID_20 = 20
}
te_GPIO_CFEX_PORT_ID;

typedef union
{
   /* gpio pin READ-WRITE */
   te_GPIO_CFEX_PIN_RW_ID   u_gpio_pin_rw_id;
   /* gpio pin READ-ONLY */
   te_GPIO_CFEX_PIN_RO_ID   u_gpio_pin_ro_id;
   /* gpio_port */
   te_GPIO_CFEX_PORT_ID     u_gpio_port_id;
}
tu_GPIO_CFEX_ID;

/* */
typedef struct
{
   /* gpio id */
   tu_GPIO_CFEX_ID        s_gpio_id;
   /* gpio s_direction */
   te_GPIO_CFEX_DIR       s_direction;
   /* gpio s_access */
   te_GPIO_CFEX_ACCES     s_access;
   /* reset value */
   uint8_t                s_reset_value;
   /*  mask enable */
   te_GPIO_CFEX_MASK_USED s_mask_used;
   /* mask value */
   uint32_t               s_mask_value;
}
ts_GPIO_CFEX_ELT;

/* */
typedef struct
{
   /* gpio id */
   GPIO_CFEX_GPIO_ID_t    s_gpio_id;
   /* mask value */
   uint32_t               s_mask_value;
}
ts_GPIO_CONFIG_DESC;




/* ---------- provided constants: ------------------------------------------- */
/* */

/* {{RELAX<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> : the table c_GPIO_CFEX_CONFIGURATION_tab and */
/* GPIO_CFEX_descriptor_tab share the same size : c_GPIO_CFEX_tab_SIZE. This size is a integration value */
/* so the table are declared without a size. */
extern const uint32_t c_GPIO_CFEX_tab_SIZE; 
extern const ts_GPIO_CFEX_ELT c_GPIO_CFEX_CONFIGURATION_tab[];

/* ---------- provided data: ------------------------------------------------ */
/* */
/* GPIO descriptor */
extern ts_GPIO_CONFIG_DESC GPIO_CFEX_descriptor_tab[];
/* }}<SYNCHRONe_C_Code_8.12, SYNCHRONe_C_Code_8.16> */


/* ---------- provided operations: ------------------------------------------ */
/* */

#endif /* GPIO_CFEX_public_H */
