/*
 * File: open_loop_inverter_model_badry_sus.h
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 9.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Sat May 10 20:28:53 2025
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
#include "rtw_continuous.h"
#include "rtw_solver.h"
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
} DW_open_loop_inverter_model_b_T;

/* Parameters (default storage) */
struct P_open_loop_inverter_model_ba_T_ {
  real_T Constant1_Value;              /* Expression: 1.8
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 120*pi
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.9
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<Root>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<Root>/Discrete-Time Integrator'
                                        */
  real_T Gain_Gain;                    /* Expression: 100
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Gain8_Gain;                   /* Expression: 100
                                        * Referenced by: '<Root>/Gain8'
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
 * Block '<Root>/Scope1' : Unused code path elimination
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
 * '<S1>'   : 'open_loop_inverter_model_badry_sus/powergui'
 */
#endif                               /* open_loop_inverter_model_badry_sus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
