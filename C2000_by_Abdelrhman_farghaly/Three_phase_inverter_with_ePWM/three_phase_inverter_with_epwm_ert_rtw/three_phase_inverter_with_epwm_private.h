/*
 * File: three_phase_inverter_with_epwm_private.h
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

#ifndef three_phase_inverter_with_epwm_private_h_
#define three_phase_inverter_with_epwm_private_h_
#include "rtwtypes.h"
#include "three_phase_inverter_with_epwm_types.h"

void config_QEP_eQEP2(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void InitAdcC (void);
void config_ADCC_SOC0 (void);
extern uint16_T MW_adcBInitFlag;
extern uint16_T MW_adcCInitFlag;

#endif                           /* three_phase_inverter_with_epwm_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
