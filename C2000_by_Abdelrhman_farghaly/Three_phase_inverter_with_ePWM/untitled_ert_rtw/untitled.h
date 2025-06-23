/*
 * File: untitled.h
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jun 20 15:14:13 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef untitled_h_
#define untitled_h_
#ifndef untitled_COMMON_INCLUDES_
#define untitled_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#include "MW_c2000DAC.h"
#endif                                 /* untitled_COMMON_INCLUDES_ */

#include <stddef.h>
#include "untitled_types.h"
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
  real_T Probe[2];                     /* '<S6>/Probe' */
  real_T Saturation;                   /* '<S12>/Saturation' */
  real_T Sum;                          /* '<Root>/Sum' */
  real_T Sum_i;                        /* '<S55>/Sum' */
  real_T Product1[3];                  /* '<S4>/Product1' */
  real_T Fcn;                          /* '<Root>/Fcn' */
  real_T Add;                          /* '<S72>/Add' */
  uint16_T eQEP_o1;                    /* '<Root>/eQEP' */
  uint16_T eQEP_o2;                    /* '<Root>/eQEP' */
} B_untitled_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S4>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S1>/UD' */
  real_T Integrator_DSTATE;            /* '<S12>/Integrator' */
  real_T Integrator_DSTATE_h;          /* '<S46>/Integrator' */
  struct {
    void *LoggedData;
  } ControlSignals_PWORK;              /* '<S4>/Control Signals' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } ErrorandFreqCommand_PWORK;         /* '<Root>/Error and Freq Command' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<Root>/Scope5' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  int16_T Integrator_PrevResetState;   /* '<S12>/Integrator' */
  int16_T PositionResetAtIndex_SubsysRanB;/* '<S68>/PositionResetAtIndex' */
  int16_T PositionNoReset_SubsysRanBC; /* '<S68>/PositionNoReset' */
  int16_T IfActionSubsystem1_SubsysRanBC;/* '<S71>/If Action Subsystem1' */
  int16_T IfActionSubsystem_SubsysRanBC;/* '<S71>/If Action Subsystem' */
  uint16_T Integrator_IC_LOADING;      /* '<S12>/Integrator' */
} DW_untitled_T;

