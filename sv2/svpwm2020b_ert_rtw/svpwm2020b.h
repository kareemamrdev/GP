/*
 * File: svpwm2020b.h
 *
 * Code generated for Simulink model 'svpwm2020b'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 18:11:17 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef svpwm2020b_h_
#define svpwm2020b_h_
#ifndef svpwm2020b_COMMON_INCLUDES_
#define svpwm2020b_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* svpwm2020b_COMMON_INCLUDES_ */

#include "svpwm2020b_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T SineWave1;                    /* '<Root>/Sine Wave1' */
  real_T Gain[3];                      /* '<S4>/Gain' */
  real_T One_by_Two[3];                /* '<Root>/One_by_Two' */
  real_T PWM_Duty_Cycles[3];           /* '<Root>/Sum' */
} B_svpwm2020b_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[3];
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<Root>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  int32_T counter;                     /* '<Root>/Sine Wave' */
  int32_T counter_h;                   /* '<Root>/Sine Wave1' */
} DW_svpwm2020b_T;

/* Parameters (default storage) */
struct P_svpwm2020b_T_ {
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_NumSamp;             /* Expression: 314
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Offset;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T Ka_Gain;                      /* Expression: 1
                                        * Referenced by: '<S8>/Ka'
                                        */
  real_T one_by_two_Gain;              /* Expression: 1/2
                                        * Referenced by: '<S8>/one_by_two'
                                        */
  real_T SineWave1_Amp;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_NumSamp;            /* Expression: 314
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Offset;             /* Expression: 79
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T sqrt3_by_two_Gain;            /* Expression: sqrt(3)/2
                                        * Referenced by: '<S8>/sqrt3_by_two'
                                        */
  real_T Kb_Gain;                      /* Expression: 1
                                        * Referenced by: '<S8>/Kb'
                                        */
  real_T Kc_Gain;                      /* Expression: 1
                                        * Referenced by: '<S8>/Kc'
                                        */
  real_T one_by_two_Gain_j;            /* Expression: -0.5
                                        * Referenced by: '<S5>/one_by_two'
                                        */
  real_T Gain_Gain;                    /* Expression: 2/sqrt(3)
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T One_by_Two_Gain;              /* Expression: 0.5
                                        * Referenced by: '<Root>/One_by_Two'
                                        */
  real_T ShiftingUP_Value;             /* Expression: 0.5
                                        * Referenced by: '<Root>/Shifting UP'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 6667
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_svpwm2020b_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_svpwm2020b_T svpwm2020b_P;

/* Block signals (default storage) */
extern B_svpwm2020b_T svpwm2020b_B;

/* Block states (default storage) */
extern DW_svpwm2020b_T svpwm2020b_DW;

/* Model entry point functions */
extern void svpwm2020b_initialize(void);
extern void svpwm2020b_step(void);
extern void svpwm2020b_terminate(void);

/* Real-time Model object */
extern RT_MODEL_svpwm2020b_T *const svpwm2020b_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S1>/Vc' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
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
 * '<Root>' : 'svpwm2020b'
 * '<S1>'   : 'svpwm2020b/PWM Reference Generator'
 * '<S2>'   : 'svpwm2020b/PWM Reference Generator/Modulation method'
 * '<S3>'   : 'svpwm2020b/PWM Reference Generator/Voltage Input'
 * '<S4>'   : 'svpwm2020b/PWM Reference Generator/Modulation method/SVPWM'
 * '<S5>'   : 'svpwm2020b/PWM Reference Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S6>'   : 'svpwm2020b/PWM Reference Generator/Voltage Input/Valphabeta'
 * '<S7>'   : 'svpwm2020b/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S8>'   : 'svpwm2020b/PWM Reference Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 */
#endif                                 /* svpwm2020b_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
