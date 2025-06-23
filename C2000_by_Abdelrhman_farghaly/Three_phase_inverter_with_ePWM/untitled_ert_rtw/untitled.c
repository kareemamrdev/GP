/*
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jun 20 15:14:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "untitled_private.h"
#include <string.h>

/* Block signals (default storage) */
B_untitled_T untitled_B;

/* Block states (default storage) */
DW_untitled_T untitled_DW;

/* Real-time model */
static RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;
uint32_T plook_u32u16u64n48_evenc_gf(uint16_T u, uint16_T bp0, uint16_T bpSpace,
  uint32_T maxIndex, uint64_T *fraction)
{
  uint32_T bpIndex;
  uint16_T fbpIndex;
  uint16_T uAdjust;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'floor'
   */
  uAdjust = u - bp0;
  fbpIndex = uAdjust / bpSpace;
  if (fbpIndex < maxIndex) {
    bpIndex = fbpIndex;
    *fraction = ((uint64_T)(uAdjust - fbpIndex * bpSpace) << 48U) / bpSpace;
  } else {
    bpIndex = maxIndex - 1UL;
    *fraction = 281474976710656ULL;
  }

  return bpIndex;
}

int16_T intrp1d_s16s32s32u32u64n48l_f(uint32_T bpIndex, uint64_T frac, const
  int16_T table[])
{
  int16_T yL_0d0;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'floor'
     Overflow mode: 'wrapping'
   */
  yL_0d0 = table[bpIndex];
  return (int16_T)((((int32_T)table[bpIndex + 1UL] - yL_0d0) * (int64_T)frac) >>
                   48U) + yL_0d0;
}

