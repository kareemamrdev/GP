/*
 * File: SVM_CG_private.h
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

#ifndef SVM_CG_private_h_
#define SVM_CG_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "SVM_CG_types.h"
#include "SVM_CG.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T look1_binlcpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void SVM_C_SwitchCaseActionSubsystem(real_T rtu_In1, real_T rtu_In2,
  real_T rtu_In3, real_T *rty_Out1, real_T *rty_Out2, real_T *rty_Out3);

#endif                                 /* SVM_CG_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
