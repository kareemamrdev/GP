/*
 * File: FOC_2.c
 *
 * Code generated for Simulink model 'FOC_2'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May  6 16:54:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "FOC_2.h"
#include "rtwtypes.h"
#include "FOC_2_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "rt_defines.h"

/* Block signals (default storage) */
B_FOC_2_T FOC_2_B;

/* Block states (default storage) */
DW_FOC_2_T FOC_2_DW;

/* Real-time model */
static RT_MODEL_FOC_2_T FOC_2_M_;
RT_MODEL_FOC_2_T *const FOC_2_M = &FOC_2_M_;
static void rate_monotonic_scheduler(void);
real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    iLeft = 0UL;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1UL;
    iLeft = 0UL;
    iRght = maxIndex;
    while (iRght - iLeft > 1UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1UL;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1UL] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1UL;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (table[iLeft + 1UL] - yL_0d0) * frac + yL_0d0;
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void FOC_2_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(FOC_2_M, 1));
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
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 0 shares data with slower tid rate: 1 */
  FOC_2_M->Timing.RateInteraction.TID0_1 = (FOC_2_M->Timing.TaskCounters.TID[1] ==
    0);

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (FOC_2_M->Timing.TaskCounters.TID[1])++;
  if ((FOC_2_M->Timing.TaskCounters.TID[1]) > 99999) {/* Sample time: [0.1s, 0.0s] */
    FOC_2_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S50>/Switch Case Action Subsystem'
 *    '<S50>/Switch Case Action Subsystem1'
 *    '<S50>/Switch Case Action Subsystem2'
 *    '<S50>/Switch Case Action Subsystem3'
 *    '<S50>/Switch Case Action Subsystem4'
 *    '<S50>/Switch Case Action Subsystem5'
 */
void F_SwitchCaseActionSubsystem(real_T rtu_In1, real_T rtu_In2, real_T rtu_In3,
  real_T *rty_Out1, real_T *rty_Out2, real_T *rty_Out3)
{
  /* SignalConversion generated from: '<S56>/In1' */
  *rty_Out1 = rtu_In1;

  /* SignalConversion generated from: '<S56>/In2' */
  *rty_Out2 = rtu_In2;

  /* SignalConversion generated from: '<S56>/In3' */
  *rty_Out3 = rtu_In3;
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int16_T tmp;
  int16_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u0 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp, tmp_0);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Model step function for TID0 */
void FOC_2_step0(void)                 /* Sample time: [1.0E-6s, 0.0s] */
{
  real_T Merge_tmp;
  real_T rtb_AvoidDividebyZero;
  real_T rtb_DataTypeConversion;
  real_T rtb_DiscreteTimeIntegrator1;
  real_T rtb_K;
  real_T rtb_Lookup;
  boolean_T rtb_LogicalOperator;

  {                                    /* Sample time: [1.0E-6s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(FOC_2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy);

  /* Reset subsysRan breadcrumbs */
  srClearBC(FOC_2_DW.LinearOperation_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(FOC_2_DW.Limitations_SubsysRanBC);

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem3' */
  /* Logic: '<S14>/Logical Operator' incorporates:
   *  Constant: '<S14>/Constant'
   *  Constant: '<S14>/Time constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   *  Sum: '<S14>/Sum1'
   */
  rtb_LogicalOperator = ((FOC_2_P.LowPassFilter_T - FOC_2_B.Probe[0] <=
    FOC_2_P.Constant_Value) && (FOC_2_P.LowPassFilter_init_option <
    FOC_2_P.CompareToConstant_const));

  /* Constant: '<S1>/Constant1' */
  FOC_2_B.Constant1 = FOC_2_P.Constant1_Value;

  /* Gain: '<S3>/K' */
  rtb_K = FOC_2_P.LowPassFilter_K * FOC_2_B.Constant1;

  /* DiscreteIntegrator: '<S20>/Integrator' */
  if (FOC_2_DW.Integrator_IC_LOADING != 0U) {
    FOC_2_DW.Integrator_DSTATE = rtb_K;
    if (FOC_2_DW.Integrator_DSTATE > FOC_2_P.Integrator_UpperSat) {
      FOC_2_DW.Integrator_DSTATE = FOC_2_P.Integrator_UpperSat;
    } else if (FOC_2_DW.Integrator_DSTATE < FOC_2_P.Integrator_LowerSat) {
      FOC_2_DW.Integrator_DSTATE = FOC_2_P.Integrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator || (FOC_2_DW.Integrator_PrevResetState != 0)) {
    FOC_2_DW.Integrator_DSTATE = rtb_K;
    if (FOC_2_DW.Integrator_DSTATE > FOC_2_P.Integrator_UpperSat) {
      FOC_2_DW.Integrator_DSTATE = FOC_2_P.Integrator_UpperSat;
    } else if (FOC_2_DW.Integrator_DSTATE < FOC_2_P.Integrator_LowerSat) {
      FOC_2_DW.Integrator_DSTATE = FOC_2_P.Integrator_LowerSat;
    }
  }

  /* Saturate: '<S20>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S20>/Integrator'
   */
  if (FOC_2_DW.Integrator_DSTATE > FOC_2_P.Saturation_UpperSat) {
    /* Saturate: '<S20>/Saturation' */
    FOC_2_B.Saturation = FOC_2_P.Saturation_UpperSat;
  } else if (FOC_2_DW.Integrator_DSTATE < FOC_2_P.Saturation_LowerSat) {
    /* Saturate: '<S20>/Saturation' */
    FOC_2_B.Saturation = FOC_2_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S20>/Saturation' */
    FOC_2_B.Saturation = FOC_2_DW.Integrator_DSTATE;
  }

  /* End of Saturate: '<S20>/Saturation' */

  /* RateTransition generated from: '<S1>/Scope1' */
  if (FOC_2_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S1>/Scope1' */
    FOC_2_B.TmpRTBAtScope1Inport3 = FOC_2_DW.TmpRTBAtScope1Inport3_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/Scope1' */
  /* RateTransition generated from: '<S1>/Sum2' */
  if (FOC_2_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S1>/Sum2' */
    FOC_2_B.TmpRTBAtSum2Inport2 = FOC_2_DW.TmpRTBAtSum2Inport2_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/Sum2' */

  /* Sum: '<S1>/Sum2' incorporates:
   *  Gain: '<S1>/Gain1'
   */
  rtb_Lookup = FOC_2_P.Gain1_Gain * FOC_2_B.Saturation -
    FOC_2_B.TmpRTBAtSum2Inport2;

  /* DiscreteIntegrator: '<S44>/Integrator' */
  if (FOC_2_DW.Integrator_IC_LOADING_a != 0U) {
    FOC_2_DW.Integrator_DSTATE_j = 0.0;
    if (FOC_2_P.Integrator_UpperSat_n < 0.0) {
      FOC_2_DW.Integrator_DSTATE_j = FOC_2_P.Integrator_UpperSat_n;
    } else if (FOC_2_P.Integrator_LowerSat_k > 0.0) {
      FOC_2_DW.Integrator_DSTATE_j = FOC_2_P.Integrator_LowerSat_k;
    }
  }

  if (FOC_2_DW.Integrator_PrevResetState_a != 0) {
    FOC_2_DW.Integrator_DSTATE_j = 0.0;
    if (FOC_2_P.Integrator_UpperSat_n < 0.0) {
      FOC_2_DW.Integrator_DSTATE_j = FOC_2_P.Integrator_UpperSat_n;
    } else if (FOC_2_P.Integrator_LowerSat_k > 0.0) {
      FOC_2_DW.Integrator_DSTATE_j = FOC_2_P.Integrator_LowerSat_k;
    }
  }

  /* Saturate: '<S44>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S44>/Integrator'
   */
  if (FOC_2_DW.Integrator_DSTATE_j > FOC_2_P.Saturation_UpperSat_b) {
    Merge_tmp = FOC_2_P.Saturation_UpperSat_b;
  } else if (FOC_2_DW.Integrator_DSTATE_j < FOC_2_P.Saturation_LowerSat_d) {
    Merge_tmp = FOC_2_P.Saturation_LowerSat_d;
  } else {
    Merge_tmp = FOC_2_DW.Integrator_DSTATE_j;
  }

  /* Sum: '<S7>/Add' incorporates:
   *  Gain: '<S7>/Gain3'
   *  Saturate: '<S44>/Saturation'
   */
  rtb_DiscreteTimeIntegrator1 = FOC_2_P.Kp_s * rtb_Lookup + Merge_tmp;

  /* Saturate: '<S7>/Saturation' */
  if (rtb_DiscreteTimeIntegrator1 > FOC_2_P.Saturation_UpperSat_f) {
    rtb_DataTypeConversion = FOC_2_P.Saturation_UpperSat_f;
  } else if (rtb_DiscreteTimeIntegrator1 < FOC_2_P.Saturation_LowerSat_c) {
    rtb_DataTypeConversion = FOC_2_P.Saturation_LowerSat_c;
  } else {
    rtb_DataTypeConversion = rtb_DiscreteTimeIntegrator1;
  }

  /* End of Saturate: '<S7>/Saturation' */

  /* Product: '<S7>/Product' incorporates:
   *  Abs: '<S7>/Abs'
   *  Constant: '<S42>/Constant'
   *  Gain: '<S7>/Gain4'
   *  RelationalOperator: '<S42>/Compare'
   *  Sum: '<S7>/Add1'
   */
  rtb_DiscreteTimeIntegrator1 = (real_T)(fabs(rtb_DiscreteTimeIntegrator1 -
    rtb_DataTypeConversion) <= FOC_2_P.CompareToConstant1_const) * (FOC_2_P.Ki_s
    * rtb_Lookup);

  /* RateTransition generated from: '<S1>/Sum' */
  if (FOC_2_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S1>/Sum' */
    FOC_2_B.Iq = FOC_2_DW.Iq_Buffer0;
  }

  /* End of RateTransition generated from: '<S1>/Sum' */

  /* Sum: '<S1>/Sum' incorporates:
   *  Gain: '<S1>/Gain2'
   */
  rtb_DataTypeConversion = 2.0 / (3.0 * FOC_2_P.lambda * FOC_2_P.p) *
    rtb_DataTypeConversion - FOC_2_B.Iq;

  /* Sum: '<S63>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S63>/Discrete-Time Integrator1'
   *  Gain: '<S63>/Gain1'
   */
  FOC_2_B.Sum1 = FOC_2_P.Kp * rtb_DataTypeConversion +
    FOC_2_DW.DiscreteTimeIntegrator1_DSTATE;

  /* RateTransition generated from: '<S2>/Add' incorporates:
   *  RateTransition generated from: '<S12>/Add'
   *  RateTransition generated from: '<S12>/Linear Operation '
   */
  if (FOC_2_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S2>/Add' */
    FOC_2_B.TmpRTBAtAddInport1 = FOC_2_DW.TmpRTBAtAddInport1_Buffer0;

    /* RateTransition generated from: '<S2>/Add' */
    FOC_2_B.TmpRTBAtAddInport2 = FOC_2_DW.TmpRTBAtAddInport2_Buffer0;

    /* RateTransition generated from: '<S12>/Add' */
    FOC_2_B.TmpRTBAtAddInport2_i = FOC_2_DW.TmpRTBAtAddInport2_Buffer0_e;

    /* RateTransition generated from: '<S12>/Linear Operation ' */
    FOC_2_B.TmpRTBAtLinearOperationInport2 =
      FOC_2_DW.TmpRTBAtLinearOperationInport2_;

    /* RateTransition generated from: '<S12>/Limitations' */
    FOC_2_B.Vd = FOC_2_DW.Vd_Buffer0;
  }

  /* End of RateTransition generated from: '<S2>/Add' */

  /* Sum: '<S2>/Add' */
  FOC_2_B.Vq = (FOC_2_B.TmpRTBAtAddInport1 + FOC_2_B.TmpRTBAtAddInport2) +
    FOC_2_B.Sum1;

  /* Outputs for IfAction SubSystem: '<S12>/Limitations' incorporates:
   *  ActionPort: '<S66>/Action Port'
   */
  /* If: '<S12>/If' incorporates:
   *  Constant: '<S12>/Constant'
   *  Gain: '<S12>/Gain'
   *  Math: '<S12>/Square'
   *  Math: '<S66>/Square'
   *  Sqrt: '<S12>/Sqrt'
   *  Sum: '<S12>/Add'
   *  Sum: '<S12>/Subtract'
   */
  Merge_tmp = FOC_2_B.Vq * FOC_2_B.Vq;

  /* End of Outputs for SubSystem: '<S12>/Limitations' */
  if (sqrt(Merge_tmp + FOC_2_B.TmpRTBAtAddInport2_i) - FOC_2_P.Vdc /
      1.7320508075688772 * FOC_2_P.ma <= 0.0) {
    /* Outputs for IfAction SubSystem: '<S12>/Linear Operation ' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    /* Merge: '<S12>/Merge' incorporates:
     *  SignalConversion generated from: '<S67>/Vq_ref1'
     */
    FOC_2_B.Merge = FOC_2_B.Vq;

    /* Merge: '<S12>/Merge1' incorporates:
     *  SignalConversion generated from: '<S67>/Vd_ref1'
     */
    FOC_2_B.Merge1 = FOC_2_B.TmpRTBAtLinearOperationInport2;

    /* End of Outputs for SubSystem: '<S12>/Linear Operation ' */

    /* Update for IfAction SubSystem: '<S12>/Linear Operation ' incorporates:
     *  ActionPort: '<S67>/Action Port'
     */
    /* Update for If: '<S12>/If' */
    srUpdateBC(FOC_2_DW.LinearOperation_SubsysRanBC);

    /* End of Update for SubSystem: '<S12>/Linear Operation ' */
  } else {
    /* Outputs for IfAction SubSystem: '<S12>/Limitations' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    /* Gain: '<S66>/Gain' incorporates:
     *  Math: '<S66>/Square1'
     *  Sqrt: '<S66>/Sqrt'
     *  Sum: '<S66>/Add'
     */
    rtb_Lookup = sqrt(FOC_2_B.Vd * FOC_2_B.Vd + Merge_tmp) * FOC_2_P.Gain_Gain;

    /* Gain: '<S66>/Gain2' incorporates:
     *  Gain: '<S66>/Gain1'
     */
    Merge_tmp = FOC_2_P.Vdc * FOC_2_P.ma;

    /* Merge: '<S12>/Merge' incorporates:
     *  Gain: '<S66>/Gain2'
     *  Product: '<S66>/Product'
     */
    FOC_2_B.Merge = Merge_tmp * FOC_2_B.Vq / rtb_Lookup;

    /* Merge: '<S12>/Merge1' incorporates:
     *  Gain: '<S66>/Gain1'
     *  Product: '<S66>/Product1'
     */
    FOC_2_B.Merge1 = Merge_tmp * FOC_2_B.Vd * (1.0 / rtb_Lookup);

    /* End of Outputs for SubSystem: '<S12>/Limitations' */

    /* Update for IfAction SubSystem: '<S12>/Limitations' incorporates:
     *  ActionPort: '<S66>/Action Port'
     */
    /* Update for If: '<S12>/If' */
    srUpdateBC(FOC_2_DW.Limitations_SubsysRanBC);

    /* End of Update for SubSystem: '<S12>/Limitations' */
  }

  /* End of If: '<S12>/If' */
  /* Product: '<S63>/Product' incorporates:
   *  Gain: '<S63>/Gain2'
   */
  FOC_2_B.Product = FOC_2_P.Ki * rtb_DataTypeConversion * 0.0;

  /* MinMax: '<S14>/Max' incorporates:
   *  Constant: '<S14>/Time constant'
   */
  if ((FOC_2_B.Probe[0] >= FOC_2_P.LowPassFilter_T) || rtIsNaN
      (FOC_2_P.LowPassFilter_T)) {
    rtb_DataTypeConversion = FOC_2_B.Probe[0];
  } else {
    rtb_DataTypeConversion = FOC_2_P.LowPassFilter_T;
  }

  /* End of MinMax: '<S14>/Max' */

  /* Fcn: '<S14>/Avoid Divide by Zero' */
  rtb_AvoidDividebyZero = (real_T)(rtb_DataTypeConversion == 0.0) *
    2.2204460492503131e-16 + rtb_DataTypeConversion;

  /* RateTransition generated from: '<S10>/Product1' incorporates:
   *  RateTransition generated from: '<S10>/Product2'
   *  RateTransition generated from: '<S10>/Product3'
   *  RateTransition generated from: '<S10>/Product'
   */
  if (FOC_2_M->Timing.RateInteraction.TID0_1) {
    /* RateTransition generated from: '<S10>/Product1' */
    FOC_2_B.TmpRTBAtProduct1Inport1 = FOC_2_DW.TmpRTBAtProduct1Inport1_Buffer0;

    /* RateTransition generated from: '<S10>/Product' */
    FOC_2_B.TmpRTBAtProductInport1 = FOC_2_DW.TmpRTBAtProductInport1_Buffer0;

    /* RateTransition generated from: '<S10>/Product3' */
    FOC_2_B.TmpRTBAtProduct3Inport2 = FOC_2_DW.TmpRTBAtProduct3Inport2_Buffer0;

    /* RateTransition generated from: '<S10>/Product2' */
    FOC_2_B.TmpRTBAtProduct2Inport1 = FOC_2_DW.TmpRTBAtProduct2Inport1_Buffer0;
  }

  /* End of RateTransition generated from: '<S10>/Product1' */

  /* Sum: '<S10>/Add' incorporates:
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   */
  FOC_2_B.V_beta = FOC_2_B.TmpRTBAtProduct1Inport1 * FOC_2_B.Merge1 +
    FOC_2_B.TmpRTBAtProductInport1 * FOC_2_B.Merge;

  /* Gain: '<S10>/Gain' incorporates:
   *  Product: '<S10>/Product2'
   *  Product: '<S10>/Product3'
   *  Sum: '<S10>/Add1'
   */
  rtb_DataTypeConversion = (FOC_2_B.TmpRTBAtProduct2Inport1 * FOC_2_B.Merge1 -
    FOC_2_B.Merge * FOC_2_B.TmpRTBAtProduct3Inport2) * FOC_2_P.Gain_Gain_g;

  /* Gain: '<S10>/Gain2' incorporates:
   *  Sum: '<S10>/Add3'
   */
  FOC_2_B.Vb = (rtb_DataTypeConversion - FOC_2_B.V_beta) * FOC_2_P.Gain2_Gain;

  /* Gain: '<S10>/Gain1' incorporates:
   *  Sum: '<S10>/Add2'
   */
  FOC_2_B.Vc = ((0.0 - rtb_DataTypeConversion) - FOC_2_B.V_beta) *
    FOC_2_P.Gain1_Gain_n;

  /* Gain: '<S45>/Gain2' incorporates:
   *  Gain: '<S45>/Gain'
   *  Gain: '<S45>/Gain1'
   *  Sum: '<S45>/Add'
   */
  FOC_2_B.alpha = ((FOC_2_B.V_beta - FOC_2_P.Gain_Gain_f * FOC_2_B.Vb) -
                   FOC_2_P.Gain1_Gain_p * FOC_2_B.Vc) * FOC_2_P.Gain2_Gain_k;

  /* Gain: '<S45>/Gain5' incorporates:
   *  Gain: '<S45>/Gain3'
   *  Gain: '<S45>/Gain4'
   *  Sum: '<S45>/Add1'
   */
  FOC_2_B.beta = (FOC_2_P.Gain3_Gain * FOC_2_B.Vb - FOC_2_P.Gain4_Gain *
                  FOC_2_B.Vc) * FOC_2_P.Gain5_Gain;

  /* Trigonometry: '<S51>/Atan2' */
  FOC_2_B.Atan2 = rt_atan2d_snf(FOC_2_B.alpha, FOC_2_B.beta);

  /* Gain: '<S48>/Gain13' */
  rtb_DataTypeConversion = FOC_2_P.Gain13_Gain * FOC_2_B.Atan2;

  /* Sum: '<S48>/Add3' incorporates:
   *  Constant: '<S48>/Constant12'
   *  Constant: '<S48>/Constant13'
   *  Constant: '<S48>/Constant14'
   *  Constant: '<S48>/Constant15'
   *  Constant: '<S48>/Constant16'
   *  Constant: '<S48>/Constant17'
   *  Constant: '<S48>/Constant18'
   *  Constant: '<S48>/Constant19'
   *  Constant: '<S48>/Constant20'
   *  Constant: '<S48>/Constant21'
   *  Constant: '<S48>/Constant22'
   *  Constant: '<S48>/Constant23'
   *  DataTypeConversion: '<S48>/Data Type Conversion10'
   *  DataTypeConversion: '<S48>/Data Type Conversion11'
   *  DataTypeConversion: '<S48>/Data Type Conversion6'
   *  DataTypeConversion: '<S48>/Data Type Conversion7'
   *  DataTypeConversion: '<S48>/Data Type Conversion8'
   *  DataTypeConversion: '<S48>/Data Type Conversion9'
   *  Gain: '<S48>/Gain14'
   *  Gain: '<S48>/Gain15'
   *  Gain: '<S48>/Gain16'
   *  Gain: '<S48>/Gain17'
   *  Gain: '<S48>/Gain18'
   *  Gain: '<S48>/Gain19'
   *  Logic: '<S48>/AND'
   *  Logic: '<S48>/AND1'
   *  Logic: '<S48>/AND2'
   *  Logic: '<S48>/AND3'
   *  Logic: '<S48>/AND4'
   *  Logic: '<S48>/AND5'
   *  RelationalOperator: '<S48>/Relational Operator12'
   *  RelationalOperator: '<S48>/Relational Operator13'
   *  RelationalOperator: '<S48>/Relational Operator14'
   *  RelationalOperator: '<S48>/Relational Operator15'
   *  RelationalOperator: '<S48>/Relational Operator16'
   *  RelationalOperator: '<S48>/Relational Operator17'
   *  RelationalOperator: '<S48>/Relational Operator18'
   *  RelationalOperator: '<S48>/Relational Operator19'
   *  RelationalOperator: '<S48>/Relational Operator20'
   *  RelationalOperator: '<S48>/Relational Operator21'
   *  RelationalOperator: '<S48>/Relational Operator22'
   *  RelationalOperator: '<S48>/Relational Operator23'
   */
  FOC_2_B.K = (((((real32_T)((rtb_DataTypeConversion >= FOC_2_P.Constant12_Value)
    && (rtb_DataTypeConversion <= FOC_2_P.Constant13_Value)) *
                  FOC_2_P.Gain14_Gain + (real_T)((rtb_DataTypeConversion >=
    FOC_2_P.Constant14_Value) && (rtb_DataTypeConversion <=
    FOC_2_P.Constant15_Value)) * FOC_2_P.Gain15_Gain) + (real_T)
                 ((rtb_DataTypeConversion >= FOC_2_P.Constant16_Value) &&
                  (rtb_DataTypeConversion <= FOC_2_P.Constant17_Value)) *
                 FOC_2_P.Gain16_Gain) + (real_T)((rtb_DataTypeConversion >=
    FOC_2_P.Constant18_Value) && (rtb_DataTypeConversion <=
    FOC_2_P.Constant19_Value)) * FOC_2_P.Gain17_Gain) + (real_T)
               ((rtb_DataTypeConversion >= FOC_2_P.Constant20_Value) &&
                (rtb_DataTypeConversion <= FOC_2_P.Constant21_Value)) *
               FOC_2_P.Gain18_Gain) + (real_T)((rtb_DataTypeConversion >=
    FOC_2_P.Constant22_Value) && (rtb_DataTypeConversion <=
    FOC_2_P.Constant23_Value)) * FOC_2_P.Gain19_Gain;

  /* Sqrt: '<S51>/Square Root' incorporates:
   *  Math: '<S51>/Math Function'
   *  Math: '<S51>/Math Function1'
   *  Sum: '<S51>/Add2'
   */
  FOC_2_B.Vr = sqrt(FOC_2_B.alpha * FOC_2_B.alpha + FOC_2_B.beta * FOC_2_B.beta);

  /* Saturate: '<S51>/Saturation2' */
  FOC_2_B.Saturation2 = 0.95 * FOC_2_P.Vdc / 1.7320508075688772;
  if (!(FOC_2_B.Vr > FOC_2_B.Saturation2)) {
    if (FOC_2_B.Vr < FOC_2_P.Saturation2_LowerSat) {
      /* Saturate: '<S51>/Saturation2' */
      FOC_2_B.Saturation2 = FOC_2_P.Saturation2_LowerSat;
    } else {
      /* Saturate: '<S51>/Saturation2' */
      FOC_2_B.Saturation2 = FOC_2_B.Vr;
    }
  }

  /* End of Saturate: '<S51>/Saturation2' */

  /* Gain: '<S52>/Gain6' incorporates:
   *  Constant: '<S52>/Vdc'
   *  Product: '<S52>/Divide'
   */
  rtb_DataTypeConversion = 1.7320508075688772 * FOC_2_P.T_period *
    (FOC_2_B.Saturation2 / FOC_2_P.Vdc);

  /* Product: '<S52>/Product' incorporates:
   *  Gain: '<S52>/Gain7'
   *  Sum: '<S52>/Add4'
   *  Trigonometry: '<S52>/Sin1'
   */
  FOC_2_B.T1 = sin(FOC_2_P.Gain7_Gain * FOC_2_B.K - FOC_2_B.Atan2) *
    rtb_DataTypeConversion;

  /* Product: '<S52>/Product1' incorporates:
   *  Constant: '<S52>/const'
   *  Gain: '<S52>/Gain8'
   *  Sum: '<S52>/Add5'
   *  Sum: '<S52>/Add6'
   *  Trigonometry: '<S52>/Sin4'
   */
  FOC_2_B.T2 = sin(FOC_2_B.Atan2 - (FOC_2_B.K - FOC_2_P.const_Value) *
                   FOC_2_P.Gain8_Gain) * rtb_DataTypeConversion;

  /* Sum: '<S52>/Add7' incorporates:
   *  Constant: '<S52>/Constant'
   */
  FOC_2_B.Add7 = (FOC_2_P.T_period - FOC_2_B.T1) - FOC_2_B.T2;

  /* SwitchCase: '<S50>/Switch Case' incorporates:
   *  Gain: '<S49>/Gain10'
   *  Gain: '<S49>/Gain11'
   *  Gain: '<S49>/Gain12'
   *  Gain: '<S49>/Gain9'
   *  Sum: '<S49>/Add10'
   *  Sum: '<S49>/Add8'
   *  Sum: '<S49>/Add9'
   */
  if (FOC_2_B.K < 0.0) {
    Merge_tmp = ceil(FOC_2_B.K);
  } else {
    Merge_tmp = floor(FOC_2_B.K);
  }

  if (rtIsNaN(Merge_tmp) || rtIsInf(Merge_tmp)) {
    Merge_tmp = 0.0;
  } else {
    Merge_tmp = fmod(Merge_tmp, 4.294967296E+9);
  }

  switch (Merge_tmp < 0.0 ? -(int32_T)(uint32_T)-Merge_tmp : (int32_T)(uint32_T)
          Merge_tmp) {
   case 1L:
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem' incorporates:
     *  ActionPort: '<S56>/Action Port'
     */
    F_SwitchCaseActionSubsystem((FOC_2_B.T1 + FOC_2_B.T2) + FOC_2_P.Gain9_Gain *
      FOC_2_B.Add7, FOC_2_B.T2 + FOC_2_P.Gain10_Gain * FOC_2_B.Add7,
      FOC_2_P.Gain12_Gain * FOC_2_B.Add7, &FOC_2_B.ref1, &FOC_2_B.ref2,
      &FOC_2_B.Merge2);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem' */
    break;

   case 2L:
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem1' incorporates:
     *  ActionPort: '<S57>/Action Port'
     */
    F_SwitchCaseActionSubsystem(FOC_2_B.T1 + FOC_2_P.Gain11_Gain * FOC_2_B.Add7,
      (FOC_2_B.T1 + FOC_2_B.T2) + FOC_2_P.Gain9_Gain * FOC_2_B.Add7,
      FOC_2_P.Gain12_Gain * FOC_2_B.Add7, &FOC_2_B.ref1, &FOC_2_B.ref2,
      &FOC_2_B.Merge2);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem1' */
    break;

   case 3L:
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem2' incorporates:
     *  ActionPort: '<S58>/Action Port'
     */
    F_SwitchCaseActionSubsystem(FOC_2_P.Gain12_Gain * FOC_2_B.Add7, (FOC_2_B.T1
      + FOC_2_B.T2) + FOC_2_P.Gain9_Gain * FOC_2_B.Add7, FOC_2_B.T2 +
      FOC_2_P.Gain10_Gain * FOC_2_B.Add7, &FOC_2_B.ref1, &FOC_2_B.ref2,
      &FOC_2_B.Merge2);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem2' */
    break;

   case 4L:
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem3' incorporates:
     *  ActionPort: '<S59>/Action Port'
     */
    F_SwitchCaseActionSubsystem(FOC_2_P.Gain12_Gain * FOC_2_B.Add7, FOC_2_B.T1 +
      FOC_2_P.Gain11_Gain * FOC_2_B.Add7, (FOC_2_B.T1 + FOC_2_B.T2) +
      FOC_2_P.Gain9_Gain * FOC_2_B.Add7, &FOC_2_B.ref1, &FOC_2_B.ref2,
      &FOC_2_B.Merge2);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem3' */
    break;

   case 5L:
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem4' incorporates:
     *  ActionPort: '<S60>/Action Port'
     */
    F_SwitchCaseActionSubsystem(FOC_2_B.T2 + FOC_2_P.Gain10_Gain * FOC_2_B.Add7,
      FOC_2_P.Gain12_Gain * FOC_2_B.Add7, (FOC_2_B.T1 + FOC_2_B.T2) +
      FOC_2_P.Gain9_Gain * FOC_2_B.Add7, &FOC_2_B.ref1, &FOC_2_B.ref2,
      &FOC_2_B.Merge2);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem4' */
    break;

   case 6L:
    /* Outputs for IfAction SubSystem: '<S50>/Switch Case Action Subsystem5' incorporates:
     *  ActionPort: '<S61>/Action Port'
     */
    F_SwitchCaseActionSubsystem((FOC_2_B.T1 + FOC_2_B.T2) + FOC_2_P.Gain9_Gain *
      FOC_2_B.Add7, FOC_2_P.Gain12_Gain * FOC_2_B.Add7, FOC_2_B.T1 +
      FOC_2_P.Gain11_Gain * FOC_2_B.Add7, &FOC_2_B.ref1, &FOC_2_B.ref2,
      &FOC_2_B.Merge2);

    /* End of Outputs for SubSystem: '<S50>/Switch Case Action Subsystem5' */
    break;
  }

  /* End of SwitchCase: '<S50>/Switch Case' */
  /* Lookup_n-D: '<S47>/Lookup' incorporates:
   *  DataTypeConversion: '<S47>/Data Type Conversion'
   *  SampleTimeMath: '<S47>/Sample Time Math'
   *  UnitDelay: '<S53>/Output'
   *
   * About '<S47>/Sample Time Math':
   *  y = u * K where K = ( w * Ts )
   *   */
  rtb_Lookup = look1_binlcpw((real_T)FOC_2_DW.Output_DSTATE *
    FOC_2_P.SampleTimeMath_WtEt, FOC_2_P.RepeatingSequenceInterpolated_j,
    FOC_2_P.RepeatingSequenceInterpolated1_, 2UL);

  /* RelationalOperator: '<S46>/Relational Operator' */
  FOC_2_B.RelationalOperator = (FOC_2_B.ref1 >= rtb_Lookup);

  /* RelationalOperator: '<S46>/Relational Operator1' */
  FOC_2_B.RelationalOperator1 = (FOC_2_B.ref2 >= rtb_Lookup);

  /* RelationalOperator: '<S46>/Relational Operator2' */
  FOC_2_B.RelationalOperator2 = (FOC_2_B.Merge2 >= rtb_Lookup);

  /* Sum: '<S54>/FixPt Sum1' incorporates:
   *  Constant: '<S54>/FixPt Constant'
   *  UnitDelay: '<S53>/Output'
   */
  FOC_2_DW.Output_DSTATE = (FOC_2_DW.Output_DSTATE + FOC_2_P.FixPtConstant_Value)
    & 255U;

  /* Switch: '<S55>/FixPt Switch' incorporates:
   *  Constant: '<S55>/Constant'
   *  Sum: '<S54>/FixPt Sum1'
   */
  if (FOC_2_DW.Output_DSTATE > FOC_2_P.WrapToZero_Threshold) {
    FOC_2_DW.Output_DSTATE = FOC_2_P.Constant_Value_e;
  }

  /* End of Switch: '<S55>/FixPt Switch' */
  /* Update for DiscreteIntegrator: '<S20>/Integrator' incorporates:
   *  Product: '<S3>/1//T'
   *  Sum: '<S3>/Sum1'
   */
  FOC_2_DW.Integrator_IC_LOADING = 0U;
  FOC_2_DW.Integrator_DSTATE += 1.0 / rtb_AvoidDividebyZero * (rtb_K -
    FOC_2_B.Saturation) * FOC_2_P.Integrator_gainval;
  if (FOC_2_DW.Integrator_DSTATE > FOC_2_P.Integrator_UpperSat) {
    FOC_2_DW.Integrator_DSTATE = FOC_2_P.Integrator_UpperSat;
  } else if (FOC_2_DW.Integrator_DSTATE < FOC_2_P.Integrator_LowerSat) {
    FOC_2_DW.Integrator_DSTATE = FOC_2_P.Integrator_LowerSat;
  }

  FOC_2_DW.Integrator_PrevResetState = (int16_T)rtb_LogicalOperator;

  /* End of Update for DiscreteIntegrator: '<S20>/Integrator' */

  /* Update for DiscreteIntegrator: '<S44>/Integrator' */
  FOC_2_DW.Integrator_IC_LOADING_a = 0U;
  FOC_2_DW.Integrator_DSTATE_j += FOC_2_P.Integrator_gainval_p *
    rtb_DiscreteTimeIntegrator1;
  if (FOC_2_DW.Integrator_DSTATE_j > FOC_2_P.Integrator_UpperSat_n) {
    FOC_2_DW.Integrator_DSTATE_j = FOC_2_P.Integrator_UpperSat_n;
  } else if (FOC_2_DW.Integrator_DSTATE_j < FOC_2_P.Integrator_LowerSat_k) {
    FOC_2_DW.Integrator_DSTATE_j = FOC_2_P.Integrator_LowerSat_k;
  }

  FOC_2_DW.Integrator_PrevResetState_a = 0;

  /* End of Update for DiscreteIntegrator: '<S44>/Integrator' */

  /* Update for DiscreteIntegrator: '<S63>/Discrete-Time Integrator1' */
  FOC_2_DW.DiscreteTimeIntegrator1_DSTATE +=
    FOC_2_P.DiscreteTimeIntegrator1_gainval * FOC_2_B.Product;

  /* End of Outputs for SubSystem: '<Root>/Subsystem3' */

  /* S-Function (c2802xpwm): '<Root>/ePWM' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(FOC_2_B.RelationalOperator);
  }

  /* S-Function (c2802xpwm): '<Root>/ePWM1' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(FOC_2_B.RelationalOperator1);
  }

  /* S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(FOC_2_B.RelationalOperator2);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++FOC_2_M->Timing.clockTick0)) {
    ++FOC_2_M->Timing.clockTickH0;
  }

  FOC_2_M->Timing.taskTime0 = FOC_2_M->Timing.clockTick0 *
    FOC_2_M->Timing.stepSize0 + FOC_2_M->Timing.clockTickH0 *
    FOC_2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model step function for TID1 */
void FOC_2_step1(void)                 /* Sample time: [0.1s, 0.0s] */
{
  real_T rtb_AvoidDividebyZero_h;
  real_T rtb_Cosine1_g;
  real_T rtb_Cosine_b;
  real_T rtb_DiscreteTimeIntegrator1;
  real_T rtb_Integrator_l;
  real_T rtb_Iq;
  real_T rtb_K_b;
  real_T rtb_K_d;
  real_T rtb_K_p;
  real_T rtb_Max;
  real_T rtb_Product1_i;
  real_T rtb_Product_b;
  real_T rtb_Rem;
  real_T rtb_Saturation;
  real_T rtb_Saturation_e;
  real_T rtb_Saturation_g;
  real_T rtb_Square1;
  real_T rtb_beta;
  int16_T rtb_Compare;
  boolean_T rtb_LogicalOperator_a;
  boolean_T rtb_LogicalOperator_e;
  boolean_T rtb_LogicalOperator_h;
  boolean_T rtb_LogicalOperator_i;

  /* S-Function (c280xgpio_di): '<Root>/Iu_40' */
  {
    FOC_2_B.Iu_40 = GpioDataRegs.GPBDAT.bit.GPIO40;
  }

  /* S-Function (c280xgpio_di): '<Root>/Iv_41' */
  {
    FOC_2_B.Iv_41 = GpioDataRegs.GPBDAT.bit.GPIO41;
  }

  /* S-Function (c280xgpio_di): '<Root>/Iw_52' */
  {
    FOC_2_B.Iw_52 = GpioDataRegs.GPBDAT.bit.GPIO52;
  }

  /* S-Function (c280xgpio_di): '<Root>/Digital Input3' */
  {
    FOC_2_B.DigitalInput3 = GpioDataRegs.GPCDAT.bit.GPIO65;
  }

  /* S-Function (c280xgpio_di): '<Root>/Digital Input4' */
  {
    FOC_2_B.DigitalInput4 = GpioDataRegs.GPCDAT.bit.GPIO94;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Subsystem3' */
  /* Logic: '<S35>/Logical Operator' incorporates:
   *  Constant: '<S35>/Constant'
   *  Constant: '<S35>/Time constant'
   *  Constant: '<S38>/Constant'
   *  Constant: '<S39>/Constant'
   *  RelationalOperator: '<S38>/Compare'
   *  RelationalOperator: '<S39>/Compare'
   *  Sum: '<S35>/Sum1'
   */
  rtb_LogicalOperator_i = ((FOC_2_P.LowPassFilter3_T - FOC_2_B.Probe_m[0] <=
    FOC_2_P.Constant_Value_o) && (FOC_2_P.LowPassFilter3_init_option <
    FOC_2_P.CompareToConstant_const_f));

  /* Gain: '<S6>/K' */
  rtb_K_p = FOC_2_P.LowPassFilter3_K * FOC_2_B.Iw_52;

  /* DiscreteIntegrator: '<S41>/Integrator' */
  if (FOC_2_DW.Integrator_IC_LOADING_e != 0U) {
    FOC_2_DW.Integrator_DSTATE_i = rtb_K_p;
    if (FOC_2_DW.Integrator_DSTATE_i > FOC_2_P.Integrator_UpperSat_d) {
      FOC_2_DW.Integrator_DSTATE_i = FOC_2_P.Integrator_UpperSat_d;
    } else if (FOC_2_DW.Integrator_DSTATE_i < FOC_2_P.Integrator_LowerSat_j) {
      FOC_2_DW.Integrator_DSTATE_i = FOC_2_P.Integrator_LowerSat_j;
    }
  }

  if (rtb_LogicalOperator_i || (FOC_2_DW.Integrator_PrevResetState_h != 0)) {
    FOC_2_DW.Integrator_DSTATE_i = rtb_K_p;
    if (FOC_2_DW.Integrator_DSTATE_i > FOC_2_P.Integrator_UpperSat_d) {
      FOC_2_DW.Integrator_DSTATE_i = FOC_2_P.Integrator_UpperSat_d;
    } else if (FOC_2_DW.Integrator_DSTATE_i < FOC_2_P.Integrator_LowerSat_j) {
      FOC_2_DW.Integrator_DSTATE_i = FOC_2_P.Integrator_LowerSat_j;
    }
  }

  /* Saturate: '<S41>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S41>/Integrator'
   */
  if (FOC_2_DW.Integrator_DSTATE_i > FOC_2_P.Saturation_UpperSat_h) {
    rtb_Saturation = FOC_2_P.Saturation_UpperSat_h;
  } else if (FOC_2_DW.Integrator_DSTATE_i < FOC_2_P.Saturation_LowerSat_l) {
    rtb_Saturation = FOC_2_P.Saturation_LowerSat_l;
  } else {
    rtb_Saturation = FOC_2_DW.Integrator_DSTATE_i;
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* Gain: '<S1>/Gain6' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Sum: '<S1>/Add2'
   */
  rtb_Integrator_l = (rtb_Saturation - FOC_2_P.Constant3_Value) *
    FOC_2_P.Gain6_Gain;

  /* Logic: '<S28>/Logical Operator' incorporates:
   *  Constant: '<S28>/Constant'
   *  Constant: '<S28>/Time constant'
   *  Constant: '<S31>/Constant'
   *  Constant: '<S32>/Constant'
   *  RelationalOperator: '<S31>/Compare'
   *  RelationalOperator: '<S32>/Compare'
   *  Sum: '<S28>/Sum1'
   */
  rtb_LogicalOperator_a = ((FOC_2_P.LowPassFilter2_T - FOC_2_B.Probe_j[0] <=
    FOC_2_P.Constant_Value_i) && (FOC_2_P.LowPassFilter2_init_option <
    FOC_2_P.CompareToConstant_const_o));

  /* Gain: '<S5>/K' */
  rtb_K_b = FOC_2_P.LowPassFilter2_K * FOC_2_B.Iu_40;

  /* DiscreteIntegrator: '<S34>/Integrator' */
  if (FOC_2_DW.Integrator_IC_LOADING_d != 0U) {
    FOC_2_DW.Integrator_DSTATE_iy = rtb_K_b;
    if (FOC_2_DW.Integrator_DSTATE_iy > FOC_2_P.Integrator_UpperSat_f) {
      FOC_2_DW.Integrator_DSTATE_iy = FOC_2_P.Integrator_UpperSat_f;
    } else if (FOC_2_DW.Integrator_DSTATE_iy < FOC_2_P.Integrator_LowerSat_jk) {
      FOC_2_DW.Integrator_DSTATE_iy = FOC_2_P.Integrator_LowerSat_jk;
    }
  }

  if (rtb_LogicalOperator_a || (FOC_2_DW.Integrator_PrevResetState_o != 0)) {
    FOC_2_DW.Integrator_DSTATE_iy = rtb_K_b;
    if (FOC_2_DW.Integrator_DSTATE_iy > FOC_2_P.Integrator_UpperSat_f) {
      FOC_2_DW.Integrator_DSTATE_iy = FOC_2_P.Integrator_UpperSat_f;
    } else if (FOC_2_DW.Integrator_DSTATE_iy < FOC_2_P.Integrator_LowerSat_jk) {
      FOC_2_DW.Integrator_DSTATE_iy = FOC_2_P.Integrator_LowerSat_jk;
    }
  }

  /* Saturate: '<S34>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S34>/Integrator'
   */
  if (FOC_2_DW.Integrator_DSTATE_iy > FOC_2_P.Saturation_UpperSat_a) {
    rtb_Saturation_e = FOC_2_P.Saturation_UpperSat_a;
  } else if (FOC_2_DW.Integrator_DSTATE_iy < FOC_2_P.Saturation_LowerSat_n) {
    rtb_Saturation_e = FOC_2_P.Saturation_LowerSat_n;
  } else {
    rtb_Saturation_e = FOC_2_DW.Integrator_DSTATE_iy;
  }

  /* End of Saturate: '<S34>/Saturation' */

  /* Logic: '<S21>/Logical Operator' incorporates:
   *  Constant: '<S21>/Constant'
   *  Constant: '<S21>/Time constant'
   *  Constant: '<S24>/Constant'
   *  Constant: '<S25>/Constant'
   *  RelationalOperator: '<S24>/Compare'
   *  RelationalOperator: '<S25>/Compare'
   *  Sum: '<S21>/Sum1'
   */
  rtb_LogicalOperator_h = ((FOC_2_P.LowPassFilter1_T - FOC_2_B.Probe_e[0] <=
    FOC_2_P.Constant_Value_m) && (FOC_2_P.LowPassFilter1_init_option <
    FOC_2_P.CompareToConstant_const_m));

  /* Gain: '<S4>/K' */
  rtb_K_d = FOC_2_P.LowPassFilter1_K * FOC_2_B.Iv_41;

  /* DiscreteIntegrator: '<S27>/Integrator' */
  if (FOC_2_DW.Integrator_IC_LOADING_o != 0U) {
    FOC_2_DW.Integrator_DSTATE_b = rtb_K_d;
    if (FOC_2_DW.Integrator_DSTATE_b > FOC_2_P.Integrator_UpperSat_fq) {
      FOC_2_DW.Integrator_DSTATE_b = FOC_2_P.Integrator_UpperSat_fq;
    } else if (FOC_2_DW.Integrator_DSTATE_b < FOC_2_P.Integrator_LowerSat_a) {
      FOC_2_DW.Integrator_DSTATE_b = FOC_2_P.Integrator_LowerSat_a;
    }
  }

  if (rtb_LogicalOperator_h || (FOC_2_DW.Integrator_PrevResetState_d != 0)) {
    FOC_2_DW.Integrator_DSTATE_b = rtb_K_d;
    if (FOC_2_DW.Integrator_DSTATE_b > FOC_2_P.Integrator_UpperSat_fq) {
      FOC_2_DW.Integrator_DSTATE_b = FOC_2_P.Integrator_UpperSat_fq;
    } else if (FOC_2_DW.Integrator_DSTATE_b < FOC_2_P.Integrator_LowerSat_a) {
      FOC_2_DW.Integrator_DSTATE_b = FOC_2_P.Integrator_LowerSat_a;
    }
  }

  /* Saturate: '<S27>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S27>/Integrator'
   */
  if (FOC_2_DW.Integrator_DSTATE_b > FOC_2_P.Saturation_UpperSat_c) {
    rtb_Saturation_g = FOC_2_P.Saturation_UpperSat_c;
  } else if (FOC_2_DW.Integrator_DSTATE_b < FOC_2_P.Saturation_LowerSat_i) {
    rtb_Saturation_g = FOC_2_P.Saturation_LowerSat_i;
  } else {
    rtb_Saturation_g = FOC_2_DW.Integrator_DSTATE_b;
  }

  /* End of Saturate: '<S27>/Saturation' */

  /* Gain: '<S1>/Gain5' incorporates:
   *  Constant: '<S1>/Constant2'
   *  Sum: '<S1>/Add1'
   */
  rtb_beta = (rtb_Saturation_g - FOC_2_P.Constant2_Value) * FOC_2_P.Gain5_Gain_i;

  /* Gain: '<S11>/Gain2' incorporates:
   *  Constant: '<S1>/Constant'
   *  Gain: '<S11>/Gain'
   *  Gain: '<S11>/Gain1'
   *  Gain: '<S1>/Gain3'
   *  Sum: '<S11>/Add2'
   *  Sum: '<S1>/Add'
   */
  rtb_DiscreteTimeIntegrator1 = (((rtb_Saturation_e - FOC_2_P.Constant_Value_c) *
    FOC_2_P.Gain3_Gain_e - FOC_2_P.Gain_Gain_go * rtb_beta) -
    FOC_2_P.Gain1_Gain_f * rtb_Integrator_l) * FOC_2_P.Gain2_Gain_n;

  /* RelationalOperator: '<S71>/Compare' incorporates:
   *  Constant: '<S71>/Constant'
   */
  rtb_Compare = (FOC_2_B.DigitalInput3 > FOC_2_P.Constant_Value_m4);

  /* Switch: '<S13>/Switch' incorporates:
   *  RelationalOperator: '<S68>/FixPt Relational Operator'
   *  RelationalOperator: '<S71>/Compare'
   *  UnitDelay: '<S68>/Delay Input1'
   *
   * Block description for '<S68>/Delay Input1':
   *
   *  Store in Global RAM
   */
  if ((uint16_T)((uint16_T)rtb_Compare > FOC_2_DW.DelayInput1_DSTATE) >
      FOC_2_P.Switch_Threshold) {
    /* Switch: '<S13>/Switch2' incorporates:
     *  DataTypeConversion: '<S13>/Data Type Conversion1'
     */
    if (FOC_2_B.DigitalInput4 > FOC_2_P.Switch2_Threshold) {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant2'
       *  DataTypeConversion: '<S13>/Data Type Conversion'
       *  Gain: '<S13>/Gain1'
       */
      FOC_2_B.Switch = FOC_2_P.Gain1_Gain_b * (real32_T)
        FOC_2_P.Constant2_Value_i;
    } else {
      /* Switch: '<S13>/Switch' incorporates:
       *  Constant: '<S13>/Constant2'
       *  DataTypeConversion: '<S13>/Data Type Conversion'
       *  Gain: '<S13>/Gain'
       */
      FOC_2_B.Switch = FOC_2_P.Gain_Gain_k * (real32_T)FOC_2_P.Constant2_Value_i;
    }

    /* End of Switch: '<S13>/Switch2' */
  } else {
    /* Switch: '<S13>/Switch' incorporates:
     *  Constant: '<S13>/Constant4'
     */
    FOC_2_B.Switch = FOC_2_P.Constant4_Value;
  }

  /* End of Switch: '<S13>/Switch' */

  /* Sum: '<S13>/Add1' incorporates:
   *  UnitDelay: '<S13>/Unit Delay'
   */
  FOC_2_DW.UnitDelay_DSTATE += FOC_2_B.Switch;

  /* Gain: '<S13>/Gain2' incorporates:
   *  UnitDelay: '<S13>/Unit Delay'
   */
  FOC_2_B.Gain2 = FOC_2_P.Gain2_Gain_o * FOC_2_DW.UnitDelay_DSTATE;

  /* Math: '<S13>/Rem' incorporates:
   *  Constant: '<S13>/Constant3'
   *  Gain: '<S13>/Gain3'
   */
  rtb_Rem = fmod(FOC_2_P.Gain3_Gain_a * FOC_2_B.Gain2, FOC_2_P.Constant3_Value_h);

  /* Gain: '<S11>/Gain5' incorporates:
   *  Gain: '<S11>/Gain3'
   *  Gain: '<S11>/Gain4'
   *  Sum: '<S11>/Add3'
   */
  rtb_beta = (FOC_2_P.Gain3_Gain_c * rtb_beta - FOC_2_P.Gain4_Gain_g *
              rtb_Integrator_l) * FOC_2_P.Gain5_Gain_ij;

  /* Trigonometry: '<S11>/Cosine1' incorporates:
   *  Trigonometry: '<S10>/Cosine'
   *  Trigonometry: '<S10>/Sin1'
   *  Trigonometry: '<S11>/Cosine'
   */
  rtb_Cosine_b = cos(rtb_Rem);

  /* Trigonometry: '<S11>/Sin1' incorporates:
   *  Trigonometry: '<S10>/Cosine1'
   *  Trigonometry: '<S10>/Sin'
   *  Trigonometry: '<S11>/Sin'
   */
  rtb_Cosine1_g = sin(rtb_Rem);

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product2'
   *  Product: '<S11>/Product3'
   *  Trigonometry: '<S11>/Cosine1'
   *  Trigonometry: '<S11>/Sin1'
   */
  rtb_Iq = rtb_Cosine_b * rtb_beta - rtb_DiscreteTimeIntegrator1 * rtb_Cosine1_g;

  /* Logic: '<S72>/Logical Operator' incorporates:
   *  Constant: '<S72>/Constant'
   *  Constant: '<S72>/Time constant'
   *  Constant: '<S75>/Constant'
   *  Constant: '<S76>/Constant'
   *  RelationalOperator: '<S75>/Compare'
   *  RelationalOperator: '<S76>/Compare'
   *  Sum: '<S72>/Sum1'
   */
  rtb_LogicalOperator_e = ((FOC_2_P.LowPassFilter_T_k - FOC_2_B.Probe_k[0] <=
    FOC_2_P.Constant_Value_p) && (FOC_2_P.LowPassFilter_init_option_f <
    FOC_2_P.CompareToConstant_const_l));

  /* SampleTimeMath: '<S69>/TSamp'
   *
   * About '<S69>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_Rem = FOC_2_B.Gain2 * FOC_2_P.TSamp_WtEt;

  /* Gain: '<S70>/K' incorporates:
   *  Sum: '<S69>/Diff'
   *  UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  rtb_Integrator_l = (rtb_Rem - FOC_2_DW.UD_DSTATE) * FOC_2_P.LowPassFilter_K_g;

  /* DiscreteIntegrator: '<S78>/Integrator' */
  if (FOC_2_DW.Integrator_IC_LOADING_h != 0U) {
    FOC_2_DW.Integrator_DSTATE_o = rtb_Integrator_l;
    if (FOC_2_DW.Integrator_DSTATE_o > FOC_2_P.Integrator_UpperSat_k) {
      FOC_2_DW.Integrator_DSTATE_o = FOC_2_P.Integrator_UpperSat_k;
    } else if (FOC_2_DW.Integrator_DSTATE_o < FOC_2_P.Integrator_LowerSat_jn) {
      FOC_2_DW.Integrator_DSTATE_o = FOC_2_P.Integrator_LowerSat_jn;
    }
  }

  if (rtb_LogicalOperator_e || (FOC_2_DW.Integrator_PrevResetState_m != 0)) {
    FOC_2_DW.Integrator_DSTATE_o = rtb_Integrator_l;
    if (FOC_2_DW.Integrator_DSTATE_o > FOC_2_P.Integrator_UpperSat_k) {
      FOC_2_DW.Integrator_DSTATE_o = FOC_2_P.Integrator_UpperSat_k;
    } else if (FOC_2_DW.Integrator_DSTATE_o < FOC_2_P.Integrator_LowerSat_jn) {
      FOC_2_DW.Integrator_DSTATE_o = FOC_2_P.Integrator_LowerSat_jn;
    }
  }

  /* Saturate: '<S78>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S78>/Integrator'
   */
  if (FOC_2_DW.Integrator_DSTATE_o > FOC_2_P.Saturation_UpperSat_al) {
    /* Saturate: '<S78>/Saturation' */
    FOC_2_B.Saturation_h = FOC_2_P.Saturation_UpperSat_al;
  } else if (FOC_2_DW.Integrator_DSTATE_o < FOC_2_P.Saturation_LowerSat_a) {
    /* Saturate: '<S78>/Saturation' */
    FOC_2_B.Saturation_h = FOC_2_P.Saturation_LowerSat_a;
  } else {
    /* Saturate: '<S78>/Saturation' */
    FOC_2_B.Saturation_h = FOC_2_DW.Integrator_DSTATE_o;
  }

  /* End of Saturate: '<S78>/Saturation' */

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<S2>/Constant2'
   */
  rtb_Product1_i = FOC_2_B.Saturation_h * rtb_Iq * FOC_2_P.L;

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  rtb_Product_b = FOC_2_B.Saturation_h * FOC_2_P.lambda;

  /* MinMax: '<S72>/Max' incorporates:
   *  Constant: '<S72>/Time constant'
   */
  if ((FOC_2_B.Probe_k[0] >= FOC_2_P.LowPassFilter_T_k) || rtIsNaN
      (FOC_2_P.LowPassFilter_T_k)) {
    rtb_Max = FOC_2_B.Probe_k[0];
  } else {
    rtb_Max = FOC_2_P.LowPassFilter_T_k;
  }

  /* End of MinMax: '<S72>/Max' */

  /* Fcn: '<S72>/Avoid Divide by Zero' */
  rtb_AvoidDividebyZero_h = (real_T)(rtb_Max == 0.0) * 2.2204460492503131e-16 +
    rtb_Max;

  /* Sum: '<S11>/Add' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   */
  rtb_Max = rtb_DiscreteTimeIntegrator1 * rtb_Cosine_b + rtb_Cosine1_g *
    rtb_beta;

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  rtb_beta = FOC_2_B.Saturation_h * rtb_Max * FOC_2_P.L;

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S1>/Id_Ref'
   */
  rtb_Max = FOC_2_P.Id_Ref_Value - rtb_Max;

  /* Sum: '<S62>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S62>/Discrete-Time Integrator1'
   *  Gain: '<S62>/Gain1'
   */
  FOC_2_B.Sum1_c = FOC_2_P.Kp * rtb_Max +
    FOC_2_DW.DiscreteTimeIntegrator1_DSTAT_b;

  /* Sum: '<S2>/Add1' */
  FOC_2_B.Vd_d = FOC_2_B.Sum1_c - rtb_beta;

  /* Math: '<S12>/Square1' */
  rtb_Square1 = FOC_2_B.Vd_d * FOC_2_B.Vd_d;

  /* Product: '<S62>/Product' incorporates:
   *  Gain: '<S62>/Gain2'
   */
  FOC_2_B.Product_o = FOC_2_P.Ki * rtb_Max * 0.0;

  /* Gain: '<S1>/Gain4' */
  FOC_2_B.Gain4 = FOC_2_P.Gain4_Gain_l * FOC_2_B.Saturation_h;

  /* MinMax: '<S21>/Max' incorporates:
   *  Constant: '<S21>/Time constant'
   */
  if ((FOC_2_B.Probe_e[0] >= FOC_2_P.LowPassFilter1_T) || rtIsNaN
      (FOC_2_P.LowPassFilter1_T)) {
    rtb_Max = FOC_2_B.Probe_e[0];
  } else {
    rtb_Max = FOC_2_P.LowPassFilter1_T;
  }

  /* End of MinMax: '<S21>/Max' */

  /* Fcn: '<S21>/Avoid Divide by Zero' */
  rtb_beta = (real_T)(rtb_Max == 0.0) * 2.2204460492503131e-16 + rtb_Max;

  /* MinMax: '<S28>/Max' incorporates:
   *  Constant: '<S28>/Time constant'
   */
  if ((FOC_2_B.Probe_j[0] >= FOC_2_P.LowPassFilter2_T) || rtIsNaN
      (FOC_2_P.LowPassFilter2_T)) {
    rtb_Max = FOC_2_B.Probe_j[0];
  } else {
    rtb_Max = FOC_2_P.LowPassFilter2_T;
  }

  /* End of MinMax: '<S28>/Max' */

  /* Fcn: '<S28>/Avoid Divide by Zero' */
  rtb_DiscreteTimeIntegrator1 = (real_T)(rtb_Max == 0.0) *
    2.2204460492503131e-16 + rtb_Max;

  /* MinMax: '<S35>/Max' incorporates:
   *  Constant: '<S35>/Time constant'
   */
  if ((FOC_2_B.Probe_m[0] >= FOC_2_P.LowPassFilter3_T) || rtIsNaN
      (FOC_2_P.LowPassFilter3_T)) {
    rtb_Max = FOC_2_B.Probe_m[0];
  } else {
    rtb_Max = FOC_2_P.LowPassFilter3_T;
  }

  /* End of MinMax: '<S35>/Max' */

  /* Update for RateTransition generated from: '<S1>/Scope1' */
  FOC_2_DW.TmpRTBAtScope1Inport3_Buffer0 = FOC_2_B.Gain4;

  /* Update for RateTransition generated from: '<S1>/Sum2' */
  FOC_2_DW.TmpRTBAtSum2Inport2_Buffer0 = FOC_2_B.Saturation_h;

  /* Update for RateTransition generated from: '<S1>/Sum' */
  FOC_2_DW.Iq_Buffer0 = rtb_Iq;

  /* Update for RateTransition generated from: '<S2>/Add' */
  FOC_2_DW.TmpRTBAtAddInport1_Buffer0 = rtb_Product_b;

  /* Update for RateTransition generated from: '<S2>/Add' */
  FOC_2_DW.TmpRTBAtAddInport2_Buffer0 = rtb_Product1_i;

  /* Update for RateTransition generated from: '<S12>/Add' */
  FOC_2_DW.TmpRTBAtAddInport2_Buffer0_e = rtb_Square1;

  /* Update for RateTransition generated from: '<S12>/Linear Operation ' */
  FOC_2_DW.TmpRTBAtLinearOperationInport2_ = FOC_2_B.Vd_d;

  /* Update for RateTransition generated from: '<S12>/Limitations' */
  FOC_2_DW.Vd_Buffer0 = FOC_2_B.Vd_d;

  /* Update for RateTransition generated from: '<S10>/Product1' */
  FOC_2_DW.TmpRTBAtProduct1Inport1_Buffer0 = rtb_Cosine1_g;

  /* Update for RateTransition generated from: '<S10>/Product' */
  FOC_2_DW.TmpRTBAtProductInport1_Buffer0 = rtb_Cosine_b;

  /* Update for RateTransition generated from: '<S10>/Product3' */
  FOC_2_DW.TmpRTBAtProduct3Inport2_Buffer0 = rtb_Cosine1_g;

  /* Update for RateTransition generated from: '<S10>/Product2' */
  FOC_2_DW.TmpRTBAtProduct2Inport1_Buffer0 = rtb_Cosine_b;

  /* Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
   *  Fcn: '<S35>/Avoid Divide by Zero'
   *  Product: '<S6>/1//T'
   *  Sum: '<S6>/Sum1'
   */
  FOC_2_DW.Integrator_IC_LOADING_e = 0U;
  FOC_2_DW.Integrator_DSTATE_i += 1.0 / ((real_T)(rtb_Max == 0.0) *
    2.2204460492503131e-16 + rtb_Max) * (rtb_K_p - rtb_Saturation) *
    FOC_2_P.Integrator_gainval_j;
  if (FOC_2_DW.Integrator_DSTATE_i > FOC_2_P.Integrator_UpperSat_d) {
    FOC_2_DW.Integrator_DSTATE_i = FOC_2_P.Integrator_UpperSat_d;
  } else if (FOC_2_DW.Integrator_DSTATE_i < FOC_2_P.Integrator_LowerSat_j) {
    FOC_2_DW.Integrator_DSTATE_i = FOC_2_P.Integrator_LowerSat_j;
  }

  FOC_2_DW.Integrator_PrevResetState_h = (int16_T)rtb_LogicalOperator_i;

  /* End of Update for DiscreteIntegrator: '<S41>/Integrator' */

  /* Update for DiscreteIntegrator: '<S34>/Integrator' incorporates:
   *  Product: '<S5>/1//T'
   *  Sum: '<S5>/Sum1'
   */
  FOC_2_DW.Integrator_IC_LOADING_d = 0U;
  FOC_2_DW.Integrator_DSTATE_iy += 1.0 / rtb_DiscreteTimeIntegrator1 * (rtb_K_b
    - rtb_Saturation_e) * FOC_2_P.Integrator_gainval_n;
  if (FOC_2_DW.Integrator_DSTATE_iy > FOC_2_P.Integrator_UpperSat_f) {
    FOC_2_DW.Integrator_DSTATE_iy = FOC_2_P.Integrator_UpperSat_f;
  } else if (FOC_2_DW.Integrator_DSTATE_iy < FOC_2_P.Integrator_LowerSat_jk) {
    FOC_2_DW.Integrator_DSTATE_iy = FOC_2_P.Integrator_LowerSat_jk;
  }

  FOC_2_DW.Integrator_PrevResetState_o = (int16_T)rtb_LogicalOperator_a;

  /* End of Update for DiscreteIntegrator: '<S34>/Integrator' */

  /* Update for DiscreteIntegrator: '<S27>/Integrator' incorporates:
   *  Product: '<S4>/1//T'
   *  Sum: '<S4>/Sum1'
   */
  FOC_2_DW.Integrator_IC_LOADING_o = 0U;
  FOC_2_DW.Integrator_DSTATE_b += 1.0 / rtb_beta * (rtb_K_d - rtb_Saturation_g) *
    FOC_2_P.Integrator_gainval_m;
  if (FOC_2_DW.Integrator_DSTATE_b > FOC_2_P.Integrator_UpperSat_fq) {
    FOC_2_DW.Integrator_DSTATE_b = FOC_2_P.Integrator_UpperSat_fq;
  } else if (FOC_2_DW.Integrator_DSTATE_b < FOC_2_P.Integrator_LowerSat_a) {
    FOC_2_DW.Integrator_DSTATE_b = FOC_2_P.Integrator_LowerSat_a;
  }

  FOC_2_DW.Integrator_PrevResetState_d = (int16_T)rtb_LogicalOperator_h;

  /* End of Update for DiscreteIntegrator: '<S27>/Integrator' */

  /* Update for UnitDelay: '<S68>/Delay Input1' incorporates:
   *  RelationalOperator: '<S71>/Compare'
   *
   * Block description for '<S68>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FOC_2_DW.DelayInput1_DSTATE = (uint16_T)rtb_Compare;

  /* Update for UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  FOC_2_DW.UD_DSTATE = rtb_Rem;

  /* Update for DiscreteIntegrator: '<S78>/Integrator' incorporates:
   *  Product: '<S70>/1//T'
   *  Sum: '<S70>/Sum1'
   */
  FOC_2_DW.Integrator_IC_LOADING_h = 0U;
  FOC_2_DW.Integrator_DSTATE_o += 1.0 / rtb_AvoidDividebyZero_h *
    (rtb_Integrator_l - FOC_2_B.Saturation_h) * FOC_2_P.Integrator_gainval_o;
  if (FOC_2_DW.Integrator_DSTATE_o > FOC_2_P.Integrator_UpperSat_k) {
    FOC_2_DW.Integrator_DSTATE_o = FOC_2_P.Integrator_UpperSat_k;
  } else if (FOC_2_DW.Integrator_DSTATE_o < FOC_2_P.Integrator_LowerSat_jn) {
    FOC_2_DW.Integrator_DSTATE_o = FOC_2_P.Integrator_LowerSat_jn;
  }

  FOC_2_DW.Integrator_PrevResetState_m = (int16_T)rtb_LogicalOperator_e;

  /* End of Update for DiscreteIntegrator: '<S78>/Integrator' */

  /* Update for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  FOC_2_DW.DiscreteTimeIntegrator1_DSTAT_b +=
    FOC_2_P.DiscreteTimeIntegrator1_gainv_m * FOC_2_B.Product_o;

  /* End of Outputs for SubSystem: '<Root>/Subsystem3' */

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.1, which is the step size
   * of the task. Size of "clockTick1" ensures timer will not overflow during the
   * application lifespan selected.
   */
  FOC_2_M->Timing.clockTick1++;
}

/* Model initialize function */
void FOC_2_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  FOC_2_P.Integrator_UpperSat = rtInf;
  FOC_2_P.Integrator_LowerSat = rtMinusInf;
  FOC_2_P.Saturation_UpperSat = rtInf;
  FOC_2_P.Saturation_LowerSat = rtMinusInf;
  FOC_2_P.Integrator_LowerSat_k = rtMinusInf;
  FOC_2_P.Saturation_UpperSat_b = rtInf;
  FOC_2_P.Saturation_LowerSat_d = rtMinusInf;
  FOC_2_P.Integrator_UpperSat_d = rtInf;
  FOC_2_P.Integrator_LowerSat_j = rtMinusInf;
  FOC_2_P.Saturation_UpperSat_h = rtInf;
  FOC_2_P.Saturation_LowerSat_l = rtMinusInf;
  FOC_2_P.Integrator_UpperSat_f = rtInf;
  FOC_2_P.Integrator_LowerSat_jk = rtMinusInf;
  FOC_2_P.Saturation_UpperSat_a = rtInf;
  FOC_2_P.Saturation_LowerSat_n = rtMinusInf;
  FOC_2_P.Integrator_UpperSat_fq = rtInf;
  FOC_2_P.Integrator_LowerSat_a = rtMinusInf;
  FOC_2_P.Saturation_UpperSat_c = rtInf;
  FOC_2_P.Saturation_LowerSat_i = rtMinusInf;
  FOC_2_P.Integrator_UpperSat_k = rtInf;
  FOC_2_P.Integrator_LowerSat_jn = rtMinusInf;
  FOC_2_P.Saturation_UpperSat_al = rtInf;
  FOC_2_P.Saturation_LowerSat_a = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)FOC_2_M, 0,
                sizeof(RT_MODEL_FOC_2_T));
  rtmSetTFinal(FOC_2_M, -1);
  FOC_2_M->Timing.stepSize0 = 1.0E-6;

  /* External mode info */
  FOC_2_M->Sizes.checksums[0] = (283693136U);
  FOC_2_M->Sizes.checksums[1] = (1858918177U);
  FOC_2_M->Sizes.checksums[2] = (33981398U);
  FOC_2_M->Sizes.checksums[3] = (1938795305U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[15];
    FOC_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)
      &FOC_2_DW.SwitchCaseActionSubsystem.SwitchCaseActionSubsystem_Subsy;
    systemRan[3] = (sysRanDType *)
      &FOC_2_DW.SwitchCaseActionSubsystem1.SwitchCaseActionSubsystem_Subsy;
    systemRan[4] = (sysRanDType *)
      &FOC_2_DW.SwitchCaseActionSubsystem2.SwitchCaseActionSubsystem_Subsy;
    systemRan[5] = (sysRanDType *)
      &FOC_2_DW.SwitchCaseActionSubsystem3.SwitchCaseActionSubsystem_Subsy;
    systemRan[6] = (sysRanDType *)
      &FOC_2_DW.SwitchCaseActionSubsystem4.SwitchCaseActionSubsystem_Subsy;
    systemRan[7] = (sysRanDType *)
      &FOC_2_DW.SwitchCaseActionSubsystem5.SwitchCaseActionSubsystem_Subsy;
    systemRan[8] = (sysRanDType *)&FOC_2_DW.Limitations_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&FOC_2_DW.LinearOperation_SubsysRanBC;
    systemRan[10] = &rtAlwaysEnabled;
    systemRan[11] = &rtAlwaysEnabled;
    systemRan[12] = &rtAlwaysEnabled;
    systemRan[13] = &rtAlwaysEnabled;
    systemRan[14] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(FOC_2_M->extModeInfo,
      &FOC_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(FOC_2_M->extModeInfo, FOC_2_M->Sizes.checksums);
    rteiSetTPtr(FOC_2_M->extModeInfo, rtmGetTPtr(FOC_2_M));
  }

  /* block I/O */
  (void) memset(((void *) &FOC_2_B), 0,
                sizeof(B_FOC_2_T));

  /* states (dwork) */
  (void) memset((void *)&FOC_2_DW, 0,
                sizeof(DW_FOC_2_T));

  /* Start for S-Function (c280xgpio_di): '<Root>/Iu_40' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFCFFFFU;
  GpioCtrlRegs.GPBDIR.all &= 0xFFFFFEFFU;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<Root>/Iv_41' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFF3FFFFU;
  GpioCtrlRegs.GPBDIR.all &= 0xFFFFFDFFU;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<Root>/Iw_52' */
  EALLOW;
  GpioCtrlRegs.GPBMUX2.all &= 0xFFFFFCFFU;
  GpioCtrlRegs.GPBDIR.all &= 0xFFEFFFFFU;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<Root>/Digital Input3' */
  EALLOW;
  GpioCtrlRegs.GPCMUX1.all &= 0xFFFFFFF3U;
  GpioCtrlRegs.GPCDIR.all &= 0xFFFFFFFDU;
  EDIS;

  /* Start for S-Function (c280xgpio_di): '<Root>/Digital Input4' */
  EALLOW;
  GpioCtrlRegs.GPCMUX2.all &= 0xCFFFFFFFU;
  GpioCtrlRegs.GPCDIR.all &= 0xBFFFFFFFU;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm1Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x32U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 10000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 96U;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(400.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(400.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM1' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm2Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x32U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 10000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 96U;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(400.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(400.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*** Initialize ePWM3 modules ***/
  {
    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm3Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x32U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 10000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 96U;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(400.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(400.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for Probe: '<S14>/Probe' */
  FOC_2_B.Probe[0] = 1.0E-6;
  FOC_2_B.Probe[1] = 0.0;

  /* Start for RateTransition generated from: '<S1>/Scope1' */
  FOC_2_B.TmpRTBAtScope1Inport3 = FOC_2_P.TmpRTBAtScope1Inport3_InitialCo;

  /* Start for RateTransition generated from: '<S1>/Sum2' */
  FOC_2_B.TmpRTBAtSum2Inport2 = FOC_2_P.TmpRTBAtSum2Inport2_InitialCond;

  /* Start for RateTransition generated from: '<S1>/Sum' */
  FOC_2_B.Iq = FOC_2_P.Iq_InitialCondition;

  /* Start for RateTransition generated from: '<S2>/Add' */
  FOC_2_B.TmpRTBAtAddInport1 = FOC_2_P.TmpRTBAtAddInport1_InitialCondi;

  /* Start for RateTransition generated from: '<S2>/Add' */
  FOC_2_B.TmpRTBAtAddInport2 = FOC_2_P.TmpRTBAtAddInport2_InitialCondi;

  /* Start for RateTransition generated from: '<S12>/Add' */
  FOC_2_B.TmpRTBAtAddInport2_i = FOC_2_P.TmpRTBAtAddInport2_InitialCon_j;

  /* Start for RateTransition generated from: '<S12>/Linear Operation ' */
  FOC_2_B.TmpRTBAtLinearOperationInport2 =
    FOC_2_P.TmpRTBAtLinearOperationInport2_;

  /* Start for RateTransition generated from: '<S12>/Limitations' */
  FOC_2_B.Vd = FOC_2_P.Vd_InitialCondition;

  /* Start for RateTransition generated from: '<S10>/Product1' */
  FOC_2_B.TmpRTBAtProduct1Inport1 = FOC_2_P.TmpRTBAtProduct1Inport1_Initial;

  /* Start for RateTransition generated from: '<S10>/Product' */
  FOC_2_B.TmpRTBAtProductInport1 = FOC_2_P.TmpRTBAtProductInport1_InitialC;

  /* Start for RateTransition generated from: '<S10>/Product3' */
  FOC_2_B.TmpRTBAtProduct3Inport2 = FOC_2_P.TmpRTBAtProduct3Inport2_Initial;

  /* Start for RateTransition generated from: '<S10>/Product2' */
  FOC_2_B.TmpRTBAtProduct2Inport1 = FOC_2_P.TmpRTBAtProduct2Inport1_Initial;

  /* Start for Probe: '<S72>/Probe' */
  FOC_2_B.Probe_k[0] = 0.1;
  FOC_2_B.Probe_k[1] = 0.0;

  /* Start for Probe: '<S28>/Probe' */
  FOC_2_B.Probe_j[0] = 0.1;
  FOC_2_B.Probe_j[1] = 0.0;

  /* Start for Probe: '<S21>/Probe' */
  FOC_2_B.Probe_e[0] = 0.1;
  FOC_2_B.Probe_e[1] = 0.0;

  /* Start for Probe: '<S35>/Probe' */
  FOC_2_B.Probe_m[0] = 0.1;
  FOC_2_B.Probe_m[1] = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S20>/Integrator' */
  FOC_2_DW.Integrator_PrevResetState = 0;
  FOC_2_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for RateTransition generated from: '<S1>/Scope1' */
  FOC_2_DW.TmpRTBAtScope1Inport3_Buffer0 =
    FOC_2_P.TmpRTBAtScope1Inport3_InitialCo;

  /* InitializeConditions for RateTransition generated from: '<S1>/Sum2' */
  FOC_2_DW.TmpRTBAtSum2Inport2_Buffer0 = FOC_2_P.TmpRTBAtSum2Inport2_InitialCond;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
  FOC_2_DW.Integrator_PrevResetState_a = 0;
  FOC_2_DW.Integrator_IC_LOADING_a = 1U;

  /* InitializeConditions for RateTransition generated from: '<S1>/Sum' */
  FOC_2_DW.Iq_Buffer0 = FOC_2_P.Iq_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S63>/Discrete-Time Integrator1' */
  FOC_2_DW.DiscreteTimeIntegrator1_DSTATE = FOC_2_P.DiscreteTimeIntegrator1_IC;

  /* InitializeConditions for RateTransition generated from: '<S2>/Add' */
  FOC_2_DW.TmpRTBAtAddInport1_Buffer0 = FOC_2_P.TmpRTBAtAddInport1_InitialCondi;

  /* InitializeConditions for RateTransition generated from: '<S2>/Add' */
  FOC_2_DW.TmpRTBAtAddInport2_Buffer0 = FOC_2_P.TmpRTBAtAddInport2_InitialCondi;

  /* InitializeConditions for RateTransition generated from: '<S12>/Add' */
  FOC_2_DW.TmpRTBAtAddInport2_Buffer0_e =
    FOC_2_P.TmpRTBAtAddInport2_InitialCon_j;

  /* InitializeConditions for RateTransition generated from: '<S12>/Linear Operation ' */
  FOC_2_DW.TmpRTBAtLinearOperationInport2_ =
    FOC_2_P.TmpRTBAtLinearOperationInport2_;

  /* InitializeConditions for RateTransition generated from: '<S12>/Limitations' */
  FOC_2_DW.Vd_Buffer0 = FOC_2_P.Vd_InitialCondition;

  /* InitializeConditions for RateTransition generated from: '<S10>/Product1' */
  FOC_2_DW.TmpRTBAtProduct1Inport1_Buffer0 =
    FOC_2_P.TmpRTBAtProduct1Inport1_Initial;

  /* InitializeConditions for RateTransition generated from: '<S10>/Product' */
  FOC_2_DW.TmpRTBAtProductInport1_Buffer0 =
    FOC_2_P.TmpRTBAtProductInport1_InitialC;

  /* InitializeConditions for RateTransition generated from: '<S10>/Product3' */
  FOC_2_DW.TmpRTBAtProduct3Inport2_Buffer0 =
    FOC_2_P.TmpRTBAtProduct3Inport2_Initial;

  /* InitializeConditions for RateTransition generated from: '<S10>/Product2' */
  FOC_2_DW.TmpRTBAtProduct2Inport1_Buffer0 =
    FOC_2_P.TmpRTBAtProduct2Inport1_Initial;

  /* InitializeConditions for Sum: '<S54>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S53>/Output'
   */
  FOC_2_DW.Output_DSTATE = FOC_2_P.Output_InitialCondition;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Integrator' */
  FOC_2_DW.Integrator_PrevResetState_h = 0;
  FOC_2_DW.Integrator_IC_LOADING_e = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S34>/Integrator' */
  FOC_2_DW.Integrator_PrevResetState_o = 0;
  FOC_2_DW.Integrator_IC_LOADING_d = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S27>/Integrator' */
  FOC_2_DW.Integrator_PrevResetState_d = 0;
  FOC_2_DW.Integrator_IC_LOADING_o = 1U;

  /* InitializeConditions for UnitDelay: '<S68>/Delay Input1'
   *
   * Block description for '<S68>/Delay Input1':
   *
   *  Store in Global RAM
   */
  FOC_2_DW.DelayInput1_DSTATE = FOC_2_P.DetectRisePositive_vinit;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  FOC_2_DW.UnitDelay_DSTATE = FOC_2_P.UnitDelay_InitialCondition;

  /* InitializeConditions for UnitDelay: '<S69>/UD'
   *
   * Block description for '<S69>/UD':
   *
   *  Store in Global RAM
   */
  FOC_2_DW.UD_DSTATE = FOC_2_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S78>/Integrator' */
  FOC_2_DW.Integrator_PrevResetState_m = 0;
  FOC_2_DW.Integrator_IC_LOADING_h = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S62>/Discrete-Time Integrator1' */
  FOC_2_DW.DiscreteTimeIntegrator1_DSTAT_b =
    FOC_2_P.DiscreteTimeIntegrator1_IC_c;

  /* SystemInitialize for Merge: '<S50>/Merge' */
  FOC_2_B.ref1 = FOC_2_P.Merge_InitialOutput;

  /* SystemInitialize for Merge: '<S50>/Merge1' */
  FOC_2_B.ref2 = FOC_2_P.Merge1_InitialOutput;

  /* SystemInitialize for Merge: '<S50>/Merge2' */
  FOC_2_B.Merge2 = FOC_2_P.Merge2_InitialOutput;

  /* End of SystemInitialize for SubSystem: '<Root>/Subsystem3' */
}

/* Model terminate function */
void FOC_2_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
