/*
 * File: three_phase_inverter_with_epwm.c
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

#include "three_phase_inverter_with_epwm.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "three_phase_inverter_with_epwm_private.h"
#include <string.h>

/* Block signals (default storage) */
B_three_phase_inverter_with_e_T three_phase_inverter_with_epw_B;

/* Block states (default storage) */
DW_three_phase_inverter_with__T three_phase_inverter_with_ep_DW;

/* Real-time model */
static RT_MODEL_three_phase_inverter_T three_phase_inverter_with_ep_M_;
RT_MODEL_three_phase_inverter_T *const three_phase_inverter_with_ep_M =
  &three_phase_inverter_with_ep_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

/* Model step function */
void three_phase_inverter_with_epwm_step(void)
{
  real_T Subtract;
  real_T rtb_Gain1;
  real_T rtb_Gain2;
  real_T rtb_Gain2_e;
  real_T rtb_Gain2_tmp;
  real_T rtb_Product_o;
  real_T rtb_Switch;
  real_T rtb_alpha;
  uint32_T Subsystem2_ELAPS_T_idx_0;
  uint16_T rtb_Merge;
  uint16_T rtb_Sum3;
  boolean_T tmp;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* S-Function (c2802xadc): '<S2>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcbRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    three_phase_inverter_with_epw_B.ADC = (AdcbResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S2>/ADC1' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdccRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    three_phase_inverter_with_epw_B.ADC1 = (AdccResultRegs.ADCRESULT0);
  }

  /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  rtb_Gain2 = three_phase_inverter_with_epw_P.DiscreteTransferFcn_NumCoef *
    three_phase_inverter_with_ep_DW.DiscreteTransferFcn_states;

  /* DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn1' */
  rtb_alpha = three_phase_inverter_with_epw_P.DiscreteTransferFcn1_NumCoef *
    three_phase_inverter_with_ep_DW.DiscreteTransferFcn1_states;

  /* Sum: '<S2>/Subtract' incorporates:
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn1'
   */
  Subtract = (0.0 - rtb_alpha) - rtb_Gain2;

  /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' incorporates:
   *  Constant: '<S2>/Constant'
   *  Gain: '<S2>/Gain3'
   *  Gain: '<S2>/Gain4'
   *  Sum: '<S2>/Add'
   */
  three_phase_inverter_with_ep_DW.DiscreteTransferFcn_states =
    ((three_phase_inverter_with_epw_P.Gain3_Gain *
      three_phase_inverter_with_epw_B.ADC -
      three_phase_inverter_with_epw_P.Constant_Value) *
     three_phase_inverter_with_epw_P.Gain4_Gain -
     three_phase_inverter_with_epw_P.DiscreteTransferFcn_DenCoef[1L] *
     three_phase_inverter_with_ep_DW.DiscreteTransferFcn_states) /
    three_phase_inverter_with_epw_P.DiscreteTransferFcn_DenCoef[0];

  /* Update for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn1' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Gain: '<S2>/Gain5'
   *  Gain: '<S2>/Gain6'
   *  Sum: '<S2>/Add1'
   */
  three_phase_inverter_with_ep_DW.DiscreteTransferFcn1_states =
    ((three_phase_inverter_with_epw_P.Gain5_Gain *
      three_phase_inverter_with_epw_B.ADC1 -
      three_phase_inverter_with_epw_P.Constant2_Value) *
     three_phase_inverter_with_epw_P.Gain6_Gain -
     three_phase_inverter_with_epw_P.DiscreteTransferFcn1_DenCoef[1L] *
     three_phase_inverter_with_ep_DW.DiscreteTransferFcn1_states) /
    three_phase_inverter_with_epw_P.DiscreteTransferFcn1_DenCoef[0];

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem6'
   */
  /* S-Function (c280xqep): '<S7>/eQEP' */
  {
    three_phase_inverter_with_epw_B.eQEP_o1 = EQep2Regs.QPOSCNT;/*eQEP Position Counter*/
    three_phase_inverter_with_epw_B.eQEP_o2 = EQep2Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* If: '<S23>/If1' incorporates:
   *  Constant: '<S23>/ResetMode'
   */
  if (three_phase_inverter_with_epw_P.ResetMode_Value > 0) {
    /* Outputs for IfAction SubSystem: '<S23>/PositionNoReset' incorporates:
     *  ActionPort: '<S33>/Action Port'
     */
    /* Sum: '<S33>/Sum3' */
    rtb_Sum3 = three_phase_inverter_with_epw_B.eQEP_o1 -
      three_phase_inverter_with_epw_B.eQEP_o2;

    /* Sum: '<S33>/Sum7' incorporates:
     *  Constant: '<S38>/Constant'
     */
    rtb_Merge = rtb_Sum3 + three_phase_inverter_with_epw_P.Constant_Value_o;

    /* MinMax: '<S33>/MinMax' */
    if (rtb_Sum3 <= rtb_Merge) {
      rtb_Merge = rtb_Sum3;
    }

    /* End of MinMax: '<S33>/MinMax' */
    /* End of Outputs for SubSystem: '<S23>/PositionNoReset' */
  } else {
    /* Outputs for IfAction SubSystem: '<S23>/PositionResetAtIndex' incorporates:
     *  ActionPort: '<S34>/Action Port'
     */
    /* SignalConversion generated from: '<S34>/Count' */
    rtb_Merge = three_phase_inverter_with_epw_B.eQEP_o1;

    /* End of Outputs for SubSystem: '<S23>/PositionResetAtIndex' */
  }

  /* End of If: '<S23>/If1' */

  /* Product: '<S23>/Product' incorporates:
   *  Constant: '<S39>/Constant'
   *  DataTypeConversion: '<S36>/DTC'
   */
  rtb_Product_o = (real_T)rtb_Merge *
    three_phase_inverter_with_epw_P.Constant_Value_j;

  /* Switch: '<S25>/Switch' incorporates:
   *  Constant: '<S22>/ReplaceInport_Offset'
   *  Constant: '<S25>/Constant'
   *  Constant: '<S25>/Constant1'
   */
  if (three_phase_inverter_with_epw_P.Constant_Value_jr >
      three_phase_inverter_with_epw_P.Switch_Threshold) {
    rtb_Switch = three_phase_inverter_with_epw_P.Constant1_Value;
  } else {
    rtb_Switch = three_phase_inverter_with_epw_P.ReplaceInport_Offset_Value;
  }

  /* End of Switch: '<S25>/Switch' */

  /* If: '<S26>/If' incorporates:
   *  Constant: '<S28>/Constant'
   *  Gain: '<S31>/Number of pole pairs'
   *  Sum: '<S28>/Add'
   *  Sum: '<S29>/Add'
   */
  if (rtb_Product_o <= rtb_Switch) {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem' incorporates:
     *  ActionPort: '<S28>/Action Port'
     */
    rtb_Product_o = (rtb_Product_o +
                     three_phase_inverter_with_epw_P.Constant_Value_l) -
      rtb_Switch;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S26>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S29>/Action Port'
     */
    rtb_Product_o -= rtb_Switch;

    /* End of Outputs for SubSystem: '<S26>/If Action Subsystem1' */
  }

  rtb_Product_o *=
    three_phase_inverter_with_epw_P.MechanicaltoElectricalPosition_;

  /* End of If: '<S26>/If' */

  /* Sum: '<S27>/Add' incorporates:
   *  Gain: '<S27>/Multiply'
   *  Gain: '<S27>/Multiply1'
   *  Rounding: '<S27>/Floor'
   */
  rtb_Product_o -= floor(three_phase_inverter_with_epw_P.Multiply_Gain *
    rtb_Product_o) * three_phase_inverter_with_epw_P.Multiply1_Gain;

  /* MATLABSystem: '<S7>/DAC' incorporates:
   *  Gain: '<S7>/Gain1'
   */
  MW_C2000DACSat(0U, three_phase_inverter_with_epw_P.Gain1_Gain * rtb_Product_o);

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem4'
   */
  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* Gain: '<S5>/Gain2' incorporates:
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn1'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain1'
   *  Sum: '<S5>/Add2'
   */
  rtb_alpha = ((rtb_alpha - three_phase_inverter_with_epw_P.Gain_Gain * Subtract)
               - three_phase_inverter_with_epw_P.Gain1_Gain_d * rtb_Product_o) *
    three_phase_inverter_with_epw_P.Gain2_Gain;

  /* Gain: '<S5>/Gain5' incorporates:
   *  Gain: '<S5>/Gain3'
   *  Gain: '<S5>/Gain4'
   *  Sum: '<S5>/Add3'
   */
  Subtract = (three_phase_inverter_with_epw_P.Gain3_Gain_b * Subtract -
              three_phase_inverter_with_epw_P.Gain4_Gain_e * rtb_Product_o) *
    three_phase_inverter_with_epw_P.Gain5_Gain_k;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem2'
   */
  if (three_phase_inverter_with_ep_DW.Subsystem2_RESET_ELAPS_T) {
    Subsystem2_ELAPS_T_idx_0 = 0UL;
  } else {
    Subsystem2_ELAPS_T_idx_0 = three_phase_inverter_with_ep_M->Timing.clockTick0
      - three_phase_inverter_with_ep_DW.Subsystem2_PREV_T[0];
  }

  three_phase_inverter_with_ep_DW.Subsystem2_PREV_T[0L] =
    three_phase_inverter_with_ep_M->Timing.clockTick0;
  three_phase_inverter_with_ep_DW.Subsystem2_PREV_T[1L] =
    three_phase_inverter_with_ep_M->Timing.clockTickH0;
  three_phase_inverter_with_ep_DW.Subsystem2_RESET_ELAPS_T = false;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem4'
   */
  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* Trigonometry: '<S5>/Cosine1' incorporates:
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
   *  Trigonometry: '<S5>/Cosine'
   */
  rtb_Switch = cos(rtb_Gain2);

  /* Trigonometry: '<S5>/Sin1' incorporates:
   *  DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn'
   *  Trigonometry: '<S5>/Sin'
   */
  rtb_Gain2_tmp = sin(rtb_Gain2);

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem2'
   */
  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S3>/Constant4'
   *  Gain: '<S3>/Gain2'
   *  Product: '<S5>/Product2'
   *  Product: '<S5>/Product3'
   *  Sum: '<S5>/Add1'
   *  Trigonometry: '<S5>/Cosine1'
   *  Trigonometry: '<S5>/Sin1'
   */
  rtb_Gain2 = 2.0 / (3.0 * three_phase_inverter_with_epw_P.lambda *
                     three_phase_inverter_with_epw_P.p) *
    three_phase_inverter_with_epw_P.Constant4_Value - (rtb_Switch * Subtract -
    rtb_alpha * rtb_Gain2_tmp);

  /* Gain: '<S9>/Gain1' */
  rtb_Gain1 = three_phase_inverter_with_epw_P.Kp * rtb_Gain2;

  /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
  if (three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_SYSTEM_ == 0U) {
    /* DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
    three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_DSTATE +=
      three_phase_inverter_with_epw_P.DiscreteTimeIntegrator1_gainval * (real_T)
      Subsystem2_ELAPS_T_idx_0 *
      three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_PREV_U;
  }

  /* End of DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */

  /* Gain: '<S9>/Gain2' */
  rtb_Gain2_e = three_phase_inverter_with_epw_P.Ki * rtb_Gain2;

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem4'
   */
  /* Sum: '<S3>/Sum1' incorporates:
   *  Constant: '<S3>/Constant1'
   *  Product: '<S5>/Product'
   *  Product: '<S5>/Product1'
   *  Sum: '<S5>/Add'
   */
  rtb_Gain2 = three_phase_inverter_with_epw_P.Constant1_Value_o - (rtb_alpha *
    rtb_Switch + rtb_Gain2_tmp * Subtract);

  /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  if (three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_SYSTE_l == 0U) {
    /* DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
    three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_DSTAT_o +=
      three_phase_inverter_with_epw_P.DiscreteTimeIntegrator1_gainv_l * (real_T)
      Subsystem2_ELAPS_T_idx_0 *
      three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_PREV__g;
  }

  /* End of DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */

  /* Update for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' incorporates:
   *  Product: '<S9>/Product'
   */
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_SYSTEM_ = 0U;
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_PREV_U = 0.0 *
    rtb_Gain2_e;

  /* Update for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' incorporates:
   *  Gain: '<S8>/Gain2'
   *  Product: '<S8>/Product'
   */
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_SYSTE_l = 0U;
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_PREV__g =
    three_phase_inverter_with_epw_P.Ki * rtb_Gain2 * 0.0;

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Decoupling'
   */
  /* Sum: '<S1>/Add' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Product: '<S1>/Product'
   *  Product: '<S1>/Product1'
   *  Sum: '<S9>/Sum1'
   */
  rtb_alpha = (0.0 * three_phase_inverter_with_epw_P.lambda + 0.0 *
               three_phase_inverter_with_epw_P.L) + (rtb_Gain1 +
    three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_DSTATE);

  /* Sum: '<S1>/Add1' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Gain: '<S8>/Gain1'
   *  Product: '<S1>/Product2'
   *  Sum: '<S8>/Sum1'
   */
  rtb_Gain2 = (three_phase_inverter_with_epw_P.Kp * rtb_Gain2 +
               three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_DSTAT_o)
    - 0.0 * three_phase_inverter_with_epw_P.L;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem3'
   */
  /* Trigonometry: '<S4>/Cosine' incorporates:
   *  Trigonometry: '<S4>/Sin1'
   */
  Subtract = cos(rtb_Product_o);

  /* Trigonometry: '<S4>/Sin' incorporates:
   *  Trigonometry: '<S4>/Cosine1'
   */
  rtb_Switch = sin(rtb_Product_o);

  /* Sum: '<S4>/Add' incorporates:
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Trigonometry: '<S4>/Cosine'
   *  Trigonometry: '<S4>/Sin'
   */
  rtb_Product_o = rtb_Switch * rtb_Gain2 + Subtract * rtb_alpha;

  /* Gain: '<S4>/Gain' incorporates:
   *  Product: '<S4>/Product2'
   *  Product: '<S4>/Product3'
   *  Sum: '<S4>/Add1'
   */
  rtb_alpha = (Subtract * rtb_Gain2 - rtb_alpha * rtb_Switch) *
    three_phase_inverter_with_epw_P.Gain_Gain_g;

  /* Gain: '<S4>/Gain1' incorporates:
   *  Sum: '<S4>/Add2'
   */
  rtb_Gain2 = ((0.0 - rtb_alpha) - rtb_Product_o) *
    three_phase_inverter_with_epw_P.Gain1_Gain_e;

  /* Gain: '<S4>/Gain2' incorporates:
   *  Sum: '<S4>/Add3'
   */
  rtb_alpha = (rtb_alpha - rtb_Product_o) *
    three_phase_inverter_with_epw_P.Gain2_Gain_n;

  /* S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem5'
   */
  /* MinMax: '<S10>/Max' incorporates:
   *  MinMax: '<S10>/Min'
   */
  tmp = rtIsNaN(rtb_alpha);
  if ((rtb_Product_o >= rtb_alpha) || tmp) {
    Subtract = rtb_Product_o;
  } else {
    Subtract = rtb_alpha;
  }

  /* MinMax: '<S10>/Min' */
  if ((rtb_Product_o <= rtb_alpha) || tmp) {
    rtb_Switch = rtb_Product_o;
  } else {
    rtb_Switch = rtb_alpha;
  }

  /* MinMax: '<S10>/Max' incorporates:
   *  MinMax: '<S10>/Min'
   */
  tmp = !rtIsNaN(rtb_Gain2);
  if ((!(Subtract >= rtb_Gain2)) && tmp) {
    Subtract = rtb_Gain2;
  }

  /* MinMax: '<S10>/Min' */
  if ((!(rtb_Switch <= rtb_Gain2)) && tmp) {
    rtb_Switch = rtb_Gain2;
  }

  /* Gain: '<S10>/one_by_two' incorporates:
   *  MinMax: '<S10>/Max'
   *  MinMax: '<S10>/Min'
   *  Sum: '<S10>/Add'
   */
  Subtract = (Subtract + rtb_Switch) *
    three_phase_inverter_with_epw_P.one_by_two_Gain;

  /* Sum: '<S6>/Add3' */
  rtb_Switch = rtb_alpha + Subtract;

  /* Fcn: '<S6>/Fcn' incorporates:
   *  Gain: '<S6>/Gain'
   *  Sum: '<S6>/Add5'
   */
  rtb_alpha = ((rtb_Product_o + Subtract) *
               three_phase_inverter_with_epw_P.Gain_Gain_a + 1.0) * 5000.0;

  /* S-Function (c2802xpwm): '<S6>/ePWM' */

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_alpha);
  }

  /* Fcn: '<S6>/Fcn1' incorporates:
   *  Gain: '<S6>/Gain'
   */
  rtb_alpha = (three_phase_inverter_with_epw_P.Gain_Gain_a * rtb_Switch + 1.0) *
    5000.0;

  /* S-Function (c2802xpwm): '<S6>/ePWM1' */

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_alpha);
  }

  /* Fcn: '<S6>/Fcn2' incorporates:
   *  Gain: '<S6>/Gain'
   *  Sum: '<S6>/Add4'
   */
  rtb_alpha = ((Subtract + rtb_Gain2) *
               three_phase_inverter_with_epw_P.Gain_Gain_a + 1.0) * 5000.0;

  /* S-Function (c2802xpwm): '<S6>/ePWM2' */

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(rtb_alpha);
  }

  /* End of Outputs for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 1.0E-5, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  three_phase_inverter_with_ep_M->Timing.clockTick0++;
  if (!three_phase_inverter_with_ep_M->Timing.clockTick0) {
    three_phase_inverter_with_ep_M->Timing.clockTickH0++;
  }
}

/* Model initialize function */
void three_phase_inverter_with_epwm_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)three_phase_inverter_with_ep_M, 0,
                sizeof(RT_MODEL_three_phase_inverter_T));

  /* block I/O */
  (void) memset(((void *) &three_phase_inverter_with_epw_B), 0,
                sizeof(B_three_phase_inverter_with_e_T));

  /* states (dwork) */
  (void) memset((void *)&three_phase_inverter_with_ep_DW, 0,
                sizeof(DW_three_phase_inverter_with__T));

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* Start for S-Function (c2802xadc): '<S2>/ADC' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S2>/ADC1' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn' */
  three_phase_inverter_with_ep_DW.DiscreteTransferFcn_states =
    three_phase_inverter_with_epw_P.DiscreteTransferFcn_InitialStat;

  /* InitializeConditions for DiscreteTransferFcn: '<S2>/Discrete Transfer Fcn1' */
  three_phase_inverter_with_ep_DW.DiscreteTransferFcn1_states =
    three_phase_inverter_with_epw_P.DiscreteTransferFcn1_InitialSta;

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem6'
   */
  /* Start for S-Function (c280xqep): '<S7>/eQEP' */
  config_QEP_eQEP2((uint32_T)30000U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for MATLABSystem: '<S7>/DAC' */
  MW_ConfigureDACA();

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem2'
   */
  /* InitializeConditions for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_DSTATE =
    three_phase_inverter_with_epw_P.DiscreteTimeIntegrator1_IC;
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_PREV_U = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_DSTAT_o =
    three_phase_inverter_with_epw_P.DiscreteTimeIntegrator1_IC_p;
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_PREV__g = 0.0;

  /* SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem5'
   */

  /* Start for S-Function (c2802xpwm): '<S6>/ePWM' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm1Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x32U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 10000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 96U;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(400.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(400.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S6>/ePWM1' */

  /*** Initialize ePWM2 modules ***/
  {
    /*  // Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm2Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x32U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 10000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 96U;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(400.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(400.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          // EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S6>/ePWM2' */

  /*** Initialize ePWM3 modules ***/
  {
    /*  // Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          // Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 3U;          // Sync Output Select
       EPwm3Regs.TBCTL2.bit.SYNCOSELX           = 0U;          // Sync Output Select - additional options

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          // Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          // Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 0U;          // Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 0U;          // Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          // High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          // Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x32U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 10000U;          // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          // Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          // Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          // Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          // Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          // Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 0U;      // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 32000U;  // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 96U;// Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          // Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          // Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          // Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          // Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          // Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          // Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          // Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          // DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          // DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(400.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(400.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          // Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          // EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          // Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          // EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          // Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1101U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          // PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          // Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          // One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          // Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          // TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          // EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          // EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          // EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          // EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	// Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          // Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          // Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          // Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          // Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          // Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          // Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	// Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          // DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          // DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          // DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          // DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	// Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          // DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          // DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          // DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          // DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          // DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          // DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	// Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          // Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0U;          // Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          // Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0U;          // Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x0U;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          // Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          // Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          // Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          // Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	// Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          // Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          // Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          // Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          // Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          // Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	// HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          // EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          // EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          //  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* End of SystemInitialize for S-Function (fcgen): '<Root>/Function-Call Generator' */

  /* Enable for S-Function (fcgen): '<Root>/Function-Call Generator' incorporates:
   *  SubSystem: '<Root>/Subsystem2'
   */
  three_phase_inverter_with_ep_DW.Subsystem2_RESET_ELAPS_T = true;

  /* Enable for DiscreteIntegrator: '<S9>/Discrete-Time Integrator1' */
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_SYSTEM_ = 1U;

  /* Enable for DiscreteIntegrator: '<S8>/Discrete-Time Integrator1' */
  three_phase_inverter_with_ep_DW.DiscreteTimeIntegrator1_SYSTE_l = 1U;

  /* End of Enable for S-Function (fcgen): '<Root>/Function-Call Generator' */
}

/* Model terminate function */
void three_phase_inverter_with_epwm_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
