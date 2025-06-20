/*
 * File: SVM_CG.h
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

#ifndef SVM_CG_h_
#define SVM_CG_h_
#ifndef SVM_CG_COMMON_INCLUDES_
#define SVM_CG_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* SVM_CG_COMMON_INCLUDES_ */

#include <stddef.h>
#include "SVM_CG_types.h"
#include "rtGetNaN.h"
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
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block states (default storage) for system '<S7>/Switch Case Action Subsystem' */
typedef struct {
  int16_T SwitchCaseActionSubsystem_Subsy;/* '<S7>/Switch Case Action Subsystem' */
} DW_SwitchCaseActionSubsystem__T;

/* Block signals (default storage) */
typedef struct {
  real_T SineWave;                     /* '<Root>/Sine Wave' */
  real_T SineWave1;                    /* '<Root>/Sine Wave1' */
  real_T SineWave2;                    /* '<Root>/Sine Wave2' */
  real_T alpha;                        /* '<S2>/Gain2' */
  real_T beta;                         /* '<S2>/Gain5' */
  real_T Vr;                           /* '<S8>/Square Root' */
  real_T Saturation2;                  /* '<S8>/Saturation2' */
  real_T Atan2;                        /* '<S8>/Atan2' */
  real_T K;                            /* '<S5>/Add3' */
  real_T T1;                           /* '<S9>/Product' */
  real_T T2;                           /* '<S9>/Product1' */
  real_T Add7;                         /* '<S9>/Add7' */
  real_T ref1;                         /* '<S7>/Merge' */
  real_T ref2;                         /* '<S7>/Merge1' */
  real_T Merge2;                       /* '<S7>/Merge2' */
  boolean_T RelationalOperator;        /* '<S3>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S3>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S3>/Relational Operator2' */
} B_SVM_CG_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<S2>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_b;                    /* '<S8>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_e;                    /* '<S1>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK;                       /* '<S1>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK;                      /* '<S8>/Scope2' */

  struct {
    void *LoggedData[3];
  } Scope2_PWORK_g;                    /* '<S1>/Scope2' */

  uint16_T Output_DSTATE;              /* '<S10>/Output' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem5;
                                      /* '<S7>/Switch Case Action Subsystem5' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem4;
                                      /* '<S7>/Switch Case Action Subsystem4' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem3;
                                      /* '<S7>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem2;
                                      /* '<S7>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem1;
                                      /* '<S7>/Switch Case Action Subsystem1' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem;/* '<S7>/Switch Case Action Subsystem' */
} DW_SVM_CG_T;

