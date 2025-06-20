/*
 * File: external_mode.c
 *
 * Code generated for Simulink model 'external_mode'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Feb 28 21:08:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "external_mode.h"
#include "rtwtypes.h"
#include "external_mode_private.h"
#include <string.h>

/* Block signals (default storage) */
B_external_mode_T external_mode_B;

/* Block states (default storage) */
DW_external_mode_T external_mode_DW;

/* Real-time model */
static RT_MODEL_external_mode_T external_mode_M_;
RT_MODEL_external_mode_T *const external_mode_M = &external_mode_M_;

/* Model step function */
void external_mode_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  external_mode_B.PulseGenerator = (external_mode_DW.clockTickCounter <
    external_mode_P.PulseGenerator_Duty) && (external_mode_DW.clockTickCounter >=
    0L) ? external_mode_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (external_mode_DW.clockTickCounter >= external_mode_P.PulseGenerator_Period
      - 1.0) {
    external_mode_DW.clockTickCounter = 0L;
  } else {
    external_mode_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)
      (external_mode_B.PulseGenerator != 0);
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)
      (external_mode_B.PulseGenerator != 0);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  external_mode_M->Timing.taskTime0 =
    ((time_T)(++external_mode_M->Timing.clockTick0)) *
    external_mode_M->Timing.stepSize0;
}

/* Model initialize function */
void external_mode_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)external_mode_M, 0,
                sizeof(RT_MODEL_external_mode_T));
  rtmSetTFinal(external_mode_M, -1);
  external_mode_M->Timing.stepSize0 = 0.5;

  /* External mode info */
  external_mode_M->Sizes.checksums[0] = (1181649507U);
  external_mode_M->Sizes.checksums[1] = (1835058972U);
  external_mode_M->Sizes.checksums[2] = (3199860303U);
  external_mode_M->Sizes.checksums[3] = (3135982554U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    external_mode_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(external_mode_M->extModeInfo,
      &external_mode_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(external_mode_M->extModeInfo,
                        external_mode_M->Sizes.checksums);
    rteiSetTPtr(external_mode_M->extModeInfo, rtmGetTPtr(external_mode_M));
  }

  /* block I/O */
  (void) memset(((void *) &external_mode_B), 0,
                sizeof(B_external_mode_T));

  /* states (dwork) */
  (void) memset((void *)&external_mode_DW, 0,
                sizeof(DW_external_mode_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  external_mode_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;
}

/* Model terminate function */
void external_mode_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
