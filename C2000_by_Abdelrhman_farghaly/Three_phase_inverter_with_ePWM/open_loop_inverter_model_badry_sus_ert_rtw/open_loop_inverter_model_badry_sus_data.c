/*
 * File: open_loop_inverter_model_badry_sus_data.c
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 13:43:15 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "open_loop_inverter_model_badry_sus.h"

/* Block parameters (default storage) */
P_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_P = {
  /* Mask Parameter: RepeatingSequenceInterpolated2_
   * Referenced by: '<S2>/Lookup'
   */
  { 0.0, 1.0, 1.0E-6 },

  /* Mask Parameter: RepeatingSequenceInterpolated1_
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 1.0, 1.0E-6 },

  /* Mask Parameter: RepeatingSequenceInterpolated3_
   * Referenced by: '<S3>/Lookup'
   */
  { 0.0, 1.0, 1.0E-6 },

  /* Mask Parameter: RepeatingSequenceInterpolated_h
   * Referenced by: '<S2>/Lookup'
   */
  { 0.0, 5.0E-5, 9.9990000999900015E-5 },

  /* Mask Parameter: RepeatingSequenceInterpolated_c
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 5.0E-5, 9.9990000999900015E-5 },

  /* Mask Parameter: RepeatingSequenceInterpolated_a
   * Referenced by: '<S3>/Lookup'
   */
  { 0.0, 5.0E-5, 9.9990000999900015E-5 },

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S13>/FixPt Switch'
   */
  99U,

  /* Mask Parameter: WrapToZero_Threshold_n
   * Referenced by: '<S7>/FixPt Switch'
   */
  99U,

  /* Mask Parameter: WrapToZero_Threshold_a
   * Referenced by: '<S10>/FixPt Switch'
   */
  99U,

  /* Expression: 50
   * Referenced by: '<Root>/Constant'
   */
  50.0,

  /* Expression: .9/50
   * Referenced by: '<Root>/Gain2'
   */
  0.018000000000000002,

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  1.0E-6,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator'
   */
  0.0,

  /* Computed Parameter: SampleTimeMath_WtEt
   * Referenced by: '<S2>/Sample Time Math'
   */
  1.0E-6,

  /* Expression: 50
   * Referenced by: '<Root>/Constant1'
   */
  50.0,

  /* Expression: .9/50
   * Referenced by: '<Root>/Gain3'
   */
  0.018000000000000002,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  1.0E-6,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator1'
   */
  0.0,

  /* Computed Parameter: SampleTimeMath_WtEt_c
   * Referenced by: '<S1>/Sample Time Math'
   */
  1.0E-6,

  /* Expression: 50
   * Referenced by: '<Root>/Constant2'
   */
  50.0,

  /* Expression: .9/50
   * Referenced by: '<Root>/Gain4'
   */
  0.018000000000000002,

  /* Computed Parameter: DiscreteTimeIntegrator2_gainval
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  1.0E-6,

  /* Expression: 0
   * Referenced by: '<Root>/Discrete-Time Integrator2'
   */
  0.0,

  /* Computed Parameter: SampleTimeMath_WtEt_b
   * Referenced by: '<S3>/Sample Time Math'
   */
  1.0E-6,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Gain7'
   */
  6.2831853071795862,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Gain5'
   */
  6.2831853071795862,

  /* Expression: 2*pi
   * Referenced by: '<Root>/Gain6'
   */
  6.2831853071795862,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain1_Gain
   * Referenced by: '<Root>/Gain1'
   */
  51200U,

  /* Computed Parameter: Gain8_Gain
   * Referenced by: '<Root>/Gain8'
   */
  51200U,

  /* Computed Parameter: Constant_Value_l
   * Referenced by: '<S7>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S10>/Constant'
   */
  0U,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S13>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S8>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_p
   * Referenced by: '<S5>/Output'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition_f
   * Referenced by: '<S11>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S12>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_m
   * Referenced by: '<S6>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: FixPtConstant_Value_a
   * Referenced by: '<S9>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
