/*
 * File: ADC_private.h
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

#ifndef ADC_private_h_
#define ADC_private_h_
#include "rtwtypes.h"
#include "ADC_types.h"

void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcA (void);
void config_ADCA_SOC0 (void);
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcAInitFlag;

#endif                                 /* ADC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
