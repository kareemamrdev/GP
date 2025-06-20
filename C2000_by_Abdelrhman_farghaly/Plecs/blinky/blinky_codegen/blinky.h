/*
 * Header file for: blinky
 * Generated with : PLECS 4.9.2
 *                  TI2837xS 1.10.1
 * Generated on   : 6 May 2025 15:16:59
 */
#ifndef PLECS_HEADER_blinky_h_
#define PLECS_HEADER_blinky_h_

#include <stdbool.h>
#include <stdint.h>

/* Target typedefs */
typedef int_fast8_t int8_t;
typedef uint_fast8_t uint8_t;


/* Model floating point type */
typedef float blinky_FloatType;

/* Target declarations */
extern void blinky_background(void);

/* Model checksum */
extern const char * const blinky_checksum;

/* Model error status */
extern const char * blinky_errorStatus;


/* Model sample time */
extern const float blinky_sampleTime;


/* Entry point functions */
void blinky_initialize(void);
void blinky_step(void);
void blinky_terminate(void);

#endif /* PLECS_HEADER_blinky_h_ */
