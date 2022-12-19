#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Program now supports boards up to 26 columns and 19 rows, and up to 20 hidden word
// (hidden words restriceted by number of words in dictionary)
// (board dimensions restricted by no. of letters and terminal scrolling)


#define ROWS 10
#define COLUMNS 10
#define AREA (ROWS*COLUMNS)

#define WORDSTOCHOOSE 4

#define MAXITERATIONS 50 // affects the chance of not finding a valid pos'n for a word


//Functions:

extern void displayWordBank();
extern void displayPuzzle();
extern void fillPuzzleWithWords();
extern void fillRandom();
extern void createBlankPuzzle();


// Escape Codes:
#define HIGHLIGHT  "\x1b[7m"
#define REDBACK    "\x1b[41m"
#define GRNBACK    "\x1b[42m"
#define REDFORE    "\x1b[31m"
#define GRNFORE    "\x1b[32m"
#define BOLD	   "\x1b[1m"
#define RESET      "\x1b[0m"
#define CURSORPOS  "\x1b[%i;%iH"
#define CURSORHOME "\x1b[H"
#define CLEARFIELD "\x1b[0K"
#define CLEARLINE "\x1b[2K"
#define CLRSCREEN  "\x1b[2J"CURSORHOME



