#include "DrvGPIO_Private.h"

    (TS_DrvGPIO_Registers *) DRVGPIO_PORT_E_ADDRESS }; const TS_DrvGPIO_Port_Config C_DrvGPIO_Port_Config [DRVGPIO_OVSP_SIDE_NB] [DRVGPIO_MAX_PORTS_NB] = {    {       {DRVGPIO_PORT_A_PDDR_CONFIG_HS, DRVGPIO_PORT_A_PIDR_CONFIG_HS},       {DRVGPIO_PORT_B_PDDR_CONFIG_HS, DRVGPIO_PORT_B_PIDR_CONFIG_HS},       {DRVGPIO_PORT_C_PDDR_CONFIG_HS, DRVGPIO_PORT_C_PIDR_CONFIG_HS},       {DRVGPIO_PORT_D_PDDR_CONFIG_HS, DRVGPIO_PORT_D_PIDR_CONFIG_HS},       {DRVGPIO_PORT_E_PDDR_CONFIG_HS, DRVGPIO_PORT_E_PIDR_CONFIG_HS}    },    {       {DRVGPIO_PORT_A_PDDR_CONFIG_LS, DRVGPIO_PORT_A_PIDR_CONFIG_LS},       {DRVGPIO_PORT_B_PDDR_CONFIG_LS, DRVGPIO_PORT_B_PIDR_CONFIG_LS},       {DRVGPIO_PORT_C_PDDR_CONFIG_LS, DRVGPIO_PORT_C_PIDR_CONFIG_LS},       {DRVGPIO_PORT_D_PDDR_CONFIG_LS, DRVGPIO_PORT_D_PIDR_CONFIG_LS},       {DRVGPIO_PORT_E_PDDR_CONFIG_LS, DRVGPIO_PORT_E_PIDR_CONFIG_LS}    } }; const TS_DrvGPIO_IO_Config C_DrvGPIO_IO_Config [DRVGPIO_IO_MAX_NB] = {    {DRVGPIO_PORT_D_ID,  5UL, DRVGPIO_PIN_05_MASK, DRVGPIO_STATE_HIGH, DRVGPIO_STATE_LOW},    {DRVGPIO_PORT_E_ID,  9UL, DRVGPIO_PIN_09_MASK, DRVGPIO_STATE_HIGH, DRVGPIO_STATE_LOW},    {DRVGPIO_PORT_A_ID,  1UL, DRVGPIO_PIN_01_MASK, DRVGPIO_STATE_HIGH, DRVGPIO_STATE_LOW},    {DRVGPIO_PORT_E_ID,  0UL, DRVGPIO_PIN_00_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH},    {DRVGPIO_PORT_E_ID, 11UL, DRVGPIO_PIN_11_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH},    {DRVGPIO_PORT_E_ID,  7UL, DRVGPIO_PIN_07_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH},    {DRVGPIO_PORT_D_ID, 15UL, DRVGPIO_PIN_15_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH},    {DRVGPIO_PORT_D_ID,  3UL, DRVGPIO_PIN_03_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH},    {DRVGPIO_PORT_E_ID,  6UL, DRVGPIO_PIN_06_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH},    {DRVGPIO_PORT_E_ID,  8UL, DRVGPIO_PIN_08_MASK, DRVGPIO_STATE_HIGH, DRVGPIO_STATE_LOW},    {DRVGPIO_PORT_B_ID,  5UL, DRVGPIO_PIN_05_MASK, DRVGPIO_STATE_HIGH, DRVGPIO_STATE_LOW},    {DRVGPIO_PORT_E_ID,  1UL, DRVGPIO_PIN_01_MASK, DRVGPIO_STATE_LOW,  DRVGPIO_STATE_HIGH}
