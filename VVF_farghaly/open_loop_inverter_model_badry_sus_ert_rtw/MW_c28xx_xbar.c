#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "open_loop_inverter_model_badry_sus.h"
#include "open_loop_inverter_model_badry_sus_private.h"
#include "MW_c28xGPIO.h"

void configureIXbar(void)
{
  /*--- Configuring GPIO set in Input Xbar---*/
  EALLOW;
  InputXbarRegs.INPUT5SELECT = 0;
  EDIS;
}