/* Model step function */
void untitled_step(void)
{
  real_T rtb_AvoidDividebyZero;
  real_T rtb_K;
  real_T rtb_Numberofpolepairs;
  real_T rtb_Product;
  real_T rtb_TSamp;
  uint64_T frac;
  uint32_T bpIdx;
  int16_T rtb_SignCorrected_idx_0;
  int16_T rtb_SignCorrected_idx_1;
  int16_T rtb_SignCorrected_idx_2;
  uint16_T bpIdx_tmp;
  uint16_T rtb_Merge;
  uint16_T rtb_QuadHandle2_idx_0;
  uint16_T rtb_QuadHandle2_idx_1;
  boolean_T rtb_LTEp50_idx_0;
  boolean_T rtb_LTEp50_idx_1;
  boolean_T rtb_LogicalOperator;

  /* Reset subsysRan breadcrumbs */
  srClearBC(untitled_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(untitled_DW.IfActionSubsystem1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(untitled_DW.PositionNoReset_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(untitled_DW.PositionResetAtIndex_SubsysRanB);

  /* DataTypeConversion: '<S65>/CastU16En16' incorporates:
   *  Constant: '<S4>/Introducing Phase Shift'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Sum: '<S4>/Add'
   *  Switch: '<S65>/QuadHandle2'
   */
  rtb_TSamp = floor((untitled_DW.DiscreteTimeIntegrator_DSTATE +
                     untitled_P.IntroducingPhaseShift_Value[0]) * 65536.0);
  if (rtIsNaN(rtb_TSamp) || rtIsInf(rtb_TSamp)) {
    rtb_TSamp = 0.0;
  } else {
    rtb_TSamp = fmod(rtb_TSamp, 65536.0);
  }

  rtb_Merge = rtb_TSamp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_TSamp :
    (uint16_T)rtb_TSamp;

  /* RelationalOperator: '<S65>/LTEp50' incorporates:
   *  Constant: '<S65>/Point50'
   *  Switch: '<S65>/QuadHandle2'
   */
  rtb_LogicalOperator = (rtb_Merge <= untitled_P.Point50_Value);
  rtb_LTEp50_idx_0 = rtb_LogicalOperator;

  /* Switch: '<S65>/QuadHandle1' incorporates:
   *  Constant: '<S65>/Point50'
   *  Sum: '<S65>/Amp50'
   *  Switch: '<S65>/QuadHandle2'
   */
  if (!rtb_LogicalOperator) {
    rtb_Merge -= untitled_P.Point50_Value;
  }

  /* Switch: '<S65>/QuadHandle2' incorporates:
   *  Constant: '<S65>/Point25'
   *  Constant: '<S65>/Point50'
   *  RelationalOperator: '<S65>/LTEp25'
   *  Sum: '<S65>/p50mA'
   */
  if (rtb_Merge > untitled_P.Point25_Value) {
    rtb_Merge = untitled_P.Point50_Value - rtb_Merge;
  }

  rtb_QuadHandle2_idx_0 = rtb_Merge;

  /* DataTypeConversion: '<S65>/CastU16En16' incorporates:
   *  Constant: '<S4>/Introducing Phase Shift'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Sum: '<S4>/Add'
   *  Switch: '<S65>/QuadHandle2'
   */
  rtb_TSamp = floor((untitled_DW.DiscreteTimeIntegrator_DSTATE +
                     untitled_P.IntroducingPhaseShift_Value[1]) * 65536.0);
  if (rtIsNaN(rtb_TSamp) || rtIsInf(rtb_TSamp)) {
    rtb_TSamp = 0.0;
  } else {
    rtb_TSamp = fmod(rtb_TSamp, 65536.0);
  }

  rtb_Merge = rtb_TSamp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_TSamp :
    (uint16_T)rtb_TSamp;

  /* RelationalOperator: '<S65>/LTEp50' incorporates:
   *  Constant: '<S65>/Point50'
   *  Switch: '<S65>/QuadHandle2'
   */
  rtb_LogicalOperator = (rtb_Merge <= untitled_P.Point50_Value);
  rtb_LTEp50_idx_1 = rtb_LogicalOperator;

  /* Switch: '<S65>/QuadHandle1' incorporates:
   *  Constant: '<S65>/Point50'
   *  Sum: '<S65>/Amp50'
   *  Switch: '<S65>/QuadHandle2'
   */
  if (!rtb_LogicalOperator) {
    rtb_Merge -= untitled_P.Point50_Value;
  }

  /* Switch: '<S65>/QuadHandle2' incorporates:
   *  Constant: '<S65>/Point25'
   *  Constant: '<S65>/Point50'
   *  RelationalOperator: '<S65>/LTEp25'
   *  Sum: '<S65>/p50mA'
   */
  if (rtb_Merge > untitled_P.Point25_Value) {
    rtb_Merge = untitled_P.Point50_Value - rtb_Merge;
  }

  rtb_QuadHandle2_idx_1 = rtb_Merge;

  /* DataTypeConversion: '<S65>/CastU16En16' incorporates:
   *  Constant: '<S4>/Introducing Phase Shift'
   *  DiscreteIntegrator: '<S4>/Discrete-Time Integrator'
   *  Sum: '<S4>/Add'
   *  Switch: '<S65>/QuadHandle2'
   */
  rtb_TSamp = floor((untitled_DW.DiscreteTimeIntegrator_DSTATE +
                     untitled_P.IntroducingPhaseShift_Value[2]) * 65536.0);
  if (rtIsNaN(rtb_TSamp) || rtIsInf(rtb_TSamp)) {
    rtb_TSamp = 0.0;
  } else {
    rtb_TSamp = fmod(rtb_TSamp, 65536.0);
  }

  rtb_Merge = rtb_TSamp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-rtb_TSamp :
    (uint16_T)rtb_TSamp;

  /* RelationalOperator: '<S65>/LTEp50' incorporates:
   *  Constant: '<S65>/Point50'
   *  Switch: '<S65>/QuadHandle2'
   */
  rtb_LogicalOperator = (rtb_Merge <= untitled_P.Point50_Value);

  /* Switch: '<S65>/QuadHandle1' incorporates:
   *  Constant: '<S65>/Point50'
   *  Sum: '<S65>/Amp50'
   *  Switch: '<S65>/QuadHandle2'
   */
  if (!rtb_LogicalOperator) {
    rtb_Merge -= untitled_P.Point50_Value;
  }

  /* Switch: '<S65>/QuadHandle2' incorporates:
   *  Constant: '<S65>/Point25'
   *  Constant: '<S65>/Point50'
   *  RelationalOperator: '<S65>/LTEp25'
   *  Sum: '<S65>/p50mA'
   */
  if (rtb_Merge > untitled_P.Point25_Value) {
    rtb_Merge = untitled_P.Point50_Value - rtb_Merge;
  }

  /* Lookup_n-D: '<S64>/Look-Up Table' incorporates:
   *  Switch: '<S65>/QuadHandle2'
   *  Switch: '<S65>/SignCorrected'
   */
  bpIdx_tmp = untitled_P.LookUpTable_bp01Data[1] -
    untitled_P.LookUpTable_bp01Data[0];
  bpIdx = plook_u32u16u64n48_evenc_gf(rtb_QuadHandle2_idx_0,
    untitled_P.LookUpTable_bp01Data[0], bpIdx_tmp, 32UL, &frac);
  rtb_SignCorrected_idx_0 = intrp1d_s16s32s32u32u64n48l_f(bpIdx, frac,
    untitled_P.LookUpTable_tableData);
  bpIdx = plook_u32u16u64n48_evenc_gf(rtb_QuadHandle2_idx_1,
    untitled_P.LookUpTable_bp01Data[0], bpIdx_tmp, 32UL, &frac);
  rtb_SignCorrected_idx_1 = intrp1d_s16s32s32u32u64n48l_f(bpIdx, frac,
    untitled_P.LookUpTable_tableData);
  bpIdx = plook_u32u16u64n48_evenc_gf(rtb_Merge,
    untitled_P.LookUpTable_bp01Data[0], bpIdx_tmp, 32UL, &frac);
  rtb_SignCorrected_idx_2 = intrp1d_s16s32s32u32u64n48l_f(bpIdx, frac,
    untitled_P.LookUpTable_tableData);

  /* Switch: '<S65>/SignCorrected' incorporates:
   *  RelationalOperator: '<S65>/LTEp50'
   *  UnaryMinus: '<S65>/Negate'
   */
  if (!rtb_LTEp50_idx_0) {
    rtb_SignCorrected_idx_0 = -rtb_SignCorrected_idx_0;
  }

  if (!rtb_LTEp50_idx_1) {
    rtb_SignCorrected_idx_1 = -rtb_SignCorrected_idx_1;
  }

  if (!rtb_LogicalOperator) {
    rtb_SignCorrected_idx_2 = -rtb_SignCorrected_idx_2;
  }

  /* End of Switch: '<S65>/SignCorrected' */

  /* Logic: '<S6>/Logical Operator' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Time constant'
   *  Constant: '<S9>/Constant'
   *  RelationalOperator: '<S10>/Compare'
   *  RelationalOperator: '<S9>/Compare'
   *  Sum: '<S6>/Sum1'
   */
  rtb_LogicalOperator = ((untitled_P.LowPassFilter_T - untitled_B.Probe[0] <=
    untitled_P.Constant_Value_gf) && (untitled_P.LowPassFilter_init_option <
    untitled_P.CompareToConstant_const));

  /* S-Function (c280xqep): '<Root>/eQEP' */
  {
    untitled_B.eQEP_o1 = EQep2Regs.QPOSCNT;/*eQEP Position Counter*/
    untitled_B.eQEP_o2 = EQep2Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* If: '<S68>/If1' incorporates:
   *  Constant: '<S68>/ResetMode'
   */
  if (untitled_P.ResetMode_Value > 0) {
    /* Outputs for IfAction SubSystem: '<S68>/PositionNoReset' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Sum: '<S78>/Sum3' */
    rtb_QuadHandle2_idx_0 = untitled_B.eQEP_o1 - untitled_B.eQEP_o2;

    /* Sum: '<S78>/Sum7' incorporates:
     *  Constant: '<S83>/Constant'
     */
    rtb_Merge = rtb_QuadHandle2_idx_0 + untitled_P.Constant_Value_h;

    /* MinMax: '<S78>/MinMax' */
    if (rtb_QuadHandle2_idx_0 <= rtb_Merge) {
      rtb_Merge = rtb_QuadHandle2_idx_0;
    }

    /* End of MinMax: '<S78>/MinMax' */
    /* End of Outputs for SubSystem: '<S68>/PositionNoReset' */

    /* Update for IfAction SubSystem: '<S68>/PositionNoReset' incorporates:
     *  ActionPort: '<S78>/Action Port'
     */
    /* Update for If: '<S68>/If1' */
    srUpdateBC(untitled_DW.PositionNoReset_SubsysRanBC);

    /* End of Update for SubSystem: '<S68>/PositionNoReset' */
  } else {
    /* Outputs for IfAction SubSystem: '<S68>/PositionResetAtIndex' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* SignalConversion generated from: '<S79>/Count' */
    rtb_Merge = untitled_B.eQEP_o1;

    /* End of Outputs for SubSystem: '<S68>/PositionResetAtIndex' */

    /* Update for IfAction SubSystem: '<S68>/PositionResetAtIndex' incorporates:
     *  ActionPort: '<S79>/Action Port'
     */
    /* Update for If: '<S68>/If1' */
    srUpdateBC(untitled_DW.PositionResetAtIndex_SubsysRanB);

    /* End of Update for SubSystem: '<S68>/PositionResetAtIndex' */
  }

  /* End of If: '<S68>/If1' */

  /* Product: '<S68>/Product' incorporates:
   *  Constant: '<S84>/Constant'
   *  DataTypeConversion: '<S81>/DTC'
   */
  rtb_Product = (real_T)rtb_Merge * untitled_P.Constant_Value_m;

  /* SampleTimeMath: '<S1>/TSamp'
   *
   * About '<S1>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  rtb_TSamp = rtb_Product * untitled_P.TSamp_WtEt;

  /* Gain: '<S2>/K' incorporates:
   *  Sum: '<S1>/Diff'
   *  UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  rtb_K = (rtb_TSamp - untitled_DW.UD_DSTATE) * untitled_P.LowPassFilter_K;

  /* DiscreteIntegrator: '<S12>/Integrator' */
  if (untitled_DW.Integrator_IC_LOADING != 0U) {
    untitled_DW.Integrator_DSTATE = rtb_K;
    if (untitled_DW.Integrator_DSTATE > untitled_P.Integrator_UpperSat) {
      untitled_DW.Integrator_DSTATE = untitled_P.Integrator_UpperSat;
    } else if (untitled_DW.Integrator_DSTATE < untitled_P.Integrator_LowerSat) {
      untitled_DW.Integrator_DSTATE = untitled_P.Integrator_LowerSat;
    }
  }

  if (rtb_LogicalOperator || (untitled_DW.Integrator_PrevResetState != 0)) {
    untitled_DW.Integrator_DSTATE = rtb_K;
    if (untitled_DW.Integrator_DSTATE > untitled_P.Integrator_UpperSat) {
      untitled_DW.Integrator_DSTATE = untitled_P.Integrator_UpperSat;
    } else if (untitled_DW.Integrator_DSTATE < untitled_P.Integrator_LowerSat) {
      untitled_DW.Integrator_DSTATE = untitled_P.Integrator_LowerSat;
    }
  }

  /* Saturate: '<S12>/Saturation' incorporates:
   *  DiscreteIntegrator: '<S12>/Integrator'
   */
  if (untitled_DW.Integrator_DSTATE > untitled_P.Saturation_UpperSat) {
    /* Saturate: '<S12>/Saturation' */
    untitled_B.Saturation = untitled_P.Saturation_UpperSat;
  } else if (untitled_DW.Integrator_DSTATE < untitled_P.Saturation_LowerSat) {
    /* Saturate: '<S12>/Saturation' */
    untitled_B.Saturation = untitled_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<S12>/Saturation' */
    untitled_B.Saturation = untitled_DW.Integrator_DSTATE;
  }

  /* End of Saturate: '<S12>/Saturation' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<Root>/Constant'
   */
  untitled_B.Sum = untitled_P.Constant_Value_g - untitled_B.Saturation;

  /* Sum: '<S55>/Sum' incorporates:
   *  DiscreteIntegrator: '<S46>/Integrator'
   *  Gain: '<S51>/Proportional Gain'
   */
  untitled_B.Sum_i = untitled_P.PIDController_P * untitled_B.Sum +
    untitled_DW.Integrator_DSTATE_h;

  /* Gain: '<S4>/Adjusting Modulation Index' */
  rtb_Numberofpolepairs = untitled_P.AdjustingModulationIndex_Gain *
    untitled_B.Sum_i;

  /* Saturate: '<S4>/Modulation Index Limiter' */
  if (rtb_Numberofpolepairs > untitled_P.ModulationIndexLimiter_UpperSat) {
    rtb_Numberofpolepairs = untitled_P.ModulationIndexLimiter_UpperSat;
  } else if (rtb_Numberofpolepairs < untitled_P.ModulationIndexLimiter_LowerSat)
  {
    rtb_Numberofpolepairs = untitled_P.ModulationIndexLimiter_LowerSat;
  }

  /* End of Saturate: '<S4>/Modulation Index Limiter' */

  /* Product: '<S4>/Product1' incorporates:
   *  Switch: '<S65>/SignCorrected'
   */
  untitled_B.Product1[0] = (real_T)rtb_SignCorrected_idx_0 * 6.103515625E-5 *
    rtb_Numberofpolepairs;
  untitled_B.Product1[1] = (real_T)rtb_SignCorrected_idx_1 * 6.103515625E-5 *
    rtb_Numberofpolepairs;
  untitled_B.Product1[2] = (real_T)rtb_SignCorrected_idx_2 * 6.103515625E-5 *
    rtb_Numberofpolepairs;

  /* Fcn: '<Root>/Fcn' */
  untitled_B.Fcn = (untitled_B.Product1[0] + 1.0) * 5000.0;

  /* S-Function (c2802xpwm): '<Root>/ePWM' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(untitled_B.Fcn);
  }

  /* Fcn: '<Root>/Fcn1' */
  rtb_Numberofpolepairs = (untitled_B.Product1[1] + 1.0) * 5000.0;

  /* S-Function (c2802xpwm): '<Root>/ePWM1' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Numberofpolepairs);
  }

  /* Fcn: '<Root>/Fcn2' */
  rtb_Numberofpolepairs = (untitled_B.Product1[2] + 1.0) * 5000.0;

  /* S-Function (c2802xpwm): '<Root>/ePWM2' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Numberofpolepairs);
  }

  /* MinMax: '<S6>/Max' incorporates:
   *  Constant: '<S6>/Time constant'
   */
  if ((untitled_B.Probe[0] >= untitled_P.LowPassFilter_T) || rtIsNaN
      (untitled_P.LowPassFilter_T)) {
    rtb_Numberofpolepairs = untitled_B.Probe[0];
  } else {
    rtb_Numberofpolepairs = untitled_P.LowPassFilter_T;
  }

  /* End of MinMax: '<S6>/Max' */

  /* Fcn: '<S6>/Avoid Divide by Zero' */
  rtb_AvoidDividebyZero = (real_T)(rtb_Numberofpolepairs == 0.0) *
    2.2204460492503131e-16 + rtb_Numberofpolepairs;

  /* Switch: '<S70>/Switch' incorporates:
   *  Constant: '<S67>/ReplaceInport_Offset'
   *  Constant: '<S70>/Constant'
   *  Constant: '<S70>/Constant1'
   */
  if (untitled_P.Constant_Value_i > untitled_P.Switch_Threshold) {
    rtb_Numberofpolepairs = untitled_P.Constant1_Value;
  } else {
    rtb_Numberofpolepairs = untitled_P.ReplaceInport_Offset_Value;
  }

  /* End of Switch: '<S70>/Switch' */

  /* If: '<S71>/If' */
  if (rtb_Product <= rtb_Numberofpolepairs) {
    /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    /* Sum: '<S73>/Add' incorporates:
     *  Constant: '<S73>/Constant'
     */
    rtb_Numberofpolepairs = (rtb_Product + untitled_P.Constant_Value) -
      rtb_Numberofpolepairs;

    /* End of Outputs for SubSystem: '<S71>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S71>/If Action Subsystem' incorporates:
     *  ActionPort: '<S73>/Action Port'
     */
    /* Update for If: '<S71>/If' */
    srUpdateBC(untitled_DW.IfActionSubsystem_SubsysRanBC);

    /* End of Update for SubSystem: '<S71>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    /* Sum: '<S74>/Add' */
    rtb_Numberofpolepairs = rtb_Product - rtb_Numberofpolepairs;

    /* End of Outputs for SubSystem: '<S71>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S71>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S74>/Action Port'
     */
    /* Update for If: '<S71>/If' */
    srUpdateBC(untitled_DW.IfActionSubsystem1_SubsysRanBC);

    /* End of Update for SubSystem: '<S71>/If Action Subsystem1' */
  }

  /* End of If: '<S71>/If' */
  /* Gain: '<S76>/Number of pole pairs' */
  rtb_Numberofpolepairs *= untitled_P.MechanicaltoElectricalPosition_;

  /* Sum: '<S72>/Add' incorporates:
   *  Gain: '<S72>/Multiply'
   *  Gain: '<S72>/Multiply1'
   *  Rounding: '<S72>/Floor'
   */
  untitled_B.Add = rtb_Numberofpolepairs - floor(untitled_P.Multiply_Gain *
    rtb_Numberofpolepairs) * untitled_P.Multiply1_Gain;

  /* MATLABSystem: '<Root>/DAC' incorporates:
   *  Gain: '<Root>/Gain1'
   */
  MW_C2000DACSat(0U, untitled_P.Gain1_Gain * untitled_B.Add);

  /* Update for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  untitled_DW.DiscreteTimeIntegrator_DSTATE +=
    untitled_P.DiscreteTimeIntegrator_gainval * untitled_B.Sum_i;

  /* Update for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  untitled_DW.UD_DSTATE = rtb_TSamp;

  /* Update for DiscreteIntegrator: '<S12>/Integrator' incorporates:
   *  Product: '<S2>/1//T'
   *  Sum: '<S2>/Sum1'
   */
  untitled_DW.Integrator_IC_LOADING = 0U;
  untitled_DW.Integrator_DSTATE += 1.0 / rtb_AvoidDividebyZero * (rtb_K -
    untitled_B.Saturation) * untitled_P.Integrator_gainval;
  if (untitled_DW.Integrator_DSTATE > untitled_P.Integrator_UpperSat) {
    untitled_DW.Integrator_DSTATE = untitled_P.Integrator_UpperSat;
  } else if (untitled_DW.Integrator_DSTATE < untitled_P.Integrator_LowerSat) {
    untitled_DW.Integrator_DSTATE = untitled_P.Integrator_LowerSat;
  }

  untitled_DW.Integrator_PrevResetState = (int16_T)rtb_LogicalOperator;

  /* End of Update for DiscreteIntegrator: '<S12>/Integrator' */

  /* Update for DiscreteIntegrator: '<S46>/Integrator' incorporates:
   *  Gain: '<S43>/Integral Gain'
   */
  untitled_DW.Integrator_DSTATE_h += untitled_P.PIDController_I * untitled_B.Sum
    * untitled_P.Integrator_gainval_m;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  untitled_M->Timing.taskTime0 =
    ((time_T)(++untitled_M->Timing.clockTick0)) * untitled_M->Timing.stepSize0;
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  untitled_P.Integrator_UpperSat = rtInf;
  untitled_P.Integrator_LowerSat = rtMinusInf;
  untitled_P.Saturation_UpperSat = rtInf;
  untitled_P.Saturation_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)untitled_M, 0,
                sizeof(RT_MODEL_untitled_T));
  rtmSetTFinal(untitled_M, -1);
  untitled_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  untitled_M->Sizes.checksums[0] = (1508613555U);
  untitled_M->Sizes.checksums[1] = (3175465582U);
  untitled_M->Sizes.checksums[2] = (2461609841U);
  untitled_M->Sizes.checksums[3] = (2254510569U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[8];
    untitled_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = (sysRanDType *)&untitled_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&untitled_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = (sysRanDType *)&untitled_DW.PositionNoReset_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&untitled_DW.PositionResetAtIndex_SubsysRanB;
    rteiSetModelMappingInfoPtr(untitled_M->extModeInfo,
      &untitled_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(untitled_M->extModeInfo, untitled_M->Sizes.checksums);
    rteiSetTPtr(untitled_M->extModeInfo, rtmGetTPtr(untitled_M));
  }

  /* block I/O */
  (void) memset(((void *) &untitled_B), 0,
                sizeof(B_untitled_T));

  /* states (dwork) */
  (void) memset((void *)&untitled_DW, 0,
                sizeof(DW_untitled_T));

  /* Start for Probe: '<S6>/Probe' */
  untitled_B.Probe[0] = 0.2;
  untitled_B.Probe[1] = 0.0;

  /* Start for S-Function (c280xqep): '<Root>/eQEP' */
  config_QEP_eQEP2((uint32_T)30000U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

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

  /* InitializeConditions for DiscreteIntegrator: '<S4>/Discrete-Time Integrator' */
  untitled_DW.DiscreteTimeIntegrator_DSTATE =
    untitled_P.DiscreteTimeIntegrator_IC;

  /* InitializeConditions for UnitDelay: '<S1>/UD'
   *
   * Block description for '<S1>/UD':
   *
   *  Store in Global RAM
   */
  untitled_DW.UD_DSTATE = untitled_P.DiscreteDerivative_ICPrevScaled;

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Integrator' */
  untitled_DW.Integrator_PrevResetState = 0;
  untitled_DW.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  untitled_DW.Integrator_DSTATE_h = untitled_P.PIDController_InitialConditionF;

  /* Start for MATLABSystem: '<Root>/DAC' */
  MW_ConfigureDACA();
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
