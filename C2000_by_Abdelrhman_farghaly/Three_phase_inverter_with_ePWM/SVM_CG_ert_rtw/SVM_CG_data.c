/*
 * File: SVM_CG_data.c
 *
 * Code generated for Simulink model 'SVM_CG'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May  6 17:00:42 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SVM_CG.h"

/* Block parameters (default storage) */
P_SVM_CG_T SVM_CG_P = {
  /* Variable: T_period
   * Referenced by:
   *   '<S9>/Constant'
   *   '<S9>/Gain6'
   */
  0.0001,

  /* Variable: Vdc
   * Referenced by:
   *   '<S8>/Saturation2'
   *   '<S9>/Vdc'
   */
  300.0,

  /* Mask Parameter: RepeatingSequenceInterpolated1_
   * Referenced by: '<S4>/Lookup'
   */
  { 0.0, 6.666666666666667E-5, 1.0E-6 },

  /* Mask Parameter: RepeatingSequenceInterpolated_g
   * Referenced by: '<S4>/Lookup'
   */
  { 0.0, 2.5E-5, 4.9997500124993749E-5 },

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S12>/FixPt Switch'
   */
  49U,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave1'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Sine Wave2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S2>/Gain1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S2>/Gain'
   */
  0.5,

  /* Expression: 2/3
   * Referenced by: '<S2>/Gain2'
   */
  0.66666666666666663,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S2>/Gain3'
   */
  0.8660254037844386,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S2>/Gain4'
   */
  0.8660254037844386,

  /* Expression: 2/3
   * Referenced by: '<S2>/Gain5'
   */
  0.66666666666666663,

  /* Expression: 0
   * Referenced by: '<S8>/Saturation2'
   */
  0.0,

  /* Expression: 180/pi
   * Referenced by: '<S5>/Gain13'
   */
  57.295779513082323,

  /* Expression: 0
   * Referenced by: '<S5>/Constant12'
   */
  0.0,

  /* Expression: 60
   * Referenced by: '<S5>/Constant13'
   */
  60.0,

  /* Expression: 60
   * Referenced by: '<S5>/Constant14'
   */
  60.0,

  /* Expression: 120
   * Referenced by: '<S5>/Constant15'
   */
  120.0,

  /* Expression: 2
   * Referenced by: '<S5>/Gain15'
   */
  2.0,

  /* Expression: 120
   * Referenced by: '<S5>/Constant16'
   */
  120.0,

  /* Expression: 180
   * Referenced by: '<S5>/Constant17'
   */
  180.0,

  /* Expression: 3
   * Referenced by: '<S5>/Gain16'
   */
  3.0,

  /* Expression: -180
   * Referenced by: '<S5>/Constant18'
   */
  -180.0,

  /* Expression: -120
   * Referenced by: '<S5>/Constant19'
   */
  -120.0,

  /* Expression: 4
   * Referenced by: '<S5>/Gain17'
   */
  4.0,

  /* Expression: -120
   * Referenced by: '<S5>/Constant20'
   */
  -120.0,

  /* Expression: -60
   * Referenced by: '<S5>/Constant21'
   */
  -60.0,

  /* Expression: 5
   * Referenced by: '<S5>/Gain18'
   */
  5.0,

  /* Expression: -60
   * Referenced by: '<S5>/Constant22'
   */
  -60.0,

  /* Expression: 0
   * Referenced by: '<S5>/Constant23'
   */
  0.0,

  /* Expression: 6
   * Referenced by: '<S5>/Gain19'
   */
  6.0,

  /* Expression: pi/3
   * Referenced by: '<S9>/Gain7'
   */
  1.0471975511965976,

  /* Expression: 1
   * Referenced by: '<S9>/const'
   */
  1.0,

  /* Expression: pi/3
   * Referenced by: '<S9>/Gain8'
   */
  1.0471975511965976,

  /* Expression: 0.5
   * Referenced by: '<S6>/Gain9'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S6>/Gain12'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S6>/Gain11'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S6>/Gain10'
   */
  0.5,

  /* Computed Parameter: SampleTimeMath_WtEt
   * Referenced by: '<S4>/Sample Time Math'
   */
  1.0E-6,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S7>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S7>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S7>/Merge2'
   */
  0.0,

  /* Computed Parameter: Gain14_Gain
   * Referenced by: '<S5>/Gain14'
   */
  1.0F,

  /* Computed Parameter: Constant_Value
   * Referenced by: '<S12>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S10>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S11>/FixPt Constant'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
