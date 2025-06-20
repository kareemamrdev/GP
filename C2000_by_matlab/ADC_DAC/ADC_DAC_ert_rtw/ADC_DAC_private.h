/*
 * File: ADC_DAC_private.h
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

#ifndef ADC_DAC_private_h_
#define ADC_DAC_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "ADC_DAC_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcA (void);
void config_ADCA_SOC0 (void);
extern uint16_T MW_adcAInitFlag;

#endif                                 /* ADC_DAC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
