/*
 * File: ADC_DAC.c
 *
 * Code generated for Simulink model 'ADC_DAC'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Fri Apr  4 06:45:55 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ADC_DAC.h"
#include "ADC_DAC_private.h"
#include <string.h>

/* Block signals (default storage) */
B_ADC_DAC_T ADC_DAC_B;

/* Block states (default storage) */
DW_ADC_DAC_T ADC_DAC_DW;

/* Real-time model */
static RT_MODEL_ADC_DAC_T ADC_DAC_M_;
RT_MODEL_ADC_DAC_T *const ADC_DAC_M = &ADC_DAC_M_;

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

/* Model step function */
void ADC_DAC_step(void)
{
  /* S-Function (c2802xadc): '<Root>/ADC' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    AdcaRegs.ADCSOCFRC1.bit.SOC0 = 1U;

    /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

    asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

    real32_T wait_index;
    for (wait_index= 12; wait_index > 0; wait_index--)
      __mnop();

#endif

    ADC_DAC_B.ADC = (AdcaResultRegs.ADCRESULT0);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  ADC_DAC_M->Timing.taskTime0 =
    ((time_T)(++ADC_DAC_M->Timing.clockTick0)) * ADC_DAC_M->Timing.stepSize0;
}

/* Model initialize function */
void ADC_DAC_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)ADC_DAC_M, 0,
                sizeof(RT_MODEL_ADC_DAC_T));
  rtmSetTFinal(ADC_DAC_M, -1);
  ADC_DAC_M->Timing.stepSize0 = 1.0;

  /* External mode info */
  ADC_DAC_M->Sizes.checksums[0] = (3217529429U);
  ADC_DAC_M->Sizes.checksums[1] = (2383862942U);
  ADC_DAC_M->Sizes.checksums[2] = (3735636621U);
  ADC_DAC_M->Sizes.checksums[3] = (1460659108U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    ADC_DAC_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(ADC_DAC_M->extModeInfo,
      &ADC_DAC_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(ADC_DAC_M->extModeInfo, ADC_DAC_M->Sizes.checksums);
    rteiSetTPtr(ADC_DAC_M->extModeInfo, rtmGetTPtr(ADC_DAC_M));
  }

  /* block I/O */
  (void) memset(((void *) &ADC_DAC_B), 0,
                sizeof(B_ADC_DAC_T));

  /* states (dwork) */
  (void) memset((void *)&ADC_DAC_DW, 0,
                sizeof(DW_ADC_DAC_T));

  /* Start for S-Function (c2802xadc): '<Root>/ADC' */
  if (MW_adcAInitFlag == 0U) {
    InitAdcA();
    MW_adcAInitFlag = 1U;
  }

  config_ADCA_SOC0 ();
}

/* Model terminate function */
void ADC_DAC_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
