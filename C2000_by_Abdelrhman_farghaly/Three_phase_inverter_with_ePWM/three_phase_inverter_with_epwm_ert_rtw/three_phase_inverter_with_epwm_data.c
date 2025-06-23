/*
 * File: three_phase_inverter_with_epwm_data.c
 *
 * Code generated for Simulink model 'three_phase_inverter_with_epwm'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jun 20 16:25:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "three_phase_inverter_with_epwm.h"

/* Block parameters (default storage) */
P_three_phase_inverter_with_e_T three_phase_inverter_with_epw_P = {
  /* Variable: Ki
   * Referenced by:
   *   '<S8>/Gain2'
   *   '<S9>/Gain2'
   */
  105972.78225806463,

  /* Variable: Kp
   * Referenced by:
   *   '<S8>/Gain1'
   *   '<S9>/Gain1'
   */
  62.350000000000037,

  /* Variable: L
   * Referenced by:
   *   '<S1>/Constant2'
   *   '<S1>/Constant3'
   */
  0.0124,

  /* Variable: lambda
   * Referenced by:
   *   '<S1>/Constant1'
   *   '<S3>/Gain2'
   */
  0.12333333333333334,

  /* Variable: p
   * Referenced by: '<S3>/Gain2'
   */
  4.0,

  /* Mask Parameter: MechanicaltoElectricalPosition_
   * Referenced by: '<S31>/Number of pole pairs'
   */
  4.0,

  /* Computed Parameter: Out1_Y0
   * Referenced by: '<S2>/Out1'
   */
  0.0,

  /* Computed Parameter: Out2_Y0
   * Referenced by: '<S2>/Out2'
   */
  0.0,

  /* Computed Parameter: Out3_Y0
   * Referenced by: '<S2>/Out3'
   */
  0.0,

  /* Expression: 3.3/4095
   * Referenced by: '<S2>/Gain5'
   */
  0.00080586080586080586,

  /* Expression: 1.49
   * Referenced by: '<S2>/Constant2'
   */
  1.49,

  /* Expression: -1/0.177985
   * Referenced by: '<S2>/Gain6'
   */
  -5.618450993061213,

  /* Expression: 3.3/4095
   * Referenced by: '<S2>/Gain3'
   */
  0.00080586080586080586,

  /* Expression: 1.49
   * Referenced by: '<S2>/Constant'
   */
  1.49,

  /* Expression: -1/0.177985
   * Referenced by: '<S2>/Gain4'
   */
  -5.618450993061213,

  /* Expression: [0.09516]
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  0.09516,

  /* Expression: [1 -0.9048]
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  { 1.0, -0.9048 },

  /* Expression: 0
   * Referenced by: '<S2>/Discrete Transfer Fcn'
   */
  0.0,

  /* Expression: [0.09516]
   * Referenced by: '<S2>/Discrete Transfer Fcn1'
   */
  0.09516,

  /* Expression: [1 -0.9048]
   * Referenced by: '<S2>/Discrete Transfer Fcn1'
   */
  { 1.0, -0.9048 },

  /* Expression: 0
   * Referenced by: '<S2>/Discrete Transfer Fcn1'
   */
  0.0,

  /* Expression: maxAngleIn
   * Referenced by: '<S28>/Constant'
   */
  6.2831853071795862,

  /* Expression: mechOffsetIn
   * Referenced by: '<S25>/Constant1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S22>/ReplaceInport_Offset'
   */
  0.0,

  /* Computed Parameter: Pos_e_Y0
   * Referenced by: '<S7>/Pos_e'
   */
  0.0,

  /* Expression: 7.853982e-04
   * Referenced by: '<S39>/Constant'
   */
  0.0007853982,

  /* Expression: 1/maxAngleIn
   * Referenced by: '<S27>/Multiply'
   */
  0.15915494309189535,

  /* Expression: maxAngleIn
   * Referenced by: '<S27>/Multiply1'
   */
  6.2831853071795862,

  /* Expression: 4095/(2*pi)
   * Referenced by: '<S7>/Gain1'
   */
  651.73949196131139,

  /* Computed Parameter: Id_Y0
   * Referenced by: '<S5>/Id'
   */
  0.0,

  /* Computed Parameter: Iq_Y0
   * Referenced by: '<S5>/Iq'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S5>/Gain'
   */
  0.5,

  /* Expression: 0.5
   * Referenced by: '<S5>/Gain1'
   */
  0.5,

  /* Expression: 2/3
   * Referenced by: '<S5>/Gain2'
   */
  0.66666666666666663,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S5>/Gain3'
   */
  0.8660254037844386,

  /* Expression: sqrt(3)/2
   * Referenced by: '<S5>/Gain4'
   */
  0.8660254037844386,

  /* Expression: 2/3
   * Referenced by: '<S5>/Gain5'
   */
  0.66666666666666663,

  /* Computed Parameter: Vq_coupled_Y0
   * Referenced by: '<S3>/Vq_coupled'
   */
  0.0,

  /* Computed Parameter: Vd_coupled1_Y0
   * Referenced by: '<S3>/Vd_coupled1'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<S3>/Constant4'
   */
  1.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainval
   * Referenced by: '<S9>/Discrete-Time Integrator1'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S9>/Discrete-Time Integrator1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S3>/Constant1'
   */
  0.0,

  /* Computed Parameter: DiscreteTimeIntegrator1_gainv_l
   * Referenced by: '<S8>/Discrete-Time Integrator1'
   */
  1.0E-5,

  /* Expression: 0
   * Referenced by: '<S8>/Discrete-Time Integrator1'
   */
  0.0,

  /* Computed Parameter: Vq_Y0
   * Referenced by: '<S1>/Vq+'
   */
  0.0,

  /* Computed Parameter: Vd_Y0
   * Referenced by: '<S1>/Vd+'
   */
  0.0,

  /* Computed Parameter: Va_Y0
   * Referenced by: '<S4>/Va'
   */
  0.0,

  /* Computed Parameter: Vb_Y0
   * Referenced by: '<S4>/Vb'
   */
  0.0,

  /* Computed Parameter: Vc_Y0
   * Referenced by: '<S4>/Vc'
   */
  0.0,

  /* Expression: sqrt(3)
   * Referenced by: '<S4>/Gain'
   */
  1.7320508075688772,

  /* Expression: 1/2
   * Referenced by: '<S4>/Gain1'
   */
  0.5,

  /* Expression: 1/2
   * Referenced by: '<S4>/Gain2'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S10>/one_by_two'
   */
  -0.5,

  /* Expression: 2/sqrt(3)
   * Referenced by: '<S6>/Gain'
   */
  1.1547005383792517,

  /* Computed Parameter: ResetMode_Value
   * Referenced by: '<S23>/ResetMode'
   */
  1,

  /* Computed Parameter: Constant_Value_o
   * Referenced by: '<S38>/Constant'
   */
  8000U,

  /* Computed Parameter: Constant_Value_jr
   * Referenced by: '<S25>/Constant'
   */
  2U,

  /* Computed Parameter: Switch_Threshold
   * Referenced by: '<S25>/Switch'
   */
  1U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
