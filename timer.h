#include <time.h>


void startTimer(time_t eventTime);

void pauseTimer(time_t eventTime, double *timeToComplete);

void resumeTimer(time_t eventTime);

void endTimer(double timeToComplete);
