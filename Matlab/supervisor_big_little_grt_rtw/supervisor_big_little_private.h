/*
 * supervisor_big_little_private.h
 *
 * Code generation for model "supervisor_big_little".
 *
 * Model version              : 1.19
 * Simulink Coder version : 8.10 (R2016a) 10-Feb-2016
 * C source code generated on : Mon Mar 13 15:41:47 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_supervisor_big_little_private_h_
#define RTW_HEADER_supervisor_big_little_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               (&(rtm)->Timing.taskTime0)
#endif
#endif                                 /* RTW_HEADER_supervisor_big_little_private_h_ */
