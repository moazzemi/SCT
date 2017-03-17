/*
 * supervisor_big_little.h
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

#ifndef RTW_HEADER_supervisor_big_little_h_
#define RTW_HEADER_supervisor_big_little_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef supervisor_big_little_COMMON_INCLUDES_
# define supervisor_big_little_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* supervisor_big_little_COMMON_INCLUDES_ */

#include "supervisor_big_little_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T sfEvent;                     /* '<Root>/Chart' */
  uint8_T is_active_c3_supervisor_big_lit;/* '<Root>/Chart' */
  uint8_T is_c3_supervisor_big_little; /* '<Root>/Chart' */
} DW_supervisor_big_little_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Chart_Trig_ZCE[10];       /* '<Root>/Chart' */
} PrevZCX_supervisor_big_little_T;

/* Real-time Model Data Structure */
struct tag_RTM_supervisor_big_little_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (auto storage) */
extern DW_supervisor_big_little_T supervisor_big_little_DW;

/* Model entry point functions */
extern void supervisor_big_little_initialize(void);
extern void supervisor_big_little_step(void);
extern void supervisor_big_little_terminate(void);

/* Real-time Model object */
extern RT_MODEL_supervisor_big_littl_T *const supervisor_big_little_M;

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