/* Parameters (default storage) */
struct P_SVM_CG_T_ {
  real_T T_period;                     /* Variable: T_period
                                        * Referenced by:
                                        *   '<S9>/Constant'
                                        *   '<S9>/Gain6'
                                        */
  real_T Vdc;                          /* Variable: Vdc
                                        * Referenced by:
                                        *   '<S8>/Saturation2'
                                        *   '<S9>/Vdc'
                                        */
  real_T RepeatingSequenceInterpolated1_[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated1_
                               * Referenced by: '<S4>/Lookup'
                               */
  real_T RepeatingSequenceInterpolated_g[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated_g
                               * Referenced by: '<S4>/Lookup'
                               */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S12>/FixPt Switch'
                                        */
  real_T SineWave_Amp;                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave1_Amp;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Freq;               /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave1_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave1'
                                        */
  real_T SineWave2_Amp;                /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Bias;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Freq;               /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T SineWave2_Phase;              /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave2'
                                        */
  real_T Gain1_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S2>/Gain5'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S8>/Saturation2'
                                        */
  real_T Gain13_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S5>/Gain13'
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 60
                                        * Referenced by: '<S5>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 60
                                        * Referenced by: '<S5>/Constant14'
                                        */
  real_T Constant15_Value;             /* Expression: 120
                                        * Referenced by: '<S5>/Constant15'
                                        */
  real_T Gain15_Gain;                  /* Expression: 2
                                        * Referenced by: '<S5>/Gain15'
                                        */
  real_T Constant16_Value;             /* Expression: 120
                                        * Referenced by: '<S5>/Constant16'
                                        */
  real_T Constant17_Value;             /* Expression: 180
                                        * Referenced by: '<S5>/Constant17'
                                        */
  real_T Gain16_Gain;                  /* Expression: 3
                                        * Referenced by: '<S5>/Gain16'
                                        */
  real_T Constant18_Value;             /* Expression: -180
                                        * Referenced by: '<S5>/Constant18'
                                        */
  real_T Constant19_Value;             /* Expression: -120
                                        * Referenced by: '<S5>/Constant19'
                                        */
  real_T Gain17_Gain;                  /* Expression: 4
                                        * Referenced by: '<S5>/Gain17'
                                        */
  real_T Constant20_Value;             /* Expression: -120
                                        * Referenced by: '<S5>/Constant20'
                                        */
  real_T Constant21_Value;             /* Expression: -60
                                        * Referenced by: '<S5>/Constant21'
                                        */
  real_T Gain18_Gain;                  /* Expression: 5
                                        * Referenced by: '<S5>/Gain18'
                                        */
  real_T Constant22_Value;             /* Expression: -60
                                        * Referenced by: '<S5>/Constant22'
                                        */
  real_T Constant23_Value;             /* Expression: 0
                                        * Referenced by: '<S5>/Constant23'
                                        */
  real_T Gain19_Gain;                  /* Expression: 6
                                        * Referenced by: '<S5>/Gain19'
                                        */
  real_T Gain7_Gain;                   /* Expression: pi/3
                                        * Referenced by: '<S9>/Gain7'
                                        */
  real_T const_Value;                  /* Expression: 1
                                        * Referenced by: '<S9>/const'
                                        */
  real_T Gain8_Gain;                   /* Expression: pi/3
                                        * Referenced by: '<S9>/Gain8'
                                        */
  real_T Gain9_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S6>/Gain9'
                                        */
  real_T Gain12_Gain;                  /* Expression: 0.5
                                        * Referenced by: '<S6>/Gain12'
                                        */
  real_T Gain11_Gain;                  /* Expression: 0.5
                                        * Referenced by: '<S6>/Gain11'
                                        */
  real_T Gain10_Gain;                  /* Expression: 0.5
                                        * Referenced by: '<S6>/Gain10'
                                        */
  real_T SampleTimeMath_WtEt;         /* Computed Parameter: SampleTimeMath_WtEt
                                       * Referenced by: '<S4>/Sample Time Math'
                                       */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S7>/Merge'
                                       */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S7>/Merge1'
                                      */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S7>/Merge2'
                                      */
  real32_T Gain14_Gain;                /* Computed Parameter: Gain14_Gain
                                        * Referenced by: '<S5>/Gain14'
                                        */
  uint16_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S10>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S11>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_SVM_CG_T {
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_SVM_CG_T SVM_CG_P;

/* Block signals (default storage) */
extern B_SVM_CG_T SVM_CG_B;

/* Block states (default storage) */
extern DW_SVM_CG_T SVM_CG_DW;

/* Model entry point functions */
extern void SVM_CG_initialize(void);
extern void SVM_CG_step(void);
extern void SVM_CG_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SVM_CG_T *const SVM_CG_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S4>/Data Type Propagation' : Unused code path elimination
 * Block '<S10>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S4>/Output' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'SVM_CG'
 * '<S1>'   : 'SVM_CG/SVPWM'
 * '<S2>'   : 'SVM_CG/SVPWM/ABC to alpha-beta'
 * '<S3>'   : 'SVM_CG/SVPWM/PWM'
 * '<S4>'   : 'SVM_CG/SVPWM/Repeating Sequence Interpolated1'
 * '<S5>'   : 'SVM_CG/SVPWM/Sector selection'
 * '<S6>'   : 'SVM_CG/SVPWM/Subsystem3'
 * '<S7>'   : 'SVM_CG/SVPWM/Time equations to Referance signal'
 * '<S8>'   : 'SVM_CG/SVPWM/polar form'
 * '<S9>'   : 'SVM_CG/SVPWM/time equations'
 * '<S10>'  : 'SVM_CG/SVPWM/Repeating Sequence Interpolated1/LimitedCounter'
 * '<S11>'  : 'SVM_CG/SVPWM/Repeating Sequence Interpolated1/LimitedCounter/Increment Real World'
 * '<S12>'  : 'SVM_CG/SVPWM/Repeating Sequence Interpolated1/LimitedCounter/Wrap To Zero'
 * '<S13>'  : 'SVM_CG/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem'
 * '<S14>'  : 'SVM_CG/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem1'
 * '<S15>'  : 'SVM_CG/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem2'
 * '<S16>'  : 'SVM_CG/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem3'
 * '<S17>'  : 'SVM_CG/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem4'
 * '<S18>'  : 'SVM_CG/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem5'
 */
#endif                                 /* SVM_CG_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
