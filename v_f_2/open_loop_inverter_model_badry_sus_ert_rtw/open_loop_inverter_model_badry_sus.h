/*
 * File: open_loop_inverter_model_badry_sus.h
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 15:08:24 2025
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
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

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define open_loop_inverter_model_badry_sus_M (open_loop_inverter_model_bad_M)

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block signals (default storage) */
typedef struct {
  real_T frequency;                    /* '<Root>/Gain9' */
  real_T APhase;                       /* '<S1>/A-Phase' */
  real_T Add3;                         /* '<S4>/Add3' */
  uint16_T Gain;                       /* '<Root>/Gain' */
  boolean_T RelationalOperator;        /* '<S1>/Relational Operator' */
} B_open_loop_inverter_model_ba_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S1>/Discrete-Time Integrator' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData[3];
  } carrierandcontrol_PWORK;           /* '<S1>/carrier and control' */

  uint32_T m_bpIndex;                  /* '<S4>/1-D Lookup Table' */
} DW_open_loop_inverter_model_b_T;

/* Parameters (default storage) */
struct P_open_loop_inverter_model_ba_T_ {
  real_T Constant_Value;               /* Expression: 1500
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain9_Gain;                   /* Expression: 8/120
                                        * Referenced by: '<Root>/Gain9'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1/50
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T ModulationIndexLimiter_UpperSat;/* Expression: 0.9
                                          * Referenced by: '<S1>/Modulation Index Limiter'
                                          */
  real_T ModulationIndexLimiter_LowerSat;/* Expression: 0
                                          * Referenced by: '<S1>/Modulation Index Limiter'
                                          */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S1>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  real_T Constant3_Value;              /* Expression: sps.Delay
                                        * Referenced by: '<S4>/Constant3'
                                        */
  real_T Constant4_Value;              /* Expression: sps.Period
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T uib1_Gain;                    /* Expression: sps.Freq
                                        * Referenced by: '<S4>/1\ib1'
                                        */
  real_T uDLookupTable_tableData[3];   /* Expression: [0 2 0]
                                        * Referenced by: '<S4>/1-D Lookup Table'
                                        */
  real_T uDLookupTable_bp01Data[3];    /* Expression: [0 .5 1]
                                        * Referenced by: '<S4>/1-D Lookup Table'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S4>/Constant2'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Gain1_Gain_j;               /* Computed Parameter: Gain1_Gain_j
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint16_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<Root>/Gain8'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_open_loop_inverter_mo_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;

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
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTick2;
    struct {
      uint16_T TID[3];
    } TaskCounters;

    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[3];
  } Timing;
};

/* Block parameters (default storage) */
extern P_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_P;

/* Block signals (default storage) */
extern B_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_B;

/* Block states (default storage) */
extern DW_open_loop_inverter_model_b_T open_loop_inverter_model_bad_DW;

/* External function called from main */
extern void open_loop_inverter_model_badry_sus_SetEventsForThisBaseStep
  (boolean_T *eventFlags);

/* Model entry point functions */
extern void open_loop_inverter_model_badry_sus_initialize(void);
extern void open_loop_inverter_model_badry_sus_step0(void);
extern void open_loop_inverter_model_badry_sus_step2(void);
extern void open_loop_inverter_model_badry_sus_terminate(void);

/* Real-time Model object */
extern RT_MODEL_open_loop_inverter_m_T *const open_loop_inverter_model_bad_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Unit Delay' : Unused code path elimination
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
 * '<Root>' : 'open_loop_inverter_model_badry_sus'
 * '<S1>'   : 'open_loop_inverter_model_badry_sus/PWM control signal1'
 * '<S2>'   : 'open_loop_inverter_model_badry_sus/powergui'
 * '<S3>'   : 'open_loop_inverter_model_badry_sus/PWM control signal1/Triangle Generator'
 * '<S4>'   : 'open_loop_inverter_model_badry_sus/PWM control signal1/Triangle Generator/Model'
 */
#endif                               /* open_loop_inverter_model_badry_sus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
