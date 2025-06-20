/*
 * File: untitled1_data.c
 *
 * Code generated for Simulink model 'untitled1'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 17:46:30 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled1.h"

/* Block parameters (default storage) */
P_untitled1_T untitled1_P = {
  /* Mask Parameter: RepeatingSequenceInterpolated3_
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 6.2831853071795862 },

  /* Mask Parameter: RepeatingSequenceInterpolated_m
   * Referenced by: '<S1>/Lookup'
   */
  { 0.0, 0.02 },

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S6>/FixPt Switch'
   */
  200U,

  /* Computed Parameter: SampleTimeMath_WtEt
   * Referenced by: '<S1>/Sample Time Math'
   */
  0.0001,

  /* Expression: 0.9
   * Referenced by: '<Root>/Constant'
   */
  0.9,

  /* Expression: 10000
   * Referenced by: '<Root>/Constant1'
   */
  10000.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain1'
   */
  100.0,

  /* Expression: 100
   * Referenced by: '<Root>/Gain2'
   */
  100.0,

  /* Computed Parameter: Constant_Value_d
   * Referenced by: '<S6>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S4>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S5>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
