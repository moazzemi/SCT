/*
 * File: supervisor_big_little.c
 *
 * Code generated for Simulink model 'supervisor_big_little'.
 *
 * Model version                  : 1.21
 * Simulink Coder version         : 8.10 (R2016a) 10-Feb-2016
 * C/C++ source code generated on : Wed Mar 15 15:32:11 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM 7
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "supervisor_big_little.h"

/* Block signals and states (auto storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void supervisor_big_little_step(void)
{
  /* (no output/update code required) */
}

/* Model initialize function */
void supervisor_big_little_initialize(void)
{
  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      rtPrevZCX.Chart_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
