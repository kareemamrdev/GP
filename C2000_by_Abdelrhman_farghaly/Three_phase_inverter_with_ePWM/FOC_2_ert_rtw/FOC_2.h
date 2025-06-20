/*
 * File: FOC_2.h
 *
 * Code generated for Simulink model 'FOC_2'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue May  6 16:54:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef FOC_2_h_
#define FOC_2_h_
#ifndef FOC_2_COMMON_INCLUDES_
#define FOC_2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#endif                                 /* FOC_2_COMMON_INCLUDES_ */

#include <stddef.h>
#include "FOC_2_types.h"
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
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block states (default storage) for system '<S50>/Switch Case Action Subsystem' */
typedef struct {
  int16_T SwitchCaseActionSubsystem_Subsy;
                                      /* '<S50>/Switch Case Action Subsystem' */
} DW_SwitchCaseActionSubsystem__T;

/* Block signals (default storage) */
typedef struct {
  real_T Iu_40;                        /* '<Root>/Iu_40' */
  real_T Iv_41;                        /* '<Root>/Iv_41' */
  real_T Iw_52;                        /* '<Root>/Iw_52' */
  real_T Probe[2];                     /* '<S14>/Probe' */
  real_T Constant1;                    /* '<S1>/Constant1' */
  real_T Saturation;                   /* '<S20>/Saturation' */
  real_T TmpRTBAtScope1Inport3;        /* '<S1>/Gain4' */
  real_T TmpRTBAtSum2Inport2;
  real_T Iq;
  real_T Sum1;                         /* '<S63>/Sum1' */
  real_T TmpRTBAtAddInport1;           /* '<S2>/Product' */
  real_T TmpRTBAtAddInport2;           /* '<S2>/Product1' */
  real_T Vq;                           /* '<S2>/Add' */
  real_T TmpRTBAtAddInport2_i;         /* '<S12>/Square1' */
  real_T TmpRTBAtLinearOperationInport2;
  real_T Vd;
  real_T Product;                      /* '<S63>/Product' */
  real_T TmpRTBAtProduct1Inport1;      /* '<S10>/Sin' */
  real_T Merge1;                       /* '<S12>/Merge1' */
  real_T TmpRTBAtProductInport1;       /* '<S10>/Cosine' */
  real_T Merge;                        /* '<S12>/Merge' */
  real_T V_beta;                       /* '<S10>/Add' */
  real_T TmpRTBAtProduct3Inport2;      /* '<S10>/Cosine1' */
  real_T TmpRTBAtProduct2Inport1;      /* '<S10>/Sin1' */
  real_T Vb;                           /* '<S10>/Gain2' */
  real_T Vc;                           /* '<S10>/Gain1' */
  real_T alpha;                        /* '<S45>/Gain2' */
  real_T beta;                         /* '<S45>/Gain5' */
  real_T Atan2;                        /* '<S51>/Atan2' */
  real_T K;                            /* '<S48>/Add3' */
  real_T Vr;                           /* '<S51>/Square Root' */
  real_T Saturation2;                  /* '<S51>/Saturation2' */
  real_T T1;                           /* '<S52>/Product' */
  real_T T2;                           /* '<S52>/Product1' */
  real_T Add7;                         /* '<S52>/Add7' */
  real_T ref1;                         /* '<S50>/Merge' */
  real_T ref2;                         /* '<S50>/Merge1' */
  real_T Merge2;                       /* '<S50>/Merge2' */
  real_T Probe_k[2];                   /* '<S72>/Probe' */
  real_T Probe_j[2];                   /* '<S28>/Probe' */
  real_T Probe_e[2];                   /* '<S21>/Probe' */
  real_T Probe_m[2];                   /* '<S35>/Probe' */
  real_T Switch;                       /* '<S13>/Switch' */
  real_T Gain2;                        /* '<S13>/Gain2' */
  real_T Saturation_h;                 /* '<S78>/Saturation' */
  real_T Sum1_c;                       /* '<S62>/Sum1' */
  real_T Vd_d;                         /* '<S2>/Add1' */
  real_T Product_o;                    /* '<S62>/Product' */
  real_T Gain4;                        /* '<S1>/Gain4' */
  real32_T DigitalInput3;              /* '<Root>/Digital Input3' */
  uint16_T DigitalInput4;              /* '<Root>/Digital Input4' */
  boolean_T RelationalOperator;        /* '<S46>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S46>/Relational Operator1' */
  boolean_T RelationalOperator2;       /* '<S46>/Relational Operator2' */
} B_FOC_2_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T Integrator_DSTATE;            /* '<S20>/Integrator' */
  real_T Integrator_DSTATE_j;          /* '<S44>/Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S63>/Discrete-Time Integrator1' */
  real_T Integrator_DSTATE_i;          /* '<S41>/Integrator' */
  real_T Integrator_DSTATE_iy;         /* '<S34>/Integrator' */
  real_T Integrator_DSTATE_b;          /* '<S27>/Integrator' */
  real_T UnitDelay_DSTATE;             /* '<S13>/Unit Delay' */
  real_T UD_DSTATE;                    /* '<S69>/UD' */
  real_T Integrator_DSTATE_o;          /* '<S78>/Integrator' */
  real_T DiscreteTimeIntegrator1_DSTAT_b;/* '<S62>/Discrete-Time Integrator1' */
  real_T TmpRTBAtScope1Inport3_Buffer0;/* synthesized block */
  real_T TmpRTBAtSum2Inport2_Buffer0;  /* synthesized block */
  real_T Iq_Buffer0;                   /* synthesized block */
  real_T TmpRTBAtAddInport1_Buffer0;   /* synthesized block */
  real_T TmpRTBAtAddInport2_Buffer0;   /* synthesized block */
  real_T TmpRTBAtAddInport2_Buffer0_e; /* synthesized block */
  real_T TmpRTBAtLinearOperationInport2_;/* synthesized block */
  real_T Vd_Buffer0;                   /* synthesized block */
  real_T TmpRTBAtProduct1Inport1_Buffer0;/* synthesized block */
  real_T TmpRTBAtProductInport1_Buffer0;/* synthesized block */
  real_T TmpRTBAtProduct3Inport2_Buffer0;/* synthesized block */
  real_T TmpRTBAtProduct2Inport1_Buffer0;/* synthesized block */
  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<S1>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_m;                    /* '<S63>/Scope1' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S12>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK;                       /* '<S63>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_k;                    /* '<S8>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_g;                    /* '<S51>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_f;                     /* '<S8>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope2_PWORK_n;                    /* '<S51>/Scope2' */

  struct {
    void *LoggedData[3];
  } Scope3_PWORK;                      /* '<S1>/Scope3' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK_mb;                   /* '<S45>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope2_PWORK_l;                    /* '<S8>/Scope2' */

  struct {
    void *LoggedData[2];
  } Scope4_PWORK;                      /* '<S1>/Scope4' */

  struct {
    void *LoggedData;
  } Scope_PWORK_l;                     /* '<S12>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_gr;                   /* '<S12>/Scope1' */

  struct {
    void *LoggedData[3];
  } Scope_PWORK_h;                     /* '<S13>/Scope' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_d;                    /* '<S12>/Scope3' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_ky;                   /* '<S62>/Scope1' */

  struct {
    void *LoggedData[2];
  } Scope_PWORK_b;                     /* '<S62>/Scope' */

  uint16_T Output_DSTATE;              /* '<S53>/Output' */
  uint16_T DelayInput1_DSTATE;         /* '<S68>/Delay Input1' */
  int16_T Integrator_PrevResetState;   /* '<S20>/Integrator' */
  int16_T Integrator_PrevResetState_a; /* '<S44>/Integrator' */
  int16_T Integrator_PrevResetState_h; /* '<S41>/Integrator' */
  int16_T Integrator_PrevResetState_o; /* '<S34>/Integrator' */
  int16_T Integrator_PrevResetState_d; /* '<S27>/Integrator' */
  int16_T Integrator_PrevResetState_m; /* '<S78>/Integrator' */
  int16_T Limitations_SubsysRanBC;     /* '<S12>/Limitations' */
  int16_T LinearOperation_SubsysRanBC; /* '<S12>/Linear Operation ' */
  uint16_T Integrator_IC_LOADING;      /* '<S20>/Integrator' */
  uint16_T Integrator_IC_LOADING_a;    /* '<S44>/Integrator' */
  uint16_T Integrator_IC_LOADING_e;    /* '<S41>/Integrator' */
  uint16_T Integrator_IC_LOADING_d;    /* '<S34>/Integrator' */
  uint16_T Integrator_IC_LOADING_o;    /* '<S27>/Integrator' */
  uint16_T Integrator_IC_LOADING_h;    /* '<S78>/Integrator' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem5;
                                     /* '<S50>/Switch Case Action Subsystem5' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem4;
                                     /* '<S50>/Switch Case Action Subsystem4' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem3;
                                     /* '<S50>/Switch Case Action Subsystem3' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem2;
                                     /* '<S50>/Switch Case Action Subsystem2' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem1;
                                     /* '<S50>/Switch Case Action Subsystem1' */
  DW_SwitchCaseActionSubsystem__T SwitchCaseActionSubsystem;
                                      /* '<S50>/Switch Case Action Subsystem' */
} DW_FOC_2_T;

