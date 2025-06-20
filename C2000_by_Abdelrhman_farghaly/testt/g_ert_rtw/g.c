/*
 * File: g.c
 *
 * Code generated for Simulink model 'g'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Feb 28 18:43:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "g.h"
#include "rtwtypes.h"
#include <string.h>

/* Block signals (default storage) */
B_g_T g_B;

/* Block states (default storage) */
DW_g_T g_DW;

/* Real-time model */
static RT_MODEL_g_T g_M_;
RT_MODEL_g_T *const g_M = &g_M_;

/* Model step function */
void g_step(void)
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  g_B.PulseGenerator = (g_DW.clockTickCounter < g_P.PulseGenerator_Duty) &&
    (g_DW.clockTickCounter >= 0L) ? g_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (g_DW.clockTickCounter >= g_P.PulseGenerator_Period - 1.0) {
    g_DW.clockTickCounter = 0L;
  } else {
    g_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)(g_B.PulseGenerator != 0);
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)(g_B.PulseGenerator != 0);
  }
}

/* Model initialize function */
void g_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(g_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &g_B), 0,
                sizeof(B_g_T));

  /* states (dwork) */
  (void) memset((void *)&g_DW, 0,
                sizeof(DW_g_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  g_DW.clockTickCounter = 0L;

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
void g_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
