/****************************************************************************************/
/*                                                                                      */
/*--------------------------------------------------------------------------------------*/
/* Copyright (c) 2019                                                                   */
/* SAFRAN Electronics & Defense. Reproduction and disclosure forbidden.                 */
/****************************************************************************************/
#ifndef LIBBSP_IMU_H_
#define LIBBSP_IMU_H_

#include "LIBMCP_Types.h"
#include "kcg_types.h"


/*==== Definitions =====================================================================*/
#define C_IMU_NB_INERTIAL_DATA_TO_READ 63ul
#define C_IMU_NB_PERMANENT_DATA_TO_WRITE 1ul
//#define C_IMU_DATA_TAB_SIZE 3
#define C_IMU_COEFF_ADDR 2ul
/*==== Types =======================================================================*/

typedef enum {
   E_LIBBSP_IMU_VALID_ADDR = 0,
   E_LIBBSP_IMU_INVALID_ADDR =  1

} TE_LIBBSP_IMU_AddrStatus;


typedef enum {
   E_LIBBSP_IMU_RESET_ALL_R_ADDR = 0,
   E_LIBBSP_IMU_RESET_ADD_R_ADDR =  1

} TE_LIBBSP_IMU_ReadEraseCmd;

/*#ifndef _KCG_TYPES_H_ */
/*typedef enum { */
/*   E_LIBBSP_IMU_RESET_ALL_W_ADDR = 0, */
/*   E_LIBBSP_IMU_RESET_ADD_W_ADDR =  1 */
/* */
/*} TE_LIBBSP_IMU_WriteEraseCmd; */
/*#endif */
/* defined in kcg_types.h */

/*typedef enum { */
/*   E_LIBBSP_IMU_NB_DATA_OK = 0, */
/*   E_LIBBSP_IMU_NB_DATA_EXCEEDED =  1 */
/* */
/*} TE_LIBBSP_IMU_ProgStatus; */
/* defined in kcg_types.h */

/*typedef enum { */
/*   E_LIBBSP_IMU_WRITE_ADDRESS = 0, */
/*   E_LIBBSP_IMU_NO_WRITE_ADDRESS =  1 */
/* */
/*} TE_LIBBSP_IMU_WriteAddr; */
/* defined in kcg_types.h */

/*typedef struct
{
*/
	/*Nav data*/
/*	float64_t dTheta[C_IMU_DATA_TAB_SIZE];
	float64_t dV[C_IMU_DATA_TAB_SIZE];
	float64_t Cp[C_IMU_DATA_TAB_SIZE];
	float64_t TheteE[C_IMU_DATA_TAB_SIZE];
	float64_t ErrFEP[C_IMU_DATA_TAB_SIZE];
	float64_t IndFEP[C_IMU_DATA_TAB_SIZE];
	uint32_t HRGReady_MEO;
	uint32_t cbit;
	uint32_t pbit;
	uint32_t cpt_umi;
	boolean_t validity;
	boolean_t FEP_update;
*/
	/*Pilot data*/
/*	float64_t fs_filtA_fPilot[C_IMU_DATA_TAB_SIZE];
	float64_t fs_filtB_BdL_fPilot[C_IMU_DATA_TAB_SIZE];
	float64_t pqr_filtE_fPilot[C_IMU_DATA_TAB_SIZE];
	float64_t pqr_filtF_fPilot[C_IMU_DATA_TAB_SIZE];
	float64_t accAng_filtE_fPilot[C_IMU_DATA_TAB_SIZE];
	float64_t accAng_filtF_fPilot[C_IMU_DATA_TAB_SIZE];
*/
	/*Temp data*/
/*	float64_t Tacc_filtre[C_IMU_DATA_TAB_SIZE];
	float64_t Tida_filtre;
	float64_t Tacc_sature[C_IMU_DATA_TAB_SIZE];
    float64_t Cpulse_sature[C_IMU_DATA_TAB_SIZE];
	float64_t Tida_sature;
} TS_LIBBSP_IMU_InertialData;*/
/* defined in kcg_types.g */

