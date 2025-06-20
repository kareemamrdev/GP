#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "CAN_send.h"
#include "CAN_send_private.h"

void init_eCAN_B ( uint16_T bitRatePrescaler, uint16_T timeSeg1, uint16_T
                  timeSeg2, uint16_T sbg, uint16_T sjw, uint16_T sam)
{
  uint32_T ui32RegValue;
  uint16_T ui16CANCTL;
  EALLOW;
  CpuSysRegs.PCLKCR10.bit.CAN_B = 1;
  GpioCtrlRegs.GPAPUD.bit.GPIO12 = 0;  /* Enable pull-up on GPIO12 */
  GpioCtrlRegs.GPAGMUX1.bit.GPIO12 = 0;
  GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 2;
  GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;  /* Enable pull-up on GPIO17 */
  GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 0;
  GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 2;
  EDIS;
  ui32RegValue = (((uint32_T)((bitRatePrescaler-1) & 0x03C0))<<10)|((timeSeg2-1)<<
    12)|((timeSeg1-1)<<8)|((sjw-1)<<6)|((bitRatePrescaler-1) & 0x3F);
  CAN_initModule(CANB_BASE);
  CAN_selectClockSource(CANB_BASE, (CAN_ClockSource)0);

  //Set init mode
  ui16CANCTL = HWREGH(CANB_BASE + CAN_O_CTL);
  HWREGH(CANB_BASE + CAN_O_CTL) = ui16CANCTL | CAN_CTL_INIT | CAN_CTL_CCE;

  //Set Bit Timing register
  HWREGH(CANB_BASE + CAN_O_BTR) = (ui32RegValue & 0xFFFFU);
  HWREGH(CANB_BASE + CAN_O_BTR + 2) = (ui32RegValue >> 16);

  // Restore the saved CAN Control register.
  HWREGH(CANB_BASE + CAN_O_CTL) = ui16CANCTL;
  HWREGH(CANB_BASE + CAN_O_IP_MUX21) = 0;
  HWREGH(CANB_BASE + CAN_O_IP_MUX21 + 2) = 0;

  // Enable the CAN for operation.
  CAN_enableController(CANB_BASE);
}
