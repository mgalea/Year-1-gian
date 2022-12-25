#ifndef GLOBALS_H
#define GLOBALS_H

#pragma once

#include <time.h>
#include <stdio.h>
#include "terminal_defs.h"

#define ROWS 10               // number of rows
#define COLUMNS 10            // number of columns
#define AREA (ROWS * COLUMNS) // area covered by puzzle

#define WORDSTOCHOOSE 4  // affects the chance of not finding a valid position for a word
#define MAXITERATIONS 50 // affects the chance of not finding a valid position for a word

time_t startTime;
time_t timeToComplete = 0;

#endif