typedef union
{
	struct
	{
	uint32_t msb;
	uint32_t lsb;
	} double_int;
	float64_t float_double;
	float32_t float_simple;
	struct
	{
		struct
		{
			uint32_t s:1;
			uint32_t exp:8;
			uint32_t mant:23;
		} first;
		struct
		{
			uint32_t mant:8;
			uint32_t dummy:24;
		} second;
	} float_40;
	struct
	{
		struct
		{
			uint32_t s:1;
			uint32_t exp:11;
			uint32_t mant:20;
		} first;
		uint32_t second;
	} float_64;
} TS_LIBBSP_IMU_DoubleWord;

/*typedef struct
{
    uint32_t* p_IMU_BaseAddress;
}TS_LIBBSP_IMU_BaseAddress;*/

typedef struct
{
    uint32_t tic_input_sw2hw_start;
    uint32_t input_write_sw2hw[64];
    uint32_t input_read_sw2hw[64];
    uint32_t tic_input_sw2hw_end;
}TS_sw2hw_buffer;

typedef struct
{
    uint32_t tic_output_hw2sw_start;
    uint32_t unused1;
    uint32_t tic_output_hw2sw_time_ref;
    uint32_t unused2;
    uint32_t output_read_sw2hw[128];
    uint32_t tic_output_hw2sw_end;
    uint32_t unused3;
}TS_hw2sw_buffer;


typedef struct
{
	TS_sw2hw_buffer tic_sw2hw_buffer;
	uint32_t tic_sw2hw_buffer_en_consistent_data;
	uint32_t spare[893];
	TS_hw2sw_buffer tic_hw2sw_buffer;
}TS_LIBBSP_IMU_TicBuffersReg;

/*==== Variables =======================================================================*/
//extern TS_LIBBSP_IMU_BaseAddress IMU_Interface;
extern volatile TS_LIBBSP_IMU_TicBuffersReg * const V_IMUTicRegs;
//extern const uint32_t C_IMU_SW2HW_READ_BASE_ADDRESS;
//extern const uint32_t C_IMU_HW2SW_READ_BASE_ADDRESS;
// extern const uint32_t C_IMU_BLADE_TIC_NB_DATA_READ_MAX;
//extern const uint32_t C_IMU_SW2HW_WRITE_BASE_ADDRESS;
// extern const uint32_t C_IMU_BLADE_TIC_NB_DATA_WRITE_MAX;

/*==== Services =======================================================================*/
extern void LIBBSP_IMU_Zero(void);
extern void LIBBSP_IMU_ProgReadInertialData(void);
extern void LIBBSP_IMU_Activation(void);
extern void LIBBSP_IMU_GetReadInertialData(TS_LIBBSP_IMU_InertialData* const ReadInertialData);
extern void LIBBSP_IMU_ProgPrecStatusCommand(const boolean_t PrecessionCmd, const TE_LIBBSP_IMU_WriteAddr WritePrecAddr);
extern TE_LIBBSP_IMU_ProgStatus LIBBSP_IMU_ProgAdditionalReadData (const uint32_t * const BufferAddrRead, const uint32_t NbDataToRead);
//extern void LIBBSP_IMU_GetAdditionalReadData(const uint32_t NbDataToRead, float64_t* const AdditionalReadData);
extern void LIBBSP_IMU_GetAdditionalReadData(const uint32_t NbDataToRead, TS_LIBBSP_IMU_DoubleWord* const v_RawAdditionalData);
extern void LIBBSP_IMU_RazReadData(const TE_LIBBSP_IMU_ReadEraseCmd EraseCmd);
extern TE_LIBBSP_IMU_ProgStatus LIBBSP_IMU_ProgAdditionalWrite(const uint32_t * const BuffAddDataAddr,const int32_t * const BuffAddData, const uint32_t NbAddDataToWrite);
extern void LIBBSP_IMU_RazWriteData(const TE_LIBBSP_IMU_WriteEraseCmd EraseCmd);
extern float64_t LIBBSP_IMU_F40toF64( const TS_LIBBSP_IMU_DoubleWord* const p_dw);

#endif /* LIBBSP_IMU_H_ */
