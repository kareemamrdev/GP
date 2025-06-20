/*
 * File: three_phase_inverter_with_epwm_data.c
 *
 * Code generated for Simulink model 'three_phase_inverter_with_epwm'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Jun 18 19:31:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "three_phase_inverter_with_epwm.h"

/* Block parameters (default storage) */
P_three_phase_inverter_with_e_T three_phase_inverter_with_epw_P = {
  /* Expression: 0.9
   * Referenced by: '<Root>/Sine Wave'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Expression: 100*pi
   * Referenced by: '<Root>/Sine Wave'
   */
  314.15926535897933,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.062790519529313374,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99802672842827156,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.062790519529313374,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99802672842827156,

  /* Expression: 0.9
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 100*pi
   * Referenced by: '<Root>/Sine Wave1'
   */
  314.15926535897933,

  /* Expression: (-2*pi)/3
   * Referenced by: '<Root>/Sine Wave1'
   */
  -2.0943951023931953,

  /* Computed Parameter: SineWave1_Hsin
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.062790519529313374,

  /* Computed Parameter: SineWave1_HCos
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.99802672842827156,

  /* Computed Parameter: SineWave1_PSin
   * Referenced by: '<Root>/Sine Wave1'
   */
  -0.83292124071009954,

  /* Computed Parameter: SineWave1_PCos
   * Referenced by: '<Root>/Sine Wave1'
   */
  -0.553391549243344,

  /* Expression: 0.9
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.0,

  /* Expression: 100*pi
   * Referenced by: '<Root>/Sine Wave2'
   */
  314.15926535897933,

  /* Expression: (2*pi)/3
   * Referenced by: '<Root>/Sine Wave2'
   */
  2.0943951023931953,

  /* Computed Parameter: SineWave2_Hsin
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.062790519529313374,

  /* Computed Parameter: SineWave2_HCos
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.99802672842827156,

  /* Computed Parameter: SineWave2_PSin
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.895711760239413,

  /* Computed Parameter: SineWave2_PCos
   * Referenced by: '<Root>/Sine Wave2'
   */
  -0.44463517918492723
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
