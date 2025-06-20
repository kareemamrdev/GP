/*
 * File: three_phase_inverter_with_epwm_data.c
 *
 * Code generated for Simulink model 'three_phase_inverter_with_epwm'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 14:51:52 2025
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

  /* Expression: 160*pi
   * Referenced by: '<Root>/Sine Wave'
   */
  502.6548245743669,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave'
   */
  0.0,

  /* Computed Parameter: SineWave_Hsin
   * Referenced by: '<Root>/Sine Wave'
   */
  0.10036171485121489,

  /* Computed Parameter: SineWave_HCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99495101698130017,

  /* Computed Parameter: SineWave_PSin
   * Referenced by: '<Root>/Sine Wave'
   */
  -0.10036171485121489,

  /* Computed Parameter: SineWave_PCos
   * Referenced by: '<Root>/Sine Wave'
   */
  0.99495101698130017,

  /* Expression: 0.9
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.0,

  /* Expression: 160*pi
   * Referenced by: '<Root>/Sine Wave1'
   */
  502.6548245743669,

  /* Expression: (-2*pi)/3
   * Referenced by: '<Root>/Sine Wave1'
   */
  -2.0943951023931953,

  /* Computed Parameter: SineWave1_Hsin
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.10036171485121489,

  /* Computed Parameter: SineWave1_HCos
   * Referenced by: '<Root>/Sine Wave1'
   */
  0.99495101698130017,

  /* Computed Parameter: SineWave1_PSin
   * Referenced by: '<Root>/Sine Wave1'
   */
  -0.811471998801361,

  /* Computed Parameter: SineWave1_PCos
   * Referenced by: '<Root>/Sine Wave1'
   */
  -0.58439130311917187,

  /* Expression: 0.9
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.9,

  /* Expression: 0
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.0,

  /* Expression: 160*pi
   * Referenced by: '<Root>/Sine Wave2'
   */
  502.6548245743669,

  /* Expression: (2*pi)/3
   * Referenced by: '<Root>/Sine Wave2'
   */
  2.0943951023931953,

  /* Computed Parameter: SineWave2_Hsin
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.10036171485121489,

  /* Computed Parameter: SineWave2_HCos
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.99495101698130017,

  /* Computed Parameter: SineWave2_PSin
   * Referenced by: '<Root>/Sine Wave2'
   */
  0.91183371365257582,

  /* Computed Parameter: SineWave2_PCos
   * Referenced by: '<Root>/Sine Wave2'
   */
  -0.41055971386212786
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
