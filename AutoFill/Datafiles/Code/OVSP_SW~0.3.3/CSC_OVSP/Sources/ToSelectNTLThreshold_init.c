#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ToSelectNTLThreshold.h"

 void ToSelectNTLThreshold_init(outC_ToSelectNTLThreshold *outC) {   outC->init = kcg_true;   outC->_L21 = kcg_lit_float32(0.0);   outC->threshold = kcg_lit_float32(0.0); }
