/*
 * File: untitled_data.c
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

/* Block parameters (default storage) */
P_untitled_T untitled_P = {
  /* Mask Parameter: PIDController_I
   * Referenced by: '<S43>/Integral Gain'
   */
  0.0012,

  /* Mask Parameter: DiscreteDerivative_ICPrevScaled
   * Referenced by: '<S1>/UD'
   */
  0.0,

  /* Mask Parameter: PIDController_InitialConditionF
   * Referenced by: '<S46>/Integrator'
   */
  0.0,

  /* Mask Parameter: LowPassFilter_K
   * Referenced by: '<S2>/K'
   */
  1.0,

  /* Mask Parameter: MechanicaltoElectricalPosition_
   * Referenced by: '<S76>/Number of pole pairs'
   */
  4.0,

  /* Mask Parameter: PIDController_P
   * Referenced by: '<S51>/Proportional Gain'
   */
  0.0001,

  /* Mask Parameter: LowPassFilter_T
   * Referenced by: '<S6>/Time constant'
   */
  0.01,

  /* Mask Parameter: CompareToConstant_const
   * Referenced by: '<S9>/Constant'
   */
  2.0,

  /* Mask Parameter: LowPassFilter_init_option
   * Referenced by: '<S6>/Constant'
   */
  1.0,

  /* Expression: maxAngleIn
   * Referenced by: '<S73>/Constant'
   */
  6.2831853071795862,

  /* Expression: mechOffsetIn
   * Referenced by: '<S70>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S67>/ReplaceInport_Offset'
   */
  0.0,

  /* Expression: [0 2/3 1/3]
   * Referenced by: '<S4>/Introducing Phase Shift'
   */
  { 0.0, 0.66666666666666663, 0.33333333333333331 },

  /* Computed Parameter: DiscreteTimeIntegrator_gainval
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.2,

  /* Expression: 0
   * Referenced by: '<S4>/Discrete-Time Integrator'
   */
  0.0,

  /* Expression: 1000
   * Referenced by: '<Root>/Constant'
   */
  1000.0,

  /* Expression: 0
   * Referenced by: '<S10>/Constant'
   */
  0.0,

  /* Expression: 7.853982e-04
   * Referenced by: '<S84>/Constant'
   */
  0.0007853982,

  /* Computed Parameter: TSamp_WtEt
   * Referenced by: '<S1>/TSamp'
   */
  5.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S12>/Integrator'
   */
  0.2,

  /* Expression: antiwindupUpperLimit
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: antiwindupLowerLimit
   * Referenced by: '<S12>/Integrator'
   */
  0.0,

  /* Expression: windupUpperLimit
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Expression: windupLowerLimit
   * Referenced by: '<S12>/Saturation'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval_m
   * Referenced by: '<S46>/Integrator'
   */
  0.2,

  /* Expression: 1/60
   * Referenced by: '<S4>/Adjusting Modulation Index'
   */
  0.016666666666666666,

  /* Expression: 0.9
   * Referenced by: '<S4>/Modulation Index Limiter'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<S4>/Modulation Index Limiter'
   */
  0.0,

  /* Expression: 1/maxAngleIn
   * Referenced by: '<S72>/Multiply'
   */
  0.15915494309189535,

  /* Expression: maxAngleIn
   * Referenced by: '<S72>/Multiply1'
   */
  6.2831853071795862,

  /* Expression: 4095/(2*pi)
   * Referenced by: '<Root>/Gain1'
   */
  651.73949196131139,

  /* Computed Parameter: ResetMode_Value
   * Referenced by: '<S68>/ResetMode'
   */
  1,

  /* Computed Parameter: LookUpTable_tableData
   * Referenced by: '<S64>/Look-Up Table'
   */
  { 0, 804, 1606, 2404, 3196, 3981, 4756, 5520, 6270, 7005, 7723, 8423, 9102,
    9760, 10394, 11003, 11585, 12140, 12665, 13160, 13623, 14053, 14449, 14811,
    15137, 15426, 15679, 15893, 16069, 16207, 16305, 16364, 16384 },

  /* Computed Parameter: Point50_Value
   * Referenced by: '<S65>/Point50'
   */
  32768U,

  /* Computed Parameter: Point25_Value
   * Referenced by: '<S65>/Point25'
   */
  16384U,

  /* Computed Parameter: LookUpTable_bp01Data
   * Referenced by: '<S64>/Look-Up Table'
   */
  { 0U, 512U, 1024U, 1536U, 2048U, 2560U, 3072U, 3584U, 4096U, 4608U, 5120U,
    5632U, 6144U, 6656U, 7168U, 7680U, 8192U, 8704U, 9216U, 9728U, 10240U,
    10752U, 11264U, 11776U, 12288U, 12800U, 13312U, 13824U, 14336U, 14848U,
    15360U, 15872U, 16384U },

  /* Computed Parameter: Constant_Value_h
   * Referenced by: '<S83>/Constant'
   */
  8000U,

  /* Computed Parameter: Constant_Value_i
   * Referenced by: '<S70>/Constant'
   */
  2U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S70>/Switch'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
