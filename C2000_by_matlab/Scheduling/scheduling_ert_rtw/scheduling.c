/*
 * File: scheduling.c
 *
 * Code generated for Simulink model 'scheduling'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Apr  3 17:43:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "scheduling.h"
#include "scheduling_private.h"
#include "rtwtypes.h"
#include <string.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_scheduling_T scheduling_B;

/* Block states (default storage) */
DW_scheduling_T scheduling_DW;

/* Real-time model */
static RT_MODEL_scheduling_T scheduling_M_;
RT_MODEL_scheduling_T *const scheduling_M = &scheduling_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt' */
void isr_int1pie4_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/Function-Call Subsystem1 */
    {
      /* Reset subsysRan breadcrumbs */
      srClearBC(scheduling_DW.FunctionCallSubsystem1_SubsysRa);

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Function-Call Subsystem1' */

      /* Asynchronous task reads absolute time. Data (absolute time)
         transfers from low priority task (base rate) to high priority
         task (asynchronous rate). Double buffers are used to ensure
         data integrity.
         -- rtmL2HLastBufWr is the buffer index that is written last.
       */
      scheduling_M->Timing.clockTick2 =
        scheduling_M->Timing.rtmL2HDbBufClockTick
        [scheduling_M->Timing.rtmL2HLastBufWr];

      /* UnitDelay: '<S2>/Output' */
      scheduling_B.Output = scheduling_DW.Output_DSTATE;

      /* Sum: '<S3>/FixPt Sum1' incorporates:
       *  Constant: '<S3>/FixPt Constant'
       *  UnitDelay: '<S2>/Output'
       */
      scheduling_DW.Output_DSTATE = (scheduling_B.Output +
        scheduling_P.FixPtConstant_Value) & 255U;

      /* Switch: '<S4>/FixPt Switch' incorporates:
       *  Sum: '<S3>/FixPt Sum1'
       */
      if (scheduling_DW.Output_DSTATE > scheduling_P.WrapToZero_Threshold) {
        /* Update for UnitDelay: '<S2>/Output' incorporates:
         *  Constant: '<S4>/Constant'
         */
        scheduling_DW.Output_DSTATE = scheduling_P.Constant_Value;
      }

      /* End of Switch: '<S4>/FixPt Switch' */
      scheduling_DW.FunctionCallSubsystem1_SubsysRa = 4;

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }

    currentTime = (extmodeSimulationTime_T) scheduling_M->Timing.clockTick0;
    extmodeEvent(2,currentTime);
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void scheduling_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(scheduling_M, 1));
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
  (scheduling_M->Timing.TaskCounters.TID[1])++;
  if ((scheduling_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [1.0s, 0.0s] */
    scheduling_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function for TID0 */
void scheduling_step0(void)            /* Sample time: [0.1s, 0.0s] */
{
  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* S-Function (c2802xadc): '<Root>/ADC' */
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

    scheduling_B.ADC = (AdcaResultRegs.ADCRESULT0);
  }

  /* S-Function (c280xgpio_di): '<Root>/Digital Input' */
  {
    scheduling_B.DigitalInput = GpioDataRegs.GPADAT.bit.GPIO1;
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  scheduling_M->Timing.taskTime0 =
    ((time_T)(++scheduling_M->Timing.clockTick0)) *
    scheduling_M->Timing.stepSize0;

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !(scheduling_M->Timing.rtmL2HLastBufWr != 0U);
    scheduling_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      scheduling_M->Timing.clockTick0;
    scheduling_M->Timing.rtmL2HLastBufWr = bufIdx ? 1U : 0U;
  }
}

/* Model step function for TID1 */
void scheduling_step1(void)            /* Sample time: [1.0s, 0.0s] */
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  scheduling_B.PulseGenerator = (scheduling_DW.clockTickCounter <
    scheduling_P.PulseGenerator_Duty) && (scheduling_DW.clockTickCounter >= 0L) ?
    scheduling_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (scheduling_DW.clockTickCounter >= scheduling_P.PulseGenerator_Period - 1.0)
  {
    scheduling_DW.clockTickCounter = 0L;
  } else {
    scheduling_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (scheduling_B.PulseGenerator) {
      GpioDataRegs.GPASET.bit.GPIO0 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO0 = 1U;
    }
  }

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  scheduling_M->Timing.clockTick1++;
}

/* Model initialize function */
void scheduling_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)scheduling_M, 0,
                sizeof(RT_MODEL_scheduling_T));
  rtmSetTFinal(scheduling_M, -1);
  scheduling_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  scheduling_M->Sizes.checksums[0] = (4032083201U);
  scheduling_M->Sizes.checksums[1] = (2506826127U);
  scheduling_M->Sizes.checksums[2] = (91605182U);
  scheduling_M->Sizes.checksums[3] = (1694417636U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    scheduling_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&scheduling_DW.FunctionCallSubsystem1_SubsysRa;
    systemRan[2] = (sysRanDType *)&scheduling_DW.FunctionCallSubsystem1_SubsysRa;
    rteiSetModelMappingInfoPtr(scheduling_M->extModeInfo,
      &scheduling_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(scheduling_M->extModeInfo, scheduling_M->Sizes.checksums);
    rteiSetTPtr(scheduling_M->extModeInfo, rtmGetTPtr(scheduling_M));
  }

  /* block I/O */
  (void) memset(((void *) &scheduling_B), 0,
                sizeof(B_scheduling_T));

  /* states (dwork) */
  (void) memset((void *)&scheduling_DW, 0,
                sizeof(DW_scheduling_T));

  /* Start for S-Function (c2802xadc): '<Root>/ADC' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC0 ();

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  scheduling_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_di): '<Root>/Digital Input' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFF3U;
  GpioCtrlRegs.GPADIR.all &= 0xFFFFFFFDU;
  EDIS;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX1.all &= 0xFFFFFFFCU;
  GpioCtrlRegs.GPADIR.all |= 0x1U;
  EDIS;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Function-Call Subsystem1'
   */

  /* System initialize for function-call system: '<Root>/Function-Call Subsystem1' */

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  scheduling_M->Timing.clockTick2 = scheduling_M->
    Timing.rtmL2HDbBufClockTick[scheduling_M->Timing.rtmL2HLastBufWr];

  /* InitializeConditions for Sum: '<S3>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S2>/Output'
   */
  scheduling_DW.Output_DSTATE = scheduling_P.Output_InitialCondition;

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
}

/* Model terminate function */
void scheduling_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
