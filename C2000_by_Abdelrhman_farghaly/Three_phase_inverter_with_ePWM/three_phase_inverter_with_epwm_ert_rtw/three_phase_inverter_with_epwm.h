/*
 * File: three_phase_inverter_with_epwm.h
 *
 * Code generated for Simulink model 'three_phase_inverter_with_epwm'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Jun 20 16:25:24 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef three_phase_inverter_with_epwm_h_
#define three_phase_inverter_with_epwm_h_
#ifndef three_phase_inverter_with_epwm_COMMON_INCLUDES_
#define three_phase_inverter_with_epwm_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#include "MW_c2000DAC.h"
#endif                     /* three_phase_inverter_with_epwm_COMMON_INCLUDES_ */

#include <stddef.h>
#include "three_phase_inverter_with_epwm_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define three_phase_inverter_with_epwm_M (three_phase_inverter_with_ep_M)

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  real_T ADC;                          /* '<S2>/ADC' */
  real_T ADC1;                         /* '<S2>/ADC1' */
  uint16_T eQEP_o1;                    /* '<S7>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S7>/eQEP' */
} B_three_phase_inverter_with_e_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S9>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_DSTAT_o;/* '<S8>/Discrete-Time Integrator1' */
  real_T DiscreteTransferFcn_states;   /* '<S2>/Discrete Transfer Fcn' */
  real_T DiscreteTransferFcn1_states;  /* '<S2>/Discrete Transfer Fcn1' */
  real_T DiscreteTimeIntegrator1_PREV_U;/* '<S9>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator1_PREV__g;/* '<S8>/Discrete-Time Integrator1' */
  uint32_T Subsystem2_PREV_T[2];       /* '<Root>/Subsystem2' */
  uint16_T DiscreteTimeIntegrator1_SYSTEM_;/* '<S9>/Discrete-Time Integrator1' */
  uint16_T DiscreteTimeIntegrator1_SYSTE_l;/* '<S8>/Discrete-Time Integrator1' */
  boolean_T Subsystem2_RESET_ELAPS_T;  /* '<Root>/Subsystem2' */
} DW_three_phase_inverter_with__T;

