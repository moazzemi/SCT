/*
 * File: supervisor_big_little.h
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

#ifndef RTW_HEADER_supervisor_big_little_h_
#define RTW_HEADER_supervisor_big_little_h_
#ifndef supervisor_big_little_COMMON_INCLUDES_
# define supervisor_big_little_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* supervisor_big_little_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Chart' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[10];       /* '<Root>/Chart' */
} PrevZCX;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* Model entry point functions */
extern void supervisor_big_little_initialize(void);
extern void supervisor_big_little_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'supervisor_big_little'
 * '<S1>'   : 'supervisor_big_little/Chart'
 */
#endif                                 /* RTW_HEADER_supervisor_big_little_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
