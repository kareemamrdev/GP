/*
 * File: open_loop_inverter_model_badry_sus_private.h
 *
 * Code generated for Simulink model 'open_loop_inverter_model_badry_sus'.
 *
 * Model version                  : 9.3
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Wed Jun 18 21:34:58 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef open_loop_inverter_model_badry_sus_private_h_
#define open_loop_inverter_model_badry_sus_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "open_loop_inverter_model_badry_sus_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
void InitAdcA (void);
void config_ADCA_SOC0 (void);
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcAInitFlag;

#endif                       /* open_loop_inverter_model_badry_sus_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
