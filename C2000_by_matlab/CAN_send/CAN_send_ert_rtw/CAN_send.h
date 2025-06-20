/*
 * File: CAN_send.h
 *
 * Code generated for Simulink model 'CAN_send'.
 *
 * Model version                  : 1.2
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jun 20 09:34:45 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef CAN_send_h_
#define CAN_send_h_
#ifndef CAN_send_COMMON_INCLUDES_
#define CAN_send_COMMON_INCLUDES_
#include <string.h>
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "can_message.h"
#include "F2837xD_device.h"
#endif                                 /* CAN_send_COMMON_INCLUDES_ */

#include <stddef.h>
#include "CAN_send_types.h"
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

extern void init_eCAN_B ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam);

/* user code (top of export header file) */
#include "can_message.h"

/* Block signals (default storage) */
typedef struct {
  real_T Switch;                       /* '<Root>/Switch' */
  real_T PulseGenerator;               /* '<Root>/Pulse Generator' */
  uint16_T CANReceive_o2[8];           /* '<Root>/CAN Receive' */
  uint16_T FixPtSum1;                  /* '<S2>/FixPt Sum1' */
} B_CAN_send_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  int32_T DigitalOutput1_FRAC_LEN;     /* '<Root>/Digital Output1' */
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<Root>/Digital Output' */
  uint16_T Output_DSTATE;              /* '<S1>/Output' */
} DW_CAN_send_T;

/* Parameters (default storage) */
struct P_CAN_send_T_ {
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S3>/FixPt Switch'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;     /* Computed Parameter: PulseGenerator_Period
                                     * Referenced by: '<Root>/Pulse Generator'
                                     */
  real_T PulseGenerator_Duty;         /* Computed Parameter: PulseGenerator_Duty
                                       * Referenced by: '<Root>/Pulse Generator'
                                       */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  uint16_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<Root>/Switch'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S1>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S2>/FixPt Constant'
                                       */
};

/* Real-time Model Data Structure */
struct tag_RTM_CAN_send_T {
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

extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;
extern CAN_DATATYPE CAN_DATATYPE_GROUND;

/* Block parameters (default storage) */
extern P_CAN_send_T CAN_send_P;

/* Block signals (default storage) */
extern B_CAN_send_T CAN_send_B;

/* Block states (default storage) */
extern DW_CAN_send_T CAN_send_DW;

/* External function called from main */
extern void CAN_send_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void CAN_send_initialize(void);
extern void CAN_send_step0(void);
extern void CAN_send_step1(void);
extern void CAN_send_step2(void);
extern void CAN_send_terminate(void);

/* Real-time Model object */
extern RT_MODEL_CAN_send_T *const CAN_send_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Propagation' : Unused code path elimination
 * Block '<S2>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S3>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
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
 * '<Root>' : 'CAN_send'
 * '<S1>'   : 'CAN_send/Counter Limited'
 * '<S2>'   : 'CAN_send/Counter Limited/Increment Real World'
 * '<S3>'   : 'CAN_send/Counter Limited/Wrap To Zero'
 */
#endif                                 /* CAN_send_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
