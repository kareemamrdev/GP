/*
 * File: blinky.c
 *
 * Code generated for Simulink model 'blinky'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May  6 17:02:57 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "blinky.h"
#include "rtwtypes.h"
#include "blinky_private.h"
#include <string.h>

/* Block signals (default storage) */
B_blinky_T blinky_B;

/* Block states (default storage) */
DW_blinky_T blinky_DW;

/* Real-time model */
static RT_MODEL_blinky_T blinky_M_;
RT_MODEL_blinky_T *const blinky_M = &blinky_M_;

/* Model step function */
void blinky_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  blinky_B.PulseGenerator = (blinky_DW.clockTickCounter <
    blinky_P.PulseGenerator_Duty) && (blinky_DW.clockTickCounter >= 0L) ?
    blinky_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (blinky_DW.clockTickCounter >= blinky_P.PulseGenerator_Period - 1.0) {
    blinky_DW.clockTickCounter = 0L;
  } else {
    blinky_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (blinky_B.PulseGenerator) {
      GpioDataRegs.GPASET.bit.GPIO31 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO31 = 1U;
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++blinky_M->Timing.clockTick0)) {
    ++blinky_M->Timing.clockTickH0;
  }

  blinky_M->Timing.taskTime0 = blinky_M->Timing.clockTick0 *
    blinky_M->Timing.stepSize0 + blinky_M->Timing.clockTickH0 *
    blinky_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void blinky_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)blinky_M, 0,
                sizeof(RT_MODEL_blinky_T));
  rtmSetTFinal(blinky_M, -1);
  blinky_M->Timing.stepSize0 = 1.0E-5;

  /* External mode info */
  blinky_M->Sizes.checksums[0] = (353182801U);
  blinky_M->Sizes.checksums[1] = (2630253876U);
  blinky_M->Sizes.checksums[2] = (889311965U);
  blinky_M->Sizes.checksums[3] = (165979019U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    blinky_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(blinky_M->extModeInfo,
      &blinky_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(blinky_M->extModeInfo, blinky_M->Sizes.checksums);
    rteiSetTPtr(blinky_M->extModeInfo, rtmGetTPtr(blinky_M));
  }

  /* block I/O */
  (void) memset(((void *) &blinky_B), 0,
                sizeof(B_blinky_T));

  /* states (dwork) */
  (void) memset((void *)&blinky_DW, 0,
                sizeof(DW_blinky_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  blinky_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;
}

/* Model terminate function */
void blinky_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
