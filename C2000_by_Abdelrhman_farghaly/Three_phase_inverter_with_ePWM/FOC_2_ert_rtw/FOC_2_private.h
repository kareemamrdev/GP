/*
 * File: FOC_2_private.h
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

#ifndef FOC_2_private_h_
#define FOC_2_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "FOC_2_types.h"
#include "FOC_2.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void F_SwitchCaseActionSubsystem(real_T rtu_In1, real_T rtu_In2, real_T
  rtu_In3, real_T *rty_Out1, real_T *rty_Out2, real_T *rty_Out3);

#endif                                 /* FOC_2_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
