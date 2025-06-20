/*
 * File: test_2.c
 *
 * Code generated for Simulink model 'test_2'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Feb 28 20:51:23 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_2.h"
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_test_2_T test_2_B;

/* Block states (default storage) */
DW_test_2_T test_2_DW;

/* Real-time model */
static RT_MODEL_test_2_T test_2_M_;
RT_MODEL_test_2_T *const test_2_M = &test_2_M_;

/* Model step function */
void test_2_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test_2_B.PulseGenerator = (test_2_DW.clockTickCounter <
    test_2_P.PulseGenerator_Duty) && (test_2_DW.clockTickCounter >= 0L) ?
    test_2_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (test_2_DW.clockTickCounter >= test_2_P.PulseGenerator_Period - 1.0) {
    test_2_DW.clockTickCounter = 0L;
  } else {
    test_2_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)(test_2_B.PulseGenerator != 0);
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)(test_2_B.PulseGenerator != 0);
  }
}

/* Model initialize function */
void test_2_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_2_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &test_2_B), 0,
                sizeof(B_test_2_T));

  /* states (dwork) */
  (void) memset((void *)&test_2_DW, 0,
                sizeof(DW_test_2_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  test_2_DW.clockTickCounter = 0L;

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
void test_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
