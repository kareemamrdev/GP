/*
 * Implementation file for: blinky
 * Generated with         : PLECS 4.9.2
 *                          TI2837xS 1.10.1
 * Generated on           : 6 May 2025 15:16:59
 */
#include "blinky.h"
#ifndef PLECS_HEADER_blinky_h_
#error The wrong header file "blinky.h" was included. Please check your
#error include path to see whether this file name conflicts with the name
#error of another header file.
#endif /* PLECS_HEADER_blinky_h_ */
#if defined(__GNUC__) && (__GNUC__ > 4)
#   define _ALIGNMENT 16
#   define _RESTRICT __restrict
#   define _ALIGN __attribute__((aligned(_ALIGNMENT)))
#   if defined(__clang__)
#      if __has_builtin(__builtin_assume_aligned)
#         define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#      else
#         define _ASSUME_ALIGNED(a) a
#      endif
#   else
#      define _ASSUME_ALIGNED(a) __builtin_assume_aligned(a, _ALIGNMENT)
#   endif
#else
#   ifndef _RESTRICT
#      define _RESTRICT
#   endif
#   ifndef _ALIGN
#      define _ALIGN
#   endif
#   ifndef _ASSUME_ALIGNED
#      define _ASSUME_ALIGNED(a) a
#   endif
#endif
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "plx_hal.h"
#define PLECSRunTimeError(msg) blinky_errorStatus = msg
#define blinky_UNCONNECTED 0
static uint32_t blinky_tickLo;
static int32_t blinky_tickHi;
const char * blinky_errorStatus;
const float blinky_sampleTime = 0.0001f;
const char * const blinky_checksum =
   "d7e5c9204f3126783d3dd99ed153ae23ecf4bb16";
/* Target declarations */
// tag step function to allow special linking
#pragma CODE_SECTION(blinky_step, "step")
extern void blinky_initHal();

void blinky_initialize(void)
{
   blinky_tickHi = 0;
   blinky_tickLo = 0;

   /* Target pre-initialization */
   blinky_initHal();
}

void blinky_step(void)
{
   if (blinky_errorStatus)
   {
      return;
   }
   /* Digital Out : 'blinky/Digital Out' */
   PLXHAL_DIO_set(0, 1.f);

   /* Digital Out : 'blinky/Digital Out1' */
   PLXHAL_DIO_set(1, 1.f);

   /* Digital Out : 'blinky/Digital Out2' */
   PLXHAL_DIO_set(2, 0.f);

   /* Digital Out : 'blinky/Digital Out3' */
   PLXHAL_DIO_set(3, 0.f);

   /* Digital Out : 'blinky/Digital Out4' */
   PLXHAL_DIO_set(4, 0.f);

   /* Digital Out : 'blinky/Digital Out5' */
   PLXHAL_DIO_set(5, 0.f);
   if (blinky_errorStatus)
   {
      return;
   }
}

void blinky_terminate(void)
{
}
