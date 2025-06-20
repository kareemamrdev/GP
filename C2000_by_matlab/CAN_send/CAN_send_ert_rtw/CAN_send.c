/*
 * File: CAN_send.c
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

#include "CAN_send.h"
#include "rtwtypes.h"
#include "CAN_send_private.h"
#include <string.h>

/* Block signals (default storage) */
B_CAN_send_T CAN_send_B;

/* Block states (default storage) */
DW_CAN_send_T CAN_send_DW;

/* Real-time model */
static RT_MODEL_CAN_send_T CAN_send_M_;
RT_MODEL_CAN_send_T *const CAN_send_M = &CAN_send_M_;
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void CAN_send_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(CAN_send_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(CAN_send_M, 2));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (CAN_send_M->Timing.TaskCounters.TID[1])++;
  if ((CAN_send_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.2s, 0.0s] */
    CAN_send_M->Timing.TaskCounters.TID[1] = 0;
  }

  (CAN_send_M->Timing.TaskCounters.TID[2])++;
  if ((CAN_send_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.5s, 0.0s] */
    CAN_send_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Model step function for TID0 */
void CAN_send_step0(void)              /* Sample time: [0.1s, 0.0s] */
{
  {                                    /* Sample time: [0.1s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S1>/Output'
   */
  CAN_send_B.FixPtSum1 = CAN_send_DW.Output_DSTATE;

  /* S-Function (c280xcanxmt): '<Root>/CAN Transmit' */
  {
    uchar_T ucTXMsgData[1];
    ucTXMsgData[0] = (CAN_send_B.FixPtSum1);
    CAN_sendMessage(CANB_BASE, 2, 1, (uint16_T*)ucTXMsgData);
  }

  /* Sum: '<S2>/FixPt Sum1' incorporates:
   *  Constant: '<S2>/FixPt Constant'
   */
  CAN_send_B.FixPtSum1 = (CAN_send_B.FixPtSum1 + CAN_send_P.FixPtConstant_Value)
    & 255U;

  /* Switch: '<S3>/FixPt Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Sum: '<S2>/FixPt Sum1'
   *  UnitDelay: '<S1>/Output'
   */
  if (CAN_send_B.FixPtSum1 > CAN_send_P.WrapToZero_Threshold) {
    CAN_send_DW.Output_DSTATE = CAN_send_P.Constant_Value_j;
  } else {
    CAN_send_DW.Output_DSTATE = CAN_send_B.FixPtSum1;
  }

  /* End of Switch: '<S3>/FixPt Switch' */
}

/* Model step function for TID1 */
void CAN_send_step1(void)              /* Sample time: [0.2s, 0.0s] */
{
  /* S-Function (c280xcanrcv): '<Root>/CAN Receive' */
  {
    uchar_T ucRXMsgData[8]= { 0, 0, 0, 0, 0, 0, 0, 0 };

    uint16_T status = 0;
    CAN_MsgFrameType frameType;
    uint32_T messageID = 0;
    uint32_T reqNewDataRegValue = (((uint32_T)0x1)<<0);
    uint32_T newDataReg = CAN_getNewDataFlags(CANB_BASE) & reqNewDataRegValue;
    if (newDataReg == reqNewDataRegValue) {
      status = CAN_readMessageWithID(CANB_BASE, 1, &frameType, &messageID,
        (uint16_T*)ucRXMsgData);
    }

    if ((newDataReg == reqNewDataRegValue)&&(status > 0)) {
      CAN_send_B.CANReceive_o2[0] = ucRXMsgData[0];
      CAN_send_B.CANReceive_o2[1] = ucRXMsgData[1];
      CAN_send_B.CANReceive_o2[2] = ucRXMsgData[2];
      CAN_send_B.CANReceive_o2[3] = ucRXMsgData[3];
      CAN_send_B.CANReceive_o2[4] = ucRXMsgData[4];
      CAN_send_B.CANReceive_o2[5] = ucRXMsgData[5];
      CAN_send_B.CANReceive_o2[6] = ucRXMsgData[6];
      CAN_send_B.CANReceive_o2[7] = ucRXMsgData[7];

      /* -- Call CAN RX Fcn-Call_0 -- */
    } else {
      CAN_send_B.CANReceive_o2[0] = 0;
      CAN_send_B.CANReceive_o2[1] = 0;
      CAN_send_B.CANReceive_o2[2] = 0;
      CAN_send_B.CANReceive_o2[3] = 0;
      CAN_send_B.CANReceive_o2[4] = 0;
      CAN_send_B.CANReceive_o2[5] = 0;
      CAN_send_B.CANReceive_o2[6] = 0;
      CAN_send_B.CANReceive_o2[7] = 0;
    }
  }

  /* Switch: '<Root>/Switch' */
  if (CAN_send_B.CANReceive_o2[0] > CAN_send_P.Switch_Threshold) {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    CAN_send_B.Switch = CAN_send_P.Constant_Value;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    CAN_send_B.Switch = CAN_send_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  {
    if (CAN_send_B.Switch) {
      GpioDataRegs.GPBSET.bit.GPIO34 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1U;
    }
  }
}

/* Model step function for TID2 */
void CAN_send_step2(void)              /* Sample time: [0.5s, 0.0s] */
{
  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  CAN_send_B.PulseGenerator = (CAN_send_DW.clockTickCounter <
    CAN_send_P.PulseGenerator_Duty) && (CAN_send_DW.clockTickCounter >= 0L) ?
    CAN_send_P.PulseGenerator_Amp : 0.0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  if (CAN_send_DW.clockTickCounter >= CAN_send_P.PulseGenerator_Period - 1.0) {
    CAN_send_DW.clockTickCounter = 0L;
  } else {
    CAN_send_DW.clockTickCounter++;
  }

  /* S-Function (c280xgpio_do): '<Root>/Digital Output' */
  {
    if (CAN_send_B.PulseGenerator) {
      GpioDataRegs.GPASET.bit.GPIO31 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO31 = 1U;
    }
  }
}

/* Model initialize function */
void CAN_send_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)CAN_send_M, 0,
                sizeof(RT_MODEL_CAN_send_T));

  /* block I/O */
  (void) memset(((void *) &CAN_send_B), 0,
                sizeof(B_CAN_send_T));

  /* states (dwork) */
  (void) memset((void *)&CAN_send_DW, 0,
                sizeof(DW_CAN_send_T));

  /* Start for S-Function (c280xcanrcv): '<Root>/CAN Receive' */
  {
    uint32_T ui32Flags;
    ui32Flags = CAN_MSG_OBJ_NO_FLAGS;
    CAN_setupMessageObject(CANB_BASE, 1, 0x123, CAN_MSG_FRAME_STD,
      CAN_MSG_OBJ_TYPE_RX, 0, ui32Flags, sizeof(uchar_T) * 8);
  }

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output1' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
  GpioCtrlRegs.GPBDIR.all |= 0x4U;
  EDIS;

  /* Start for S-Function (c280xcanxmt): '<Root>/CAN Transmit' */
  CAN_setupMessageObject(CANB_BASE, 2, 0x7D, CAN_MSG_FRAME_STD,
    CAN_MSG_OBJ_TYPE_TX, 0, CAN_MSG_OBJ_NO_FLAGS, 1);

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  CAN_send_DW.clockTickCounter = 0L;

  /* Start for S-Function (c280xgpio_do): '<Root>/Digital Output' */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0x3FFFFFFFU;
  GpioCtrlRegs.GPADIR.all |= 0x80000000U;
  EDIS;

  /* InitializeConditions for UnitDelay: '<S1>/Output' */
  CAN_send_DW.Output_DSTATE = CAN_send_P.Output_InitialCondition;
}

/* Model terminate function */
void CAN_send_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
