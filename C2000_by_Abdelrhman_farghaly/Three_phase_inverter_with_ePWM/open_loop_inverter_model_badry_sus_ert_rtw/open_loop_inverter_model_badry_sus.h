/*
 * File: open_loop_inverter_model_badry_sus.h
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 13:43:15 2025
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
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                 /* open_loop_inverter_model_badry_sus_COMMON_INCLUDES_ */

#include "open_loop_inverter_model_badry_sus_types.h"
#include <stddef.h>
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define open_loop_inverter_model_badry_sus_M (open_loop_inverter_model_bad_M)

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void configureIXbar(void);

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<Root>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<Root>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<Root>/Discrete-Time Integrator2' */
  uint16_T Output_DSTATE;              /* '<S8>/Output' */
  uint16_T Output_DSTATE_n;            /* '<S5>/Output' */
  uint16_T Output_DSTATE_f;            /* '<S11>/Output' */
} DW_open_loop_inverter_model_b_T;

/* Parameters (default storage) */
struct P_open_loop_inverter_model_ba_T_ {
  real_T RepeatingSequenceInterpolated2_[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated2_
                               * Referenced by: '<S2>/Lookup'
                               */
  real_T RepeatingSequenceInterpolated1_[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated1_
                               * Referenced by: '<S1>/Lookup'
                               */
  real_T RepeatingSequenceInterpolated3_[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated3_
                               * Referenced by: '<S3>/Lookup'
                               */
  real_T RepeatingSequenceInterpolated_h[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated_h
                               * Referenced by: '<S2>/Lookup'
                               */
  real_T RepeatingSequenceInterpolated_c[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated_c
                               * Referenced by: '<S1>/Lookup'
                               */
  real_T RepeatingSequenceInterpolated_a[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated_a
                               * Referenced by: '<S3>/Lookup'
                               */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S13>/FixPt Switch'
                                        */
  uint16_T WrapToZero_Threshold_n;     /* Mask Parameter: WrapToZero_Threshold_n
                                        * Referenced by: '<S7>/FixPt Switch'
                                        */
  uint16_T WrapToZero_Threshold_a;     /* Mask Parameter: WrapToZero_Threshold_a
                                        * Referenced by: '<S10>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 50
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Gain2_Gain;                   /* Expression: .9/50
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T SampleTimeMath_WtEt;         /* Computed Parameter: SampleTimeMath_WtEt
                                       * Referenced by: '<S2>/Sample Time Math'
                                       */
  real_T Constant1_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain3_Gain;                   /* Expression: .9/50
                                        * Referenced by: '<Root>/Gain3'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator1'
                                        */
  real_T SampleTimeMath_WtEt_c;     /* Computed Parameter: SampleTimeMath_WtEt_c
                                     * Referenced by: '<S1>/Sample Time Math'
                                     */
  real_T Constant2_Value;              /* Expression: 50
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Gain4_Gain;                   /* Expression: .9/50
                                        * Referenced by: '<Root>/Gain4'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator2_gainval
                           * Referenced by: '<Root>/Discrete-Time Integrator2'
                           */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator2'
                                        */
  real_T SampleTimeMath_WtEt_b;     /* Computed Parameter: SampleTimeMath_WtEt_b
                                     * Referenced by: '<S3>/Sample Time Math'
                                     */
  real_T Gain7_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<Root>/Gain7'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<Root>/Gain5'
                                        */
  real_T Gain6_Gain;                   /* Expression: 2*pi
                                        * Referenced by: '<Root>/Gain6'
                                        */
  uint16_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint16_T Gain1_Gain;                 /* Computed Parameter: Gain1_Gain
                                        * Referenced by: '<Root>/Gain1'
                                        */
  uint16_T Gain8_Gain;                 /* Computed Parameter: Gain8_Gain
                                        * Referenced by: '<Root>/Gain8'
                                        */
  uint16_T Constant_Value_l;           /* Computed Parameter: Constant_Value_l
                                        * Referenced by: '<S7>/Constant'
                                        */
  uint16_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S10>/Constant'
                                        */
  uint16_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S13>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S8>/Output'
                                   */
  uint16_T Output_InitialCondition_p;
                                /* Computed Parameter: Output_InitialCondition_p
                                 * Referenced by: '<S5>/Output'
                                 */
  uint16_T Output_InitialCondition_f;
                                /* Computed Parameter: Output_InitialCondition_f
                                 * Referenced by: '<S11>/Output'
                                 */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S12>/FixPt Constant'
                                       */
  uint16_T FixPtConstant_Value_m;   /* Computed Parameter: FixPtConstant_Value_m
                                     * Referenced by: '<S6>/FixPt Constant'
                                     */
  uint16_T FixPtConstant_Value_a;   /* Computed Parameter: FixPtConstant_Value_a
                                     * Referenced by: '<S9>/FixPt Constant'
                                     */
};

/* Real-time Model Data Structure */
struct tag_RTM_open_loop_inverter_mo_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (default storage) */
extern P_open_loop_inverter_model_ba_T open_loop_inverter_model_badr_P;

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
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S5>/Data Type Propagation' : Unused code path elimination
 * Block '<S6>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S7>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S2>/Data Type Propagation' : Unused code path elimination
 * Block '<S8>/Data Type Propagation' : Unused code path elimination
 * Block '<S9>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S10>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S3>/Data Type Propagation' : Unused code path elimination
 * Block '<S11>/Data Type Propagation' : Unused code path elimination
 * Block '<S12>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S13>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<S1>/Output' : Eliminate redundant signal conversion block
 * Block '<S2>/Output' : Eliminate redundant signal conversion block
 * Block '<S3>/Output' : Eliminate redundant signal conversion block
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
 * '<S1>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated1'
 * '<S2>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated2'
 * '<S3>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated3'
 * '<S4>'   : 'open_loop_inverter_model_badry_sus/powergui'
 * '<S5>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated1/LimitedCounter'
 * '<S6>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated1/LimitedCounter/Increment Real World'
 * '<S7>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated1/LimitedCounter/Wrap To Zero'
 * '<S8>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated2/LimitedCounter'
 * '<S9>'   : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated2/LimitedCounter/Increment Real World'
 * '<S10>'  : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated2/LimitedCounter/Wrap To Zero'
 * '<S11>'  : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated3/LimitedCounter'
 * '<S12>'  : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated3/LimitedCounter/Increment Real World'
 * '<S13>'  : 'open_loop_inverter_model_badry_sus/Repeating Sequence Interpolated3/LimitedCounter/Wrap To Zero'
 */
#endif                               /* open_loop_inverter_model_badry_sus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
