#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Program now supports boards up to 26 columns and 99 rows, and up to 20 hidden words (restriceted by number of words in dictionary)
// (hidden words restriceted by number of words in dictionary)
// (board dimensions restricted by no. of letters and 3-digit number formatting)


#define ROWS 10
#define COLUMNS 10
#define AREA (ROWS*COLUMNS)

#define WORDSTOCHOOSE 20

#define MAXITERATIONS 50 // affects the chance of not finding a valid pos'n for a word

