#include "Seq_Public.h"
#include "Seq_Private.h"
#include "DrvLPIT_Public.h"
#include "DrvNVIC_Public.h"
#include "MCP_Types.h"

 void Seq_Start_Sequencer (void) {    DrvLPIT_Start (DRVLPIT_IDENT_0, DRVLPIT_500_US);    DrvNVIC_Initialize (DRVNVIC_SEQ_IRQ_SELECTION); }