/* Parameters (default storage) */
struct P_FOC_2_T_ {
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by:
                                        *   '<S62>/Gain2'
                                        *   '<S63>/Gain2'
                                        */
  real_T Ki_s;                         /* Variable: Ki_s
                                        * Referenced by: '<S7>/Gain4'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S62>/Gain1'
                                        *   '<S63>/Gain1'
                                        */
  real_T Kp_s;                         /* Variable: Kp_s
                                        * Referenced by: '<S7>/Gain3'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S2>/Constant2'
                                        *   '<S2>/Constant3'
                                        */
  real_T T_period;                     /* Variable: T_period
                                        * Referenced by:
                                        *   '<S52>/Constant'
                                        *   '<S52>/Gain6'
                                        */
  real_T Vdc;                          /* Variable: Vdc
                                        * Referenced by:
                                        *   '<S12>/Constant'
                                        *   '<S51>/Saturation2'
                                        *   '<S52>/Vdc'
                                        *   '<S66>/Gain1'
                                        *   '<S66>/Gain2'
                                        */
  real_T lambda;                       /* Variable: lambda
                                        * Referenced by:
                                        *   '<S1>/Gain2'
                                        *   '<S2>/Constant1'
                                        */
  real_T ma;                           /* Variable: ma
                                        * Referenced by:
                                        *   '<S12>/Gain'
                                        *   '<S66>/Gain1'
                                        *   '<S66>/Gain2'
                                        */
  real_T p;                            /* Variable: p
                                        * Referenced by: '<S1>/Gain2'
                                        */
  real_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S69>/UD'
                               */
  real_T LowPassFilter_K;              /* Mask Parameter: LowPassFilter_K
                                        * Referenced by: '<S3>/K'
                                        */
  real_T LowPassFilter3_K;             /* Mask Parameter: LowPassFilter3_K
                                        * Referenced by: '<S6>/K'
                                        */
  real_T LowPassFilter2_K;             /* Mask Parameter: LowPassFilter2_K
                                        * Referenced by: '<S5>/K'
                                        */
  real_T LowPassFilter1_K;             /* Mask Parameter: LowPassFilter1_K
                                        * Referenced by: '<S4>/K'
                                        */
  real_T LowPassFilter_K_g;            /* Mask Parameter: LowPassFilter_K_g
                                        * Referenced by: '<S70>/K'
                                        */
  real_T RepeatingSequenceInterpolated1_[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated1_
                               * Referenced by: '<S47>/Lookup'
                               */
  real_T LowPassFilter_T;              /* Mask Parameter: LowPassFilter_T
                                        * Referenced by: '<S14>/Time constant'
                                        */
  real_T LowPassFilter3_T;             /* Mask Parameter: LowPassFilter3_T
                                        * Referenced by: '<S35>/Time constant'
                                        */
  real_T LowPassFilter2_T;             /* Mask Parameter: LowPassFilter2_T
                                        * Referenced by: '<S28>/Time constant'
                                        */
  real_T LowPassFilter1_T;             /* Mask Parameter: LowPassFilter1_T
                                        * Referenced by: '<S21>/Time constant'
                                        */
  real_T LowPassFilter_T_k;            /* Mask Parameter: LowPassFilter_T_k
                                        * Referenced by: '<S72>/Time constant'
                                        */
  real_T RepeatingSequenceInterpolated_j[3];
                              /* Mask Parameter: RepeatingSequenceInterpolated_j
                               * Referenced by: '<S47>/Lookup'
                               */
  real_T CompareToConstant_const;     /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S17>/Constant'
                                       */
  real_T CompareToConstant1_const;   /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S42>/Constant'
                                      */
  real_T CompareToConstant_const_f; /* Mask Parameter: CompareToConstant_const_f
                                     * Referenced by: '<S38>/Constant'
                                     */
  real_T CompareToConstant_const_o; /* Mask Parameter: CompareToConstant_const_o
                                     * Referenced by: '<S31>/Constant'
                                     */
  real_T CompareToConstant_const_m; /* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S24>/Constant'
                                     */
  real_T CompareToConstant_const_l; /* Mask Parameter: CompareToConstant_const_l
                                     * Referenced by: '<S75>/Constant'
                                     */
  real_T LowPassFilter_init_option; /* Mask Parameter: LowPassFilter_init_option
                                     * Referenced by: '<S14>/Constant'
                                     */
  real_T LowPassFilter3_init_option;
                                   /* Mask Parameter: LowPassFilter3_init_option
                                    * Referenced by: '<S35>/Constant'
                                    */
  real_T LowPassFilter2_init_option;
                                   /* Mask Parameter: LowPassFilter2_init_option
                                    * Referenced by: '<S28>/Constant'
                                    */
  real_T LowPassFilter1_init_option;
                                   /* Mask Parameter: LowPassFilter1_init_option
                                    * Referenced by: '<S21>/Constant'
                                    */
  real_T LowPassFilter_init_option_f;
                                  /* Mask Parameter: LowPassFilter_init_option_f
                                   * Referenced by: '<S72>/Constant'
                                   */
  uint16_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S55>/FixPt Switch'
                                        */
  uint16_T DetectRisePositive_vinit; /* Mask Parameter: DetectRisePositive_vinit
                                      * Referenced by: '<S68>/Delay Input1'
                                      */
  real_T Gain_Gain;                    /* Expression: sqrt(3)
                                        * Referenced by: '<S66>/Gain'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<S13>/Constant4'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: 3000
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T Integrator_UpperSat;          /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T Integrator_LowerSat;          /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S20>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: windupUpperLimit
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: windupLowerLimit
                                        * Referenced by: '<S20>/Saturation'
                                        */
  real_T TmpRTBAtScope1Inport3_InitialCo;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain1_Gain;                   /* Expression: 2*pi/60
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T TmpRTBAtSum2Inport2_InitialCond;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Integrator_gainval_p;       /* Computed Parameter: Integrator_gainval_p
                                      * Referenced by: '<S44>/Integrator'
                                      */
  real_T Integrator_UpperSat_n;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S44>/Integrator'
                                        */
  real_T Integrator_LowerSat_k;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S44>/Integrator'
                                        */
  real_T Saturation_UpperSat_b;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S44>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S44>/Saturation'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: 3.8
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: -3.8
                                        * Referenced by: '<S7>/Saturation'
                                        */
  real_T Iq_InitialCondition;          /* Expression: 0
                                        * Referenced by:
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S63>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S63>/Discrete-Time Integrator1'
                                        */
  real_T TmpRTBAtAddInport1_InitialCondi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtAddInport2_InitialCondi;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtAddInport2_InitialCon_j;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtLinearOperationInport2_;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Vd_InitialCondition;          /* Expression: 0
                                        * Referenced by:
                                        */
  real_T Constant12_Value;             /* Expression: 0
                                        * Referenced by: '<S48>/Constant12'
                                        */
  real_T TmpRTBAtProduct1Inport1_Initial;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtProductInport1_InitialC;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtProduct3Inport2_Initial;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T TmpRTBAtProduct2Inport1_Initial;/* Expression: 0
                                          * Referenced by:
                                          */
  real_T Gain_Gain_g;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S10>/Gain'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1/2
                                        * Referenced by: '<S10>/Gain2'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 0.5
                                        * Referenced by: '<S45>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1/2
                                        * Referenced by: '<S10>/Gain1'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: 0.5
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real_T Gain2_Gain_k;                 /* Expression: 2/3
                                        * Referenced by: '<S45>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S45>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: sqrt(3)/2
                                        * Referenced by: '<S45>/Gain4'
                                        */
  real_T Gain5_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S45>/Gain5'
                                        */
  real_T Gain13_Gain;                  /* Expression: 180/pi
                                        * Referenced by: '<S48>/Gain13'
                                        */
  real_T Constant13_Value;             /* Expression: 60
                                        * Referenced by: '<S48>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 60
                                        * Referenced by: '<S48>/Constant14'
                                        */
  real_T Constant15_Value;             /* Expression: 120
                                        * Referenced by: '<S48>/Constant15'
                                        */
  real_T Gain15_Gain;                  /* Expression: 2
                                        * Referenced by: '<S48>/Gain15'
                                        */
  real_T Constant16_Value;             /* Expression: 120
                                        * Referenced by: '<S48>/Constant16'
                                        */
  real_T Constant17_Value;             /* Expression: 180
                                        * Referenced by: '<S48>/Constant17'
                                        */
  real_T Gain16_Gain;                  /* Expression: 3
                                        * Referenced by: '<S48>/Gain16'
                                        */
  real_T Constant18_Value;             /* Expression: -180
                                        * Referenced by: '<S48>/Constant18'
                                        */
  real_T Constant19_Value;             /* Expression: -120
                                        * Referenced by: '<S48>/Constant19'
                                        */
  real_T Gain17_Gain;                  /* Expression: 4
                                        * Referenced by: '<S48>/Gain17'
                                        */
  real_T Constant20_Value;             /* Expression: -120
                                        * Referenced by: '<S48>/Constant20'
                                        */
  real_T Constant21_Value;             /* Expression: -60
                                        * Referenced by: '<S48>/Constant21'
                                        */
  real_T Gain18_Gain;                  /* Expression: 5
                                        * Referenced by: '<S48>/Gain18'
                                        */
  real_T Constant22_Value;             /* Expression: -60
                                        * Referenced by: '<S48>/Constant22'
                                        */
  real_T Constant23_Value;             /* Expression: 0
                                        * Referenced by: '<S48>/Constant23'
                                        */
  real_T Gain19_Gain;                  /* Expression: 6
                                        * Referenced by: '<S48>/Gain19'
                                        */
  real_T Gain7_Gain;                   /* Expression: pi/3
                                        * Referenced by: '<S52>/Gain7'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S51>/Saturation2'
                                        */
  real_T const_Value;                  /* Expression: 1
                                        * Referenced by: '<S52>/const'
                                        */
  real_T Gain8_Gain;                   /* Expression: pi/3
                                        * Referenced by: '<S52>/Gain8'
                                        */
  real_T Gain9_Gain;                   /* Expression: 0.5
                                        * Referenced by: '<S49>/Gain9'
                                        */
  real_T Gain12_Gain;                  /* Expression: 0.5
                                        * Referenced by: '<S49>/Gain12'
                                        */
  real_T Gain11_Gain;                  /* Expression: 0.5
                                        * Referenced by: '<S49>/Gain11'
                                        */
  real_T Gain10_Gain;                  /* Expression: 0.5
                                        * Referenced by: '<S49>/Gain10'
                                        */
  real_T SampleTimeMath_WtEt;         /* Computed Parameter: SampleTimeMath_WtEt
                                       * Referenced by: '<S47>/Sample Time Math'
                                       */
  real_T Merge_InitialOutput;         /* Computed Parameter: Merge_InitialOutput
                                       * Referenced by: '<S50>/Merge'
                                       */
  real_T Merge1_InitialOutput;       /* Computed Parameter: Merge1_InitialOutput
                                      * Referenced by: '<S50>/Merge1'
                                      */
  real_T Merge2_InitialOutput;       /* Computed Parameter: Merge2_InitialOutput
                                      * Referenced by: '<S50>/Merge2'
                                      */
  real_T Constant_Value_o;             /* Expression: 0
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Integrator_gainval_j;       /* Computed Parameter: Integrator_gainval_j
                                      * Referenced by: '<S41>/Integrator'
                                      */
  real_T Integrator_UpperSat_d;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Integrator_LowerSat_j;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S41>/Integrator'
                                        */
  real_T Saturation_UpperSat_h;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Saturation_LowerSat_l;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S41>/Saturation'
                                        */
  real_T Constant3_Value;              /* Expression: 1.38
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/0.177985
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 0.5
                                        * Referenced by: '<S11>/Gain1'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S32>/Constant'
                                        */
  real_T Integrator_gainval_n;       /* Computed Parameter: Integrator_gainval_n
                                      * Referenced by: '<S34>/Integrator'
                                      */
  real_T Integrator_UpperSat_f;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S34>/Integrator'
                                        */
  real_T Integrator_LowerSat_jk;       /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S34>/Integrator'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S34>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S34>/Saturation'
                                        */
  real_T Constant_Value_c;             /* Expression: 1.38
                                        * Referenced by: '<S1>/Constant'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 1/0.177985
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T Constant_Value_m;             /* Expression: 0
                                        * Referenced by: '<S25>/Constant'
                                        */
  real_T Integrator_gainval_m;       /* Computed Parameter: Integrator_gainval_m
                                      * Referenced by: '<S27>/Integrator'
                                      */
  real_T Integrator_UpperSat_fq;       /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S27>/Integrator'
                                        */
  real_T Integrator_LowerSat_a;        /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S27>/Integrator'
                                        */
  real_T Saturation_UpperSat_c;        /* Expression: windupUpperLimit
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S27>/Saturation'
                                        */
  real_T Constant2_Value;              /* Expression: 1.38
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Gain5_Gain_i;                 /* Expression: 1/0.177985
                                        * Referenced by: '<S1>/Gain5'
                                        */
  real_T Gain_Gain_go;                 /* Expression: 0.5
                                        * Referenced by: '<S11>/Gain'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 2/3
                                        * Referenced by: '<S11>/Gain2'
                                        */
  real_T Constant2_Value_i;            /* Expression: 1
                                        * Referenced by: '<S13>/Constant2'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S13>/Unit Delay'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 2*pi /2000
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: 4
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Constant3_Value_h;            /* Expression: 2*pi
                                        * Referenced by: '<S13>/Constant3'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: sqrt(3)/2
                                        * Referenced by: '<S11>/Gain3'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: sqrt(3)/2
                                        * Referenced by: '<S11>/Gain4'
                                        */
  real_T Gain5_Gain_ij;                /* Expression: 2/3
                                        * Referenced by: '<S11>/Gain5'
                                        */
  real_T Constant_Value_p;             /* Expression: 0
                                        * Referenced by: '<S76>/Constant'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S69>/TSamp'
                                        */
  real_T Integrator_gainval_o;       /* Computed Parameter: Integrator_gainval_o
                                      * Referenced by: '<S78>/Integrator'
                                      */
  real_T Integrator_UpperSat_k;        /* Expression: antiwindupUpperLimit
                                        * Referenced by: '<S78>/Integrator'
                                        */
  real_T Integrator_LowerSat_jn;       /* Expression: antiwindupLowerLimit
                                        * Referenced by: '<S78>/Integrator'
                                        */
  real_T Saturation_UpperSat_al;       /* Expression: windupUpperLimit
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: windupLowerLimit
                                        * Referenced by: '<S78>/Saturation'
                                        */
  real_T Id_Ref_Value;                 /* Expression: 0
                                        * Referenced by: '<S1>/Id_Ref'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_m;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_m
                           * Referenced by: '<S62>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC_c; /* Expression: 0
                                        * Referenced by: '<S62>/Discrete-Time Integrator1'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: 60/(2*pi)
                                        * Referenced by: '<S1>/Gain4'
                                        */
  real32_T Gain1_Gain_b;               /* Computed Parameter: Gain1_Gain_b
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S13>/Gain'
                                        */
  real32_T Switch2_Threshold;          /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S13>/Switch2'
                                        */
  real32_T Gain14_Gain;                /* Computed Parameter: Gain14_Gain
                                        * Referenced by: '<S48>/Gain14'
                                        */
  real32_T Constant_Value_m4;          /* Computed Parameter: Constant_Value_m4
                                        * Referenced by: '<S71>/Constant'
                                        */
  uint16_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S55>/Constant'
                                        */
  uint16_T Output_InitialCondition;
                                  /* Computed Parameter: Output_InitialCondition
                                   * Referenced by: '<S53>/Output'
                                   */
  uint16_T FixPtConstant_Value;       /* Computed Parameter: FixPtConstant_Value
                                       * Referenced by: '<S54>/FixPt Constant'
                                       */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S13>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_FOC_2_T {
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
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    struct {
      uint32_T TID[2];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
    } RateInteraction;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_FOC_2_T FOC_2_P;

/* Block signals (default storage) */
extern B_FOC_2_T FOC_2_B;

/* Block states (default storage) */
extern DW_FOC_2_T FOC_2_DW;

/* External function called from main */
extern void FOC_2_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void FOC_2_initialize(void);
extern void FOC_2_step0(void);
extern void FOC_2_step1(void);
extern void FOC_2_terminate(void);

/* Real-time Model object */
extern RT_MODEL_FOC_2_T *const FOC_2_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S47>/Data Type Propagation' : Unused code path elimination
 * Block '<S53>/Data Type Propagation' : Unused code path elimination
 * Block '<S54>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S55>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S12>/Abs' : Unused code path elimination
 * Block '<S12>/Abs1' : Unused code path elimination
 * Block '<S12>/Add1' : Unused code path elimination
 * Block '<S12>/Add2' : Unused code path elimination
 * Block '<S64>/Compare' : Unused code path elimination
 * Block '<S64>/Constant' : Unused code path elimination
 * Block '<S65>/Compare' : Unused code path elimination
 * Block '<S65>/Constant' : Unused code path elimination
 * Block '<S12>/Delay' : Unused code path elimination
 * Block '<S12>/Delay1' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S47>/Output' : Eliminate redundant signal conversion block
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
 * '<Root>' : 'FOC_2'
 * '<S1>'   : 'FOC_2/Subsystem3'
 * '<S2>'   : 'FOC_2/Subsystem3/Decoupling'
 * '<S3>'   : 'FOC_2/Subsystem3/Low-Pass Filter '
 * '<S4>'   : 'FOC_2/Subsystem3/Low-Pass Filter 1'
 * '<S5>'   : 'FOC_2/Subsystem3/Low-Pass Filter 2'
 * '<S6>'   : 'FOC_2/Subsystem3/Low-Pass Filter 3'
 * '<S7>'   : 'FOC_2/Subsystem3/PI_Controller_speed'
 * '<S8>'   : 'FOC_2/Subsystem3/SVPWM'
 * '<S9>'   : 'FOC_2/Subsystem3/Subsystem2'
 * '<S10>'  : 'FOC_2/Subsystem3/Subsystem3'
 * '<S11>'  : 'FOC_2/Subsystem3/Subsystem4'
 * '<S12>'  : 'FOC_2/Subsystem3/Subsystem5'
 * '<S13>'  : 'FOC_2/Subsystem3/encoder demux1'
 * '<S14>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Enable//disable time constant'
 * '<S15>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Initialization'
 * '<S16>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Integrator (Discrete or Continuous)'
 * '<S17>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Enable//disable time constant/Compare To Constant'
 * '<S18>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Enable//disable time constant/Compare To Zero'
 * '<S19>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Initialization/Init_u'
 * '<S20>'  : 'FOC_2/Subsystem3/Low-Pass Filter /Integrator (Discrete or Continuous)/Discrete'
 * '<S21>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Enable//disable time constant'
 * '<S22>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Initialization'
 * '<S23>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Integrator (Discrete or Continuous)'
 * '<S24>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Enable//disable time constant/Compare To Constant'
 * '<S25>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Enable//disable time constant/Compare To Zero'
 * '<S26>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Initialization/Init_u'
 * '<S27>'  : 'FOC_2/Subsystem3/Low-Pass Filter 1/Integrator (Discrete or Continuous)/Discrete'
 * '<S28>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Enable//disable time constant'
 * '<S29>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Initialization'
 * '<S30>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Integrator (Discrete or Continuous)'
 * '<S31>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Enable//disable time constant/Compare To Constant'
 * '<S32>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Enable//disable time constant/Compare To Zero'
 * '<S33>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Initialization/Init_u'
 * '<S34>'  : 'FOC_2/Subsystem3/Low-Pass Filter 2/Integrator (Discrete or Continuous)/Discrete'
 * '<S35>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Enable//disable time constant'
 * '<S36>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Initialization'
 * '<S37>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Integrator (Discrete or Continuous)'
 * '<S38>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Enable//disable time constant/Compare To Constant'
 * '<S39>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Enable//disable time constant/Compare To Zero'
 * '<S40>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Initialization/Init_u'
 * '<S41>'  : 'FOC_2/Subsystem3/Low-Pass Filter 3/Integrator (Discrete or Continuous)/Discrete'
 * '<S42>'  : 'FOC_2/Subsystem3/PI_Controller_speed/Compare To Constant1'
 * '<S43>'  : 'FOC_2/Subsystem3/PI_Controller_speed/Integrator (Discrete or Continuous)'
 * '<S44>'  : 'FOC_2/Subsystem3/PI_Controller_speed/Integrator (Discrete or Continuous)/Discrete'
 * '<S45>'  : 'FOC_2/Subsystem3/SVPWM/ABC to alpha-beta'
 * '<S46>'  : 'FOC_2/Subsystem3/SVPWM/PWM'
 * '<S47>'  : 'FOC_2/Subsystem3/SVPWM/Repeating Sequence Interpolated1'
 * '<S48>'  : 'FOC_2/Subsystem3/SVPWM/Sector selection'
 * '<S49>'  : 'FOC_2/Subsystem3/SVPWM/Subsystem3'
 * '<S50>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal'
 * '<S51>'  : 'FOC_2/Subsystem3/SVPWM/polar form'
 * '<S52>'  : 'FOC_2/Subsystem3/SVPWM/time equations'
 * '<S53>'  : 'FOC_2/Subsystem3/SVPWM/Repeating Sequence Interpolated1/LimitedCounter'
 * '<S54>'  : 'FOC_2/Subsystem3/SVPWM/Repeating Sequence Interpolated1/LimitedCounter/Increment Real World'
 * '<S55>'  : 'FOC_2/Subsystem3/SVPWM/Repeating Sequence Interpolated1/LimitedCounter/Wrap To Zero'
 * '<S56>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem'
 * '<S57>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem1'
 * '<S58>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem2'
 * '<S59>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem3'
 * '<S60>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem4'
 * '<S61>'  : 'FOC_2/Subsystem3/SVPWM/Time equations to Referance signal/Switch Case Action Subsystem5'
 * '<S62>'  : 'FOC_2/Subsystem3/Subsystem2/PI_Controller_Id'
 * '<S63>'  : 'FOC_2/Subsystem3/Subsystem2/PI_Controller_Iq'
 * '<S64>'  : 'FOC_2/Subsystem3/Subsystem5/Compare To Constant'
 * '<S65>'  : 'FOC_2/Subsystem3/Subsystem5/Compare To Constant1'
 * '<S66>'  : 'FOC_2/Subsystem3/Subsystem5/Limitations'
 * '<S67>'  : 'FOC_2/Subsystem3/Subsystem5/Linear Operation '
 * '<S68>'  : 'FOC_2/Subsystem3/encoder demux1/Detect Rise Positive'
 * '<S69>'  : 'FOC_2/Subsystem3/encoder demux1/Discrete Derivative'
 * '<S70>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter '
 * '<S71>'  : 'FOC_2/Subsystem3/encoder demux1/Detect Rise Positive/Positive'
 * '<S72>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Enable//disable time constant'
 * '<S73>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Initialization'
 * '<S74>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Integrator (Discrete or Continuous)'
 * '<S75>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Enable//disable time constant/Compare To Constant'
 * '<S76>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Enable//disable time constant/Compare To Zero'
 * '<S77>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Initialization/Init_u'
 * '<S78>'  : 'FOC_2/Subsystem3/encoder demux1/Low-Pass Filter /Integrator (Discrete or Continuous)/Discrete'
 */
#endif                                 /* FOC_2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
