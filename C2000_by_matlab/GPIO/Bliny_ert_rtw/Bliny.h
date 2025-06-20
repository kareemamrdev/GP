/*
 * File: Bliny.h
 *
 * Code generated for Simulink model 'Bliny'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Apr  2 11:45:48 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Bliny_h_
#define Bliny_h_
#ifndef Bliny_COMMON_INCLUDES_
#define Bliny_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#endif                                 /* Bliny_COMMON_INCLUDES_ */

#include <stddef.h>
#include "Bliny_types.h"
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
  uint16_T DigitalInput;               /* '<Root>/Digital Input' */
} B_Bliny_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
  int32_T DigitalOutput3_FRAC_LEN;     /* '<Root>/Digital Output3' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<Root>/Digital Output1' */
} DW_Bliny_T;

/* Parameters (default storage) */
struct P_Bliny_T_ {
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Bliny_T {
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
extern P_Bliny_T Bliny_P;

/* Block signals (default storage) */
extern B_Bliny_T Bliny_B;

/* Block states (default storage) */
extern DW_Bliny_T Bliny_DW;

/* External function called from main */
extern void Bliny_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void Bliny_initialize(void);
extern void Bliny_step0(void);
extern void Bliny_step1(void);
extern void Bliny_step2(void);
extern void Bliny_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Bliny_T *const Bliny_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Constant1' : Unused code path elimination
 * Block '<Root>/Pulse Generator' : Unused code path elimination
 * Block '<Root>/Pulse Generator1' : Unused code path elimination
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
 * '<Root>' : 'Bliny'
 */
#endif                                 /* Bliny_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
