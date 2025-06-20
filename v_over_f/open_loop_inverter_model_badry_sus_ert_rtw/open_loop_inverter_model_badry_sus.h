/*
 * File: open_loop_inverter_model_badry_sus.h
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 13:25:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef open_loop_inverter_model_badry_sus_h_
#define open_loop_inverter_model_badry_sus_h_
#ifndef open_loop_inverter_model_badry_sus_COMMON_INCLUDES_
#define open_loop_inverter_model_badry_sus_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                 /* open_loop_inverter_model_badry_sus_COMMON_INCLUDES_ */

#include "open_loop_inverter_model_badry_sus_types.h"
#include <string.h>
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

#define open_loop_inverter_model_badry_sus_M (open_loop_inverter_model_bad_M)

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  real_T Fcn3;                         /* '<Root>/Fcn3' */
} B_open_loop_inverter_model_ba_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<Root>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator4_DSTATE;/* '<Root>/Discrete-Time Integrator4' */
  real_T DiscreteTimeIntegrator5_DSTATE;/* '<Root>/Discrete-Time Integrator5' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */
} DW_open_loop_inverter_model_b_T;

/* Parameters (default storage) */
struct P_open_loop_inverter_model_ba_T_ {
  real_T Constant3_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Gain11_Gain;                  /* Expression: .9/50
                                        * Referenced by: '<Root>/Gain11'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator3_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator3'
                           */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator3'
                                        */
  real_T Constant4_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Gain12_Gain;                  /* Expression: .9/50
                                        * Referenced by: '<Root>/Gain12'
                                        */
  real_T DiscreteTimeIntegrator4_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator4_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator4'
                           */
  real_T DiscreteTimeIntegrator4_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator4'
                                        */
  real_T Constant5_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T Gain13_Gain;                  /* Expression: .9/50
                                        * Referenced by: '<Root>/Gain13'
                                        */
  real_T DiscreteTimeIntegrator5_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator5_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator5'
                           */
  real_T DiscreteTimeIntegrator5_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator5'
                                        */
  real_T Gain16_Gain;                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Gain16'
                                        */
  real_T Gain14_Gain;                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Gain14'
                                        */
  real_T Gain15_Gain;                  /* Expression: 2*pi
                                        * Referenced by: '<Root>/Gain15'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_open_loop_inverter_mo_T {
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
extern P_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_P;

/* Block signals (default storage) */
extern B_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_B;

/* Block states (default storage) */
extern DW_open_loop_inverter_model_b_T open_loop_inverter_model_bad_DW;

/* Model entry point functions */
extern void open_loop_inverter_model_badry_sus_initialize(void);
extern void open_loop_inverter_model_badry_sus_step(void);
extern void open_loop_inverter_model_badry_sus_terminate(void);

/* Real-time Model object */
extern RT_MODEL_open_loop_inverter_m_T *const open_loop_inverter_model_bad_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'open_loop_inverter_model_badry_sus'
 * '<S1>'   : 'open_loop_inverter_model_badry_sus/powergui'
 */
#endif                               /* open_loop_inverter_model_badry_sus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
