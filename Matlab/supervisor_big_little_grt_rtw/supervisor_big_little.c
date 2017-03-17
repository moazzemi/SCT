/*
 * supervisor_big_little.c
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

#include "supervisor_big_little.h"
#include "supervisor_big_little_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define supervisor_b_IN_NO_ACTIVE_CHILD ((uint8_T)0U)

/* Block states (auto storage) */
DW_supervisor_big_little_T supervisor_big_little_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_supervisor_big_little_T supervisor_big_little_PrevZCX;

/* Real-time model */
RT_MODEL_supervisor_big_littl_T supervisor_big_little_M_;
RT_MODEL_supervisor_big_littl_T *const supervisor_big_little_M =
  &supervisor_big_little_M_;

/* Model step function */
void supervisor_big_little_step(void)
{
  /* Matfile logging */
  rt_UpdateTXYLogVars(supervisor_big_little_M->rtwLogInfo,
                      (&supervisor_big_little_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(supervisor_big_little_M)!=-1) &&
        !((rtmGetTFinal(supervisor_big_little_M)-
           supervisor_big_little_M->Timing.taskTime0) >
          supervisor_big_little_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(supervisor_big_little_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++supervisor_big_little_M->Timing.clockTick0)) {
    ++supervisor_big_little_M->Timing.clockTickH0;
  }

  supervisor_big_little_M->Timing.taskTime0 =
    supervisor_big_little_M->Timing.clockTick0 *
    supervisor_big_little_M->Timing.stepSize0 +
    supervisor_big_little_M->Timing.clockTickH0 *
    supervisor_big_little_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void supervisor_big_little_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)supervisor_big_little_M, 0,
                sizeof(RT_MODEL_supervisor_big_littl_T));
  rtmSetTFinal(supervisor_big_little_M, 10.0);
  supervisor_big_little_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    supervisor_big_little_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(supervisor_big_little_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(supervisor_big_little_M->rtwLogInfo, (NULL));
    rtliSetLogT(supervisor_big_little_M->rtwLogInfo, "tout");
    rtliSetLogX(supervisor_big_little_M->rtwLogInfo, "");
    rtliSetLogXFinal(supervisor_big_little_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(supervisor_big_little_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(supervisor_big_little_M->rtwLogInfo, 4);
    rtliSetLogMaxRows(supervisor_big_little_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(supervisor_big_little_M->rtwLogInfo, 1);
    rtliSetLogY(supervisor_big_little_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(supervisor_big_little_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(supervisor_big_little_M->rtwLogInfo, (NULL));
  }

  /* states (dwork) */
  (void) memset((void *)&supervisor_big_little_DW, 0,
                sizeof(DW_supervisor_big_little_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(supervisor_big_little_M->rtwLogInfo, 0.0,
    rtmGetTFinal(supervisor_big_little_M),
    supervisor_big_little_M->Timing.stepSize0, (&rtmGetErrorStatus
    (supervisor_big_little_M)));

  /* ConstCode for Chart: '<Root>/Chart' */
  supervisor_big_little_DW.is_active_c3_supervisor_big_lit = 0U;
  supervisor_big_little_DW.is_c3_supervisor_big_little =
    supervisor_b_IN_NO_ACTIVE_CHILD;

  {
    int32_T i;
    for (i = 0; i < 10; i++) {
      supervisor_big_little_PrevZCX.Chart_Trig_ZCE[i] = UNINITIALIZED_ZCSIG;
    }
  }
}

/* Model terminate function */
void supervisor_big_little_terminate(void)
{
  /* (no terminate code required) */
}
