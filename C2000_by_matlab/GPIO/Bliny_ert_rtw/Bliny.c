/*
 * File: Bliny.c
 *
 * Code generated for Simulink model 'Bliny'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Apr  2 11:45:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Bliny.h"
#include <string.h>

/* Block signals (default storage) */
B_Bliny_T Bliny_B;

/* Block states (default storage) */
DW_Bliny_T Bliny_DW;

/* Real-time model */
static RT_MODEL_Bliny_T Bliny_M_;
RT_MODEL_Bliny_T *const Bliny_M = &Bliny_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void Bliny_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(Bliny_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(Bliny_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Bliny_M->Timing.TaskCounters.TID[1])++;
  if ((Bliny_M->Timing.TaskCounters.TID[1]) > 3) {/* Sample time: [0.4s, 0.0s] */
    Bliny_M->Timing.TaskCounters.TID[1] = 0;
  }

  (Bliny_M->Timing.TaskCounters.TID[2])++;
  if ((Bliny_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.5s, 0.0s] */
    Bliny_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void Bliny_step0(void)                 /* Sample time: [0.1s, 0.0s] */
{
  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    if (Bliny_P.Constant_Value) {
      GpioDataRegs.GPASET.bit.GPIO31 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO31 = 1U;
    }
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output3' incorporates:
   *  Constant: '<Root>/Constant3'
   */
  {
    if (Bliny_P.Constant3_Value) {
      GpioDataRegs.GPBSET.bit.GPIO34 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1U;
    }
  }

  /* S-Function (c280xgpio_di): '<Root>/Digital Input' */
  {
    Bliny_B.DigitalInput = GpioDataRegs.GPADAT.bit.GPIO1;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  {
    if (Bliny_B.DigitalInput) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }
}

/* Model step function for TID1 */
void Bliny_step1(void)                 /* Sample time: [0.4s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model step function for TID2 */
void Bliny_step2(void)                 /* Sample time: [0.5s, 0.0s] */
{
  /* (no output/update code required) */
}

/* Model initialize function */
void Bliny_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)Bliny_M, 0,
                sizeof(RT_MODEL_Bliny_T));

  /* block I/O */
  (void) memset(((void *) &Bliny_B), 0,
                sizeof(B_Bliny_T));

  /* states (dwork) */
  (void) memset((void *)&Bliny_DW, 0,
                sizeof(DW_Bliny_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output3' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<Root>/Digital Input' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFF3U;
  GpioCtrlRegs.GPADIR.all &= 0xFFFFFFFDU;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;
}

/* Model terminate function */
void Bliny_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
