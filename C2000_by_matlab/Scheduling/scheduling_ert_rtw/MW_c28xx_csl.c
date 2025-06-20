#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "scheduling.h"
#include "scheduling_private.h"

void enableExtInterrupt (void);
void configureGPIOExtInterrupt(void);

#include <stdint.h>

void disableWatchdog(void)
{
  int *WatchdogWDCR = (int *)(uintptr_t)0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}

interrupt void XINT1_INT_isr(void)
{
  isr_int1pie4_task_fcn();
  PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
                                     /* Acknowledge to receive more interrupts*/
}

void enable_interrupts()
{
  enableExtInterrupt();
  EALLOW;
  PieVectTable.XINT1_INT = &XINT1_INT_isr;/* Hook interrupt to the ISR*/
  EDIS;
  PieCtrlRegs.PIEIER1.bit.INTx4 = 1;   /* Enable interrupt XINT1_INT*/
  IER |= M_INT1;

  /* Enable global Interrupts and higher priority real-time debug events:*/
  EINT;                                /* Enable Global interrupt INTM*/
  ERTM;                               /* Enable Global realtime interrupt DBGM*/
}

void enableExtInterrupt (void)
{
  EALLOW;
  XintRegs.XINT1CR.bit.ENABLE = 1U;
  XintRegs.XINT1CR.bit.POLARITY = 1U;
  EDIS;
}
