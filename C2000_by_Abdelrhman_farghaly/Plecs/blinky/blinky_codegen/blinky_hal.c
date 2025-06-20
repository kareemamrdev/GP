/*
 * Hardware configuration file for: TI2837xS
 * Generated with                 : PLECS 4.9.2
 * Generated on                   : Tue May  6 15:16:59 2025
 */

/* HAL Includes */
#include "blinky.h"
#include "plx_hal.h"
#include "plx_dispatcher.h"
#include "pil.h"
#include "pin_map.h"
#include "gpio.h"
#include "xbar.h"
#include "asysctl.h"
#include "sysctl.h"
#include "plx_dio.h"

/* HAL Declarations */
void DevInit(uint32_t aDeviceClkConf);
void InitFlashHz(Uint32 clkHz);
void DSP28x_usDelay(long LoopCount);

// Clock configuration
#define PLX_DEVICE_SETCLOCK_CFG  (SYSCTL_OSCSRC_OSC2 | SYSCTL_IMULT(19) |  \
                                  SYSCTL_FMULT_0 | SYSCTL_SYSDIV(1) |   \
                                  SYSCTL_PLL_ENABLE)

#define SYSCLK_HZ 190000000L
#define SYSCLK_WC_HI_HZ 196000000L
#define LSPCLK_HZ (SYSCLK_HZ / 4l)
#define PLX_DELAY_US(A)  DSP28x_usDelay( \
                                        ((((long double) A * \
                                           1000.0L) / \
                                          5.263158L) - 9.0L) / 5.0L)

PIL_Obj_t PilObj;
PIL_Handle_t PilHandle = 0;
PLX_DIO_Handle_t DoutHandles[6];
PLX_DIO_Obj_t DoutObj[6];

void PLXHAL_DIO_set(uint16_t aHandle, bool aVal)
{
   PLX_DIO_set(DoutHandles[aHandle], aVal);
}

interrupt void blinky_baseTaskInterrupt(void)
{
   CpuTimer0Regs.TCR.bit.TIF = 1;
   PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
   IER |= M_INT1;
   DISPR_dispatch();
}


void PIL_setErrorMessage(PIL_Handle_t aPilHandle, const char* aMessage);
extern const char * blinky_errorStatus;

extern PIL_Handle_t PilHandle;
DISPR_TaskObj_t TaskObj[1];
extern void blinky_step();
extern void blinky_enableTasksInterrupt();
extern void blinky_syncTimers();
static void Tasks(bool aInit, void * const aParam)
{
   if(blinky_errorStatus)
   {
      PIL_setErrorMessage(PilHandle, blinky_errorStatus);
      return;
   }
   if(aInit)
   {
      blinky_enableTasksInterrupt();
   }
   else
   {
      blinky_step();
   }
}



/* Interrupt Enable Code */
void blinky_enableTasksInterrupt(void)
{
   IER |= M_INT1;
}

/* Timer Synchronization Code */
void blinky_syncTimers(void)
{
   CpuTimer0Regs.TCR.bit.TSS = 0;
}

/* Background tasks */
void blinky_background(void)
{

}
/* HAL Initialization Code */
static bool HalInitialized = false;
void blinky_initHal()
{
   if(HalInitialized == true)
   {
      return;
   }
   HalInitialized = true;
   // Pre init code
   {
      uint32_t sysPllConfig = PLX_DEVICE_SETCLOCK_CFG;
      DevInit(sysPllConfig);
      SysCtl_setLowSpeedClock(SYSCTL_LSPCLK_PRESCALE_4);

      PLX_ASSERT(SysCtl_getClock(10000000) == SYSCLK_HZ);
      PLX_ASSERT(SysCtl_getLowSpeedClock(10000000) == LSPCLK_HZ);
   }
   InitFlashHz(SYSCLK_WC_HI_HZ);
   // set cpu timers to same clock as ePWM
   CpuTimer0Regs.TPR.all = 3;
   CpuTimer1Regs.TPR.all = 3;
   CpuTimer2Regs.TPR.all = 3;
   EALLOW;
   CpuSysRegs.PCLKCR0.bit.CPUTIMER0 = 1;
   CpuSysRegs.PCLKCR0.bit.CPUTIMER1 = 1;
   CpuSysRegs.PCLKCR0.bit.CPUTIMER2 = 1;
   CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;  // stop all the TB clocks on the local cpu
   CpuSysRegs.PCLKCR0.bit.GTBCLKSYNC = 0;  // stop all the TB clocks
   ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1;
   EDIS;

   {
      // early system configuration
      PLX_DIO_sinit();
   }
   PLX_DIO_sinit();
   for (int i = 0; i < 6; i++)
   {
      DoutHandles[i] = PLX_DIO_init(&DoutObj[i], sizeof(DoutObj[i]));
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };

      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[0], 40,  &props);
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };

      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[1], 41,  &props);
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };

      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[2], 65,  &props);
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };

      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[3], 52,  &props);
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };

      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[4], 97,  &props);
   }

   {
      PLX_DIO_OutputProperties_t props = {
         0
      };

      props.enableInvert = false;
      PLX_DIO_configureOut(DoutHandles[5], 94,  &props);
   }

   {
      CpuTimer0Regs.TCR.bit.TSS = 1; // stop timer
      CpuTimer0Regs.TPRH.all = 0;
      CpuTimer0Regs.PRD.all = 4750 - 1;
      CpuTimer0Regs.TCR.bit.TRB = 1; // reload period
      CpuTimer0Regs.TCR.bit.TIE = 1; // enable trigger to SOC/interrupt
      PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
      EALLOW;
      PieVectTable.TIMER0_INT = &blinky_baseTaskInterrupt;
      EDIS;
      PieCtrlRegs.PIEIER1.bit.INTx7 = 1;
      PieCtrlRegs.PIEACK.all = PIEACK_GROUP1; // acknowledge interrupt to PIE

   }
   DISPR_sinit();
   DISPR_configure((uint32_t)(4750), PilHandle, &TaskObj[0],
                   sizeof(TaskObj)/sizeof(DISPR_TaskObj_t));
   DISPR_registerIdleTask(&blinky_background);
   DISPR_registerSyncCallback(&blinky_syncTimers);
   DISPR_setPowerupDelay(10);
   {
      static int taskId = 0;
      // Task 0 at 1.000000e+04 Hz
      DISPR_registerTask(0, &Tasks, 4750L, (void *)&taskId);
   }

   // Post init code (for modules that depend on other modules)

   {
      // late system configuration
      GPIO_setPadConfig(40, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(40, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(41, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(41, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(65, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(65, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(52, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(52, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(97, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(97, GPIO_DIR_MODE_OUT);
      GPIO_setPadConfig(94, GPIO_PIN_TYPE_STD);
      GPIO_setDirectionMode(94, GPIO_DIR_MODE_OUT);
   }
}
