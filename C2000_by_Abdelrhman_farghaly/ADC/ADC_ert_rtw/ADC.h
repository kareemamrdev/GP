/*
 * File: ADC.h
 *
 * Code generated for Simulink model 'ADC'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Mar  4 07:34:29 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef ADC_h_
#define ADC_h_
#ifndef ADC_COMMON_INCLUDES_
#define ADC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#endif                                 /* ADC_COMMON_INCLUDES_ */

#include <stddef.h>
#include "ADC_types.h"
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

/* Block signals (default storage) */
typedef struct {
  real_T Buffer[500];                  /* '<Root>/Buffer' */
  real_T Buffer1[500];                 /* '<Root>/Buffer1' */
  real_T ADC_l;                        /* '<Root>/ADC' */
  real_T ADC1;                         /* '<Root>/ADC1' */
} B_ADC_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T Buffer_inBufPtrIdx;          /* '<Root>/Buffer' */
  int32_T Buffer_outBufPtrIdx;         /* '<Root>/Buffer' */
  int32_T Buffer1_inBufPtrIdx;         /* '<Root>/Buffer1' */
  int32_T Buffer1_outBufPtrIdx;        /* '<Root>/Buffer1' */
} DW_ADC_T;

/* Parameters (default storage) */
struct P_ADC_T_ {
  real_T Gain_Gain;                    /* Expression: 3/4095
                                        * Referenced by: '<Root>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 500/3
                                        * Referenced by: '<Root>/Gain1'
                                        */
  real_T Buffer_ic;                    /* Expression: 0
                                        * Referenced by: '<Root>/Buffer'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3/4095
                                        * Referenced by: '<Root>/Gain2'
                                        */
  real_T Buffer1_ic;                   /* Expression: 0
                                        * Referenced by: '<Root>/Buffer1'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_ADC_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_ADC_T ADC_P;

/* Block signals (default storage) */
extern B_ADC_T ADC_B;

/* Block states (default storage) */
extern DW_ADC_T ADC_DW;

/* External function called from main */
extern void ADC_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void ADC_initialize(void);
extern void ADC_step0(void);
extern void ADC_step1(void);
extern void ADC_step2(void);
extern void ADC_terminate(void);

/* Real-time Model object */
extern RT_MODEL_ADC_T *const ADC_M;
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
 * '<Root>' : 'ADC'
 */
#endif                                 /* ADC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
