/*
 * File: FOC_2_data.c
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

/* Block parameters (default storage) */
P_FOC_2_T FOC_2_P = {
  /* Variable: Ki
   * Referenced by:
   *   '<S62>/Gain2'
   *   '<S63>/Gain2'
   */
  105972.78225806463,

  /* Variable: Ki_s
   * Referenced by: '<S7>/Gain4'
   */
  3.0027161494220578,

  /* Variable: Kp
   * Referenced by:
   *   '<S62>/Gain1'
   *   '<S63>/Gain1'
   */
  62.350000000000037,

  /* Variable: Kp_s
   * Referenced by: '<S7>/Gain3'
   */
  0.017197907585004366,

  /* Variable: L
   * Referenced by:
   *   '<S2>/Constant2'
   *   '<S2>/Constant3'
   */
  0.0124,

  /* Variable: T_period
   * Referenced by:
   *   '<S52>/Constant'
   *   '<S52>/Gain6'
   */
  0.0001,

  /* Variable: Vdc
   * Referenced by:
   *   '<S12>/Constant'
   *   '<S51>/Saturation2'
   *   '<S52>/Vdc'
   *   '<S66>/Gain1'
   *   '<S66>/Gain2'
   */
  300.0,

  /* Variable: lambda
   * Referenced by:
   *   '<S1>/Gain2'
   *   '<S2>/Constant1'
   */
  0.12333333333333334,

  /* Variable: ma
   * Referenced by:
   *   '<S12>/Gain'
   *   '<S66>/Gain1'
   *   '<S66>/Gain2'
   */
  0.95,

  /* Variable: p
   * Referenced by: '<S1>/Gain2'
   */
  4.0,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S69>/UD'
   */
  0.0,

  /* Mask Parameter: LowPassFilter_K
   * Referenced by: '<S3>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilter3_K
   * Referenced by: '<S6>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilter2_K
   * Referenced by: '<S5>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilter1_K
   * Referenced by: '<S4>/K'
   */
  1.0,

  /* Mask Parameter: LowPassFilter_K_g
   * Referenced by: '<S70>/K'
   */
  1.0,

  /* Mask Parameter: RepeatingSequenceInterpolated1_
   * Referenced by: '<S47>/Lookup'
   */
  { 0.0, 6.666666666666667E-5, 1.0E-6 },

  /* Mask Parameter: LowPassFilter_T
   * Referenced by: '<S14>/Time constant'
   */
  0.01,

  /* Mask Parameter: LowPassFilter3_T
   * Referenced by: '<S35>/Time constant'
   */
  0.01,

  /* Mask Parameter: LowPassFilter2_T
   * Referenced by: '<S28>/Time constant'
   */
  0.01,

  /* Mask Parameter: LowPassFilter1_T
   * Referenced by: '<S21>/Time constant'
   */
  0.01,

  /* Mask Parameter: LowPassFilter_T_k
   * Referenced by: '<S72>/Time constant'
   */
  0.01,

  /* Mask Parameter: RepeatingSequenceInterpolated_j
   * Referenced by: '<S47>/Lookup'
   */
  { 0.0, 2.5E-5, 4.9997500124993749E-5 },

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S17>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant1_const
   * Referenced by: '<S42>/Constant'
   */
  0.0001,

  /* Mask Parameter: CompareToConstant_const_f
   * Referenced by: '<S38>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_o
   * Referenced by: '<S31>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_m
   * Referenced by: '<S24>/Constant'
   */
  2.0,

  /* Mask Parameter: CompareToConstant_const_l
   * Referenced by: '<S75>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilter_init_option
   * Referenced by: '<S14>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilter3_init_option
   * Referenced by: '<S35>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilter2_init_option
   * Referenced by: '<S28>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilter1_init_option
   * Referenced by: '<S21>/Constant'
   */
  1.0,

  /* Mask Parameter: LowPassFilter_init_option_f
   * Referenced by: '<S72>/Constant'
   */
  1.0,

  /* Mask Parameter: WrapToZero_Threshold
   * Referenced by: '<S55>/FixPt Switch'
   */
  49U,

  /* Mask Parameter: DetectRisePositive_vinit
   * Referenced by: '<S68>/Delay Input1'
   */
  0U,

  /* Expression: sqrt(3)
   * Referenced by: '<S66>/Gain'
   */
  1.7320508075688772,

  /* Expression: 0
   * Referenced by: '<S13>/Constant4'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Constant'
   */
  0.0,

  /* Expression: 3000
   * Referenced by: '<S1>/Constant1'
   */
  3000.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S20>/Integrator'
   */
  1.0E-6,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S20>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S20>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S20>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S20>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 2*pi/60
   * Referenced by: '<S1>/Gain1'
   */
  0.10471975511965977,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_p
   * Referenced by: '<S44>/Integrator'
   */
  1.0E-6,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S44>/Integrator'
   */
  4.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S44>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S44>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S44>/Saturation'
   */
  0.0,

  /* Expression: 3.8
   * Referenced by: '<S7>/Saturation'
   */
  3.8,

  /* Expression: -3.8
   * Referenced by: '<S7>/Saturation'
   */
  -3.8,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S63>/Discrete-Time Integrator1'
   */
  1.0E-6,

  /* Expression: 0
   * Referenced by: '<S63>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S48>/Constant12'
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: 0
   * Referenced by:
   */
  0.0,

  /* Expression: sqrt(3)
   * Referenced by: '<S10>/Gain'
   */
  1.7320508075688772,

  /* Expression: 1/2
   * Referenced by: '<S10>/Gain2'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S45>/Gain'
   */
  0.5,

  /* Expression: 1/2
   * Referenced by: '<S10>/Gain1'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S45>/Gain1'
   */
  0.5,

  /* Expression: 2/3
   * Referenced by: '<S45>/Gain2'
   */
  0.66666666666666663,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S45>/Gain3'
   */
  0.8660254037844386,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S45>/Gain4'
   */
  0.8660254037844386,

  /* Expression: 2/3
   * Referenced by: '<S45>/Gain5'
   */
  0.66666666666666663,

  /* Expression: 180/pi
   * Referenced by: '<S48>/Gain13'
   */
  57.295779513082323,

  /* Expression: 60
   * Referenced by: '<S48>/Constant13'
   */
  60.0,

  /* Expression: 60
   * Referenced by: '<S48>/Constant14'
   */
  60.0,

  /* Expression: 120
   * Referenced by: '<S48>/Constant15'
   */
  120.0,

  /* Expression: 2
   * Referenced by: '<S48>/Gain15'
   */
  2.0,

  /* Expression: 120
   * Referenced by: '<S48>/Constant16'
   */
  120.0,

  /* Expression: 180
   * Referenced by: '<S48>/Constant17'
   */
  180.0,

  /* Expression: 3
   * Referenced by: '<S48>/Gain16'
   */
  3.0,

  /* Expression: -180
   * Referenced by: '<S48>/Constant18'
   */
  -180.0,

  /* Expression: -120
   * Referenced by: '<S48>/Constant19'
   */
  -120.0,

  /* Expression: 4
   * Referenced by: '<S48>/Gain17'
   */
  4.0,

  /* Expression: -120
   * Referenced by: '<S48>/Constant20'
   */
  -120.0,

  /* Expression: -60
   * Referenced by: '<S48>/Constant21'
   */
  -60.0,

  /* Expression: 5
   * Referenced by: '<S48>/Gain18'
   */
  5.0,

  /* Expression: -60
   * Referenced by: '<S48>/Constant22'
   */
  -60.0,

  /* Expression: 0
   * Referenced by: '<S48>/Constant23'
   */
  0.0,

  /* Expression: 6
   * Referenced by: '<S48>/Gain19'
   */
  6.0,

  /* Expression: pi/3
   * Referenced by: '<S52>/Gain7'
   */
  1.0471975511965976,

  /* Expression: 0
   * Referenced by: '<S51>/Saturation2'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S52>/const'
   */
  1.0,

  /* Expression: pi/3
   * Referenced by: '<S52>/Gain8'
   */
  1.0471975511965976,

  /* Expression: 0.5
   * Referenced by: '<S49>/Gain9'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S49>/Gain12'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S49>/Gain11'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S49>/Gain10'
   */
  0.5,

  /* Computed Parameter: SampleTimeMath_WtEt
   * Referenced by: '<S47>/Sample Time Math'
   */
  1.0E-6,

  /* Computed Parameter: Merge_InitialOutput
   * Referenced by: '<S50>/Merge'
   */
  0.0,

  /* Computed Parameter: Merge1_InitialOutput
   * Referenced by: '<S50>/Merge1'
   */
  0.0,

  /* Computed Parameter: Merge2_InitialOutput
   * Referenced by: '<S50>/Merge2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S39>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_j
   * Referenced by: '<S41>/Integrator'
   */
  0.1,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S41>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S41>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S41>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S41>/Saturation'
   */
  0.0,

  /* Expression: 1.38
   * Referenced by: '<S1>/Constant3'
   */
  1.38,

  /* Expression: 1/0.177985
   * Referenced by: '<S1>/Gain6'
   */
  5.618450993061213,

  /* Expression: 0.5
   * Referenced by: '<S11>/Gain1'
   */
  0.5,

  /* Expression: 0
   * Referenced by: '<S32>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_n
   * Referenced by: '<S34>/Integrator'
   */
  0.1,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S34>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S34>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S34>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S34>/Saturation'
   */
  0.0,

  /* Expression: 1.38
   * Referenced by: '<S1>/Constant'
   */
  1.38,

  /* Expression: 1/0.177985
   * Referenced by: '<S1>/Gain3'
   */
  5.618450993061213,

  /* Expression: 0
   * Referenced by: '<S25>/Constant'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S27>/Integrator'
   */
  0.1,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S27>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S27>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S27>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S27>/Saturation'
   */
  0.0,

  /* Expression: 1.38
   * Referenced by: '<S1>/Constant2'
   */
  1.38,

  /* Expression: 1/0.177985
   * Referenced by: '<S1>/Gain5'
   */
  5.618450993061213,

  /* Expression: 0.5
   * Referenced by: '<S11>/Gain'
   */
  0.5,

  /* Expression: 2/3
   * Referenced by: '<S11>/Gain2'
   */
  0.66666666666666663,

  /* Expression: 1
   * Referenced by: '<S13>/Constant2'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S13>/Unit Delay'
   */
  0.0,

  /* Expression: 2*pi /2000
   * Referenced by: '<S13>/Gain2'
   */
  0.0031415926535897933,

  /* Expression: 4
   * Referenced by: '<S13>/Gain3'
   */
  4.0,

  /* Expression: 2*pi
   * Referenced by: '<S13>/Constant3'
   */
  6.2831853071795862,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S11>/Gain3'
   */
  0.8660254037844386,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S11>/Gain4'
   */
  0.8660254037844386,

  /* Expression: 2/3
   * Referenced by: '<S11>/Gain5'
   */
  0.66666666666666663,

  /* Expression: 0
   * Referenced by: '<S76>/Constant'
   */
  0.0,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S69>/TSamp'
   */
  10.0,

  /* Computed Parameter: Integrator_gainval_o
   * Referenced by: '<S78>/Integrator'
   */
  0.1,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S78>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S78>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S78>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S78>/Saturation'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Id_Ref'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
   * Referenced by: '<S62>/Discrete-Time Integrator1'
   */
  0.1,

  /* Expression: 0
   * Referenced by: '<S62>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 60/(2*pi)
   * Referenced by: '<S1>/Gain4'
   */
  9.5492965855137211,

  /* Computed Parameter: Gain1_Gain_b
   * Referenced by: '<S13>/Gain1'
   */
  -1.0F,

  /* Computed Parameter: Gain_Gain_k
   * Referenced by: '<S13>/Gain'
   */
  1.0F,

  /* Computed Parameter: Switch2_Threshold
   * Referenced by: '<S13>/Switch2'
   */
  0.0F,

  /* Computed Parameter: Gain14_Gain
   * Referenced by: '<S48>/Gain14'
   */
  1.0F,

  /* Computed Parameter: Constant_Value_m4
   * Referenced by: '<S71>/Constant'
   */
  0.0F,

  /* Computed Parameter: Constant_Value_e
   * Referenced by: '<S55>/Constant'
   */
  0U,

  /* Computed Parameter: Output_InitialCondition
   * Referenced by: '<S53>/Output'
   */
  0U,

  /* Computed Parameter: FixPtConstant_Value
   * Referenced by: '<S54>/FixPt Constant'
   */
  1U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S13>/Switch'
   */
  0U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
