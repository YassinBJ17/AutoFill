/* --------------------------------------------------------------------------
 *                        SAFRAN Electronics & Defense
 *                   Reproduction and disclosure forbidden.
 * --------------------------------------------------------------------------
 * DESCRIPTION : Definition of the sections for CSS wrapper GX
 * -------------------------------------------------------------------------- */

/* ---------- include provided interface: ----------------------------------- */
#include "memory/lib_critical_service_section_def_data.h"
#include "memory/shared_memory_public.h"
#include "middleware/tmot/tmot_write_public.h"
#include "driver/can/can_critical_public.h"
#include "middleware/smot/smot_write_public.h"
#include "middleware/accom/accom_public.h"
#include "middleware/icdl/ICDL_public.h"
#include "middleware/discrete/discrete_atp_public.h"

/* ---------- include required interface: ----------------------------------- */

/* ---------- internal define constants: ------------------------------------ */

/* ---------- internal types: ----------------------------------------------- */

/* ---------- provided constants: ------------------------------------------- */

/* ---------- provided data: ------------------------------------------------ */
/* Shared memory */
#pragma section SHARED_MEMORY_AREA \
    ".shared_memory_src"           \
    ".shared_memory_src"
#pragma use_section SHARED_MEMORY_AREA shmem

/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
ts_shmem shmem;

#pragma section SHARED_MEMORY_AREA

/* Critical services pointers area */
#pragma section CRITICAL_SERVICES_POINTERS_AREA \
    ".critical_services_pointers_src"           \
    ".critical_services_pointers_src"

#pragma use_section CRITICAL_SERVICES_POINTERS_AREA \
    critical_services_pointers_area

/* >RELAX<SYNCHRONe_C_Code_8.2> justification */
/* >RELAX<SYNCHRONe_C_Code_8.13> justification */
/* >RELAX<SYNCHRONe_C_Code_8.15> justification */
/* >RELAX<SYNCHRONe_C_Code_8.17> justification */

const uint32_t critical_services_pointers_area[CRITICAL_SERVICES_POINTERS_AREA_SIZE] =
{
   (uint32_t)(&tmot_write),                                     /*  0 : tmot function          */
   (uint32_t)(&can1_critical_write),                            /*  1 : can function           */
   (uint32_t)(&smot_write),                                     /*  2 : smot function          */
   (uint32_t)(&accom_preferential_channel_refuse_write_set),    /*  3 : accom function WRITE   */
   (uint32_t)(&accom_preferential_channel_refuse_write_clear),  /*  4 : accom function WRITE   */
   (uint32_t)(&accom_control_refuse_write_set),                 /*  5 : accom function WRITE   */
   (uint32_t)(&accom_control_refuse_write_clear),               /*  6 : accom function WRITE   */
   (uint32_t)(&accom_css_unable_write_set),                     /*  7 : accom function WRITE   */
   (uint32_t)(&accom_css_unable_write_clear),                   /*  8 : accom function WRITE   */
   (uint32_t)(&accom_force_disconnection_set),                  /*  9 : accom function WRITE   */
   (uint32_t)(&accom_force_disconnection_clear),                /* 10 : accom function WRITE   */
   (uint32_t)(&accom_mcss_inconsistent_write_set),              /* 11 : accom function WRITE   */
   (uint32_t)(&accom_mcss_inconsistent_write_clear),            /* 12 : accom function WRITE   */
   (uint32_t) 0,                                                /* 13 : time_base_read         */
   (uint32_t)(&icdl_write),                                     /* 14 : ICDL function WRITE    */
   (uint32_t)(&icdl_read),                                      /* 15 : ICDL function READ     */
   (uint32_t)0,                                                 /* 16 : reserved */
   (uint32_t)0,                                                 /* 17 : ovs_detect             */
   (uint32_t)0,                                                 /* 18 : hp_write               */
   (uint32_t)0,                                                 /* 19 : lp_read                */
   (uint32_t)(&discrete_atp_set),                               /* 20 : reserved for test only */
   (uint32_t)(&discrete_atp_clear),                             /* 21 : reserved for test only */
   (uint32_t)0,                                                 /* 22 : reserved */
   (uint32_t)0,                                                 /* 23 : reserved */
   (uint32_t)0,                                                 /* 24 : reserved */
   (uint32_t)0,                                                 /* 25 : reserved */
   (uint32_t)0,                                                 /* 26 : reserved */
   (uint32_t)0,                                                 /* 27 : reserved */
   (uint32_t)0,                                                 /* 28 : reserved */
   (uint32_t)0,                                                 /* 29 : reserved */
   (uint32_t)0,                                                 /* 30 : reserved */
   (uint32_t)0,                                                 /* 31 : reserved */
   (uint32_t)0,                                                 /* 32 : reserved */
   (uint32_t)0,                                                 /* 33 : reserved */
   (uint32_t)0,                                                 /* 34 : reserved */
   (uint32_t)0,                                                 /* 35 : reserved */
   (uint32_t)0,                                                 /* 36 : reserved */
   (uint32_t)0,                                                 /* 37 : reserved */
   (uint32_t)0,                                                 /* 38 : reserved */
   (uint32_t)0,                                                 /* 39 : reserved */
   (uint32_t)0,                                                 /* 40 : reserved */
   (uint32_t)0,                                                 /* 41 : reserved */
   (uint32_t)0,                                                 /* 42 : reserved */
   (uint32_t)0,                                                 /* 43 : reserved */
   (uint32_t)0,                                                 /* 44 : reserved */
   (uint32_t)0,                                                 /* 45 : reserved */
   (uint32_t)0,                                                 /* 46 : reserved */
   (uint32_t)0,                                                 /* 47 : reserved */
   (uint32_t)0,                                                 /* 48 : reserved */
   (uint32_t)0,                                                 /* 49 : reserved */
   (uint32_t)0,                                                 /* 50 : reserved */
   (uint32_t)0,                                                 /* 51 : reserved */
   (uint32_t)0,                                                 /* 52 : reserved */
   (uint32_t)0,                                                 /* 53 : reserved */
   (uint32_t)0,                                                 /* 54 : reserved */
   (uint32_t)0,                                                 /* 55 : reserved */
   (uint32_t)0,                                                 /* 56 : reserved */
   (uint32_t)0,                                                 /* 57 : reserved */
   (uint32_t)0,                                                 /* 58 : reserved */
   (uint32_t)0,                                                 /* 59 : reserved */
   (uint32_t)0,                                                 /* 60 : reserved */
   (uint32_t)0,                                                 /* 61 : reserved */
   (uint32_t)0,                                                 /* 62 : reserved */
   (uint32_t)0                                                  /* 63 : reserved */
};

#pragma section CRITICAL_SERVICES_POINTERS_AREA

/* ---------- internal constants: ------------------------------------------- */

/* ---------- internal data: ------------------------------------------------ */

/* ---------- provided operation bodies: ------------------------------------ */

/* ---------- internal operations: ------------------------------------------ */
