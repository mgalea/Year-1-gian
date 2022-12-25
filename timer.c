/**
 *@file timer.c
 *@brief timer management functions
 *
 */

#include <time.h>
#include "timer.h"

/**
 * @brief start Timer
 *
 */
void startTimer(time_t eventTime)
{
    time(&eventTime);
}

/**
 * @brief
 *
 */
void pauseTimer(time_t eventTime, double *timeToComplete)
{
    *timeToComplete += difftime(time(NULL), eventTime);
}

/**
 * @brief
 *
 */
void resumeTimer(time_t eventTime)
{
    time(&eventTime);
}

/**
 * @brief
 *
 */
void endTimer(double timeToComplete)
{
    timeToComplete = 0;
}
