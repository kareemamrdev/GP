/*
 * File: scheduling_private.h
 *
 * Code generated for Simulink model 'scheduling'.
 *
 * Model version                  : 1.1
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Thu Apr  3 17:43:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef scheduling_private_h_
#define scheduling_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "scheduling_types.h"
#include "scheduling.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcA (void);
void config_ADCA_SOC0 (void);
extern uint16_T MW_adcAInitFlag;
void isr_int1pie4_task_fcn(void);
extern void configureGPIOExtInterrupt(void);
void isr_int1pie4_task_fcn(void);

#endif                                 /* scheduling_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
