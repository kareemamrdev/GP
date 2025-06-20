/*
 * File: three_phase_inverter_with_epwm.h
 *
 * Code generated for Simulink model 'three_phase_inverter_with_epwm'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 16:39:18 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef three_phase_inverter_with_epwm_h_
#define three_phase_inverter_with_epwm_h_
#ifndef three_phase_inverter_with_epwm_COMMON_INCLUDES_
#define three_phase_inverter_with_epwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                     /* three_phase_inverter_with_epwm_COMMON_INCLUDES_ */

#include <stddef.h>
#include "three_phase_inverter_with_epwm_types.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define three_phase_inverter_with_epwm_M (three_phase_inverter_with_ep_M)

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  real_T lastSin_i;                    /* '<Root>/Sine Wave1' */
  real_T lastCos_i;                    /* '<Root>/Sine Wave1' */
  real_T lastSin_a;                    /* '<Root>/Sine Wave2' */
  real_T lastCos_j;                    /* '<Root>/Sine Wave2' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
  int32_T systemEnable_b;              /* '<Root>/Sine Wave1' */
  int32_T systemEnable_c;              /* '<Root>/Sine Wave2' */
} DW_three_phase_inverter_with__T;

/* Parameters (default storage) */
struct P_three_phase_inverter_with_e_T_ {
  real_T SineWave_Amp;                 /* Expression: 0.9
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 160*pi
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave1_Amp;                /* Expression: 0.9
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 160*pi
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: (-2*pi)/3
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Hsin;               /* Computed Parameter: SineWave1_Hsin
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_HCos;               /* Computed Parameter: SineWave1_HCos
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_PSin;               /* Computed Parameter: SineWave1_PSin
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_PCos;               /* Computed Parameter: SineWave1_PCos
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 0.9
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 160*pi
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: (2*pi)/3
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Hsin;               /* Computed Parameter: SineWave2_Hsin
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_HCos;               /* Computed Parameter: SineWave2_HCos
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_PSin;               /* Computed Parameter: SineWave2_PSin
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_PCos;               /* Computed Parameter: SineWave2_PCos
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_three_phase_inverter__T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick1;
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_three_phase_inverter_with_e_T three_phase_inverter_with_epw_P;

/* Block states (default storage) */
extern DW_three_phase_inverter_with__T three_phase_inverter_with_ep_DW;

/* External function called from main */
extern void three_phase_inverter_with_epwm_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void three_phase_inverter_with_epwm_initialize(void);
extern void three_phase_inverter_with_epwm_step0(void);
extern void three_phase_inverter_with_epwm_step1(void);
extern void three_phase_inverter_with_epwm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_three_phase_inverter_T *const three_phase_inverter_with_ep_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Scope' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'three_phase_inverter_with_epwm'
 */
#endif                                 /* three_phase_inverter_with_epwm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