/* Parameters (default storage) */
struct P_three_phase_inverter_with_e_T_ {
  real_T Ki;                           /* Variable: Ki
                                        * Referenced by:
                                        *   '<S8>/Gain2'
                                        *   '<S9>/Gain2'
                                        */
  real_T Kp;                           /* Variable: Kp
                                        * Referenced by:
                                        *   '<S8>/Gain1'
                                        *   '<S9>/Gain1'
                                        */
  real_T L;                            /* Variable: L
                                        * Referenced by:
                                        *   '<S1>/Constant2'
                                        *   '<S1>/Constant3'
                                        */
  real_T lambda;                       /* Variable: lambda
                                        * Referenced by:
                                        *   '<S1>/Constant1'
                                        *   '<S3>/Gain2'
                                        */
  real_T p;                            /* Variable: p
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T MechanicaltoElectricalPosition_;
                              /* Mask Parameter: MechanicaltoElectricalPosition_
                               * Referenced by: '<S31>/Number of pole pairs'
                               */
  real_T Out1_Y0;                      /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S2>/Out1'
                                        */
  real_T Out2_Y0;                      /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S2>/Out2'
                                        */
  real_T Out3_Y0;                      /* Computed Parameter: Out3_Y0
                                        * Referenced by: '<S2>/Out3'
                                        */
  real_T Gain5_Gain;                   /* Expression: 3.3/4095
                                        * Referenced by: '<S2>/Gain5'
                                        */
  real_T Constant2_Value;              /* Expression: 1.49
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Gain6_Gain;                   /* Expression: -1/0.177985
                                        * Referenced by: '<S2>/Gain6'
                                        */
  real_T Gain3_Gain;                   /* Expression: 3.3/4095
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Constant_Value;               /* Expression: 1.49
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T Gain4_Gain;                   /* Expression: -1/0.177985
                                        * Referenced by: '<S2>/Gain4'
                                        */
  real_T DiscreteTransferFcn_NumCoef;  /* Expression: [0.09516]
                                        * Referenced by: '<S2>/Discrete Transfer Fcn'
                                        */
  real_T DiscreteTransferFcn_DenCoef[2];/* Expression: [1 -0.9048]
                                         * Referenced by: '<S2>/Discrete Transfer Fcn'
                                         */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S2>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn1_NumCoef; /* Expression: [0.09516]
                                        * Referenced by: '<S2>/Discrete Transfer Fcn1'
                                        */
  real_T DiscreteTransferFcn1_DenCoef[2];/* Expression: [1 -0.9048]
                                          * Referenced by: '<S2>/Discrete Transfer Fcn1'
                                          */
  real_T DiscreteTransferFcn1_InitialSta;/* Expression: 0
                                          * Referenced by: '<S2>/Discrete Transfer Fcn1'
                                          */
  real_T Constant_Value_l;             /* Expression: maxAngleIn
                                        * Referenced by: '<S28>/Constant'
                                        */
  real_T Constant1_Value;              /* Expression: mechOffsetIn
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T ReplaceInport_Offset_Value;   /* Expression: 0
                                        * Referenced by: '<S22>/ReplaceInport_Offset'
                                        */
  real_T Pos_e_Y0;                     /* Computed Parameter: Pos_e_Y0
                                        * Referenced by: '<S7>/Pos_e'
                                        */
  real_T Constant_Value_j;             /* Expression: 7.853982e-04
                                        * Referenced by: '<S39>/Constant'
                                        */
  real_T Multiply_Gain;                /* Expression: 1/maxAngleIn
                                        * Referenced by: '<S27>/Multiply'
                                        */
  real_T Multiply1_Gain;               /* Expression: maxAngleIn
                                        * Referenced by: '<S27>/Multiply1'
                                        */
  real_T Gain1_Gain;                   /* Expression: 4095/(2*pi)
                                        * Referenced by: '<S7>/Gain1'
                                        */
  real_T Id_Y0;                        /* Computed Parameter: Id_Y0
                                        * Referenced by: '<S5>/Id'
                                        */
  real_T Iq_Y0;                        /* Computed Parameter: Iq_Y0
                                        * Referenced by: '<S5>/Iq'
                                        */
  real_T Gain_Gain;                    /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 0.5
                                        * Referenced by: '<S5>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 2/3
                                        * Referenced by: '<S5>/Gain2'
                                        */
  real_T Gain3_Gain_b;                 /* Expression: sqrt(3)/2
                                        * Referenced by: '<S5>/Gain3'
                                        */
  real_T Gain4_Gain_e;                 /* Expression: sqrt(3)/2
                                        * Referenced by: '<S5>/Gain4'
                                        */
  real_T Gain5_Gain_k;                 /* Expression: 2/3
                                        * Referenced by: '<S5>/Gain5'
                                        */
  real_T Vq_coupled_Y0;                /* Computed Parameter: Vq_coupled_Y0
                                        * Referenced by: '<S3>/Vq_coupled'
                                        */
  real_T Vd_coupled1_Y0;               /* Computed Parameter: Vd_coupled1_Y0
                                        * Referenced by: '<S3>/Vd_coupled1'
                                        */
  real_T Constant4_Value;              /* Expression: 1
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainval
                           * Referenced by: '<S9>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S9>/Discrete-Time Integrator1'
                                        */
  real_T Constant1_Value_o;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T DiscreteTimeIntegrator1_gainv_l;
                          /* Computed Parameter: DiscreteTimeIntegrator1_gainv_l
                           * Referenced by: '<S8>/Discrete-Time Integrator1'
                           */
  real_T DiscreteTimeIntegrator1_IC_p; /* Expression: 0
                                        * Referenced by: '<S8>/Discrete-Time Integrator1'
                                        */
  real_T Vq_Y0;                        /* Computed Parameter: Vq_Y0
                                        * Referenced by: '<S1>/Vq+'
                                        */
  real_T Vd_Y0;                        /* Computed Parameter: Vd_Y0
                                        * Referenced by: '<S1>/Vd+'
                                        */
  real_T Va_Y0;                        /* Computed Parameter: Va_Y0
                                        * Referenced by: '<S4>/Va'
                                        */
  real_T Vb_Y0;                        /* Computed Parameter: Vb_Y0
                                        * Referenced by: '<S4>/Vb'
                                        */
  real_T Vc_Y0;                        /* Computed Parameter: Vc_Y0
                                        * Referenced by: '<S4>/Vc'
                                        */
  real_T Gain_Gain_g;                  /* Expression: sqrt(3)
                                        * Referenced by: '<S4>/Gain'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: 1/2
                                        * Referenced by: '<S4>/Gain1'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 1/2
                                        * Referenced by: '<S4>/Gain2'
                                        */
  real_T one_by_two_Gain;              /* Expression: -0.5
                                        * Referenced by: '<S10>/one_by_two'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 2/sqrt(3)
                                        * Referenced by: '<S6>/Gain'
                                        */
  int16_T ResetMode_Value;             /* Computed Parameter: ResetMode_Value
                                        * Referenced by: '<S23>/ResetMode'
                                        */
  uint16_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S38>/Constant'
                                        */
  uint16_T Constant_Value_jr;          /* Computed Parameter: Constant_Value_jr
                                        * Referenced by: '<S25>/Constant'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S25>/Switch'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_three_phase_inverter__T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_three_phase_inverter_with_e_T three_phase_inverter_with_epw_P;

/* Block signals (default storage) */
extern B_three_phase_inverter_with_e_T three_phase_inverter_with_epw_B;

/* Block states (default storage) */
extern DW_three_phase_inverter_with__T three_phase_inverter_with_ep_DW;

/* Model entry point functions */
extern void three_phase_inverter_with_epwm_initialize(void);
extern void three_phase_inverter_with_epwm_step(void);
extern void three_phase_inverter_with_epwm_terminate(void);

/* Real-time Model object */
extern RT_MODEL_three_phase_inverter_T *const three_phase_inverter_with_ep_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S2>/Display' : Unused code path elimination
 * Block '<S2>/Display1' : Unused code path elimination
 * Block '<S2>/Display3' : Unused code path elimination
 * Block '<S2>/Scope1' : Unused code path elimination
 * Block '<S2>/Scope2' : Unused code path elimination
 * Block '<S2>/Scope4' : Unused code path elimination
 * Block '<S8>/Scope' : Unused code path elimination
 * Block '<S8>/Scope1' : Unused code path elimination
 * Block '<S9>/Scope' : Unused code path elimination
 * Block '<S9>/Scope1' : Unused code path elimination
 * Block '<S6>/Scope' : Unused code path elimination
 * Block '<S11>/Data Type Duplicate' : Unused code path elimination
 * Block '<S11>/Diff' : Unused code path elimination
 * Block '<S11>/TSamp' : Unused code path elimination
 * Block '<S11>/UD' : Unused code path elimination
 * Block '<S12>/1//T' : Unused code path elimination
 * Block '<S14>/Avoid Divide by Zero' : Unused code path elimination
 * Block '<S17>/Compare' : Unused code path elimination
 * Block '<S17>/Constant' : Unused code path elimination
 * Block '<S18>/Compare' : Unused code path elimination
 * Block '<S18>/Constant' : Unused code path elimination
 * Block '<S14>/Constant' : Unused code path elimination
 * Block '<S14>/Logical Operator' : Unused code path elimination
 * Block '<S14>/Max' : Unused code path elimination
 * Block '<S14>/Probe' : Unused code path elimination
 * Block '<S14>/Sum1' : Unused code path elimination
 * Block '<S14>/Time constant' : Unused code path elimination
 * Block '<S20>/Integrator' : Unused code path elimination
 * Block '<S20>/Saturation' : Unused code path elimination
 * Block '<S12>/K' : Unused code path elimination
 * Block '<S12>/Sum1' : Unused code path elimination
 * Block '<S7>/Scope5' : Unused code path elimination
 * Block '<S7>/Scope6' : Unused code path elimination
 * Block '<S25>/Data Type Duplicate' : Unused code path elimination
 * Block '<S22>/ReplaceInport_Npp' : Unused code path elimination
 * Block '<S23>/ReplaceInport_CountsPerRev' : Unused code path elimination
 * Block '<S23>/ReplaceInport_OneByCountsPerRev' : Unused code path elimination
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
 * '<Root>' : 'three_phase_inverter_with_epwm'
 * '<S1>'   : 'three_phase_inverter_with_epwm/Decoupling'
 * '<S2>'   : 'three_phase_inverter_with_epwm/Subsystem'
 * '<S3>'   : 'three_phase_inverter_with_epwm/Subsystem2'
 * '<S4>'   : 'three_phase_inverter_with_epwm/Subsystem3'
 * '<S5>'   : 'three_phase_inverter_with_epwm/Subsystem4'
 * '<S6>'   : 'three_phase_inverter_with_epwm/Subsystem5'
 * '<S7>'   : 'three_phase_inverter_with_epwm/Subsystem6'
 * '<S8>'   : 'three_phase_inverter_with_epwm/Subsystem2/PI_Controller_Id'
 * '<S9>'   : 'three_phase_inverter_with_epwm/Subsystem2/PI_Controller_Iq'
 * '<S10>'  : 'three_phase_inverter_with_epwm/Subsystem5/Half(Vmin+Vmax)'
 * '<S11>'  : 'three_phase_inverter_with_epwm/Subsystem6/Discrete Derivative'
 * '<S12>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter '
 * '<S13>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1'
 * '<S14>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Enable//disable time constant'
 * '<S15>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Initialization'
 * '<S16>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Integrator (Discrete or Continuous)'
 * '<S17>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Enable//disable time constant/Compare To Constant'
 * '<S18>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Enable//disable time constant/Compare To Zero'
 * '<S19>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Initialization/Init_u'
 * '<S20>'  : 'three_phase_inverter_with_epwm/Subsystem6/Low-Pass Filter /Integrator (Discrete or Continuous)/Discrete'
 * '<S21>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder'
 * '<S22>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position'
 * '<S23>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder'
 * '<S24>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec'
 * '<S25>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S26>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S27>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S28>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S29>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S30>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S31>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S32>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/DT_Handle'
 * '<S33>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionNoReset'
 * '<S34>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionResetAtIndex'
 * '<S35>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/Variant Subsystem'
 * '<S36>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/DT_Handle/floating-point'
 * '<S37>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S38>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S39>'  : 'three_phase_inverter_with_epwm/Subsystem6/Subsystem1/eQEP_Decoder/Quadrature Decoder/Variant Subsystem/Dialog'
 */
#endif                                 /* three_phase_inverter_with_epwm_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