/* Parameters (default storage) */
struct P_untitled_T_ {
  real_T PIDController_I;              /* Mask Parameter: PIDController_I
                                        * Referenced by: '<S43>/Integral Gain'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S1>/UD'
                               */
  real_T PIDController_InitialConditionF;
                              /* Mask Parameter: PIDController_InitialConditionF
                               * Referenced by: '<S46>/Integrator'
                               */
  real_T LowPassFilter_K;              /* Mask Parameter: LowPassFilter_K
                                        * Referenced by: '<S2>/K'
                                        */
  real_T MechanicaltoElectricalPosition_;
                              /* Mask Parameter: MechanicaltoElectricalPosition_
                               * Referenced by: '<S76>/Number of pole pairs'
                               */
  real_T PIDController_P;              /* Mask Parameter: PIDController_P
                                        * Referenced by: '<S51>/Proportional Gain'
                                        */
  real_T LowPassFilter_T;              /* Mask Parameter: LowPassFilter_T
                                        * Referenced by: '<S6>/Time constant'
                                        */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S9>/Constant'
                                       */
  real_T LowPassFilter_init_option; /* Mask Parameter: LowPassFilter_init_option
                                     * Referenced by: '<S6>/Constant'
                                     */
  real_T Constant_Value;               /* Expression: maxAngleIn
                                        * Referenced by: '<S73>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: mechOffsetIn
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T ReplaceInport_Offset_Value;   /* Expression: 0
                                        * Referenced by: '<S67>/ReplaceInport_Offset'
                                        */
  real_T IntroducingPhaseShift_Value[3];/* Expression: [0 2/3 1/3]
                                         * Referenced by: '<S4>/Introducing Phase Shift'
                                         */
  real_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S4>/Discrete-Time Integrator'
                            */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_g;             /* Expression: 1000
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Constant_Value_gf;            /* Expression: 0
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Constant_Value_m;             /* Expression: 7.853982e-04
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S1>/TSamp'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S12>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S12>/Saturation'
                                        */
  real_T Integrator_gainval_m;       /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S46>/Integrator'
                                      */
  real_T AdjustingModulationIndex_Gain;/* Expression: 1/60
                                        * Referenced by: '<S4>/Adjusting Modulation Index'
                                        */
  real_T ModulationIndexLimiter_UpperSat;/* Expression: 0.9
                                          * Referenced by: '<S4>/Modulation Index Limiter'
                                          */
  real_T ModulationIndexLimiter_LowerSat;/* Expression: 0
                                          * Referenced by: '<S4>/Modulation Index Limiter'
                                          */
  real_T Multiply_Gain;                /* Expression: 1/maxAngleIn
                                        * Referenced by: '<S72>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: maxAngleIn
                                        * Referenced by: '<S72>/Multiply1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4095/(2*pi)
                                        * Referenced by: '<Root>/Gain1'
                                        */
  int16_T ResetMode_Value;             /* Computed Parameter: ResetMode_Value
                                        * Referenced by: '<S68>/ResetMode'
                                        */
  int16_T LookUpTable_tableData[33];/* Computed Parameter: LookUpTable_tableData
                                     * Referenced by: '<S64>/Look-Up Table'
                                     */
  uint16_T Point50_Value;              /* Computed Parameter: Point50_Value
                                        * Referenced by: '<S65>/Point50'
                                        */
  uint16_T Point25_Value;              /* Computed Parameter: Point25_Value
                                        * Referenced by: '<S65>/Point25'
                                        */
  uint16_T LookUpTable_bp01Data[33]; /* Computed Parameter: LookUpTable_bp01Data
                                      * Referenced by: '<S64>/Look-Up Table'
                                      */
  uint16_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S83>/Constant'
                                        */
  uint16_T Constant_Value_i;           /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S70>/Constant'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S70>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_untitled_T {
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
extern P_untitled_T untitled_P;

/* Block signals (default storage) */
extern B_untitled_T untitled_B;

/* Block states (default storage) */
extern DW_untitled_T untitled_DW;

/* Model entry point functions */
extern void untitled_initialize(void);
extern void untitled_step(void);
extern void untitled_terminate(void);

/* Real-time Model object */
extern RT_MODEL_untitled_T *const untitled_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Data Type Duplicate' : Unused code path elimination
 * Block '<S70>/Data Type Duplicate' : Unused code path elimination
 * Block '<S67>/ReplaceInport_Npp' : Unused code path elimination
 * Block '<S68>/ReplaceInport_CountsPerRev' : Unused code path elimination
 * Block '<S68>/ReplaceInport_OneByCountsPerRev' : Unused code path elimination
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
 * '<Root>' : 'untitled'
 * '<S1>'   : 'untitled/Discrete Derivative'
 * '<S2>'   : 'untitled/Low-Pass Filter '
 * '<S3>'   : 'untitled/PID Controller'
 * '<S4>'   : 'untitled/Reference Sine Generation'
 * '<S5>'   : 'untitled/Subsystem1'
 * '<S6>'   : 'untitled/Low-Pass Filter /Enable//disable time constant'
 * '<S7>'   : 'untitled/Low-Pass Filter /Initialization'
 * '<S8>'   : 'untitled/Low-Pass Filter /Integrator (Discrete or Continuous)'
 * '<S9>'   : 'untitled/Low-Pass Filter /Enable//disable time constant/Compare To Constant'
 * '<S10>'  : 'untitled/Low-Pass Filter /Enable//disable time constant/Compare To Zero'
 * '<S11>'  : 'untitled/Low-Pass Filter /Initialization/Init_u'
 * '<S12>'  : 'untitled/Low-Pass Filter /Integrator (Discrete or Continuous)/Discrete'
 * '<S13>'  : 'untitled/PID Controller/Anti-windup'
 * '<S14>'  : 'untitled/PID Controller/D Gain'
 * '<S15>'  : 'untitled/PID Controller/External Derivative'
 * '<S16>'  : 'untitled/PID Controller/Filter'
 * '<S17>'  : 'untitled/PID Controller/Filter ICs'
 * '<S18>'  : 'untitled/PID Controller/I Gain'
 * '<S19>'  : 'untitled/PID Controller/Ideal P Gain'
 * '<S20>'  : 'untitled/PID Controller/Ideal P Gain Fdbk'
 * '<S21>'  : 'untitled/PID Controller/Integrator'
 * '<S22>'  : 'untitled/PID Controller/Integrator ICs'
 * '<S23>'  : 'untitled/PID Controller/N Copy'
 * '<S24>'  : 'untitled/PID Controller/N Gain'
 * '<S25>'  : 'untitled/PID Controller/P Copy'
 * '<S26>'  : 'untitled/PID Controller/Parallel P Gain'
 * '<S27>'  : 'untitled/PID Controller/Reset Signal'
 * '<S28>'  : 'untitled/PID Controller/Saturation'
 * '<S29>'  : 'untitled/PID Controller/Saturation Fdbk'
 * '<S30>'  : 'untitled/PID Controller/Sum'
 * '<S31>'  : 'untitled/PID Controller/Sum Fdbk'
 * '<S32>'  : 'untitled/PID Controller/Tracking Mode'
 * '<S33>'  : 'untitled/PID Controller/Tracking Mode Sum'
 * '<S34>'  : 'untitled/PID Controller/Tsamp - Integral'
 * '<S35>'  : 'untitled/PID Controller/Tsamp - Ngain'
 * '<S36>'  : 'untitled/PID Controller/postSat Signal'
 * '<S37>'  : 'untitled/PID Controller/preSat Signal'
 * '<S38>'  : 'untitled/PID Controller/Anti-windup/Passthrough'
 * '<S39>'  : 'untitled/PID Controller/D Gain/Disabled'
 * '<S40>'  : 'untitled/PID Controller/External Derivative/Disabled'
 * '<S41>'  : 'untitled/PID Controller/Filter/Disabled'
 * '<S42>'  : 'untitled/PID Controller/Filter ICs/Disabled'
 * '<S43>'  : 'untitled/PID Controller/I Gain/Internal Parameters'
 * '<S44>'  : 'untitled/PID Controller/Ideal P Gain/Passthrough'
 * '<S45>'  : 'untitled/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S46>'  : 'untitled/PID Controller/Integrator/Discrete'
 * '<S47>'  : 'untitled/PID Controller/Integrator ICs/Internal IC'
 * '<S48>'  : 'untitled/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S49>'  : 'untitled/PID Controller/N Gain/Disabled'
 * '<S50>'  : 'untitled/PID Controller/P Copy/Disabled'
 * '<S51>'  : 'untitled/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S52>'  : 'untitled/PID Controller/Reset Signal/Disabled'
 * '<S53>'  : 'untitled/PID Controller/Saturation/Passthrough'
 * '<S54>'  : 'untitled/PID Controller/Saturation Fdbk/Disabled'
 * '<S55>'  : 'untitled/PID Controller/Sum/Sum_PI'
 * '<S56>'  : 'untitled/PID Controller/Sum Fdbk/Disabled'
 * '<S57>'  : 'untitled/PID Controller/Tracking Mode/Disabled'
 * '<S58>'  : 'untitled/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S59>'  : 'untitled/PID Controller/Tsamp - Integral/TsSignalSpecification'
 * '<S60>'  : 'untitled/PID Controller/Tsamp - Ngain/Passthrough'
 * '<S61>'  : 'untitled/PID Controller/postSat Signal/Forward_Path'
 * '<S62>'  : 'untitled/PID Controller/preSat Signal/Forward_Path'
 * '<S63>'  : 'untitled/Reference Sine Generation/Sine Generator'
 * '<S64>'  : 'untitled/Reference Sine Generation/Sine Generator/Sine'
 * '<S65>'  : 'untitled/Reference Sine Generation/Sine Generator/Sine/Handle Quarter Symmetry Sine'
 * '<S66>'  : 'untitled/Subsystem1/eQEP_Decoder'
 * '<S67>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position'
 * '<S68>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder'
 * '<S69>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec'
 * '<S70>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S71>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S72>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S73>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S74>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S75>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S76>'  : 'untitled/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S77>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/DT_Handle'
 * '<S78>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionNoReset'
 * '<S79>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionResetAtIndex'
 * '<S80>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/Variant Subsystem'
 * '<S81>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/DT_Handle/floating-point'
 * '<S82>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S83>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S84>'  : 'untitled/Subsystem1/eQEP_Decoder/Quadrature Decoder/Variant Subsystem/Dialog'
 */
#endif                                 /* untitled_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
