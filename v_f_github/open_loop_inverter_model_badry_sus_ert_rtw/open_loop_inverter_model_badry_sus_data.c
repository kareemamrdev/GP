/*
 * File: open_loop_inverter_model_badry_sus_data.c
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 14:05:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "open_loop_inverter_model_badry_sus.h"

/* Block parameters (default storage) */
P_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_P = {
  /* Expression: 1500
   * Referenced by: '<Root>/Constant'
   */
  1500.0,

  /* Expression: 2/60
   * Referenced by: '<Root>/Gain9'
   */
  0.033333333333333333,

  /* Expression: 1/50
   * Referenced by: '<S1>/Gain1'
   */
  0.02,

  /* Expression: 1
   * Referenced by: '<S1>/Modulation Index Limiter'
   */
  1.0,

  /* Expression: 0
   * Referenced by: '<S1>/Modulation Index Limiter'
   */
  0.0,

  /* Expression: sps.Delay
   * Referenced by: '<S4>/Constant3'
   */
  2.5000000000000005E-5,

  /* Expression: sps.Period
   * Referenced by: '<S4>/Constant4'
   */
  0.0001,

  /* Expression: sps.Freq
   * Referenced by: '<S4>/1\ib1'
   */
  10000.0,

  /* Expression: [0 2 0]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 0.0, 2.0, 0.0 },

  /* Expression: [0 .5 1]
   * Referenced by: '<S4>/1-D Lookup Table'
   */
  { 0.0, 0.5, 1.0 },

  /* Expression: 1
   * Referenced by: '<S4>/Constant2'
   */
  1.0,

  /* Computed Parameter: Gain_Gain
   * Referenced by: '<Root>/Gain'
   */
  51200U,

  /* Computed Parameter: Gain1_Gain_j
   * Referenced by: '<Root>/Gain1'
   */
  51200U,

  /* Computed Parameter: Gain8_Gain
   * Referenced by: '<Root>/Gain8'
   */
  51200U
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
