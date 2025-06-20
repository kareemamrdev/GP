/*
 * File: ADC.c
 *
 * Code generated for Simulink model 'ADC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Mar  4 07:34:29 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADC.h"
#include "rtwtypes.h"
#include "ADC_private.h"
#include <string.h>

/* Block signals (default storage) */
B_ADC_T ADC_B;

/* Block states (default storage) */
DW_ADC_T ADC_DW;

/* Real-time model */
static RT_MODEL_ADC_T ADC_M_;
RT_MODEL_ADC_T *const ADC_M = &ADC_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void ADC_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(ADC_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(ADC_M, 2));
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
  (ADC_M->Timing.TaskCounters.TID[1])++;
  if ((ADC_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.001s, 0.0s] */
    ADC_M->Timing.TaskCounters.TID[1] = 0;
  }

  (ADC_M->Timing.TaskCounters.TID[2])++;
  if ((ADC_M->Timing.TaskCounters.TID[2]) > 4999) {/* Sample time: [0.5s, 0.0s] */
    ADC_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void ADC_step0(void)                   /* Sample time: [0.0001s, 0.0s] */
{
  {                                    /* Sample time: [0.0001s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void ADC_step1(void)                   /* Sample time: [0.001s, 0.0s] */
{
  /* S-Function (c2802xadc): '<Root>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcbRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    ADC_B.ADC_l = (AdcbResultRegs.ADCRESULT0);
  }

  /* Buffer: '<Root>/Buffer' */
  ADC_DW.Buffer_inBufPtrIdx++;
  if (ADC_DW.Buffer_inBufPtrIdx >= 1000L) {
    ADC_DW.Buffer_inBufPtrIdx -= 1000L;
  }

  /* End of Buffer: '<Root>/Buffer' */

  /* S-Function (c2802xadc): '<Root>/ADC1' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    ADC_B.ADC1 = (AdcaResultRegs.ADCRESULT0);
  }

  /* Buffer: '<Root>/Buffer1' */
  ADC_DW.Buffer1_inBufPtrIdx++;
  if (ADC_DW.Buffer1_inBufPtrIdx >= 1000L) {
    ADC_DW.Buffer1_inBufPtrIdx -= 1000L;
  }

  /* End of Buffer: '<Root>/Buffer1' */
}

/* Model step function for TID2 */
void ADC_step2(void)                   /* Sample time: [0.5s, 0.0s] */
{
  int32_T currentOffset;

  /* Buffer: '<Root>/Buffer' */
  currentOffset = ADC_DW.Buffer_outBufPtrIdx + 500L;
  if (ADC_DW.Buffer_outBufPtrIdx + 500L == 1000L) {
    currentOffset = 0L;
  }

  ADC_DW.Buffer_outBufPtrIdx = currentOffset;

  /* End of Buffer: '<Root>/Buffer' */

  /* Buffer: '<Root>/Buffer1' */
  currentOffset = ADC_DW.Buffer1_outBufPtrIdx + 500L;
  if (ADC_DW.Buffer1_outBufPtrIdx + 500L == 1000L) {
    currentOffset = 0L;
  }

  ADC_DW.Buffer1_outBufPtrIdx = currentOffset;

  /* End of Buffer: '<Root>/Buffer1' */
}

/* Model initialize function */
void ADC_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ADC_M, 0,
                sizeof(RT_MODEL_ADC_T));

  /* block I/O */
  (void) memset(((void *) &ADC_B), 0,
                sizeof(B_ADC_T));

  /* states (dwork) */
  (void) memset((void *)&ADC_DW, 0,
                sizeof(DW_ADC_T));

  /* Start for S-Function (c2802xadc): '<Root>/ADC' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<Root>/ADC1' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC0 ();

  /* InitializeConditions for Buffer: '<Root>/Buffer' */
  ADC_DW.Buffer_inBufPtrIdx = 500L;
  ADC_DW.Buffer_outBufPtrIdx = 0L;

  /* InitializeConditions for Buffer: '<Root>/Buffer1' */
  ADC_DW.Buffer1_inBufPtrIdx = 500L;
  ADC_DW.Buffer1_outBufPtrIdx = 0L;

  /* ConstCode for S-Function (memorycopy): '<Root>/Memory Copy' */
  {
    uint16_T i1;
    real_T *memindsrc1 = (real_T *) (&ADC_B.Buffer[0]);
    real_T *meminddst1 = (real_T *) (8192U);
    for (i1=0U; i1<500U; i1++) {
      *(real_T *) (meminddst1) = *(real_T *) (memindsrc1);
      meminddst1++;
      memindsrc1++;
    }
  }

  /* ConstCode for S-Function (memorycopy): '<Root>/Memory Copy1' */
  {
    uint16_T i2;
    real_T *memindsrc2 = (real_T *) (&ADC_B.Buffer1[0]);
    real_T *meminddst2 = (real_T *) (8192U);
    for (i2=0U; i2<500U; i2++) {
      *(real_T *) (meminddst2) = *(real_T *) (memindsrc2);
      meminddst2++;
      memindsrc2++;
    }
  }
}

/* Model terminate function */
void ADC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
